#pragma once

const uint8_t   PANEL_PITCH     = 128 + 0;
const uint8_t   PANEL_SCALE     = 128 + 1;
const uint8_t   PANEL_TRANSPOSE = 128 + 2;

const uint8_t   PC_BY_PANEL_0   = 128 + 64;
const uint8_t   PC_BY_PANEL_1   = 128 + 65;
const uint8_t   PC_BY_PANEL_2   = 128 + 66;
const uint8_t   PC_BY_PANEL_3   = 128 + 67;
const uint8_t   PC_BY_PANEL_4   = 128 + 68;
const uint8_t   PC_BY_PANEL_5   = 128 + 69;
const uint8_t   PC_BY_PANEL_6   = 128 + 70;
const uint8_t   PC_BY_PANEL_7   = 128 + 71;

const uint8_t   PC_BY_PANEL_8   = 128 + 72;
const uint8_t   PC_BY_PANEL_9   = 128 + 73;
const uint8_t   PC_BY_PANEL_10  = 128 + 74;
const uint8_t   PC_BY_PANEL_11  = 128 + 75;
const uint8_t   PC_BY_PANEL_12  = 128 + 76;
const uint8_t   PC_BY_PANEL_13  = 128 + 77;
const uint8_t   PC_BY_PANEL_14  = 128 + 78;
const uint8_t   PC_BY_PANEL_15  = 128 + 79;

const uint8_t   WR_BY_PANEL_0   = 128 + 80;  // Invalid
const uint8_t   WR_BY_PANEL_1   = 128 + 81;  // Invalid
const uint8_t   WR_BY_PANEL_2   = 128 + 82;  // Invalid
const uint8_t   WR_BY_PANEL_3   = 128 + 83;  // Invalid
const uint8_t   WR_BY_PANEL_4   = 128 + 84;  // Invalid
const uint8_t   WR_BY_PANEL_5   = 128 + 85;  // Invalid
const uint8_t   WR_BY_PANEL_6   = 128 + 86;  // Invalid
const uint8_t   WR_BY_PANEL_7   = 128 + 87;  // Invalid

const uint8_t   WR_BY_PANEL_8   = 128 + 88;
const uint8_t   WR_BY_PANEL_9   = 128 + 89;
const uint8_t   WR_BY_PANEL_10  = 128 + 90;
const uint8_t   WR_BY_PANEL_11  = 128 + 91;
const uint8_t   WR_BY_PANEL_12  = 128 + 92;
const uint8_t   WR_BY_PANEL_13  = 128 + 93;
const uint8_t   WR_BY_PANEL_14  = 128 + 94;
const uint8_t   WR_BY_PANEL_15  = 128 + 95;

