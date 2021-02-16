/* Copyright 2019 Thomas Baart <thomas@splitkb.com>e
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
#include <keymap_german.h>
#include <sendstring_german.h>
#include <stdio.h>

char wpm_str[10];
uint16_t wpm_graph_timer = 0;

enum layers {
    _QWERTZ = 0,
    _KOY,
    _NUM,
    _SYM,
    _NAV,
    _FNC,
    _KUMA,
    _GAMING
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

#define GU_A LGUI_T(DE_A)
#define GU_ODIA LGUI_T(DE_ODIA)
#define AL_S LALT_T(DE_S)
#define AL_L LALT_T(DE_L)
#define CT_D LCTL_T(DE_D)
#define CT_K LCTL_T(DE_K)
#define SH_F LSFT_T(DE_F)
#define SH_J LSFT_T(DE_J)

#define SH_MINS LSFT_T(DE_MINS)
#define CT_6 LCTL_T(DE_6)
#define AL_5 LALT_T(DE_5)
#define GU_4 LGUI_T(DE_4)

#define GU_MINS LGUI_T(DE_MINS)
#define AL_6 LALT_T(DE_6)
#define CT_5 LCTL_T(DE_5)
#define SH_4 LSFT_T(DE_4)


#define GU_DOT LGUI(DE_DOT)

uint16_t copy_paste_timer;

enum custom_keycodes {
    KC_CCCV = SAFE_RANGE
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
// /*
//  * Layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),


[_QWERTZ] = LAYOUT(
    KC_ESC,     DE_Q,       DE_W,       DE_E,       DE_R,       DE_T,                                                                               DE_Z,       DE_U,       DE_I,       DE_O,       DE_P,       DE_UDIA,
    KC_TAB,     SH_A,       CT_S,       AL_D,       GU_F,       DE_G,                                                                               DE_H,       GU_J,       AL_K,       CT_L,       SH_ODIA,    DE_ADIA,
    KC_ALGR,    DE_Y,       DE_X,       DE_C,       DE_V,       DE_B,       _______,            KC_CCCV,             KC_LEAD,          _______,     DE_N,       DE_M,       DE_COMM,    DE_DOT,     DE_MINS,    DE_SS,
                                        KC_MUTE,    KC_DEL,     KC_BSPC,    LT(_SYM,KC_BSPC),  LT(_NUM,KC_SPC),     LT(_NAV,KC_SPC),   KC_SPC,     LT(_KUMA,KC_SPC),     KC_ENT,  _______
),

/*
[_QWERTZ] = LAYOUT(
    KC_ESC,     DE_Q,       DE_W,       DE_E,       DE_R,       DE_T,                                                                               DE_Z,       DE_U,       DE_I,       DE_O,       DE_P,       DE_UDIA,
    KC_TAB,     GU_A,       AL_S,       CT_D,       SH_F,       DE_G,                                                                               DE_H,       SH_J,       CT_K,       AL_L,       GU_ODIA,    DE_ADIA,
    KC_ALGR,    DE_Y,       DE_X,       DE_C,       DE_V,       DE_B,       _______,            KC_CCCV,             KC_LEAD,          _______,     DE_N,       DE_M,       DE_COMM,    DE_DOT,     DE_MINS,    DE_SS,
                                        KC_MUTE,    KC_DEL,     KC_BSPC,    LT(_SYM,KC_BSPC),  LT(_NUM,KC_SPC),     LT(_NAV,KC_SPC),   KC_SPC,     LT(_KUMA,KC_SPC),     KC_ENT,  _______
),
*/

[_KOY] = LAYOUT(
    KC_ESC,     DE_K,       DE_DOT,     DE_O,       DE_COMM,    DE_Y,                                                              DE_V,       DE_G,       DE_C,       DE_L,       DE_SS,      DE_Z,
    KC_TAB,     DE_H,       DE_A,       DE_E,       DE_I,       DE_U,                                                              DE_D,       DE_T,       DE_R,       DE_N,       DE_S,       DE_F,
    KC_ALGR,    DE_X,       DE_Q,       DE_ADIA,    DE_UDIA,    DE_ODIA,    _______,           KC_CCCV,    KC_LEAD,    _______,     DE_B,       DE_P,       DE_W,       DE_M,       DE_J,       KC_NO,
                                        KC_MUTE,    KC_DEL,     KC_BSPC,    LT(_SYM,KC_BSPC),  LT(_NUM,KC_SPC),     LT(_NAV,KC_SPC),   KC_SPC,     LT(_KUMA,KC_SPC),     KC_ENT,  _______
),


