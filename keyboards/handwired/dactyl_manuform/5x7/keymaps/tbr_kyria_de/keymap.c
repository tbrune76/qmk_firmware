#include QMK_KEYBOARD_H
#include <keymap_german.h>
#include <sendstring_german.h>

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layers {
    _QWERTZ = 0,
    _KOY,
    _NUM,
    _SYM,
    _NAV,
    _FNC,
    _KUMA
};

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

#define SH_MINS LSFT_T(DE_MINS)
#define CT_6 LCTL_T(DE_6)
#define AL_5 LALT_T(DE_5)
#define GU_4 LGUI_T(DE_4)

#define GU_DOT LGUI(DE_DOT)


uint16_t copy_paste_timer;

enum custom_keycodes {
    KC_CCCV = SAFE_RANGE
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Template
[_TEMPLATE] = LAYOUT(
    _______,    _______,    _______,    _______,    _______,    _______,    _______,                            _______,    _______,    _______,    _______,    _______,    _______,    _______,
    _______,    _______,    _______,    _______,    _______,    _______,    _______,                            _______,    _______,    _______,    _______,    _______,    _______,    _______,
    _______,    _______,    _______,    _______,    _______,    _______,    _______,                            _______,    _______,    _______,    _______,    _______,    _______,    _______,
    _______,    _______,    _______,    _______,    _______,    _______,                                                    _______,    _______,    _______,    _______,    _______,    _______,
    _______,    _______,    _______,    _______,                                                                                                    _______,    _______,    _______,    _______,
                                                    _______,    _______,                                                    _______,    _______,
                                                                            _______,    _______,    _______,    _______,
                                                                            _______,    _______,    _______,    _______),
*/

[_QWERTZ] = LAYOUT(
    _______,    _______,    _______,    _______,    _______,    _______,    _______,                            _______,    _______,    _______,    _______,    _______,    _______,    _______,
    KC_ESC,     DE_Q,       DE_W,       DE_E,       DE_R,       DE_T,       _______,                            _______,    DE_Z,       DE_U,       DE_I,       DE_O,       DE_P,       DE_UDIA,
    KC_TAB,     SH_A,       CT_S,       AL_D,       GU_F,       DE_G,       _______,                            _______,    DE_H,       GU_J,       AL_K,       CT_L,       SH_ODIA,    DE_ADIA,
    KC_LSFT,    DE_Y,       DE_X,       DE_C,       DE_V,       DE_B,                                                       DE_N,       DE_M,       DE_COMM,    DE_DOT,     DE_MINS,    DE_SS,
    WIN_L,      RGB_TOG,    _______,      _______,                                                                                                  _______,    _______,    _______,    _______,
                                                    KC_BSPC,    MO(_SYM),                                                   KC_SPC,    KC_ENT,
                                                                            TT(_NUM),   KC_CCCV,    KC_LEAD,    TT(_NAV),
                                                                            KC_DEL,     KC_INS,     KC_ESC,     MO(_KUMA)),



[_KOY] = LAYOUT(
    _______,    _______,    _______,    _______,    _______,    _______,    _______,                            _______,    _______,    _______,    _______,    _______,    _______,    _______,
    KC_ESC,     DE_K,       DE_DOT,     DE_O,       DE_COMM,    DE_Y,       _______,                            _______,    DE_V,       DE_G,       DE_C,       DE_L,       DE_SS,      DE_Z,
    KC_TAB,     DE_H,       DE_A,       DE_E,       DE_I,       DE_U,       _______,                            _______,    DE_D,       DE_T,       DE_R,       DE_N,       DE_S,       DE_F,
    KC_LSFT,    DE_X,       DE_Q,       DE_ADIA,    DE_UDIA,    DE_ODIA,                                                    DE_B,       DE_P,       DE_W,       DE_M,       DE_J,       _______,
    WIN_L,      RGB_TOG,    _______,      _______,                                                                                                  _______,    _______,    _______,    _______,
                                                    KC_BSPC,    MO(_SYM),                                                   KC_SPC,    KC_ENT,
                                                                            TT(_NUM),   KC_CCCV,    KC_LEAD,    TT(_NAV),
                                                                            KC_DEL,     KC_INS,     KC_ESC,     MO(_KUMA)),



[_NUM] = LAYOUT(  // Numpad
    _______,    _______,    _______,    _______,    _______,    _______,    _______,                            _______,    _______,    _______,    _______,    _______,    _______,    _______,
    _______,    DE_1,       DE_2,       DE_3,       DE_4,       DE_5,       _______,                            _______,    DE_6,       DE_7,       DE_8,       DE_9,       DE_PLUS,    DE_ASTR,
    _______,    _______,    _______,    _______,    _______,    DE_EQL,     KC_CALC,                            _______,    DE_0,       GU_4,       AL_5,       CT_6,       SH_MINS,    DE_SLSH,
    _______,    _______,    _______,    _______,    DE_0,       DE_DOT,                                                     DE_DOT,     DE_1,       DE_2,       DE_3,       DE_LPRN,    DE_RPRN,
    _______,    _______,    _______,    _______,                                                                                                    _______,    _______,    _______,    _______,
                                                    _______,    _______,                                                    _______,    _______,
                                                                            _______,    _______,    _______,    _______,
                                                                            _______,    _______,    _______,    _______),



[_SYM] = LAYOUT(  // Symbols
    _______,    _______,    _______,    _______,    _______,    _______,    _______,                            _______,    _______,    _______,    _______,    _______,    _______,    _______,
    _______,    DE_EXLM,    DE_DQOT,    DE_DLR,     DE_PERC,    DE_AMPR,    _______,                            _______,    DE_SLSH,    DE_ASTR,    DE_QUOT,    _______,    DE_TILD,    DE_DEG,
    _______,    DE_LABK,    DE_RABK,    DE_LPRN,    DE_RPRN,    DE_EQL,     _______,                            _______,    DE_PIPE,    DE_AT,      DE_PLUS,    DE_MINS,    DE_HASH,    DE_CIRC,
    _______,    DE_LCBR,    DE_RCBR,    DE_LBRC,    DE_RBRC,    _______,                                                    DE_BSLS,    _______,    DE_SCLN,    DE_COLN,    DE_UNDS,    DE_QUES,
    _______,    _______,    _______,    _______,                                                                                                    _______,    _______,    _______,    _______,
                                                    _______,    _______,                                                    _______,    _______,
                                                                            _______,    _______,    _______,    _______,
                                                                            _______,    _______,    _______,    _______),

[_NAV] = LAYOUT(
    _______,    _______,    _______,    _______,    _______,    _______,    _______,                            _______,    _______,    _______,    _______,    _______,    _______,    _______,
    _______,    _______,    _______,    _______,    _______,    _______,    _______,                            _______,    KC_PGUP,    KC_HOME,    KC_UP,      KC_END,     _______,    _______,
    _______,    _______,    _______,    _______,    _______,    _______,    _______,                            _______,    KC_PGDN,    KC_LEFT,    KC_DOWN,    KC_RIGHT,   _______,    _______,
    _______,    _______,    _______,    _______,    _______,    _______,                                                    _______,    KC_VOLD,    KC_MUTE,    KC_VOLU,    _______,    _______,
    _______,    _______,    _______,    _______,                                                                                                    _______,    _______,    _______,    _______,
                                                    _______,    _______,                                                    _______,    _______,
                                                                            _______,    _______,    _______,    _______,
                                                                            _______,    _______,    _______,    _______),


[_FNC] = LAYOUT(  // Function Keys
    _______,    _______,    _______,    _______,    _______,    _______,    _______,                            _______,    _______,    _______,    _______,    _______,    _______,    _______,
    RESET,      _______,    _______,    _______,    _______,    _______,    KC_SLEP,                            KC_WAKE,    _______,    KC_F7,      KC_F8,      KC_F9,      KC_F12,     _______,
    _______,    _______,    _______,    _______,    _______,    _______,    DF(_QWERTZ),                        DF(_KOY),   _______,    KC_F4,      KC_F5,      KC_F6,      KC_F11,     _______,
    _______,    _______,    _______,    _______,    _______,    _______,                                                    _______,    KC_F1,      KC_F2,      KC_F3,      KC_F10,     _______,
    KC_PSCR,    _______,    RGB_VAI,    RGB_VAD,                                                                                                    _______,    _______,    _______,    _______,
                                                    _______,    _______,                                                    _______,    _______,
                                                                            _______,    _______,    _______,    _______,
                                                                            _______,    _______,    _______,    _______),


[_KUMA] = LAYOUT(
    _______,    _______,    _______,    _______,    _______,    _______,    _______,                            _______,    _______,    _______,    _______,    _______,    _______,    _______,
    _______,    _______,    _______,    OBJEXPL,    _______,    TBLFILT,    _______,                            _______,    PROPERT,    _______,    INSLINE,    DELLINE,    _______,    _______,
    _______,    NOFILT,     SEARCH,     _______,    FLDFILT,    _______,    _______,                            _______,    ZOOM,       _______,    _______,    _______,    _______,    _______,
    _______,    _______,    _______,    _______,    _______,    _______,                                                    MARK,       TOPLINE,    PREVTAB,    NEXTTAB,    BTMLINE,    _______,
    _______,    _______,    _______,    _______,                                                                                                    _______,    _______,    _______,    _______,
                                                    _______,    _______,                                                    _______,    _______,
                                                                            _______,    _______,    _______,    _______,
                                                                            _______,    _______,    _______,    _______),


};


