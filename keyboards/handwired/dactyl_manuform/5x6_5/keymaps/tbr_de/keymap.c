#include QMK_KEYBOARD_H
#include <keymap_german.h>
#include <sendstring_german.h>


enum layers {
    _QWERTZ = 0,
    _KOY,
    _NUM,
    _MOV,
    _SYM,
    _NAV,
    _NP
};

// Some basic macros
#define TASK    LCTL(KC_ESC)
#define TAB_R   LCTL(KC_TAB)
#define TAB_L   LCTL(LSFT(KC_TAB))
#define TAB_RO  LCTL(LSFT(KC_T))

#define BASE    DF(_QWERTZ)
#define KOY     DF(_KOY)

#define NEXTTAB  LCTL(KC_PGDN)
#define PREVTAB  LCTL(KC_PGUP)
#define TOPLINE  LCTL(KC_HOME)
#define BTMLINE  LCTL(KC_END)
#define WIN_L  LGUI(LSFT(KC_LEFT))
#define WIN_R  LGUI(LSFT(KC_RGHT))

//QWERTZ
#define SH_A LSFT_T(DE_A)
#define SH_ODIA LSFT_T(DE_ODIA)
#define CT_S LCTL_T(DE_S)
#define CT_L LCTL_T(DE_L)
#define AL_D LALT_T(DE_D)
#define AL_K LALT_T(DE_K)
#define GU_F LGUI_T(DE_F)
#define GU_J LGUI_T(DE_J)

//NUM
#define GU_4 LGUI_T(DE_4)
#define AL_5 LALT_T(DE_5)
#define CT_6 LCTL_T(DE_6)
#define SH_MINS LSFT_T(DE_MINS)

//KOY
#define SH_H LSFT_T(DE_H)
#define CT_A LCTL_T(DE_A)
#define AL_E LALT_T(DE_E)
#define GU_I LGUI_T(DE_I)
#define GU_T LGUI_T(DE_T)
#define AL_R LALT_T(DE_R)
#define CT_N LCTL_T(DE_N)
#define SH_S LSFT_T(DE_S)
#define GU_DOT LGUI_T(DE_DOT)


uint16_t copy_paste_timer;

