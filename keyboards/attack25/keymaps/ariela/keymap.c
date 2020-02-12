#include QMK_KEYBOARD_H
#include "ariela.h"
#include <print.h>
#include <drivers/avr/pro_micro.h>

#ifdef RGBLIGHT_ENABLE
    extern rgblight_config_t rgblight_config;
    rgblight_config_t RGB_current_config;
#endif

//--+----1----+----2----+----3----+----4----+----5----+----6----+----7----+----8----+----9----+----0
// LED色定義
//--+----1----+----2----+----3----+----4----+----5----+----6----+----7----+----8----+----9----+----0
// レイヤーがFUNCTION時の色設定
#define u_rgblight_layer_function()     rgblight_sethsv_noeeprom_orange()
// Numlock解除時の色設定
#define u_rgblight_layer_unnumlock()    rgblight_sethsv_noeeprom_azure()

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

//--+----1----+----2----+----3----+----4----+----5----+----6----+----7----+----8----+----9----+----0
// レイヤー定義
//--+----1----+----2----+----3----+----4----+----5----+----6----+----7----+----8----+----9----+----0
enum layer_number {
    _NUMPAD = 0,
    _NUMLOCK,
    _FUNCTION,
    _RGB
};

//--+----1----+----2----+----3----+----4----+----5----+----6----+----7----+----8----+----9----+----0
// カスタムキーコード定義
//--+----1----+----2----+----3----+----4----+----5----+----6----+----7----+----8----+----9----+----0
enum custom_keycodes {
    L_NUMPD = SAFE_RANGE,
    L_NUMLK,
    L_FUNC,
    L_RGB,
    RGB_RST,
    KC_P00
};

//--+----1----+----2----+----3----+----4----+----5----+----6----+----7----+----8----+----9----+----0
// 複合キーコード定義
//--+----1----+----2----+----3----+----4----+----5----+----6----+----7----+----8----+----9----+----0
// コンビネーションキー定義
#define KC_BTAB LSFT(KC_TAB)

//--+----1----+----2----+----3----+----4----+----5----+----6----+----7----+----8----+----9----+----0
// キーマップ定義
//--+----1----+----2----+----3----+----4----+----5----+----6----+----7----+----8----+----9----+----0
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* NumPad
    * ,-------------------------------------------------.
    * |  NumLk  |    /    |    *    |    -    |  BkSp   |
    * |---------+---------+---------+---------+---------|
    * |    7    |    8    |    9    |         |  BkTab  |
    * |---------+---------+---------+    +    +---------|
    * |    4    |    5    |    6    |         |   Tab   | // RGB/Tab
    * |---------+---------+---------+---------+---------|
    * |    1    |    2    |    3    |         |   DEL   | // Func/Delete
    * |---------+---------+---------+  Enter  +---------|
    * |    0    |   00    |    .    |         |   ESC   |
    * `-------------------------------------------------'
      //_______ , _______ , _______ , _______ , _______ ,
    */
    [_NUMPAD] = LAYOUT_ortho_5x5_wrapper( \
        L_NUMLK , _________NUMPAD__1_________ , KC_BSPC , \
        _______________NUMPAD__2_____________ , KC_BTAB , \
        _______________NUMPAD__3_____________ , L_RGB   , \
        _______________NUMPAD__4_____________ , L_FUNC  , \
        _______________NUMPAD_W5_____________ , KC_ESC    \
      //_______ , _______ , _______ , _______ , _______ ,
    ), \

    /* NumLock
    * ,-------------------------------------------------.
    * |  NumLk  |         |         |         |  BkSp   |
    * |---------+---------+---------+---------+---------|
    * |  Home   |    ↑    |  PgUp   |         |  BkTab  |
    * |---------+---------+---------+         +---------|
    * |    ←    |         |    →    |         |   Tab   | // RGB/Tab
    * |---------+---------+---------+---------+---------|
    * |   End   |    ↓    |  PgDn   |         |   DEL   | // Func/Delete
    * |---------+---------+---------+         +---------|
    * |   Ins   |         |   Del   |         |   ESC   |
    * `-------------------------------------------------'
    */
    [_NUMLOCK] = LAYOUT_ortho_5x5_wrapper( \
        L_NUMLK , XXXXXXX , XXXXXXX , XXXXXXX , KC_BSPC , \
        ______________NUMLOCK_2______________ , KC_BTAB , \
        ______________NUMLOCK_3______________ , L_RGB   , \
        ______________NUMLOCK_4______________ , L_FUNC  , \
        ______________NUMLOCKW5______________ , KC_ESC    \
      //_______ , _______ , _______ , _______ , _______
    ), \

    /* Function
    * ,-------------------------------------------------.
    * |   F10   |   F11   |   F12   |         |  RESET  |
    * |---------+---------+---------+---------+---------|
    * |   F7    |   F8    |   F9    |         |         |
    * |---------+---------+---------+         +---------|
    * |   F4    |   F5    |   F6    |         |         |
    * |---------+---------+---------+---------+---------|
    * |   F1    |   F2    |   F3    |         |         |
    * |---------+---------+---------+         +---------|
    * |         |         |         |         |         |
    * `-------------------------------------------------'
    */
    [_FUNCTION] = LAYOUT_ortho_5x5_wrapper( \
        ______________NUMFUNC_1______________ , RESET   , \
        ______________NUMFUNC_2______________ , XXXXXXX , \
        ______________NUMFUNC_3______________ , XXXXXXX , \
        ______________NUMFUNC_4______________ , _______ , \
        XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX \
      //_______ , _______ , _______ , _______ , _______
    ), \

    /* RGB
    * ,-------------------------------------------------.
    * | TOGGLE  |  MOD+   |  HUE+   |  SAT+   |  VAL+   |
    * |---------+---------+---------+---------+---------|
    * |   RST   |  MOD-   |  HUE-   |  SAT-   |  VAL-   |
    * |---------+---------+---------+         +---------|
    * |  PLAIN  | BREATH  | RAINBO  |         |         |
    * |---------+---------+---------+---------+---------|
    * |  SWIRL  |  SNAKE  | KNIGHT  |         |         |
    * |---------+---------+---------+         +---------|
    * |         |         |         |         |         |
    * `-------------------------------------------------'
    */
    [_RGB] = LAYOUT_ortho_5x5_wrapper( \
        RGB_TOG , RGB_MOD , RGB_HUI , RGB_SAI , RGB_VAI , \
        RGB_RST , RGB_RMOD, RGB_HUD , RGB_SAD , RGB_VAD , \
        RGB_M_P , RGB_M_B , RGB_M_R , XXXXXXX , XXXXXXX , \
        RGB_M_SW, RGB_M_SN, RGB_M_K , XXXXXXX , XXXXXXX , \
        _______ , _______ , _______ , _______ , _______   \
      //_______ , _______ , _______ , _______ , _______
    ) \
};