const rgblight_segment_t PROGMEM _QWERTZ_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 3, HSV_RED},    // Light 3 LEDs, starting with LED 0
    {3, 3, HSV_RED}    // Light 3 LED, starting with LED 3
);
const rgblight_segment_t PROGMEM _KOY_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 3, HSV_SPRINGGREEN},    // Light 3 LEDs, starting with LED 0
    {3, 3, HSV_SPRINGGREEN}    // Light 3 LED, starting with LED 3
);
const rgblight_segment_t PROGMEM _NUM_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 3, HSV_ORANGE},
    {3, 3, HSV_ORANGE}
);
const rgblight_segment_t PROGMEM _SYM_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 3, HSV_BLUE},
    {3, 3, HSV_BLUE}
);

const rgblight_segment_t PROGMEM _FNC_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 3, HSV_GREEN},
    {3, 3, HSV_GREEN}
);
const rgblight_segment_t PROGMEM _NAV_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 3, HSV_PURPLE},
    {3, 3, HSV_PURPLE}
);
const rgblight_segment_t PROGMEM _KUMA_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 3, HSV_AZURE},
    {3, 3, HSV_AZURE}
);

const rgblight_segment_t* const PROGMEM tbr_layers[] = RGBLIGHT_LAYERS_LIST(
    _QWERTZ_layer,
    _KOY_layer,
    _NUM_layer,
    _SYM_layer,
    _NAV_layer,
    _FNC_layer,
    _KUMA_layer
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
    state = update_tri_layer_state(state, _NUM, _NAV, _FNC);
    rgblight_set_layer_state(_KOY,  layer_state_cmp(state, _KOY));
    rgblight_set_layer_state(_NUM,  layer_state_cmp(state, _NUM));
    rgblight_set_layer_state(_SYM,  layer_state_cmp(state, _SYM));
    rgblight_set_layer_state(_NAV,  layer_state_cmp(state, _NAV));
    rgblight_set_layer_state(_FNC,  layer_state_cmp(state, _FNC));
    rgblight_set_layer_state(_KUMA, layer_state_cmp(state, _KUMA));
    return (state);
}


LEADER_EXTERNS();

void matrix_scan_user(void) {
    LEADER_DICTIONARY() {
        leading = false;
        leader_end();

        SEQ_TWO_KEYS(KC_E, KC_U) { // ¯\_(ツ)_/¯
            //send_unicode_hex_string("00AF 005C 005F 0028 30C4 0029 005F 002F 00AF");
            send_unicode_string("¯\\_(ツ)_/¯");
        }
        SEQ_TWO_KEYS(KC_T, KC_S) { // ¯\_(ツ)_/¯
            SEND_STRING(":man_shrugging:");
        }
        SEQ_TWO_KEYS(KC_T, KC_F) {
            SEND_STRING(":man_facepalming:");
        }
        SEQ_ONE_KEY(KC_G) {
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
