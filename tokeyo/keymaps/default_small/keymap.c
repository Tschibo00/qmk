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
    MC_CBR_DOT
};

// This is the magic leader keycode (which does Alt on hold)
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
#define MC_D        MT(MOD_LSFT,KC_D)
#define MC_H        MT(MOD_LSFT,KC_H)
#define MMC_COMMA   MT(MOD_LCTL,MC_COMMA)
#define MMC_DOT     MT(MOD_LALT,MC_DOT)
#define MMC_QUOT    MT(MOD_LGUI,MC_QUOT) 

/*
const uint16_t PROGMEM cmb_auml[]=      {KC_A,     KC_R,    COMBO_END}; 
const uint16_t PROGMEM cmb_ouml[]=      {KC_O,     KC_I,    COMBO_END}; 
const uint16_t PROGMEM cmb_uuml[]=      {KC_U,     KC_Y,    COMBO_END}; 
const uint16_t PROGMEM cmb_szlig[]=     {KC_R,     KC_S,    COMBO_END}; 
const uint16_t PROGMEM cmb_euro[]=      {KC_E,     KC_O,    COMBO_END}; 
const uint16_t PROGMEM cmb_esc[]=       {KC_W,     KC_F,    COMBO_END}; 
const uint16_t PROGMEM cmb_caps[]=      {KC_B,     KC_J,    COMBO_END}; 
const uint16_t PROGMEM cmb_tab[]=       {KC_S,     KC_T,    COMBO_END}; 
const uint16_t PROGMEM cmb_sfttab[]=    {KC_F,     KC_P,    COMBO_END}; 
const uint16_t PROGMEM cmb_bksp[]=      {KC_N,     KC_E,    COMBO_END}; 
const uint16_t PROGMEM cmb_del[]=       {KC_L,     KC_U,    COMBO_END}; 
const uint16_t PROGMEM cmb_delline[]=   {KC_H,     MC_COMMA,COMBO_END};
const uint16_t PROGMEM cmb_delword[]=   {MC_COMMA, MC_DOT,  COMBO_END};
const uint16_t PROGMEM cmb_return[]=    {KC_E,     KC_I,    COMBO_END};
combo_t key_combos[]={
     COMBO(cmb_auml,    RALT(KC_Q)),
     COMBO(cmb_ouml,    RALT(KC_P)),
     COMBO(cmb_uuml,    RALT(KC_Y)),
     COMBO(cmb_szlig,   RALT(KC_S)),
     COMBO(cmb_euro,    LALT(LCTL(KC_5))),
     COMBO(cmb_esc,     KC_ESC),
     COMBO(cmb_caps,    QK_CAPS_WORD_TOGGLE),
     COMBO(cmb_tab,     KC_TAB),
     COMBO(cmb_sfttab,  LSFT(KC_TAB)),
     COMBO(cmb_bksp,    KC_BSPC),
     COMBO(cmb_del,     KC_DEL),
     COMBO(cmb_delline, DELLINE),                   // workaround because qmk doesn't allow complex output for combos
     COMBO(cmb_delword, DELWORD),
     COMBO(cmb_return,  KC_ENT)
};
*/
const uint16_t PROGMEM cmb_caps[]=      {KC_B, KC_J, COMBO_END}; 
const uint16_t PROGMEM cmb_tab[]=       {KC_S, KC_T, COMBO_END}; 
const uint16_t PROGMEM cmb_sfttab[]=    {KC_F, KC_P, COMBO_END}; 
const uint16_t PROGMEM cmb_bksp[]=      {KC_E, KC_I, COMBO_END}; 
const uint16_t PROGMEM cmb_del[]=       {KC_U, KC_Y, COMBO_END}; 
const uint16_t PROGMEM cmb_bksp_left[]= {KC_R, KC_S, COMBO_END}; 
const uint16_t PROGMEM cmb_del_left[]=  {KC_W, KC_F, COMBO_END}; 
const uint16_t PROGMEM cmb_delword[]=   {MMC_COMMA, MMC_DOT, COMBO_END};
const uint16_t PROGMEM cmb_delline[]=   {MMC_DOT, MMC_QUOT, COMBO_END};
const uint16_t PROGMEM cmb_ctlx[]=      {MC_Z, MC_X, COMBO_END};
const uint16_t PROGMEM cmb_ctlc[]=      {MC_X, MC_C, COMBO_END};
const uint16_t PROGMEM cmb_ctlv[]=      {MC_C, MC_D, COMBO_END};
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
    {KC_W,      SS_TAP(X_ESC)},
    {KC_M,      "- [ ] "},
    {KC_J,      SS_DOWN(X_LSFT) SS_DOWN(X_LCTL) SS_TAP(X_PSLS) SS_UP(X_LCTL) SS_UP(X_LSFT)},
    {KC_B,      SS_DOWN(X_LCTL) SS_TAP(X_X) SS_UP(X_LCTL) "/*" SS_TAP(X_ENTER) SS_DOWN(X_LCTL) SS_TAP(X_V) SS_UP(X_LCTL) "*/" SS_TAP(X_ENTER)},
    {KC_P,      SS_TAP(X_HOME) SS_TAP(X_HOME) "// "},
    {KC_L,      SS_TAP(X_GRV) SS_TAP(X_GRV) SS_TAP(X_GRV) SS_TAP(X_SPC) SS_DOWN(X_LSFT) SS_TAP(X_ENTER) SS_UP(X_LSFT) SS_DOWN(X_LCTL) SS_TAP(X_V) SS_UP(X_LCTL) SS_DOWN(X_LSFT) SS_TAP(X_ENTER) SS_UP(X_LSFT) SS_TAP(X_GRV) SS_TAP(X_GRV) SS_TAP(X_GRV) SS_TAP(X_SPC)},
    {KC_R,      SS_DOWN(X_LGUI) SS_TAP(X_R) SS_UP(X_LGUI)},
    {KC_S,      SS_TAP(X_PSCR)},
    {KC_N,      "()" SS_TAP(X_LEFT)},
    {KC_E,      "[]" SS_TAP(X_LEFT)},
    {KC_I,      "{}" SS_TAP(X_LEFT)},
    {KC_O,      "``" SS_TAP(X_LEFT)},
    {KC_A,      "->"},
    {MC_QUOT,   "\"\"" SS_TAP(X_LEFT)},
    {KC_SPACE,  SS_DOWN(X_LSFT) SS_DOWN(X_LGUI) SS_TAP(X_LEFT) SS_UP(X_LGUI) SS_UP(X_LSFT)},
    {KC_PRIR,   SS_DOWN(X_LSFT) SS_DOWN(X_LGUI) SS_TAP(X_RIGHT) SS_UP(X_LGUI) SS_UP(X_LSFT)},
    {KC_MINUS,  SS_DOWN(X_LALT) SS_TAP(X_F4) SS_UP(X_LALT)},
    {KC_BSLS,   SS_DOWN(X_LALT) SS_DOWN(X_LCTL) SS_TAP(X_DEL) SS_UP(X_LCTL) SS_UP(X_LALT)},
    {KC_C,      SS_DOWN(X_LCTL) SS_TAP(X_C) SS_UP(X_LCTL)},
    {KC_D,      SS_DOWN(X_LCTL) SS_TAP(X_X) SS_UP(X_LCTL)},
    {KC_K,      SS_DOWN(X_LALT) SS_DOWN(X_LCTL) SS_TAP(X_V) SS_UP(X_LCTL) SS_UP(X_LALT)},
    {KC_V,      SS_DOWN(X_LCTL) SS_TAP(X_V) SS_UP(X_LCTL)},
    {KC_H,      SS_DOWN(X_LSFT) SS_DOWN(X_LCTL) SS_TAP(X_V) SS_UP(X_LCTL) SS_UP(X_LSFT)},
    {KC_BSPC,   SS_TAP(X_END) SS_DOWN(X_LSFT) SS_TAP(X_HOME) SS_TAP(X_HOME) SS_UP(X_LSFT) SS_TAP(X_DELETE) SS_TAP(X_DELETE)},
    {KC_F,      SS_TAP(X_LSFT) SS_TAP(X_LSFT)},
    {KC_T,      SS_TAP(X_ENTER)},
    {KC_G,      SS_DOWN(X_LALT) SS_DOWN(X_LCTL) SS_TAP(X_TAB) SS_UP(X_LCTL) SS_UP(X_LALT)},
    {KC_TAB,    SS_DOWN(X_LALT) SS_TAP(X_TAB) SS_UP(X_LALT)},
    {KC_ENT,    SS_DOWN(X_LSFT) SS_DOWN(X_LALT) SS_TAP(X_TAB) SS_UP(X_LALT) SS_UP(X_LSFT)},
    {KC_U,      SS_TAP(X_END) SS_DOWN(X_LSFT) SS_TAP(X_HOME) SS_TAP(X_HOME) SS_UP(X_LSFT) SS_DOWN(X_LCTL) SS_TAP(X_C) SS_UP(X_LCTL) SS_DELAY(100) SS_TAP(X_END) SS_TAP(X_ENTER) SS_TAP(X_HOME) SS_TAP(X_SLSH) SS_TAP(X_SLSH) SS_TAP(X_SPC) SS_DOWN(X_LCTL) SS_TAP(X_V) SS_UP(X_LCTL) SS_TAP(X_HOME) SS_TAP(X_UP)}
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
 * base
 *             ┌─────┐                             ┌─────┐
 *       ┌─────┤f    │                             │u    ├─────┐
 * ┌─────┤w    │     ├─────┬─────┐     ┌─────┬─────┤     │y    ├─────┐
 * │q    │     ├─────┤p    │b    │     │j    │l    ├─────┤     │- _  │
 * │     ├─────┤s    │     │     │     │     │     │e    ├─────┤     │
 * ├─────┤r    │     ├─────┼─────┤     ├─────┼─────┤     │i    ├─────┤
 * │a    │     ├─────┤t    │g    │     │m    │n    ├─────┤     │o    │
 * │     ├─────┤c    │     │     │     │     │     │, ?  ├─────┤     │
 * ├─────┤x    │     ├─────┼─────┤     ├─────┼─────┤     │. !  ├─────┤
 * │z    │     ├─────┤d    │v    │     │k    │h    ├─────┤     │' "  │
 * │     ├─────┘     │     │     │     │     │     │     └─────┤     │
 * └─────┘           └─────┴─────┘     └─────┴─────┘           └─────┘
 *                         ┌─────┐     ┌─────┐
 *                         │space├─────┤cmd  │
 *                         │shift│lead │navfn│
 *                         └─────┤numsy├─────┘
 *                               └─────┘
 * number/symbol
 *             ┌─────┐                             ┌─────┐
 *       ┌─────┤3    │                             │8    ├─────┐
 * ┌─────┤2    │     ├─────┬─────┐     ┌─────┬─────┤     │9    ├─────┐
 * │1    │     ├─────┤4    │5    │     │6    │7    ├─────┤     │0    │
 * │     ├─────┤= \  │     │     │     │     │     │[    ├─────┤     │
 * ├─────┤@    │     ├─────┼─────┤     ├─────┼─────┤     │{    ├─────┤
 * │~    │     ├─────┤* |  │+ /  │     │:    │(    ├─────┤     │<    │
 * │     ├─────┤^    │     │     │     │     │     │] ,  ├─────┤     │
 * ├─────┤%    │     ├─────┼─────┤     ├─────┼─────┤     │} .  ├─────┤
 * │$    │     ├─────┤#    │&    │     │;    │)    ├─────┤     │>    │
 * │     ├─────┘     │     │     │     │     │     │     └─────┤     │
 * └─────┘           └─────┴─────┘     └─────┴─────┘           └─────┘
 *                         ┌─────┐     ┌─────┐
 *                         │space├─────┤cmd  │
 *                         │shift│lead │navfn│
 *                         └─────┤numsy├─────┘
 *                               └─────┘
 * navigation/function
 *             ┌─────┐                             ┌─────┐
 *       ┌─────┤F3   │                             │↑    ├─────┐
 * ┌─────┤F2   │     ├─────┬─────┐     ┌─────┬─────┤     │PgDwn├─────┐
 * │F1   │     ├─────┤F4   │F5   │     │Top  │PgUp ├─────┤     │Bottm│
 * │     ├─────┤F8   │     │     │     │     │     │↓    ├─────┤     │
 * ├─────┤F7   │     ├─────┼─────┤     ├─────┼─────┤     │→    ├─────┤
 * │F6   │     ├─────┤F9   │F10  │     │Home │←    ├─────┤     │End  │
 * │     ├─────┤CtrlC│     │     │     │     │     │SelLn├─────┤     │
 * ├─────┤F12  │     ├─────┼─────┤     ├─────┼─────┤     │WrdRg├─────┤
 * │F11  │     ├─────┤CtrlX│CtrlV│     │SelWL│WrdLf├─────┤     │SelWR│
 * │     ├─────┘     │     │     │     │     │     │     └─────┤     │
 * └─────┘           └─────┴─────┘     └─────┴─────┘           └─────┘
 *                         ┌─────┐     ┌─────┐
 *                         │space├─────┤cmd  │
 *                         │shift│lead │navfn│
 *                         └─────┤numsy├─────┘
 *                               └─────┘
 * leader one keys (for two-or-more leader key combos see lk_words.h)
 *             ┌─────┐                             ┌─────┐
 *       ┌─────┤Doubl│                             │Dupli├─────┐
 * ┌─────┤Esc  │Shift├─────┬─────┐     ┌─────┬─────┤Line │     ├─────┐
 * │Lock │     ├─────┤Comnt│Multi│     │MltCm│Multi├─────┤     │     │
 * │     ├─────┤PrtSc│     │Comnt│     │InteJ│Code │[]   ├─────┤     │
 * ├─────┤WinR │     ├─────┼─────┤     ├─────┼─────┤     │{}   ├─────┤
 * │->   │     ├─────┤Retrn│CtAlt│     │- [ ]│()   ├─────┤     │´´   │
 * │     ├─────┤CtrlC│     │Tab  │     │     │     │     ├─────┤     │
 * ├─────┤CtrlY│     ├─────┼─────┤     ├─────┼─────┤     │     ├─────┤
 * │CtrlZ│     ├─────┤CtrlX│CtrlV│     │Alt  │Shift├─────┤     │""   │
 * │     ├─────┘     │     │     │     │CtrlV│CtrlV│     └─────┤     │
 * └─────┘           └─────┴─────┘     └─────┴─────┘           └─────┘
 *                         ┌─────┐     ┌─────┐
 *                         │WinLf├─────┤WinRg│
 *                         │     │lead │     │
 *                         └─────┤alt  ├─────┘
 *                               └─────┘
 * system
 *             ┌─────┐                             ┌─────┐
 *       ┌─────┤play │                             │mouse├─────┐
 * ┌─────┤track│pause├─────┬─────┐     ┌─────┬─────┤up   │msWhl├─────┐
 * │Boot │prev ├─────┤track│vol  │     │msWhl│msWhl├─────┤right│mouse│
 * │     ├─────┤stop │next │up   │     │up   │left │mouse├─────┤acc2 │
 * ├─────┤RGB  │     ├─────┼─────┤     ├─────┼─────┤down │mouse├─────┤
 * │RGB  │Lum+ ├─────┤RGB  │vol  │     │msWhl│mouse├─────┤right│mouse│
 * │Sat+ ├─────┤RGB  │Hue+ │down │     │down │left │mouse├─────┤acc1 │
 * ├─────┤RGB  │Mode ├─────┼─────┤     ├─────┼─────┤btn3 │mouse├─────┤
 * │RGB  │Lum- ├─────┤RGB  │vol  │     │RGB  │mouse├─────┤btn2 │mouse│
 * │Sat- ├─────┘     │Hue- │mute │     │OnOff│btn1 │     └─────┤acc0 │
 * └─────┘           └─────┴─────┘     └─────┴─────┘           └─────┘
 *                         ┌─────┐     ┌─────┐
 *                         │space├─────┤cmd  │
 *                         │shift│lead │navfn│
 *                         └─────┤numsy├─────┘
 *                               └─────┘
 * combos
 *             ┌─────┐                             ┌─────┐
 *       ┌─────┤     │                             │     ├─────┐
 * ┌─────┤ +=Del=+   ├─────┬─────┐     ┌─────┬─────┤  +=Del=+  ├─────┐
 * │     │     ├──\+SftTab+│   +===Caps===+  │     ├─────┤     │     │
 * │     ├─────┤     │     │     │     │     │     │     ├─────┤     │
 * ├─────┤+=BkSp=+   ├─────┼─────┤     ├─────┼─────┤  +=BkSp=+ ├─────┤
 * │     │     ├──\=+=Tab=+│     │     │     │     ├─────┤     │     │
 * │     ├─────┤     │     │     │     │     │     │     ├─────┤     │
 * ├─────┤ +=CtrlC=+ ├─────┼─────┤     ├─────┼─────┤+=DelWord=+├─────┤
 * │ +=CtrlX=+ ├──\=CtrlV=+│     │     │     │     ├─────┤+=DelLine=+│
 * │     ├─────┘     │     │     │     │     │     │     └─────┤     │
 * └─────┘           └─────┴─────┘     └─────┴─────┘           └─────┘
 *                         ┌─────┐     ┌─────┐
 *                         │     ├─────┤     │
 *                         │     │+=system==+│
 *                         └─────┤     ├─────┘
 *                               └─────┘
 * one-shots cmd
 *             ┌─────┐                             ┌─────┐
 *       ┌─────┤Ctrl │                             │ü    ├─────┐
 * ┌─────┤Esc  │Sft F├─────┬─────┐     ┌─────┬─────┤     │Del  ├─────┐
 * │     │     ├─────┤Sft+ │     │     │     │Sft+ ├─────┤     │     │
 * │     ├─────┤ß    │Tab  │     │     │     │Retrn│€    ├─────┤     │
 * ├─────┤     │     ├─────┼─────┤     ├─────┼─────┤     │BkSp ├─────┤
 * │ä    │     ├─────┤Tab  │Mute/│     │     │Retrn├─────┤     │ö    │
 * │     ├─────┤     │     │Unmte│     │     │     │     ├─────┤     │
 * ├─────┤     │     ├─────┼─────┤     ├─────┼─────┤     │Del  ├─────┤
 * │     │     ├─────┤     │     │     │     │     ├─────┤Wrd  │Del  │
 * │     ├─────┘     │     │     │     │     │     │     └─────┤Line │
 * └─────┘           └─────┴─────┘     └─────┴─────┘           └─────┘
 *                         ┌─────┐     ┌─────┐
 *                         │     ├─────┤     │
 *                         │     │     │     │
 *                         └─────┤     ├─────┘
 *                               └─────┘
 */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BASE] = LAYOUT(
    KC_Q,      KC_W,   KC_F,            KC_P,            KC_B,              KC_J,               KC_L,         KC_U,            KC_Y,          KC_MINUS,
    KC_A,      KC_R,   KC_S,            KC_T,            KC_G,              KC_M,               KC_N,         KC_E,            KC_I,          KC_O,
    MC_Z,      MC_X,   MC_C,            MC_D,            KC_V,              KC_K,               MC_H,         MMC_COMMA,       MMC_DOT,       MMC_QUOT,
    KC_NO,     KC_NO,  LSFT_T(KC_SPACE),LSFT_T(KC_SPACE),UNICORN,           MC_NAV_CMD,         MC_NAV_CMD,   KC_NO,           KC_NO,         KC_NO),
