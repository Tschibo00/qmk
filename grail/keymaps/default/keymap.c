#include "../lk_words.h"
#include "../LeaderKeys.h"
#include "timer.h"

enum layers {
  _BASE = 0,
  _NUMSYM,
  _NAVFN,
  _SYSTEM,
  _CMD
};

enum custom_keycodes {
    MC_GRV = SAFE_RANGE,
    MC_QUOT,
    MC_CARET,
    MC_TILD,
    MC_COMMA,
    MC_DOT,
    MC_EQL_BKSL,
    MC_ASTR_PIP,
    MC_PLUS_SLSH,
    MC_SBR_COMMA,
    MC_CBR_DOT,
    MC_LT
};

#define ___ KC_NO

// This is the magic leader keycode
#define UNICORN     LT(_NUMSYM,KC_CAPS)
#define DELLINE     KC_OUT
#define DELWORD     KC_OPER
#define MC_COMMA    KC_CLAG
#define MC_DOT      KC_CRSL
#define MC_QUOT     KC_EXSL
#define MC_NAV_CMD  LT(_NAVFN, KC_PRIR)
#define MC_Z        MT(MOD_LGUI,KC_Z)
#define MC_X        MT(MOD_LALT,KC_X)
#define MC_C        MT(MOD_LCTL,KC_C)
#define MC_V        MT(MOD_LSFT,KC_V)
#define MC_M        MT(MOD_LSFT,KC_M)
#define MMC_COMMA   MT(MOD_LCTL,MC_COMMA)
#define MMC_DOT     MT(MOD_LALT,MC_DOT)
#define MMC_QUOT    MT(MOD_LGUI,MC_QUOT)

const uint16_t PROGMEM cmb_caps[]=      {KC_T, KC_Y, COMBO_END}; 
const uint16_t PROGMEM cmb_tab[]=       {KC_D, KC_F, COMBO_END}; 
const uint16_t PROGMEM cmb_sfttab[]=    {KC_E, KC_R, COMBO_END}; 
const uint16_t PROGMEM cmb_bksp[]=      {KC_K, KC_L, COMBO_END}; 
const uint16_t PROGMEM cmb_del[]=       {KC_I, KC_O, COMBO_END}; 
const uint16_t PROGMEM cmb_bksp_left[]= {KC_D, KC_S, COMBO_END}; 
const uint16_t PROGMEM cmb_del_left[]=  {KC_W, KC_E, COMBO_END}; 
const uint16_t PROGMEM cmb_delword[]=   {MMC_COMMA, MMC_DOT, COMBO_END};
const uint16_t PROGMEM cmb_delline[]=   {MMC_DOT, MMC_QUOT, COMBO_END};
const uint16_t PROGMEM cmb_ctlx[]=      {MC_Z, MC_X, COMBO_END};
const uint16_t PROGMEM cmb_ctlc[]=      {MC_X, MC_C, COMBO_END};
const uint16_t PROGMEM cmb_ctlv[]=      {MC_C, MC_V, COMBO_END};
combo_t key_combos[]={
     COMBO(cmb_caps,     QK_CAPS_WORD_TOGGLE),
     COMBO(cmb_tab,      KC_TAB),
     COMBO(cmb_sfttab,   LSFT(KC_TAB)),
     COMBO(cmb_bksp,     KC_BSPC),
     COMBO(cmb_del,      KC_DEL),
     COMBO(cmb_bksp_left,KC_BSPC),
     COMBO(cmb_del_left, KC_DEL),
     COMBO(cmb_delword,  DELWORD),
     COMBO(cmb_delline,  DELLINE),
     COMBO(cmb_ctlx,     LCTL(KC_X)),
     COMBO(cmb_ctlc,     LCTL(KC_C)),
     COMBO(cmb_ctlv,     LCTL(KC_V)),
};

