#pragma once

#include "pra32-u-common.h"
#include "pra32-u-lfo-table.h"

class PRA32_U_LFO {
  static const uint8_t LFO_WAVEFORM_TRI_ASYNC = 0;
  static const uint8_t LFO_WAVEFORM_TRI_SYNC  = 1;
  static const uint8_t LFO_WAVEFORM_SAW_DOWN  = 2;
  static const uint8_t LFO_WAVEFORM_RANDOM    = 3;
  static const uint8_t LFO_WAVEFORM_SQUARE    = 4;

  static const uint8_t LFO_FADE_COEF_OFF      = 1;
  static const uint8_t LFO_FADE_COEF_ON_MIN   = 2;

  static const uint8_t LFO_FADE_LEVEL_MAX     = 128;

  uint16_t m_lfo_phase;
  int16_t  m_lfo_wave_level;
  int16_t  m_lfo_level;
  uint16_t m_lfo_rate;
  uint8_t  m_lfo_depth[2];
  uint8_t  m_lfo_waveform;
  uint8_t  m_lfo_sampled;
  uint8_t  m_lfo_fade_coef;
  uint8_t  m_lfo_fade_cnt;
  uint8_t  m_lfo_fade_level;
  uint8_t  m_rnd;

public:
  PRA32_U_LFO()
  : m_lfo_phase()
  , m_lfo_wave_level()
  , m_lfo_level()
  , m_lfo_rate()
  , m_lfo_depth()
  , m_lfo_waveform()
  , m_lfo_sampled()
  , m_lfo_fade_coef()
  , m_lfo_fade_cnt()
  , m_lfo_fade_level()
  , m_rnd()
  {}

  INLINE void initialize() {
    m_lfo_waveform = LFO_WAVEFORM_TRI_ASYNC;
    m_lfo_sampled = 64;
    m_lfo_fade_coef = LFO_FADE_COEF_OFF;
    m_lfo_fade_cnt = m_lfo_fade_coef;
    m_lfo_fade_level = LFO_FADE_LEVEL_MAX;
    m_rnd = 1;
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

  INLINE void set_lfo_fade_time(uint8_t controller_value) {
    m_lfo_fade_coef = high_byte(controller_value * controller_value) + LFO_FADE_COEF_OFF;
  }

  INLINE void trigger_lfo() {
    if (m_lfo_waveform != LFO_WAVEFORM_TRI_ASYNC) {
      m_lfo_phase = 0xFFFF;
    }

    if (m_lfo_fade_coef >= LFO_FADE_COEF_ON_MIN) {
      m_lfo_fade_level = 0;
    }
  }

  INLINE int16_t get_lfo_level() {
    return m_lfo_level;
  }

  INLINE uint8_t get_rnd() {
    return m_rnd;
  }

  INLINE void process(uint8_t count) {
#if 1
    if ((count & (OSC_CONTROL_INTERVAL - 1)) == 0) {
      //printf("%d LFO\n", count);
      switch ((count >> OSC_CONTROL_INTERVAL_BITS) & 0x1F) {
      case 0x05: update_rnd();                 break;
      case 0x07: update_lfo_2nd();             break;
      case 0x0D: update_rnd();                 break;
      case 0x0E: update_lfo_3rd();             break;
      case 0x15: update_rnd();                 break;
      case 0x1D: update_rnd();                 break;
      }
    }
#endif

    return;
  }

private:
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

  INLINE void update_rnd() {
    // TODO
    m_rnd ^= m_rnd << 1;
    m_rnd ^= m_rnd >> 1;
    m_rnd ^= m_rnd << 2;
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
};