#include QMK_KEYBOARD_H


enum layers {
    _NAV = 0,
    _GEO,
    _CON
};



#define VISI    KC_SPC
#define TOP     KC_2
#define FRONT   KC_1
#define LEFT    KC_6
#define BTTM    KC_5
#define REAR    KC_4
#define RIGHT   KC_3

//Define FreeCAD Keys
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

}
#endif

//Process FreeCAD key combos
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

