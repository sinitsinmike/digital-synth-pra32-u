/*
 * Digital Synth PRA32-U
 *
 * - An I2S DAC hardware (e.g. Pico Audio Pack) is required
 * - Raspberry Pi Pico/RP2040 core version 3.2.0 is recommended
 * - Select CPU Speed: "120 MHz" in the Arduino IDE "Tools" menu
 */

#define DEBUG_PRINT

#define USE_USB_MIDI      // Select USB Stack: "Adafruit TinuUSB" in the Arduino IDE "Tools" menu
//#define USE_SERIAL1_MIDI

#define SERIAL1_MIDI_SPEED           (31250)
//#define SERIAL1_MIDI_SPEED           (38400)

#define MIDI_CH                      (0)  // 0-based

#define I2S_DAC_MUTE_OFF_PIN         (22)

#define I2S_DATA_PIN                 (9)
#define I2S_BCLK_PIN                 (10)  // I2S_LRCLK_PIN is I2S_BCLK_PIN + 1
#define I2S_SWAP_BCLK_AND_LRCLK_PINS (false)

#define I2S_BUFFERS                  (4)
#define I2S_BUFFER_WORDS             (32)

////////////////////////////////////////////////////////////////

#include "pra32-u-common.h"
#include "pra32-u-synth.h"

PRA32_U_Synth g_synth;

#include <MIDI.h>
#if defined(USE_USB_MIDI)
#include <Adafruit_TinyUSB.h>
Adafruit_USBD_MIDI usbd_midi;
MIDI_CREATE_INSTANCE(Adafruit_USBD_MIDI, usbd_midi, MIDI);
#elif defined(USE_SERIAL1_MIDI)
MIDI_CREATE_INSTANCE(HardwareSerial, Serial1, MIDI);
#endif

#include <I2S.h>

I2S g_i2s_output(OUTPUT);

void handleNoteOn(byte channel, byte pitch, byte velocity);
void handleNoteOff(byte channel, byte pitch, byte velocity);
void handleControlChange(byte channel, byte number, byte value);
void handleHandleProgramChange(byte channel, byte number);
void handleHandlePitchBend(byte channel, int bend);

void __not_in_flash_func(setup)() {
}

void __not_in_flash_func(loop)() {
}

void __not_in_flash_func(setup1)() {
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);

#if defined(USE_USB_MIDI)
  TinyUSB_Device_Init(0);
#endif
  MIDI.setHandleNoteOn(handleNoteOn);
  MIDI.setHandleNoteOff(handleNoteOff);
  MIDI.setHandleControlChange(handleControlChange);
  MIDI.setHandleProgramChange(handleHandleProgramChange);
  MIDI.setHandlePitchBend(handleHandlePitchBend);
  MIDI.begin(MIDI_CHANNEL_OMNI);
#if defined(USE_SERIAL1_MIDI)
  Serial1.begin(SERIAL1_MIDI_SPEED);
#endif

  g_i2s_output.setDATA(I2S_DATA_PIN);
  g_i2s_output.setBCLK(I2S_BCLK_PIN);
  g_i2s_output.setBitsPerSample(16);
  g_i2s_output.setBuffers(I2S_BUFFERS, I2S_BUFFER_WORDS);
  g_i2s_output.setFrequency(SAMPLING_RATE);
  if (I2S_SWAP_BCLK_AND_LRCLK_PINS) {
    g_i2s_output.swapClocks();
  }
  g_i2s_output.begin();

#if defined(I2S_DAC_MUTE_OFF_PIN)
  pinMode(I2S_DAC_MUTE_OFF_PIN, OUTPUT);
  digitalWrite(I2S_DAC_MUTE_OFF_PIN, HIGH);
#endif

#if defined(DEBUG_PRINT)
#if defined(USE_SERIAL1_MIDI)
  Serial.begin(0);  // Select USB Stack: "Pico SDK" in the Arduino IDE "Tools" menu
#else
  Serial1.begin(115200);
#endif
#endif
}

void __not_in_flash_func(loop1)() {

#if defined(DEBUG_PRINT)
  uint32_t debug_measurement_start0_us = micros();
#endif

  for (uint32_t i = 0; i < (I2S_BUFFER_WORDS >> 4); i++) {
    MIDI.read();
  }

#if defined(DEBUG_PRINT)
  uint32_t debug_measurement_start1_us = micros();
#endif

  int16_t left_buffer[I2S_BUFFER_WORDS];
  int16_t right_buffer[I2S_BUFFER_WORDS];
  for (uint32_t i = 0; i < I2S_BUFFER_WORDS; i++) {
    left_buffer[i] = g_synth.process(right_buffer[i]);
  }

#if defined(DEBUG_PRINT)
  uint32_t debug_measurement_end_us = micros();
#endif

  for (uint32_t i = 0; i < I2S_BUFFER_WORDS; i++) {
    g_i2s_output.write16(left_buffer[i], right_buffer[i]);
  }

#if defined(DEBUG_PRINT)
  static uint32_t s_debug_measurement_max0_us = 0;
  uint32_t debug_measurement_elapsed0_us = debug_measurement_end_us - debug_measurement_start0_us;
  s_debug_measurement_max0_us += (debug_measurement_elapsed0_us > s_debug_measurement_max0_us) *
                                 (debug_measurement_elapsed0_us - s_debug_measurement_max0_us);

  static uint32_t s_debug_measurement_max1_us = 0;
  uint32_t debug_measurement_elapsed1_us = debug_measurement_end_us - debug_measurement_start1_us;
  s_debug_measurement_max1_us += (debug_measurement_elapsed1_us > s_debug_measurement_max1_us) *
                                 (debug_measurement_elapsed1_us - s_debug_measurement_max1_us);

  static uint32_t s_debug_loop_counter = 0;
  if (++s_debug_loop_counter == 4000) {
    s_debug_loop_counter = 0;
#if defined(USE_SERIAL1_MIDI)
    Serial.println(debug_measurement_elapsed1_us);
    Serial.println(s_debug_measurement_max1_us);
    Serial.println(debug_measurement_elapsed0_us);
    Serial.println(s_debug_measurement_max0_us);
    Serial.println();
#else
    Serial1.println(debug_measurement_elapsed1_us);
    Serial1.println(s_debug_measurement_max1_us);
    Serial1.println(debug_measurement_elapsed0_us);
    Serial1.println(s_debug_measurement_max0_us);
    Serial1.println();
#endif
  }
#endif
}

void __not_in_flash_func(handleNoteOn)(byte channel, byte pitch, byte velocity)
{
  if ((channel - 1) == MIDI_CH) {
    if (velocity > 0) {
      g_synth.note_on(pitch, velocity);
    } else {
      g_synth.note_off(pitch);
    }
  }
}

void __not_in_flash_func(handleNoteOff)(byte channel, byte pitch, byte velocity)
{
  if ((channel - 1) == MIDI_CH) {
    (void) velocity;
    g_synth.note_off(pitch);
  }
}

void __not_in_flash_func(handleControlChange)(byte channel, byte number, byte value)
{
  if ((channel - 1) == MIDI_CH) {
    g_synth.control_change(number, value);
  }
}

void __not_in_flash_func(handleHandleProgramChange)(byte channel, byte number)
{
  if ((channel - 1) == MIDI_CH) {
    g_synth.program_change(number);
  }
}

void __not_in_flash_func(handleHandlePitchBend)(byte channel, int bend)
{
  if ((channel - 1) == MIDI_CH) {
    g_synth.pitch_bend(bend & 0x7F, bend >> 7);
  }
}
