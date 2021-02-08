#ifndef ARTIFACT_VALUE
#define ARTIFACT_VALUE

#include "inputhandler.h"

#define MAX_FLAT_ATK 95
#define MAX_SUB_ATKP 29.0
#define MAX_MAINS_ATKP 46.6
#define FEATHER_FLAT_MAX_ATK 311

extern int flat_atk[5];
extern float atk_percent[5];
void flat_atk_get();
void atk_perc_get();
#endif