#include QMK_KEYBOARD_H


enum layers {
    _NAV = 0,
    _GEO,
    _CON
};



/* Enum for the tap dancing keys */
/*
enum tap_codes {
    A_Q, E_Q, E_U, E_E,
    A_Y, I_I, O_C, U_U
};


void send_french_unicode_char(uint8_t count, char *once, char *twice)
{
    if (count <= 1)
	send_unicode_hex_string(once);
    else
	send_unicode_hex_string(twice);
}

void dance_a_q(qk_tap_dance_state_t *state, void *user_data)
{
    send_french_unicode_char(state->count, FR_A_GRAVE, FR_L_QUOTE);
}

void dance_e_q(qk_tap_dance_state_t *state, void *user_data)
{
    send_french_unicode_char(state->count, FR_E_AIGU, FR_R_QUOTE);
}

void dance_e_u(qk_tap_dance_state_t *state, void *user_data)
{
    send_french_unicode_char(state->count, FR_E_GRAVE, FR_U_GRAVE);
}

void dance_e_e(qk_tap_dance_state_t *state, void *user_data)
{
    send_french_unicode_char(state->count, FR_E_HAT, FR_E_UMLAUT);
}

void dance_a_y(qk_tap_dance_state_t *state, void *user_data)
{
    send_french_unicode_char(state->count, FR_A_HAT, FR_Y_UMLAUT);
}

void dance_i_i(qk_tap_dance_state_t *state, void *user_data)
{
    send_french_unicode_char(state->count, FR_I_HAT, FR_I_UMLAUT);
}

void dance_o_c(qk_tap_dance_state_t *state, void *user_data)
{
    send_french_unicode_char(state->count, FR_O_HAT, FR_C_CIRCUM);
}

void dance_u_u(qk_tap_dance_state_t *state, void *user_data)
{
    send_french_unicode_char(state->count, FR_U_HAT, FR_U_UMLAUT);
}
*/
/* Define the tap dance actions for the french characters */
/*
qk_tap_dance_action_t tap_dance_actions[] = {
    [A_Q] = ACTION_TAP_DANCE_FN(dance_a_q),
    [E_Q] = ACTION_TAP_DANCE_FN(dance_e_q),
    [E_U] = ACTION_TAP_DANCE_FN(dance_e_u),
    [E_E] = ACTION_TAP_DANCE_FN(dance_e_e),

    [A_Y] = ACTION_TAP_DANCE_FN(dance_a_y),
    [I_I] = ACTION_TAP_DANCE_FN(dance_i_i),
    [O_C] = ACTION_TAP_DANCE_FN(dance_o_c),
    [U_U] = ACTION_TAP_DANCE_FN(dance_u_u)
};

*/

#define VISI    KC_SPC
#define TOP     KC_2
#define FRONT   KC_1
#define LEFT    KC_6
#define BTTM    KC_5
#define REAR    KC_4
#define RIGHT   KC_3

enum custom_keycodes {
    FC_G_ARC = SAFE_RANGE,
    FC_G_CIRC,
    FC_G_CONIC,
    FC_G_SLOT,
    FC_G_LINE,
    FC_G_MULTI,
    FC_G_RECT,
    FC_G_HEX,
    FC_G_EXTRN,
    FC_V_SECTN,
    FC_G_GEOM,
    FC_C_POINT,
    FC_C_VERT,
    FC_C_HORZ,
    FC_C_DIA,
    FC_C_RAD,
    FC_C_WIDTH,
    FC_C_HEIGH,
    FC_C_TOUCH,
    FC_C_REF,
    FC_C_DIST,
    FC_C_ANGL,
    FC_V_FULL,
    FC_V_SEL,
    FC_C_EQL,
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_NAV] = LAYOUT(
        TO(_GEO),   VISI,       FC_V_FULL,    TOP,        FRONT,      FC_V_SEL,        _______,
		KC_DEL,     _______,    LEFT,         BTTM,       REAR,       RIGHT),

    [_GEO] = LAYOUT(
        TO(_CON),   FC_G_EXTRN,      FC_G_ARC,        FC_G_CIRC,       FC_G_CONIC,      FC_G_SLOT,           KC_M,
		FC_G_GEOM,  FC_V_SECTN,      FC_G_LINE,       FC_G_MULTI,      FC_G_RECT,       FC_G_HEX),

    [_CON] = LAYOUT(
        TO(_NAV),   FC_C_ANGL,       FC_C_POINT,      FC_C_VERT,       FC_C_HEIGH,      FC_C_DIA,            FC_C_EQL,
	    FC_C_REF,   FC_C_DIST,       FC_C_TOUCH,      FC_C_HORZ,       FC_C_WIDTH,      FC_C_RAD)

};

