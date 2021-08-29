#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_german.h"
#include "keymap_nordic.h"
#include "keymap_french.h"
#include "keymap_spanish.h"
#include "keymap_hungarian.h"
#include "keymap_swedish.h"
#include "keymap_br_abnt2.h"
#include "keymap_canadian_multilingual.h"
#include "keymap_german_ch.h"
#include "keymap_jp.h"
#include "keymap_korean.h"
#include "keymap_bepo.h"
#include "keymap_italian.h"
#include "keymap_slovenian.h"
#include "keymap_lithuanian_azerty.h"
#include "keymap_danish.h"
#include "keymap_norwegian.h"
#include "keymap_portuguese.h"
#include "keymap_contributions.h"
#include "keymap_czech.h"
#include "keymap_romanian.h"
#include "keymap_russian.h"
#include "keymap_uk.h"
#include "keymap_estonian.h"
#include "keymap_belgian.h"
#include "keymap_us_international.h"

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
#define BP_NDSH_MAC ALGR(KC_8)
#define MOON_LED_LEVEL LED_LEVEL

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  ST_MACRO_0,
  ALT_TAB
};


enum tap_dance_codes {
  DANCE_0,
  DANCE_1,
  DANCE_2,
  DANCE_3,
  DANCE_4,
  DANCE_5,
  DANCE_6,
  DANCE_7,
  DANCE_8,
  DANCE_9,
  DANCE_10,
  DANCE_11,
  DANCE_12,
  DANCE_13,
  DANCE_14,
  DANCE_15,
  DANCE_16,
  DANCE_17,
  DANCE_18,
  SPACE_DANCE, // 19
};

typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

enum {
  NO_TAP = 0,
  SINGLE_TAP,
  SINGLE_HOLD,
  DOUBLE_TAP,
  DOUBLE_HOLD,
  DOUBLE_SINGLE_TAP,
  MORE_TAPS,
  SPACE_MODE
};


uint8_t dance_step(qk_tap_dance_state_t *state);

uint8_t dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (!state->pressed) return SINGLE_TAP;
        else if (state->interrupted && state->pressed) return SINGLE_HOLD;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}

static tap dance_state[20];

enum layers {
  MAIN,
  NAV1,
  SYMBOL,
  NAV2,
  CONTROL_LAYER,
  NAVB,
  ALT_TAB_LAYER
};

