#pragma once

const uint8_t PROGRAM_NUMBER_DEFAULT = 0;

// PRESET                                   #0   #1   #2   #3   #4   #5   #6   #7     #8   #9   #10  #11  #12  #13  #14  #15  
uint8_t g_preset_table_OSC_1_WAVE     [] = {100, 100, 100, 100, 100, 100, 100, 0  ,   100, 100, 100, 100, 100, 100, 100, 0  };
uint8_t g_preset_table_OSC_1_SHAPE    [] = {0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  ,   0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  };
uint8_t g_preset_table_OSC_1_MORPH    [] = {64 , 64 , 64 , 64 , 64 , 0  , 127, 0  ,   64 , 64 , 64 , 64 , 64 , 0  , 127, 0  };
uint8_t g_preset_table_MIXER_SUB_OSC  [] = {127, 127, 127, 127, 127, 127, 127, 64 ,   127, 127, 127, 127, 127, 127, 127, 64 };

uint8_t g_preset_table_OSC_2_WAVE     [] = {0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  ,   0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  };
uint8_t g_preset_table_OSC_2_COARSE   [] = {64 , 64 , 64 , 64 , 64 , 64 , 64 , 64 ,   64 , 64 , 64 , 64 , 64 , 64 , 64 , 64 };
uint8_t g_preset_table_OSC_2_PITCH    [] = {109, 72 , 72 , 72 , 72 , 72 , 72 , 64 ,   109, 72 , 72 , 72 , 72 , 72 , 72 , 64 };
uint8_t g_preset_table_MIXER_OSC_MIX  [] = {64 , 64 , 64 , 64 , 64 , 64 , 64 , 0  ,   64 , 64 , 64 , 64 , 64 , 64 , 64 , 0  };

uint8_t g_preset_table_FILTER_CUTOFF  [] = {115, 115, 91 , 115, 67 , 115, 67 , 127,   115, 115, 91 , 115, 67 , 115, 67 , 127};
uint8_t g_preset_table_FILTER_RESO    [] = {64 , 64 , 32 , 32 , 64 , 64 , 32 , 0  ,   64 , 64 , 32 , 32 , 64 , 64 , 32 , 0  };
uint8_t g_preset_table_FILTER_EG_AMT  [] = {64 , 64 , 88 , 16 , 112, 64 , 76 , 64 ,   64 , 64 , 88 , 16 , 112, 64 , 76 , 64 };
uint8_t g_preset_table_FILTER_KEY_TRK [] = {64 , 64 , 64 , 64 , 64 , 64 , 64 , 0  ,   64 , 64 , 64 , 64 , 64 , 64 , 64 , 0  };

uint8_t g_preset_table_EG_ATTACK      [] = {0  , 64 , 48 , 96 , 0  , 0  , 0  , 0  ,   0  , 64 , 48 , 96 , 0  , 0  , 0  , 0  };
uint8_t g_preset_table_EG_DECAY       [] = {0  , 0  , 80 , 96 , 96 , 0  , 104, 0  ,   0  , 0  , 80 , 96 , 96 , 0  , 104, 0  };
uint8_t g_preset_table_EG_SUSTAIN     [] = {127, 127, 0  , 0  , 0  , 127, 0  , 127,   127, 127, 0  , 0  , 0  , 127, 0  , 127};
uint8_t g_preset_table_EG_RELEASE     [] = {0  , 64 , 0  , 0  , 96 , 0  , 0  , 0  ,   0  , 64 , 0  , 0  , 96 , 0  , 0  , 0  };

uint8_t g_preset_table_EG_OSC_AMT     [] = {64 , 64 , 70 , 64 , 64 , 64 , 88 , 64 ,   64 , 64 , 70 , 64 , 64 , 64 , 88 , 64 };
uint8_t g_preset_table_EG_OSC_DST     [] = {0  , 0  , 64 , 0  , 0  , 0  , 127, 0  ,   0  , 0  , 64 , 0  , 0  , 0  , 127, 0  };
uint8_t g_preset_table_VOICE_MODE     [] = {127, 0  , 0  , 0  , 75 , 127, 0  , 0  ,   127, 0  , 0  , 0  , 75 , 127, 0  , 0  };
uint8_t g_preset_table_PORTAMENTO     [] = {0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  ,   0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  };

