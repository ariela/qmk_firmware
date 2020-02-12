/* Copyright 2018 Carlos Filoteo
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

//--+----1----+----2----+----3----+----4----+----5----+----6----+----7----+----8----+----9----+----0
// レイヤー定義
//--+----1----+----2----+----3----+----4----+----5----+----6----+----7----+----8----+----9----+----0
enum layer_number {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _ADJUST,
};

//--+----1----+----2----+----3----+----4----+----5----+----6----+----7----+----8----+----9----+----0
// カスタムキーコード定義
//--+----1----+----2----+----3----+----4----+----5----+----6----+----7----+----8----+----9----+----0
enum custom_keycodes {
    QWERTY = SAFE_RANGE,    // デフォルトレイヤー
    LOWER,                  // タップ時英数/ホールド時Lowerレイヤー切り替え
    RAISE,                  // タップ時かな/ホールド時Raiseレイヤー切り替え
    EISU,                   // 英数
    KANA                    // かな
};

#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* QWERTYレイヤー
   * ,-------------------------------------------------------------------------.
   * | Tab |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  | BkSp  |
   * |-------------------------------------------------------------------------+
   * | Ctrl |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |   '  |
   * |-------------------------------------------------------------------------+
   * | Shift |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  |Sh/En|
   * |-------------------------------------------------------------------------+
   * | En  | Esc | Alt | Gui | Lower|   Space   | Raise| Left| Down|  Up |Right|
   * `-------------------------------------------------------------------------'
   */
  [_QWERTY] = LAYOUT( \
    KC_TAB  , KC_Q    , KC_W    , KC_E    , KC_R    , KC_T    , KC_Y    , KC_U    , KC_I    , KC_O    , KC_P    , KC_BSPC , \
    KC_LCTL , KC_A    , KC_S    , KC_D    , KC_F    , KC_G    , KC_H    , KC_J    , KC_K    , KC_L    , KC_SCLN , KC_QUOT , \
    KC_LSFT , KC_Z    , KC_X    , KC_C    , KC_V    , KC_B    , KC_N    , KC_M    , KC_COMM , KC_DOT  , KC_SLSH , KC_SFTENT, \
    EISU    , KC_ESC  , KC_LALT , KC_LGUI , LOWER   ,      KC_SPC       , RAISE   , KC_LEFT , KC_DOWN , KC_UP   , KC_RGHT \
  ),

  /* Lowerレイヤー
   * ,-------------------------------------------------------------------------.
   * |  `  |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |       |
   * |-------------------------------------------------------------------------+
   * | BkSp |  6  |  7  |  8  |  9  |  0  |     |     |     |     |     |      |
   * |-------------------------------------------------------------------------+
   * |       |     |     |     |  -  |  [  |  ]  |  =  |     |     |     |     |
   * |-------------------------------------------------------------------------+
   * | Ja  |     |     |     |      |           |      |     |     |     |     |
   * `-------------------------------------------------------------------------'
   */
  [_LOWER] = LAYOUT( \
    KC_GRV  , KC_1    , KC_2    , KC_3    , KC_4    , KC_5    , KC_6    , KC_7    , KC_8    , KC_9    , KC_0    , _______ , \
    _______ , KC_6    , KC_7    , KC_8    , KC_9    , KC_0    , _______ , _______ , _______ , _______ , _______ , _______ , \
    _______ , _______ , _______ , _______ , KC_MINS , KC_LBRC , KC_RBRC , KC_EQUAL , _______ , _______ , _______ , _______ , \
    _______ , _______ , _______ , _______ , _______ ,      _______      , _______ , _______ , _______ , _______ , _______ \
  ),

  /* Raiseレイヤー
   * ,-------------------------------------------------------------------------.
   * |  ~  |  !  |  @  |  #  |  $  |  %  |  ^  |  &  |  *  |  (  |  )  |       |
   * |-------------------------------------------------------------------------+
   * |      |  ^  |  &  |  *  |  (  |  )  |     |     |     |     |     |      |
   * |-------------------------------------------------------------------------+
   * |       |     |     |     |  _  |  {  |  }  |  +  |     |     |     |     |
   * |-------------------------------------------------------------------------+
   * |     |     |     |     |      |           |      |     |     |     |     |
   * `-------------------------------------------------------------------------'
   */
  [_RAISE] = LAYOUT( \
    KC_TILD , KC_EXLM , KC_AT   , KC_HASH , KC_DLR  , KC_PERC , KC_CIRC , KC_AMPR , KC_ASTR , KC_LPRN , KC_RPRN , _______ , \
    _______ , KC_CIRC , KC_AMPR , KC_ASTR , KC_LPRN , KC_RPRN , _______ , _______ , _______ , _______ , _______ , _______ , \
    _______ , _______ , _______ , _______ , KC_UNDS , KC_LCBR , KC_RCBR , KC_PLUS , _______ , _______ , _______ , _______ , \
    _______ , _______ , _______ , _______ , _______ ,      _______      , _______ , _______ , _______ , _______ , _______ \
  ),

  /* Adjustレイヤー
   * ,-------------------------------------------------------------------------.
   * |  F1 |  F2 |  F3 |  F4 |  F5 |  F6 |  F7 |  F8 |  F9 | F10 | F11 |  F12  |
   * |-------------------------------------------------------------------------+
   * |  F7  |  F8 |  F9 | F10 | F11 | F12 |  ←  |  ↓  |  ↑  |  →  |     |      |
   * |-------------------------------------------------------------------------+
   * |       |     |     |     |     |     |     |     |     |     |     |     |
   * |-------------------------------------------------------------------------+
   * |     |     |     |     |      |           |      |     |     |     |     |
   * `-------------------------------------------------------------------------'
   */
  [_ADJUST] = LAYOUT( \
    KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   , KC_F6   , KC_F7   , KC_F8   , KC_F9   , KC_F10  , KC_F11  , KC_F12  , \
    KC_F7   , KC_F8   , KC_F9   , KC_F10  , KC_F11  , KC_F12  , KC_LEFT , KC_DOWN , KC_UP   , KC_RGHT , _______ , _______ , \
    RGB_MOD , RGB_HUI , RGB_SAI , RGB_VAI , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , \
    RGB_RMOD, RGB_HUD , RGB_SAD , RGB_VAD , _______ ,      RGB_TOG      , _______ , _______ , _______ , _______ , RESET   \
  ),
};