const uint16_t nav_keymap[MATRIX_ROWS][MATRIX_COLS] = LAYOUT_moonlander (
  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, LALT(LCTL(KC_W)), KC_TRANSPARENT  , KC_TRANSPARENT, KC_ESCAPE     , KC_BSPACE     , KC_UP         , KC_DELETE     , LCTL(KC_P)    , KC_TRANSPARENT, 
  KC_TRANSPARENT, MO(5)         , TD(DANCE_0)   , TD(DANCE_1)     , TD(DANCE_2)     , KC_TRANSPARENT, KC_TRANSPARENT, KC_LEFT       , KC_DOWN       , KC_RIGHT      , KC_ENTER      , KC_TRANSPARENT, 
  KC_TRANSPARENT, KC_TRANSPARENT, LCTL(KC_Z)    , KC_TRANSPARENT  , LCTL(LSFT(KC_Z)), KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                  KC_TRANSPARENT  , KC_TRANSPARENT  , KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [MAIN] = LAYOUT_moonlander(
    KC_ESCAPE,            KC_Q,           KC_W,           KC_E,           KC_R,          KC_T,            KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_TRANSPARENT, 
    LT(CONTROL_LAYER,KC_TAB),   KC_A,           KC_S,           KC_D,           KC_F,          KC_G,            KC_H,           KC_J,           KC_K,           KC_L,           KC_QUOTE,       MO(SYMBOL),          
    KC_LSHIFT,            KC_Z,           KC_X,           KC_C,           KC_V,          KC_B,            KC_N,           KC_M,           KC_COMMA,       TD(DANCE_17),   KC_QUOTE,       KC_LCTRL,       
                                                           KC_LALT,        KC_LCTRL,      KC_SPACE,        MO(NAV1),          KC_TRANSPARENT, KC_TRANSPARENT 
  ),
  [NAV1] = LAYOUT_moonlander (
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, LALT(LCTL(KC_W)), KC_TRANSPARENT  , KC_TRANSPARENT, KC_ESCAPE     , KC_BSPACE     , KC_UP         , KC_DELETE     , LCTL(KC_P)    , KC_TRANSPARENT, 
    KC_TRANSPARENT, MO(5)         , TD(DANCE_0)   , TD(DANCE_1)     , TD(DANCE_2)     , KC_TRANSPARENT, KC_TRANSPARENT, KC_LEFT       , KC_DOWN       , KC_RIGHT      , KC_ENTER      , KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, LCTL(KC_Z)    , KC_TRANSPARENT  , LCTL(LSFT(KC_Z)), KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT  , KC_TRANSPARENT  , KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [SYMBOL] = LAYOUT_moonlander(
    KC_TRANSPARENT, TD(DANCE_3),    TD(DANCE_4),    TD(DANCE_5),    ST_MACRO_0,     TD(DANCE_6),    KC_TILD,        TD(DANCE_12),   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, TD(DANCE_7),    TD(DANCE_8),    TD(DANCE_9),    TD(DANCE_10),   TD(DANCE_11),   TD(DANCE_13),   TD(DANCE_14),   TD(DANCE_15),   TD(DANCE_16),   KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_0,           KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_6,           KC_7,           KC_8,           KC_9,           KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, MO(NAV2), KC_TRANSPARENT, KC_TRANSPARENT 
  ),
  [NAV2] = LAYOUT_moonlander (
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, LALT(LCTL(KC_W)), KC_TRANSPARENT  , KC_TRANSPARENT, KC_ESCAPE     , KC_BSPACE     , KC_UP         , KC_DELETE     , LCTL(KC_P)    , KC_TRANSPARENT, 
    KC_TRANSPARENT, MO(5)         , TD(DANCE_0)   , TD(DANCE_1)     , TD(DANCE_2)     , KC_TRANSPARENT, KC_TRANSPARENT, KC_LEFT       , KC_DOWN       , KC_RIGHT      , KC_ENTER      , KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, LCTL(KC_Z)    , KC_TRANSPARENT  , LCTL(LSFT(KC_Z)), KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT  , KC_TRANSPARENT  , KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [CONTROL_LAYER] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_ENTER,       KC_LGUI,        ALT_TAB,        LCTL(LSFT(KC_R)), KC_TRANSPARENT,  LCTL(KC_BSLASH),LCTL(LSFT(KC_K)),LCTL(LSFT(KC_ENTER)),KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, LCTL(KC_X),     LCTL(KC_C),     LCTL(KC_V),       KC_TRANSPARENT,  LCTL(KC_SLASH), LCTL(KC_LBRACKET),LCTL(KC_ENTER), LCTL(KC_RBRACKET),KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, LCTL(KC_Z),     KC_TRANSPARENT, LCTL(LSFT(KC_Z)), KC_TRANSPARENT,  LALT(LCTL(KC_N)),KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,   KC_TRANSPARENT,  KC_TRANSPARENT, KC_TRANSPARENT,   KC_TRANSPARENT 
  ),
  [NAVB] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, LCTL(KC_BSLASH),LCTL(LSFT(KC_K)),LCTL(LSFT(KC_ENTER)),KC_TRANSPARENT, KC_PGUP,        KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_LALT,        KC_LCTRL,       KC_LSHIFT,      KC_TRANSPARENT, LCTL(KC_SLASH), LCTL(KC_LBRACKET),LCTL(KC_ENTER), LCTL(KC_RBRACKET),KC_PGDOWN,      KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, LALT(LCTL(KC_N)),KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [ALT_TAB_LAYER] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_LEFT, ALT_TAB, KC_RIGHT, KC_TRANSPARENT, KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT, KC_TRANSPARENT,        KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,        KC_TRANSPARENT,       KC_TRANSPARENT,      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,KC_TRANSPARENT, KC_TRANSPARENT,KC_TRANSPARENT,      KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
};

extern bool g_suspend_state;
extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [0] = { {85,203,158}, {85,203,158}, {105,255,255}, {0,0,0}, {0,0,0}, {85,203,158}, {85,203,158}, {85,203,158}, {0,0,0}, {0,0,0}, {85,203,158}, {85,203,158}, {85,203,158}, {0,0,0}, {0,0,0}, {85,203,158}, {85,203,158}, {85,203,158}, {0,0,0}, {0,0,0}, {85,203,158}, {85,203,158}, {85,203,158}, {32,176,255}, {0,0,0}, {85,203,158}, {85,203,158}, {85,203,158}, {85,203,158}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {85,203,158}, {85,203,158}, {32,176,255}, {0,0,0}, {0,0,0}, {85,203,158}, {85,203,158}, {134,255,213}, {0,0,0}, {0,0,0}, {85,203,158}, {85,203,158}, {134,255,213}, {0,0,0}, {0,0,0}, {85,203,158}, {85,203,158}, {134,255,213}, {0,0,0}, {0,0,0}, {85,203,158}, {85,203,158}, {85,203,158}, {0,0,0}, {0,0,0}, {85,203,158}, {85,203,158}, {85,203,158}, {32,176,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [1] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {32,176,255}, {0,0,0}, {0,0,0}, {0,0,0}, {134,255,213}, {32,176,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {32,176,255}, {0,0,0}, {35,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {32,176,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {134,255,213}, {32,176,255}, {0,0,0}, {0,0,0}, {0,0,0}, {243,222,234}, {85,203,158}, {0,0,0}, {0,0,0}, {0,0,0}, {85,203,158}, {85,203,158}, {0,0,0}, {0,0,0}, {0,0,0}, {243,222,234}, {85,203,158}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [2] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {169,120,255}, {169,120,255}, {0,0,0}, {0,0,0}, {0,0,0}, {32,176,255}, {32,176,255}, {0,204,255}, {0,0,0}, {0,0,0}, {10,225,255}, {10,225,255}, {0,204,255}, {0,0,0}, {0,0,0}, {85,203,158}, {85,203,158}, {32,255,234}, {0,0,0}, {0,0,0}, {243,222,234}, {134,255,213}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {205,255,255}, {205,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {32,176,255}, {32,176,255}, {205,255,255}, {0,0,0}, {0,0,0}, {10,225,255}, {10,225,255}, {0,204,255}, {0,0,0}, {0,0,0}, {154,255,255}, {154,255,255}, {105,255,255}, {0,0,0}, {0,0,0}, {35,255,255}, {105,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [3] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {32,176,255}, {0,0,0}, {0,0,0}, {0,0,0}, {134,255,213}, {32,176,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {32,176,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {35,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {134,255,213}, {32,176,255}, {0,0,0}, {0,0,0}, {0,0,0}, {243,222,234}, {85,203,158}, {0,0,0}, {0,0,0}, {0,0,0}, {85,203,158}, {85,203,158}, {0,0,0}, {0,0,0}, {0,0,0}, {243,222,234}, {85,203,158}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [4] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {154,255,255}, {250,159,255}, {0,0,0}, {0,0,0}, {105,255,255}, {134,255,213}, {0,183,238}, {0,0,0}, {0,0,0}, {105,255,255}, {134,255,213}, {0,0,0}, {0,0,0}, {0,0,0}, {154,255,255}, {134,255,213}, {85,203,158}, {0,0,0}, {0,0,0}, {27,126,255}, {32,176,255}, {27,126,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {10,225,255}, {0,0,0}, {0,0,0}, {0,0,0}, {27,126,255}, {10,225,255}, {0,0,0}, {0,0,0}, {0,0,0}, {27,126,255}, {134,255,213}, {0,0,0}, {0,0,0}, {0,0,0}, {27,126,255}, {27,126,255}, {27,126,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [5] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {134,255,213}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {134,255,213}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {134,255,213}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {134,255,213}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {134,255,213}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {134,255,213}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {134,255,213}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {134,255,213}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {134,255,213}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {134,255,213}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

};

void set_layer_color(int layer) {
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

void rgb_matrix_indicators_user(void) {
  if (g_suspend_state || keyboard_config.disable_layer_led) { return; }
  switch (biton32(layer_state)) {
    case 0:
      set_layer_color(0);
      break;
    case 1:
      set_layer_color(1);
      break;
    case 2:
      set_layer_color(2);
      break;
    case 3:
      set_layer_color(3);
      break;
    case 4:
      set_layer_color(4);
      break;
    case 5:
      set_layer_color(5);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case ST_MACRO_0:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_EQUAL) SS_DELAY(100) SS_LSFT(SS_TAP(X_DOT)));

      }
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
    case ALT_TAB:
      if (record->event.pressed) {
        layer_move(ALT_TAB_LAYER);
        register_code(KC_LALT);
        tap_code(KC_TAB);
      } else {
        unregister_code(KC_LALT);
        layer_move(CONTROL_LAYER);
      }
      break;
    }
  return true;
}


void on_dance_0(qk_tap_dance_state_t *state, void *user_data);
void dance_0_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_0_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_0(qk_tap_dance_state_t *state, void *user_data) {
}

void dance_0_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP: register_code16(LCTL(KC_X)); break;
        case SINGLE_HOLD: register_code16(KC_LALT); break;
    }
}

void dance_0_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP: unregister_code16(LCTL(KC_X)); break;
        case SINGLE_HOLD: unregister_code16(KC_LALT); break;
        case DOUBLE_TAP: unregister_code16(LCTL(KC_X)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LCTL(KC_X)); break;
    }
    dance_state[0].step = 0;
}
void on_dance_1(qk_tap_dance_state_t *state, void *user_data);
void dance_1_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_1_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_1(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LCTL(KC_C));
        tap_code16(LCTL(KC_C));
        tap_code16(LCTL(KC_C));
    }
    if(state->count > 3) {
        tap_code16(LCTL(KC_C));
    }
}

void dance_1_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[1].step = dance_step(state);
    switch (dance_state[1].step) {
        case SINGLE_TAP: register_code16(LCTL(KC_C)); break;
        case SINGLE_HOLD: register_code16(KC_LCTRL); break;
        case DOUBLE_TAP: register_code16(KC_LCTRL); break;
        case DOUBLE_HOLD: register_code16(KC_LCTRL); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LCTL(KC_C)); register_code16(LCTL(KC_C));
    }
}

void dance_1_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[1].step) {
        case SINGLE_TAP: unregister_code16(LCTL(KC_C)); break;
        case SINGLE_HOLD: unregister_code16(KC_LCTRL); break;
        case DOUBLE_TAP: unregister_code16(KC_LCTRL); break;
        case DOUBLE_HOLD: unregister_code16(KC_LCTRL); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LCTL(KC_C)); break;
    }
    dance_state[1].step = 0;
}
void on_dance_2(qk_tap_dance_state_t *state, void *user_data);
void dance_2_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_2_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_2(qk_tap_dance_state_t *state, void *user_data) {
}

