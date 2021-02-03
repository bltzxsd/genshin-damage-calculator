#include "include/inputhandler.h"
#include "weaponlist.cpp"

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
    float substat{substat_chk(weapon)};
    float passive{passive_chk(substat)};
}
