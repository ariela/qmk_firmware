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
#include "keymap_clipstudio.h"

#ifdef RGBLIGHT_ENABLE
    //Following line allows macro to read current RGB settings
    extern rgblight_config_t rgblight_config;
#endif

//--+----1----+----2----+----3----+----4----+----5----+----6----+----7----+----8----+----9----+----0
// LED色定義
//--+----1----+----2----+----3----+----4----+----5----+----6----+----7----+----8----+----9----+----0
#ifdef RGBLIGHT_ENABLE
    /* rgblight_list.h 定義済み色 一覧
    #define rgblight_sethsv_noeeprom_white()       rgblight_sethsv_noeeprom (  0,   0, 255)
    #define rgblight_sethsv_noeeprom_red()         rgblight_sethsv_noeeprom (  0, 255, 255)
    #define rgblight_sethsv_noeeprom_coral()       rgblight_sethsv_noeeprom ( 16, 176, 255)
    #define rgblight_sethsv_noeeprom_orange()      rgblight_sethsv_noeeprom ( 39, 255, 255)
    #define rgblight_sethsv_noeeprom_goldenrod()   rgblight_sethsv_noeeprom ( 43, 218, 218)
    #define rgblight_sethsv_noeeprom_gold()        rgblight_sethsv_noeeprom ( 51, 255, 255)
    #define rgblight_sethsv_noeeprom_yellow()      rgblight_sethsv_noeeprom ( 60, 255, 255)
    #define rgblight_sethsv_noeeprom_chartreuse()  rgblight_sethsv_noeeprom ( 90, 255, 255)
    #define rgblight_sethsv_noeeprom_green()       rgblight_sethsv_noeeprom (120, 255, 255)
    #define rgblight_sethsv_noeeprom_springgreen() rgblight_sethsv_noeeprom (150, 255, 255)
    #define rgblight_sethsv_noeeprom_turquoise()   rgblight_sethsv_noeeprom (174,  90, 112)
    #define rgblight_sethsv_noeeprom_teal()        rgblight_sethsv_noeeprom (180, 255, 128)
    #define rgblight_sethsv_noeeprom_cyan()        rgblight_sethsv_noeeprom (180, 255, 255)
    #define rgblight_sethsv_noeeprom_azure()       rgblight_sethsv_noeeprom (186, 102, 255)
    #define rgblight_sethsv_noeeprom_blue()        rgblight_sethsv_noeeprom (240, 255, 255)
    #define rgblight_sethsv_noeeprom_purple()      rgblight_sethsv_noeeprom (270, 255, 255)
    #define rgblight_sethsv_noeeprom_magenta()     rgblight_sethsv_noeeprom (300, 255, 255)
    #define rgblight_sethsv_noeeprom_pink()        rgblight_sethsv_noeeprom (330, 128, 255)
    */
    // レイヤーがBASE時の色設定
    #define u_rgblight_layer_base()     rgblight_sethsv_noeeprom_cyan()
    // レイヤーがCANVAS時の色設定
    #define u_rgblight_layer_canvas()   rgblight_sethsv_noeeprom_magenta()
    // レイヤーがOTHER時の色設定
    #define u_rgblight_layer_other()    rgblight_sethsv_noeeprom_yellow()
    // レイヤーがKEYBOARD時の色設定
    #define u_rgblight_layer_keyboard() rgblight_sethsv_noeeprom_chartreuse()
#endif

//--+----1----+----2----+----3----+----4----+----5----+----6----+----7----+----8----+----9----+----0
// レイヤー定義
//--+----1----+----2----+----3----+----4----+----5----+----6----+----7----+----8----+----9----+----0
enum layer_number {
    _BASE = 0,
    _CANVAS,
    _OTHER,
    _KEYBOARD,
};

//--+----1----+----2----+----3----+----4----+----5----+----6----+----7----+----8----+----9----+----0
// カスタムキーコード定義
//--+----1----+----2----+----3----+----4----+----5----+----6----+----7----+----8----+----9----+----0
enum custom_keycodes {
    L_CANVS = SAFE_RANGE,
    L_OTHER,
    L_KEYBD,
};

//--+----1----+----2----+----3----+----4----+----5----+----6----+----7----+----8----+----9----+----0
// キーコード定義
//--+----1----+----2----+----3----+----4----+----5----+----6----+----7----+----8----+----9----+----0
#define _______ KC_TRNS
#define XXXXXXX KC_NO

/* Base
 * ,-------------------------------------------.
 * |   鉛筆   | 消しゴム | スポイト | ブラシ大 | タップ
 * |          |          |          |→ _CANVAS | ホールド
 * |----------+----------+----------+----------|
 * |    筆    |塗りつぶし| Qアクセス| ブラシ小 | タップ
 * |          |          |→_KEYBOARD|→ _OTHER  | ホールド
 * `-------------------------------------------'
 */