LeaderOneKey leaderOneKeys[]={
    {KC_Q,      SS_DOWN(X_LGUI) SS_TAP(X_L) SS_UP(X_LGUI)},
    {KC_H,      "- [ ] "},
    {KC_Y,      SS_DOWN(X_LSFT) SS_DOWN(X_LCTL) SS_TAP(X_PSLS) SS_UP(X_LCTL) SS_UP(X_LSFT)},
    {KC_T,      SS_DOWN(X_LCTL) SS_TAP(X_X) SS_UP(X_LCTL) "/*" SS_TAP(X_ENTER) SS_DOWN(X_LCTL) SS_TAP(X_V) SS_UP(X_LCTL) "*/" SS_TAP(X_ENTER)},
    {KC_R,      SS_TAP(X_HOME) SS_TAP(X_HOME) "// "},
    {KC_U,      SS_TAP(X_GRV) SS_TAP(X_GRV) SS_TAP(X_GRV) SS_TAP(X_SPC) SS_DOWN(X_LSFT) SS_TAP(X_ENTER) SS_UP(X_LSFT) SS_DOWN(X_LCTL) SS_TAP(X_V) SS_UP(X_LCTL) SS_DOWN(X_LSFT) SS_TAP(X_ENTER) SS_UP(X_LSFT) SS_TAP(X_GRV) SS_TAP(X_GRV) SS_TAP(X_GRV) SS_TAP(X_SPC)},
    {KC_S,      SS_DOWN(X_LGUI) SS_TAP(X_R) SS_UP(X_LGUI)},
    {KC_D,      SS_TAP(X_PSCR)},
    {KC_J,      "()" SS_TAP(X_LEFT)},
    {KC_K,      "[]" SS_TAP(X_LEFT)},
    {KC_L,      "{}" SS_TAP(X_LEFT)},
    {KC_P,      "``" SS_TAP(X_LEFT)},
    {KC_A,      "->"},
    {MC_QUOT,   "\"\"" SS_TAP(X_LEFT)},
    {KC_SPACE,  SS_DOWN(X_LSFT) SS_DOWN(X_LGUI) SS_TAP(X_LEFT) SS_UP(X_LGUI) SS_UP(X_LSFT)},
    {KC_PRIR,   SS_DOWN(X_LSFT) SS_DOWN(X_LGUI) SS_TAP(X_RIGHT) SS_UP(X_LGUI) SS_UP(X_LSFT)},
    {KC_MINUS,  SS_DOWN(X_LALT) SS_TAP(X_F4) SS_UP(X_LALT)},
    {KC_BSLS,   SS_DOWN(X_LALT) SS_DOWN(X_LCTL) SS_TAP(X_DEL) SS_UP(X_LCTL) SS_UP(X_LALT)},
    {KC_C,      SS_DOWN(X_LCTL) SS_TAP(X_C) SS_UP(X_LCTL)},
    {KC_V,      SS_DOWN(X_LCTL) SS_TAP(X_X) SS_UP(X_LCTL)},
    {KC_N,      SS_DOWN(X_LALT) SS_DOWN(X_LCTL) SS_TAP(X_V) SS_UP(X_LCTL) SS_UP(X_LALT)},
    {KC_B,      SS_DOWN(X_LCTL) SS_TAP(X_V) SS_UP(X_LCTL)},
    {KC_M,      SS_DOWN(X_LSFT) SS_DOWN(X_LCTL) SS_TAP(X_V) SS_UP(X_LCTL) SS_UP(X_LSFT)},
    {KC_BSPC,   SS_TAP(X_END) SS_DOWN(X_LSFT) SS_TAP(X_HOME) SS_TAP(X_HOME) SS_UP(X_LSFT) SS_TAP(X_DELETE) SS_TAP(X_DELETE)},
    {KC_E,      SS_TAP(X_LSFT) SS_TAP(X_LSFT)},
    {KC_F,      SS_DOWN(X_LGUI) SS_DOWN(X_LALT) SS_TAP(X_K) SS_UP(X_LALT) SS_UP(X_LGUI)},
    {KC_TAB,    SS_DOWN(X_LALT) SS_TAP(X_TAB) SS_UP(X_LALT)},
    {KC_ENT,    SS_DOWN(X_LSFT) SS_DOWN(X_LALT) SS_TAP(X_TAB) SS_UP(X_LALT) SS_UP(X_LSFT)},
    {KC_I,      SS_TAP(X_END) SS_DOWN(X_LSFT) SS_TAP(X_HOME) SS_TAP(X_HOME) SS_UP(X_LSFT) SS_DOWN(X_LCTL) SS_TAP(X_C) SS_UP(X_LCTL) SS_DELAY(100) SS_TAP(X_END) SS_TAP(X_ENTER) SS_TAP(X_HOME) SS_TAP(X_SLSH) SS_TAP(X_SLSH) SS_TAP(X_SPC) SS_DOWN(X_LCTL) SS_TAP(X_V) SS_UP(X_LCTL) SS_TAP(X_HOME) SS_TAP(X_UP)}
};

