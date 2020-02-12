#include QMK_KEYBOARD_H
#include "ariela.h"
#include "bootloader.h"

#ifdef PROTOCOL_LUFA
    #include "lufa.h"
    #include "split_util.h"
#endif
#ifdef SSD1306OLED
    #include "ssd1306.h"
#endif

// JISキーコード
#include "keymap_jp.h"

extern keymap_config_t keymap_config;

#ifdef RGBLIGHT_ENABLE
    extern rgblight_config_t rgblight_config;
    rgblight_config_t RGB_current_config;
#endif

extern uint8_t is_master;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_number {
    _LAYER1 = 0,
    _LAYER2,
    _LAYER3,
    _ADJUST,
};

enum custom_keycodes {
    LAYER = SAFE_RANGE,
    LAYER_F,
    ADJUST,
    RGB_RST,
};

#define KC_AF1  LALT(KC_F1)       // Alt + F1
#define KC_AF2  LALT(KC_F2)       // Alt + F2
#define KC_AF3  LALT(KC_F3)       // Alt + F3
#define KC_AF4  LALT(KC_F4)       // Alt + F4
#define KC_AF5  LALT(KC_F5)       // Alt + F5
#define KC_AF6  LALT(KC_F6)       // Alt + F6
#define KC_AF7  LALT(KC_F7)       // Alt + F7
#define KC_AF8  LALT(KC_F8)       // Alt + F8
#define KC_AF9  LALT(KC_F9)       // Alt + F9
#define KC_AF10 LALT(KC_F10)      // Alt + F10
#define KC_AF11 LALT(KC_F11)      // Alt + F11
#define KC_AF12 LALT(KC_F12)      // Alt + F12
#define KC_CF1  LCTL(KC_F1)       // Ctrl + F1
#define KC_CF2  LCTL(KC_F2)       // Ctrl + F2
#define KC_CF3  LCTL(KC_F3)       // Ctrl + F3
#define KC_CF4  LCTL(KC_F4)       // Ctrl + F4
#define KC_CF5  LCTL(KC_F5)       // Ctrl + F5
#define KC_CF6  LCTL(KC_F6)       // Ctrl + F6
#define KC_CF7  LCTL(KC_F7)       // Ctrl + F7
#define KC_CF8  LCTL(KC_F8)       // Ctrl + F8
#define KC_CF9  LCTL(KC_F9)       // Ctrl + F9
#define KC_CF10 LCTL(KC_F10)      // Ctrl + F10
#define KC_CF11 LCTL(KC_F11)      // Ctrl + F11
#define KC_CF12 LCTL(KC_F12)      // Ctrl + F12
#define KC_SF1  LSFT(KC_F1)       // Shift + F1
#define KC_SF2  LSFT(KC_F2)       // Shift + F2
#define KC_SF3  LSFT(KC_F3)       // Shift + F3
#define KC_SF4  LSFT(KC_F4)       // Shift + F4
#define KC_SF5  LSFT(KC_F5)       // Shift + F5
#define KC_SF6  LSFT(KC_F6)       // Shift + F6
#define KC_SF7  LSFT(KC_F7)       // Shift + F7
#define KC_SF8  LSFT(KC_F8)       // Shift + F8
#define KC_SF9  LSFT(KC_F9)       // Shift + F9
#define KC_SF10 LSFT(KC_F10)      // Shift + F10
#define KC_SF11 LSFT(KC_F11)      // Shift + F11
#define KC_SF12 LSFT(KC_F12)      // Shift + F12
#define KC_A1   LALT(KC_1)        // Alt + 1
#define KC_A2   LALT(KC_2)        // Alt + 2
#define KC_A3   LALT(KC_3)        // Alt + 3
#define KC_A4   LALT(KC_4)        // Alt + 4
#define KC_A5   LALT(KC_5)        // Alt + 5
#define KC_A6   LALT(KC_6)        // Alt + 6
#define KC_A7   LALT(KC_7)        // Alt + 7
#define KC_A8   LALT(KC_8)        // Alt + 8
#define KC_A9   LALT(KC_9)        // Alt + 9
#define KC_A0   LALT(KC_0)        // Alt + 0
#define KC_AMNS LALT(JP_MINS)     // Alt + -
#define KC_ACRC LALT(JP_CIRC)     // Alt + ^ 
#define KC_C1   LCTL(KC_1)        // Ctrl + 1
#define KC_C2   LCTL(KC_2)        // Ctrl + 2
#define KC_C3   LCTL(KC_3)        // c + 3
#define KC_C4   LCTL(KC_4)        // Ctrl + 4
#define KC_C5   LCTL(KC_5)        // Ctrl + 5
#define KC_C6   LCTL(KC_6)        // Ctrl + 6
#define KC_C7   LCTL(KC_7)        // Ctrl + 7
#define KC_C8   LCTL(KC_8)        // Ctrl + 8
#define KC_C9   LCTL(KC_9)        // Ctrl + 9
#define KC_C0   LCTL(KC_0)        // Ctrl + 0
#define KC_CMNS LCTL(JP_MINS)     // Ctrl + -
#define KC_CCRC LCTL(JP_CIRC)     // Ctrl + ^ 
#define C_SY    LALT(KC_S)        // 一時的にSayチャットに変更する
#define C_SYF   LCA(KC_S)         // Sayチャットに変更する (Alt + Ctrl +  S)
#define C_SH    LALT(KC_H)        // 一時的にShoutチャットに変更する
#define C_SHF   LCA(KC_H)         // Shoutチャットに変更する (Alt + Ctrl +  H)
#define C_PT    LALT(KC_P)        // 一時的にPTチャットに変更する
#define C_PTF   LCA(KC_P)         // PTチャットに変更する (Alt + Ctrl +  P)
#define C_YL    LALT(KC_Y)        // 一時的にYellチャットに変更する
#define C_YLF   LCA(KC_Y)         // Yellチャットに変更する (Alt + Ctrl +  Y)
#define C_TL    LALT(KC_R)        // 一時的にTellチャットに変更する
#define C_TLF   LCA(KC_R)         // Tellチャットに変更する (Alt + Ctrl +  R)
#define C_FC    LALT(KC_F)        // 一時的にFCチャットに変更する
#define C_FCF   LCA(KC_F)         // FCチャットに変更する (Alt + Ctrl +  F)
#define C_LSN   LALT(KC_L)        // 一時的にLSチャット(順送)に変更する
#define C_LSF   LCA(KC_L)         // LSチャットに変更する (Alt + Ctrl +  L)
#define C_CLSN  LALT(KC_X)        // 一時的にCWLSチャット(順送)に変更する
#define C_CLSF  LCA(KC_X)         // CWLSチャットに変更する (Alt + Ctrl +  X)
#define C_LSR   LALT(LSFT(KC_L))  // 一時的にLSチャット(逆送)に変更する
#define C_LS1   LCA(KC_1)         // 一時的にLSチャット1に変更する (Alt + Ctrl +  1)
#define C_LS2   LCA(KC_2)         // 一時的にLSチャット2に変更する (Alt + Ctrl +  2)
#define C_LS3   LCA(KC_3)         // 一時的にLSチャット3に変更する (Alt + Ctrl +  3)
#define C_LS4   LCA(KC_4)         // 一時的にLSチャット4に変更する (Alt + Ctrl +  4)
#define C_LS5   LCA(KC_5)         // 一時的にLSチャット5に変更する (Alt + Ctrl +  5)
#define C_LS6   LCA(KC_6)         // 一時的にLSチャット6に変更する (Alt + Ctrl +  6)
#define C_LS7   LCA(KC_7)         // 一時的にLSチャット7に変更する (Alt + Ctrl +  7)
#define C_LS8   LCA(KC_8)         // 一時的にLSチャット8に変更する (Alt + Ctrl +  8)
#define C_LS1F  MEH(KC_1)         // LSチャット1に変更する (Alt + Ctrl + Shift +  1)
#define C_LS2F  MEH(KC_2)         // LSチャット2に変更する (Alt + Ctrl + Shift +  2)
#define C_LS3F  MEH(KC_3)         // LSチャット3に変更する (Alt + Ctrl + Shift +  3)
#define C_LS4F  MEH(KC_4)         // LSチャット4に変更する (Alt + Ctrl + Shift +  4)
#define C_LS5F  MEH(KC_5)         // LSチャット5に変更する (Alt + Ctrl + Shift +  5)
#define C_LS6F  MEH(KC_6)         // LSチャット6に変更する (Alt + Ctrl + Shift +  6)
#define C_LS7F  MEH(KC_7)         // LSチャット7に変更する (Alt + Ctrl + Shift +  7)
#define C_LS8F  MEH(KC_8)         // LSチャット8に変更する (Alt + Ctrl + Shift +  8)
#define C_CWLS1 LSFT(LCTL(KC_1))  // 一時的にCWLSチャット1に変更する (Ctrl + Shift +  1)
#define C_CWLS2 LSFT(LCTL(KC_2))  // 一時的にCWLSチャット2に変更する (Ctrl + Shift +  2)
#define C_CWLS3 LSFT(LCTL(KC_3))  // 一時的にCWLSチャット3に変更する (Ctrl + Shift +  3)
#define C_CWLS4 LSFT(LCTL(KC_4))  // 一時的にCWLSチャット4に変更する (Ctrl + Shift +  4)
#define C_CWLS5 LSFT(LCTL(KC_5))  // 一時的にCWLSチャット5に変更する (Ctrl + Shift +  5)
#define C_CWLS6 LSFT(LCTL(KC_6))  // 一時的にCWLSチャット6に変更する (Ctrl + Shift +  6)
#define C_CWLS7 LSFT(LCTL(KC_7))  // 一時的にCWLSチャット7に変更する (Ctrl + Shift +  7)
#define C_CWLS8 LSFT(LCTL(KC_8))  // 一時的にCWLSチャット8に変更する (Ctrl + Shift +  8)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* LAYER
     *,-----------------------------------------------------------.
     *|         |         |         |         |         |         |
     *|---------+---------+---------+---------+---------+---------|
     *|         |         |         |         |         |         |
     *|---------+---------+---------+---------+---------+---------|
     *|         |         |         |         |         |         |
     *|---------+---------+---------+---------+---------+---------+---------.
     *|         |         |         |         |         |         |         |
     *|---------+---------+---------+---------+---------+---------+---------|
     *|         |         |         |         |         |         |         |
     *`---------------------------------------------------------------------.
     */
    /*
    [_XXXXXX] = LAYOUT_wrapper( \
        _______ , _______ , _______ , _______ , _______ , _______ ,                     _________________________________________________________ , \
        _______ , _______ , _______ , _______ , _______ , _______ ,                     _________________________________________________________ , \
        _______ , _______ , _______ , _______ , _______ , _______ ,                     _________________________________________________________ , \
        _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _________________________________________________________ , \
        _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _________________________________________________________   \
    ),
    */

    /* Layer1
     *,-----------------------------------------------------------.
     *|    1    |    2    |    3    |    4    |    5    |    6    |             // ホットバー1
     *|---------+---------+---------+---------+---------+---------|
     *|    7    |    8    |    9    |    0    |    -    |    ^    |
     *|---------+---------+---------+---------+---------+---------|
     *|  Ctl+1  |  Ctl+2  |  Ctl+3  |  Ctl+4  |  Ctl+5  |  Ctl+6  |             // ホットバー2
     *|---------+---------+---------+---------+---------+---------+---------.
     *|  Ctl+7  |  Ctl+8  |  Ctl+9  |  Ctl+0  |  Ctl+-  |  Ctl+^  | ADJUST  |
     *|---------+---------+---------+---------+---------+---------+---------|
     *|  Alt+1  |  Alt+2  |  Alt+3  |  Alt+4  |  Alt+5  |  Alt+6  |  LAYER  |   // 半ホットバー
     *`---------------------------------------------------------------------.
     */
    [_LAYER1] = LAYOUT_wrapper( \
        KC_1    , KC_2    , KC_3    , KC_4    , KC_5    , KC_6    ,                     _________________________________________________________ , \
        KC_7    , KC_8    , KC_9    , KC_0    , JP_MINS , JP_CIRC ,                     _________________________________________________________ , \
        KC_C1   , KC_C2   , KC_C3   , KC_C4   , KC_C5   , KC_C6   ,                     _________________________________________________________ , \
        KC_C7   , KC_C8   , KC_C9   , KC_C0   , KC_CMNS , KC_CCRC , ADJUST  , _______ , _________________________________________________________ , \
        KC_A1   , KC_A2   , KC_A3   , KC_A4   , KC_A5   , KC_A6   , LAYER   , _______ , _________________________________________________________   \
    ),

    /* Layer2
     *,-----------------------------------------------------------.
     *| Ctl+F1  | Ctl+F2  | Ctl+F3  | Ctl+F4  | Ctl+F5  | Ctl+F6  |             // ホットバー3
     *|---------+---------+---------+---------+---------+---------|
     *| Ctl+F7  | Ctl+F8  | Ctl+F9  | Ctl+F10 | Ctl+F11 | Ctl+F12 |
     *|---------+---------+---------+---------+---------+---------|
     *| Alt+F1  | Alt+F2  | Alt+F3  | Alt+F4  | Alt+F5  | Alt+F6  |             // ホットバー4
     *|---------+---------+---------+---------+---------+---------+---------.
     *| Alt+F7  | Alt+F8  | Alt+F9  | Alt+F10 | Alt+F11 | Alt+F12 | ADJUST  |
     *|---------+---------+---------+---------+---------+---------+---------|
     *|  Alt+7  |  Alt+8  |  Alt+9  |  Alt+0  |  Alt+-  |  Alt+^  |  LAYER  |   // 半ホットバー
     *`---------------------------------------------------------------------.
     */
    [_LAYER2] = LAYOUT_wrapper( \
        KC_CF1  , KC_CF2  , KC_CF3  , KC_CF4  , KC_CF5  , KC_CF6  ,                     _________________________________________________________ , \
        KC_CF7  , KC_CF8  , KC_CF9  , KC_CF10 , KC_CF11 , KC_CF12 ,                     _________________________________________________________ , \
        KC_AF1  , KC_AF2  , KC_AF3  , KC_AF4  , KC_AF5  , KC_AF6  ,                     _________________________________________________________ , \
        KC_AF7  , KC_AF8  , KC_AF9  , KC_AF10 , KC_AF11 , KC_AF12 , _______ , _______ , _________________________________________________________ , \
        KC_A7   , KC_A8   , KC_A9   , KC_A0   , KC_AMNS , KC_ACRC , _______ , _______ , _________________________________________________________   \
    ),

    /* Layer3
     *,-----------------------------------------------------------.
     *|  RESET  |         |         |         |         |         |
     *|---------+---------+---------+---------+---------+---------|
     *|         |         |         |         |         |         |
     *|---------+---------+---------+---------+---------+---------|
     *|         |         |         |         |         |         |
     *|---------+---------+---------+---------+---------+---------+---------.
     *| RGB_TOG | RGB_MOD | RGB_HUI | RGB_SAI | RGB_VAI |         | ADJUST  |
     *|---------+---------+---------+---------+---------+---------+---------|
     *| RGB_RST |RGB_RMOD | RGB_HUD | RGB_SAD | RGB_VAD |         |  LAYER  |
     *`---------------------------------------------------------------------.
     */
    [_LAYER3] = LAYOUT_wrapper( \
        RESET   , _______ , _______ , _______ , _______ , _______ ,                     _________________________________________________________ , \
        _______ , _______ , _______ , _______ , _______ , _______ ,                     _________________________________________________________ , \
        _______ , _______ , _______ , _______ , _______ , _______ ,                     _________________________________________________________ , \
        RGB_TOG , RGB_MOD , RGB_HUI , RGB_SAI , RGB_VAI , _______ , _______ , _______ , _________________________________________________________ , \
        RGB_RST , RGB_RMOD, RGB_HUD , RGB_SAD , RGB_VAD , _______ , _______ , _______ , _________________________________________________________   \
    ),

    /* Adjust
     *,-----------------------------------------------------------.
     *|   say   |  shout  |  party  |  yell   |  CWLS   |   FC    |             // チャット一時変更
     *|---------+---------+---------+---------+---------+---------|
     *|   say   |  shout  |  party  |  yell   |  CWLS   |   FC    |             // チャット変更
     *|---------+---------+---------+---------+---------+---------|
     *|   LS1   |   LS2   |   LS3   |   LS4   |   LS5   |   LS6   |             // LS一時変更
     *|---------+---------+---------+---------+---------+---------+---------.
     *|   LS1   |   LS2   |   LS3   |   LS4   |   LS5   |   LS6   | ADJUST  |   // LS変更
     *|---------+---------+---------+---------+---------+---------+---------|
     *|  CWLS1  |  CWLS2  |  CWLS3  |  CWLS4  |  CWLS5  |  CWLS6  | LAYER_F |   // CWLS変更
     *`---------------------------------------------------------------------.
     */
    [_ADJUST] = LAYOUT_wrapper( \
        C_SY    , C_SH    , C_PT    , C_YL    , C_CLSN  , C_FC    ,                     _________________________________________________________ , \
        C_SYF   , C_SHF   , C_PTF   , C_YLF   , C_CLSF  , C_FCF   ,                     _________________________________________________________ , \
        C_LS1   , C_LS2   , C_LS3   , C_LS4   , C_LS5   , C_LS6   ,                     _________________________________________________________ , \
        C_LS1F  , C_LS2F  , C_LS3F  , C_LS4F  , C_LS5F  , C_LS6F  , _______ , _______ , _________________________________________________________ , \
        C_CWLS1 , C_CWLS2 , C_CWLS3 , C_CWLS4 , C_CWLS5 , C_CWLS6 , LAYER_F , _______ , _________________________________________________________   \
    ),
};

