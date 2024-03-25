#include "../lk_words.h"
#include "../LeaderKeys.h"

enum layers {
  _BASE = 0,
  _NUMSYM,
  _NAVFN,
  _SYSTEM
};

enum custom_keycodes {
    MC_GRV = SAFE_RANGE,
    MC_QUOT,
    MC_CARET,
    MC_TILD,
    MC_LEAD,
    MC_COMMA,
    MC_DOT
};

const uint16_t PROGMEM cmb_auml[]=  {KC_A, KC_R,COMBO_END}; 
const uint16_t PROGMEM cmb_ouml[]=  {KC_O, KC_I,COMBO_END}; 
const uint16_t PROGMEM cmb_uuml[]=  {KC_U, KC_Y,COMBO_END}; 
const uint16_t PROGMEM cmb_szlig[]= {KC_S, KC_T,COMBO_END}; 
const uint16_t PROGMEM cmb_euro[]=  {KC_E, KC_O,COMBO_END}; 
const uint16_t PROGMEM cmb_esc[]=   {KC_W, KC_F,COMBO_END}; 
const uint16_t PROGMEM cmb_caps[]=  {KC_B, KC_J,COMBO_END}; 
combo_t key_combos[]={
     COMBO(cmb_auml,    RALT(KC_Q)),
     COMBO(cmb_ouml,    RALT(KC_P)),
     COMBO(cmb_uuml,    RALT(KC_Y)),
     COMBO(cmb_szlig,   RALT(KC_S)),
     COMBO(cmb_euro,    LALT(LCTL(KC_5))),
     COMBO(cmb_esc,     KC_ESC),
     COMBO(cmb_caps,    QK_CAPS_WORD_TOGGLE)
};
 
LeaderOneKey leaderOneKeys[]={
    {KC_Q,      SS_DOWN(X_LGUI) SS_TAP(X_L) SS_UP(X_LGUI)},
    {KC_M,      "- [ ] "},
    {KC_J,      SS_DOWN(X_LCTL) SS_TAP(X_X) SS_UP(X_LCTL) "/*" SS_TAP(X_ENTER) SS_DOWN(X_LCTL) SS_TAP(X_V) SS_UP(X_LCTL) "*/" SS_TAP(X_ENTER)},
    {KC_B,      SS_TAP(X_HOME) SS_TAP(X_HOME) "// "},
    {KC_L,      SS_TAP(X_GRV) SS_TAP(X_GRV) SS_TAP(X_GRV) SS_TAP(X_SPC) SS_DOWN(X_LSFT) SS_TAP(X_ENTER) SS_UP(X_LSFT) SS_DOWN(X_LCTL) SS_TAP(X_V) SS_UP(X_LCTL) SS_DOWN(X_LSFT) SS_TAP(X_ENTER) SS_UP(X_LSFT) SS_TAP(X_GRV) SS_TAP(X_GRV) SS_TAP(X_GRV) SS_TAP(X_SPC)},
    {KC_P,      SS_TAP(X_END) SS_DOWN(X_LSFT) SS_TAP(X_HOME) SS_TAP(X_HOME) SS_UP(X_LSFT) SS_TAP(X_DELETE) SS_TAP(X_DELETE)},
    {KC_S,      SS_TAP(X_PSCR)},
    {KC_N,      "()" SS_TAP(X_LEFT)},
    {KC_E,      "[]" SS_TAP(X_LEFT)},
    {KC_I,      "{}" SS_TAP(X_LEFT)},
    {KC_O,      "``" SS_TAP(X_LEFT)},
    {KC_A,      "=>"},
    {KC_C,      SS_TAP(X_CALC)},
    {KC_X,      SS_DOWN(X_LGUI) "r" SS_UP(X_LGUI) SS_DELAY(100) "c:\\csp\\cmder\\Cmder.exe" SS_TAP(X_ENTER)},
    {KC_Z,      SS_DOWN(X_LGUI) "r" SS_UP(X_LGUI) SS_DELAY(100) "c:\\csp\\cmder\\Cmder.exe" SS_DOWN(X_LSFT) SS_DOWN(X_LCTL) SS_TAP(X_ENTER) SS_UP(X_LCTL) SS_UP(X_LSFT)},
    {MC_QUOT,   "\"\"" SS_TAP(X_LEFT)},
    {KC_LCTL,   SS_DOWN(X_LSFT) SS_DOWN(X_LGUI) SS_TAP(X_LEFT) SS_UP(X_LGUI) SS_UP(X_LSFT)},
    {KC_MINUS,  SS_DOWN(X_LALT) SS_TAP(X_F4) SS_UP(X_LALT)},
    {KC_BSLS,   SS_DOWN(X_LALT) SS_DOWN(X_LCTL) SS_TAP(X_DEL) SS_UP(X_LCTL) SS_UP(X_LALT)},
    {KC_SLSH,   SS_DOWN(X_LSFT) SS_DOWN(X_LGUI) SS_TAP(X_RIGHT) SS_UP(X_LGUI) SS_UP(X_LSFT)},
    {KC_D,      SS_DOWN(X_LCTL) SS_TAP(X_C) SS_UP(X_LCTL)},
    {KC_V,      SS_DOWN(X_LCTL) SS_TAP(X_X) SS_UP(X_LCTL)},
    {KC_K,      SS_DOWN(X_LALT) SS_DOWN(X_LCTL) SS_TAP(X_V) SS_UP(X_LCTL) SS_UP(X_LALT)},
    {KC_H,      SS_DOWN(X_LCTL) SS_TAP(X_V) SS_UP(X_LCTL)},
    {KC_COMMA,  SS_DOWN(X_LSFT) SS_DOWN(X_LCTL) SS_TAP(X_V) SS_UP(X_LCTL) SS_UP(X_LSFT)},
};

