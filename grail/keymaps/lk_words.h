#ifndef LEADER_WORDS
#define LEADER_WORDS

#include QMK_KEYBOARD_H
#include "../LeaderKeys.h"

LeaderTwoKey leaderTwoKeys[]={
    LK1(KC_S, KC_A, "#afk"),
    LK1(KC_E, KC_V, ":)"),
    LK1(KC_X, KC_E, SS_DOWN(X_LGUI) "r" SS_UP(X_LGUI) SS_DELAY(100) "explorer" SS_TAP(X_ENTER)),
};

#endif