[_NUM] = LAYOUT(
    _______,    DE_1,       DE_2,       DE_3,       DE_4,       DE_5,                                                       DE_6,       DE_7,       DE_8,       DE_9,       DE_PLUS,    DE_ASTR,
    _______,    _______,    _______,    _______,    _______,    DE_EQL,                                                     DE_0,       GU_4,       AL_5,       CT_6,       SH_MINS,    DE_SLSH,
    _______,    _______,    _______,    _______,    DE_0,       DE_DOT,     _______,    _______,    _______,    KC_CALC,    DE_DOT,     DE_1,       DE_2,       DE_3,       DE_LPRN,    DE_RPRN,
                                        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______
),

/*
[_NUM] = LAYOUT(
    _______,    DE_1,       DE_2,       DE_3,       DE_4,       DE_5,                                                       DE_6,       DE_7,       DE_8,       DE_9,       DE_PLUS,    DE_ASTR,
    _______,    _______,    _______,    _______,    _______,    DE_EQL,                                                     DE_0,       GU_4,       AL_5,       CT_6,       SH_MINS,    DE_SLSH,
    _______,    _______,    _______,    _______,    DE_0,       DE_DOT,     _______,    _______,    _______,    KC_CALC,    DE_DOT,     DE_1,       DE_2,       DE_3,       DE_LPRN,    DE_RPRN,
                                        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______
),
*/

[_SYM] = LAYOUT(
    _______,    DE_EXLM,    DE_DQOT,    DE_DLR,     DE_PERC,    DE_AMPR,                                                    DE_SLSH,    DE_ASTR,    DE_QUOT,    _______,    DE_TILD,    DE_DEG,
    _______,    DE_LABK,    DE_RABK,    DE_LPRN,    DE_RPRN,    DE_EQL,                                                     DE_PIPE,    DE_AT,      DE_PLUS,    DE_MINS,    DE_HASH,    DE_CIRC,
    _______,    DE_LCBR,    DE_RCBR,    DE_LBRC,    DE_RBRC,    _______,    _______,    _______,    _______,    _______,    DE_BSLS,    _______,    DE_SCLN,    DE_COLN,    DE_UNDS,    DE_QUES,
                                        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______
),

[_NAV] = LAYOUT(
    _______,    _______,    _______,    _______,    _______,    _______,                                                    KC_PGUP,    KC_HOME,    KC_UP,      KC_END,     _______,    _______,
    _______,    _______,    _______,    _______,    _______,    _______,                                                    KC_PGDN,    KC_LEFT,    KC_DOWN,    KC_RIGHT,   _______,    _______,
    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    KC_PGUP,    KC_DOWN,    KC_PGDN,    _______,    _______,
                                        KC_MEDIA_PLAY_PAUSE,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______
),

