#ifndef ATTACK_OUTPUT
#define ATTACK_OUTPUT

#include "weapon_level.h"
#include "artifact_set.h"
#include "talent_level.h"
#include "dmg_calculation.h"

extern float first_atk_ratio;
extern float second_atk_ratio;
extern float third_atk_ratio;
extern float fourth_atk_ratio;
extern float fifth_atk_ratio;
extern float sixth_atk_ratio;
extern float aim_atk_ratio;
extern float charge_atk_ratio;
extern float frostflake_arrow;
extern float frostflake_bloom;


int weapon_dmg_bonus(float, float, float, float);
float artifact_dmg_bonus(int, float);

#endif