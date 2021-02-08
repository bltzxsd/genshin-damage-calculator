#include "include/inputhandler.h"
#include "include/weapon_stats.h"
#include "include/weapon_level.h"
#include "include/artifact_value.h"
#include "include/artifact_set.h"

int main() {

    // Get level
    std::cout << "Enter your Ganyu's level: ";
    auto char_level{input_handler_range(1, 90)};
    std::cout << "Your Ganyu's level is: " << char_level << std::endl;
    ignore_line();

    // Get weapon
    int weaponName{weapon_name()};
    ignore_line();
    std::string name_weapon{(weaponName == AMOS) ? "Amos Bow" : "Prototype Crescent"};
    std::cout << "Enter the level of your " << name_weapon << ": ";
    std::string weapon_level{level_chk(weaponName)};
    float weapon_substat{substat_chk(weaponName, weapon_level)};
    passive_chk(weaponName);
    ignore_line();

    // Get which set is being used
    artifact_set_chk();
    ignore_line();
    // Get Flat ATK from artifact
    flat_atk_get();
    // Get ATK% from artifact
    atk_perc_get();

    // calculate the sum of all flat atk given
    int total_flat_atk{0};
    for (auto& x : flat_atk) {
        total_flat_atk += x;
    }
    // calculate the sum of all atk% given
    int total_perc_atk{0};
    for (auto& x : atk_percent) {
        total_perc_atk += x;
    }

    std::cout << "Total flat ATK: " << total_flat_atk << '\n'
              << "Total ATK%: " << total_perc_atk << '%' << '\n';
}
