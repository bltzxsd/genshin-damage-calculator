#include "include/attack_output.h"

float first_atk_ratio{auto_first_atk(auto_talent_level)};
float second_atk_ratio{auto_second_atk(auto_talent_level)};
float third_atk_ratio{auto_third_atk(auto_talent_level)};
float fourth_atk_ratio{auto_fourth_atk(auto_talent_level)};
float fifth_atk_ratio{auto_fifth_atk(auto_talent_level)};
float sixth_atk_ratio{auto_sixth_atk(auto_talent_level)};
float aim_atk_ratio{auto_aimshot(auto_talent_level)};
float charge_atk_ratio{auto_chargeshot(auto_talent_level)};
float frostflake_arrow{auto_frostflake(auto_talent_level)};
float frostflake_bloom{auto_frostflake_bloom(auto_talent_level)};

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

