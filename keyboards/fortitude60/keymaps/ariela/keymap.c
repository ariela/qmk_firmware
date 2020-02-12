#include QMK_KEYBOARD_H
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 16

enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    LOWER,
    RAISE,
    ADJUST,
    EISU,
    KANA
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Qwerty
     * ,-----------------------------------------.             ,-----------------------------------------.
     * |   `  |   1  |   2  |   3  |   4  |   5  |             |   6  |   7  |   8  |   9  |   0  | Bksp |
     * |------+------+------+------+------+------|             |------+------+------+------+------+------|
     * | Tab  |   Q  |   W  |   E  |   R  |   T  |             |   Y  |   U  |   I  |   O  |   P  |  \   |
     * |------+------+------+------+------+------|             |------+------+------+------+------+------|
     * | Ctrl |   A  |   S  |   D  |   F  |   G  |             |   H  |   J  |   K  |   L  |   ;  |  "   |
     * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
     * | Shift|   Z  |   X  |   C  |   V  |   B  | EISU | KANA |   N  |   M  |   ,  |   .  |   /  |Enter |
     * `-------------+------+------+------+------+------+------+------+------+------+------+-------------'
     *               | Esc  | Alt  | GUI  |Space |Lower |Raise |Space |Enter |   [  |   ]  |
     *               `---------------------------------------------------------------------'
     */
    [_QWERTY] = LAYOUT( \
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS, \
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    EISU,    KANA,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,  \
                          KC_ESC,  KC_LALT, KC_LGUI, KC_SPC,  LOWER,   RAISE,   KC_SPC,  KC_ENT,  KC_LBRC, KC_RBRC \
    ),
      //_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,

    /* Lower
     * ,-----------------------------------------.             ,-----------------------------------------.
     * | Esc  |   !  |   @  |   #  |   $  |   %  |             |   ^  |   &  |   *  |   (  |   )  | Del  |
     * |------+------+------+------+------+------|             |------+------+------+------+------+------|
     * |      |      |      |      |      |      |             | Home |PgDown| PgUp | End  |      |      |
     * |------+------+------+------+------+------|             |------+------+------+------+------+------|
     * |      |      |      |      |      |      |             |      |   _  |   +  |   {  |   }  |  |   |
     * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
     * `-------------+------+------+------+------+------+------+------+------+------+------+-------------'
     *               |      |      |      |      |      |      |      |      |      |      |
     *               `---------------------------------------------------------------------'
     */
    [_LOWER] = LAYOUT( \
        KC_ESC,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,  \
        _______, _______, _______, _______, _______, _______,                   KC_HOME, KC_PGDN, KC_PGDN, KC_END,  _______, _______, \
        _______, _______, _______, _______, _______, _______,                   _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
                          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
    ),
      //_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,

    /* Raise
     * ,-----------------------------------------.             ,-----------------------------------------.
     * |      |      |      |      |      |      |             |      |      |      |      |      |      |
     * |------+------+------+------+------+------.             ,------+------+------+------+------+------|
     * |      |      |      |      |      |      |             | Home |PgDown| PgUp | End  |      |      |
     * |------+------+------+------+------+------.             ,------+------+------+------+------+------|
     * |      |      |      |      |      |      |             |      |   -  |   =  |   [  |   ]  |  \   |
     * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
     * `-------------+------+------+------+------+------+------+------+------+------+------+-------------'
     *               |      |      |      |      |      |      |      |      |      |      |
     *               `---------------------------------------------------------------------'
     */
    [_RAISE] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______,                   KC_HOME, KC_PGDN, KC_PGDN, KC_END,  _______, _______, \
        _______, _______, _______, _______, _______, _______,                   _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
                          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
    ),
      //_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,

    /* Adjust (Lower + Raise)
     * ,-----------------------------------------.             ,-----------------------------------------.
     * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |             |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
     * |------+------+------+------+------+------.             ,------+------+------+------+------+------|
     * |Reset |      |  Up  |      |      |      |             | Home |PgDown| PgUp | End  |      |      |
     * |------+------+------+------+------+------.             ,------+------+------+------+------+------|
     * |      | Left | Down |Right |      |      |             | Left | Down |  Up  |Right |      |      |
     * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
     * |      |      |      |Aud on|Audoff|      | Mac  | Win  |      |      |      |      |      |      |
     * `-------------+------+------+------+------+------+------+------+------+------+------+-------------'
     *               |BL TOG|BL STP|BL BRT| Bksp |      |      |Enter |      |      |      |
     *               `---------------------------------------------------------------------'
     */
    [_ADJUST] = LAYOUT( \
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  \
        RESET,   _______, KC_UP,   _______, _______, _______,                   KC_HOME, KC_PGDN, KC_PGDN, KC_END,  _______, _______, \
        _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,                   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______, \
        _______, _______, _______, AU_ON,   AU_OFF,  _______, AG_NORM, AG_SWAP, _______, _______, _______, _______, _______, _______, \
                          BL_TOGG, BL_STEP, BL_BRTG, KC_BSPC, _______, _______, KC_ENT,  _______, _______, _______ \
    )
      //_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,

};

uint32_t layer_state_set_user(uint32_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
            break;
        case EISU:
            if (record->event.pressed) {
                if(keymap_config.swap_lalt_lgui==false){
                    register_code(KC_LANG2);
                }else{
                    SEND_STRING(SS_LALT("`"));
                }
            } else {
                unregister_code(KC_LANG2);
            }
            return false;
            break;
        case KANA:
            if (record->event.pressed) {
                if(keymap_config.swap_lalt_lgui==false){
                    register_code(KC_LANG1);
                }else{
                    SEND_STRING(SS_LALT("`"));
                }
            } else {
                unregister_code(KC_LANG1);
            }
            return false;
            break;
    }
    return true;
}