//--+----1----+----2----+----3----+----4----+----5----+----6----+----7----+----8----+----9----+----0
// 変数定義
//--+----1----+----2----+----3----+----4----+----5----+----6----+----7----+----8----+----9----+----0
static bool u_pressed_adjust = false;
static uint16_t u_pressed_adjust_time = 0;

//--+----1----+----2----+----3----+----4----+----5----+----6----+----7----+----8----+----9----+----0
// 関数定義
//--+----1----+----2----+----3----+----4----+----5----+----6----+----7----+----8----+----9----+----0

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

/**
 * LAYER1の時のLED設定
 */
void led_layer1(void) {
    #ifdef RGBLIGHT_ENABLE
        rgblight_mode_noeeprom(RGB_current_config.mode);
        rgblight_sethsv_noeeprom(RGB_current_config.hue, RGB_current_config.sat, RGB_current_config.val);
    #endif
}

/**
 * LAYER2の時のLED設定
 */
void led_layer2(void) {
    #ifdef RGBLIGHT_ENABLE
        rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
        rgblight_sethsv_noeeprom_springgreen();
    #endif
}

/**
 * LAYER3の時のLED設定
 */
void led_layer3(void) {
    #ifdef RGBLIGHT_ENABLE
        rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING + 3);
        rgblight_sethsv_noeeprom_red();
    #endif
}