// these are defined in lk_words.h, example:
/*
LeaderTwoKey leaderTwoKeys[]={
    LK1(KC_E, KC_T, "test"),                    // only one variant of word
    LK2(KC_E, KC_T, "test", "Test"),            // normal variant plus shifted (trigger lead key with Shift)
    LK3(KC_E, KC_T, "test", "Test", "TEST")     // full variant (like LK2 plus additional capsed version when triggering with Ctrl)
};
*/
/*
 * ┌───────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬───────┐
 * │c0r0   │c1r0 │c2r0 │c3r0 │c4r0 │c5r0 │c6r0 │c7r0 │c8r0 │c8r3   │
 * │       │     │     │     │     │     │     │     │     │       │
 * ├───────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┐      │
 * │c0r1    │c1r1 │c2r1 │c3r1 │c4r1 │c5r1 │c6r1 │c7r1 │c8r1 │      │
 * │        │     │     │     │     │     │     │     │     │      │
 * ├────────┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴──────┤
 * │c0r2      │c1r2 │c2r2 │c3r2 │c4r2 │c5r2 │c6r2 │c7r2 │c8r0      │
 * │          │     │     │     │     │     │     │     │          │
 * ├──────────┴─────┴─────┴─────┴─────┼─────┼─────┴─────┴┬─────────┤
 * │c2r3                              │c3r3 │c4r3        │c5r3     │
 * │                                  │     │            │         │
 * └──────────────────────────────────┴─────┴────────────┴─────────┘
*/
/*
 * base
 * ┌───────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬───────┐
 * │q      │w    │e    │r    │t    │y    │u    │i    │o    │p      │
 * │       │     │     │     │     │     │     │     │     │       │
 * ├───────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┐      │
 * │a       │s    │d    │f    │g    │h    │j    │k    │l    │      │
 * │        │     │     │     │     │     │     │     │     │      │
 * ├────────┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴──────┤
 * │z         │x    │c    │v    │b    │n    │m    │, ?  │. !       │
 * │          │     │     │     │     │     │     │     │          │
 * ├──────────┴─────┴─────┴─────┴─────┼─────┼─────┴─────┴┬─────────┤
 * │space                             │lead │cmd         │' "      │
 * │shift                             │numsy│navfn       │         │
 * └──────────────────────────────────┴─────┴────────────┴─────────┘
 */
/*
 * number/symbol
 * ┌───────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬───────┐
 * │6      │7    │8    │9    │0    │1    │2    │3    │4    │5      │
 * │       │     │     │     │     │     │     │     │     │       │
 * ├───────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┐      │
 * │~       │@    │= \  │* |  │+ /  │:    │(    │[    │{    │      │
 * │        │     │     │     │     │     │     │     │     │      │
 * ├────────┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴──────┤
 * │$         │%    │^    │#    │&    │;    │)    │] ,  │} .       │
 * │          │     │     │     │     │     │     │     │          │
 * ├──────────┴─────┴─────┴─────┴─────┼─────┼─────┴─────┴┬─────────┤
 * │space                             │lead │cmd         │< >      │
 * │shift                             │numsy│navfn       │         │
 * └──────────────────────────────────┴─────┴────────────┴─────────┘
 */
