#pragma once

#include "common.h"
#include "osc-table.h"
#include <math.h>

static const uint8_t OSC_MIX_TABLE_LENGTH   = 31;

static const uint8_t CHORUS_MODE_OFF        = 0;
static const uint8_t CHORUS_MODE_STEREO     = 1;
static const uint8_t CHORUS_MODE_P_STEREO   = 2;
static const uint8_t CHORUS_MODE_MONO       = 3;
static const uint8_t CHORUS_MODE_STEREO_2   = 4;

static const uint8_t PORTAMENTO_COEF_OFF    = 190;

class Osc {
  static const uint8_t WAVEFORM_SAW           = 0;
  static const uint8_t WAVEFORM_SQUARE        = 1;
  static const uint8_t WAVEFORM_TRIANGLE      = 2;
  static const uint8_t WAVEFORM_1_PULSE       = 4;
  static const uint8_t WAVEFORM_2_NOISE       = 5;

  static const uint8_t LFO_WAVEFORM_TRI_ASYNC = 0;
  static const uint8_t LFO_WAVEFORM_TRI_SYNC  = 1;
  static const uint8_t LFO_WAVEFORM_SAW_DOWN  = 2;
  static const uint8_t LFO_WAVEFORM_RANDOM    = 3;
  static const uint8_t LFO_WAVEFORM_SQUARE    = 4;

  static const uint8_t LFO_FADE_COEF_OFF      = 1;
  static const uint8_t LFO_FADE_COEF_ON_MIN   = 2;

  static const uint8_t LFO_FADE_LEVEL_MAX     = 128;

  uint8_t        m_portamento_coef[4];
  int8_t         m_pitch_eg_amt[2];
  int16_t        m_lfo_mod_level[2];
  uint16_t       m_lfo_phase;
  int16_t        m_lfo_wave_level;
  int16_t        m_lfo_level;
  uint16_t       m_lfo_rate;
  uint8_t        m_lfo_depth[2];
  int8_t         m_pitch_lfo_amt[2];
  uint8_t        m_lfo_waveform;
  uint8_t        m_lfo_sampled;
  uint8_t        m_lfo_fade_coef;
  uint8_t        m_lfo_fade_cnt;
  uint8_t        m_lfo_fade_level;

  uint8_t        m_chorus_depth_control;
  uint8_t        m_chorus_rate_control;
  uint8_t        m_chorus_delay_time_control;
  uint8_t        m_chorus_delay_time_control_effective;
  uint8_t        m_chorus_mode;
  uint8_t        m_chorus_depth_control_actual;
  uint16_t       m_chorus_lfo_phase;
  int16_t        m_chorus_lfo_wave_level;
  int16_t        m_chorus_lfo_level;
  uint16_t       m_chorus_delay_time[2];

  uint8_t        m_waveform[2];
  int16_t        m_pitch_bend;
  uint8_t        m_pitch_bend_range;
  int16_t        m_pitch_bend_normalized;
  uint16_t       m_pitch_target[4];
  uint16_t       m_pitch_current[4];
  uint16_t       m_pitch_real[4];
  const int8_t*  m_wave_table[4];
  const int8_t*  m_wave_table_temp[4];
  uint16_t       m_freq[4];
  uint16_t       m_freq_temp[4];
  uint16_t       m_phase[4];
  boolean        m_osc_on[4];
  boolean        m_osc_on_temp[4];
  int8_t         m_osc_gain_effective[4];
  int8_t         m_osc_gain[4];
  int8_t         m_osc_level;

  boolean        m_mono_mode;
  uint8_t        m_mono_osc2_mix;
  int8_t         m_mono_osc2_pitch;
  int8_t         m_mono_osc2_detune;

  uint8_t        m_rnd;

  __uint24       m_lfsr;
  uint8_t        m_phase_high;
  int8_t         m_osc1_shape_control;
  int8_t         m_osc1_shape_control_effective;
  int8_t         m_osc1_morph_control;
  uint16_t       m_osc1_shape;
  uint8_t        m_mixer_sub_osc_control;
  uint8_t        m_mix_table[OSC_MIX_TABLE_LENGTH];
  int8_t         m_shape_eg_amt;
  int8_t         m_shape_lfo_amt;

public:
  Osc()
  : m_portamento_coef()
  , m_pitch_eg_amt()
  , m_lfo_mod_level()
  , m_lfo_phase()
  , m_lfo_wave_level()
  , m_lfo_level()
  , m_lfo_rate()
  , m_lfo_depth()
  , m_pitch_lfo_amt()
  , m_lfo_waveform()
  , m_lfo_sampled()
  , m_lfo_fade_coef()
  , m_lfo_fade_cnt()
  , m_lfo_fade_level()