uint8_t g_preset_table_LFO_WAVE       [] = {0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  ,   0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  };
uint8_t g_preset_table_LFO_RATE       [] = {80 , 80 , 80 , 80 , 80 , 80 , 80 , 80 ,   80 , 80 , 80 , 80 , 80 , 80 , 80 , 80 };
uint8_t g_preset_table_LFO_DEPTH      [] = {0  , 0  , 0  , 0  , 0  , 127, 0  , 0  ,   0  , 0  , 0  , 0  , 0  , 127, 0  , 0  };
uint8_t g_preset_table_LFO_FADE_TIME  [] = {0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  ,   0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  };

uint8_t g_preset_table_LFO_OSC_AMT    [] = {119, 119, 119, 119, 64 , 96 , 64 , 64 ,   119, 119, 119, 119, 64 , 96 , 64 , 64 };
uint8_t g_preset_table_LFO_OSC_DST    [] = {0  , 0  , 0  , 0  , 0  , 127, 0  , 0  ,   0  , 0  , 0  , 0  , 0  , 127, 0  , 0  };
uint8_t g_preset_table_LFO_FILTER_AMT [] = {64 , 64 , 64 , 64 , 88 , 64 , 88 , 64 ,   64 , 64 , 64 , 64 , 88 , 64 , 88 , 64 };
uint8_t g_preset_table_AMP_GAIN       [] = {100, 100, 100, 100, 100, 100, 127, 100,   100, 100, 100, 100, 100, 100, 127, 100};

uint8_t g_preset_table_AMP_ATTACK     [] = {0  , 64 , 0  , 0  , 0  , 0  , 0  , 0  ,   0  , 64 , 0  , 0  , 0  , 0  , 0  , 0  };
uint8_t g_preset_table_AMP_DECAY      [] = {0  , 0  , 0  , 0  , 96 , 0  , 104, 0  ,   0  , 0  , 0  , 0  , 96 , 0  , 104, 0  };
uint8_t g_preset_table_AMP_SUSTAIN    [] = {127, 127, 127, 127, 0  , 127, 0  , 127,   127, 127, 127, 127, 0  , 127, 0  , 127};
uint8_t g_preset_table_AMP_RELEASE    [] = {0  , 64 , 0  , 0  , 96 , 0  , 0  , 0  ,   0  , 64 , 0  , 0  , 96 , 0  , 0  , 0  };

uint8_t g_preset_table_CHORUS_MODE    [] = {127, 127, 127, 127, 127, 127, 127, 0  ,   127, 127, 127, 127, 127, 127, 127, 0  };
uint8_t g_preset_table_CHORUS_RATE    [] = {64 , 64 , 64 , 64 , 64 , 64 , 64 , 64 ,   64 , 64 , 64 , 64 , 64 , 64 , 64 , 64 };
uint8_t g_preset_table_CHORUS_DEPTH   [] = {64 , 64 , 64 , 64 , 64 , 64 , 64 , 64 ,   64 , 64 , 64 , 64 , 64 , 64 , 64 , 64 };
uint8_t g_preset_table_CHORUS_DLY_TIME[] = {64 , 64 , 64 , 64 , 64 , 64 , 64 , 64 ,   64 , 64 , 64 , 64 , 64 , 64 , 64 , 64 };

uint8_t g_preset_table_P_BEND_RANGE   [] = {12 , 12 , 12 , 12 , 12 , 12 , 12 , 12 ,   12 , 12 , 12 , 12 , 12 , 12 , 12 , 12 };
uint8_t g_preset_table_CHORUS_BYPASS  [] = {0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  ,   0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  };
uint8_t g_preset_table_EG_AMP_MOD     [] = {0  , 0  , 0  , 0  , 127, 0  , 0  , 0  ,   0  , 0  , 0  , 0  , 127, 0  , 0  , 0  };
uint8_t g_preset_table_REL_EQ_DECAY   [] = {0  , 0  , 0  , 0  , 127, 0  , 0  , 0  ,   0  , 0  , 0  , 0  , 127, 0  , 0  , 0  };

uint8_t g_preset_table_FILTER_MODE    [] = {0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  ,   0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  };