enum custom_keycodes {
    KC_CCCV = SAFE_RANGE
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Template
[_TEMPLATE] = LAYOUT_5x6_5T(
     _______,   _______,    _______,    _______,    _______,    _______,                                                        _______,    _______,    _______,    _______,    _______,    _______,
     _______,   _______,    _______,    _______,    _______,    _______,                                                        _______,    _______,    _______,    _______,    _______,    _______,
     _______,   _______,    _______,    _______,    _______,    _______,                                                        _______,    _______,    _______,    _______,    _______,    _______,
     _______,   _______,    _______,    _______,    _______,    _______,                                                        _______,    _______,    _______,    _______,    _______,    _______,
                            _______,    _______,                _______,    _______,    _______,        _______,    _______,    _______,                _______,    _______,
                                                                            _______,    _______,        _______,    _______
  ),

*/
[_QWERTZ] = LAYOUT_5x6_5T(
     KC_ESC,    KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,                                                          KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     _______,
     KC_TAB,    DE_Q,       DE_W,       DE_E,       DE_R,       DE_T,                                                           DE_Z,       DE_U,       DE_I,       DE_O,       DE_P,       DE_UDIA,
     KC_TAB,    SH_A,       CT_S,       AL_D,       GU_F,       DE_G,                                                           DE_H,       GU_J,       AL_K,       CT_L,       SH_ODIA,    DE_ADIA,
     KC_CCCV,   DE_Y,       DE_X,       DE_C,       DE_V,       DE_B,                                                           DE_N,       DE_M,       DE_COMM,    DE_DOT,     DE_MINS,    DE_SS,
                            KC_MEH,     KC_HYPR,                KC_BSPC,    KC_SPC,     KC_DEL,         KC_BSPC,    KC_SPC,     KC_ENT,                 KC_HYPR,    KC_MEH,
                                                                            MO(_SYM),   MO(_NUM),       TT(_NAV),   KC_LEAD
),


[_KOY] = LAYOUT_5x6_5T(
     KC_ESC,    KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,                                                          KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     _______,
     KC_TAB,    DE_K,       DE_DOT,     DE_O,       DE_COMM,    DE_Y,                                                           DE_V,       DE_G,       DE_C,       DE_L,       DE_SS,      DE_Z,
     KC_TAB,    SH_H,       CT_A,       AL_E,       GU_I,       DE_U,                                                           DE_D,       GU_T,       AL_R,       CT_N,       SH_S,       DE_F,
     KC_CCCV,   DE_X,       DE_Q,       DE_ADIA,    DE_UDIA,    DE_ODIA,                                                        DE_B,       DE_P,       DE_W,       DE_M,       DE_J,       DE_MINS,
                            _______,    _______,                KC_BSPC,    KC_SPC,     KC_DEL,         KC_BSPC,    KC_SPC,     KC_ENT,                 _______,    _______,
                                                                            MO(_SYM),   MO(_NUM),       TT(_NAV),   KC_LEAD
  ),


[_NUM] = LAYOUT_5x6_5T(
     KC_NO,     KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,                                                          KC_NO,      KC_NO,      KC_NO,      KC_NO,      DE_0,       DE_EQL,
     _______,   DE_1,       DE_2,       DE_3,       DE_4,       DE_5,                                                           DE_6,       DE_7,       DE_8,       DE_9,       DE_PLUS,    DE_ASTR,
     _______,   _______,    _______,    _______,    _______,    DE_EQL,                                                         _______,    GU_4,       AL_5,       CT_6,       SH_MINS,    DE_SLSH,
     _______,   _______,    _______,    _______,    _______,    KC_CALC,                                                        _______,    DE_1,       DE_2,       DE_3,       DE_LPRN,    DE_RPRN,
                            _______,    _______,                _______,    _______,    _______,        _______,    _______,    _______,                DE_0,       DE_DOT,
                                                                            _______,    _______,        _______,    _______
  ),


[_MOV] = LAYOUT_5x6_5T(
     _______,   _______,    _______,    _______,    _______,    _______,                                                        _______,    _______,    _______,    _______,    _______,    _______,
     _______,   _______,    _______,    _______,    _______,    _______,                                                        _______,    _______,    _______,    _______,    _______,    _______,
     _______,   _______,    _______,    _______,    _______,    _______,                                                        _______,    _______,    _______,    _______,    _______,    _______,
     _______,   _______,    _______,    _______,    _______,    _______,                                                        _______,    _______,    _______,    _______,    _______,    _______,
                            _______,    _______,                _______,    _______,    _______,        _______,    _______,    _______,                _______,    _______,
                                                                            _______,    _______,        _______,    _______
  ),


[_SYM] = LAYOUT_5x6_5T(
     KC_NO,     KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,                                                          KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
     _______,   DE_EXLM,    DE_DQOT,    DE_DLR,     DE_PERC,    DE_AMPR,                                                        DE_SLSH,    DE_ASTR,    DE_LBRC,    DE_RBRC,    KC_NO,      KC_NO,
     _______,   KC_NO,      DE_MINS,    DE_PLUS,    DE_AT,      DE_EQL,                                                         DE_PIPE,    DE_QUOT,    DE_LPRN,    DE_RPRN,    DE_SCLN,    DE_COLN,
     _______,   DE_DEG,     KC_NO,      DE_CIRC,    DE_TILD,    DE_HASH,                                                        DE_BSLS,    DE_HASH,    DE_LCBR,    DE_RCBR,    DE_UNDS,    DE_QUES,
                            _______,    _______,                _______,    _______,    _______,        _______,    _______,    _______,                DE_LABK,    DE_RABK,
                                                                            _______,    _______,        _______,    _______
  ),


[_NAV] = LAYOUT_5x6_5T(
     KC_NO,     KC_F11,     KC_F12,     KC_F13,     KC_F14,     KC_F15,                                                         KC_F16,     KC_F17,     KC_F18,     KC_F19,     KC_F20,     KC_F21,
     _______,   _______,    _______,    _______,    _______,    _______,                                                        KC_PGUP,    KC_HOME,    KC_UP,      KC_END,     _______,    _______,
     _______,   _______,    _______,    _______,    _______,    KC_PSCR,                                                        KC_PGDN,    KC_LEFT,    KC_DOWN,    KC_RIGHT,   _______,    _______,
     _______,   KC_MPRV,    KC_VOLD,    KC_VOLU,    KC_MNXT,    _______,                                                        _______,    _______,    KC_DOWN,    _______,    _______,    KC_INS,
                            WIN_L,      WIN_R,                  _______,    _______,    _______,        _______,    _______,    _______,                KC_MPLY,    KC__MUTE,
                                                                            _______,    _______,        _______,    _______
  ),

[_NP] = LAYOUT_5x6_5T(
     RESET,     _______,    _______,    _______,    _______,    KC_NLCK,                                                        _______,    _______,    _______,    _______,    _______,    KC_PEQL,
     _______,   _______,    _______,    _______,    _______,    _______,                                                        _______,    KC_KP_7,    KC_KP_8,    KC_KP_9,    KC_PPLS,    KC_PAST,
     _______,   _______,    _______,    _______,    _______,    KC_PEQL,                                                        _______,    KC_KP_4,    KC_KP_5,    KC_KP_6,    KC_PMNS,    KC_PSLS,
     _______,   _______,    _______,    _______,    _______,    KC_CALC,                                                        _______,    KC_KP_1,    KC_KP_2,    KC_KP_3,    DE_LPRN,    DE_RPRN,
                            _______,    _______,                _______,    _______,    _______,        _______,    _______,    _______,                KC_KP_0,    KC_KP_DOT,
                                                                            _______,    _______,        _______,    _______
  ),


/*
[_QWERTZ] = LAYOUT(
    KC_ESC,     DE_Q,       DE_W,       DE_E,       DE_R,       DE_T,                                                                               DE_Z,       DE_U,       DE_I,       DE_O,       DE_P,       DE_UDIA,
    KC_TAB,     SH_A,       CT_S,       AL_D,       GU_F,       DE_G,                                                                               DE_H,       GU_J,       AL_K,       CT_L,       SH_ODIA,    DE_ADIA,
    KC_ALGR,    DE_Y,       DE_X,       DE_C,       DE_V,       DE_B,       _______,            KC_CCCV,             KC_LEAD,          _______,     DE_N,       DE_M,       DE_COMM,    DE_DOT,     DE_MINS,    DE_SS,
                                        KC_MUTE,    KC_DEL,     KC_BSPC,    LT(_SYM,KC_BSPC),  LT(_NUM,KC_SPC),     LT(_NAV,KC_SPC),   KC_SPC,     LT(_KUMA,KC_SPC),     KC_ENT,  _______
),

[_KOY] = LAYOUT(
    KC_ESC,     DE_K,       DE_DOT,     DE_O,       DE_COMM,    DE_Y,                                                              DE_V,       DE_G,       DE_C,       DE_L,       DE_SS,      DE_Z,
    KC_TAB,     DE_H,       DE_A,       DE_E,       DE_I,       DE_U,                                                              DE_D,       DE_T,       DE_R,       DE_N,       DE_S,       DE_F,
    KC_ALGR,    DE_X,       DE_Q,       DE_ADIA,    DE_UDIA,    DE_ODIA,    _______,           KC_CCCV,    KC_LEAD,    _______,     DE_B,       DE_P,       DE_W,       DE_M,       DE_J,       KC_NO,
                                        KC_MUTE,    KC_DEL,     KC_BSPC,    LT(_SYM,KC_BSPC),  LT(_NUM,KC_SPC),     LT(_NAV,KC_SPC),   KC_SPC,     LT(_KUMA,KC_SPC),     KC_ENT,  _______
),


[_SYM] = LAYOUT(
    _______,    DE_EXLM,    DE_DQOT,    DE_DLR,     DE_PERC,    DE_AMPR,                                                    DE_SLSH,    DE_ASTR,    DE_QUOT,    _______,    DE_TILD,    DE_DEG,
    _______,    DE_LABK,    DE_RABK,    DE_LPRN,    DE_RPRN,    DE_EQL,                                                     DE_PIPE,    DE_AT,      DE_PLUS,    DE_MINS,    DE_HASH,    DE_CIRC,
    _______,    DE_LCBR,    DE_RCBR,    DE_LBRC,    DE_RBRC,    _______,    _______,    _______,    _______,    _______,    DE_BSLS,    _______,    DE_SCLN,    DE_COLN,    DE_UNDS,    DE_QUES,
                                        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______
),

[_FNC] = LAYOUT(
    _______,    TG(_KOY),   TO(_GAMING),_______,    _______,    KC_PSCR,                                                    _______,    KC_F7,      KC_F8,      KC_F9,      KC_F12,     _______,
    _______,    _______,    _______,    _______,    _______,    _______,                                                    _______,    KC_F4,      KC_F5,      KC_F6,      KC_F11,     _______,
    _______,    _______,    _______,    _______,    _______,    KC_INS,     _______,    _______,    _______,    _______,    _______,    KC_F1,      KC_F2,      KC_F3,      KC_F10,     _______,
                                        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______
),

[_KUMA] = LAYOUT(
    _______,    _______,    _______,    OBJEXPL,    _______,    TBLFILT,                                                    PROPERT,    _______,    INSLINE,    DELLINE,    _______,    _______,
    _______,    NOFILT,     SEARCH,     _______,    FLDFILT,    _______,                                                    ZOOM,       _______,    _______,    _______,    _______,    _______,
    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    MARK,       TOPLINE,    PREVTAB,    NEXTTAB,    BTMLINE,    _______,
                                        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______
),

[_GAMING] = LAYOUT(
    KC_ESC,     DE_Q,       DE_W,       DE_E,       DE_R,       DE_T,                                                      DE_Z,       DE_U,       DE_I,       DE_O,       DE_P,       DE_UDIA,
    KC_TAB,     DE_A,       DE_S,       DE_D,       DE_F,       DE_G,                                                      DE_H,       DE_J,       DE_K,       DE_L,       DE_ODIA,    DE_ADIA,
    KC_LSFT,    DE_Y,       DE_X,       DE_C,       DE_V,       DE_B,       _______,  _______,     _______,   TO(_QWERTZ),     DE_N,       DE_M,       DE_COMM,    DE_DOT,     DE_MINS,    DE_SS,
                                        KC_MUTE,    KC_DEL,     KC_BSPC,    KC_SPC,   KC_LCTL,     _______,   KC_SPC,     _______,     KC_ENT,  _______
),
*/

};


LEADER_EXTERNS();

void matrix_scan_user(void) {
    LEADER_DICTIONARY() {
        leading = false;
        leader_end();

        SEQ_TWO_KEYS(KC_U, KC_F) { // ¯\_(ツ)_/¯
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

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _NUM, _NAV, _NP);
};

/*
//Always enable NUMLOCK
void led_set_keymap(uint8_t usb_led) {
  if (!(usb_led & (1<<USB_LED_NUM_LOCK))) {
    register_code(KC_NUMLOCK);
    unregister_code(KC_NUMLOCK);
  }
}
*/
