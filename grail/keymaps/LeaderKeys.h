#ifndef LEADER_KEYS
#define LEADER_KEYS

typedef struct {
    uint16_t key;
    const char *out;
} LeaderOneKey;
typedef struct {
    uint16_t key1;
    uint16_t key2;
    const char *out;
    const char *outShifted;
    const char *outCapsed;
} LeaderTwoKey;

#define LK1(k1, k2, o) {k1, k2, o, o, o}
#define LK2(k1, k2, o, os) {k1, k2, o, os, os}
#define LK3(k1, k2, o, os, oc) {k1, k2, o, os, oc}

#endif