  , m_chorus_depth_control()
  , m_chorus_rate_control()
  , m_chorus_delay_time_control()
  , m_chorus_delay_time_control_effective()
  , m_chorus_mode()
  , m_chorus_depth_control_actual()
  , m_chorus_lfo_phase()
  , m_chorus_lfo_wave_level()
  , m_chorus_lfo_level()
  , m_chorus_delay_time()

  , m_waveform()
  , m_pitch_bend()
  , m_pitch_bend_range()
  , m_pitch_bend_normalized()
  , m_pitch_target()
  , m_pitch_current()
  , m_pitch_real()
  , m_wave_table()
  , m_wave_table_temp()
  , m_freq()
  , m_freq_temp()
  , m_phase()
  , m_osc_on()
  , m_osc_on_temp()
  , m_osc_gain_effective()
  , m_osc_gain()
  , m_osc_level()

  , m_mono_mode()
  , m_mono_osc2_mix()
  , m_mono_osc2_pitch()
  , m_mono_osc2_detune()

  , m_rnd()

  , m_lfsr()
  , m_phase_high()
  , m_osc1_shape_control()
  , m_osc1_shape_control_effective()
  , m_osc1_morph_control()
  , m_osc1_shape()
  , m_mixer_sub_osc_control()
  , m_mix_table()
  , m_shape_eg_amt()
  , m_shape_lfo_amt()
  {}

  INLINE void initialize() {
    m_portamento_coef[0] = PORTAMENTO_COEF_OFF;
    m_portamento_coef[1] = PORTAMENTO_COEF_OFF;
    m_portamento_coef[2] = PORTAMENTO_COEF_OFF;
    m_portamento_coef[3] = PORTAMENTO_COEF_OFF;

    m_lfo_waveform = LFO_WAVEFORM_TRI_ASYNC;
    m_lfo_sampled = 64;
    m_lfo_fade_coef = LFO_FADE_COEF_OFF;
    m_lfo_fade_cnt = m_lfo_fade_coef;
    m_lfo_fade_level = LFO_FADE_LEVEL_MAX;

    set_chorus_depth     (32 );
    set_chorus_rate      (32 );
    set_chorus_delay_time(80 );
    set_chorus_mode      (CHORUS_MODE_OFF);
    set_mono_mode        (false);
    set_mono_osc2_mix    (0);
    set_mono_osc2_pitch  (0);
    set_mono_osc2_detune (0);

    m_chorus_depth_control_actual = 64;

    m_waveform[0] = WAVEFORM_SAW;
    m_waveform[1] = WAVEFORM_SAW;
    m_pitch_target[0] = 60 << 8;
    m_pitch_target[1] = 60 << 8;
    m_pitch_target[2] = 60 << 8;
    m_pitch_target[3] = 60 << 8;
    m_pitch_current[0] = m_pitch_target[0];
    m_pitch_current[1] = m_pitch_target[1];
    m_pitch_current[2] = m_pitch_target[2];
    m_pitch_current[3] = m_pitch_target[3];
    m_pitch_real[0] = m_pitch_current[0];
    m_pitch_real[1] = m_pitch_current[1];
    m_pitch_real[2] = m_pitch_current[2];
    m_pitch_real[3] = m_pitch_current[3];
    m_wave_table[0] = g_osc_saw_wave_tables[0];
    m_wave_table[1] = g_osc_saw_wave_tables[0];
    m_wave_table[2] = g_osc_saw_wave_tables[0];
    m_wave_table[3] = g_osc_saw_wave_tables[0];
    m_wave_table_temp[0] = g_osc_saw_wave_tables[0];
    m_wave_table_temp[1] = g_osc_saw_wave_tables[0];
    m_wave_table_temp[2] = g_osc_saw_wave_tables[0];
    m_wave_table_temp[3] = g_osc_saw_wave_tables[0];
    m_freq[0] = g_osc_freq_table[0];
    m_freq[1] = g_osc_freq_table[0];
    m_freq[2] = g_osc_freq_table[0];
    m_freq[3] = g_osc_freq_table[0];
    m_freq_temp[0] = g_osc_freq_table[0];
    m_freq_temp[1] = g_osc_freq_table[0];
    m_freq_temp[2] = g_osc_freq_table[0];
    m_freq_temp[3] = g_osc_freq_table[0];
    m_osc_level = 48;

    m_rnd = 1;

    m_lfsr = 0x000001u;
    m_osc1_shape = 0x8000;
    for (uint8_t i = 0; i < OSC_MIX_TABLE_LENGTH; ++i) {
      m_mix_table[i] = static_cast<uint8_t>(sqrtf(static_cast<float>(i) /
                                                  (OSC_MIX_TABLE_LENGTH - 1)) * 255);
    }

    set_pitch_bend_range(2);
  }