/**
 * ADJUSTの時のLED設定
 */
void led_layer_adjust(void) {
    #ifdef RGBLIGHT_ENABLE
        rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
        rgblight_sethsv_noeeprom_magenta();
    #endif
}

/**
 * マトリクス初期化時ユーザ定義
 */
void matrix_init_user(void) {
    //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
    #ifdef SSD1306OLED
        iota_gfx_init(!has_usb());   // turns on the display
    #endif
    persistent_default_layer_set(1UL<<_LAYER1);
    #ifdef RGBLIGHT_ENABLE
        rgblight_init();      
        RGB_current_config = rgblight_config;
        led_layer1();
    #endif
}

/**
 * キー処理実行時ユーザ定義
 */
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LAYER:
            if (record->event.pressed) {
                if (default_layer_state & (1UL<<_LAYER1)) {
                    dprint("PROCESS RECORD USER: LAYER2\n");
                    persistent_default_layer_set(1UL<<_LAYER2);
                    led_layer2();
                } else {
                    dprint("PROCESS RECORD USER: LAYER1\n");
                    persistent_default_layer_set(1UL<<_LAYER1);
                    led_layer1();
                }
            }
            return false;
            break;
        
        case LAYER_F:
            if (record->event.pressed) {
                dprint("PROCESS RECORD USER: LAYER3\n");
                persistent_default_layer_set(1UL<<_LAYER3);
                led_layer3();
            }
            return false;
            break;

        case ADJUST:
            return change_layer_onpress_with_tap(_ADJUST, _______, record, &u_pressed_adjust, &u_pressed_adjust_time);
            break;
        
        // 以下、LED制御 ===========================================================================
        #ifdef RGBLIGHT_ENABLE
        case RGB_MOD:
            if (record->event.pressed) {
                rgblight_mode_noeeprom(RGB_current_config.mode);
                rgblight_step();
                RGB_current_config.mode = rgblight_config.mode;
            }
	        return false;
	        break;

        case RGB_RMOD:
            if (record->event.pressed) {
                rgblight_mode_noeeprom(RGB_current_config.mode);
                rgblight_step_reverse();
                RGB_current_config.mode = rgblight_config.mode;
            }
	        return false;
	        break;

	    case RGB_RST:
            if (record->event.pressed) {
                eeconfig_update_rgblight_default();
                rgblight_enable();
                RGB_current_config = rgblight_config;
            }
            return false;
            break;

        case RGB_HUI:
            if (record->event.pressed) {
                rgblight_increase_hue();
                RGB_current_config.hue = rgblight_config.hue;
            }
            return false;
            break;

        case RGB_HUD:
            if (record->event.pressed) {
                rgblight_decrease_hue();
                RGB_current_config.hue = rgblight_config.hue;
            }
            return false;
            break;

        case RGB_SAI:
            if (record->event.pressed) {
                rgblight_increase_sat();
                RGB_current_config.sat = rgblight_config.sat;
            }
            return false;
            break;

        case RGB_SAD:
            if (record->event.pressed) {
                rgblight_decrease_sat();
                RGB_current_config.sat = rgblight_config.sat;
            }
            return false;
            break;

        case RGB_VAI:
            if (record->event.pressed) {
                rgblight_increase_val();
                RGB_current_config.val = rgblight_config.val;
            }
            return false;
            break;

        case RGB_VAD:
            if (record->event.pressed) {
                rgblight_decrease_val();
                RGB_current_config.val = rgblight_config.val;
            }
            return false;
            break;
        #endif

        default:
            u_pressed_adjust = false;
            break;
    }
    return true;
}

