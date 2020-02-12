#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

//==+====1====+====2====+====3====+====4====+====5====+====6====+====7====+====8====+====9====+====0
// レイヤー定義
//==+====1====+====2====+====3====+====4====+====5====+====6====+====7====+====8====+====9====+====0
enum layer_number {
    _QWERTY = 0,  // デフォルトレイヤー(QWERTY配列)
    _EUCALYN,     // デフォルトレイヤー(Eucalyn配列)
    _KEYPAD,      // デフォルトレイヤー(10キーパッド)
    _LOWER,       // Lower
    _RAISE,       // Raise
    _FUNC1,       // Function 1
    _ADJUST,      // Adjust
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
#define FN1_ESC LT(_FUNC1, KC_ESC)  // タップでESC・ホールドでFunction1レイヤーON

//==+====1====+====2====+====3====+====4====+====5====+====6====+====7====+====8====+====9====+====0
// キーコードエイリアス定義
//==+====1====+====2====+====3====+====4====+====5====+====6====+====7====+====8====+====9====+====0
#define _______ KC_TRNS // 下位レイヤーのキーコードを使用
#define XXXXXXX KC_NO   // キーを無効にする

//==+====1====+====2====+====3====+====4====+====5====+====6====+====7====+====8====+====9====+====0
// キーマップ定義
//==+====1====+====2====+====3====+====4====+====5====+====6====+====7====+====8====+====9====+====0
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,------------------------------------------------.   ,------------------------------------------------.
   * | Tab/ |  Q   |  W   |  E   |  R   |  T   |  [   |   |   ]  |   Y  |   U  |   I  |   O  |   P  | Bksp |
   * |------+------+------+------+------+------+------|   |-------------+------+------+------+------+------|
   * | Ctrl |  A   |  S   |  D   |  F   |  G   |  -   |   |   =  |   H  |   J  |   K  |   L  |   ;  |   '  |
   * |------+------+------+------+------+------+------|   |------|------+------+------+------+------+------|
   * |Shift |  Z   |  X   |  C   |  V   |  B   | Bksp |   | Shift|   N  |   M  |   ,  |   .  |   /  | ENTER|
   * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
   * |Adjust| ESC  | Mac  | ALT  | GUI  |Lower |Space |   | Space| Raise| LEFT | DOWN |  UP  | RIGHT|Adjust|
   * |      |Func1 |      |      |      |      |      |   |      |      |      |      |      |      |      |
   * `------------------------------------------------'   `------------------------------------------------'
   */
  [_QWERTY] = LAYOUT( \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC,          KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_MINS,          KC_EQL,  KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_BSPC,          KC_RSFT, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT, \
    ADJUST,  FN1_ESC, AG_NORM, KC_LALT, KC_LGUI, LOWER,   KC_SPC,           KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, ADJUST \
//  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  
  ),

  /* Eucalyn
   * ,------------------------------------------------.   ,------------------------------------------------.
   * | Tab  |  Q   |  W   |  ,   |  .   |  ;   |  [   |   |   ]  |   M  |   R  |   D  |   Y  |   P  | Bksp |
   * |------+------+------+------+------+------+------|   |-------------+------+------+------+------+------|
   * | Ctrl |  A   |  O   |  E   |  I   |  U   |  -   |   |   =  |   G  |   T  |   K  |   S  |   N  |   '  |
   * |------+------+------+------+------+------+------|   |------|------+------+------+------+------+------|
   * |Shift |  Z   |  X   |  C   |  V   |  F   | Bksp |   | Shift|   B  |   H  |   J  |   L  |   /  | ENTER|
   * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
   * |Adjust| ESC  | Mac  | ALT  | GUI  |Lower |Space |   | Space| Raise| LEFT | DOWN |  UP  | RIGHT|Adjust|
   * |      |Func1 |      |      |      |      |      |   |      |      |      |      |      |      |      |
   * `------------------------------------------------'   `------------------------------------------------'
   */
  [_EUCALYN] = LAYOUT( \
    KC_TAB,  KC_Q,    KC_W,    KC_COMM, KC_DOT,  KC_SCLN, KC_LBRC,          KC_RBRC, KC_M,    KC_R,    KC_D,    KC_Y,    KC_P,    KC_BSPC, \
    KC_LCTL, KC_A,    KC_O,    KC_E,    KC_I,    KC_U,    KC_MINS,          KC_EQL,  KC_G,    KC_T,    KC_K,    KC_S,    KC_N,    KC_QUOT, \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_F,    KC_BSPC,          KC_RSFT, KC_B,    KC_H,    KC_J,    KC_L,    KC_SLSH, KC_ENT, \
    ADJUST,  FN1_ESC, AG_NORM, KC_LALT, KC_LGUI, LOWER,   KC_SPC,           KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, ADJUST \
//  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  
  ),