  template <uint8_t N>
  INLINE void set_osc_waveform(uint8_t controller_value) {
    if (N == 0) {
      if (controller_value < 48) {
        m_waveform[0] = WAVEFORM_SAW;
      } else if (controller_value < 80) {
        m_waveform[0] = WAVEFORM_TRIANGLE;
      } else if (controller_value < 112) {
        m_waveform[0] = WAVEFORM_1_PULSE;
      } else {
        m_waveform[0] = WAVEFORM_SQUARE;
      }
    } else {
      if (controller_value < 48) {
        m_waveform[1] = WAVEFORM_SAW;
      } else if (controller_value < 80) {
        m_waveform[1] = WAVEFORM_TRIANGLE;
      } else if (controller_value < 112) {
        m_waveform[1] = WAVEFORM_2_NOISE;
      } else {
        m_waveform[1] = WAVEFORM_SQUARE;
      }
    }
  }

  INLINE void set_osc1_shape_control(uint8_t controller_value) {
    m_osc1_shape_control = -(((controller_value + 1) >> 1) << 1);
  }

  INLINE void set_osc1_morph_control(uint8_t controller_value) {
    m_osc1_morph_control = -(((controller_value - 63) >> 1) << 1);
  }

  INLINE void set_mixer_sub_osc_control(uint8_t controller_value) {
    m_mixer_sub_osc_control = (((controller_value + 1) >> 1) *
                              static_cast<uint8_t>(OSC_WAVE_TABLE_AMPLITUDE << 1)) >> 8;
  }

  INLINE void set_osc_level(uint8_t controller_value) {
    if (controller_value < 10) {
      m_osc_level = 4;
    } else {
      m_osc_level = ((controller_value - 1) >> 1);
    }
  }

  template <uint8_t N>
  INLINE void set_pitch_eg_amt(uint8_t controller_value) {
    if (controller_value < 25) {
      m_pitch_eg_amt[N] = -96;
    } else if (controller_value < 48) {
      m_pitch_eg_amt[N] = (controller_value - 49) << 2;
    } else if (controller_value < 80) {
      m_pitch_eg_amt[N] = (controller_value - 62) >> 2;
    } else if (controller_value < 103) {
      m_pitch_eg_amt[N] = (controller_value - 79) << 2;
    } else {
      m_pitch_eg_amt[N] = 96;
    }
  }

  INLINE void set_shape_eg_amt(uint8_t controller_value) {
    if (controller_value == 0) {
      controller_value = 1;
    }
    m_shape_eg_amt = ((controller_value - 64) << 1);
  }

  INLINE void set_lfo_waveform(uint8_t controller_value) {
    if        (controller_value < 16) {
      m_lfo_waveform = LFO_WAVEFORM_TRI_ASYNC;
    } else if (controller_value < 48) {
      m_lfo_waveform = LFO_WAVEFORM_TRI_SYNC;
    } else if (controller_value < 80) {
      m_lfo_waveform = LFO_WAVEFORM_SAW_DOWN;
    } else if (controller_value < 112) {
      m_lfo_waveform = LFO_WAVEFORM_RANDOM;
    } else {
      m_lfo_waveform = LFO_WAVEFORM_SQUARE;
    }
  }

  INLINE void set_lfo_rate(uint8_t controller_value) {
    m_lfo_rate = g_lfo_rate_table[(controller_value + 1) >> 1];
  }

  template <uint8_t N>
  INLINE void set_lfo_depth(uint8_t controller_value) {
    m_lfo_depth[N] = (controller_value + 1) >> 1;
  }

