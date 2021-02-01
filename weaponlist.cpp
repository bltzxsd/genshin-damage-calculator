#include <string>
#include <iostream>
#include "include/inputhandler.h"

std::string bows[] = {
    "Prototype Crescent",
    "Amos Bow",
    "prototype crescent",
    "prototype",
    "Prototype",
    "prototype Crescent",
    "Prototype crescent",
    "amos bow",
    "amos",
    "Amos",
    "amos Bow",
    "Amow bow"};

int weapon_name() {
    // Gets weapon input from user. 
    std::cout << "Enter the weapon you have equipped: ";
    std::string weapon{input_handler_str()};
    for (int elements{0}; elements < std::size(bows); ++elements) {
        if (weapon == bows[elements]) {
            if ((weapon[0] == 'P') || (weapon[0] == 'p')) {
                std::cout << "Your weapon is: Prototype Crescent" << std::endl;
                int prototype{99};
                return prototype;
            } else {
                std::cout << "Your weapon is: Amos Bow" << std::endl;
                int amos{98};
                return amos;
            }
        }
    }
    return false;
}