  /* Keypad
   * ,------------------------------------------------.   ,------------------------------------------------.
   * |      |  7   |  8   |  9   |  /   |      |      |   |      |      |   7  |   8  |   9  |   /  |      |
   * |------+------+------+------+------+------+------|   |-------------+------+------+------+------+------|
   * |      |  4   |  5   |  6   |  *   |      |      |   |      |      |   4  |   5  |   6  |   *  |      |
   * |------+------+------+------+------+------+------|   |------|------+------+------+------+------+------|
   * |      |  1   |  2   |  3   |  -   |  =   |      |   |      |      |   1  |   2  |   3  |   -  |   =  |
   * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
   * |Adjust|  0   |  0   |  .   |  +   |Lower |      |   |      | Raise|   0  |   0  |   .  |   +  |Adjust|
   * `------------------------------------------------'   `------------------------------------------------'
   */
  [_KEYPAD] = LAYOUT( \
    XXXXXXX, KC_P7,   KC_P8,   KC_P9,   KC_PSLS, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, KC_P7,   KC_P8,   KC_P9,   KC_PSLS, XXXXXXX, \
    XXXXXXX, KC_P4,   KC_P5,   KC_P6,   KC_PAST, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, KC_P4,   KC_P5,   KC_P6,   KC_PAST, XXXXXXX, \
    XXXXXXX, KC_P1,   KC_P2,   KC_P3,   KC_PMNS, KC_PEQL, XXXXXXX,          XXXXXXX, XXXXXXX, KC_P1,   KC_P2,   KC_P3,   KC_PMNS, KC_PEQL, \
    ADJUST,  KC_P0,   KC_P0,   KC_PDOT, KC_PPLS, LOWER,   XXXXXXX,          XXXXXXX, RAISE,   KC_P0,   KC_P0,   KC_PDOT, KC_PPLS, ADJUST \
//  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  
  ),

  /* Lower
   * ,------------------------------------------------.   ,------------------------------------------------.
   * |  `   |  1   |  2   |  3   |  4   |  5   |      |   |      |   6  |   7  |   8  |   9  |   0  |   \  |
   * |------+------+------+------+------+------+------|   |-------------+------+------+------+------+------|
   * |      |  6   |  7   |  8   |  9   |  0   |      |   |      |      |   -  |   =  |   [  |   ]  |      |
   * |------+------+------+------+------+------+------|   |------|------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |   |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
   * |Adjust|      | Win  |      |      |Lower |      |   |      | Raise| HOME | PgDn | PgUp |  END |Adjust|
   * `------------------------------------------------'   `------------------------------------------------'
   */
  [_LOWER] = LAYOUT( \
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______,          _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS, \
    _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,          _______, _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, _______, \
    _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______, \
    XXXXXXX, _______, AG_SWAP, _______, _______, _______, _______,          _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  XXXXXXX \
//  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  
  ),

  /* Raise
   * ,------------------------------------------------.   ,------------------------------------------------.
   * |  ~   |  !   |  @   |  #   |  $   |  %   |  {   |   |   }  |   ^  |   &  |   *  |   (  |   )  |   |  |
   * |------+------+------+------+------+------+------|   |-------------+------+------+------+------+------|
   * |      |  ^   |  &   |  *   |  (   |  )   |  _   |   |   +  |      |   _  |   +  |   {  |   }  |      |
   * |------+------+------+------+------+------+------|   |------|------+------+------+------+------+------|
   * |      |      |  -   |  =   |  [   |  ]   |      |   |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
   * |Adjust|      |      |      |      |Lower |      |   |      | Raise|      |      |      |      |Adjust|
   * `------------------------------------------------'   `------------------------------------------------'
   */
  [_RAISE] = LAYOUT( \
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_LCBR,          KC_RCBR, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE, \
    _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS,          KC_PLUS, _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, _______, \
    _______, _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, _______,          _______, _______, _______, _______, _______, _______, _______, \
    XXXXXXX, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, XXXXXXX \
//  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  
  ),

  /* Function 1
   * ,------------------------------------------------.   ,------------------------------------------------.
   * |      |      |      |      |      |      |      |   |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------|   |-------------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |   |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------|   |------|------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |   |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
   * |Adjust|      |      |      |      |Lower |Reset |   |      | Raise|      |      |      |      |Adjust|
   * `------------------------------------------------'   `------------------------------------------------'
   */
  [_FUNC1] = LAYOUT( \
    _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______, \
    XXXXXXX, _______, _______, _______, _______, TGL_LOW, RESET,            _______, TGL_RIS, _______, _______, _______, _______, XXXXXXX \
//  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  
  ),

