#include "../lk_words.h"

enum layers {
  _QWERTY = 0,
  _LOWER,
  _FUNCTION,
  _SYSTEM
};

enum custom_keycodes {
    MC_GRV = SAFE_RANGE,
    MC_QUOT,
    MC_CARET,
    MC_TILD,
    MC_LEAD,
    MC_COMMA,
    MC_DOT,
    MC_COLON
};

const uint16_t PROGMEM cmb_auml[]={KC_A, KC_R,COMBO_END}; 
const uint16_t PROGMEM cmb_ouml[]={KC_O, KC_I,COMBO_END}; 
const uint16_t PROGMEM cmb_uuml[]={KC_U, KC_Y,COMBO_END}; 
const uint16_t PROGMEM cmb_szlig[]={KC_S, KC_T,COMBO_END}; 
const uint16_t PROGMEM cmb_euro[]={KC_E, KC_O,COMBO_END}; 
const uint16_t PROGMEM cmb_esc[]={KC_W, KC_F,COMBO_END}; 
combo_t key_combos[]={
     COMBO(cmb_auml, RALT(KC_Q)),
     COMBO(cmb_ouml, RALT(KC_P)),
     COMBO(cmb_uuml, RALT(KC_Y)),
     COMBO(cmb_szlig, RALT(KC_S)),
     COMBO(cmb_euro, LALT(LCTL(KC_5))),
     COMBO(cmb_esc, KC_ESC)
};

typedef struct {
    uint16_t key;
    const char *out;
} LeaderOneKey;
typedef struct {
    uint16_t key1;
    uint16_t key2;
    const char *out;
} LeaderTwoKey;

LeaderOneKey leaderOneKeys[]={
    {KC_TAB,    SS_DOWN(X_LCTL) SS_TAP(X_Z) SS_UP(X_LCTL)},
    {KC_Q,      SS_DOWN(X_LGUI) SS_TAP(X_L) SS_UP(X_LGUI)},
    {KC_W,      ":coffeezombie:"},
    {KC_F,      "- [ ] "},
    {KC_P,      ":puzzled:"},
    {KC_B,      ":think:"},
    {KC_J,      ":this-is-fine-fire:"},
    {KC_L,      ":man-shrugging:"},
    {KC_U,      SS_DOWN(X_LCTL) SS_TAP(X_X) SS_UP(X_LCTL) "/*" SS_TAP(X_ENTER) SS_DOWN(X_LCTL) SS_TAP(X_V) SS_UP(X_LCTL) "*/" SS_TAP(X_ENTER)},
    {KC_Y,      SS_TAP(X_HOME) SS_TAP(X_HOME) "// "},
    {MC_COLON,  SS_TAP(X_GRV) SS_TAP(X_GRV) SS_TAP(X_GRV) SS_TAP(X_SPC) SS_DOWN(X_LSFT) SS_TAP(X_ENTER) SS_UP(X_LSFT) SS_DOWN(X_LCTL) SS_TAP(X_V) SS_UP(X_LCTL) SS_DOWN(X_LSFT) SS_TAP(X_ENTER) SS_UP(X_LSFT) SS_TAP(X_GRV) SS_TAP(X_GRV) SS_TAP(X_GRV) SS_TAP(X_SPC)},
    {KC_BSPC,   SS_TAP(X_END) SS_DOWN(X_LSFT) SS_TAP(X_HOME) SS_TAP(X_HOME) SS_UP(X_LSFT) SS_TAP(X_DELETE) SS_TAP(X_DELETE)},
    // A needs special handling
    {KC_S,      SS_TAP(X_PSCR)},
    {KC_T,      ":machete:"},
    {KC_G,      ":homerdisappear:"},
    {KC_M,      ":homer_scream:"},
    {KC_N,      "()" SS_TAP(X_LEFT)},
    {KC_E,      "[]" SS_TAP(X_LEFT)},
    {KC_I,      "{}" SS_TAP(X_LEFT)},
    {KC_O,      "``" SS_TAP(X_LEFT)},
    
    {KC_Z,      SS_TAP(X_LSFT) SS_TAP(X_LSFT)},
    {KC_X,      "=>"},
    {KC_C,      ":D"},
    {KC_D,      ":)"},
    {KC_V,      ":("},
    {KC_K,      ":+1:"},
    {KC_H,      SS_TAP(X_CALC)},
    {MC_COMMA,  SS_DOWN(X_LGUI) "r" SS_UP(X_LGUI) SS_DELAY(100) "c:\\csp\\cmder\\Cmder.exe" SS_TAP(X_ENTER)},
    {MC_DOT,    SS_DOWN(X_LGUI) "r" SS_UP(X_LGUI) SS_DELAY(100) "c:\\csp\\cmder\\Cmder.exe" SS_DOWN(X_LSFT) SS_DOWN(X_LCTL) SS_TAP(X_ENTER) SS_UP(X_LCTL) SS_UP(X_LSFT)},
    {MC_QUOT,   "\"\"" SS_TAP(X_LEFT)},
    
    {KC_LCTL,   SS_DOWN(X_LSFT) SS_DOWN(X_LGUI) SS_TAP(X_LEFT) SS_UP(X_LGUI) SS_UP(X_LSFT)},
    {KC_MINUS,  SS_DOWN(X_LALT) SS_TAP(X_F4) SS_UP(X_LALT)},
    {KC_BSLS,   SS_DOWN(X_LALT) SS_DOWN(X_LCTL) SS_TAP(X_DEL) SS_UP(X_LCTL) SS_UP(X_LALT)},
    {KC_SLSH,   SS_DOWN(X_LSFT) SS_DOWN(X_LGUI) SS_TAP(X_RIGHT) SS_UP(X_LGUI) SS_UP(X_LSFT)},
};