//--+----1----+----2----+----3----+----4----+----5----+----6----+----7----+----8----+----9----+----0
// 変数定義
//--+----1----+----2----+----3----+----4----+----5----+----6----+----7----+----8----+----9----+----0

static bool u_pressed_lower = false;
static bool u_pressed_raise = false;
static uint16_t u_pressed_lower_time = 0;
static uint16_t u_pressed_raise_time = 0;

//--+----1----+----2----+----3----+----4----+----5----+----6----+----7----+----8----+----9----+----0
// 関数定義
//--+----1----+----2----+----3----+----4----+----5----+----6----+----7----+----8----+----9----+----0

/**
 * 押下時にレイヤーの変更を行う
 */
bool change_layer_onpress(uint16_t layer, keyrecord_t *record, bool is_tri_layer) {
    if (record->event.pressed) {
        layer_on(layer);
    } else {
        layer_off(layer);
    }
    if (is_tri_layer) {
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
    }
    return false;
}

/**
 * タップ時にキーコード発行/ホールド時にレイヤー変更を行う
 */
bool change_layer_onpress_with_tap(uint16_t layer, uint16_t keycode, keyrecord_t *record, bool *flag, uint16_t *time, bool is_tri_layer) {
    if (record->event.pressed) {
        *flag = true;
        *time = record->event.time;
        layer_on(layer);
    } else {
        layer_off(layer);
        if (*flag && (TIMER_DIFF_16(record->event.time, *time) < TAPPING_TERM)) {
            register_code(keycode);
            unregister_code(keycode);
        }
        *flag = false;
    }
    if (is_tri_layer) {
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
    }
    return false;
}

/**
 * 文字変換キー押下時の処理を行う
 */
bool lang_key_onpress(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        if(keymap_config.swap_lalt_lgui == false){
            register_code(keycode);
        }else{
            SEND_STRING(SS_LALT("`"));
        }
    } else {
        unregister_code(keycode);
    }
    return false;
}

/**
 * キー処理実行時ユーザ定義
 */
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    bool result;
    switch (keycode) {
        case QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
            break;
        case LOWER:
            result = change_layer_onpress_with_tap(_LOWER, KC_LANG2, record, &u_pressed_lower, &u_pressed_lower_time, true);
            if (record->event.pressed) {
                // 他のキーのタップ機能を停止させる
                u_pressed_raise = false; 
            }
            return result;
            break;
        case RAISE:
            result = change_layer_onpress_with_tap(_RAISE, KC_LANG1, record, &u_pressed_raise, &u_pressed_raise_time, true);
            if (record->event.pressed) {
                // 他のキーのタップ機能を停止させる
                u_pressed_lower = false;
            }
            return result;
            break;
        case EISU:
            return lang_key_onpress(KC_LANG2, record);
            break;
        case KANA:
            return lang_key_onpress(KC_LANG1, record);
            break;
    }
  
    // タップ対応キーと他のキーが同時押しされた場合はタップ機能を停止させる
    u_pressed_lower = false;
    u_pressed_raise = false;

    // キー入力パススルー
    return true;
}
