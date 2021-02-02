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

float substat_chk(int weapon) {

    if (weapon == 99) {
        float passive{41.3}; // ATK% Boost of 41.3% on Prototype Crescent
        std::cout << "\tWeapon Substat is " << passive << " percent ATK bonus." << std::endl;
        return passive;
    } else if (weapon == 98) {
        float passive{49.6}; // ATK% Boost of 49.6% on Amos Bow
        std::cout << "\tWeapon Substat is " << passive << " percent ATK bonus." << std::endl;
        return passive;
    }
    std::cout << "Invalid input. Please try again." << std::endl;
    return 1;
}

float passive_chk(float substat_chk) {
    float prototype_passive{41.3};
    if (substat_chk == prototype_passive) {
        std::cout << " Weapon passive is:\n\tUnreturning:\n\t\t";
        std::cout << "Charged Attack hits on weak points increase Movement SPD by 10 percent and ATK by 36 percent for 10s." << std::endl;
        return 36; // 36% ATK% boost on hitting weakponts.
    }
    float amos_passive{49.6};
    if (substat_chk == amos_passive) {
        std::cout << "Your weapon passive is:\n\tStrong-Willed:\n\t\tIncreases Normal Attack and Charged Attack DMG by 12%.";
        std::cout << "\tNormal and Charged Attack DMG increases by 8 percent every 0.1 seconds for up to 5 times." << std::endl;
        return 52; // 52% ATK% boost on reg shoot boost + 5 stacks of airtime boost
    }
    std::cout << "Invalid input. Please try again." << std::endl;
    return 1;
}