#ifdef MODE_MAC
    #define KC_BASE_1 CS_TOOL_PEN
    #define KC_BASE_2 CS_TOOL_ERASER
    #define KC_BASE_3 CS_TOOL_DROPPER
    #define KC_BASE_4 SS_TAP(X_NONUS_HASH)  // 特殊キー/CS_BRUSH_SIZE_UP
    #define KC_BASE_5 CS_TOOL_BRUSH
    #define KC_BASE_6 CS_TOOL_FILL
    #define KC_BASE_7 SS_LSFT("q")          // 特殊キー/Shift + Q
    #define KC_BASE_8 SS_TAP(X_RBRACKET)    // 特殊キー/CS_BRUSH_SIZE_DOWN
#else
    #define KC_BASE_1 CS_TOOL_PEN
    #define KC_BASE_2 CS_TOOL_ERASER
    #define KC_BASE_3 CS_TOOL_DROPPER
    #define KC_BASE_4 SS_TAP(X_NONUS_HASH)  // 特殊キー/CS_BRUSH_SIZE_UP
    #define KC_BASE_5 CS_TOOL_BRUSH
    #define KC_BASE_6 CS_TOOL_FILL
    #define KC_BASE_7 SS_LSFT("q")          // 特殊キー/Shift + Q
    #define KC_BASE_8 SS_TAP(X_RBRACKET)    // 特殊キー/CS_BRUSH_SIZE_DOWN
#endif

/* Canvas
 * ,-------------------------------------------.
 * |   拡大   | 100%表示 |  左回転  | holding  | タップ
 * |          |          |          |          | ホールド
 * |----------+----------+----------+----------|
 * |   縮小   | 全体表示 |  右回転  | 手のひら | タップ
 * |          |          |          |          | ホールド
 * `-------------------------------------------'
 */
#ifdef MODE_MAC
    #define KC_CANVAS_1 CS_CANVAS_ZOOM_IN_MAC
    #define KC_CANVAS_2 CS_CANVAS_DISPLAY_100P_MAC
    #define KC_CANVAS_3 CS_CANVAS_ROTATE_LEFT
    #define KC_CANVAS_4 _______                         // ホールド状態
    #define KC_CANVAS_5 CS_CANVAS_ZOOM_OUT_MAC
    #define KC_CANVAS_6 CS_CANVAS_DISPLAY_OVERALL_MAC
    #define KC_CANVAS_7 CS_CANVAS_ROTATE_RIGHT
    #define KC_CANVAS_8 CS_MOVE_MODE
#else
    #define KC_CANVAS_1 CS_CANVAS_ZOOM_IN
    #define KC_CANVAS_2 CS_CANVAS_DISPLAY_100P
    #define KC_CANVAS_3 CS_CANVAS_ROTATE_LEFT
    #define KC_CANVAS_4 _______                         // ホールド状態
    #define KC_CANVAS_5 CS_CANVAS_ZOOM_OUT
    #define KC_CANVAS_6 CS_CANVAS_DISPLAY_OVERALL
    #define KC_CANVAS_7 CS_CANVAS_ROTATE_RIGHT
    #define KC_CANVAS_8 CS_MOVE_MODE
#endif

/* Other
 * ,-------------------------------------------.
 * | 取り消し |  コピー  | 切り取り | 上書保存 | タップ
 * |          |          |          |          | ホールド
 * |----------+----------+----------+----------|
 * | やり直し | ペースト |   消去   | holding  | タップ
 * |          |          |          |          | ホールド
 * `-------------------------------------------'
 */
#ifdef MODE_MAC
    #define KC_OTHER_1 CS_EDIT_UNDO_MAC
    #define KC_OTHER_2 CS_EDIT_COPY
    #define KC_OTHER_3 CS_EDIT_CUT
    #define KC_OTHER_4 CS_FILE_SAVE_MAC
    #define KC_OTHER_5 CS_EDIT_REDO_MAC
    #define KC_OTHER_6 CS_EDIT_PASTE
    #define KC_OTHER_7 CS_EDIT_DELETE
    #define KC_OTHER_8 _______          // ホールド状態
#else
    #define KC_OTHER_1 CS_EDIT_UNDO
    #define KC_OTHER_2 CS_EDIT_COPY
    #define KC_OTHER_3 CS_EDIT_CUT
    #define KC_OTHER_4 CS_FILE_SAVE
    #define KC_OTHER_5 CS_EDIT_REDO
    #define KC_OTHER_6 CS_EDIT_PASTE
    #define KC_OTHER_7 CS_EDIT_DELETE
    #define KC_OTHER_8 _______          // ホールド状態
#endif

