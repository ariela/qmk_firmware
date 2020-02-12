#pragma once

#define LAYOUT_wrapper(...)             LAYOUT(__VA_ARGS__)
#define LAYOUT_ortho_5x5_wrapper(...)   LAYOUT_ortho_5x5(__VA_ARGS__)
/*
Blocks for each of the four major keyboard layouts
Organized so we can quickly adapt and modify all of them
at once, rather than for each keyboard, one at a time.
And this allows for much cleaner blocks in the keymaps.
For instance Tap/Hold for Control on all of the layouts

NOTE: These are all the same length.  If you do a search/replace
  then you need to add/remove underscores to keep the
  lengths consistent.
*/

#define ___________________QWERTY_L1___________________     KC_Q,     KC_W,     KC_E,     KC_R,     KC_T
#define ___________________QWERTY_L2___________________     KC_A,     KC_S,     KC_D,     KC_F,     KC_G
#define ___________________QWERTY_L3___________________     KC_Z,     KC_X,     KC_C,     KC_V,     KC_B

#define ___________________QWERTY_R1___________________     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P
#define ___________________QWERTY_R2___________________     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN
#define ___________________QWERTY_R3___________________     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH


#define ___________________RAISE__L1___________________     KC_EXLM , KC_AT   , KC_HASH , KC_DLR  , KC_PERC
#define ___________________RAISE__L2___________________     KC_CIRC , KC_AMPR , KC_ASTR , KC_LPRN , KC_RPRN

#define ___________________RAISE__R1___________________     KC_CIRC , KC_AMPR , KC_ASTR , KC_LPRN , KC_RPRN
#define ___________________RAISE__R2___________________     _______ , KC_UNDS , KC_PLUS , KC_LCBR , KC_RCBR

#define ___________________LOWER__L1___________________     KC_1,     KC_2,     KC_3,     KC_4,     KC_5
#define ___________________LOWER__L2___________________     KC_6,     KC_7,     KC_8,     KC_9,     KC_0

#define ___________________LOWER__R1___________________     KC_6,     KC_7,     KC_8,     KC_9,     KC_0
#define ___________________LOWER__R2___________________     _______ , KC_MINS , KC_EQL ,  KC_LBRC , KC_RBRC

#define ________________________ADJUST_L1________________________   KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   , KC_F6
#define ________________________ADJUST_L2________________________   KC_F7   , KC_F8   , KC_F9   , KC_F10  , KC_F11  , KC_F12

#define ________________________ADJUST_R1________________________   KC_F7   , KC_F8   , KC_F9   , KC_F10  , KC_F11  , KC_F12
#define ________________________ADJUST_R2________________________   KC_LEFT , KC_DOWN , KC_UP   , KC_RGHT , _______ , _______

#define _________________                                           _______ , _______
#define ___________________________                                 _______ , _______ , _______
#define _____________________________________                       _______ , _______ , _______ , _______
#define _______________________________________________             _______ , _______ , _______ , _______ , _______
#define _________________________________________________________   _______ , _______ , _______ , _______ , _______ , _______

#define _________NUMPAD__1_________             KC_PSLS , KC_PAST , KC_PMNS
#define _______________NUMPAD__2_____________   KC_P7   , KC_P8   , KC_P9   , KC_PPLS
#define _______________NUMPAD__3_____________   KC_P4   , KC_P5   , KC_P6   , KC_PPLS
#define _______________NUMPAD__4_____________   KC_P1   , KC_P2   , KC_P3   , KC_PENT
#define _______________NUMPAD__5_____________   KC_P0   , KC_P0   , KC_PDOT , KC_PENT
#define _______________NUMPAD_W5_____________   KC_P0   , KC_P00  , KC_PDOT , KC_PENT

#define ______________NUMLOCK_2______________   KC_HOME , KC_UP   , KC_PGUP , XXXXXXX
#define ______________NUMLOCK_3______________   KC_LEFT , XXXXXXX , KC_RGHT , XXXXXXX
#define ______________NUMLOCK_4______________   KC_END  , KC_DOWN , KC_PGDN , XXXXXXX
#define ______________NUMLOCK_5______________   KC_INS  , KC_INS  , KC_PDOT , XXXXXXX
#define ______________NUMLOCKW5______________   KC_INS  , XXXXXXX , KC_PDOT , XXXXXXX

#define ______________NUMFUNC_1______________   KC_F10  , KC_F11  , KC_F12  , _______
#define ______________NUMFUNC_2______________   KC_F7   , KC_F8   , KC_F9   , _______
#define ______________NUMFUNC_3______________   KC_F4   , KC_F5   , KC_F6   , _______
#define ______________NUMFUNC_4______________   KC_F1   , KC_F2   , KC_F3   , _______