void dance_2_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[2].step = dance_step(state);
    switch (dance_state[2].step) {
        case SINGLE_TAP: register_code16(LCTL(KC_V)); break;
        case SINGLE_HOLD: register_code16(KC_LSHIFT); break;
    }
}

void dance_2_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[2].step) {
        case SINGLE_TAP: unregister_code16(LCTL(KC_V)); break;
        case SINGLE_HOLD: unregister_code16(KC_LSHIFT); break;
    }
    dance_state[2].step = 0;
}
void on_dance_3(qk_tap_dance_state_t *state, void *user_data);
void dance_3_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_3_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_3(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LSFT(KC_7));
        tap_code16(LSFT(KC_7));
        tap_code16(LSFT(KC_7));
    }
    if(state->count > 3) {
        tap_code16(LSFT(KC_7));
    }
}

void dance_3_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[3].step = dance_step(state);
    switch (dance_state[3].step) {
        case SINGLE_TAP: register_code16(LSFT(KC_7)); break;
        case SINGLE_HOLD: register_code16(LSFT(KC_4)); break;
        case DOUBLE_TAP: register_code16(LSFT(KC_7)); register_code16(LSFT(KC_7)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LSFT(KC_7)); register_code16(LSFT(KC_7));
    }
}

void dance_3_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[3].step) {
        case SINGLE_TAP: unregister_code16(LSFT(KC_7)); break;
        case SINGLE_HOLD: unregister_code16(LSFT(KC_4)); break;
        case DOUBLE_TAP: unregister_code16(LSFT(KC_7)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LSFT(KC_7)); break;
    }
    dance_state[3].step = 0;
}
void on_dance_4(qk_tap_dance_state_t *state, void *user_data);
void dance_4_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_4_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_4(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LSFT(KC_BSLASH));
        tap_code16(LSFT(KC_BSLASH));
        tap_code16(LSFT(KC_BSLASH));
    }
    if(state->count > 3) {
        tap_code16(LSFT(KC_BSLASH));
    }
}

