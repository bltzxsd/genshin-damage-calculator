#include <algorithm>
#include "include/inputhandler.h"
#include "weaponlist.cpp"

int main() {

    // Get level
    std::cout << "Enter your Ganyu's level: ";
    int level{input_handler_range(1, 90, "Your Ganyu's level: ")};
    std::cout << "Your Ganyu's level is: " << level << std::endl;
    ignore_line();
    
    // Get weapon
    int weapon{weapon_name()};
    ignore_line();
    substat_chk(weapon);
}