//--+----1----+----2----+----3----+----4----+----5----+----6----+----7----+----8----+----9----+----0
// キーマップ定義
//--+----1----+----2----+----3----+----4----+----5----+----6----+----7----+----8----+----9----+----0
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        KC_BASE_1, KC_BASE_2, KC_BASE_3, L_CANVS,
        KC_BASE_5, KC_BASE_6, L_KEYBD,   L_OTHER
    ),

    [_CANVAS] = LAYOUT(
        KC_CANVAS_1, KC_CANVAS_2, KC_CANVAS_3, KC_CANVAS_4,
        KC_CANVAS_5, KC_CANVAS_6, KC_CANVAS_7, KC_CANVAS_8
    ),

    [_OTHER] = LAYOUT(
        KC_OTHER_1, KC_OTHER_2, KC_OTHER_3, KC_OTHER_4,
        KC_OTHER_5, KC_OTHER_6, KC_OTHER_7, KC_OTHER_8
    ),

    /* Keyboard
     * ,-------------------------------------------.
     * | LED照度+ |          | LED ONOF |          | タップ
     * |          |          |          |          | ホールド
     * |----------+----------+----------+----------|
     * | LED照度- |          | holding  |          | タップ
     * |          |          |          |          | ホールド
     * `-------------------------------------------'
     */
    [_KEYBOARD] = LAYOUT(
        RGB_VAI, XXXXXXX, RGB_TOG, XXXXXXX,
        RGB_VAD, XXXXXXX, _______, XXXXXXX
    ),
};

//--+----1----+----2----+----3----+----4----+----5----+----6----+----7----+----8----+----9----+----0
// 変数定義
//--+----1----+----2----+----3----+----4----+----5----+----6----+----7----+----8----+----9----+----0
// CANVASキー ホールド状態保持
static bool pressed_canvas   = false;
// OTHERキー ホールド状態保持
static bool pressed_other    = false;
// KEYBOARDキー ホールド状態保持
static bool pressed_keyboard = false;
// CANVASキー ホールド時間保持
static uint16_t pressed_time_canvas   = 0;
// OTHERキー ホールド時間保持
static uint16_t pressed_time_other    = 0;
// KEYBOARDキー ホールド時間保持
static uint16_t pressed_time_keyboard = 0;

//--+----1----+----2----+----3----+----4----+----5----+----6----+----7----+----8----+----9----+----0
// マトリクス初期化処理
//--+----1----+----2----+----3----+----4----+----5----+----6----+----7----+----8----+----9----+----0
void matrix_init_user(void) {
}

//--+----1----+----2----+----3----+----4----+----5----+----6----+----7----+----8----+----9----+----0
// マトリクススキャン時処理
//--+----1----+----2----+----3----+----4----+----5----+----6----+----7----+----8----+----9----+----0
void matrix_scan_user(void) {
}

//--+----1----+----2----+----3----+----4----+----5----+----6----+----7----+----8----+----9----+----0
// キーコード処理
//--+----1----+----2----+----3----+----4----+----5----+----6----+----7----+----8----+----9----+----0
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case L_CANVS:
            // タップで「KC_BASE_4」、ホールドで「Canvas」
            if (record->event.pressed) {
                pressed_canvas = true;
                pressed_time_canvas = record->event.time;
                layer_on(_CANVAS);
            } else {
                layer_off(_CANVAS);
                if (pressed_canvas && (TIMER_DIFF_16(record->event.time, pressed_time_canvas) < TAPPING_TERM)) {
                    SEND_STRING(KC_BASE_4);
                }
                pressed_canvas = false;
            }
            return false;
            break;
        case L_OTHER:
            // タップで「KC_BASE_8」、ホールドで「Other」
            if (record->event.pressed) {
                pressed_other = true;
                pressed_time_other = record->event.time;
                layer_on(_OTHER);
            } else {
                layer_off(_OTHER);
                if (pressed_other && (TIMER_DIFF_16(record->event.time, pressed_time_other) < TAPPING_TERM)) {
                    SEND_STRING(KC_BASE_8);
                }
                pressed_other = false;
            }
            return false;
            break;
        case L_KEYBD:
            // タップで「KC_BASE_7」、ホールドで「KEYBOARD」
            if (record->event.pressed) {
                pressed_keyboard = true;
                pressed_time_keyboard = record->event.time;
                layer_on(_KEYBOARD);
            } else {
                layer_off(_KEYBOARD);
                if (pressed_keyboard && (TIMER_DIFF_16(record->event.time, pressed_time_keyboard) < TAPPING_TERM)) {
                    SEND_STRING(KC_BASE_7);
                }
                pressed_keyboard = false;
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

//--+----1----+----2----+----3----+----4----+----5----+----6----+----7----+----8----+----9----+----0
// レイヤーステート設定時処理
//--+----1----+----2----+----3----+----4----+----5----+----6----+----7----+----8----+----9----+----0
uint32_t layer_state_set_user(uint32_t state) {
    #ifdef RGBLIGHT_ENABLE
        switch (biton32(state)) {
            case _BASE:
                u_rgblight_layer_base();
                rgblight_mode_noeeprom(1);
                break;
            case _CANVAS:
                u_rgblight_layer_canvas();
                rgblight_mode_noeeprom(1);
                break;
            case _OTHER:
                u_rgblight_layer_other();
                rgblight_mode_noeeprom(1);
                break;
            case _KEYBOARD:
                u_rgblight_layer_keyboard();
                rgblight_mode_noeeprom(1);
                break;
        }
    #endif
    return state;
} 

//--+----1----+----2----+----3----+----4----+----5----+----6----+----7----+----8----+----9----+----0
// LED設定時処理
//--+----1----+----2----+----3----+----4----+----5----+----6----+----7----+----8----+----9----+----0
void led_set_user(uint8_t usb_led) {
}