[_NUMSYM] = LAYOUT(
    KC_1,      KC_2,   KC_3,            KC_4,            KC_5,              KC_6,               KC_7,         KC_8,            KC_9,          KC_0,
    MC_TILD,   KC_AT,  MC_EQL_BKSL,     MC_ASTR_PIP,     MC_PLUS_SLSH,      KC_COLON,           KC_LPRN,      KC_LBRC,         KC_LCBR,       KC_LT,
    KC_DLR,    KC_PERC,MC_CARET,        KC_HASH,         KC_AMPR,           KC_SCLN,            KC_RPRN,      MC_SBR_COMMA,    MC_CBR_DOT,    KC_GT,
    KC_NO,     KC_NO,  LSFT_T(KC_SPACE),LSFT_T(KC_SPACE),UNICORN,           MC_NAV_CMD,         MC_NAV_CMD,   KC_NO,           KC_NO,         KC_NO),
[_NAVFN] = LAYOUT(
    KC_F1,     KC_F2,  KC_F3,           KC_F4,           KC_F5,             LCTL(KC_HOME),      KC_PGUP,      KC_UP,           KC_PGDN,       LCTL(KC_END),
    KC_F6,     KC_F7,  KC_F8,           KC_F9,           KC_F10,            KC_HOME,            KC_LEFT,      KC_DOWN,         KC_RIGHT,      KC_END,
    KC_F11,    KC_F12, LCTL(KC_C),      LCTL(KC_X),      LCTL(KC_V),        LSFT(LCTL(KC_LEFT)),LCTL(KC_LEFT),LSFT(KC_DOWN),   LCTL(KC_RIGHT),LSFT(LCTL(KC_RIGHT)),
    KC_NO,     KC_NO,  LSFT_T(KC_SPACE),LSFT_T(KC_SPACE),UNICORN,           MC_NAV_CMD,         MC_NAV_CMD,   KC_NO,           KC_NO,         KC_NO),