void dance_4_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[4].step = dance_step(state);
    switch (dance_state[4].step) {
        case SINGLE_TAP: register_code16(LSFT(KC_BSLASH)); break;
        case SINGLE_HOLD: register_code16(LSFT(KC_3)); break;
        case DOUBLE_TAP: register_code16(LSFT(KC_BSLASH)); register_code16(LSFT(KC_BSLASH)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LSFT(KC_BSLASH)); register_code16(LSFT(KC_BSLASH));
    }
}

void dance_4_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[4].step) {
        case SINGLE_TAP: unregister_code16(LSFT(KC_BSLASH)); break;
        case SINGLE_HOLD: unregister_code16(LSFT(KC_3)); break;
        case DOUBLE_TAP: unregister_code16(LSFT(KC_BSLASH)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LSFT(KC_BSLASH)); break;
    }
    dance_state[4].step = 0;
}
void on_dance_5(qk_tap_dance_state_t *state, void *user_data);
void dance_5_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_5_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_5(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LSFT(KC_SLASH));
        tap_code16(LSFT(KC_SLASH));
        tap_code16(LSFT(KC_SLASH));
    }
    if(state->count > 3) {
        tap_code16(LSFT(KC_SLASH));
    }
}

void dance_5_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[5].step = dance_step(state);
    switch (dance_state[5].step) {
        case SINGLE_TAP: register_code16(LSFT(KC_SLASH)); break;
        case SINGLE_HOLD: register_code16(LSFT(KC_1)); break;
        case DOUBLE_TAP: register_code16(LSFT(KC_SLASH)); register_code16(LSFT(KC_SLASH)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LSFT(KC_SLASH)); register_code16(LSFT(KC_SLASH));
    }
}

