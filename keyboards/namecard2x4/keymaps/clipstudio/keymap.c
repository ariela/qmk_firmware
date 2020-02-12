/* Copyright 2018 takashiski
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
#include "keymap_jp.h"

// Macモード(trueに指定した際は起動時にMacモードになる)
static bool mode_mac = true;

//--+----1----+----2----+----3----+----4----+----5----+----6----+----7----+----8----+----9----+----0
// レイヤー定義
//--+----1----+----2----+----3----+----4----+----5----+----6----+----7----+----8----+----9----+----0
enum layer_number {
    _BASE = 0,
    _CANVAS,
    _CANVAS_MAC,
	_OTHER,
    _OTHER_MAC,
	_KEYBOARD,
};

//--+----1----+----2----+----3----+----4----+----5----+----6----+----7----+----8----+----9----+----0
// カスタムキーコード定義
//--+----1----+----2----+----3----+----4----+----5----+----6----+----7----+----8----+----9----+----0
enum custom_keycodes {
  L_CANVS = SAFE_RANGE,
  L_OTHER,
  L_KEYBD,
  M_WIN,
  M_MAC,
};

//--+----1----+----2----+----3----+----4----+----5----+----6----+----7----+----8----+----9----+----0
// 複合キーコード定義
//--+----1----+----2----+----3----+----4----+----5----+----6----+----7----+----8----+----9----+----0
// 拡大
#define KC_ZMIN LCTL(KC_PPLS)
#define KM_ZMIN LGUI(KC_PPLS)
// 縮小
#define KC_ZMOT LCTL(KC_PMNS)
#define KM_ZMOT LGUI(KC_PMNS)
// 100%表示
#define KC_D100 LCA_T(KC_0)
#define KM_D100 LGUI(LALT(KC_0))
// 全体表示
#define KC_DFUL LCTL(KC_0)
#define KM_DFUL LGUI(KC_0)
// 巻き戻し
#define KM_UNDO LGUI(KC_Z)
// やり直し
#define KC_REDO C_S_T(KC_Z)
#define KM_REDO LGUI(LSFT(KC_Z))
// コピー
#define KM_COPY LGUI(KC_C)
// 貼り付け
#define KM_PSTE LGUI(KC_V)
// 切り取り
#define KM_CUT LGUI(KC_X)
// 保存
#define KC_SAVE LCTL(KC_S)
#define KM_SAVE LGUI(KC_S)

// L_CANVS タップ時キー設定
#define CANVS_TAP SS_TAP(X_NONUS_HASH)
// L_OTHER タップ時キー設定
#define OTHER_TAP SS_TAP(X_RBRACKET)
// L_KEYBOARD タップ時キー設定
#define KEYBD_TAP SS_LSFT("q")

#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base
     * ,-------------------------------------------.
     * |   鉛筆   | 消しゴム | スポイト | ブラシ大 | タップ
     * |          |          |          |→ _CANVAS | ホールド
     * |----------+----------+----------+----------|
     * |    筆    |塗りつぶし| Qアクセス| ブラシ小 | タップ
     * |          |          |→_KEYBOARD|→ _OTHER  | ホールド
     * `-------------------------------------------'
     */
    [_BASE] = LAYOUT(
        KC_P,	 KC_E,	  KC_I,	   L_CANVS,
        KC_B,	 KC_G,	  L_KEYBD, L_OTHER
    ),

    /* Canvas
     * ,-------------------------------------------.
     * |   拡大   | 100%表示 |  左回転  | holding  | タップ
     * |          |          |          |          | ホールド
     * |----------+----------+----------+----------|
     * |   縮小   | 全体表示 |  右回転  | 手のひら | タップ
     * |          |          |          |          | ホールド
     * `-------------------------------------------'
    */
    [_CANVAS] = LAYOUT(
        KC_ZMIN, KC_D100, KC_MINS, _______,
        KC_ZMOT, KC_DFUL, JP_CIRC, KC_SPC
    ),
    [_CANVAS_MAC] = LAYOUT(
        KM_ZMIN, KM_D100, KC_MINS, _______,
        KM_ZMOT, KM_DFUL, JP_CIRC, KC_SPC
    ),

    /* Other
     * ,-------------------------------------------.
     * | 取り消し |  コピー  | 切り取り | 上書保存 | タップ
     * |          |          |          |          | ホールド
     * |----------+----------+----------+----------|
     * | やり直し | ペースト |   消去   | holding  | タップ
     * |          |          |          |          | ホールド
     * `-------------------------------------------'
     */
    [_OTHER] = LAYOUT(
        KC_UNDO, KC_COPY, KC_CUT,  KC_SAVE,
        KC_REDO, KC_PSTE, KC_BSPC, _______
    ),
    [_OTHER_MAC] = LAYOUT(
        KM_UNDO, KM_COPY, KM_CUT,  KM_SAVE,
        KM_REDO, KM_PSTE, KC_BSPC, _______
    ),

    /* Keyboard
     * ,-------------------------------------------.
     * |Winモード |          |          |          | タップ
     * |          |          |          |          | ホールド
     * |----------+----------+----------+----------|
     * |Macモード |          | holding  |          | タップ
     * |          |          |          |          | ホールド
     * `-------------------------------------------'
     */
    [_KEYBOARD] = LAYOUT(
        M_WIN,   XXXXXXX, XXXXXXX, XXXXXXX,
        M_MAC,   XXXXXXX, _______, XXXXXXX
    ),
};

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

