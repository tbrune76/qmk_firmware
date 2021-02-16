#include QMK_KEYBOARD_H
#include <keymap_german.h>
#include <sendstring_german.h>


// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTZ 0
#define _FN     1
#define _NUMPAD 2
#define _NAV    3

// Some basic macros
#define TASK    LCTL(KC_ESC)
#define TAB_R   LCTL(KC_TAB)
#define TAB_L   LCTL(LSFT(KC_TAB))
#define TAB_RO  LCTL(LSFT(KC_T))

#define NEXTTAB  LCTL(KC_PGDN)
#define PREVTAB  LCTL(KC_PGUP)
#define TOPLINE  LCTL(KC_HOME)
#define BTMLINE  LCTL(KC_END)
#define WIN_L  LGUI(LSFT(KC_LEFT))
#define WIN_R  LGUI(LSFT(KC_RGHT))
#define MARK     LCTL(KC_F1)
#define FLDFILT  KC_F7
#define TBLFILT  LCTL(KC_F7)
#define NOFILT   LCTL(LSFT(KC_F7))
#define INSLINE  LCTL(KC_INS)
#define DELLINE  LCTL(KC_DEL)
#define CPYLINE  LCTL(LSFT(KC_C))
#define PSTLINE  LCTL(LSFT(KC_V))
#define OBJEXPL  LSFT(KC_F12)
#define PROPERT  LSFT(KC_F4)
#define SEARCH   LCTL(KC_F3)
#define ZOOM     LCTL(LALT(KC_F1))

#define SH_A LSFT_T(DE_A)
#define SH_ODIA LSFT_T(DE_ODIA)
#define CT_S LCTL_T(DE_S)
#define CT_L LCTL_T(DE_L)
#define AL_D LALT_T(DE_D)
#define AL_K LALT_T(DE_K)
#define GU_F LGUI_T(DE_F)
#define GU_J LGUI_T(DE_J)

uint16_t copy_paste_timer;

enum custom_keycodes {
    KC_CCCV = SAFE_RANGE
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTZ] = LAYOUT_5x7(
  // left hand
   KC_ESC,          DE_1,    DE_2,    DE_3,   DE_4,   DE_5,   DE_6,
   KC_TAB,          DE_Q,    DE_W,    DE_E,   DE_R,   DE_T,   DE_LABK,
//   KC_LCTL,         DE_A,    DE_S,    DE_D,   DE_F,   DE_G,   KC_PSCR,
   KC_LCTL,         SH_A,    CT_S,    AL_D,   GU_F,   DE_G,   _______,
   OSM(MOD_LSFT),   DE_Y,    DE_X,    DE_C,   DE_V,   DE_B,
   KC_LGUI,         RGB_TOG, WIN_L,  WIN_R,
                                                KC_BSPC,      MO(_FN),
                                                TT(_NUMPAD),  KC_CCCV,
                                                KC_DEL,       KC_MUTE,
        // right hand
                     DE_7,    DE_8,    DE_9,    DE_0,     DE_SS,    DE_PLUS,  DE_HASH,
                     DE_AT,   DE_Z,    DE_U,    DE_I,     DE_O,     DE_P,     DE_UDIA,
//                     _______, DE_H,    DE_J,    DE_K,     DE_L,     DE_ODIA,  DE_ADIA,
                     _______, DE_H,    GU_J,    AL_K,     CT_L,     SH_ODIA,  DE_ADIA,
                              DE_N,    DE_M,    DE_COMM,  DE_DOT,   DE_MINS,  OSM(MOD_RSFT),
                                       KC_LEFT, KC_UP,    KC_DOWN,  KC_RGHT,
        KC_SPC,   KC_ENT,
        KC_ALGR,  KC_LEAD,
        KC_TAB,   MO(_NAV)),

[_FN] = LAYOUT_5x7(
  // left hand
   _______,   KC_F1,     KC_F2,        KC_F3,      KC_F4,      KC_F5,     KC_F6,
   _______,   _______,   KC__VOLDOWN,  KC__MUTE,   KC__VOLUP,  _______,   _______,
   _______,   _______,   _______,      _______,    _______,    _______,   RESET,
   _______,   KC_MSTP,   KC_MPRV,      KC_MPLY,    KC_MNXT,    _______,
   KC_PSCR,   _______,   _______,      _______,
                                                    _______, _______,
                                                    _______, _______,
                                                    _______, _______,
        // right hand
                     KC_F7,     KC_F8,     KC_F9,     KC_F10,    KC_F11,    KC_F12,    _______,
                     _______,   _______,   KC_BTN1,   KC_MS_U,   KC_BTN2,   _______,   _______,
                     _______,   _______,   KC_MS_L,   KC_MS_D,   KC_MS_R,   _______,   _______,
                                _______,   _______,   _______,   _______,   _______,   _______,
                                                      KC_HOME,   KC_PGUP,   KC_PGDN,   KC_END,
        _______, _______,
        _______, _______,
        _______, _______),

