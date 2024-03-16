#include QMK_KEYBOARD_H

enum layers {
  _QWERTY = 0,
  _LOWER,
  _FUNCTION,
  _MAGIC,
  _SYSTEM
};

enum custom_keycodes {
    MC_GRV = SAFE_RANGE,
	MC_QUOT,
	COM_MULTI_CODE,
	COM_CODE,
	COM_BRK,
	COM_SBRK,
	COM_CBRK,
	COM_DQUOT,
	COM_LOCK,
	COM_CMDER,
	COM_ADMIN_CMDER,
    COM_DOUBLE_SHIFT,
	MC_CARET,
	MC_DELLINE,
	MC_TILD,
	MC_COFFEE,
	MC_ENUM,
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
	MC_ARROW,
    MC_COMMENT,
    MC_MULTI_COMMENT,
    MC_SHRUG
};

const uint16_t PROGMEM cmb_auml[]={KC_A, KC_R,COMBO_END}; 
const uint16_t PROGMEM cmb_ouml[]={KC_O, KC_I,COMBO_END}; 
const uint16_t PROGMEM cmb_uuml[]={KC_U, KC_Y,COMBO_END}; 
const uint16_t PROGMEM cmb_szlig[]={KC_S, KC_T,COMBO_END}; 
const uint16_t PROGMEM cmb_euro[]={KC_E, KC_O,COMBO_END}; 
combo_t key_combos[5]={
     COMBO(cmb_auml, RALT(KC_Q)),
     COMBO(cmb_ouml, RALT(KC_P)),
     COMBO(cmb_uuml, RALT(KC_Y)),
     COMBO(cmb_szlig, RALT(KC_S)),
     COMBO(cmb_euro, LALT(LCTL(KC_5)))
};

