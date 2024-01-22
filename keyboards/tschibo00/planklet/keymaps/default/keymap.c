#include QMK_KEYBOARD_H
#include "hp_display.h"

enum layers {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _FUNCTION,
  _GAME
};

enum custom_keycodes {
    MC_QUOT = SAFE_RANGE,
    MC_GRV,
	COM_BRK,
	COM_SBRK,
	COM_CBRK,
	COM_DQUOT,
	MC_CARET,
	MC_DEL,
	MC_TILD,
	MC_Y_Z,
	MC_Z_Y
};

const uint16_t PROGMEM cmb_auml[]={KC_A, KC_S,COMBO_END}; 
const uint16_t PROGMEM cmb_ouml[]={KC_O, KC_P,COMBO_END}; 
const uint16_t PROGMEM cmb_uuml[]={KC_U, KC_I,COMBO_END}; 
const uint16_t PROGMEM cmb_szlig[]={KC_S, KC_D,COMBO_END}; 
const uint16_t PROGMEM cmb_euro[]={KC_E, KC_T,COMBO_END}; 
combo_t key_combos[5]={
     COMBO(cmb_auml, RALT(KC_Q)),
     COMBO(cmb_ouml, RALT(KC_P)),
     COMBO(cmb_uuml, RALT(KC_Y)),
     COMBO(cmb_szlig, RALT(KC_S)),
     COMBO(cmb_euro, LALT(LCTL(KC_5)))
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_ortho_3x13(				// layer -
        LALT_T(KC_ESC), KC_Q,   KC_W, KC_E, KC_R, KC_T, LT(_FUNCTION,KC_BSPC), MC_Z_Y, KC_U, KC_I,     KC_O,   KC_P,    LALT_T(KC_MINUS),
        LSFT_T(KC_TAB), KC_A,   KC_S, KC_D, KC_F, KC_G, LT(_LOWER,KC_ENT),     KC_H,   KC_J, KC_K,     KC_L,   KC_SCLN, LSFT_T(KC_PLUS),
        LCTL_T(KC_QUOT),MC_Y_Z, KC_X, KC_C, KC_V, KC_B, LT(_RAISE,KC_SPACE),   KC_N,   KC_M, KC_COMMA, KC_DOT, KC_SLSH, LCTL_T(KC_BSLS)
    ),
    [_LOWER] = LAYOUT_ortho_3x13(				// lower
		MC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, LT(_FUNCTION,KC_DEL), MC_CARET, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_NO,
		KC_NO,   KC_NO,   KC_NO, KC_NO,   KC_NO,  KC_NO,   LT(_LOWER,KC_ENT),    KC_NO,    KC_NO,   KC_NO,   KC_LBRC, KC_RBRC, KC_NO,
		KC_NO,   KC_NO,   KC_NO, KC_NO,   KC_NO,  KC_NO,   LT(_RAISE,KC_SPACE),  KC_NO,    KC_NO,   KC_NO,   KC_LCBR, KC_RCBR, KC_NO
    ),
    [_RAISE] = LAYOUT_ortho_3x13(				// raise
		MC_GRV, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   LT(_FUNCTION,KC_DEL), KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_NO,
		KC_NO,  KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  LT(_LOWER,KC_ENT),    KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_NO,
		KC_NO,  KC_F11, KC_F12, KC_F13, KC_F14, KC_F15, LT(_RAISE,KC_SPACE),  KC_F16, KC_F17, KC_F18, KC_F19, KC_F20, KC_NO
    ),
    [_FUNCTION] = LAYOUT_ortho_3x13(			// function
		QK_BOOT,   RGB_TOG, RGB_MOD, RGB_HUD, RGB_HUI, KC_NO, LT(_FUNCTION,KC_DEL), KC_NO, KC_HOME, KC_UP,   KC_PGUP,  COM_BRK,  COM_BRK,
		KC_NO,     KC_NO,   KC_NO,   RGB_SAD, RGB_SAI, KC_NO, TG(_GAME),            KC_NO, KC_LEFT, KC_DOWN, KC_RIGHT, COM_SBRK, COM_SBRK,
		COM_DQUOT, KC_NO,   KC_NO,   RGB_VAD, RGB_VAI, KC_NO, LT(_RAISE,KC_SPACE),  KC_NO, KC_END,  KC_NO,   KC_PGDN,  COM_CBRK, COM_CBRK
    ),
    [_GAME] = LAYOUT_ortho_3x13(				// game
		KC_ESC,  KC_1,    KC_2,  KC_3, KC_4, KC_5,  LT(_FUNCTION,KC_DEL), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
		KC_NO,   KC_NO,   KC_A,  KC_W, KC_E, KC_R,  TG(_GAME),            KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
		KC_LSFT, KC_LCTL, KC_NO, KC_S, KC_D, KC_NO, LT(_RAISE,KC_SPACE),  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {	
    const uint8_t mods = get_mods();
    switch (keycode) {
		case MC_QUOT:
			if (record->event.pressed) {
				SEND_STRING(SS_TAP(X_QUOT) SS_TAP(X_SPC));
			}
			break;
		case MC_GRV:
			if (record->event.pressed) {
				SEND_STRING(SS_TAP(X_GRV) SS_TAP(X_SPC));
			}
			break;
		case MC_TILD:
			if (record->event.pressed) {
				SEND_STRING(SS_DOWN(X_LSFT) SS_TAP(X_GRV) SS_TAP(X_SPC) SS_UP(X_LSFT));
			}
			break;
		case COM_BRK:
			if (record->event.pressed) {
				SEND_STRING("()" SS_TAP(X_LEFT));
			}
			break;
		case COM_SBRK:
			if (record->event.pressed) {
				SEND_STRING("[]" SS_TAP(X_LEFT));
			}
			break;
		case COM_CBRK:
			if (record->event.pressed) {
				SEND_STRING("{}" SS_TAP(X_LEFT));
			}
			break;
		case COM_DQUOT:
			if (record->event.pressed) {
				SEND_STRING("\"\"" SS_TAP(X_LEFT));
			}
			break;
		case MC_CARET:
			if (record->event.pressed) {
				SEND_STRING(SS_LSFT("6") SS_TAP(X_SPC));
			}
			break;
		// handle the shifted macros here, as overrides don't handle macros
		case MC_DEL:
			if (record->event.pressed) {
				if (mods & MOD_MASK_SHIFT) {  // Is shift held?
				// Temporarily delete shift.
					unregister_mods(MOD_MASK_SHIFT);  
					SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_HOME) SS_UP(X_LALT) SS_DOWN(X_LSFT) SS_TAP(X_DOWN) SS_UP(X_LSFT) SS_TAP(X_DELETE));
					register_mods(mods);            // Restore mods.
				} else {
//					SEND_STRING(SS_TAP(X_BSPC));
					SEND_STRING(SS_DOWN(X_BSPC));
				}
			} else {
				SEND_STRING(SS_UP(X_BSPC));
			}
			break;
		case MC_Y_Z:
			if (record->event.pressed) {
				if (mods & MOD_MASK_CTRL) {
					SEND_STRING("z");
				} else {
					SEND_STRING("y");
				}
			}
			break;
		case MC_Z_Y:
			if (record->event.pressed) {
				if (mods & MOD_MASK_CTRL) {
					SEND_STRING("y");
				} else {
					SEND_STRING("z");
				}
			}
			break;
	}
    return true;
};
/*
void suspend_power_down_kb(void)
{
    led_matrix_set_suspend_state(true);
}

void suspend_wakeup_init_kb(void)
{
    led_matrix_set_suspend_state(false);
}
*/
void render_game_display(void){
//	led_matrix_set_value_all(99);
//    is31fl3731_update_pwm_buffers(LED_DRIVER_ADDR_1, 0);

/*	led_matrix_set_value(9,100);
	led_matrix_set_value(11,100);
	led_matrix_set_value(12,100);
	led_matrix_set_value(13,100);
	led_matrix_set_value(14,100);
	led_matrix_set_value(15,100);
	led_matrix_set_value(16,100);*/
//	led_matrix_set_value(0, 70);
//	led_matrix_set_value(0, 0);
}

void render_hack_display(void){
/*	led_matrix_set_value(9,0);
	led_matrix_set_value(11,0);
	led_matrix_set_value(12,0);
	led_matrix_set_value(13,0);
	led_matrix_set_value(14,0);
	led_matrix_set_value(15,0);
	led_matrix_set_value(16,0);*/
//	led_matrix_set_value_all(0);
//    is31fl3731_update_pwm_buffers(LED_DRIVER_ADDR_1, 0);
//	led_matrix_set_value(1, 70);
//	led_matrix_set_value(1, 0);
}
layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case _GAME:
			rgblight_enable_noeeprom();
			rgblight_sethsv_noeeprom(HSV_RED);
			rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING);
			hpDrawBitmap(1);
//			render_game_display();
            break;
        default:
			rgblight_enable_noeeprom();
			rgblight_sethsv_noeeprom(0,0,100);
			rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
//			render_hack_display();
			hpDrawBitmap(0);
            break;
    }
  return state;
}
 