#include QMK_KEYBOARD_H

enum layers {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _FUNCTION
};

enum custom_keycodes {
    MC_GRV = SAFE_RANGE,
	COM_BRK,
	COM_SBRK,
	COM_CBRK,
	COM_DQUOT,
	MC_CARET,
	MC_DEL,
	MC_TILD,
	MC_Y_Z,
	MC_Z_Y,
	MC_SPACE_UNDER,
	MC_QUOT_CTRL
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

static uint16_t lastUpdate=0;
static uint8_t currentState;
static bool alreadyShowingLogo=false;
static uint16_t space_hold_timer;
static uint16_t quot_hold_timer;
static uint16_t del_hold_timer;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*    [_QWERTY] = LAYOUT(				// layer -
        LALT_T(KC_ESC), KC_Q,   KC_W, KC_E, KC_R, KC_T, MC_DEL,            MC_Z_Y, KC_U, KC_I,     KC_O,   KC_P,    LALT_T(KC_MINUS),
        LSFT_T(KC_TAB), KC_A,   KC_S, KC_D, KC_F, KC_G, LT(_LOWER,KC_ENT), KC_H,   KC_J, KC_K,     KC_L,   KC_SCLN, LSFT_T(KC_PLUS),
        MC_QUOT_CTRL,   MC_Y_Z, KC_X, KC_C, KC_V, KC_B, MC_SPACE_UNDER,    KC_N,   KC_M, KC_COMMA, KC_DOT, KC_SLSH, LCTL_T(KC_BSLS)
    ),
    [_LOWER] = LAYOUT_ortho_3x13(				// lower
		MC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_DEL,            MC_CARET, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_LALT,
		KC_LSFT, KC_NO,   KC_NO, KC_NO,   KC_NO,  KC_NO,   LT(_LOWER,KC_ENT), KC_NO,    KC_NO,   KC_NO,   KC_LBRC, KC_RBRC, KC_LSFT,
		KC_LCTL, KC_NO,   KC_NO, KC_NO,   KC_NO,  KC_NO,   MC_SPACE_UNDER,    KC_NO,    KC_NO,   KC_NO,   KC_LCBR, KC_RCBR, KC_LCTL
    ),
    [_RAISE] = LAYOUT_ortho_3x13(				// raise
		MC_GRV,  KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_DEL,            KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_LALT,
		KC_LSFT, KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  LT(_LOWER,KC_ENT), KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_LSFT,
		KC_LCTL, KC_F11, KC_F12, KC_F13, KC_F14, KC_F15, MC_SPACE_UNDER,    KC_F16, KC_F17, KC_F18, KC_F19, KC_F20, KC_LCTL
    ),
    [_FUNCTION] = LAYOUT_ortho_3x13(			// function
		QK_BOOT,   RGB_TOG,       RGB_MOD,        RGB_HUD, RGB_HUI, KC_NO, MC_DEL,         KC_NO, KC_HOME, KC_UP,   KC_PGUP,  COM_BRK,  COM_BRK,
		QK_RBT,    DB_TOGG,       KC_NO,          RGB_SAD, RGB_SAI, KC_NO, TG(_GAME),      KC_NO, KC_LEFT, KC_DOWN, KC_RIGHT, COM_SBRK, COM_SBRK,
		COM_DQUOT, LGUI(KC_LEFT), LGUI(KC_RIGHT), RGB_VAD, RGB_VAI, KC_NO, MC_SPACE_UNDER, KC_NO, KC_END,  KC_NO,   KC_PGDN,  COM_CBRK, COM_CBRK
    ),
    [_GAME] = LAYOUT_ortho_3x13(				// game
		KC_ESC,  KC_1,    KC_2,  KC_3, KC_4, KC_5,  KC_DEL, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_LALT, 
		KC_NO,   KC_NO,   KC_A,  KC_W, KC_E, KC_R,  TG(_GAME),            KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_LSFT, 
		KC_LSFT, KC_LCTL, KC_NO, KC_S, KC_D, KC_NO, MC_SPACE_UNDER,       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_LCTL
    )*/
[_QWERTY] = LAYOUT(
	KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,
	KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,
	KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,
	KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO),
[_LOWER] = LAYOUT(
	KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,
	KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,
	KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,
	KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO),
[_RAISE] = LAYOUT(
	KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,
	KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,
	KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,
	KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO),
[_FUNCTION] = LAYOUT(
	KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,
	KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,
	KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,
	KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    const uint8_t mods = get_mods();
    switch (keycode) {
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
				del_hold_timer=timer_read();
				layer_on(_FUNCTION);
			} else {
				layer_off(_FUNCTION);
				if (timer_elapsed(del_hold_timer)<TAPPING_TERM){
					if (mods & MOD_MASK_SHIFT) {  // Is shift held?
						unregister_mods(MOD_MASK_SHIFT);  
						SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_HOME) SS_UP(X_LALT) SS_DOWN(X_LSFT) SS_TAP(X_DOWN) SS_UP(X_LSFT) SS_TAP(X_DELETE));
						register_mods(mods);
					} else {
						SEND_STRING(SS_TAP(X_BSPC));
					}
				}
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
		case MC_SPACE_UNDER:
			if (record->event.pressed) {
				space_hold_timer=timer_read();
				layer_on(_RAISE);
			} else {
				layer_off(_RAISE);
				if (timer_elapsed(space_hold_timer)<TAPPING_TERM){
					if (mods & MOD_MASK_SHIFT) {
						SEND_STRING(SS_TAP(X_MINUS));
					} else {
						SEND_STRING(SS_TAP(X_SPACE));
					}
				}
			}
			break;
		case MC_QUOT_CTRL:
			if (record->event.pressed) {
				quot_hold_timer=timer_read();
				register_mods(MOD_BIT(KC_LCTL));
			} else {
				unregister_mods(MOD_BIT(KC_LCTL));
				if (timer_elapsed(quot_hold_timer)<TAPPING_TERM){
					SEND_STRING(SS_TAP(X_QUOT) SS_TAP(X_SPC));
				}
			}
			break;
	}
    return true;
};
