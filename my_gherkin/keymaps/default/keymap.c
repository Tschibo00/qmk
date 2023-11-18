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
    )
};

const uint16_t PROGMEM test_combo[]={LT(2,KC_B), LT(2,KC_N),COMBO_END};
combo_t key_combos[1]={
	COMBO(test_combo, KC_SPC)
};