void dance_5_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[5].step) {
        case SINGLE_TAP: unregister_code16(LSFT(KC_SLASH)); break;
        case SINGLE_HOLD: unregister_code16(LSFT(KC_1)); break;
        case DOUBLE_TAP: unregister_code16(LSFT(KC_SLASH)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LSFT(KC_SLASH)); break;
    }
    dance_state[5].step = 0;
}
void on_dance_6(qk_tap_dance_state_t *state, void *user_data);
void dance_6_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_6_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_6(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LSFT(KC_8));
        tap_code16(LSFT(KC_8));
        tap_code16(LSFT(KC_8));
    }
    if(state->count > 3) {
        tap_code16(LSFT(KC_8));
    }
}

void dance_6_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[6].step = dance_step(state);
    switch (dance_state[6].step) {
        case SINGLE_TAP: register_code16(LSFT(KC_8)); break;
        case SINGLE_HOLD: register_code16(LSFT(KC_6)); break;
        case DOUBLE_TAP: register_code16(LSFT(KC_8)); register_code16(LSFT(KC_8)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LSFT(KC_8)); register_code16(LSFT(KC_8));
    }
}

void dance_6_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[6].step) {
        case SINGLE_TAP: unregister_code16(LSFT(KC_8)); break;
        case SINGLE_HOLD: unregister_code16(LSFT(KC_6)); break;
        case DOUBLE_TAP: unregister_code16(LSFT(KC_8)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LSFT(KC_8)); break;
    }
    dance_state[6].step = 0;
}
void on_dance_7(qk_tap_dance_state_t *state, void *user_data);
void dance_7_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_7_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_7(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LSFT(KC_2));
        tap_code16(LSFT(KC_2));
        tap_code16(LSFT(KC_2));
    }
    if(state->count > 3) {
        tap_code16(LSFT(KC_2));
    }
}

void dance_7_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[7].step = dance_step(state);
    switch (dance_state[7].step) {
        case SINGLE_TAP: register_code16(LSFT(KC_2)); break;
        case SINGLE_HOLD: register_code16(LSFT(KC_5)); break;
        case DOUBLE_TAP: register_code16(LSFT(KC_2)); register_code16(LSFT(KC_2)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LSFT(KC_2)); register_code16(LSFT(KC_2));
    }
}

void dance_7_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[7].step) {
        case SINGLE_TAP: unregister_code16(LSFT(KC_2)); break;
        case SINGLE_HOLD: unregister_code16(LSFT(KC_5)); break;
        case DOUBLE_TAP: unregister_code16(LSFT(KC_2)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LSFT(KC_2)); break;
    }
    dance_state[7].step = 0;
}
void on_dance_8(qk_tap_dance_state_t *state, void *user_data);
void dance_8_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_8_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_8(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_SLASH);
        tap_code16(KC_SLASH);
        tap_code16(KC_SLASH);
    }
    if(state->count > 3) {
        tap_code16(KC_SLASH);
    }
}

void dance_8_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[8].step = dance_step(state);
    switch (dance_state[8].step) {
        case SINGLE_TAP: register_code16(KC_SLASH); break;
        case SINGLE_HOLD: register_code16(KC_BSLASH); break;
        case DOUBLE_TAP: register_code16(KC_SLASH); register_code16(KC_SLASH); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_SLASH); register_code16(KC_SLASH);
    }
}

void dance_8_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[8].step) {
        case SINGLE_TAP: unregister_code16(KC_SLASH); break;
        case SINGLE_HOLD: unregister_code16(KC_BSLASH); break;
        case DOUBLE_TAP: unregister_code16(KC_SLASH); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_SLASH); break;
    }
    dance_state[8].step = 0;
}
void on_dance_9(qk_tap_dance_state_t *state, void *user_data);
void dance_9_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_9_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_9(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LSFT(KC_COMMA));
        tap_code16(LSFT(KC_COMMA));
        tap_code16(LSFT(KC_COMMA));
    }
    if(state->count > 3) {
        tap_code16(LSFT(KC_COMMA));
    }
}

void dance_9_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[9].step = dance_step(state);
    switch (dance_state[9].step) {
        case SINGLE_TAP: register_code16(LSFT(KC_COMMA)); break;
        case SINGLE_HOLD: register_code16(LSFT(KC_DOT)); break;
        case DOUBLE_TAP: register_code16(LSFT(KC_COMMA)); register_code16(LSFT(KC_COMMA)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LSFT(KC_COMMA)); register_code16(LSFT(KC_COMMA));
    }
}