/*
 * navigation/function
 * ┌───────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬───────┐
 * │F1     │F2   │F3   │F4   │F5   │Top  │PgUp │↑    │PgDwn│       │
 * │       │     │     │     │     │     │     │     │     │       │
 * ├───────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┐      │
 * │F6      │F7   │F8   │F9   │F10  │Home │←    │↓    │→    │End   │
 * │        │     │     │     │     │     │     │     │     │      │
 * ├────────┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴──────┤
 * │F11       │F12  │CtrlC│CtrlX│CtrlV│SelWL│WrdLf│SelLn│WrdRg     │
 * │          │     │     │     │     │     │     │     │          │
 * ├──────────┴─────┴─────┴─────┴─────┼─────┼─────┴─────┴┬─────────┤
 * │space                             │lead │cmd         │SelWR    │
 * │shift                             │numsy│navfn       │         │
 * └──────────────────────────────────┴─────┴────────────┴─────────┘
 */
/*
 * leader one keys (for two-or-more leader key combos see lk_words.h)
 * ┌───────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬───────┐
 * │Lock   │     │Doubl│Comnt│Multi│MltCm│Multi│Dupli│     │       │
 * │       │     │Shift│     │Comnt│InteJ│Code │Line │     │       │
 * ├───────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┐      │
 * │->      │WinR │PrtSc│Mute/│     │- [ ]│()   │[]   │{}   │´´    │
 * │        │     │     │Unmte│     │     │     │     │     │      │
 * ├────────┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴──────┤
 * │CtrlZ     │CtrlY│CtrlC│CtrlX│CtrlV│Alt  │Shift│     │""        │
 * │          │     │     │     │     │CtrlV│CtrlV│     │          │
 * ├──────────┴─────┴─────┴─────┴─────┼─────┼─────┴─────┴┬─────────┤
 * │                             WinLf│lead │WinRg       │         │
 * │                                  │     │            │         │
 * └──────────────────────────────────┴─────┴────────────┴─────────┘
 */
/*
 * system
 * ┌───────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬───────┐
 * │Boot   │track│play │track│vol  │msWhl│msWhl│mouse│msWhl│mouse  │
 * │       │prev │pause│next │up   │up   │left │up   │right│acc2   │
 * ├───────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┐      │
 * │RGB     │RGB  │stop │RGB  │vol  │msWhl│mouse│mouse│mouse│      │
 * │Sat+    │Lum+ │     │Hue+ │down │down │left │down │right│      │
 * ├────────┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴──────┤
 * │RGB       │RGB  │RGB  │RGB  │vol  │RGB  │mouse│mouse│mouse     │
 * │Sat-      │Lum- │Mode │Hue- │mute │OnOff│btn1 │btn3 │btn2      │
 * ├──────────┴─────┴─────┴─────┴─────┼─────┼─────┴─────┴┬─────────┤
 * │space                             │lead │cmd         │mouse    │
 * │shift                             │numsy│navfn       │acc0     │
 * └──────────────────────────────────┴─────┴────────────┴─────────┘
 */
/*
 * combos
 * ┌───────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬───────┐
 * │       │ +=Del=+=SftTab+ │+===Caps==+│     │ +=Del=+   │       │
 * │       │     │     │     │     │     │     │     │     │       │
 * ├───────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┐      │
 * │        │ +=BkSp=+=Tab=+  │     │     │     │  +=BkSp=+ │      │
 * │        │     │     │     │     │     │     │     │     │      │
 * ├────────┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴──────┤
 * │     +=CtrlX+=CtrlC+CtrlV=+ │     │     │     │ +=DelWord=+    │
 * │          │     │     │     │     │     │     │     │     |    │
 * ├──────────┴─────┴─────┴─────┴─────┼─────┼─────┴─────┴┬────|────┤
 * │                                  │  +=system==+     │ DelLine │
 * │                                  │     │            │    +    │
 * └──────────────────────────────────┴─────┴────────────┴─────────┘
 */