// these are defined in lk_words.h, example:
/*
LeaderTwoKey leaderTwoKeys[]={
    LK1(KC_E, KC_T, "test"),                    // only one variant of word
    LK2(KC_E, KC_T, "test", "Test"),            // normal variant plus shifted (trigger lead key with Ctrl)
    LK3(KC_E, KC_T, "test", "Test", "TEST")     // full variant (like LK2 plus additional capsed version when triggering with Alt)
};
*/

bool leaderKeyPressed=false;
uint16_t MC_LEAD_TIMER = 0;

/*
 * base
 * ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
 * │Tab  │q    │w    │f    │p    │b    │j    │l    │u    │y    │- _  │BkSp │
 * │     │     │     │     │     │     │     │     │     │     │     │     │
 * │     │     │     ├─────┤     │     │     │     ├─────┤     │     │     │
 * │     │     ├─────┤s    ├─────┤     │     ├─────┤e    ├─────┤     │     │
 * │     ├─────┤r    │     │t    ├─────┼─────┤n    │     │i    ├─────┤     │
 * │     │a    │     ├─────┤     │g    │m    │     ├─────┤     │o    │     │
 * │     │     ├─────┤c    ├─────┤     │     ├─────┤, ?  ├─────┤     │     │
 * ├─────┴─────┤x    │     │d    ├─────┼─────┤h    │     │. !  ├─────┴─────┤
 * │      z    │     │     │     │v    │k    │     │     │     │' "        │
 * │           │     │     │     │     │     │     │     │     │           │
 * ├────────┬──┴──┬──┴──┬──┴─────┴──┬──┴──┬──┴─────┴──┬──┴──┬──┴──┬────────┤
 * │        │     │sys  │space      │lead │     return│sys  │\ |  │/ ?     │
 * │Ctrl    │Alt  │     │num sym    │Shift│     nav fn│     │     │        │
 * └────────┴─────┴─────┴───────────┴─────┴───────────┴─────┴─────┴────────┘
 * number/symbol
 * ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
 * │Tab  │6    │7    │8    │9    │0    │1    │2    │3    │4    │5    │Del  │
 * │     │     │     │     │     │     │     │     │     │     │     │     │
 * │     │     │     ├─────┤     │     │     │     ├─────┤     │     │     │
 * │     │     ├─────┤=    ├─────┤     │     ├─────┤[    ├─────┤     │     │
 * │     ├─────┤@    │     │*    ├─────┼─────┤(    │     │{    ├─────┤     │
 * │     │!    │     ├─────┤     │+    │:    │     ├─────┤     │<    │     │
 * │     │     ├─────┤^    ├─────┤     │     ├─────┤]    ├─────┤     │     │
 * ├─────┴─────┤%    │     │#    ├─────┼─────┤)    │     │}    ├─────┴─────┤
 * │      $    │     │     │     │&    │;    │     │     │     │>          │
 * │           │     │     │     │     │     │     │     │     │           │
 * ├────────┬──┴──┬──┴──┬──┴─────┴──┬──┴──┬──┴─────┴──┬──┴──┬──┴──┬────────┤
 * │        │     │     │space      │lead │     return│     │~    │:       │
 * │Ctrl    │Alt  │     │num sym    │Shift│     nav fn│     │     │        │
 * └────────┴─────┴─────┴───────────┴─────┴───────────┴─────┴─────┴────────┘
 * navigation/function
 * ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
 * │Tab  │F1   │F2   │F3   │F4   │F5   │Top  │PgUp │↑    │PgDwn│Bottm│Del  │
 * │     │     │     │     │     │     │     │     │     │     │     │     │
 * │     │     │     ├─────┤     │     │     │     ├─────┤     │     │     │
 * │     │     ├─────┤F8   ├─────┤     │     ├─────┤↓    ├─────┤     │     │
 * │     ├─────┤F7   │     │F9   ├─────┼─────┤←    │     │→    ├─────┤     │
 * │     │F6   │     ├─────┤     │F10  │Home │     ├─────┤     │End  │     │
 * │     │     ├─────┤     ├─────┤     │     ├─────┤     ├─────┤     │     │
 * ├─────┴─────┤F12  │     │     ├─────┼─────┤WrdLf│     │WrdRg├─────┴─────┤
 * │      F11  │     │     │     │     │SelWL│     │     │     │SelWR      │
 * │           │     │     │     │     │     │     │     │     │           │
 * ├────────┬──┴──┬──┴──┬──┴─────┴──┬──┴──┬──┴─────┴──┬──┴──┬──┴──┬────────┤
 * │        │     │     │space      │lead │     return│     │     │        │
 * │Ctrl    │Alt  │     │num sym    │Shift│     nav fn│     │     │        │
 * └────────┴─────┴─────┴───────────┴─────┴───────────┴─────┴─────┴────────┘
 * leader one keys (for two-or-more leader key combos see lk_words.h)
 * ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
 * │     │Lock │     │Doubl│´´   │Comnt│Multi│Multi│     │     │     │Del  │
 * │     │     │     │Shift│     │     │Comnt│Line │     │     │     │Line │
 * │     │     │     ├─────┤     │     │     │Code ├─────┤     │     │     │
 * │     │     ├─────┤PrtSc├─────┤     │     ├─────┤[]   ├─────┤     │     │
 * │     ├─────┤     │     │     ├─────┼─────┤()   │     │{}   ├─────┤     │
 * │     │=>   │     ├─────┤     │     │- [ ]│     ├─────┤     │     │     │
 * │     │     ├─────┤Calc ├─────┤     │     ├─────┤Shift├─────┤     │     │
 * ├─────┴─────┤Cmder│     │CtrlC├─────┼─────┤CtrlV│CtrlV│     ├─────┴─────┤
 * │      Amd  │     │     │     │CtrlX│Alt  │     │     │     │""         │
 * │      Cmd  │     │     │     │     │CtrlV│     │     │     │           │
 * ├────────┬──┴──┬──┴──┬──┴─────┴──┬──┴──┬──┴─────┴──┬──┴──┬──┴──┬────────┤
 * │WinLf   │AltF4│     │           │lead │           │     │CtlAl│WinRg   │
 * │        │     │     │           │Shift│           │     │Del  │        │
 * └────────┴─────┴─────┴───────────┴─────┴───────────┴─────┴─────┴────────┘
 * system
 * ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
 * │power│Boot │track│play │track│vol  │mseWh│mseWh│mouse│mseWh│mouse│toggl│
 * │wake │     │prev │pause│next │up   │up   │left │up   │right│acc2 │auto │
 * │     │     │     ├─────┤     │     │     │     ├─────┤     │     │corre│
 * │     │     ├─────┤stop ├─────┤     │     ├─────┤mouse├─────┤     │     │
 * │     ├─────┤     │     │     ├─────┼─────┤mouse│down │mouse├─────┤     │
 * │     │     │     ├─────┤     │vol  │mseWh│left ├─────┤right│mouse│     │
 * │     │     ├─────┤     ├─────┤down │down ├─────┤mouse├─────┤acc1 │     │
 * ├─────┴─────┤     │     │     ├─────┼─────┤mouse│btn3 │mouse├─────┴─────┤
 * │power      │     │     │     │mute │     │btn1 │     │btn2 │mouse      │
 * │sleep      │     │     │     │     │     │     │     │     │acc0       │
 * ├────────┬──┴──┬──┴──┬──┴─────┴──┬──┴──┬──┴─────┴──┬──┴──┬──┴──┬────────┤
 * │power   │     │     │           │     │           │     │     │        │
 * │off     │     │     │           │     │           │     │     │        │
 * └────────┴─────┴─────┴───────────┴─────┴───────────┴─────┴─────┴────────┘ 
 * combos
 * ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
 * │     │     │  +=Esc=+  │     │     │     │     │  +==ü==+  │     │     │
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
 * │        │     │     │    +======system=======+    │     │     │        │
 * │        │     │     │           │     │           │     │     │        │
 * └────────┴─────┴─────┴───────────┴─────┴───────────┴─────┴─────┴────────┘ 
 */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BASE] = LAYOUT(
    KC_TAB,         KC_Q,   KC_W,   KC_F,       KC_P,                KC_B,      KC_J,               KC_L,             KC_U,       KC_Y,          KC_MINUS,    KC_BSPC,
    KC_NO,          KC_A,   KC_R,   KC_S,       KC_T,                KC_G,      KC_M,               KC_N,             KC_E,       KC_I,          KC_O,        KC_NO,
    KC_Z,           KC_NO,  KC_X,   KC_C,       KC_D,                KC_V,      KC_K,               KC_H,             MC_COMMA,   MC_DOT,        KC_NO,       MC_QUOT,
    KC_LCTL,        KC_NO,  KC_LALT,MO(_SYSTEM),LT(_NUMSYM,KC_SPACE),MC_LEAD,   KC_NO,              LT(_NAVFN,KC_ENT),MO(_SYSTEM),KC_BSLS,       KC_NO,       KC_SLSH),