void dance_9_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[9].step) {
        case SINGLE_TAP: unregister_code16(LSFT(KC_COMMA)); break;
        case SINGLE_HOLD: unregister_code16(LSFT(KC_DOT)); break;
        case DOUBLE_TAP: unregister_code16(LSFT(KC_COMMA)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LSFT(KC_COMMA)); break;
    }
    dance_state[9].step = 0;
}
void on_dance_10(qk_tap_dance_state_t *state, void *user_data);
void dance_10_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_10_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_10(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_EQUAL);
        tap_code16(KC_EQUAL);
        tap_code16(KC_EQUAL);
    }
    if(state->count > 3) {
        tap_code16(KC_EQUAL);
    }
}

void dance_10_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[10].step = dance_step(state);
    switch (dance_state[10].step) {
        case SINGLE_TAP: register_code16(KC_EQUAL); break;
        case SINGLE_HOLD: register_code16(LSFT(KC_EQUAL)); break;
        case DOUBLE_TAP: register_code16(KC_EQUAL); register_code16(KC_EQUAL); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_EQUAL); register_code16(KC_EQUAL);
    }
}

void dance_10_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[10].step) {
        case SINGLE_TAP: unregister_code16(KC_EQUAL); break;
        case SINGLE_HOLD: unregister_code16(LSFT(KC_EQUAL)); break;
        case DOUBLE_TAP: unregister_code16(KC_EQUAL); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_EQUAL); break;
    }
    dance_state[10].step = 0;
}
void on_dance_11(qk_tap_dance_state_t *state, void *user_data);
void dance_11_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_11_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_11(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LSFT(KC_SCOLON));
        tap_code16(LSFT(KC_SCOLON));
        tap_code16(LSFT(KC_SCOLON));
    }
    if(state->count > 3) {
        tap_code16(LSFT(KC_SCOLON));
    }
}

void dance_11_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[11].step = dance_step(state);
    switch (dance_state[11].step) {
        case SINGLE_TAP: register_code16(LSFT(KC_SCOLON)); break;
        case SINGLE_HOLD: register_code16(KC_SCOLON); break;
        case DOUBLE_TAP: register_code16(LSFT(KC_SCOLON)); register_code16(LSFT(KC_SCOLON)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LSFT(KC_SCOLON)); register_code16(LSFT(KC_SCOLON));
    }
}

void dance_11_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[11].step) {
        case SINGLE_TAP: unregister_code16(LSFT(KC_SCOLON)); break;
        case SINGLE_HOLD: unregister_code16(KC_SCOLON); break;
        case DOUBLE_TAP: unregister_code16(LSFT(KC_SCOLON)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LSFT(KC_SCOLON)); break;
    }
    dance_state[11].step = 0;
}
void on_dance_12(qk_tap_dance_state_t *state, void *user_data);
void dance_12_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_12_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_12(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_GRAVE);
        tap_code16(KC_GRAVE);
        tap_code16(KC_GRAVE);
    }
    if(state->count > 3) {
        tap_code16(KC_GRAVE);
    }
}

void dance_12_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[12].step = dance_step(state);
    switch (dance_state[12].step) {
        case SINGLE_TAP: register_code16(KC_GRAVE); break;
        case SINGLE_HOLD: register_code16(LSFT(KC_QUOTE)); break;
        case DOUBLE_TAP: register_code16(KC_GRAVE); register_code16(KC_GRAVE); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_GRAVE); register_code16(KC_GRAVE);
    }
}

void dance_12_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[12].step) {
        case SINGLE_TAP: unregister_code16(KC_GRAVE); break;
        case SINGLE_HOLD: unregister_code16(LSFT(KC_QUOTE)); break;
        case DOUBLE_TAP: unregister_code16(KC_GRAVE); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_GRAVE); break;
    }
    dance_state[12].step = 0;
}
void on_dance_13(qk_tap_dance_state_t *state, void *user_data);
void dance_13_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_13_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_13(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_MINUS);
        tap_code16(KC_MINUS);
        tap_code16(KC_MINUS);
    }
    if(state->count > 3) {
        tap_code16(KC_MINUS);
    }
}

void dance_13_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[13].step = dance_step(state);
    switch (dance_state[13].step) {
        case SINGLE_TAP: register_code16(KC_MINUS); break;
        case SINGLE_HOLD: register_code16(LSFT(KC_MINUS)); break;
        case DOUBLE_TAP: register_code16(KC_MINUS); register_code16(KC_MINUS); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_MINUS); register_code16(KC_MINUS);
    }
}