static bool pressed_canvas   = false;
static bool pressed_other    = false;
static bool pressed_keyboard = false;
static uint16_t pressed_time_canvas   = 0;
static uint16_t pressed_time_other    = 0;
static uint16_t pressed_time_keyboard = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case L_CANVS:
            // タップで「ブラシサイズ大」、ホールドで「Canvas」
            if (record->event.pressed) {
                pressed_canvas = true;
                pressed_time_canvas = record->event.time;
                if (!mode_mac) {
                    layer_on(_CANVAS);
                } else {
                    layer_on(_CANVAS_MAC);
                }
            } else {
                if (!mode_mac) {
                    layer_off(_CANVAS);
                } else {
                    layer_off(_CANVAS_MAC);
                }
                if (pressed_canvas && (TIMER_DIFF_16(record->event.time, pressed_time_canvas) < TAPPING_TERM)) {
                    SEND_STRING(CANVS_TAP);
                }
                pressed_canvas = false;
            }
            return false;
            break;
        case L_OTHER:
            // タップで「ブラシサイズ小」、ホールドで「Other」
            if (record->event.pressed) {
                pressed_other = true;
                pressed_time_other = record->event.time;
                if (!mode_mac) {
                    layer_on(_OTHER);
                } else {
                    layer_on(_OTHER_MAC);
                }
            } else {
                if (!mode_mac) {
                    layer_off(_OTHER);
                } else {
                    layer_off(_OTHER_MAC);
                }
                if (pressed_other && (TIMER_DIFF_16(record->event.time, pressed_time_other) < TAPPING_TERM)) {
                    SEND_STRING(OTHER_TAP);
                }
                pressed_other = false;
            }
            return false;
            break;
        case L_KEYBD:
            // タップで「クイックアクセス(Shift+Q)、ホールドで「KEYBOARD」
            if (record->event.pressed) {
                pressed_keyboard = true;
                pressed_time_keyboard = record->event.time;
                layer_on(_KEYBOARD);
            } else {
                layer_off(_KEYBOARD);
                if (pressed_keyboard && (TIMER_DIFF_16(record->event.time, pressed_time_keyboard) < TAPPING_TERM)) {
                    SEND_STRING(KEYBD_TAP);
                }
                pressed_keyboard = false;
            }
            return false;
            break;
        case M_WIN:
            mode_mac = false;
            if (IS_LAYER_ON(_CANVAS_MAC)) {
                layer_off(_CANVAS_MAC);
                layer_on(_CANVAS);
            }
            if (IS_LAYER_ON(_OTHER_MAC)) {
                layer_off(_OTHER_MAC);
                layer_on(_OTHER);
            }
            return false;
            break;
        case M_MAC:
            mode_mac = true;
            if (IS_LAYER_ON(_CANVAS)) {
                layer_off(_CANVAS);
                layer_on(_CANVAS_MAC);
            }
            if (IS_LAYER_ON(_OTHER)) {
                layer_off(_OTHER);
                layer_on(_OTHER_MAC);
            }
            return false;
            break;
        default:
            if (record->event.pressed) {
                // フラグリセット
                pressed_canvas   = false;
                pressed_other    = false;
                pressed_keyboard = false;
            }
            break;
    };
    return true;
}

void led_set_user(uint8_t usb_led) {
}