//--+----1----+----2----+----3----+----4----+----5----+----6----+----7----+----8----+----9----+----0
// 変数定義
//--+----1----+----2----+----3----+----4----+----5----+----6----+----7----+----8----+----9----+----0
static bool u_pressed_function = false;
static bool u_pressed_rgb      = false;

static uint16_t u_pressed_function_time = 0;
static uint16_t u_pressed_rgb_time      = 0;


//--+----1----+----2----+----3----+----4----+----5----+----6----+----7----+----8----+----9----+----0
// 関数定義
//--+----1----+----2----+----3----+----4----+----5----+----6----+----7----+----8----+----9----+----0

/**
 * RGBのモード・HSVをリストアする
 */
void u_rgblight_restore(void) {
    #ifdef RGBLIGHT_ENABLE
        rgblight_mode_noeeprom(RGB_current_config.mode);
        rgblight_sethsv_noeeprom(RGB_current_config.hue, RGB_current_config.sat, RGB_current_config.val);
    #endif
}

void u_rgblight_unnumlock(void) {
    #ifdef RGBLIGHT_ENABLE
        rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
        u_rgblight_layer_unnumlock();
    #endif
}

void u_rgblight_function(void) {
    #ifdef RGBLIGHT_ENABLE
        rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
        u_rgblight_layer_function();
    #endif
}

void persistent_default_layer_set(uint16_t default_layer){
    eeconfig_update_default_layer(default_layer);
    default_layer_set(default_layer);
};
/**
 * タップ時にキーコード発行/ホールド時にレイヤー変更を行う
 */
bool change_layer_onpress_with_tap(uint16_t layer, uint16_t keycode, keyrecord_t *record, bool *flag, uint16_t *time) {
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
    return false;
}

/**
 * マトリクス初期化時ユーザ定義
 */
void matrix_init_user(void) {
    TX_RX_LED_INIT; //Turn LEDs off by default
    RXLED0;
    TXLED0;
    persistent_default_layer_set(1UL<<_NUMPAD);
    #ifdef RGBLIGHT_ENABLE
	    rgblight_init();
        RGB_current_config = rgblight_config;
        u_rgblight_restore();
    #endif
}

/**
 * マトリクススキャン時ユーザ定義
 */
void matrix_scan_user(void) {
}
  