/**
 * レイヤーステート設定ユーザ定義
 */
uint32_t layer_state_set_user(uint32_t state) {
    switch (biton32(state)) {
        case _ADJUST:
            dprint("LAYER STATE SET USER: ADJUST\n");
            led_layer_adjust();
            break;

        default:
            if (default_layer_state & (1UL<<_LAYER1)) {
                dprint("LAYER STATE SET USER: LAYER1\n");
                led_layer1();

            } else if (default_layer_state & (1UL<<_LAYER2)) {
                dprint("LAYER STATE SET USER: LAYER2\n");
                led_layer2();

            } else if (default_layer_state & (1UL<<_LAYER3)) {
                dprint("LAYER STATE SET USER: LAYER3\n");
                led_layer3();

            } else {
                dprint("LAYER STATE SET USER: DEFAULT\n");

            }
            break;
    }
	return state;
}

//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED

    // hook point for 'led_test' keymap
    //   'default' keymap's led_test_init() is empty function, do nothing
    //   'led_test' keymap's led_test_init() force rgblight_mode_noeeprom(RGBLIGHT_MODE_RGB_TEST);
    __attribute__ ((weak))
    void led_test_init(void) {}


    /**
     * マトリクススキャン時ユーザ定義
     */
    void matrix_scan_user(void) {
        led_test_init();
        iota_gfx_task();  // this is what updates the display continuously
    }

    void matrix_update(struct CharacterMatrix *dest, const struct CharacterMatrix *source) {
        if (memcmp(dest->display, source->display, sizeof(dest->display))) {
            memcpy(dest->display, source->display, sizeof(dest->display));
            dest->dirty = true;
        }
    }

    //assign the right code to your layers for OLED display
    #define L_LAYER1 (1<<_LAYER1)
    #define L_LAYER2 (1<<_LAYER2)
    #define L_LAYER3 (1<<_LAYER3)
    #define L_ADJUST (1<<_ADJUST)

    void render_status(struct CharacterMatrix *matrix) {
        static char logo[4][1][17]=
        {
            {
            {0x65,0x66,0x67,0x68,0x69,0x6a,0x6b,0x6c,0x6d,0x6e,0x6f,0x70,0x71,0x72,0x73,0x74,0}
            },
            {
            {0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,0}
            },
            {
            {0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,0}
            },
            {
            {0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0}
            }
        };
        static char indctr[8][2][4]=
        {
            // white icon
            {
            {0x60,0x61,0x62,0},
            {0x63,0x64,0}
            },
            {
            {0x80,0x81,0x82,0},
            {0x83,0x84,0}
            },
            {
            {0xa0,0xa1,0xa2,0},
            {0xa3,0xa4,0}
            },
            {
            {0xc0,0xc1,0xc2,0},
            {0xc3,0xc4,0}
            },
            // Black icon
            {
            {0x75,0x76,0x77,0},
            {0x78,0x79,0}
            },
            {
            {0x95,0x96,0x97,0},
            {0x98,0x99,0}
            },
            {
            {0xb5,0xb6,0xb7,0},
            {0xb8,0xb9,0}
            },
            {
            {0xd5,0xd6,0xd7,0},
            {0xd8,0xd9,0}
            },
        };

        int rown = 0;
        int rowf = 0;
        int rowa = 0;
        int rows = 0;

        //Set Indicator icon
        if (default_layer_state & L_LAYER2) { rown = 4; } else { rown = 0; }
        //if (host_keyboard_leds() & (1<<USB_LED_CAPS_LOCK)) { rowa = 4; } else { rowa = 0; }
        //if (host_keyboard_leds() & (1<<USB_LED_SCROLL_LOCK)) { rows = 4; } else { rows = 0; }
        if (default_layer_state & L_LAYER3) { rowa = 4; } else { rowa = 0; }
        if (layer_state & (1<<_ADJUST)) { rowf = 4; }
        
        matrix_write(matrix, indctr[rown]  [0]);
        matrix_write(matrix, indctr[rowf]  [1]);
        matrix_write(matrix, logo  [0]     [0]);
        matrix_write(matrix, indctr[rown+1][0]);
        matrix_write(matrix, indctr[rowf+1][1]);
        matrix_write(matrix, logo  [1]     [0]);
        matrix_write(matrix, indctr[rowa+2][0]);
        matrix_write(matrix, indctr[rows+2][1]);
        matrix_write(matrix, logo  [2]     [0]);
        matrix_write(matrix, indctr[rowa+3][0]);
        matrix_write(matrix, indctr[rows+3][1]);
        matrix_write(matrix, logo  [3]     [0]);
    }


    void iota_gfx_task_user(void) {
        struct CharacterMatrix matrix;

        #if DEBUG_TO_SCREEN
            if (debug_enable) {
                return;
            }
        #endif

        matrix_clear(&matrix);
        if(is_master){
            render_status(&matrix);
        }
        matrix_update(&display, &matrix);
    }
#endif
 