#ifdef OLED_DRIVER_ENABLE
void oled_task_user(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: \n"), false);

    switch (get_highest_layer(layer_state)) {
        case _NAV:
            oled_write_P(PSTR("   Navigation\n"), false);
            break;
        case _GEO:
            oled_write_P(PSTR("   Geometry\n"), false);
            break;
        case _CON:
            oled_write_P(PSTR("   Constraints\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }

    /*
    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
    */
}
#endif


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case FC_V_FULL:
        if (record->event.pressed) {
            // pressed
            SEND_STRING("vf");
        } else {
            // released
        }
        break;

    case FC_V_SEL:
        if (record->event.pressed) {
            // pressed
            SEND_STRING("vs");
        } else {
            // released
        }
        break;

    case FC_G_ARC:
        if (record->event.pressed) {
            // pressed
            SEND_STRING("ga");
        } else {
            // released
        }
        break;

    case FC_G_CIRC:
        if (record->event.pressed) {
            // pressed
            SEND_STRING("gc");
        } else {
            // released
        }
        break;

    case FC_G_CONIC:
        if (record->event.pressed) {
            // pressed
            SEND_STRING("ge");
        } else {
            // released
        }
        break;

    case FC_G_SLOT:
        if (record->event.pressed) {
            // pressed
            SEND_STRING("gs");
        } else {
            // released
        }
        break;

    case FC_G_LINE:
        if (record->event.pressed) {
            // pressed
            SEND_STRING("gl");
        } else {
            // released
        }
        break;

    case FC_G_MULTI:
        if (record->event.pressed) {
            // pressed
            SEND_STRING("gm");
        } else {
            // released
        }
        break;

    case FC_G_RECT:
        if (record->event.pressed) {
            // pressed
            SEND_STRING("gr");
        } else {
            // released
        }
        break;

    case FC_G_HEX:
        if (record->event.pressed) {
            // pressed
            SEND_STRING("gh");
        } else {
            // released
        }
        break;

    case FC_G_EXTRN:
        if (record->event.pressed) {
            // pressed
            SEND_STRING("gx");
        } else {
            // released
        }
        break;

    case FC_V_SECTN:
        if (record->event.pressed) {
            // pressed
            SEND_STRING("vn");
        } else {
            // released
        }
        break;

    case FC_G_GEOM:
        if (record->event.pressed) {
            // pressed
            SEND_STRING("gg");
        } else {
            // released
        }
        break;

    case FC_C_POINT:
        if (record->event.pressed) {
            // pressed
            SEND_STRING("bp");
        } else {
            // released
        }
        break;

    case FC_C_VERT:
        if (record->event.pressed) {
            // pressed
            SEND_STRING("bv");
        } else {
            // released
        }
        break;

    case FC_C_HORZ:
        if (record->event.pressed) {
            // pressed
            SEND_STRING("bh");
        } else {
            // released
        }
        break;

    case FC_C_RAD:
        if (record->event.pressed) {
            // pressed
            SEND_STRING("br");
        } else {
            // released
        }
        break;

    case FC_C_WIDTH:
        if (record->event.pressed) {
            // pressed
            SEND_STRING("bw");
        } else {
            // released
        }
        break;

    case FC_C_HEIGH:
        if (record->event.pressed) {
            // pressed
            SEND_STRING("bi");
        } else {
            // released
        }
        break;

    case FC_C_TOUCH:
        if (record->event.pressed) {
            // pressed
            SEND_STRING("bt");
        } else {
            // released
        }
        break;

    case FC_C_REF:
        if (record->event.pressed) {
            // pressed
            SEND_STRING("bf");
        } else {
            // released
        }
        break;

    case FC_C_DIST:
        if (record->event.pressed) {
            // pressed
            SEND_STRING("bm");
        } else {
            // released
        }
        break;

    case FC_C_ANGL:
        if (record->event.pressed) {
            // pressed
            SEND_STRING("ba");
        } else {
            // released
        }
        break;

    case FC_C_DIA:
        if (record->event.pressed) {
            // pressed
            SEND_STRING("bd");
        } else {
            // released
        }
        break;

    case FC_C_EQL:
        if (record->event.pressed) {
            // pressed
            SEND_STRING("be");
        } else {
            // released
        }
        break;

    }
    return true;
};

