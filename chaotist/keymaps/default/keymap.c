#include QMK_KEYBOARD_H

enum layers {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _FUNCTION
};

enum custom_keycodes {
    MC_GRV = SAFE_RANGE,
	MC_QUOT,
	COM_BRK,
	COM_SBRK,
	COM_CBRK,
	COM_DQUOT,
	COM_LOCK,
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

static uint16_t yz_hold_timer;

/*
 * Regular layout
 * ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
 * │     │     │     │     │     │     │     │     │     │     │     │     │
 * │     │     │     │     │     │     │     │     │     │     │     │     │
 * │     │     │     ├─────┤     │     │     │     ├─────┤     │     │     │
 * │     │     ├─────┤     ├─────┤     │     ├─────┤     ├─────┤     │     │
 * │     ├─────┤     │     │     ├─────┼─────┤     │     │     ├─────┤     │
 * │     │     │     ├─────┤     │     │     │     ├─────┤     │     │     │
 * │     │     ├─────┤     ├─────┤     │     ├─────┤     ├─────┤     │     │
 * ├─────┼─────┤     │     │     ├─────┼─────┤     │     │     ├─────┼─────┤
 * │     │     │     │     │     │     │     │     │     │     │     │     │
 * │     │     │     │     │     │     │     │     │     │     │     │     │
 * ├─────┴──┬──┴──┬──┴─────┴─────┴─────┴─────┴─────┴─────┴──┬──┴──┬──┴─────┤
 * │        │     │                                         │     │        │
 * │        │     │                                         │     │        │
 * └────────┴─────┴─────────────────────────────────────────┴─────┴────────┘
 * keymap (. are not used points in matrix)
 * xxxxxxxxxxxx
 * .xxxxxxxxxx.
 * x.xxxxxxxx.x
 * x.xx....xx.x
 * Alternative layout if more keys are required
 * ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
 * │     │     │     │     │     │     │     │     │     │     │     │     │
 * │     │     │     │     │     │     │     │     │     │     │     │     │
 * │     │     │     ├─────┤     │     │     │     ├─────┤     │     │     │
 * ├─────┤     ├─────┤     ├─────┤     │     ├─────┤     ├─────┤     ├─────┤
 * │     ├─────┤     │     │     ├─────┼─────┤     │     │     ├─────┤     │
 * │     │     │     ├─────┤     │     │     │     ├─────┤     │     │     │
 * │     │     ├─────┤     ├─────┤     │     ├─────┤     ├─────┤     │     │
 * ├─────┼─────┤     │     │     ├─────┼─────┤     │     │     ├─────┼─────┤
 * │     │     │     │     │     │     │     │     │     │     │     │     │
 * │     │     │     │     │     │     │     │     │     │     │     │     │
 * ├─────┴──┬──┴──┬──┴──┬──┴─────┴──┬──┴──┬──┴─────┴──┬──┴──┬──┴──┬──┴─────┤
 * │        │     │     │           │     │           │     │     │        │
 * │        │     │     │           │     │           │     │     │        │
 * └────────┴─────┴─────┴───────────┴─────┴───────────┴─────┴─────┴────────┘
 * keymap (. are not used points in matrix)
 * xxxxxxxxxxxx
 * xxxxxxxxxxxx
 * x.xxxxxxxx.x
 * x.xxxx.xxx.x
*/
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT(
	LSFT_T(KC_ESC),KC_TAB,KC_W,KC_E,KC_R,KC_T,KC_Z,KC_U,KC_I,KC_O,MC_QUOT,MC_DEL,
	KC_NO, KC_Q,KC_S,KC_D,KC_F,KC_G,KC_H,KC_J,KC_K,KC_L,KC_P,  KC_NO,
	LCTL_T(KC_A),KC_NO,KC_X,KC_C,KC_V,KC_B,KC_N,KC_M,KC_COMMA, KC_DOT,KC_NO,KC_SCLN,
	LALT_T(KC_Y),KC_NO,KC_MINUS,LT(_LOWER,KC_SPACE),KC_NO,KC_NO,KC_NO,KC_NO,LT(_RAISE,KC_ENT),KC_BSLS,KC_NO,KC_SLSH),
[_LOWER] = LAYOUT(
	KC_NO,KC_NO,KC_2,KC_3,KC_4,KC_5,KC_6,KC_7,KC_8,KC_9,KC_NO,KC_DEL,
	KC_NO,KC_1,KC_F1,KC_F2,KC_F3,KC_F4,KC_F5,KC_F6,KC_NO,KC_NO,KC_0,KC_NO,
	KC_NO,KC_NO,KC_F7,KC_F8,KC_F9,KC_F10,KC_F11,KC_F12,KC_NO,KC_NO,KC_NO,KC_NO,
	KC_NO,KC_NO,KC_NO,LT(_LOWER,KC_SPACE),KC_NO,KC_NO,KC_NO,KC_NO,LT(_RAISE,KC_ENT),KC_NO,KC_NO,KC_NO),
[_RAISE] = LAYOUT(
	KC_NO,KC_NO,KC_AT,KC_HASH,KC_DLR,KC_PERC,KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN,KC_NO,KC_DEL,
	KC_NO,KC_EXLM,KC_NO,KC_NO,KC_NO,KC_SCLN,MC_GRV,KC_PLUS,KC_LBRC,KC_RBRC,MC_CARET,KC_NO,
	KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_COLON,MC_TILD,KC_EQL,KC_LCBR,KC_RCBR,KC_NO,KC_NO,
	KC_NO,KC_NO,KC_NO,LT(_LOWER,KC_SPACE),KC_NO,KC_NO,KC_NO,KC_NO,LT(_RAISE,KC_ENT),KC_NO,KC_NO,KC_NO),
[_FUNCTION] = LAYOUT(
	COM_LOCK,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_HOME,KC_UP,KC_PGUP,KC_NO,QK_BOOT,
	KC_NO,KC_NO,KC_PSCR,KC_NO,KC_NO,KC_NO,LCTL(KC_LEFT),KC_LEFT,KC_DOWN,KC_RIGHT,LCTL(KC_RIGHT),KC_NO,
	KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,LSFT(LCTL(KC_LEFT)),KC_END,KC_NO,KC_PGDN,KC_NO,LSFT(LCTL(KC_RIGHT)),
	KC_NO,KC_NO,KC_NO,LT(_LOWER,KC_SPACE),KC_NO,KC_NO,KC_NO,KC_NO,LT(_RAISE,KC_ENT),KC_NO,KC_NO,KC_NO)
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
		case MC_DEL:
			if (record->event.pressed) {
				if (mods & MOD_MASK_SHIFT) {
					unregister_mods(MOD_MASK_SHIFT);  
					SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_HOME) SS_UP(X_LALT) SS_DOWN(X_LSFT) SS_TAP(X_DOWN) SS_UP(X_LSFT) SS_TAP(X_DELETE));
					register_mods(mods);
				} else {
					SEND_STRING(SS_TAP(X_BSPC));
				}
			}
			break;
		case MC_Y_Z:
			if (record->event.pressed) {
				yz_hold_timer=timer_read();
				register_mods(MOD_BIT(KC_LALT));
			} else {
				unregister_mods(MOD_BIT(KC_LALT));
				if (timer_elapsed(yz_hold_timer)<TAPPING_TERM){
					if (mods & MOD_MASK_CTRL) {
						SEND_STRING("z");
					} else {
						SEND_STRING("y");
					}
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
		case COM_LOCK:
			if (record->event.pressed) {
				SEND_STRING(SS_LGUI("l"));
			}
			break;
	}
    return true;
};

layer_state_t layer_state_set_user(layer_state_t state) {
	state=update_tri_layer_state(state, _LOWER, _RAISE, _FUNCTION);
	return state;
}
