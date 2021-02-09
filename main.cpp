#include "include/inputhandler.h"
#include "include/weapon_stats.h"
#include "include/weapon_level.h"
#include "include/artifact_value.h"
#include "include/artifact_set.h"
#include "include/ganyu_level.h"
// #include "include/dmg_calculation.h"
#include "include/talent_level.h"

int main() {

    // Get level
    std::cout << "Enter your Ganyu's level: ";
    std::string ganyu_lvl = get_ganyuLevel();
    std::cout << "Your Ganyu's level is: " << ganyu_lvl << '\n';
    int ganyu_batk = ganyu_base_atk(ganyu_lvl); 
    float ganyu_cmdg = ganyu_cdmg(ganyu_lvl);
    std::cout << "\n\n";
    ignore_line();

    // Get weapon
    auto weaponName{weapon_name()};
    ignore_line();
    std::string name_weapon{(weaponName == AMOS) ? "Amos Bow" : "Prototype Crescent"};
    std::cout << "Enter the level of your " << name_weapon << ": ";
    std::string weapon_level{level_chk(weaponName)};
    float weapon_substat{substat_chk(weaponName, weapon_level)};
    float dmgbonus_p{passive_chk(weaponName)};
    int weapon_base_dmg{base_dmg_weapon(weapon_level, weaponName)};
    std::cout << "\n\n";
    ignore_line();

    // Get which set is being used
    artifact_set_chk();
    ignore_line();
    // Get Flat ATK from artifact
    flat_atk_get();
    // Get ATK% from artifact
    atk_perc_get();

    // calculate the sum of all flat atk given
    int characterbaseatk{ganyu_batk + weapon_base_dmg};
    int total_flat_atk{0};
    for (auto& x : flat_atk) {
        total_flat_atk += x;
    }
    // calculate the sum of all atk% given
    float total_perc_atk{weapon_substat};
    for (auto& x : atk_percent) {
        total_perc_atk += x;
    }

    // Calculating final values to be passed: 
    std::cout << "Total flat ATK: " << total_flat_atk << '\n'
              << "Total ATK%: " << total_perc_atk << '%' << '\n';
    
    auto_talent_lvl = talent_level_get();
    get = AutoTalents.find(auto_talent_lvl);
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

    std::cout << "\tFirst Hit Ratio:  " << first_atk_ratio  << '\n'
              << "\tSecond Hit Ratio: " << second_atk_ratio << '\n'
              << "\tThird Hit Ratio:  " << third_atk_ratio  << '\n'
              << "\tFourth Hit Ratio: " << fourth_atk_ratio << '\n'
              << "\tFifth Hit Ratio:  " << fifth_atk_ratio  << '\n'
              << "\tSixth Hit Ratio:  " << sixth_atk_ratio  << '\n'
              << "\tAim Shot Ratio:   " << aim_atk_ratio    << '\n'
              << "\tChargeShot Lvl 1: " << charge_atk_ratio << '\n'
              << "\tFrostflake Arrow: " << frostflake_arrow << '\n'
              << "\tFrostflake Bloom: " << frostflake_bloom << '\n';

}