/*
 * base
 * ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
 * │Tab  │q    │w    │f    │p    │b    │j    │l    │u    │y    │; :  │BkSp │
 * │     │     │     │     │     │     │     │     │     │     │     │     │
 * │     │     │     ├─────┤     │     │     │     ├─────┤     │     │     │
 * │     │     ├─────┤s    ├─────┤     │     ├─────┤e    ├─────┤     │     │
 * │     ├─────┤r    │     │t    ├─────┼─────┤n    │     │i    ├─────┤     │
 * │     │a    │     ├─────┤     │g    │m    │     ├─────┤     │o    │     │
 * │Shift│     ├─────┤c    ├─────┤     │     ├─────┤, <  ├─────┤     │     │
 * ├─────┴─────┤x    │     │d    ├─────┼─────┤h    │     │. >  ├─────┴─────┤
 * │      z    │     │     │     │v    │k    │     │     │     │' "        │
 * │Shift      │     │     │     │     │     │     │     │     │           │
 * ├────────┬──┴──┬──┴──┬──┴─────┴──┬──┴──┬──┴─────┴──┬──┴──┬──┴──┬────────┤
 * │Esc     │- _  │systm│space      │magic│     return│systm│\ |  │/ ?     │
 * │Ctrl    │Alt  │     │lower      │     │       move│     │     │        │
 * └────────┴─────┴─────┴───────────┴─────┴───────────┴─────┴─────┴────────┘
 * lower
 * ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
 * │Tab  │6    │7    │8    │9    │0    │1    │2    │3    │4    │5    │Del  │
 * │     │     │     │     │     │     │     │     │     │     │     │     │
 * │     │     │     ├─────┤     │     │     │     ├─────┤     │     │     │
 * │     │     ├─────┤=    ├─────┤     │     ├─────┤[    ├─────┤     │     │
 * │     ├─────┤@    │     │*    ├─────┼─────┤(    │     │{    ├─────┤     │
 * │     │!    │     ├─────┤     │+    │-    │     ├─────┤     │:    │     │
 * │Shift│     ├─────┤^    ├─────┤     │     ├─────┤]    ├─────┤     │     │
 * ├─────┴─────┤$    │     │#    ├─────┼─────┤)    │     │}    ├─────┴─────┤
 * │           │     │     │     │&    │_    │     │     │     │"          │
 * │Shift      │     │     │     │     │     │     │     │     │           │
 * ├────────┬──┴──┬──┴──┬──┴─────┴──┬──┴──┬──┴─────┴──┬──┴──┬──┴──┬────────┤
 * │Esc     │     │     │space      │magic│     return│     │`    │~       │
 * │Ctrl    │Alt  │     │lower      │     │       move│     │     │        │
 * └────────┴─────┴─────┴───────────┴─────┴───────────┴─────┴─────┴────────┘
 * function
 * ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
 * │Tab  │F1   │F2   │F3   │F4   │F5   │Top  │PgUp │↑    │PgDwn│Bottm│Del  │
 * │     │     │     │     │     │     │     │     │     │     │     │     │
 * │     │     │     ├─────┤     │     │     │     ├─────┤     │     │     │
 * │     │     ├─────┤F8   ├─────┤     │     ├─────┤↓    ├─────┤     │     │
 * │     ├─────┤F7   │     │F9   ├─────┼─────┤←    │     │→    ├─────┤     │
 * │     │F6   │     ├─────┤     │F10  │Home │     ├─────┤     │End  │     │
 * │Shift│     ├─────┤     ├─────┤     │     ├─────┤     ├─────┤     │     │
 * ├─────┴─────┤F12  │     │     ├─────┼─────┤WrdLf│     │WrdRg├─────┴─────┤
 * │      F11  │     │     │     │     │SelWL│     │     │     │SelWR      │
 * │Shift      │     │     │     │     │     │     │     │     │           │
 * ├────────┬──┴──┬──┴──┬──┴─────┴──┬──┴──┬──┴─────┴──┬──┴──┬──┴──┬────────┤
 * │Esc     │     │     │           │magic│           │     │     │        │
 * │Ctrl    │Alt  │     │           │     │           │     │     │        │
 * └────────┴─────┴─────┴───────────┴─────┴───────────┴─────┴─────┴────────┘
 * magic
 * ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
 * │CtrlZ│Lock │Emoji│- [ ]│Emoji│Emoji│Emoji│Emoji│Multi│Comnt│Multi│Del  │
 * │     │     │Coffe│     │puzzl│think│fine │shrug│Comnt│     │Line │Line 
 r│
 * │     │     │     ├─────┤     │     │     │     ├─────┤     │Code │     │
 * │     │     ├─────┤PrtSc├─────┤     │     ├─────┤[]   ├─────┤     │     │
 * │     ├─────┤"René│     │Emoji├─────┼─────┤()   │     │{}   ├─────┤     │
 * │     │"avai│     ├─────┤Mache│Emoji│Emoji│     ├─────┤     │´´   │     │
 * │     │labi"├─────┤Emoji├─────┤Homer│screm├─────┤Cmder├─────┤     │     │
 * ├─────┴─────┤=>   │:D   │Emoji├─────┼─────┤Calc │     │Amd  ├─────┴─────┤
 * │Double     │     │     │:)   │Emoji│Emoji│     │     │Cmd  │""         │
 * │Shift      │     │     │     │:(   │+1   │     │     │     │           │
 * ├────────┬──┴──┬──┴──┬──┴─────┴──┬──┴──┬──┴─────┴──┬──┴──┬──┴──┬────────┤
 * │WinLf   │AltF4│Boot │           │magic│           │     │CtlAl│WinRg   │
 * │        │     │     │           │     │           │     │Del  │        │
 * └────────┴─────┴─────┴───────────┴─────┴───────────┴─────┴─────┴────────┘
 * system
 * ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
 * │     │     │track│play │track│vol  │mseWh│mseWh│mouse│mseWh│mouse│toggl│
 * │     │     │prev │pause│next │up   │up   │left │up   │right│acc2 │auto │
 * │     │     │     ├─────┤     │     │     │     ├─────┤     │     │corre│
 * │     │     ├─────┤stop ├─────┤     │     ├─────┤mouse├─────┤     │     │
 * │     ├─────┤     │     │     ├─────┼─────┤mouse│down │mouse├─────┤     │
 * │     │     │     ├─────┤     │vol  │mseWh│left ├─────┤right│mouse│     │
 * │     │     ├─────┤     ├─────┤down │down ├─────┤mouse├─────┤acc1 │     │
 * ├─────┴─────┤     │     │     ├─────┼─────┤mouse│btn3 │mouse├─────┴─────┤
 * │           │     │     │     │mute │     │btn1 │     │btn2 │mouse      │
 * │           │     │     │     │     │     │     │     │     │acc0       │
 * ├────────┬──┴──┬──┴──┬──┴─────┴──┬──┴──┬──┴─────┴──┬──┴──┬──┴──┬────────┤
 * │        │     │     │           │     │           │     │     │        │
 * │        │     │     │           │     │           │     │     │        │
 * └────────┴─────┴─────┴───────────┴─────┴───────────┴─────┴─────┴────────┘ 
 * combos
 * ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
 * │     │     │     │     │     │     │     │     │     ü     │     │     │
 * │     │     │     │     │     │     │     │     │     │     │     │     │
 * │     │     │     ├─────┤     │     │     │     ├─────┤     │     │     │
 * │     │     ├─────┤     ├─────┤     │     ├─────┤     ├─────┤     │     │
 * │     ├─────┤     │  +==ß==+  ├─────┼─────┤     │  +=====€==\─────┤     │
 * │     │  +==ä==+  ├─────┤     │     │     │     ├─────┤  +=ö \=+  │     │
 * │     │     ├─────┤     ├─────┤     │     ├─────┤     ├─────\==+  │     │
 * ├─────┴─────┤     │     │     ├─────┼─────┤     │     │     ├─────┴─────┤
 * │           │     │     │     │     │     │     │     │     │           │
 * │           │     │     │     │     │     │     │     │     │           │
 * ├────────┬──┴──┬──┴──┬──┴─────┴──┬──┴──┬──┴─────┴──┬──┴──┬──┴──┬────────┤
 * │        │     │     │           │     │           │     │     │        │
 * │        │     │     │           │     │           │     │     │        │
 * └────────┴─────┴─────┴───────────┴─────┴───────────┴─────┴─────┴────────┘ 
 */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT(
	LSFT_T(KC_TAB),	KC_Q,	KC_W,				KC_F,	    KC_P,				KC_B,		KC_J,	KC_L,			    	KC_U,		KC_Y,	KC_SCLN,KC_BSPC,
	KC_NO, 			KC_A,	KC_R,				KC_S,	    KC_T,				KC_G,		KC_M,	KC_N,			    	KC_E,		KC_I,	KC_O,   KC_NO,
	LSFT_T(KC_Z),	KC_NO,	KC_X,				KC_C,	    KC_D,				KC_V,		KC_K,	KC_H,				    KC_COMMA, 	KC_DOT,	KC_NO,	MC_QUOT,
	LCTL_T(KC_ESC),	KC_NO,	LALT_T(KC_MINUS),	MO(_SYSTEM),LT(_LOWER,KC_SPACE),MO(_MAGIC),	KC_NO,	LT(_FUNCTION,KC_ENT),	MO(_SYSTEM),KC_BSLS,KC_NO,	KC_SLSH),
