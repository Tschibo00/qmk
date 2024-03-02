#include QMK_KEYBOARD_H

enum layers {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _FUNCTION,
  _MAGIC
};

enum custom_keycodes {
    MC_GRV = SAFE_RANGE,
	MC_QUOT,
	COM_MULTI_COMMENT,
	COM_COMMENT,
	COM_BRK,
	COM_SBRK,
	COM_CBRK,
	COM_DQUOT,
	COM_LOCK,
	COM_CMDER,
	COM_ADMIN_CMDER,
	MC_CARET,
	MC_DEL,
	MC_TILD,
	MC_COFFEE,
	MC_EXCEPTION,
	MC_RENE,
	MC_THISFINE,
	MC_PUZZLED,
	MC_THINK,
	MC_AVAILABILITY,
	MC_SMILED,
	MC_SMILEH,
	MC_SMILES,
	MC_HOMER,
	MC_SCREAM,
	MC_MACHETE,
	MC_PLUSONE,
	MC_ARROW
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
 * ├─────┴─────┤     │     │     ├─────┼─────┤     │     │     ├─────┴─────┤
 * │           │     │     │     │     │     │     │     │     │           │
 * │           │     │     │     │     │     │     │     │     │           │
 * ├────────┬──┴──┬──┴─────┴─────┴─────┴─────┴─────┴─────┴──┬──┴──┬────────┤
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
 * ├─────┴─────┤     │     │     ├─────┼─────┤     │     │     ├─────┴─────┤
 * │           │     │     │     │     │     │     │     │     │           │
 * │           │     │     │     │     │     │     │     │     │           │
 * ├────────┬──┴──┬──┴──┬──┴─────┴──┬──┴──┬──┴─────┴──┬──┴──┬──┴──┬────────┤
 * │        │     │     │           │     │           │     │     │        │
 * │        │     │     │           │     │           │     │     │        │
 * └────────┴─────┴─────┴───────────┴─────┴───────────┴─────┴─────┴────────┘
 * keymap (. are not used points in matrix)
 * xxxxxxxxxxxx
 * xxxxxxxxxxxx
 * x.xxxxxxxx.x
 * x.xxxx.xxx.x
*/

/*
 * base
 * ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
 * │Tab  │q    │w    │e    │r    │t    │z    │u    │i    │o    │p    │BkSp │
 * │     │     │     │     │     │     │     │     │     │     │     │     │
 * │     │     │     ├─────┤     │     │     │     ├─────┤     │     │     │
 * │     │     ├─────┤d    ├─────┤     │     ├─────┤k    ├─────┤     │     │
 * │     ├─────┤s    │     │f    ├─────┼─────┤j    │     │l    ├─────┤     │
 * │     │a    │     ├─────┤     │g    │h    │     ├─────┤     │; :  │     │
 * │Shift│     ├─────┤c    ├─────┤     │     ├─────┤, <  ├─────┤     │     │
 * ├─────┴─────┤x    │     │v    ├─────┼─────┤m    │     │. >  ├─────┴─────┤
 * │      y    │     │     │     │b    │n    │     │     │     │' "        │
 * │Shift      │     │     │     │     │     │     │     │     │           │
 * ├────────┬──┴──┬──┴─────┴─────┴─────┴─────┴─────┴─────┴──┬──┴──┬────────┤
 * │Esc     │- _  │space                              return│\ |  │/ ?     │
 * │Ctrl    │Alt  │lower            function           raise│     │        │
 * └────────┴─────┴─────────────────────────────────────────┴─────┴────────┘
 * lower
 * ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
 * │Tab  │1    │2    │3    │4    │5    │6    │7    │8    │9    │0    │Del  │
 * │     │     │     │     │     │     │     │     │     │     │     │     │
 * │     │     │     ├─────┤     │     │     │     ├─────┤     │     │     │
 * │     │     ├─────┤F3   ├─────┤     │     ├─────┤     ├─────┤     │     │
 * │     ├─────┤F2   │     │F4   ├─────┼─────┤     │     │     ├─────┤     │
 * │     │F1   │     ├─────┤     │F5   │F6   │     ├─────┤     │     │     │
 * │Shift│     ├─────┤F9   ├─────┤     │     ├─────┤     ├─────┤     │     │
 * ├─────┴─────┤F8   │     │F10  ├─────┼─────┤     │     │     ├─────┴─────┤
 * │      F7   │     │     │     │F11  │F12  │     │     │     │           │
 * │           │     │     │     │     │     │     │     │     │           │
 * ├────────┬──┴──┬──┴─────┴─────┴─────┴─────┴─────┴─────┴──┬──┴──┬────────┤
 * │Esc     │     │space                              return│     │        │
 * │Ctrl    │Alt  │lower            function           raise│     │        │
 * └────────┴─────┴─────────────────────────────────────────┴─────┴────────┘
 * raise
 * ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
 * │Tab  │!    │@    │#    │$    │%    │^    │&    │*    │(    │)    │Del  │
 * │     │     │     │     │     │     │     │     │     │     │     │     │
 * │     │     │     ├─────┤     │     │     │     ├─────┤     │     │     │
 * │     │     ├─────┤     ├─────┤     │     ├─────┤+    ├─────┤     │     │
 * │     ├─────┤     │     │     ├─────┼─────┤-    │     │[    ├─────┤     │
 * │     │     │     ├─────┤     │;    │`    │     ├─────┤     │]    │     │
 * │Shift│     ├─────┤     ├─────┤     │     ├─────┤=    ├─────┤     │     │
 * ├─────┴─────┤     │     │     ├─────┼─────┤_    │     │{    ├─────┴─────┤
 * │Esc        │     │     │     │:    │~    │     │     │     │}          │
 * │Shift      │     │     │     │     │     │     │     │     │           │
 * ├────────┬──┴──┬──┴─────┴─────┴─────┴─────┴─────┴─────┴──┬──┴──┬────────┤
 * │        │     │space                              return│     │        │
 * │Ctrl    │Alt  │lower            function           raise│     │        │
 * └────────┴─────┴─────────────────────────────────────────┴─────┴────────┘
 * function
 * ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
 * │     │     │     │     │     │     │Top  │PgUp │↑    │PgDwn│Bottm│Del  │
 * │     │     │     │     │     │     │     │     │     │     │     │     │
 * │     │     │     ├─────┤     │     │     │     ├─────┤     │     │     │
 * │     │     ├─────┤     ├─────┤     │     ├─────┤↓    ├─────┤     │     │
 * │     ├─────┤     │     │     ├─────┼─────┤←    │     │→    ├─────┤     │
 * │     │     │     ├─────┤     │     │Home │     ├─────┤     │End  │     │
 * │Shift│     ├─────┤     ├─────┤     │     ├─────┤     ├─────┤     │     │
 * ├─────┴─────┤     │     │     ├─────┼─────┤WrdLf│     │WrdRg├─────┴─────┤
 * │           │     │     │     │     │SelWL│     │     │     │SelWR      │
 * │Shift      │     │     │     │     │     │     │     │     │           │
 * ├────────┬──┴──┬──┴─────┴─────┴─────┴─────┴─────┴─────┴──┬──┴──┬────────┤
 * │WinLf   │     │space                              return│     │WinRg   │
 * │        │     │lower            function           raise│     │        │
 * └────────┴─────┴─────────────────────────────────────────┴─────┴────────┘
 * magic
 * ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
 * │Multi│Lock │Emoji│"Exce│"Rene│Emoji│Emoji│Emoji│     │()   │     │Ctl  │
 * │Line │     │Coffe│exce"│     │fine │puzzl│think│     │     │     │Alt  │
 * │Comnt│     │     ├─────┤     │     │     │     ├─────┤     │     │Del  │
 * │     │     ├─────┤Emoji├─────┤     │     ├─────┤     ├─────┤     │     │
 * │     ├─────┤PrtSc│:D   │Emoji├─────┼─────┤Emoji│     │[]   ├─────┤     │
 * │     │"avai│     ├─────┤:)   │Emoji│Emoji│screm├─────┤     │´´   │     │
 * │     │labi"├─────┤Calc ├─────┤:(   │Homer├─────┤ =>  ├─────┤     │     │
 * ├─────┴─────┤Cmder│     │     ├─────┼─────┤Emoji│     │{}   ├─────┴─────┤
 * │AmdCmd     │     │     │     │     │Emoji│Mache│     │     │""         │
 * │           │     │     │     │     │+1   │     │     │     │           │
 * ├────────┬──┴──┬──┴─────┴─────┴─────┴─────┴─────┴─────┴──┬──┴──┬────────┤
 * │Boot    │AltF4│                                         │     │        │
 * │        │     │                                         │     │        │
 * └────────┴─────┴─────────────────────────────────────────┴─────┴────────┘
 */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT(
	LSFT_T(KC_TAB),	KC_Q,	KC_W,				KC_E,					KC_R,	KC_T,	KC_Y,	KC_U,	KC_I,				KC_O,		KC_P,		MC_DEL,
	KC_NO, 			KC_A,	KC_S,				KC_D,					KC_F,	KC_G,	KC_H,	KC_J,	KC_K,				KC_L,		KC_SCLN,  	KC_NO,
	LSFT_T(KC_Z),	KC_NO,	KC_X,				KC_C,					KC_V,	KC_B,	KC_N,	KC_M,	KC_COMMA, 			KC_DOT,		KC_NO,		MC_QUOT,
	LCTL_T(KC_ESC),	KC_NO,	LALT_T(KC_MINUS),	LT(_LOWER,KC_SPACE),	KC_NO,	KC_NO,	KC_NO,	KC_NO,	LT(_RAISE,KC_ENT),	KC_BSLS,	KC_NO,		LT(_MAGIC,KC_SLSH)),
[_LOWER] = LAYOUT(
	LSFT_T(KC_TAB),	KC_1,	KC_2,		KC_3,				KC_4,	KC_5,	KC_6,	KC_7,	KC_8,				KC_9,	KC_0,	KC_DEL,
	KC_NO,			KC_F1,	KC_F2,		KC_F3,				KC_F4,	KC_F5,	KC_F6,	KC_NO,	KC_NO,				KC_NO,	KC_NO,	KC_NO,
	LSFT_T(KC_F7),			KC_NO,	KC_F8,		KC_F9,				KC_F10,	KC_F11,	KC_F12,	KC_NO,	KC_NO,				KC_NO,	KC_NO,	KC_NO,
	LCTL_T(KC_ESC),	KC_NO,	KC_LALT,	LT(_LOWER,KC_SPACE),KC_NO,	KC_NO,	KC_NO,	KC_NO,	LT(_RAISE,KC_ENT),	KC_NO,	KC_NO,	KC_NO),
[_RAISE] = LAYOUT(
	LSFT_T(KC_TAB),	KC_EXLM,KC_AT,	KC_HASH,			KC_DLR,	KC_PERC,	MC_CARET,	KC_AMPR,KC_ASTR,			KC_LPRN,KC_RPRN,KC_DEL,
	KC_NO,			KC_NO,	KC_NO,	KC_NO,				KC_NO,	KC_SCLN,	MC_GRV,		KC_MINS,KC_PLUS,			KC_LBRC,KC_RBRC,KC_NO,
	KC_LSFT,		KC_NO,	KC_NO,	KC_NO,				KC_NO,	KC_COLON,	MC_TILD,	KC_UNDS,KC_EQL,				KC_LCBR,KC_NO,	KC_RCBR,
	LCTL_T(KC_ESC),	KC_NO,	KC_LALT,LT(_LOWER,KC_SPACE),KC_NO,	KC_NO,		KC_NO,		KC_NO,	LT(_RAISE,KC_ENT),	KC_NO,	KC_NO,	KC_NO),
[_FUNCTION] = LAYOUT(
	KC_LSFT,			KC_NO,KC_NO,	KC_NO,				KC_NO,KC_NO,LCTL(KC_HOME),		KC_PGUP,		KC_UP,				KC_PGDN,		LCTL(KC_END),	KC_DEL,
	KC_NO,				KC_NO,KC_PSCR,	KC_NO,				KC_NO,KC_NO,KC_HOME,			KC_LEFT,		KC_DOWN,			KC_RIGHT,		KC_END,			KC_NO,
	KC_LSFT,			KC_NO,KC_NO,	KC_NO,				KC_NO,KC_NO,LSFT(LCTL(KC_LEFT)),LCTL(KC_LEFT),	KC_NO,				LCTL(KC_RIGHT),	KC_NO,			LSFT(LCTL(KC_RIGHT)),
	LSFT(LGUI(KC_LEFT)),KC_NO,KC_NO,	LT(_LOWER,KC_SPACE),KC_NO,KC_NO,KC_NO,				KC_NO,			LT(_RAISE,KC_ENT),	KC_NO,			KC_NO,			LSFT(LGUI(KC_RIGHT))),
[_MAGIC] = LAYOUT(
	COM_MULTI_COMMENT,	COM_LOCK,			MC_COFFEE,	MC_EXCEPTION,	MC_RENE,	MC_THISFINE,MC_PUZZLED,	MC_THINK,	KC_NO,		COM_BRK,	KC_NO,		LALT(LCTL(KC_DEL)),
	KC_NO,				MC_AVAILABILITY, 	KC_PSCR,  	MC_SMILED,		MC_SMILEH, 	MC_SMILES,  MC_HOMER,  	MC_SCREAM, 	KC_NO,		COM_SBRK,	COM_COMMENT,KC_NO,
	COM_ADMIN_CMDER,	KC_NO,				COM_CMDER,	KC_CALC,		KC_NO,		KC_NO,		MC_PLUSONE,	MC_MACHETE,	MC_ARROW, 	COM_CBRK,	KC_NO,		COM_DQUOT,
	QK_BOOT,			KC_NO,				LALT(KC_F4),KC_NO,			KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO)
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
		case COM_MULTI_COMMENT:
			if (record->event.pressed) {
				SEND_STRING(SS_TAP(X_GRV) SS_TAP(X_GRV) SS_TAP(X_GRV) SS_TAP(X_SPC) SS_DOWN(X_LSFT) SS_TAP(X_ENTER) SS_UP(X_LSFT) SS_DOWN(X_LCTL) SS_TAP(X_V) SS_UP(X_LCTL) SS_DOWN(X_LSFT) SS_TAP(X_ENTER) SS_UP(X_LSFT) SS_TAP(X_GRV) SS_TAP(X_GRV) SS_TAP(X_GRV) SS_TAP(X_SPC));
			}
			break;
		case COM_COMMENT:
			if (record->event.pressed) {
				SEND_STRING("``" SS_TAP(X_LEFT));
			}
			break;
		case COM_CMDER:
			if (record->event.pressed) {
				SEND_STRING(SS_LGUI("r"));
				wait_ms(100);
				SEND_STRING("c:\\csp\\cmder\\Cmder.exe" SS_TAP(X_ENTER));
			}
			break;
		case COM_ADMIN_CMDER:
			if (record->event.pressed) {
				SEND_STRING(SS_LGUI("r"));
				wait_ms(100);
				SEND_STRING("c:\\csp\\cmder\\Cmder.exe" SS_DOWN(X_LSFT) SS_DOWN(X_LCTL) SS_TAP(X_ENTER) SS_UP(X_LCTL) SS_UP(X_LSFT));
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
					SEND_STRING(SS_TAP(X_END) SS_DOWN(X_LSFT) SS_TAP(X_HOME) SS_TAP(X_HOME) SS_UP(X_LSFT) SS_TAP(X_DELETE) SS_TAP(X_DELETE));
					register_mods(mods);
				} else {
					SEND_STRING(SS_TAP(X_BSPC));
				}
			}
			break;
		case COM_LOCK:
			if (record->event.pressed) {
				SEND_STRING(SS_LGUI("l"));
			}
			break;
		case MC_COFFEE: if (record->event.pressed) SEND_STRING(":coffeezombie:"); break;
		case MC_EXCEPTION: if (record->event.pressed) SEND_STRING("exception: Exception"); break;
		case MC_RENE: if (record->event.pressed) SEND_STRING("Ren" SS_TAP(X_QUOTE) "e"); break;
		case MC_THISFINE: if (record->event.pressed) SEND_STRING(":this-is-fine-fire:"); break;
		case MC_PUZZLED: if (record->event.pressed) SEND_STRING(":puzzled:"); break;
		case MC_THINK: if (record->event.pressed) SEND_STRING(":think:"); break;
		case MC_AVAILABILITY: if (record->event.pressed) {
				if (mods & MOD_MASK_SHIFT)
					SEND_STRING("Availability");
				else
					SEND_STRING("availability");
			}
			break;
		case MC_SMILED: if (record->event.pressed) SEND_STRING(":D"); break;
		case MC_SMILEH: if (record->event.pressed) SEND_STRING(":)"); break;
		case MC_SMILES: if (record->event.pressed) SEND_STRING(":("); break;
		case MC_HOMER: if (record->event.pressed) SEND_STRING(":homerdisappear:"); break;
		case MC_SCREAM: if (record->event.pressed) SEND_STRING(":homer_scream:"); break;
		case MC_MACHETE: if (record->event.pressed) SEND_STRING(":machete:"); break;
		case MC_PLUSONE: if (record->event.pressed) SEND_STRING(":+1:"); break;
		case MC_ARROW: if (record->event.pressed) SEND_STRING("=>"); break;
	}
    return true;
};

layer_state_t layer_state_set_user(layer_state_t state) {
	state=update_tri_layer_state(state, _LOWER, _RAISE, _FUNCTION);
	return state;
}