void dance_13_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[13].step) {
        case SINGLE_TAP: unregister_code16(KC_MINUS); break;
        case SINGLE_HOLD: unregister_code16(LSFT(KC_MINUS)); break;
        case DOUBLE_TAP: unregister_code16(KC_MINUS); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_MINUS); break;
    }
    dance_state[13].step = 0;
}
void on_dance_14(qk_tap_dance_state_t *state, void *user_data);
void dance_14_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_14_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_14(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LSFT(KC_9));
        tap_code16(LSFT(KC_0));
        tap_code16(LSFT(KC_9));
    }
    if(state->count > 3) {
        tap_code16(LSFT(KC_9));
    }
}

void dance_14_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[14].step = dance_step(state);
    switch (dance_state[14].step) {
        case SINGLE_TAP: register_code16(LSFT(KC_9)); break;
        case SINGLE_HOLD: register_code16(LSFT(KC_0)); break;
        case DOUBLE_TAP: register_code16(LSFT(KC_9)); register_code16(LSFT(KC_9)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LSFT(KC_9)); register_code16(LSFT(KC_9));
    }
}

void dance_14_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[14].step) {
        case SINGLE_TAP: unregister_code16(LSFT(KC_9)); break;
        case SINGLE_HOLD: unregister_code16(LSFT(KC_0)); break;
        case DOUBLE_TAP: unregister_code16(LSFT(KC_9)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LSFT(KC_9)); break;
    }
    dance_state[14].step = 0;
}
void on_dance_15(qk_tap_dance_state_t *state, void *user_data);
void dance_15_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_15_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_15(qk_tap_dance_state_t *state, void *user_data) {

}

void dance_15_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[15].step = dance_step(state);
    switch (dance_state[15].step) {
        case SINGLE_TAP: register_code16(LSFT(KC_LBRACKET)); break;
        case SINGLE_HOLD: register_code16(LSFT(KC_RBRACKET)); break;
    }
}

void dance_15_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[15].step) {
        case SINGLE_TAP: unregister_code16(LSFT(KC_LBRACKET)); break;
        case SINGLE_HOLD: unregister_code16(LSFT(KC_RBRACKET)); break;
    }
    dance_state[15].step = 0;
}
void on_dance_16(qk_tap_dance_state_t *state, void *user_data);
void dance_16_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_16_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_16(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_LBRACKET);
        tap_code16(KC_LBRACKET);
        tap_code16(KC_LBRACKET);
    }
    if(state->count > 3) {
        tap_code16(KC_LBRACKET);
    }
}

void dance_16_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[16].step = dance_step(state);
    switch (dance_state[16].step) {
        case SINGLE_TAP: register_code16(KC_LBRACKET); break;
        case SINGLE_HOLD: register_code16(KC_RBRACKET); break;
        case DOUBLE_TAP: register_code16(KC_LBRACKET); register_code16(KC_LBRACKET); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_LBRACKET); register_code16(KC_LBRACKET);
    }
}

void dance_16_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[16].step) {
        case SINGLE_TAP: unregister_code16(KC_LBRACKET); break;
        case SINGLE_HOLD: unregister_code16(KC_RBRACKET); break;
        case DOUBLE_TAP: unregister_code16(KC_LBRACKET); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_LBRACKET); break;
    }
    dance_state[16].step = 0;
}

void on_dance_17(qk_tap_dance_state_t *state, void *user_data);
void dance_17_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_17_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_17(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_DOT);
        tap_code16(KC_DOT);
        tap_code16(KC_DOT);
    }
    if(state->count > 3) {
        tap_code16(KC_DOT);
    }
}

void dance_17_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[17].step = dance_step(state);
    switch (dance_state[17].step) {
        case SINGLE_TAP: register_code16(KC_DOT); break;
        case SINGLE_HOLD: SEND_STRING("./"); break;
        case DOUBLE_TAP: register_code16(KC_DOT); register_code16(KC_DOT); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_DOT); register_code16(KC_DOT);
    }
}

void dance_17_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[17].step) {
        case SINGLE_TAP: unregister_code16(KC_DOT); break;
        case SINGLE_HOLD: break;
        case DOUBLE_TAP: unregister_code16(KC_DOT); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_DOT); break;
    }
    dance_state[17].step = 0;
}


// bool space_mod_active = false;
// bool space_mod_consumer = false;

// uint8_t space_mod_dance(qk_tap_dance_state_t *state) {

//     if (state->interrupting_keycode == TD(SPACE_DANCE)) return SPACE_MODE;
//     // if (state->interrupting_keycode == TD(SPACE_DANCE)) return SPACE_MODE;
//     if (state->count == 1) {
//         if (!state->pressed) return SINGLE_TAP;
//         else if (state->interrupted && state->pressed) return SINGLE_HOLD;
//         else return SINGLE_HOLD;
//     } else if (state->count == 2) {
//         if (state->interrupted) return DOUBLE_SINGLE_TAP;
//         else if (state->pressed) return DOUBLE_HOLD;
//         else return DOUBLE_TAP;
//     }
//     return MORE_TAPS;
// }


