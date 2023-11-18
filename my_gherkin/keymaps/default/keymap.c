// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#define COMBO_COUNT 1
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
     * │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │ A │ S │ D │ F │ G │ H │ J │ K │ L │BkS│
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │ Z │ X │ C │ V │ B │ N │ M │ , │ . │Ent│
     * └───┴───┴───┴───┴───┴───┴───┴───┴───┴───┘
     */
    [0] = LAYOUT_ortho_3x10(
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_BSPC,
        LSFT_T(KC_Z), LCTL_T(KC_X), LALT_T(KC_C), LT(1,KC_V), LT(2,KC_B), LT(2,KC_N), LT(1,KC_M), RALT_T(KC_COMM), RCTL_T(KC_DOT), RSFT_T(KC_ENT)
    ),
	[1] = LAYOUT_ortho_3x10(
		KC_1,KC_2,KC_3,KC_4,KC_5,KC_6,KC_7,KC_8,KC_9,KC_0,
		KC_TAB, KC_F2, KC_F3,   KC_F4,   KC_F5,  LSFT(KC_LBRC),KC_LBRC,KC_RBRC,LSFT(KC_RBRC), KC_ESC,
        LSFT_T(KC_Z), LCTL_T(KC_X), LALT_T(KC_C), LT(1,KC_V), LT(2,KC_B), LT(2,KC_N), LT(1,KC_M), RALT_T(KC_COMM), RCTL_T(KC_DOT), RSFT_T(KC_ENT)
	),
	[2] = LAYOUT_ortho_3x10(
		KC_ESC, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_UP, KC_NO, KC_PAGE_UP,
		KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, LCTL(KC_LEFT), KC_LEFT, KC_DOWN, KC_RIGHT, LCTL(KC_RIGHT),
		KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,KC_PAGE_DOWN
	)
};

const uint16_t PROGMEM test_combo[]={LT(2,KC_B), LT(2,KC_N),COMBO_END};
combo_t key_combos[1]={
	COMBO(test_combo, KC_SPC)
};