#ifndef ARTIFACT_SET
#define ARTIFACT_SET

#include "inputhandler.h"

#define MAX_FLAT_ATK 95
#define MAX_PERCNT_ATK 29

extern float floatflat_atk[];
extern float atk_percent[];
void flat_atk_get();
void atk_perc_get();
#endif