/*
 * one-shots cmd
 * ┌───────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬───────┐
 * │       │Esc  │€    │     │     │     │Sft+ │ü    │ö    │- _    │
 * │       │     │     │     │     │     │Retrn│     │     │       │
 * ├───────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┐      │
 * │ä       │ß    │     │Ctrl │     │     │Retrn│     │     │      │
 * │        │     │     │Sft F│     │     │     │     │     │      │
 * ├────────┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴──────┤
 * │          │     │     │     │     │     │     │     │          │
 * │          │     │     │     │     │     │     │     │          │
 * ├──────────┴─────┴─────┴─────┴─────┼─────┼─────┴─────┴┬─────────┤
 * │                                  │     │            │         │
 * │                                  │     │            │         │
 * └──────────────────────────────────┴─────┴────────────┴─────────┘
 */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BASE] = LAYOUT(
    KC_Q,      KC_W,      KC_E,            KC_R,            KC_T,              KC_Y,               KC_U,         KC_I,            KC_O,          ___,
    KC_A,      KC_S,      KC_D,            KC_F,            KC_G,              KC_H,               KC_J,         KC_K,            KC_L,          ___,
    MC_Z,      MC_X,      MC_C,            MC_V,            KC_B,              KC_N,               MC_M,         MMC_COMMA,       MMC_DOT,       ___,
    ___,       ___,       LSFT_T(KC_SPACE),UNICORN,         MC_NAV_CMD,        MMC_QUOT,           ___,          ___,             KC_P,          ___),
[_NUMSYM] = LAYOUT(
    KC_6,      KC_7,      KC_8,            KC_9,            KC_0,              KC_1,               KC_2,         KC_3,            KC_4,          ___,
    MC_TILD,   KC_AT,     MC_EQL_BKSL,     MC_ASTR_PIP,     MC_PLUS_SLSH,      KC_COLON,           KC_LPRN,      KC_LBRC,         KC_LCBR,       ___,
    KC_DLR,    KC_PERC,   MC_CARET,        KC_HASH,         KC_AMPR,           KC_SCLN,            KC_RPRN,      MC_SBR_COMMA,    MC_CBR_DOT,    ___,
    ___,       ___,       LSFT_T(KC_SPACE),UNICORN,         MC_NAV_CMD,        MC_LT,              ___,          ___,             KC_5,          ___),
[_NAVFN] = LAYOUT(
    KC_F1,     KC_F2,     KC_F3,           KC_F4,           KC_F5,             LCTL(KC_HOME),      KC_PGUP,      KC_UP,           KC_PGDN,       ___,
    KC_F6,     KC_F7,     KC_F8,           KC_F9,           KC_F10,            KC_HOME,            KC_LEFT,      KC_DOWN,         KC_RIGHT,      ___,
    KC_F11,    KC_F12,    LCTL(KC_C),      LCTL(KC_X),      LCTL(KC_V),        LSFT(LCTL(KC_LEFT)),LCTL(KC_LEFT),LSFT(KC_DOWN),   LCTL(KC_RIGHT),___,
    ___,       ___,       LSFT_T(KC_SPACE),UNICORN,         MC_NAV_CMD,        LSFT(LCTL(KC_RIGHT)),___,         ___,             KC_END,        ___),
[_SYSTEM] = LAYOUT(
    QK_BOOT,   KC_MPRV,   KC_MPLY,         KC_MNXT,         KC_VOLU,           KC_MS_WH_UP,        KC_MS_WH_LEFT,KC_MS_UP,        KC_MS_WH_RIGHT,___,
    RGB_SAI,   RGB_VAI,   KC_MSTP,         RGB_HUI,         KC_VOLD,           KC_MS_WH_DOWN,      KC_MS_LEFT,   KC_MS_DOWN,      KC_MS_RIGHT,   ___,
    RGB_SAD,   RGB_VAD,   RGB_MOD,         RGB_HUD,         KC_MUTE,           RGB_TOG,            KC_MS_BTN1,   KC_MS_BTN3,      KC_MS_BTN2,    ___,
    ___,       ___,       LSFT_T(KC_SPACE),UNICORN,         MC_NAV_CMD,        KC_MS_ACCEL0,       ___,          ___,             KC_MS_ACCEL2,  ___),
