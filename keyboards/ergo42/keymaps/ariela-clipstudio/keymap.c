#include QMK_KEYBOARD_H
#include "ariela.h"
#include "keymap_clipstudio.h"

extern keymap_config_t keymap_config;

//==+====1====+====2====+====3====+====4====+====5====+====6====+====7====+====8====+====9====+====0
// レイヤー定義
//==+====1====+====2====+====3====+====4====+====5====+====6====+====7====+====8====+====9====+====0
enum layer_number {
    _DEFAULT = 0,  // デフォルトレイヤー
};

//==+====1====+====2====+====3====+====4====+====5====+====6====+====7====+====8====+====9====+====0
// カスタムキーコード定義
//==+====1====+====2====+====3====+====4====+====5====+====6====+====7====+====8====+====9====+====0
enum custom_keycodes {
  QWERTY = SAFE_RANGE,  // デフォルトレイヤーをQWERTY配列に切り替え
  EUCALYN,              // デフォルトレイヤーをEucalyn配列に切り替え
  KEYPAD,               // デフォルトレイヤーを10キーパッドに切り替え
  LOWER,                // 押下時にLowerレイヤーに切り替え
  RAISE,                // 押下時にRaiseレイヤーに切り替え
  ADJUST,               // 押下時にAdjustレイヤーに切り替え
  EISU,                 // 英数入力に切り替え
  KANA,                 // かな入力に切り替え
  TGL_LOW,              // トグルでLowerレイヤーに切り替え
  TGL_RIS,              // トグルでRaiseレイヤーに切り替え
};

//==+====1====+====2====+====3====+====4====+====5====+====6====+====7====+====8====+====9====+====0
// ユーザキーコード定義
//==+====1====+====2====+====3====+====4====+====5====+====6====+====7====+====8====+====9====+====0

//==+====1====+====2====+====3====+====4====+====5====+====6====+====7====+====8====+====9====+====0
// キーコードエイリアス定義
//==+====1====+====2====+====3====+====4====+====5====+====6====+====7====+====8====+====9====+====0
#define KD_R1C1 CS_FILE_SAVE                // 上書き保存
#define KD_R1C2 CS_EDIT_FILL                // 塗りつぶし
#define KD_R1C3 CS_TOOL_BRUSH               // ブラシ
#define KD_R1C4 CS_TOOL_PEN                 // ペン
#define KD_R1C5 CS_TOOL_ERASER              // 消しゴム
#define KD_R1C6 CS_TOOL_DROPPER             // スポイト
#define KD_R1C7 CS_LAYER_NEW_LUSTER         // 新規ラスターレイヤー作成

#define KD_R2C1 KC_LCTRL                    // Ctrl
#define KD_R2C2 CS_CANVAS_ROTATE_LEFT       // 左回転
#define KD_R2C3 CS_CANVAS_ROTATE_RIGHT      // 右回転
#define KD_R2C4 LALT(LSFT(KC_S))            // マッピング必要 メニュー → 表示 → 回転・反転 → 左右反転 (Alt + Shift + S)
#define KD_R2C5 CS_EDIT_UNDO                // 取消
#define KD_R2C6 CS_EDIT_REDO                // やり直し
#define KD_R2C7 CS_LAYER_CLIPPING           // 下のレイヤーでクリッピング

#define KD_R3C1 KC_LSHIFT                   // Shift
#define KD_R3C2 KC_TAB                      // Tab
#define KD_R3C3 LSFT(KC_TAB)                // Shift + Tab
#define KD_R3C4 CS_BRUSH_SIZE_DOWN          // ブラシサイズ小
#define KD_R3C5 CS_BRUSH_SIZE_UP            // ブラシサイズ大
#define KD_R3C6 CS_TOOL_FIX_LINE            // 線修正
#define KD_R3C7 CS_TOGGLE_USE_LAYER_COLOR   // レイヤーカラー切替

#define KD_R4C1 CS_LAYER_EDITABLE_UPPER     // 上レイヤー編集
#define KD_R4C2 CS_LAYER_EDITABLE_UNDER     // 下レイヤー編集
#define KD_R4C3 LALT(LSFT(KC_P))            // マッピング必要 メニュー → 表示 → 印刷サイズ (Alt + Shift + P)
#define KD_R4C4 CS_CANVAS_DISPLAY_100P      // 100%表示
#define KD_R4C5 CS_CANVAS_ZOOM_OUT          // 縮小
#define KD_R4C6 CS_CANVAS_ZOOM_IN           // 拡大
#define KD_R4C7 CS_MOVE_MODE                // 移動

//==+====1====+====2====+====3====+====4====+====5====+====6====+====7====+====8====+====9====+====0
// キーマップ定義
//==+====1====+====2====+====3====+====4====+====5====+====6====+====7====+====8====+====9====+====0
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Default
   * |  小指   |  小指   |  薬指   |  中指   | 人差指  | 人差指  | 人差指  |
   * ,---------------------------------------------------------------------.
   * | KD_R1C1 | KD_R1C2 | KD_R1C3 | KD_R1C4 | KD_R1C5 | KD_R1C6 | KD_R1C7 |
   * |上書保存 |塗り潰し | ブラシ  |  ペン   |消しゴム |スポイト |新レイヤ-|
   * |---------+---------+---------+---------+---------+---------+---------|
   * | KD_R2C1 | KD_R2C2 | KD_R2C3 | KD_R2C4 | KD_R2C5 | KD_R2C6 | KD_R2C7 |
   * |  Ctrl   | 左回転  | 右回転  |左右反転 |  取消   |やり直し |クリップ |
   * |---------+---------+---------+---------+---------+---------+---------|
   * | KD_R3C1 | KD_R3C2 | KD_R3C3 | KD_R3C4 | KD_R3C5 | KD_R3C6 | KD_R3C7 |
   * |  Shift  |   Tab   |Shift+Tab|ブラシ小 |ブラシ大 | 線修正  | L色切替 |
   * |---------+---------+---------+---------+---------+---------+---------|
   * | KD_R4C1 | KD_R4C2 | KD_R4C3 | KD_R4C4 | KD_R4C5 | KD_R4C6 | KD_R4C7 |
   * | 上L編集 | 下L編集 | 印刷大  |  原寸   |  縮小   |  拡大   |  移動   |
   * `---------------------------------------------------------------------'
   */
  [_DEFAULT] = LAYOUT_wrapper( \
    KD_R1C1 , KD_R1C2 , KD_R1C3 , KD_R1C4 , KD_R1C5 , KD_R1C6 , KD_R1C7 ,           _______ , _______________________________________________ , _______ , \
    KD_R2C1 , KD_R2C2 , KD_R2C3 , KD_R2C4 , KD_R2C5 , KD_R2C6 , KD_R2C7 ,           _______ , _______________________________________________ , _______ , \
    KD_R3C1 , KD_R3C2 , KD_R3C3 , KD_R3C4 , KD_R3C5 , KD_R3C6 , KD_R3C7 ,           _______ , _______________________________________________ , _______ , \
    KD_R4C1 , KD_R4C2 , KD_R4C3 , KD_R4C4 , KD_R4C5 , KD_R4C6 , KD_R4C7 ,           _______ , _______________________________________________ , _______   \
//  _______ , _______ , _______ , _______ , _______ , _______ , _______ ,           _______ , _______ , _______ , _______ , _______ , _______ , _______
  ),

};
