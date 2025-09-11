#ifndef LEADER_WORDS
#define LEADER_WORDS

#include QMK_KEYBOARD_H
#include "../LeaderKeys.h"

LeaderTwoKey leaderTwoKeys[]={
    // status messages
    LK1(KC_S, KC_M, "#goodMorning"),

    // emojis
    LK1(KC_E, KC_K, ":("),
    LK1(KC_E, KC_V, ":)"),
};

#endif