[_CMD] = LAYOUT(
    ___,       KC_ESC,    LALT(LCTL(KC_5)),___,             ___,               ___,                LSFT(KC_ENT), RALT(KC_Y),      RALT(KC_P),    ___,
    RALT(KC_Q),RALT(KC_S),___,             LSFT(LCTL(KC_F)),___,               ___,                KC_ENT,       LALT(LCTL(KC_5)),___,           ___,
    ___,       ___,       ___,             ___,             ___,               ___,                ___,          ___,             ___,           ___,
    ___,       ___,       ___,             ___,             ___,               ___,                ___,          ___,             KC_MINUS,      ___),
};

static uint8_t navOslState = 0;
static bool encoder_side = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    const uint8_t mods = get_mods();
    switch (keycode) {
        case MC_GRV:    if (record->event.pressed && !leader_sequence_active()) SEND_STRING(SS_TAP(X_GRV) SS_TAP(X_SPC));                                break;
        case MC_TILD:   if (record->event.pressed && !leader_sequence_active()) SEND_STRING(SS_DOWN(X_LSFT) SS_TAP(X_GRV) SS_TAP(X_SPC) SS_UP(X_LSFT));  break;
        case MC_CARET:  if (record->event.pressed && !leader_sequence_active()) SEND_STRING(SS_LSFT("6") SS_TAP(X_SPC));                                 break;
        case MMC_QUOT:  if (record->event.pressed && !leader_sequence_active() && record->tap.count) SEND_STRING(SS_TAP(X_QUOT) SS_TAP(X_SPC));          break;
        // keys with changed shifted character
        case MMC_COMMA:
            if (record->event.pressed && !leader_sequence_active() && record->tap.count) {
                if (mods & MOD_MASK_SHIFT) {
                    unregister_code(KC_LSFT);
                    SEND_STRING("?"); 
                    register_code(KC_LSFT);
                } else {
                    SEND_STRING(",");
                }
            }
            break;
        case MMC_DOT:
            if (record->event.pressed && !leader_sequence_active() && record->tap.count) {
                if (mods & MOD_MASK_SHIFT) {
                    unregister_code(KC_LSFT);
                    SEND_STRING("!"); 
                    register_code(KC_LSFT);
                } else {
                    SEND_STRING(".");
                }
            }
            break;
        case MC_EQL_BKSL:
            if (record->event.pressed && !leader_sequence_active()) {
                if (mods & MOD_MASK_SHIFT) {
                    unregister_code(KC_LSFT);
                    SEND_STRING("\\"); 
                    register_code(KC_LSFT);
                } else {
                    SEND_STRING("=");
                }
            }
            break;
        case MC_ASTR_PIP:
            if (record->event.pressed && !leader_sequence_active()) {
                if (mods & MOD_MASK_SHIFT) {
                    unregister_code(KC_LSFT);
                    SEND_STRING("|"); 
                    register_code(KC_LSFT);
                } else {
                    SEND_STRING("*");
                }
            }
            break;
        case MC_PLUS_SLSH:
            if (record->event.pressed && !leader_sequence_active()) {
                if (mods & MOD_MASK_SHIFT) {
                    unregister_code(KC_LSFT);
                    SEND_STRING("/"); 
                    register_code(KC_LSFT);
                } else {
                    SEND_STRING("+");
                }
            }
            break;
        case MC_SBR_COMMA:
            if (record->event.pressed && !leader_sequence_active()) {
                if (mods & MOD_MASK_SHIFT) {
                    unregister_code(KC_LSFT);
                    SEND_STRING(","); 
                    register_code(KC_LSFT);
                } else {
                    SEND_STRING("]");
                }
            }
            break;
        case MC_CBR_DOT:
            if (record->event.pressed && !leader_sequence_active()) {
                if (mods & MOD_MASK_SHIFT) {
                    unregister_code(KC_LSFT);
                    SEND_STRING("."); 
                    register_code(KC_LSFT);
                } else {
                    SEND_STRING("}");
                }
            }
            break;
        case MC_LT:
            if (record->event.pressed && !leader_sequence_active()) {
                if (mods & MOD_MASK_SHIFT) {
                    unregister_code(KC_LSFT);
                    SEND_STRING(">"); 
                    register_code(KC_LSFT);
                } else {
                    SEND_STRING("<");
                }
            }
            break;
        case UNICORN:
            if (record->event.pressed && !leader_sequence_active()) {
                if (record->tap.count){
                    leader_start();
                    return false;
                } else {
                    layer_on(_NUMSYM);
                    return false;
                }
            }
            break;
        case DELLINE:
            if (record->event.pressed && !leader_sequence_active()) {
                SEND_STRING(SS_TAP(X_END) SS_DOWN(X_LSFT) SS_TAP(X_HOME) SS_TAP(X_HOME) SS_UP(X_LSFT) SS_TAP(X_DELETE) SS_TAP(X_DELETE));
                return false;
            }
            break;
        case DELWORD:
            if (record->event.pressed && !leader_sequence_active()) {
                SEND_STRING(SS_DOWN(X_LSFT) SS_DOWN(X_LCTL) SS_TAP(X_LEFT) SS_UP(X_LCTL) SS_UP(X_LSFT) SS_TAP(X_DELETE));
                return false;
            }
            break;
        case MC_NAV_CMD:
           if (record->event.pressed && !leader_sequence_active()) {
                if (record->tap.count) {
                    layer_move(_CMD);
                    navOslState = 1;
                    return false;
                }
            }
			break;
    }
    return true;
}

