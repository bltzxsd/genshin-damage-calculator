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
    int weaponName{weapon_name()};
    ignore_line();
    std::string weapon_level{level_chk(weaponName)};
    ignore_line();

    // float passive{passive_chk(weapon)};
}