// these are defined in lk_words.h
LeaderTwoKey leaderTwoKeys[]={
    {KC_E,KC_W, LK_EW},
    {KC_E,KC_P, LK_EP},
    
    {KC_N,KC_A, LK_NA},
    {KC_N,KC_T, LK_NT},
    {KC_N,KC_R, LK_NR},
    {KC_N,KC_S, LK_NS},
    {KC_N,KC_J, LK_NJ},
    {KC_N,KC_B, LK_NB},
    {KC_N,KC_K, LK_NK},
    {KC_N,KC_C, LK_NC}
};

bool leaderKeyPressed=false;
uint16_t MC_LEAD_TIMER = 0;

/*
 * base
 * ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
 * │Tab  │q    │w    │f    │p    │b    │j    │l    │u    │y    │: ;  │BkSp │
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
 * │        │     │systm│space      │lead │     return│systm│\ |  │/ ?     │
 * │Ctrl    │Alt  │     │lower      │Shift│       move│     │     │        │
 * └────────┴─────┴─────┴───────────┴─────┴───────────┴─────┴─────┴────────┘
 * lower
 * ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
 * │Tab  │6    │7    │8    │9    │0    │1    │2    │3    │4    │5    │Del  │
 * │     │     │     │     │     │     │     │     │     │     │     │     │
 * │     │     │     ├─────┤     │     │     │     ├─────┤     │     │     │
 * │     │     ├─────┤=    ├─────┤     │     ├─────┤[    ├─────┤     │     │
 * │     ├─────┤@    │     │*    ├─────┼─────┤(    │     │{    ├─────┤     │
 * │     │!    │     ├─────┤     │+    │-    │     ├─────┤     │<    │     │
 * │     │     ├─────┤^    ├─────┤     │     ├─────┤]    ├─────┤     │     │
 * ├─────┴─────┤%    │     │#    ├─────┼─────┤)    │     │}    ├─────┴─────┤
 * │      $    │     │     │     │&    │_    │     │     │     │>          │
 * │           │     │     │     │     │     │     │     │     │           │
 * ├────────┬──┴──┬──┴──┬──┴─────┴──┬──┴──┬──┴─────┴──┬──┴──┬──┴──┬────────┤
 * │        │     │     │space      │lead │     return│     │~    │:       │
 * │Ctrl    │Alt  │     │lower      │Shift│       move│     │     │        │
 * └────────┴─────┴─────┴───────────┴─────┴───────────┴─────┴─────┴────────┘
 * function
 * ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
 * │Tab  │F1   │F2   │F3   │F4   │F5   │Top  │PgUp │↑    │PgDwn│Bottm│Del  │
 * │     │     │     │     │     │     │     │     │     │     │     │     │
 * │     │     │     ├─────┤     │     │     │     ├─────┤     │     │     │
 * │     │     ├─────┤F8   ├─────┤     │     ├─────┤↓    ├─────┤     │     │
 * │     ├─────┤F7   │     │F9   ├─────┼─────┤←    │     │→    ├─────┤     │
 * │     │F6   │     ├─────┤     │F10  │Home │     ├─────┤     │End  │     │
 * │     │     ├─────┤CtrlX├─────┤     │     ├─────┤     ├─────┤     │     │
 * ├─────┴─────┤F12  │     │CtrlC├─────┼─────┤WrdLf│     │WrdRg├─────┴─────┤
 * │      F11  │     │     │     │CtrlV│SelWL│     │     │     │SelWR      │
 * │           │     │     │     │     │     │     │     │     │           │
 * ├────────┬──┴──┬──┴──┬──┴─────┴──┬──┴──┬──┴─────┴──┬──┴──┬──┴──┬────────┤
 * │        │     │     │           │lead │           │     │CtrlY│CtrlZ   │
 * │Ctrl    │Alt  │     │           │Shift│           │     │     │        │
 * └────────┴─────┴─────┴───────────┴─────┴───────────┴─────┴─────┴────────┘
 * leader one keys
 * ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
 * │CtrlZ│Lock │Emoji│- [ ]│Emoji│Emoji│Emoji│Emoji│Multi│Comnt│Multi│Del  │
 * │     │     │Coffe│     │puzzl│think│fine │shrug│Comnt│     │Line │Line │
 * │     │     │     ├─────┤     │     │     │     ├─────┤     │Code │     │
 * │     │     ├─────┤PrtSc├─────┤     │     ├─────┤[]   ├─────┤     │     │
 * │     ├─────┤     │     │Emoji├─────┼─────┤()   │     │{}   ├─────┤     │
 * │     │"avai│     ├─────┤Mache│Emoji│Emoji│     ├─────┤     │´´   │     │
 * │     │labi"├─────┤Emoji├─────┤Homer│screm├─────┤Cmder├─────┤     │     │
 * ├─────┴─────┤=>   │:D   │Emoji├─────┼─────┤Calc │     │Amd  ├─────┴─────┤
 * │Double     │     │     │:)   │Emoji│Emoji│     │     │Cmd  │""         │
 * │Shift      │     │     │     │:(   │+1   │     │     │     │           │
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
 * │        │     │     │           │     │           │     │     │        │
 * │        │     │     │           │     │           │     │     │        │
 * └────────┴─────┴─────┴───────────┴─────┴───────────┴─────┴─────┴────────┘ 
 */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT(
    KC_TAB, KC_Q, KC_W,   KC_F,       KC_P,               KC_B,   KC_J, KC_L,                KC_U,       KC_Y,   MC_COLON,KC_BSPC,
    KC_NO,  KC_A, KC_R,   KC_S,       KC_T,               KC_G,   KC_M, KC_N,                KC_E,       KC_I,   KC_O,    KC_NO,
    KC_Z,   KC_NO,KC_X,   KC_C,       KC_D,               KC_V,   KC_K, KC_H,                MC_COMMA,   MC_DOT, KC_NO,   MC_QUOT,
    KC_LCTL,KC_NO,KC_LALT,MO(_SYSTEM),LT(_LOWER,KC_SPACE),MC_LEAD,KC_NO,LT(_FUNCTION,KC_ENT),MO(_SYSTEM),KC_BSLS,KC_NO,   KC_SLSH),