void post_process_record_user(uint16_t keycode, keyrecord_t* record) {
    if (keycode != MC_NAV_CMD) {
        if (navOslState) {
            layer_move(_BASE);
            navOslState = 0;
        }
    }
}

void leader_end_user(void) {
    const uint8_t mods = get_mods();
    int i;
    clear_mods();
    for (i=0; i<sizeof(leaderOneKeys)/sizeof(leaderOneKeys[0]); i++)
         if (leader_sequence_one_key(leaderOneKeys[i].key)) {SEND_STRING(leaderOneKeys[i].out); return;}
    for (i=0; i<sizeof(leaderTwoKeys)/sizeof(leaderTwoKeys[0]); i++)
        if (leader_sequence_two_keys(leaderTwoKeys[i].key1, leaderTwoKeys[i].key2)) {
            if (mods & MOD_MASK_SHIFT) {SEND_STRING(leaderTwoKeys[i].outShifted); return;}
            if (mods & MOD_MASK_CTRL) {SEND_STRING(leaderTwoKeys[i].outCapsed); return;}
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

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MC_NAV_CMD:		// the nav/cmd key shouldn't have permissive hold
//		case UNICORN:
		case MC_Z:              // HRMs (better: BRMs) shouldn't have permissive hold to avoid misfires when rolling
		case MC_X:
		case MC_C:
		case MC_V:
		case MC_M:
		case MMC_COMMA:
		case MMC_DOT:
		case MMC_QUOT:
            return false;
        default:
            return true;
    }
}

bool encoder_update_user(uint8_t index, bool clockwise) {
	if (index == 0) {
		if (encoder_side)
			clockwise ? SEND_STRING(SS_TAP(X_WH_L) SS_TAP(X_WH_L) SS_TAP(X_WH_L)) : SEND_STRING(SS_TAP(X_WH_R) SS_TAP(X_WH_R) SS_TAP(X_WH_R));
		else
			clockwise ? tap_code(KC_WH_U) : tap_code(KC_WH_D);
	}
    return false;
}
