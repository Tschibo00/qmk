#include QMK_KEYBOARD_H
#include "../LeaderKeys.h"

LeaderTwoKey leaderTwoKeys[]={
    // mail addresses
    LK1(KC_M, KC_W, "test"),
    
    // status messages
    LK1(KC_S, KC_M, "test"),
    
    // names
    LK1(KC_N, KC_A, "test"),

    // complex words
    LK3(KC_T, KC_A, "test", "Test", "TEST"),

    // emojis
    LK1(KC_E, KC_C, "test"),

    // code snippets    
    LK1(KC_C, KC_C, "test"),
};