  template <uint8_t N>
  INLINE void set_pitch_lfo_amt(uint8_t controller_value) {
    if (controller_value < 25) {
      m_pitch_lfo_amt[N] = -96;
    } else if (controller_value < 48) {
      m_pitch_lfo_amt[N] = (controller_value - 49) << 2;
    } else if (controller_value < 80) {
      m_pitch_lfo_amt[N] = (controller_value - 62) >> 2;
    } else if (controller_value < 103) {
      m_pitch_lfo_amt[N] = (controller_value - 79) << 2;
    } else {
      m_pitch_lfo_amt[N] = 96;
    }
  }

  INLINE void set_shape_lfo_amt(uint8_t controller_value) {
    if (controller_value == 0) {
      controller_value = 1;
    }
    m_shape_lfo_amt = -((controller_value - 64) << 1);
  }

  INLINE void set_lfo_fade_time(uint8_t controller_value) {
    m_lfo_fade_coef = high_byte(controller_value * controller_value) + LFO_FADE_COEF_OFF;
  }

  INLINE void set_chorus_depth(uint8_t controller_value) {
    if (controller_value < 126) {
      m_chorus_depth_control = controller_value;
    } else {
      m_chorus_depth_control = 126;
    }
  }

  INLINE void set_chorus_rate(uint8_t controller_value) {
    if (controller_value < 2) {
      m_chorus_rate_control = 1;
    } else {
      m_chorus_rate_control = (controller_value + 2) >> 2;
    }
  }

  INLINE void set_chorus_delay_time(uint8_t controller_value) {
    m_chorus_delay_time_control = controller_value;
  }

  INLINE void set_chorus_mode(uint8_t chorus_mode) {
    m_chorus_mode = chorus_mode;
  }

  INLINE void set_mono_mode(boolean mono_mode) {
    m_mono_mode = mono_mode;
  }

  INLINE void set_mono_osc2_mix(uint8_t controller_value) {
    if (controller_value >= 2) {
      controller_value -= 2;
    }

    if (controller_value > 123) {
      controller_value = 123;
    }
    m_mono_osc2_mix = controller_value >> 2;
  }

  INLINE void set_mono_osc2_pitch(uint8_t controller_value) {
    if (controller_value < 16) {
      m_mono_osc2_pitch = -48;
    } else if (controller_value < 112) {
      m_mono_osc2_pitch = controller_value - 64;
    } else {
      m_mono_osc2_pitch = 48;
    }
  }

  INLINE void set_mono_osc2_detune(uint8_t controller_value) {
    m_mono_osc2_detune = (controller_value - 64) << 1;
  }

  template <uint8_t N>
  INLINE void set_portamento(uint8_t controller_value) {
    m_portamento_coef[N] = ((controller_value + 1) >> 1) + PORTAMENTO_COEF_OFF;
  }

  template <uint8_t N>
  INLINE void note_on(uint8_t note_number) {
    m_pitch_target[N] = note_number << 8;
    m_osc_on[N] = true;
  }

  template <uint8_t N>
  INLINE void note_off() {
    m_osc_on[N] = false;
  }

  INLINE void trigger_lfo() {
    if (m_lfo_waveform != LFO_WAVEFORM_TRI_ASYNC) {
      m_lfo_phase = 0xFFFF;
    }

    if (m_lfo_fade_coef >= LFO_FADE_COEF_ON_MIN) {
      m_lfo_fade_level = 0;
    }
  }

  INLINE void set_pitch_bend_range(uint8_t controller_value) {
    uint8_t range = controller_value;
    if (range > 24) {
      range = 24;
    }
    m_pitch_bend_range = range;
    update_pitch_bend();
  }

  INLINE void set_pitch_bend(int16_t pitch_bend) {
    m_pitch_bend = pitch_bend;
    update_pitch_bend();
  }

  INLINE int16_t get_lfo_level() {
    return m_lfo_level;
  }

  INLINE uint16_t get_osc_pitch() {
    if (m_mono_mode) {
      return m_pitch_current[0] + m_pitch_bend_normalized;
    }
    return (60 << 8);
  }

  template <uint8_t N>
  INLINE int16_t get_chorus_delay_time() {
    return m_chorus_delay_time[N];
  }