[_LOWER] = LAYOUT(
    KC_TAB, KC_6,   KC_7,   KC_8,    KC_9,               KC_0,   KC_1,   KC_2,                KC_3,   KC_4,   KC_5, KC_DEL,
    KC_NO,  KC_EXLM,KC_AT,  KC_EQL,  KC_ASTR,            KC_PLUS,KC_MINS,KC_LPRN,             KC_LBRC,KC_LCBR,KC_LT,KC_NO,
    KC_DLR, KC_NO,  KC_PERC,MC_CARET,KC_HASH,            KC_AMPR,KC_UNDS,KC_RPRN,             KC_RBRC,KC_RCBR,KC_NO,KC_GT,
    KC_LCTL,KC_NO,  KC_LALT,KC_NO,   LT(_LOWER,KC_SPACE),MC_LEAD,KC_NO,  LT(_FUNCTION,KC_ENT),KC_NO,  MC_TILD,KC_NO,KC_COLON),
[_FUNCTION] = LAYOUT(
    KC_TAB, KC_F1,KC_F2,  KC_F3,     KC_F4,              KC_F5,     LCTL(KC_HOME),      KC_PGUP,             KC_UP,  KC_PGDN,       LCTL(KC_END),KC_DEL,
    KC_NO,  KC_F6,KC_F7,  KC_F8,     KC_F9,              KC_F10,    KC_HOME,            KC_LEFT,             KC_DOWN,KC_RIGHT,      KC_END,      KC_NO,
    KC_F11, KC_NO,KC_F12, LCTL(KC_X),LCTL(KC_C),         LCTL(KC_V),LSFT(LCTL(KC_LEFT)),LCTL(KC_LEFT),       KC_NO,  LCTL(KC_RIGHT),KC_NO,       LSFT(LCTL(KC_RIGHT)),
    KC_LCTL,KC_NO,KC_LALT,KC_NO,     LT(_LOWER,KC_SPACE),MC_LEAD,   KC_NO,              LT(_FUNCTION,KC_ENT),KC_NO,  LCTL(KC_Y),    KC_NO,       LCTL(KC_Z)),
