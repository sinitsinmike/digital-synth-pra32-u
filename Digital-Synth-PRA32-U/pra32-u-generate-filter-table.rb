require_relative 'pra32-u-constants'

$file = File.open("pra32-u-filter-table.h", "w")

$file.printf("#pragma once\n\n")

OCTAVES = 10

def generate_filter_table(hpf, res_idx, name, q)
  $file.printf("int32_t g_filter_%s_table_%s[] = {\n  ", hpf ? "hpf" : "lpf", name)
  (0..DATA_BYTE_MAX * 2 + 1).each do |i|
    f_idx = [[-2, i - 1 * 2].max, 252].min
    f_0 = (2.0 ** ((f_idx / 2.0) / (120.0 / OCTAVES))) * ((A4_FREQ * 2.0) * 16.0) * 2.0 / (2.0 ** (OCTAVES.to_f + 1.0))
    f_0_over_f_s = f_0 / SAMPLING_RATE

    w_0 = 2.0 * Math::PI * f_0_over_f_s
    alpha = Math.sin(w_0) / (2.0 * q)

    if hpf == false
      b_2 = (1.0 - Math.cos(w_0)) / 2.0
    elsif  # hpf
      b_2 = (1.0 + Math.cos(w_0)) / 2.0
    end

    a_0 = 1.0 + alpha
    a_1 = (-2.0) * Math.cos(w_0)
    a_2 = 1.0 - alpha

    input_gain = 1.0 / (2.0 ** (res_idx / 6.0))
    b_2_over_a_0_gain = (input_gain * (b_2 / a_0) * (1 << FILTER_TABLE_FRACTION_BITS)).floor.to_i
    a_1_over_a_0 = ((a_1 / a_0) * (1 << FILTER_TABLE_FRACTION_BITS)).floor.to_i
    a_2_over_a_0 = ((a_2 / a_0) * (1 << FILTER_TABLE_FRACTION_BITS)).floor.to_i

    printf("i: %d, f_idx: %d, f_0_over_f_s: %f, f_0: %f, res_idx: %d, q: %f, g: %f, q_mul_g: %f\n", i, f_idx, f_0_over_f_s, f_0, res_idx, q, input_gain, q * input_gain)

    $file.printf("%+11d, %+11d, %+11d,", b_2_over_a_0_gain, a_1_over_a_0, a_2_over_a_0)
    if i == DATA_BYTE_MAX * 2 + 1
      $file.printf("\n")
    elsif i % 2 == (2 - 1)
      $file.printf("\n  ")
    else
      $file.printf("  ")
    end
  end
  $file.printf("};\n\n")
end

MAX_RES_IDX = 7

(0..MAX_RES_IDX).each do |res_idx|
  generate_filter_table(false, res_idx, res_idx.to_s, Math.sqrt(2.0) ** (res_idx - 1.0))
end

(0..MAX_RES_IDX).each do |res_idx|
  generate_filter_table(true,  res_idx, res_idx.to_s, Math.sqrt(2.0) ** (res_idx - 1.0))
end

def generate_filter_tables(hpf)
  $file.printf("int32_t* g_filter_%s_tables[] = {\n  ", hpf ? "hpf" : "lpf")
  (0..8).each do |res_idx|
    i = [[res_idx - 1, 0].max, MAX_RES_IDX].min
    $file.printf("g_filter_%s_table_%-2d,", hpf ? "hpf" : "lpf", i)
    if res_idx == DATA_BYTE_MAX
      $file.printf("\n")
    elsif res_idx % 4 == 3
      $file.printf("\n  ")
    else
      $file.printf(" ")
    end
  end
  $file.printf("};\n\n")
end

generate_filter_tables(false)
generate_filter_tables(true)

$file.close