  INLINE int16_t process(uint8_t count, int16_t eg_level) {
#if 1
    if ((count & (OSC_CONTROL_INTERVAL - 1)) == 0) {
      //printf("%d Osc\n", count);
      switch ((count >> OSC_CONTROL_INTERVAL_BITS) & 0x1F) {
      case 0x00: update_freq_0th<0>();         break;
      case 0x01: update_freq_1st<0>(eg_level); break;
      case 0x02: update_freq_2nd<0>();         break;
      case 0x03: update_freq_3rd<0>();         break;
      case 0x04: update_gate<0>();             break;
      case 0x05: update_rnd();                 break;
      case 0x06: update_lfo_1st();             break;
      case 0x07: update_lfo_2nd();             break;
      case 0x08: update_freq_0th<1>();         break;
      case 0x09: update_freq_1st<1>(eg_level); break;
      case 0x0A: update_freq_2nd<1>();         break;
      case 0x0B: update_freq_3rd<1>();         break;
      case 0x0C: update_gate<1>();             break;
      case 0x0D: update_rnd();                 break;
      case 0x0E: update_lfo_3rd();             break;
      case 0x0F: update_lfo_4th(eg_level);     break;
      case 0x10: update_freq_0th<2>();         break;
      case 0x11: update_freq_1st<2>(eg_level); break;
      case 0x12: update_freq_2nd<2>();         break;
      case 0x13: update_freq_3rd<2>();         break;
      case 0x14: update_gate<2>();             break;
      case 0x15: update_rnd();                 break;
      case 0x16: update_chorus_lfo_0th();      break;
      case 0x17: update_chorus_lfo_1st();      break;
      case 0x18: update_freq_0th<3>();         break;
      case 0x19: update_freq_1st<3>(eg_level); break;
      case 0x1A: update_freq_2nd<3>();         break;
      case 0x1B: update_freq_3rd<3>();         break;
      case 0x1C: update_gate<3>();             break;
      case 0x1D: update_rnd();                 break;
      case 0x1E: update_chorus_lfo_2nd();      break;
      case 0x1F: update_chorus_lfo_3rd();      break;
      }
    }
#endif

#if 1
    m_phase[0] += m_freq[0];
    int16_t wave_0 = get_wave_level(m_wave_table[0], m_phase[0]);
    int32_t result = wave_0 * m_osc_gain_effective[0];

    if (m_mono_mode == false) {
      m_phase[1] += m_freq[1];
      int16_t wave_1 = get_wave_level(m_wave_table[1], m_phase[1]);
      result += wave_1 * m_osc_gain_effective[1];

      m_phase[2] += m_freq[2];
      int16_t wave_2 = get_wave_level(m_wave_table[2], m_phase[2]);
      result += wave_2 * m_osc_gain_effective[2];

      m_phase[3] += m_freq[3];
      int16_t wave_3 = get_wave_level(m_wave_table[3], m_phase[3]);
      result += wave_3 * m_osc_gain_effective[3];
    } else {
      if (m_waveform[0] == WAVEFORM_1_PULSE) {
        // For Shaped Saw Wave or Pulse Wave (wave_3)
        m_phase[3] = m_phase[0] + m_osc1_shape;
        int16_t wave_3 = get_wave_level(m_wave_table[0], m_phase[3]);
        result += wave_3 * m_osc_gain_effective[3];
      } else {
        // Sub Osc (wave_1)
        if (m_phase[0] < m_freq[0]) {
          m_phase_high ^= 1;
        }
        m_phase[1] = m_phase[0] >> 1;
        if (m_phase_high) {
          m_phase[1] += 0x8000;
        }

        int16_t wave_1 = m_phase[1];
        if (wave_1 < -(64 << 8)) {
          wave_1 = -(64 << 8) - (wave_1 + (64 << 8));
        } else if (wave_1 < (64 << 8)) {
          // do nothing
        } else {
          wave_1 = (64 << 8) - (wave_1 - (64 << 8));
        }
        result += wave_1 * (m_osc_gain_effective[1] << 1);
      }

      if (m_waveform[1] != WAVEFORM_2_NOISE) {
        m_phase[2] += m_freq[2];
        int16_t wave_2 = get_wave_level(m_wave_table[2], m_phase[2]);
        result += wave_2 * m_osc_gain_effective[2];
      } else {
        // Noise (wave_2)
        int8_t wave_2 = -OSC_WAVE_TABLE_AMPLITUDE;
        uint8_t lsb = m_lfsr & 0x000001u;
        m_lfsr >>= 1;
        m_lfsr ^= (-lsb) & 0xE10000u;
        if (lsb) {
          wave_2 = +OSC_WAVE_TABLE_AMPLITUDE;
        }
        result += wave_2 * m_osc_gain_effective[2];
      }
    }
#else
    int32_t result  = 0;
#endif

    return result >> 8;
  }

private:
  INLINE const int8_t* get_wave_table(uint8_t waveform, uint8_t note_number) {
    const int8_t* result;
    if ((waveform == WAVEFORM_SAW) ||
        (m_mono_mode && (waveform == WAVEFORM_1_PULSE))) {
      result = g_osc_saw_wave_tables[note_number - NOTE_NUMBER_MIN];
    } else if (waveform == WAVEFORM_TRIANGLE) {
      result = g_osc_triangle_wave_table;
    } else {     // WAVEFORM_SQUARE
      result = g_osc_pulse_wave_tables[note_number - NOTE_NUMBER_MIN];
    }
    return result;
  }

