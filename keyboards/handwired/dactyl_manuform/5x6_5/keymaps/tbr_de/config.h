/*
Copyright 2012 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#define USE_SERIAL

#define MASTER_LEFT
//#define EE_HANDS

#define KINETIC_SPEED  //?

#define UNICODE_SELECTED_MODES UC_LNX
#define LEADER_PER_KEY_TIMING
#define LEADER_TIMEOUT 350
#define TAPPING_TOGGLE 3

#define IGNORE_MOD_TAP_INTERRUPT
#define TAPPING_TERM 200
#define TAP_CODE_DELAY 10


#define LAYOUT_5x6_5T(\
  L00, L01, L02, L03, L04, L05,                          R00, R01, R02, R03, R04, R05, \
  L10, L11, L12, L13, L14, L15,                          R10, R11, R12, R13, R14, R15, \
  L20, L21, L22, L23, L24, L25,                          R20, R21, R22, R23, R24, R25, \
  L30, L31, L32, L33, L34, L35,                          R30, R31, R32, R33, R34, R35, \
            L42, L43,      L44, L52, L53,      R52, R53, R41,      R42, R43,           \
                                L54, L55,      R50, R51                                \
  ) \
  { \
    { L00,   L01,   L02, L03, L04, L05   }, \
    { L10,   L11,   L12, L13, L14, L15   }, \
    { L20,   L21,   L22, L23, L24, L25   }, \
    { L30,   L31,   L32, L33, L34, L35   }, \
    { KC_NO, KC_NO, L42, L43, L44, KC_NO }, \
    { KC_NO, KC_NO, L52, L53, L54, L55   }, \
                                          \
    { R00,   R01, R02, R03, R04,   R05   }, \
    { R10,   R11, R12, R13, R14,   R15   }, \
    { R20,   R21, R22, R23, R24,   R25   }, \
    { R30,   R31, R32, R33, R34,   R35   }, \
    { KC_NO, R41, R42, R43, KC_NO, KC_NO }, \
    { R50,   R51, R52, R53, KC_NO, KC_NO }  \
}
