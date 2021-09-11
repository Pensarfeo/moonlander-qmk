#include QMK_KEYBOARD_H
#include "version.h"

enum layers {
  MAIN,
  NAV1,
  SYMBOL,
  SYMBOLB,
  SYMBOL2,
  MAINSHIFT,
  NAV2,
  CONTROL_LAYER,
  NAVB,
  ALT_TAB_LAYER
};




enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  ST_MACRO_0,
  ALT_TAB,
  
};


enum tap_dance_codes {
  DANCE_0,
  DANCE_1,
  DANCE_2,// 19
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

static tap dance_state[3];

#define UNDO LCTL(KC_Z)
#define REDO LCTL(LSFT(KC_Z))

#define CUT LCTL(KC_X)
#define COPY LCTL(KC_C)
#define PASTE LCTL(KC_V)
#define CTRL_TAB LT(CONTROL_LAYER, KC_TAB)
#define NAVB_SPACE LT(NAVB, KC_SPACE)
#define SYM2_SPACE LT(SYMBOL2, KC_SPACE)
#define SYM2_SPACE LT(SYMBOL2, KC_SPACE)
#define SFTL_SPACE LT(MAINSHIFT, KC_SPACE)
#define SYMB_SPACE LT(NAV1, KC_SPACE)

#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
#define BP_NDSH_MAC ALGR(KC_8)
#define MOON_LED_LEVEL LED_LEVEL


// Left-hand home row mods
#define ALT_S LALT_T(KC_S)
#define CTL_D LCTL_T(KC_D)
#define SFT_F LSFT_T(KC_F)

#define SFT_SPACE LSFT_T(KC_SPACE)

// Right-hand home row mods
#define SFT_J RSFT_T(KC_J)
#define CTL_K RCTL_T(KC_K)
#define ALT_L LALT_T(KC_L)


bool get_retro_tapping(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SFT_SPACE:
            return true;
        case SFTL_SPACE:
            return true;
        default:
            return false;
    }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [MAIN] = LAYOUT_moonlander(
    KC_ESC,         KC_Q              , KC_W          , KC_E            , KC_R            , KC_T             , KC_Y            , KC_U             , KC_I               , KC_O            , KC_P           , KC_TRANSPARENT, 
    CTRL_TAB ,      KC_A              , KC_S          , KC_D            , KC_F            , KC_G             , KC_H            , KC_J             , KC_K               , KC_L            , KC_QUOTE       , MO(SYMBOL)   ,          
    KC_LSHIFT,      KC_Z              , KC_X          , KC_C            , KC_V            , KC_B             , KC_N            , KC_M             , KC_COMMA           , KC_DOT          , KC_COLON       , KC_LCTRL   ,       
    KC_LALT,        KC_LCTRL          , SFTL_SPACE    , MO(NAV1)      , KC_TRANSPARENT  , KC_TRANSPARENT
  ),
  [MAINSHIFT] = LAYOUT_moonlander(
    KC_GRAVE      , LSFT(KC_Q)        , LSFT(KC_W)      , LSFT(KC_E)     , LSFT(KC_R)     , LSFT(KC_T)          , LSFT(KC_Y) , LSFT(KC_U) , LSFT(KC_I)     , LSFT(KC_O)   , LSFT(KC_P)     , KC_TRANSPARENT, 
    KC_TRANSPARENT, LSFT(KC_A)        , LSFT(KC_S)      , LSFT(KC_D)     , LSFT(KC_F)     , LSFT(KC_G)          , LSFT(KC_H) , LSFT(KC_J) , LSFT(KC_K)     , LSFT(KC_L)   , LSFT(KC_QUOTE) , KC_TRANSPARENT,          
    KC_LCTRL      , LSFT(KC_Z)        , LSFT(KC_X)      , LSFT(KC_C)     , LSFT(KC_V)     , LSFT(KC_B)          , LSFT(KC_N) , LSFT(KC_M) , KC_EXCLAIM     , KC_QUESTION  , KC_SCOLON      , KC_TRANSPARENT,       
    KC_TRANSPARENT, KC_TRANSPARENT    , KC_TRANSPARENT  , SYMB_SPACE     , KC_TRANSPARENT , KC_TRANSPARENT
  ),
  [NAV1] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_ENTER          , UNDO          , ALT_TAB         , REDO            , LCTL(LSFT(KC_R)) , KC_TRANSPARENT  , KC_BSPACE        , KC_UP              , KC_DELETE        , LCTL(KC_P)    , KC_TRANSPARENT,
    KC_TRANSPARENT, MO(CONTROL_LAYER) , TD(DANCE_0)   , TD(DANCE_1)     , TD(DANCE_2)     , KC_LGUI          , KC_TRANSPARENT  , KC_LEFT          , KC_DOWN            , KC_RIGHT         , KC_ENTER      , KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT    , KC_TRANSPARENT, LALT(LCTL(KC_W)), KC_TRANSPARENT  , KC_TRANSPARENT   , KC_TRANSPARENT  , KC_TRANSPARENT   , KC_TRANSPARENT     , KC_TRANSPARENT   , KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT    , NAVB_SPACE    , KC_TRANSPARENT  , KC_TRANSPARENT  , KC_TRANSPARENT
  ),
  [SYMBOL] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_HASH           , KC_BSLASH     , KC_RABK         , KC_TILD         , KC_PERC          , KC_CIRC         , KC_RPRN          , KC_RCBR            , KC_RBRACKET      , KC_PIPE       , KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_DLR            , KC_SLASH      , KC_LABK         , KC_EQUAL        , KC_AT            , KC_MINUS        , KC_LPRN          , KC_LCBR            , KC_LBRACKET      , KC_AMPR       , KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT    , KC_TRANSPARENT, KC_TRANSPARENT  , KC_UNDS         , KC_TRANSPARENT   , KC_ASTR         , KC_PLUS          , KC_TRANSPARENT     , KC_TRANSPARENT   , KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT    , KC_TRANSPARENT, KC_TRANSPARENT  , KC_TRANSPARENT  , KC_TRANSPARENT
  ),
  
  [CONTROL_LAYER] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_ENTER          , UNDO          , ALT_TAB         , REDO            , LCTL(LSFT(KC_R)) , KC_TRANSPARENT  , KC_BSPACE        , KC_UP              , KC_DELETE        , LCTL(KC_P)    , KC_TRANSPARENT,
    KC_TRANSPARENT, LCTL(KC_S)        , LCTL(KC_X)    , LCTL(KC_C)      , LCTL(KC_V)      , KC_LGUI          , KC_TRANSPARENT  , KC_LEFT          , KC_DOWN            , KC_RIGHT         , KC_ENTER      , KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT    , KC_TRANSPARENT, LALT(LCTL(KC_W)), KC_TRANSPARENT  , KC_TRANSPARENT   , KC_TRANSPARENT  , KC_TRANSPARENT   , KC_TRANSPARENT     , KC_TRANSPARENT   , KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT    , KC_TRANSPARENT, KC_TRANSPARENT  , KC_TRANSPARENT  , KC_TRANSPARENT
  ),
  [NAVB] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT    , KC_TRANSPARENT, KC_TRANSPARENT  , KC_TRANSPARENT  , KC_TRANSPARENT   , LCTL(KC_BSLASH) ,LCTL(LSFT(KC_K))  ,LCTL(LSFT(KC_ENTER)), KC_TRANSPARENT   , LCTL(LSFT(KC_P))       , KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT    , KC_LALT       , KC_LCTRL        , KC_LSHIFT       , KC_TRANSPARENT   , LCTL(KC_SLASH)  , LCTL(KC_LBRACKET),LCTL(KC_ENTER)      , LCTL(KC_RBRACKET), KC_PGUP      , KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT    , KC_TRANSPARENT, KC_TRANSPARENT  , KC_TRANSPARENT  , KC_TRANSPARENT   , LALT(LCTL(KC_N)),KC_TRANSPARENT    , KC_TRANSPARENT     , KC_TRANSPARENT   , KC_PGDOWN, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT    , KC_TRANSPARENT, KC_TRANSPARENT  , KC_TRANSPARENT  , KC_TRANSPARENT
  ),
  [ALT_TAB_LAYER] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT    , KC_DOWN         , ALT_TAB         , KC_UP           , KC_TRANSPARENT   , KC_TRANSPARENT  ,KC_TRANSPARENT    ,KC_TRANSPARENT      ,KC_TRANSPARENT    , KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT    , KC_LEFT         , KC_TRANSPARENT  , KC_RIGHT        , KC_TRANSPARENT   , KC_TRANSPARENT  , KC_TRANSPARENT   ,KC_TRANSPARENT      , KC_TRANSPARENT   ,KC_TRANSPARENT , KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT    , KC_TRANSPARENT  , KC_TRANSPARENT  , KC_TRANSPARENT  , KC_TRANSPARENT   , KC_TRANSPARENT  ,KC_TRANSPARENT    , KC_TRANSPARENT     , KC_TRANSPARENT   , KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT    , KC_TRANSPARENT  , KC_TRANSPARENT  , KC_TRANSPARENT  , KC_TRANSPARENT
  ),
};