  INLINE int16_t get_wave_level(const int8_t* wave_table, uint16_t phase) {
    uint8_t curr_index  = phase >> 8;
    uint8_t next_weight = phase & 0xFF;
    int8_t  curr_data   = wave_table[curr_index + 0];
    int8_t  next_data   = wave_table[curr_index + 1];

    // lerp
    int16_t result = (curr_data << 8) + ((next_data - curr_data) * next_weight);

    return result;
  }

  INLINE int16_t get_lfo_wave_level(uint16_t phase) {
    int16_t level = 0;

    switch (m_lfo_waveform) {
    case LFO_WAVEFORM_TRI_ASYNC:
    case LFO_WAVEFORM_TRI_SYNC:
      level = static_cast<int16_t>(phase) >> 1;
      if (level < -(64 << 7)) {
        level = -(64 << 7) - (level + (64 << 7));
      } else if (level < (64 << 7)) {
        // do nothing
      } else {
        level = (64 << 7) - (level - (64 << 7));
      }
      break;
    case LFO_WAVEFORM_SAW_DOWN:
      {
        level = (64 << 7) - (phase >> 2);
      }
      break;
    case LFO_WAVEFORM_RANDOM:
      if (phase < m_lfo_rate) {
        m_lfo_sampled = (m_rnd << 6);
      }
      level = (64 << 7) - m_lfo_sampled;
      break;
    case LFO_WAVEFORM_SQUARE:
      if (phase < 0x8000) {
        level = 128 << 7;
      } else {
        level = 0;
      }
      break;
    }

    return level;
  }

  template <uint8_t N>
  INLINE void update_freq_0th() {
    m_osc_on_temp[N] = m_osc_on[N];

    if (m_osc_on_temp[N]) {
      if ((m_portamento_coef[N] == PORTAMENTO_COEF_OFF) || (m_pitch_current[N] <= m_pitch_target[N])) {
        m_pitch_current[N] = m_pitch_target[N]  - (((m_pitch_target[N] - m_pitch_current[N]) *        m_portamento_coef[N] ) >> 8);
      } else {
        m_pitch_current[N] = m_pitch_current[N] + (((m_pitch_target[N] - m_pitch_current[N]) * (256 - m_portamento_coef[N])) >> 8);
      }
    }
  }

  template <uint8_t N>
  INLINE void update_freq_1st(int16_t eg_level) {
    int8_t pitch_eg_amt;
    if ((N == 2) && m_mono_mode) {
      pitch_eg_amt = m_pitch_eg_amt[1];
    } else {
      pitch_eg_amt = m_pitch_eg_amt[0];
    }
    m_pitch_real[N] =  (64 << 8) + m_pitch_current[N] + m_pitch_bend_normalized + ((pitch_eg_amt * eg_level) >> 8);

    uint8_t coarse = high_byte(m_pitch_real[N]);
    if (coarse < (NOTE_NUMBER_MIN + 64)) {
      m_pitch_real[N] = ((NOTE_NUMBER_MIN + 64) << 8);
    } else if (coarse >= (NOTE_NUMBER_MAX + 64)) {
      m_pitch_real[N] = ((NOTE_NUMBER_MAX + 64) << 8);
    }

    if (m_mono_mode && (N == 2)) {
      m_pitch_real[N] += m_lfo_mod_level[1];
      m_pitch_real[N] += (m_mono_osc2_pitch << 8) + m_mono_osc2_detune + m_mono_osc2_detune;
    } else {
      m_pitch_real[N] += m_lfo_mod_level[0];
    }

    coarse = high_byte(m_pitch_real[N]);
    if (coarse < (NOTE_NUMBER_MIN + 64)) {
      m_pitch_real[N] = NOTE_NUMBER_MIN << 8;
    } else if (coarse >= (NOTE_NUMBER_MAX + 64)) {
      m_pitch_real[N] = NOTE_NUMBER_MAX << 8;
    } else {
      m_pitch_real[N] -= (64 << 8);
    }

    m_pitch_real[N] += 128;  // For g_osc_tune_table[]
  }