[_NUMPAD] = LAYOUT_5x7(
  // left hand
   _______,   _______,   _______,   _______,   _______,   _______,  _______,
   _______,   _______,   KC_HOME,   KC_UP,     KC_PGUP,   _______,  _______,
   _______,   _______,   KC_LEFT,   KC_DOWN,   KC_RGHT,   _______,  _______,
   _______,   _______,   KC_END,    _______,   KC_PGDN,   _______,
   _______,   _______,   _______,   _______,
                               _______, _______,
                               _______, _______,
                               _______, _______,
        // right hand
                     _______,   DE_EQL,    DE_LPRN,   DE_RPRN,   _______,   DE_PLUS,   DE_MINS,
                     _______,   _______,   KC_7,      KC_8,      KC_9,      DE_ASTR,   DE_SLSH,
                     KC_CALC,   _______,   KC_4,      KC_5,      KC_6,      _______,   _______,
                                KC_0,      KC_1,      KC_2,      KC_3,      DE_DOT,    _______,
                                                      _______,   _______,   _______,   _______,
        _______, _______,
        _______, _______,
        _______, _______),

[_NAV] = LAYOUT_5x7(
  // left hand
   KC_SLEP,   _______,   _______,   _______,   _______,   _______,  _______,
   KC_WAKE,   _______,   _______,   OBJEXPL,   _______,   TBLFILT,  _______,
   _______,   NOFILT,    SEARCH,    _______,   FLDFILT,   _______,  _______,
   _______,   _______,   _______,   CPYLINE,   PSTLINE,   _______,
   _______,   _______,   _______,   _______,
                               _______, _______,
                               _______, _______,
                               _______, _______,
        // right hand
                     _______,   _______,   _______,   _______,   _______,   _______,   _______,
                     _______,   _______,   PROPERT,   INSLINE,   _______,   _______,   _______,
                     _______,   _______,   ZOOM,      DELLINE,   _______,   _______,   _______,
                                _______,   MARK,      _______,   _______,   _______,   _______,
                                                      TOPLINE,   PREVTAB,   NEXTTAB,   BTMLINE,
        _______, _______,
        _______, _______,
        _______, _______),

};


const rgblight_segment_t PROGMEM _QWERTZ_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 3, HSV_RED},    // Light 3 LEDs, starting with LED 0
    {3, 3, HSV_RED}    // Light 3 LED, starting with LED 3
);
const rgblight_segment_t PROGMEM _FN_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 3, HSV_ORANGE},
    {3, 3, HSV_ORANGE}
);
const rgblight_segment_t PROGMEM _NUM_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {3, 3, HSV_BLUE}
);
const rgblight_segment_t PROGMEM _NAV_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 3, HSV_GREEN},
    {3, 3, HSV_GREEN}
);

const rgblight_segment_t* const PROGMEM tbr_layers[] = RGBLIGHT_LAYERS_LIST(
    _QWERTZ_layer,  // 0
    _FN_layer,      // 1
    _NUM_layer,     // 2
    _NAV_layer      // 3
);

void keyboard_post_init_user(void) {
    //Enable the LED layers
    //rgblight_enable_noeeprom();
    //rgblight_sethsv_noeeprom(HSV_RED);
    rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
    layer_state_set_user(layer_state);
    rgblight_layers = tbr_layers;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    // Layers will light up if both kb layers are active
    rgblight_set_layer_state(1, layer_state_cmp(state, 1));
    rgblight_set_layer_state(2, layer_state_cmp(state, 2));
    rgblight_set_layer_state(3, layer_state_cmp(state, 3));
    return state;
}

LEADER_EXTERNS();

void matrix_scan_user(void) {
    LEADER_DICTIONARY() {
        leading = false;
        leader_end();

        SEQ_ONE_KEY(KC_F) {
            SEND_STRING("()"SS_TAP(X_LEFT));
        }
        SEQ_ONE_KEY(KC_R) {
            SEND_STRING("{}"SS_TAP(X_LEFT));
        }
        SEQ_ONE_KEY(KC_4) {
            SEND_STRING("[]"SS_TAP(X_LEFT));
        }
        SEQ_ONE_KEY(KC_V) {
            SEND_STRING("<>");
        }
        SEQ_TWO_KEYS(KC_G, KC_G) {
            SEND_STRING(SS_TAP(X_ENT)"Gruss"SS_TAP(X_ENT)"Timo"SS_TAP(X_ENT));
        }
        SEQ_TWO_KEYS(KC_F, KC_G) {
            SEND_STRING(SS_TAP(X_ENT)"Freundliche Gr"SS_TAP(X_LBRC)"sse"SS_TAP(X_ENT)"Timo Brune"SS_TAP(X_ENT));
        }
        SEQ_TWO_KEYS(KC_D, KC_D) {
            SEND_STRING(SS_TAP(X_HOME)SS_LSFT(SS_TAP(X_END))SS_TAP(X_DEL));
        }
        SEQ_TWO_KEYS(KC_S, KC_L) {
            SEND_STRING("ssh root"SS_ALGR(SS_TAP(X_Q))"nblb.home");
        }
        SEQ_TWO_KEYS(KC_S, KC_V) {
            SEND_STRING("ssh root"SS_ALGR(SS_TAP(X_Q))"pcvb.home");
        }
        SEQ_THREE_KEYS(KC_D, KC_U, KC_G) {
            SEND_STRING(SS_TAP(X_ENT)"Danke und Gruss"SS_TAP(X_ENT)"Timo"SS_TAP(X_ENT));
        }
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_CCCV:  // One key copy/paste
            if (record->event.pressed) {
                copy_paste_timer = timer_read();
            } else {
                if (timer_elapsed(copy_paste_timer) > TAPPING_TERM) {  // Hold, copy
                    tap_code16(LCTL(KC_C));
                } else { // Tap, paste
                    tap_code16(LCTL(KC_V));
                }
            }
            break;
    }
    return true;
}