[_SYSTEM] = LAYOUT(
    QK_BOOT,   KC_MPRV,KC_MPLY,         KC_MNXT,         KC_VOLU,           KC_MS_WH_UP,        KC_MS_WH_LEFT,KC_MS_UP,        KC_MS_WH_RIGHT,KC_MS_ACCEL2,
    RGB_SAI,   RGB_VAI,KC_MSTP,         RGB_HUI,         KC_VOLD,           KC_MS_WH_DOWN,      KC_MS_LEFT,   KC_MS_DOWN,      KC_MS_RIGHT,   KC_MS_ACCEL1,
    RGB_SAD,   RGB_VAD,RGB_MOD,         RGB_HUD,         KC_MUTE,           RGB_TOG,            KC_MS_BTN1,   KC_MS_BTN3,      KC_MS_BTN2,    KC_MS_ACCEL0,
    KC_NO,     KC_NO,  LSFT_T(KC_SPACE),LSFT_T(KC_SPACE),UNICORN,           MC_NAV_CMD,         MC_NAV_CMD,   KC_NO,           KC_NO,         KC_NO),
[_CMD] = LAYOUT(
    KC_NO,     KC_ESC, LSFT(LCTL(KC_F)),LSFT(KC_TAB),    KC_NO,             KC_NO,              LSFT(KC_ENT), RALT(KC_Y),      KC_DEL,        KC_NO,
    RALT(KC_Q),KC_NO,  RALT(KC_S),      KC_TAB,          LGUI(LALT(KC_K)),  KC_NO,              KC_ENT,       LALT(LCTL(KC_5)),KC_BSPC,       RALT(KC_P),
    KC_NO,     KC_NO,  KC_NO,           KC_NO,           KC_NO,             KC_NO,              KC_NO,        KC_NO,           DELWORD,       DELLINE,
    KC_NO,     KC_NO,  KC_NO,           KC_NO,           KC_NO,             KC_NO,              KC_NO,        KC_NO,           KC_NO,         KC_NO)
};

static uint8_t navOslState = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    const uint8_t mods = get_mods();
    switch (keycode) {
        case MC_GRV:    if (record->event.pressed && !leader_sequence_active()) SEND_STRING(SS_TAP(X_GRV) SS_TAP(X_SPC));                                break;
        case MC_TILD:   if (record->event.pressed && !leader_sequence_active()) SEND_STRING(SS_DOWN(X_LSFT) SS_TAP(X_GRV) SS_TAP(X_SPC) SS_UP(X_LSFT));  break;
        case MC_CARET:  if (record->event.pressed && !leader_sequence_active()) SEND_STRING(SS_LSFT("6") SS_TAP(X_SPC));                                 break;
        case MMC_QUOT:   if (record->event.pressed && !leader_sequence_active() && record->tap.count) SEND_STRING(SS_TAP(X_QUOT) SS_TAP(X_SPC));         break;
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
		case MC_D:
		case MC_H:
		case MMC_COMMA:
		case MMC_DOT:
		case MMC_QUOT:
            return false;
        default:
            return true;
    }
}