[_SYSTEM] = LAYOUT(
    KC_SYSTEM_WAKE, QK_BOOT,KC_MPRV,KC_MPLY,    KC_MNXT,KC_VOLU,KC_MS_WH_UP,  KC_MS_WH_LEFT,KC_MS_UP,   KC_MS_WH_RIGHT,KC_MS_ACCEL2,AC_TOGG,
    KC_NO,          KC_NO,  KC_NO,  KC_MSTP,    KC_NO,  KC_VOLD,KC_MS_WH_DOWN,KC_MS_LEFT,   KC_MS_DOWN, KC_MS_RIGHT,   KC_MS_ACCEL1,KC_NO,
    KC_SYSTEM_SLEEP,KC_NO,  KC_NO,  KC_NO,      KC_NO,  KC_MUTE,KC_NO,        KC_MS_BTN1,   KC_MS_BTN3, KC_MS_BTN2,    KC_NO,       KC_MS_ACCEL0,
    KC_SYSTEM_POWER,KC_NO,  KC_NO,  MO(_SYSTEM),KC_NO,  KC_NO,  KC_NO,        KC_NO,        MO(_SYSTEM),KC_NO,         KC_NO,       KC_NO)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    const uint8_t mods = get_mods();
    if (record->event.pressed) leaderKeyPressed = true;
    switch (keycode) {
        case MC_QUOT:   if (record->event.pressed && !leader_sequence_active()) SEND_STRING(SS_TAP(X_QUOT) SS_TAP(X_SPC));  break;
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
        case MC_COLON:
            if (record->event.pressed && !leader_sequence_active()) {
				if (mods & MOD_MASK_SHIFT) {
                    unregister_code(KC_LSFT);
                    SEND_STRING(";"); 
                    register_code(KC_LSFT);
                } else {
                    SEND_STRING(":");
                }
			}
            break;
    }
    return true;
};

void leader_end_user(void) {
    int i;
    for(i=0;i<sizeof(leaderOneKeys)/sizeof(leaderOneKeys[0]);i++)
        if(leader_sequence_one_key(leaderOneKeys[i].key)) {SEND_STRING(leaderOneKeys[i].out);return;}
    for(i=0;i<sizeof(leaderTwoKeys)/sizeof(leaderTwoKeys[0]);i++)
        if(leader_sequence_two_keys(leaderTwoKeys[i].key1,leaderTwoKeys[i].key2)) {SEND_STRING(leaderTwoKeys[i].out);return;}
    // everything not handled falls through and can be special-handled here
    if(leader_sequence_one_key(KC_A)) {
        if (get_mods() & MOD_MASK_SHIFT)
            SEND_STRING("Availability");
        else
            SEND_STRING("availability");
        return;
    }
}