/**
 * キー処理実行時ユーザ定義
 */
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case L_NUMLK:
            if (record->event.pressed) {
                if (default_layer_state & (1UL<<_NUMPAD)) {
                    dprint("PROCESS RECORD USER: NUMLOCK\n");
                    persistent_default_layer_set(1UL<<_NUMLOCK);
                    u_rgblight_unnumlock();
                    
                } else {
                    dprint("PROCESS RECORD USER: NUMPAD\n");
                    persistent_default_layer_set(1UL<<_NUMPAD);
                    u_rgblight_restore();

                }
            }
            return false;
            break;

        case L_FUNC:
            return change_layer_onpress_with_tap(_FUNCTION, KC_DEL, record, &u_pressed_function, &u_pressed_function_time);
            break;

        case L_RGB:
            return change_layer_onpress_with_tap(_RGB, KC_TAB, record, &u_pressed_rgb, &u_pressed_rgb_time);
            break;

        case KC_P00:
            if (record->event.pressed) {
                SEND_STRING("00");
            }  
            return false;
            break;

        case RGB_MOD:
            #ifdef RGBLIGHT_ENABLE
	            if (record->event.pressed) {
                    rgblight_mode_noeeprom(RGB_current_config.mode);
                    rgblight_step();
                    RGB_current_config.mode = rgblight_config.mode;
                }
            #endif
	        return false;
	        break;

        case RGB_RMOD:
            #ifdef RGBLIGHT_ENABLE
                if (record->event.pressed) {
                    rgblight_mode_noeeprom(RGB_current_config.mode);
                    rgblight_step_reverse();
                    RGB_current_config.mode = rgblight_config.mode;
                }
            #endif
	        return false;
	        break;

	    case RGB_RST:
            #ifdef RGBLIGHT_ENABLE
                if (record->event.pressed) {
                    eeconfig_update_rgblight_default();
                    rgblight_enable();
                    RGB_current_config = rgblight_config;
                }
            #endif
            return false;
            break;

        case RGB_HUI:
            #ifdef RGBLIGHT_ENABLE
                if (record->event.pressed) {
                    rgblight_increase_hue();
                    RGB_current_config.hue = rgblight_config.hue;
                }
            #endif
            return false;
            break;

        case RGB_HUD:
            #ifdef RGBLIGHT_ENABLE
                if (record->event.pressed) {
                    rgblight_decrease_hue();
                    RGB_current_config.hue = rgblight_config.hue;
                }
            #endif
            return false;
            break;

        case RGB_SAI:
            #ifdef RGBLIGHT_ENABLE
                if (record->event.pressed) {
                    rgblight_increase_sat();
                    RGB_current_config.sat = rgblight_config.sat;
                }
            #endif
            return false;
            break;

        case RGB_SAD:
            #ifdef RGBLIGHT_ENABLE
                if (record->event.pressed) {
                    rgblight_decrease_sat();
                    RGB_current_config.sat = rgblight_config.sat;
                }
            #endif
            return false;
            break;

        case RGB_VAI:
            #ifdef RGBLIGHT_ENABLE
                if (record->event.pressed) {
                    rgblight_increase_val();
                    RGB_current_config.val = rgblight_config.val;
                }
            #endif
            return false;
            break;

        case RGB_VAD:
            #ifdef RGBLIGHT_ENABLE
                if (record->event.pressed) {
                    rgblight_decrease_val();
                    RGB_current_config.val = rgblight_config.val;
                }
            #endif
            return false;
            break;

        case RGB_MODE_PLAIN:
        case RGB_MODE_BREATHE:
        case RGB_MODE_RAINBOW:
        case RGB_MODE_SWIRL:
        case RGB_MODE_SNAKE:
        case RGB_MODE_KNIGHT:
            #ifdef RGBLIGHT_ENABLE
                if (record->event.pressed) {
                } else {
                    RGB_current_config.mode = rgblight_config.mode;
                }
            #endif
            break;
            
        default:
            if (record->event.pressed) {
                u_pressed_function = false;
                u_pressed_rgb      = false;
            }
            break;
    }
    return true;
}

/**
 * レイヤーステート設定ユーザ定義
 */
uint32_t layer_state_set_user(uint32_t state) {
	    switch (biton32(state)) {
            case _FUNCTION:
                dprint("LAYER STATE SET USER: FUNCTION\n");
                u_rgblight_function();
                break;
            case _RGB:
                dprint("LAYER STATE SET USER: RGB\n");
                break;
            default:
                if (default_layer_state & (1UL<<_NUMPAD)) {
                    dprint("LAYER STATE SET USER: NUMPAD\n");
                    u_rgblight_restore();

                } else if (default_layer_state & (1UL<<_NUMLOCK)) {
                    dprint("LAYER STATE SET USER: NUMLOCK\n");
                    u_rgblight_unnumlock();

                } else {
                    dprint("LAYER STATE SET USER: DEFAULT\n");
	                #ifdef RGBLIGHT_ENABLE
                        rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING + 3);
                        rgblight_sethsv_noeeprom_red();
	                #endif
                }
                break;
	    }
	return state;
} 

/**
 * LED設定ユーザ定義
 */
void led_set_user(uint8_t usb_led) {
    if (usb_led & (1 << USB_LED_NUM_LOCK)) {
    } else {
    }

	if (usb_led & (1 << USB_LED_CAPS_LOCK)) {
	} else {
	}

	if (usb_led & (1 << USB_LED_SCROLL_LOCK)) {
	} else {
	}

	if (usb_led & (1 << USB_LED_COMPOSE)) {
	} else {
	}

	if (usb_led & (1 << USB_LED_KANA)) {
	} else {
	}
}
