#include "include/inputhandler.h"
#include "include/weaponlist.h"
#include "include/weapon_level.h"

int main() {

    // Get level
    std::cout << "Enter your Ganyu's level: ";
    int char_level{input_handler_range(1, 90, "Your Ganyu's level: ")};
    std::cout << "Your Ganyu's level is: " << char_level << std::endl;
    ignore_line();
    
    // Get weapon
    int weapon{weapon_name()};
    ignore_line();
    int weapon_level{level_chk(weapon)};
    if (weapon_level == 1) {
        std::cout << "Invalid input. Please try again.";
    } else {
        float substat{substat_chk(weapon, weapon_level)};
    }
    
    // float passive{passive_chk(weapon)};
}