struct PRA32_U_ControlPanelPage {
  char    page_name_line_0            [10 + 1];
  char    page_name_line_1            [10 + 1];
  char    control_target_a_name_line_0[10 + 1];
  char    control_target_a_name_line_1[10 + 1];
  uint8_t control_target_a;
  char    control_target_b_name_line_0[10 + 1];
  char    control_target_b_name_line_1[10 + 1];
  uint8_t control_target_b;
  char    control_target_c_name_line_0[10 + 1];
  char    control_target_c_name_line_1[10 + 1];
  uint8_t control_target_c;
} g_control_panel_page_table[] = {
  { "Page= 1   ", "Voice     ",   "Voice     ", "Mode      ", VOICE_MODE     ,   "Portamento", "          ", PORTAMENTO     ,   "Pitch     ", "Bend Range", P_BEND_RANGE   , },
  { "Page= 2   ", "Osc 1     ",   "Osc 1     ", "Wave      ", OSC_1_WAVE     ,   "Osc 1     ", "Shape     ", OSC_1_SHAPE    ,   "Osc 1     ", "Morph     ", OSC_1_MORPH    , },
  { "Page= 3   ", "Osc 2     ",   "Osc 2     ", "Wave      ", OSC_2_WAVE     ,   "Osc 2     ", "Coarse    ", OSC_2_COARSE   ,   "Osc 2     ", "Pitch     ", OSC_2_PITCH    , },
  { "Page= 4   ", "Mixer     ",   "Mixer     ", "Osc Mix   ", MIXER_OSC_MIX  ,   "Mixer     ", "Noise/Sub ", MIXER_SUB_OSC  ,   "          ", "          ", 0xFF           , },
  { "Page= 5   ", "Filter a  ",   "Filter    ", "Cutoff    ", FILTER_CUTOFF  ,   "Filter    ", "Resonance ", FILTER_RESO    ,   "Filter    ", "EG Amt    ", FILTER_EG_AMT  , },
  { "Page= 6   ", "Filter b  ",   "Filter    ", "Key Track ", FILTER_KEY_TRK ,   "Filter    ", "Mode      ", FILTER_MODE    ,   "          ", "          ", 0xFF           , },
  { "Page= 7   ", "EG a      ",   "EG        ", "Attack    ", EG_ATTACK      ,   "EG        ", "Decay     ", EG_DECAY       ,   "EG        ", "Sustain   ", EG_SUSTAIN     , },
  { "Page= 8   ", "EG b      ",   "EG        ", "Release   ", EG_RELEASE     ,   "EG        ", "Amp Mod   ", EG_AMP_MOD     ,   "Release   ", "= Decay   ", REL_EQ_DECAY   , },
  { "Page= 9   ", "EG c      ",   "EG        ", "Osc Amt   ", EG_OSC_AMT     ,   "EG        ", "Osc Dst   ", EG_OSC_DST     ,   "EG        ", "Velo Sens ", EG_VEL_SENS    , },
  { "Page=10   ", "Amp a     ",   "Amp       ", "Attack    ", AMP_ATTACK     ,   "Amp       ", "Decay     ", AMP_DECAY      ,   "Amp       ", "Sustain   ", AMP_SUSTAIN    , },
  { "Page=11   ", "Amp b     ",   "Amp       ", "Release   ", AMP_RELEASE    ,   "Amp       ", "Gain      ", AMP_GAIN       ,   "Amp       ", "Velo Sens ", AMP_VEL_SENS   , },
  { "Page=12   ", "LFO a     ",   "LFO       ", "Wave      ", LFO_WAVE       ,   "LFO       ", "Rate      ", LFO_RATE       ,   "LFO       ", "Depth     ", LFO_DEPTH      , },
  { "Page=13   ", "LFO b     ",   "LFO       ", "Fade Time ", LFO_FADE_TIME  ,   "          ", "          ", 0xFF           ,   "          ", "          ", 0xFF           , },
  { "Page=14   ", "LFO c     ",   "LFO       ", "Osc Amt   ", LFO_OSC_AMT    ,   "LFO       ", "Osc Dst   ", LFO_OSC_DST    ,   "LFO       ", "Filter Amt", LFO_FILTER_AMT , },
  { "Page=15   ", "Breath    ",   "Breath    ", "Filter Amt", BTH_FILTER_AMT ,   "Breath    ", "Amp Mod   ", BTH_AMP_MOD    ,   "          ", "          ", 0xFF           , },
  { "Page=16   ", "Chorus    ",   "Chorus    ", "Mix       ", CHORUS_MIX     ,   "Chorus    ", "Rate      ", CHORUS_RATE    ,   "Chorus    ", "Depth     ", CHORUS_DEPTH   , },
  { "Page=17   ", "Delay     ",   "Delay     ", "Feedback  ", DELAY_FEEDBACK ,   "Delay     ", "Time      ", DELAY_TIME     ,   "Delay     ", "Mode      ", DELAY_MODE     , },
  { "Page=18   ", "Write a   ",   "Write     ", "Program  8", WR_BY_PANEL_8  ,   "Write     ", "Program  9", WR_BY_PANEL_9  ,   "          ", "          ", 0xFF           , },
  { "Page=19   ", "Write b   ",   "Write     ", "Program 10", WR_BY_PANEL_10 ,   "Write     ", "Program 11", WR_BY_PANEL_11 ,   "          ", "          ", 0xFF           , },
  { "Page=20   ", "Write c   ",   "Write     ", "Program 12", WR_BY_PANEL_12 ,   "Write     ", "Program 13", WR_BY_PANEL_13 ,   "          ", "          ", 0xFF           , },
  { "Page=21   ", "Write d   ",   "Write     ", "Program 14", WR_BY_PANEL_14 ,   "Write     ", "Program 15", WR_BY_PANEL_15 ,   "          ", "          ", 0xFF           , },
  { "Page=22   ", "Read a    ",   "Read      ", "Program  0", PC_BY_PANEL_0  ,   "Read      ", "Program  1", PC_BY_PANEL_1  ,   "          ", "          ", 0xFF           , },
  { "Page=23   ", "Read b    ",   "Read      ", "Program  2", PC_BY_PANEL_2  ,   "Read      ", "Program  3", PC_BY_PANEL_3  ,   "          ", "          ", 0xFF           , },
  { "Page=24   ", "Read c    ",   "Read      ", "Program  4", PC_BY_PANEL_4  ,   "Read      ", "Program  5", PC_BY_PANEL_5  ,   "          ", "          ", 0xFF           , },
  { "Page=25   ", "Read d    ",   "Read      ", "Program  6", PC_BY_PANEL_6  ,   "Read      ", "Program  7", PC_BY_PANEL_7  ,   "          ", "          ", 0xFF           , },
  { "Page=26   ", "Read e    ",   "Read      ", "Program  8", PC_BY_PANEL_8  ,   "Read      ", "Program  9", PC_BY_PANEL_9  ,   "          ", "          ", 0xFF           , },
  { "Page=27   ", "Read f    ",   "Read      ", "Program 10", PC_BY_PANEL_10 ,   "Read      ", "Program 11", PC_BY_PANEL_11 ,   "          ", "          ", 0xFF           , },
  { "Page=28   ", "Read g    ",   "Read      ", "Program 12", PC_BY_PANEL_12 ,   "Read      ", "Program 13", PC_BY_PANEL_13 ,   "          ", "          ", 0xFF           , },
  { "Page=29   ", "Read h    ",   "Read      ", "Program 14", PC_BY_PANEL_14 ,   "Read      ", "Program 15", PC_BY_PANEL_15 ,   "          ", "          ", 0xFF           , },
  { "Page=30   ", "Panel a   ",   "Filter    ", "Cutoff    ", FILTER_CUTOFF  ,   "Filter    ", "Resonance ", FILTER_RESO    ,   "Panel     ", "Pitch     ", PANEL_PITCH    , },
  { "Page=31   ", "Panel b   ",   "Modulation", "          ", MODULATION     ,   "Breath    ", "Controller", BTH_CONTROLLER ,   "Panel     ", "Pitch     ", PANEL_PITCH    , },
  { "Page=32   ", "Panel c   ",   "Sustain   ", "Pedal     ", SUSTAIN_PEDAL  ,   "          ", "          ", 0xFF           ,   "Panel     ", "Pitch     ", PANEL_PITCH    , },
  { "Page=33   ", "Panel d   ",   "Panel     ", "Scale     ", PANEL_SCALE    ,   "Panel     ", "Transpose ", PANEL_TRANSPOSE,   "Panel     ", "Pitch     ", PANEL_PITCH    , },
};