[_LOWER] = LAYOUT(
	LSFT_T(KC_TAB),	KC_6,	KC_7,	KC_8,	    KC_9,				KC_0,		KC_1,	    KC_2,				    KC_3,	KC_4,	KC_5,	    KC_DEL,
	KC_NO,			KC_EXLM,KC_AT,	KC_EQL,     KC_ASTR,			KC_PLUS,	KC_MINS,	KC_LPRN,		        KC_LBRC,KC_LCBR,KC_COLON,   KC_NO,
	KC_LSFT,		KC_NO,	KC_DLR,	MC_CARET,   KC_HASH,			KC_AMPR,	KC_UNDS,    KC_RPRN,			    KC_RBRC,KC_RCBR,KC_NO,	    COM_DQUOT,
	LCTL_T(KC_ESC),	KC_NO,	KC_LALT,KC_NO,	    LT(_LOWER,KC_SPACE),MO(_MAGIC),	KC_NO,	    LT(_FUNCTION,KC_ENT),	KC_NO,	MC_GRV, KC_NO,	    MC_TILD),
[_FUNCTION] = LAYOUT(
	LSFT_T(KC_TAB),	KC_F1,  KC_F2,	            KC_F3,	KC_F4,              KC_F5,      LCTL(KC_HOME),		KC_PGUP,		        KC_UP,	KC_PGDN,		LCTL(KC_END),	KC_DEL,
	KC_NO,			KC_F6,  KC_F7,	            KC_F8,	KC_F9,              KC_F10,     KC_HOME,			KC_LEFT,		        KC_DOWN,KC_RIGHT,		KC_END,			KC_NO,
	LSFT_T(KC_F11),	KC_F12, KC_NO,	            KC_NO,	KC_NO,              KC_NO,      LSFT(LCTL(KC_LEFT)),LCTL(KC_LEFT),	        KC_NO,	LCTL(KC_RIGHT),	KC_NO,			LSFT(LCTL(KC_RIGHT)),
	LCTL_T(KC_ESC),	KC_NO,	LALT_T(KC_MINUS),	KC_NO,	LT(_LOWER,KC_SPACE),MO(_MAGIC),	KC_NO,	            LT(_FUNCTION,KC_ENT),	KC_NO,	KC_NO,	        KC_NO,			KC_NO),