[_NUMSYM] = LAYOUT(
    KC_TAB,         KC_6,   KC_7,   KC_8,       KC_9,                KC_0,      KC_1,               KC_2,             KC_3,       KC_4,          KC_5,        KC_DEL,
    KC_NO,          KC_EXLM,KC_AT,  KC_EQL,     KC_ASTR,             KC_PLUS,   KC_COLON,           KC_LPRN,          KC_LBRC,    KC_LCBR,       KC_LT,       KC_NO,
    KC_DLR,         KC_NO,  KC_PERC,MC_CARET,   KC_HASH,             KC_AMPR,   KC_SCLN,            KC_RPRN,          KC_RBRC,    KC_RCBR,       KC_NO,       KC_GT,
    KC_LCTL,        KC_NO,  KC_LALT,KC_NO,      LT(_NUMSYM,KC_SPACE),MC_LEAD,   KC_NO,              LT(_NAVFN,KC_ENT),KC_NO,      MC_TILD,       KC_NO,       KC_COLON),
[_NAVFN] = LAYOUT(
    KC_TAB,         KC_F1,  KC_F2,  KC_F3,      KC_F4,               KC_F5,     LCTL(KC_HOME),      KC_PGUP,          KC_UP,      KC_PGDN,       LCTL(KC_END),KC_DEL,
    KC_NO,          KC_F6,  KC_F7,  KC_F8,      KC_F9,               KC_F10,    KC_HOME,            KC_LEFT,          KC_DOWN,    KC_RIGHT,      KC_END,      KC_NO,
    KC_F11,         KC_NO,  KC_F12, KC_NO,      KC_NO,               KC_NO,     LSFT(LCTL(KC_LEFT)),LCTL(KC_LEFT),    KC_NO,      LCTL(KC_RIGHT),KC_NO,       LSFT(LCTL(KC_RIGHT)),
    KC_LCTL,        KC_NO,  KC_LALT,KC_NO,      LT(_NUMSYM,KC_SPACE),MC_LEAD,   KC_NO,              LT(_NAVFN,KC_ENT),KC_NO,      KC_NO,         KC_NO,       KC_NO),