  template <uint8_t N>
  INLINE void update_freq_2nd() {
    uint8_t coarse = high_byte(m_pitch_real[N]);
    m_freq_temp[N] = g_osc_freq_table[coarse - NOTE_NUMBER_MIN];
    if ((N == 2) && m_mono_mode) {
      m_wave_table_temp[N] = get_wave_table(m_waveform[1], coarse);
    } else {
      m_wave_table_temp[N] = get_wave_table(m_waveform[0], coarse);
    }
  }

  template <uint8_t N>
  INLINE void update_freq_3rd() {
    uint8_t fine = low_byte(m_pitch_real[N]);
    uint16_t freq_div_2 = (m_freq_temp[N] >> 1);
    uint8_t bit = (m_rnd >= 0xF0);
    uint8_t mono_offset = 0;
    if (N == 2) {
      if (m_mono_mode) {
        if (m_freq_temp[0] == m_freq_temp[2]) {
          mono_offset = 1;
        }
      }
    }
    int8_t freq_offset = high_sbyte(freq_div_2 * g_osc_tune_table[fine >> (8 - OSC_TUNE_TABLE_STEPS_BITS)]) + bit + mono_offset;
    m_freq[N] = m_freq_temp[N] + freq_offset;
    m_wave_table[N] = m_wave_table_temp[N];
  }

  template <uint8_t N>
  INLINE void update_gate() {
    if (m_mono_mode == false) {
      if (m_osc_on_temp[N]) {
        const int8_t half_level = (m_osc_level >> 1) + 1;

        if (m_osc_gain[N] >= (m_osc_level - half_level)) {
          m_osc_gain[N] = m_osc_level;
        } else {
          m_osc_gain[N] += half_level;
        }
      } else {
        const int8_t one_fourth_level = (m_osc_level >> 2) + 1;

        if (m_osc_gain[N] <= one_fourth_level) {
          m_osc_gain[N] = 0;
        } else {
          m_osc_gain[N] -= one_fourth_level;
        }
      }
      m_osc_gain_effective[N] = m_osc_gain[N];
    } else {
      if (N == 0) {
        uint8_t base_gain = m_osc_level << 1;
        m_osc_gain_effective[0] = high_byte(m_mix_table[(OSC_MIX_TABLE_LENGTH - 1) - m_mono_osc2_mix] * base_gain);
        m_osc_gain_effective[2] = high_byte(m_mix_table[                             m_mono_osc2_mix] * base_gain);
        m_osc_gain_effective[1] = (base_gain * m_mixer_sub_osc_control) >> 6;
        m_osc_gain_effective[3] = 0;

        if (m_waveform[0] == WAVEFORM_1_PULSE) {
          int8_t temp = high_sbyte(-m_osc_gain_effective[0] * m_osc1_morph_control);
          m_osc_gain_effective[3] = temp << 2;
        }
      }
    }
  }

  INLINE void update_rnd() {
    // TODO
    m_rnd ^= m_rnd << 1;
    m_rnd ^= m_rnd >> 1;
    m_rnd ^= m_rnd << 2;
  }

  INLINE void update_lfo_1st() {
    ;
  }

  INLINE void update_lfo_2nd() {
    --m_lfo_fade_cnt;
    if (m_lfo_fade_cnt == 0) {
      m_lfo_fade_cnt = m_lfo_fade_coef;
      if (m_lfo_fade_level < LFO_FADE_LEVEL_MAX) {
        m_lfo_fade_level += 2;
      }
    }

    m_lfo_phase += m_lfo_rate;
    m_lfo_wave_level = get_lfo_wave_level(m_lfo_phase);
  }