[_MAGIC] = LAYOUT(
	LCTL(KC_Z),	        COM_LOCK,			MC_COFFEE,	MC_ENUM,	MC_PUZZLED,	MC_THINK,   MC_THISFINE,MC_SHRUG,	MC_MULTI_COMMENT,	MC_COMMENT,	        COM_MULTI_CODE,	MC_DELLINE,
	KC_NO,				MC_AVAILABILITY, 	MC_RENE,  	KC_PSCR,	MC_MACHETE, MC_HOMER,   MC_SCREAM,  COM_BRK, 	COM_SBRK,		    COM_CBRK,	        COM_CODE,       KC_NO,
	COM_DOUBLE_SHIFT,  	KC_NO,				MC_ARROW,	MC_SMILED,	MC_SMILEH,	MC_SMILES,	MC_PLUSONE,	KC_CALC,	COM_CMDER, 	        COM_ADMIN_CMDER,    KC_NO,		    COM_DQUOT,
	LSFT(LGUI(KC_LEFT)),KC_NO,				LALT(KC_F4),QK_BOOT,	KC_NO,		MO(_MAGIC),	KC_NO,		KC_NO,		KC_NO,		        LALT(LCTL(KC_DEL)),	KC_NO,		    LSFT(LGUI(KC_RIGHT))),
[_SYSTEM] = LAYOUT(
	KC_NO,  KC_NO,  KC_MPRV,KC_MPLY,    KC_MNXT,KC_VOLU,KC_MS_WH_UP,    KC_MS_WH_LEFT,  KC_MS_UP,   KC_MS_WH_RIGHT, KC_MS_ACCEL2,   AC_TOGG,
	KC_NO,  KC_NO,  KC_NO,  KC_MSTP,    KC_NO,  KC_VOLD,KC_MS_WH_DOWN,  KC_MS_LEFT,     KC_MS_DOWN, KC_MS_RIGHT,    KC_MS_ACCEL1,   KC_NO,
	KC_NO,  KC_NO,  KC_NO,  KC_NO,      KC_NO,  KC_MUTE,KC_NO,          KC_MS_BTN1,     KC_MS_BTN3, KC_MS_BTN2,     KC_NO,          KC_MS_ACCEL0,
	KC_NO,  KC_NO,  KC_NO,  MO(_SYSTEM),KC_NO,  KC_NO,  KC_NO,          KC_NO,          MO(_SYSTEM),KC_NO,          KC_NO,          KC_NO)
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
		case COM_MULTI_CODE:
			if (record->event.pressed) {
				SEND_STRING(SS_TAP(X_GRV) SS_TAP(X_GRV) SS_TAP(X_GRV) SS_TAP(X_SPC) SS_DOWN(X_LSFT) SS_TAP(X_ENTER) SS_UP(X_LSFT) SS_DOWN(X_LCTL) SS_TAP(X_V) SS_UP(X_LCTL) SS_DOWN(X_LSFT) SS_TAP(X_ENTER) SS_UP(X_LSFT) SS_TAP(X_GRV) SS_TAP(X_GRV) SS_TAP(X_GRV) SS_TAP(X_SPC));
			}
			break;
		case COM_CODE:
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
		case MC_DELLINE:
			if (record->event.pressed) SEND_STRING(SS_TAP(X_END) SS_DOWN(X_LSFT) SS_TAP(X_HOME) SS_TAP(X_HOME) SS_UP(X_LSFT) SS_TAP(X_DELETE) SS_TAP(X_DELETE)); break;
		case COM_LOCK:
			if (record->event.pressed) {
				SEND_STRING(SS_LGUI("l"));
			}
			break;
        case COM_DOUBLE_SHIFT: if (record->event.pressed) SEND_STRING(SS_TAP(X_LSFT) SS_TAP(X_LSFT)); break;
		case MC_COFFEE: if (record->event.pressed) SEND_STRING(":coffeezombie:"); break;
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
		case MC_COMMENT: if (record->event.pressed) SEND_STRING(SS_TAP(X_HOME) SS_TAP(X_HOME) "// "); break;
		case MC_MULTI_COMMENT: if (record->event.pressed) SEND_STRING(SS_DOWN(X_LCTL) SS_TAP(X_X) SS_UP(X_LCTL) "/*" SS_TAP(X_ENTER) SS_DOWN(X_LCTL) SS_TAP(X_V) SS_UP(X_LCTL) "*/" SS_TAP(X_ENTER)); break;
		case MC_SHRUG: if (record->event.pressed) SEND_STRING(":man-shrugging:"); break;
        case MC_ENUM: if (record->event.pressed) SEND_STRING("- [ ] "); break;

	}
    return true;
};