[_FNC] = LAYOUT(
    _______,    TG(_KOY),   TO(_GAMING),    _______,    _______,    KC_PSCR,                                                    _______,    KC_F7,      KC_F8,      KC_F9,      KC_F12,     _______,
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




/*
 * Base Layer: QWERTY
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |RAIS/ESC|   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |  | \   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |Ctrl/BS |   A  |   S  |  D   |   F  |   G  |                              |   H  |   J  |   K  |   L  | ;  : |  ' "   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |LShift|LShift|  |LShift|LShift|   N  |   M  | ,  < | . >  | /  ? |  - _   |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        | GUI  | Del  | Enter| Space| Esc  |  | Enter| Space| Tab  | Bksp | AltGr|
 *                        |      |      | Alt  | Lower| Raise|  | Lower| Raise|      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
 /*   [_QWERTZ] = LAYOUT(
      LT(_RAISE, KC_ESC),       KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,                                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_PIPE,
      MT(MOD_LCTL, KC_BSPC),   KC_A,   KC_S,   KC_D,   KC_F,   KC_G,                                         KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
      KC_LSFT,                 KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_LSFT,   KC_LSFT, KC_LSFT, KC_LSFT, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_MINS,
              KC_LGUI, KC_DEL, MT(MOD_LALT, KC_ENT), LT(_LOWER, KC_SPC), LT(_RAISE, KC_ESC), LT(_LOWER, KC_ENT), LT(_RAISE, KC_SPC), KC_TAB,  KC_BSPC, KC_RALT
    ),
*/
/*
 * Lower Layer: Symbols
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |  !   |  @   |  {   |  }   |  |   |                              |      |      |      |      |      |  | \   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  #   |  $   |  (   |  )   |  `   |                              |   +  |  -   |  /   |  *   |  %   |  ' "   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |  %   |  ^   |  [   |  ]   |  ~   |      |      |  |      |      |   &  |  =   |  ,   |  .   |  / ? | - _    |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |  ;   |  =   |  |  =   |  ;   |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
/*    [_LOWER] = LAYOUT(
      _______, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE,                                     _______, _______, _______, _______, _______, KC_BSLS,
      _______, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,                                      KC_PLUS, KC_MINS, KC_SLSH, KC_ASTR, KC_PERC, KC_QUOT,
      _______, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, _______, _______, _______, _______, KC_AMPR, KC_EQL,  KC_COMM, KC_DOT,  KC_SLSH, KC_MINS,
                                 _______, _______, _______, KC_SCLN, KC_EQL,  KC_EQL,  KC_SCLN, _______, _______, _______
    ),
    */
/*
 * Raise Layer: Number keys, media, navigation
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |   1  |  2   |  3   |  4   |  5   |                              |  6   |  7   |  8   |  9   |  0   |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      | Prev | Play | Next | VolUp|                              | Left | Down | Up   | Right|      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      | Mute | VolDn|      |      |  |      |      | MLeft| Mdown| MUp  |MRight|      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
/*    [_RAISE] = LAYOUT(
      _______, KC_1, 	  KC_2,    KC_3,    KC_4,    KC_5,                                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
      _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, KC_VOLU,                                     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
      _______, _______, _______, _______, KC_MUTE, KC_VOLD, _______, _______, _______, _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
    */
/*
 * Adjust Layer: Function keys, RGB
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        | F1   |  F2  | F3   | F4   | F5   |                              | F6   | F7   |  F8  | F9   | F10  |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        | TOG  | SAI  | HUI  | VAI  | MOD  |                              |      |      |      | F11  | F12  |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      | SAD  | HUD  | VAD  | RMOD |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
 /*   [_ADJUST] = LAYOUT(
      _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
      _______, RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI, RGB_MOD,                                     _______, _______, _______, KC_F11,  KC_F12,  _______,
      _______, _______, RGB_SAD, RGB_HUD, RGB_VAD, RGB_RMOD,_______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
    */
// /*
//  * Layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _NUM, _NAV, _FNC);
    return state;
}

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	return OLED_ROTATION_180;
}

static void render_kyria_logo(void) {
    static const char PROGMEM kyria_logo[] = {
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,192,224,240,112,120, 56, 60, 28, 30, 14, 14, 14,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 14, 14, 14, 30, 28, 60, 56,120,112,240,224,192,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,192,224,240,124, 62, 31, 15,  7,  3,  1,128,192,224,240,120, 56, 60, 28, 30, 14, 14,  7,  7,135,231,127, 31,255,255, 31,127,231,135,  7,  7, 14, 14, 30, 28, 60, 56,120,240,224,192,128,  1,  3,  7, 15, 31, 62,124,240,224,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,240,252,255, 31,  7,  1,  0,  0,192,240,252,254,255,247,243,177,176, 48, 48, 48, 48, 48, 48, 48,120,254,135,  1,  0,  0,255,255,  0,  0,  1,135,254,120, 48, 48, 48, 48, 48, 48, 48,176,177,243,247,255,254,252,240,192,  0,  0,  1,  7, 31,255,252,240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,255,255,255,  0,  0,  0,  0,  0,254,255,255,  1,  1,  7, 30,120,225,129,131,131,134,134,140,140,152,152,177,183,254,248,224,255,255,224,248,254,183,177,152,152,140,140,134,134,131,131,129,225,120, 30,  7,  1,  1,255,255,254,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0,255,255,  0,  0,192,192, 48, 48,  0,  0,240,240,  0,  0,  0,  0,  0,  0,240,240,  0,  0,240,240,192,192, 48, 48, 48, 48,192,192,  0,  0, 48, 48,243,243,  0,  0,  0,  0,  0,  0, 48, 48, 48, 48, 48, 48,192,192,  0,  0,  0,  0,  0,
        0,  0,  0,255,255,255,  0,  0,  0,  0,  0,127,255,255,128,128,224,120, 30,135,129,193,193, 97, 97, 49, 49, 25, 25,141,237,127, 31,  7,255,255,  7, 31,127,237,141, 25, 25, 49, 49, 97, 97,193,193,129,135, 30,120,224,128,128,255,255,127,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0, 63, 63,  3,  3, 12, 12, 48, 48,  0,  0,  0,  0, 51, 51, 51, 51, 51, 51, 15, 15,  0,  0, 63, 63,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 48, 48, 63, 63, 48, 48,  0,  0, 12, 12, 51, 51, 51, 51, 51, 51, 63, 63,  0,  0,  0,  0,  0,
        0,  0,  0,  0, 15, 63,255,248,224,128,  0,  0,  3, 15, 63,127,255,239,207,141, 13, 12, 12, 12, 12, 12, 12, 12, 30,127,225,128,  0,  0,255,255,  0,  0,128,225,127, 30, 12, 12, 12, 12, 12, 12, 12, 13,141,207,239,255,127, 63, 15,  3,  0,  0,128,224,248,255, 63, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  3,  7, 15, 62,124,248,240,224,192,128,  1,  3,  7, 15, 30, 28, 60, 56,120,112,112,224,224,225,231,254,248,255,255,248,254,231,225,224,224,112,112,120, 56, 60, 28, 30, 15,  7,  3,  1,128,192,224,240,248,124, 62, 15,  7,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  7, 15, 14, 30, 28, 60, 56,120,112,112,112,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,112,112,112,120, 56, 60, 28, 30, 14, 15,  7,  3,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
    };
    oled_write_raw_P(kyria_logo, sizeof(kyria_logo));
}

