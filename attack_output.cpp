#include "include/attack_output.h"

/*
// checks if amos passive dmg bonus is applied
    if (dmgbonus_p == AMOS_PASSIVE_BOOST) {
        dmgbonus_p = AMOS_PASSIVE_BOOST;
    } else if (dmgbonus_p == CRESCENT_PASSIVE_BOOST) {
        // if crescent: atk bonus up 34
        total_perc_atk += CRESCENT_PASSIVE_BOOST;
    }
    // check (elemental) dmg bonus
    if (artifact_set_used == 35 wanderer boost) {
        dmgbonus_p += 35;
    } else if (artifact_set_used == 15) {
        dmgbonus_p += 15;
    }
*/
int auto_talent_lvl;
float first_atk_ratio{auto_first_atk(auto_talent_lvl)};
float second_atk_ratio{auto_second_atk(auto_talent_lvl)};
float third_atk_ratio{auto_third_atk(auto_talent_lvl)};
float fourth_atk_ratio{auto_fourth_atk(auto_talent_lvl)};
float fifth_atk_ratio{auto_fifth_atk(auto_talent_lvl)};
float sixth_atk_ratio{auto_sixth_atk(auto_talent_lvl)};
float aim_atk_ratio{auto_aimshot(auto_talent_lvl)};
float charge_atk_ratio{auto_chargeshot(auto_talent_lvl)};
float frostflake_arrow{auto_frostflake(auto_talent_lvl)};
float frostflake_bloom{auto_frostflake_bloom(auto_talent_lvl)};

int weapon_dmg_bonus(float& total_perc_atk, float& dmgbonus_p, float& weapon_passive, float&weapon_name) {
    if (weapon_name == prototype) {
        total_perc_atk += weapon_passive;
        return total_perc_atk;
    }
    if (weapon_name == amos) {
        dmgbonus_p = weapon_passive;
        return dmgbonus_p;
    }
    std::cerr << "Wrong parameter values: weapon_dmg_bonus(float&, float&, float&, float&)\n";
    return -1;
}

float artifact_dmg_bonus(int& artifact_set_used, float& dmgbonus_p, float& dmgbonus_pe) {
    if (artifact_set_used == blizzard) {
        return dmgbonus_pe += 15.0f;
    }
    if (artifact_set_used == wanderers) {
        return dmgbonus_p += 35;
    }
    std::cerr << "Wrong parameter values: artifact_dmg_bonus(int&, float&)\n";
    return -1;
} 
