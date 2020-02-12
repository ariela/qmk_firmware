#include QMK_KEYBOARD_H
#include "ariela.h"

/**
 * デフォルトレイヤーの変更処理
 */
void persistent_default_layer_set(uint16_t default_layer) {
    eeconfig_update_default_layer(default_layer);
    default_layer_set(default_layer);
};

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
 * 押下時にレイヤーの変更を行う
 */
bool change_layer_onpress(uint16_t layer, keyrecord_t *record) {
    if (record->event.pressed) {
        layer_on(layer);
    } else {
        layer_off(layer);
    }
    return false;
}

/**
 * 押下時にレイヤーの変更を行う
 */
bool change_layer_onpress_with_trilayer(uint16_t layer, keyrecord_t *record, uint16_t layer1, uint16_t layer2, uint16_t calllayer) {
    change_layer_onpress(layer, record);
    update_tri_layer(layer1, layer2, calllayer);
    return false;
}

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
 * タップ時にキーコード発行/ホールド時にレイヤー変更を行う
 */
bool change_layer_onpress_with_tap_and_trilayer(uint16_t layer, uint16_t keycode, keyrecord_t *record, bool *flag, uint16_t *time, uint16_t layer1, uint16_t layer2, uint16_t calllayer) {
    change_layer_onpress_with_tap(layer, keycode, record, flag, time);
    update_tri_layer(layer1, layer2, calllayer);
    return false;
}