  INLINE void update_lfo_3rd() {
    uint8_t lfo_depth = high_byte((m_lfo_depth[0] << 1) * m_lfo_fade_level) + m_lfo_depth[1];
    if (lfo_depth > 64) {
      lfo_depth = 64;
    }
    lfo_depth <<= 1;

    m_lfo_level = (lfo_depth * m_lfo_wave_level) >> 9;
  }

  INLINE void update_lfo_4th(int16_t eg_level) {
    m_lfo_mod_level[0] = (m_lfo_level * m_pitch_lfo_amt[0]) >> 7;

    if (m_mono_mode) {
      m_osc1_shape_control_effective += (m_osc1_shape_control_effective < m_osc1_shape_control) << 1;
      m_osc1_shape_control_effective -= (m_osc1_shape_control_effective > m_osc1_shape_control) << 1;

      m_lfo_mod_level[1] = ((m_lfo_level * m_pitch_lfo_amt[1])) >> 7;
      uint16_t shape_eg_mod  = (eg_level * m_shape_eg_amt) >> 6;
      uint16_t shape_lfo_mod = -((m_lfo_level * m_shape_lfo_amt) >> 3);
      m_osc1_shape = 0x8000u - (m_osc1_shape_control_effective << 8) +
        + shape_eg_mod + shape_eg_mod + shape_lfo_mod;
    } else {
      m_lfo_mod_level[1] = m_lfo_mod_level[0];
    }
  }

  INLINE void update_chorus_lfo_0th() {
    m_chorus_delay_time_control_effective += (m_chorus_delay_time_control_effective < m_chorus_delay_time_control);
    m_chorus_delay_time_control_effective -= (m_chorus_delay_time_control_effective > m_chorus_delay_time_control);

    if (m_chorus_delay_time_control_effective < 64) {
      if (m_chorus_depth_control > (m_chorus_delay_time_control_effective << 1)) {
        m_chorus_depth_control_actual = (m_chorus_delay_time_control_effective << 1);
      } else {
        m_chorus_depth_control_actual = m_chorus_depth_control;
      }
    } else {
      if (m_chorus_depth_control > ((127 - m_chorus_delay_time_control_effective) << 1)) {
        m_chorus_depth_control_actual = ((127 - m_chorus_delay_time_control_effective) << 1);
      } else {
        m_chorus_depth_control_actual = m_chorus_depth_control;
      }
    }

    m_chorus_lfo_phase += m_chorus_rate_control;
  }

  INLINE void update_chorus_lfo_1st() {
    m_chorus_lfo_wave_level = get_chorus_lfo_wave_level(m_chorus_lfo_phase);
  }

  INLINE void update_chorus_lfo_2nd() {
    m_chorus_lfo_level = (m_chorus_lfo_wave_level * m_chorus_depth_control_actual) >> 8;
  }

  INLINE void update_chorus_lfo_3rd() {
    switch (m_chorus_mode) {
    case CHORUS_MODE_OFF      :
      {
        m_chorus_delay_time[0] = 0;
        m_chorus_delay_time[1] = 0;
      }
      break;
    case CHORUS_MODE_STEREO   :
    case CHORUS_MODE_P_STEREO :
    case CHORUS_MODE_MONO     :
      {
        uint16_t chorus_delay_time_control_mul_4 = m_chorus_delay_time_control_effective * 4;
        m_chorus_delay_time[0] = chorus_delay_time_control_mul_4 + m_chorus_lfo_level;
        m_chorus_delay_time[1] = m_chorus_delay_time[0];
      }
      break;
    case CHORUS_MODE_STEREO_2 :
      {
        uint16_t chorus_delay_time_control_mul_4 = m_chorus_delay_time_control_effective * 4;
        m_chorus_delay_time[0] = chorus_delay_time_control_mul_4 - m_chorus_lfo_level;
        m_chorus_delay_time[1] = chorus_delay_time_control_mul_4 + m_chorus_lfo_level;
      }
      break;
    }
  }

  INLINE int16_t get_chorus_lfo_wave_level(uint16_t phase) {
    int16_t triangle_wave_level = 0;
    phase &= 0x1FFC;
    phase = (phase >> 2);

    if (phase < 0x0400) {
      triangle_wave_level = phase - 512;
    } else {
      triangle_wave_level = 1535 - phase;
    }

    return triangle_wave_level;
  }

  INLINE void update_pitch_bend() {
    int16_t b = m_pitch_bend + 1;
    b >>= 3;
    m_pitch_bend_normalized = (b * m_pitch_bend_range) >> 2;
  }
};