  /* Adjust
   * ,------------------------------------------------.   ,------------------------------------------------.
   * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |      |   |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
   * |------+------+------+------+------+------+------|   |-------------+------+------+------+------+------|
   * |  F7  |  F8  |  F9  | F10  | F11  | F12  |      |   |      | LEFT | DOWN |  UP  | RIGHT|      |      |
   * |------+------+------+------+------+------+------|   |------|------+------+------+------+------+------|
   * |      |      |      |      |      |      | DEL  |   |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
   * |Adjust|      |      |      |      |Lower | EISU |   | KANA | Raise|QWERTY|EUCALN|      |KEYPAD|Adjust|
   * `------------------------------------------------'   `------------------------------------------------'
   */
  [_ADJUST] = LAYOUT( \
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   _______,          _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, \
    KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,          _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______, \
    _______, _______, _______, _______, _______, _______, KC_DEL,           _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, XXXXXXX, EISU,             KANA,    XXXXXXX, QWERTY,  EUCALYN, _______, KEYPAD,  _______ \
//  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  
  ),

};

//==+====1====+====2====+====3====+====4====+====5====+====6====+====7====+====8====+====9====+====0
// 変数定義
//==+====1====+====2====+====3====+====4====+====5====+====6====+====7====+====8====+====9====+====0
static bool u_pressed_lower = false;
static bool u_pressed_raise = false;
static uint16_t u_pressed_lower_time = 0;
static uint16_t u_pressed_raise_time = 0;

//==+====1====+====2====+====3====+====4====+====5====+====6====+====7====+====8====+====9====+====0
// 関数定義
//==+====1====+====2====+====3====+====4====+====5====+====6====+====7====+====8====+====9====+====0
/**
 * 押下時にデフォルトレイヤーを変更する処理(EEPROMへの保存も同時に行う)
 */
bool pressed_default_layer_change(uint16_t layer, keyrecord_t *record) {
  if (record->event.pressed) {
    eeconfig_update_default_layer(1UL<<layer);
    default_layer_set(1UL<<layer);
  }
  return false;
}

/**
 * 押下時にレイヤーを変更する処理
 */
bool pressed_layer_change(uint16_t layer, keyrecord_t *record) {
  if (record->event.pressed) {
    layer_on(layer);
  } else {
    layer_off(layer);
  }
  update_tri_layer(_LOWER, _RAISE, _ADJUST);
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
 * 押下時にレイヤーをトグルで変更する処理
 */
bool pressed_layer_toggle(uint16_t layer, keyrecord_t *record) {
  static uint8_t l_r_layer;
  if (record->event.pressed) {
    l_r_layer = layer;
    if IS_LAYER_ON(l_r_layer){
      layer_off(l_r_layer);
    } else {
      layer_on(l_r_layer);
    }
  }
  return false;
}

/**
 * 押下時にIME入力変換を切り替える処理
 */
bool pressed_lang_swap(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    if(keymap_config.swap_lalt_lgui==false){
      register_code(keycode);
    }else{
      SEND_STRING(SS_LALT("`"));
    }
  } else {
    unregister_code(keycode);
  }
  return false;
}

//==+====1====+====2====+====3====+====4====+====5====+====6====+====7====+====8====+====9====+====0
// QMKキーマップ用制御関数定義
//==+====1====+====2====+====3====+====4====+====5====+====6====+====7====+====8====+====9====+====0
/**
 * キーマトリックススキャン毎に実行される関数
 */
void matrix_scan_user(void) {
  static uint8_t old_layer = 0;
  uint8_t layer = biton32(layer_state);
  if(old_layer != layer){
    // レイヤーに変化があった場合のみ処理を行う
  }
  old_layer = layer;
}

/**
 * キーコードに対する処理を行う
 */
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      return pressed_default_layer_change(_QWERTY, record);
      break;
    case EUCALYN:
      return pressed_default_layer_change(_EUCALYN, record);
      break;
    case KEYPAD:
      return pressed_default_layer_change(_KEYPAD, record);
      break;
    case LOWER:
      //return pressed_layer_change(_LOWER, record);
      return change_layer_onpress_with_tap(_LOWER, KC_LANG2, record, &u_pressed_lower, &u_pressed_lower_time, true);
      break;
    case RAISE:
      //return pressed_layer_change(_RAISE, record);
      return change_layer_onpress_with_tap(_RAISE, KC_LANG1, record, &u_pressed_raise, &u_pressed_raise_time, true);
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
    case EISU:
      return pressed_lang_swap(KC_LANG2, record);
      break;
    case KANA:
      return pressed_lang_swap(KC_LANG1, record);
      break;
    case TGL_LOW:
      return pressed_layer_toggle(_LOWER, record);
      break;
    case TGL_RIS:
      return pressed_layer_toggle(_RAISE, record);
      break;
  }
  
  // タップ対応キーと他のキーが同時押しされた場合はタップ機能を停止させる
  u_pressed_lower = false;
  u_pressed_raise = false;

  // キー入力パススルー
  return true;
}