[_SYSTEM] = LAYOUT(
    KC_SYSTEM_WAKE, QK_BOOT,KC_MPRV,KC_MPLY,    KC_MNXT,             KC_VOLU,   KC_MS_WH_UP,        KC_MS_WH_LEFT,    KC_MS_UP,   KC_MS_WH_RIGHT,KC_MS_ACCEL2,AC_TOGG,
    KC_NO,          KC_NO,  KC_NO,  KC_MSTP,    KC_NO,               KC_VOLD,   KC_MS_WH_DOWN,      KC_MS_LEFT,       KC_MS_DOWN, KC_MS_RIGHT,   KC_MS_ACCEL1,KC_NO,
    KC_SYSTEM_SLEEP,KC_NO,  KC_NO,  KC_NO,      KC_NO,               KC_MUTE,   KC_NO,              KC_MS_BTN1,       KC_MS_BTN3, KC_MS_BTN2,    KC_NO,       KC_MS_ACCEL0,
    KC_SYSTEM_POWER,KC_NO,  KC_NO,  MO(_SYSTEM),KC_NO,               KC_NO,     KC_NO,              KC_NO,            MO(_SYSTEM),KC_NO,         KC_NO,       KC_NO)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    const uint8_t mods = get_mods();
    if (record->event.pressed) leaderKeyPressed = true;
    switch (keycode) {
        case MC_GRV:    if (record->event.pressed) SEND_STRING(SS_TAP(X_GRV) SS_TAP(X_SPC));                                break;
        case MC_TILD:   if (record->event.pressed) SEND_STRING(SS_DOWN(X_LSFT) SS_TAP(X_GRV) SS_TAP(X_SPC) SS_UP(X_LSFT));  break;
        case MC_CARET:  if (record->event.pressed) SEND_STRING(SS_LSFT("6") SS_TAP(X_SPC));                                 break;
        case MC_LEAD:
            if (record->event.pressed) {
                register_code(KC_LSFT);
                leaderKeyPressed = false; 
                MC_LEAD_TIMER = timer_read();
            } else {
                unregister_code(KC_LSFT);
                if (leaderKeyPressed) break;
                if (timer_elapsed(MC_LEAD_TIMER) < TAPPING_TERM) leader_start();
            }
            break;
        case MC_QUOT:   if (record->event.pressed && !leader_sequence_active()) SEND_STRING(SS_TAP(X_QUOT) SS_TAP(X_SPC));  break;
        case MC_COMMA:
            if (record->event.pressed && !leader_sequence_active()) {
				if (mods & MOD_MASK_SHIFT) {
                    unregister_code(KC_LSFT);
                    SEND_STRING("?"); 
                    register_code(KC_LSFT);
                } else {
                    SEND_STRING(",");
                }
			}
            break;
        case MC_DOT:
            if (record->event.pressed && !leader_sequence_active()) {
				if (mods & MOD_MASK_SHIFT) {
                    unregister_code(KC_LSFT);
                    SEND_STRING("!"); 
                    register_code(KC_LSFT);
                } else {
                    SEND_STRING(".");
                }
			}
            break;
    }
    return true;
};

void leader_end_user(void) {
    const uint8_t mods = get_mods();
    int i;
    clear_mods();
    for (i=0; i<sizeof(leaderOneKeys)/sizeof(leaderOneKeys[0]); i++)
        if (leader_sequence_one_key(leaderOneKeys[i].key)) {SEND_STRING(leaderOneKeys[i].out); return;}
    for (i=0; i<sizeof(leaderTwoKeys)/sizeof(leaderTwoKeys[0]); i++)
        if (leader_sequence_two_keys(leaderTwoKeys[i].key1, leaderTwoKeys[i].key2)) {
            if (mods & MOD_MASK_CTRL) {SEND_STRING(leaderTwoKeys[i].outShifted); return;}
            if (mods & MOD_MASK_ALT) {SEND_STRING(leaderTwoKeys[i].outCapsed); return;}
            SEND_STRING(leaderTwoKeys[i].out); 
            return;
        }
    // everything not handled falls through and can be special-handled here
    set_mods(mods);
}

layer_state_t layer_state_set_user(layer_state_t state) {
	state=update_tri_layer_state(state, _NUMSYM, _NAVFN, _SYSTEM);
	return state;
}
