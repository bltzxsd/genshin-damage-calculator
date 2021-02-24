#include "include/attack_output.h"

int weapon_dmg_bonus(float total_perc_atk, float dmgbonus_p, float weapon_passive, float weapon_name) {
    if (weapon_name == prototype) {
        total_perc_atk += weapon_passive;
        return total_perc_atk;
    }
    if (weapon_name == amos) {
        dmgbonus_p = weapon_passive;
        return dmgbonus_p;
    }
    std::cerr << "Wrong parameter values: weapon_dmg_bonus(float, float, float, float)\n";
    return -1;
}

float artifact_dmg_bonus(int artifact_set_used, float dmgbonus_all) {
    if (artifact_set_used == blizzard) {
        return dmgbonus_all += 15.0F;
    }
    if (artifact_set_used == wanderers) {
        return dmgbonus_all += 35.0F;
    }
    std::cerr << "Wrong parameter values: artifact_dmg_bonus(int, float)\n";
    return -1;
}

