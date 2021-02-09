#ifndef DMG_CALC
#define DMG_CALC

#include "inputhandler.h"

int crit_dmg(int, float);
int em_perc_bonus(int);
int basic_atk(int, float, int);
int outgoing_dmg(int, int, int);
int amping_dmg(int, float, int);
#endif