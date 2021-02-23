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
    float temp_cmdg_var{input_handler_range(0.0F, 307.F)};
    float end_ganyu_cmdg_val = {(temp_cmdg_var <= ganyu_cmdg_val) ? ganyu_cmdg_val : temp_cmdg_var};
    std::cout << "  Crit DMG % on your character: " << end_ganyu_cmdg_val << "%\n\n";
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
    std::cout << "Enter the Cryo DMG Bonus% your Goblet of Eonothem has: ";
    ignore_line();
    float cryo_dmg_bonus = input_handler_range(0.0F, 46.6F);
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

    int talent_lvl{talent_level_get()};
    get = AutoTalents.find(talent_lvl);
    float elemental_bonus = ((artifact_set_used == blizzard) ? 15 : 0.0F);
    elemental_bonus += cryo_dmg_bonus;
    float regular_bonus = ((weaponName == amos) ? 52 : 0.0F);
    float total_dmg_boost = elemental_bonus + regular_bonus;
    std::string artifact_name{(artifact_set_used == 15) ? "Blizzard Strayer" : "Wanderer's Troupe"};

    int total_char_ATK{dmgCalc::basic_atk(characterbaseatk, total_perc_atk, total_flat_atk)};

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
    
    std::cout << " Report ------------------------------------------------------------------------"
              << "\n  Ganyu Stats:\n"
              << "     Ganyu Base ATK           -> " << ganyu_batk << '\n'
              << "     Equipped Weapon          -> " << name_weapon << '\n'
              << "     Weapon Base ATK          -> " << weapon_base_dmg << '\n'
              << "     Total ATK                -> " << total_char_ATK << '\n'
              << "     Crit DMG %               -> " << end_ganyu_cmdg_val << "%\n"
              << "     Artifact Set             -> " << artifact_name << '\n'
              << "     Non-Elemental DMG bonus  -> " << regular_bonus << "%\n"
              << "     Elemental DMG bonus      -> " << elemental_bonus << "%\n"
              << "     Total DMG bonus          -> " << total_dmg_boost << "%\n"
              << "     Auto attack Talent Level -> " << talent_lvl << '\n';
    
    std::cout << "\n  Ratio of Auto Attacks:\n"
              << "     First Hit Ratio          -> " << first_atk_ratio << "%\n"
              << "     Second Hit Ratio         -> " << second_atk_ratio << "%\n"
              << "     Third Hit Ratio          -> " << third_atk_ratio << "%\n"
              << "     Fourth Hit Ratio         -> " << fourth_atk_ratio << "%\n"
              << "     Fifth Hit Ratio          -> " << fifth_atk_ratio << "%\n"
              << "     Sixth Hit Ratio          -> " << sixth_atk_ratio << "%\n"
              << "     Aim Shot Ratio           -> " << aim_atk_ratio << "%\n"
              << "     ChargeShot Lvl 1 Ratio   -> " << charge_atk_ratio << "%\n"
              << "     Frostflake Arrow Ratio   -> " << frostflake_arrow << "%\n"
              << "     Frostflake Bloom Ratio   -> " << frostflake_bloom << "%\n";


    std::cout << " \n\n   | Regular DMG                  \t| Crit DMG\t                        |\n"
              << "   |------------------------------------+---------------------------------------|"
              << "\n   | First Hit DMG:\t\t" << first_hitD << "\t|"
              << " First Hit Crit DMG:\t\t" << dmgCalc::crit_dmg(first_hitD, end_ganyu_cmdg_val) << "\t|\n"

              << "   | Second Hit DMG:\t\t" << second_hitD << "\t|"
              << " Second Hit Crit DMG:\t\t" << dmgCalc::crit_dmg(second_hitD, end_ganyu_cmdg_val) << "\t|\n"

              << "   | Third Hit DMG:\t\t" << third_hitD << "\t|"
              << " Third Hit Crit DMG:\t\t" << dmgCalc::crit_dmg(third_hitD, end_ganyu_cmdg_val) << "\t|\n"

              << "   | Fourth Hit DMG:\t\t" << fourth_hitD << "\t|"
              << " Fourth Hit Crit DMG:\t\t" << dmgCalc::crit_dmg(fourth_hitD, end_ganyu_cmdg_val) << "\t|\n"

              << "   | Fifth Hit DMG:\t\t" << fifth_hitD << "\t|"
              << " Fifth Hit Crit DMG:\t\t" << dmgCalc::crit_dmg(fifth_hitD, end_ganyu_cmdg_val) << "\t|\n"

              << "   | Sixth Hit DMG:\t\t" << sixth_hitD << "\t|"
              << " Sixth Hit Crit DMG:\t\t" << dmgCalc::crit_dmg(sixth_hitD, end_ganyu_cmdg_val) << "\t|\n"

              << "   | Aim Shot DMG:\t\t" << aim_shotD << "\t|"
              << " Aim Shot Crit DMG:\t\t" << dmgCalc::crit_dmg(aim_shotD, end_ganyu_cmdg_val) << "\t|\n"

              << "   | ChargeShot Lvl 1 DMG:\t" << charge_shotD << "\t|"
              << " ChargeShot Lvl 1 Crit DMG:\t" << dmgCalc::crit_dmg(charge_shotD, end_ganyu_cmdg_val) << "\t|\n"

              << "   | Frostflake Arrow DMG:\t" << frostflake_arrowD << "\t|"
              << " Frostflake Arrow Crit DMG:\t" << dmgCalc::crit_dmg(frostflake_arrowD, end_ganyu_cmdg_val) << "\t|\n"

              << "   | Frostflake Bloom DMG:\t" << frostflake_bloomD << "\t|"
              << " Frostflake Bloom Crit DMG:\t" << dmgCalc::crit_dmg(frostflake_bloomD, end_ganyu_cmdg_val) << "\t|\n";

    std::cout << "Notice: These numbers are raw in value.\n"
              << "        These do not reflect accurately with resistances of each enemy type.\n"
              << "        Actual in-game values may or may not be lower than displayed here.\n";
}