// uint16_t comboTimer = 0;

// void on_dance_18(qk_tap_dance_state_t *state, void *user_data);
// void dance_18_finished(qk_tap_dance_state_t *state, void *user_data);
// void dance_18_reset(qk_tap_dance_state_t *state, void *user_data);

// void on_dance_18(qk_tap_dance_state_t *state, void *user_data) {
// }

// void dance_18_finished(qk_tap_dance_state_t *state, void *user_data) {
//     dance_state[18].step = space_mod_dance(state);
//     switch (dance_state[18].step) {
//         case NO_TAP: SEND_STRING("NOTAP"); break;
//         case SPACE_MODE:
//           space_mod_consumer = true;
//           register_code(KC_0);
//           break;
//         case SINGLE_TAP: register_code(KC_A); break;
//         case SINGLE_HOLD: register_code16(LSFT(KC_A)); break;
//     }
// }

// void dance_18_reset(qk_tap_dance_state_t *state, void *user_data) {
//   wait_ms(10);
//   switch (dance_state[18].step) {
//     case SPACE_MODE: unregister_code(KC_0); break;
//     case SINGLE_TAP: unregister_code(KC_A); break;
//     case SINGLE_HOLD:  unregister_code16(LSFT(KC_A)); break;
//   }
//   dance_state[18].step = 0;
// }


// void on_space_dance(qk_tap_dance_state_t *state, void *user_data);
// void space_dance_finished(qk_tap_dance_state_t *state, void *user_data);
// void space_dance_reset(qk_tap_dance_state_t *state, void *user_data);

// void on_space_dance(qk_tap_dance_state_t *state, void *user_data) {
// }

// void space_dance_finished(qk_tap_dance_state_t *state, void *user_data) {
//   dance_state[SPACE_DANCE].step = space_mod_dance(state);  
//   switch (dance_state[SPACE_DANCE].step) {
//     case SINGLE_TAP:
//       if (space_mod_consumer) {
//         return;
//       }
//       register_code(KC_SPACE);
//       break;
//   }
// }

// void space_dance_reset(qk_tap_dance_state_t *state, void *user_data) {
//     wait_ms(10);
//     dance_state[SPACE_DANCE].step = 0;
//     if (space_mod_consumer) {
//       space_mod_consumer = false;
//       return;
      
//     }
//     unregister_code(KC_SPACE);
// }


// uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
//     switch (keycode) {
//         case TD(SPACE_DANCE):
//           return 50;
//         case TD(DANCE_18):
//           if (dance_state[DANCE_18].step == NO_TAP) {
//             return 50;
//           } else if (dance_state[DANCE_18].step > NO_TAP) {
//             return (TAPPING_TERM - 50);
//           };
//         default:
//             return TAPPING_TERM;
//     }
// }

// action->state.interrupting_keycode

qk_tap_dance_action_t tap_dance_actions[] = {
        [DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_0, dance_0_finished, dance_0_reset),
        [DANCE_1] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_1, dance_1_finished, dance_1_reset),
        [DANCE_2] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_2, dance_2_finished, dance_2_reset),
        [DANCE_3] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_3, dance_3_finished, dance_3_reset),
        [DANCE_4] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_4, dance_4_finished, dance_4_reset),
        [DANCE_5] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_5, dance_5_finished, dance_5_reset),
        [DANCE_6] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_6, dance_6_finished, dance_6_reset),
        [DANCE_7] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_7, dance_7_finished, dance_7_reset),
        [DANCE_8] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_8, dance_8_finished, dance_8_reset),
        [DANCE_9] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_9, dance_9_finished, dance_9_reset),
        [DANCE_10] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_10, dance_10_finished, dance_10_reset),
        [DANCE_11] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_11, dance_11_finished, dance_11_reset),
        [DANCE_12] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_12, dance_12_finished, dance_12_reset),
        [DANCE_13] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_13, dance_13_finished, dance_13_reset),
        [DANCE_14] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_14, dance_14_finished, dance_14_reset),
        [DANCE_15] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_15, dance_15_finished, dance_15_reset),
        [DANCE_16] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_16, dance_16_finished, dance_16_reset),
        [DANCE_17] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_17, dance_17_finished, dance_17_reset),
        // [DANCE_18] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_18, dance_18_finished, dance_18_reset),
        // [SPACE_DANCE] = ACTION_TAP_DANCE_FN_ADVANCED(on_space_dance, space_dance_finished, space_dance_reset),
};