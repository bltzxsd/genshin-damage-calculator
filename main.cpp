#include "include/inputhandler.h"
#include "include/weapon_stats.h"
#include "include/weapon_level.h"
#include "include/artifact_value.h"
#include "include/artifact_set.h"
#include "include/ganyu_level.h"
#include "include/dmg_calculation.h"
#include "include/talent_level.h"
#include "include/attack_output.h"

int main() {

    // Get level
    std::cout << "Enter your Ganyu's level: ";
    std::string ganyu_lvl = get_ganyuLevel();
    std::cout << "Your Ganyu's level is: " << ganyu_lvl << '\n';
    int ganyu_batk = ganyu_base_atk(ganyu_lvl); 
    float ganyu_cmdg_val = ganyu_cdmg(ganyu_lvl);
    ignore_line();
    std::cout << "Enter the total Crit Damage% on your character: ";
    float temp_cmdg_var{input_handler_num()};
    float end_ganyu_cmdg_val = {(temp_cmdg_var == 0) ? ganyu_cmdg_val : temp_cmdg_var};
    std::cout << "Crit DMG % on your character: " << end_ganyu_cmdg_val;
    std::cout << "\n\n";
    ignore_line();

    // Get weapon
    int weaponName{weapon_name()};
    ignore_line();
    std::string name_weapon{(weaponName == amos) ? "Amos Bow" : "Prototype Crescent"};
    std::cout << "Enter the level of your " << name_weapon << ": ";
    std::string weapon_level{level_chk(weaponName)};
    float weapon_substat{substat_chk(weaponName, weapon_level)};
    float dmgbonus_p{passive_chk(weaponName)};
    int weapon_base_dmg{base_dmg_weapon(weapon_level, weaponName)};
    std::cout << "\n\n";
    ignore_line();

    // Get which set is being used
    int artifact_set_used{artifact_set_chk()};
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

    int talent_lvl{talent_level_get()};
    get = AutoTalents.find(talent_lvl);

    std::cout << "\tFirst Hit Ratio:  " << first_atk_ratio  << '\n'
              << "\tSecond Hit Ratio: " << second_atk_ratio << '\n'
              << "\tThird Hit Ratio:  " << third_atk_ratio  << '\n'
              << "\tFourth Hit Ratio: " << fourth_atk_ratio << '\n'
              << "\tFifth Hit Ratio:  " << fifth_atk_ratio  << '\n'
              << "\tSixth Hit Ratio:  " << sixth_atk_ratio  << '\n'
              << "\tAim Shot Ratio:   " << aim_atk_ratio    << '\n'
              << "\tChargeShot Lvl 1 Ratio: " << charge_atk_ratio << '\n'
              << "\tFrostflake Arrow Ratio: " << frostflake_arrow << '\n'
              << "\tFrostflake Bloom Ratio: " << frostflake_bloom << '\n';

    int total_char_ATK{dmgCalc::basic_atk(characterbaseatk, total_perc_atk, total_flat_atk)};
    std::cout << "Total ATK of Character: " << total_char_ATK << '\n';
    /*std::cout << total_char_ATK << "\n";
    std::cout << "Total outgoing DMG of char:"
              << "\n\tFirst Hit DMG:  "
              << "\tSecond Hit DMG: " << second_atk_ratio << '\n'
              << "\tThird Hit DMG:  " << third_atk_ratio  << '\n'
              << "\tFourth Hit DMG: " << fourth_atk_ratio << '\n'
              << "\tFifth Hit DMG:  " << fifth_atk_ratio  << '\n'
              << "\tSixth Hit DMG:  " << sixth_atk_ratio  << '\n'
              << "\tAim Shot DMG:   " << aim_atk_ratio    << '\n'
              << "\tChargeShot Lvl1 DMG: " << charge_atk_ratio << '\n'
              << "\tFrostflake Arrow DMG: " << frostflake_arrow << '\n'
              << "\tFrostflake Bloom DMG: " << frostflake_bloom << '\n';*/
}