const key_override_t dot_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_DOT, LSFT(KC_SLASH));
const key_override_t com_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_COMMA, LSFT(KC_1));
const key_override_t esc_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_ESC, KC_GRAVE);
const key_override_t col_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_COLON, KC_SCOLON);
// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &dot_key_override,
    &com_key_override,
    &esc_key_override,
    &col_key_override,
    NULL // Null terminate the array of overrides!
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
  if (keyboard_config.disable_layer_led) { return; }
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

bool ctrlLayerKeyPressed = false;
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
        if (ctrlLayerKeyPressed) {
          layer_move(CONTROL_LAYER);
        } else {
          layer_move(MAIN);
        }
      }
      break;
    case CTRL_TAB:
      ctrlLayerKeyPressed = record->event.pressed;
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



qk_tap_dance_action_t tap_dance_actions[] = {
        [DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_0, dance_0_finished, dance_0_reset),
        [DANCE_1] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_1, dance_1_finished, dance_1_reset),
        [DANCE_2] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_2, dance_2_finished, dance_2_reset),
};

enum conbos {
  M_A_0,
  M_S_1,
  M_D_2,
  M_F_3,
  M_G_4,
  V_H_5,
  V_J_6,
  V_K_7,
  V_L_8,
  V_QT_9,
};

