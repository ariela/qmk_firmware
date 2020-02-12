#pragma once
#include "wrappers.h"

#undef TAPPING_TERM
#define TAPPING_TERM 150

#define _______ KC_TRNS
#define XXXXXXX KC_NO

void persistent_default_layer_set(uint16_t default_layer);
bool lang_key_onpress(uint16_t keycode, keyrecord_t *record);
bool change_layer_onpress(uint16_t layer, keyrecord_t *record);
bool change_layer_onpress_with_trilayer(uint16_t layer, keyrecord_t *record, uint16_t layer1, uint16_t layer2, uint16_t calllayer);
bool change_layer_onpress_with_tap(uint16_t layer, uint16_t keycode, keyrecord_t *record, bool *flag, uint16_t *time);
bool change_layer_onpress_with_tap_and_trilayer(uint16_t layer, uint16_t keycode, keyrecord_t *record, bool *flag, uint16_t *time, uint16_t layer1, uint16_t layer2, uint16_t calllayer);
