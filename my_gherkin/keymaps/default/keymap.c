// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#define COMBO_COUNT 1
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
	 * Base layer
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
     * │ q │ w │ e │ r │ t │ y │ u │ i │ o │ p │
     * │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │ a │ s │ d │ f │ g │ h │ j │ k │ l │BkS│
     * │ A │ S │ D │ F │ G │ H │ J │ K │ L │Del│
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │ z │ x │ c │ v │ b │ n │ m │ , │ . │Ent│
     * │ Z │ X │ C │ V │ B │ N │ M │ < │ > │Del│
	 * │Shf│Ctl│Alt│L1 │L2 │L2 │L3 │Alt│Ctl│Shf│
     * └───┴───┴───┴───┴───┴───┴───┴───┴───┴───┘
	 *
	 * Combos
     * ┌───┬───┬───┬───┬───┬───┬───+───┬───+───┐
     * │  Tab  │   │   │   │   │   ü   │   ö   │
     * │       │   │   │   │   │   Ü   │   Ö   │
     * ├───+───+───┼───┼───┼───┼───┼───┼───┼───┤
     * │   ä   ß   │   │   │   │   │   │   │   │
     * │   Ä   ẞ   │   │   │   │   │   │   │   │
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │   │   │   │   │ Space │   │   │   │   │
     * └───┴───┴───┴───┴───┴───┴───┴───┴───┴───┘
	 *
	 * Symbol layer (L1)
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
     * │ ! │ @ │ # │ $ │ % │ ^ │ & │ * │ ( │ ) │
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │ - │ _ │ = │ + │ ~ │ { │ [ │ ] │ } │Del│
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │ ' │ " │ ` │xxx│ \ │ | │ / │ ? │ ; │ : │
     * └───┴───┴───┴───┴───┴───┴───┴───┴───┴───┘
	 *
	 * Move layer (L2)
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
     * │Esc│Hom│ up│Top│PgU│   │Hom│ up│Top│PgU│
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │WdL│lft│dwn│rgt│WdR│WdL│lft│dwn│rgt│WdR│
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │Shf│End│PgD│Btm│xxx│xxx│End│PgD│Btm│PgD│
     * └───┴───┴───┴───┴───┴───┴───┴───┴───┴───┘
	 *
	 * Numeric layer (L3)
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
     * │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │ F1│ F2│ F3│ F4│ F5│ F6│   │   │   │Del│
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │ F7│ F8│ F9│F10│F11│F12│xxx│   │   │Ent│
     * └───┴───┴───┴───┴───┴───┴───┴───┴───┴───┘
     */
    [0] = LAYOUT_ortho_3x10(
        KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P,
        KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_BSPC,
        LSFT_T(KC_Z), LCTL_T(KC_X), LALT_T(KC_C), LT(1, KC_V), LT(2, KC_B), LT(2, KC_N), LT(3, KC_M), RALT_T(KC_COMM), RCTL_T(KC_DOT), RSFT_T(KC_ENT)
    ),
	[1] = LAYOUT_ortho_3x10(
		KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
		KC_MINS, LSFT(KC_MINS), KC_EQL, LSFT(KC_EQL), LSFT(KC_GRV), LSFT(KC_LBRC), KC_LBRC, KC_RBRC, LSFT(KC_RBRC), KC_DEL,
        KC_QUOT, LSFT(KC_QUOT), KC_GRV, KC_NO, KC_BSLS, LSFT(KC_BSLS), KC_SLSH, LSFT(KC_SLSH), KC_SCLN, LSFT(KC_SCLN)
	),
	[2] = LAYOUT_ortho_3x10(
		KC_ESC, KC_HOME, KC_UP, LCTL(KC_HOME), KC_PGUP, KC_NO, KC_HOME, KC_UP, LCTL(KC_HOME), KC_PGUP,
		LCTL(KC_LEFT), KC_LEFT, KC_DOWN, KC_RIGHT, LCTL(KC_RIGHT), LCTL(KC_LEFT), KC_LEFT, KC_DOWN, KC_RIGHT, LCTL(KC_RIGHT),
		KC_LSFT, KC_END, KC_PGDN, LCTL(KC_END), KC_NO, KC_NO, KC_END, KC_PGDN, LCTL(KC_END), KC_PGDN
	),
	[3] = LAYOUT_ortho_3x10(
		KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0,
		KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_NO, KC_NO, KC_NO, KC_DEL,
		KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_NO, KC_NO, KC_NO, KC_ENT
	)
};

const uint16_t PROGMEM cmb_space[]={LT(2, KC_B), LT(2, KC_N),COMBO_END};
const uint16_t PROGMEM cmb_tab[]={KC_Q, KC_W,COMBO_END};
const uint16_t PROGMEM cmb_auml[]={KC_A, KC_S,COMBO_END};
const uint16_t PROGMEM cmb_ouml[]={KC_O, KC_P,COMBO_END};
const uint16_t PROGMEM cmb_uuml[]={KC_U, KC_I,COMBO_END};
const uint16_t PROGMEM cmb_szlig[]={KC_S, KC_D,COMBO_END};
combo_t key_combos[6]={
	COMBO(cmb_space, KC_SPC),
	COMBO(cmb_tab, KC_TAB),
	COMBO(cmb_auml, RALT_T(KC_Q)),
	COMBO(cmb_ouml, RALT_T(KC_P)),
	COMBO(cmb_uuml, RALT_T(KC_Y)),
	COMBO(cmb_szlig, RALT_T(KC_S)),
};