static void render_qmk_logo(void) {
  static const char PROGMEM qmk_logo[] = {
    0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
    0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
    0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};

  oled_write_P(qmk_logo, false);
}

static void render_status(void) {
    // QMK Logo and version information
    render_qmk_logo();
    oled_write_P(PSTR("Kyria rev1.0\n\n"), false);

    // Write WPM
    #ifdef WPM_ENABLE
        sprintf(wpm_str, "WPM:   %03d", get_current_wpm());
        oled_write_P(PSTR("\n"), false);
        oled_write(wpm_str, false);
    #endif

    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case _QWERTZ:
            oled_write_P(PSTR("QWERTZ\n"), false);
            break;
        case _KOY:
            oled_write_P(PSTR("KOY\n"), false);
            break;
        case _NUM:
            oled_write_P(PSTR("Numbers\n"), false);
            break;
        case _SYM:
            oled_write_P(PSTR("Symbols\n"), false);
            break;
        case _NAV:
            oled_write_P(PSTR("Navigation\n"), false);
            break;
        case _FNC:
            oled_write_P(PSTR("Functions\n"), false);
            break;
        case _KUMA:
            oled_write_P(PSTR("Dynamics NAV\n"), false);
            break;
        case _GAMING:
            oled_write_P(PSTR("Gaming\n"), false);
            break;
        default:
            oled_write_P(PSTR("Undefined\n"), false);
    }

    // Host Keyboard LED Status
    /*
    uint8_t led_usb_state = host_keyboard_leds();
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_NUM_LOCK) ? PSTR("NUMLCK ") : PSTR("       "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_CAPS_LOCK) ? PSTR("CAPLCK ") : PSTR("       "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_SCROLL_LOCK) ? PSTR("SCRLCK ") : PSTR("       "), false);
    */
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status(); // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
        render_kyria_logo();
    }
}
#endif

#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) {
    // Left Encoder
    if (index == 0) {
        switch (get_highest_layer(layer_state)) {
        //switch(biton32(layer_state)){
            case _NAV:
                if (clockwise) {
                    tap_code(KC_MEDIA_NEXT_TRACK);
                } else {
                    tap_code(KC_MEDIA_PREV_TRACK);
                }
            default:
                // Volume control
                if (clockwise) {
                    tap_code(KC_VOLD);
                } else {
                    tap_code(KC_VOLU);
                }
        }
    }
    // Right Encoder
    else if (index == 1) {
        // Page up/Page down
        if (clockwise) {
            tap_code(KC_PGUP);
        } else {
            tap_code(KC_PGDN);
        }
    }
}
#endif

LEADER_EXTERNS();

void matrix_scan_user(void) {
    LEADER_DICTIONARY() {
        leading = false;
        leader_end();

        SEQ_TWO_KEYS(KC_E, KC_S) { // ¯\_(ツ)_/¯
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