const uint16_t PROGMEM m_a_combo[] = {KC_M, KC_A, COMBO_END};
const uint16_t PROGMEM m_s_combo[] = {KC_M, KC_S, COMBO_END};
const uint16_t PROGMEM m_d_combo[] = {KC_M, KC_D, COMBO_END};
const uint16_t PROGMEM m_f_combo[] = {KC_M, KC_F, COMBO_END};
const uint16_t PROGMEM m_g_combo[] = {KC_M, KC_G, COMBO_END};
const uint16_t PROGMEM v_h_combo[] = {KC_V, KC_H, COMBO_END};
const uint16_t PROGMEM v_j_combo[] = {KC_V, KC_J, COMBO_END};
const uint16_t PROGMEM v_k_combo[] = {KC_V, KC_K, COMBO_END};
const uint16_t PROGMEM v_l_combo[] = {KC_V, KC_L, COMBO_END};
const uint16_t PROGMEM v_qt_combo[] = {KC_V, KC_QUOTE, COMBO_END};



combo_t key_combos[COMBO_COUNT] = {
  [M_A_0] = COMBO(m_a_combo, KC_0),
  [M_S_1] = COMBO(m_s_combo, KC_1),
  [M_D_2] = COMBO(m_d_combo, KC_2),
  [M_F_3] = COMBO(m_f_combo, KC_3),
  [M_G_4] = COMBO(m_g_combo, KC_4),
  [V_H_5] = COMBO(v_h_combo, KC_5),
  [V_J_6] = COMBO(v_j_combo, KC_6),
  [V_K_7] = COMBO(v_k_combo, KC_7),
  [V_L_8] = COMBO(v_l_combo, KC_8),
  [V_QT_9] = COMBO(v_qt_combo, KC_9),
};