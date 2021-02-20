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
    float elemental_bonus = ((artifact_set_used == blizzard) ? 15 : 0.0F);
    std::cout << "Enter the Cryo DMG Bonus% your Goblet of Eonothem has: ";
    float cryo_dmg_bonus = input_handler_range(0.0F, 46.6F);
    elemental_bonus += cryo_dmg_bonus;
    float regular_bonus = ((weaponName == amos) ? 52 : 0.0F);
    float total_dmg_boost = elemental_bonus + regular_bonus;

    std::cout << "\tFirst Hit Ratio:  " << first_atk_ratio << '\n'
              << "\tSecond Hit Ratio: " << second_atk_ratio << '\n'
              << "\tThird Hit Ratio:  " << third_atk_ratio << '\n'
              << "\tFourth Hit Ratio: " << fourth_atk_ratio << '\n'
              << "\tFifth Hit Ratio:  " << fifth_atk_ratio << '\n'
              << "\tSixth Hit Ratio:  " << sixth_atk_ratio << '\n'
              << "\tAim Shot Ratio:   " << aim_atk_ratio << '\n'
              << "\tChargeShot Lvl 1 Ratio: " << charge_atk_ratio << '\n'
              << "\tFrostflake Arrow Ratio: " << frostflake_arrow << '\n'
              << "\tFrostflake Bloom Ratio: " << frostflake_bloom << '\n';

    int total_char_ATK{dmgCalc::basic_atk(characterbaseatk, total_perc_atk, total_flat_atk)};
    std::cout << "Total ATK of Character: " << total_char_ATK << '\n';
    
    int first_hitD{dmgCalc::outgoing_dmg(total_char_ATK, first_atk_ratio, regular_bonus)};
    int second_hitD{dmgCalc::outgoing_dmg(total_char_ATK, second_atk_ratio, regular_bonus)};
    int third_hitD{dmgCalc::outgoing_dmg(total_char_ATK, third_atk_ratio, regular_bonus)}; 
    int fourth_hitD{dmgCalc::outgoing_dmg(total_char_ATK, fourth_atk_ratio, regular_bonus)};
    int fifth_hitD{dmgCalc::outgoing_dmg(total_char_ATK, fifth_atk_ratio, regular_bonus)};
    int sixth_hitD{dmgCalc::outgoing_dmg(total_char_ATK, sixth_atk_ratio, regular_bonus)};
    int aim_shotD{dmgCalc::outgoing_dmg(total_char_ATK, aim_atk_ratio, total_dmg_boost)};
    int charge_shotD{dmgCalc::outgoing_dmg(total_char_ATK, charge_atk_ratio, total_dmg_boost)};
    int frostflake_arrowD{dmgCalc::outgoing_dmg(total_char_ATK, frostflake_arrow, total_dmg_boost)};
    int frostflake_bloomD{dmgCalc::outgoing_dmg(total_char_ATK, frostflake_bloom, total_dmg_boost)};
    
    std::cout << total_char_ATK << "\n";
    std::cout << "Total outgoing DMG of char:"
              << "\n\tFirst Hit DMG:  " << first_hitD << "\n"
              << "\tSecond Hit DMG: " << second_hitD << '\n'
              << "\tThird Hit DMG:  " << third_hitD << '\n'
              << "\tFourth Hit DMG: " << fourth_hitD << '\n'
              << "\tFifth Hit DMG:  " << fifth_hitD << '\n'
              << "\tSixth Hit DMG:  " << sixth_hitD << '\n'
              << "\tAim Shot DMG:   " << aim_shotD << '\n'
              << "\tChargeShot Lvl1 DMG: " << charge_shotD << '\n'
              << "\tFrostflake Arrow DMG: " << frostflake_arrowD << '\n'
              << "\tFrostflake Bloom DMG: " << frostflake_bloomD << '\n';
    std::cout << "Please press the Enter key to quit the program.\n\n";
    getchar();
}
