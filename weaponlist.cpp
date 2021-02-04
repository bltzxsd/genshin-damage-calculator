#include "include/inputhandler.h"
#include "include/weapon_level.h"
#include "include/weaponlist.h"

std::string bows[] {
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
    "Amow bow"
};

int weapon_name() {
    // Gets weapon input from user. 
    std::cout << "Enter the weapon you have equipped: ";
    std::string weapon{input_handler_str()};
    for (int elements{0}; elements < (int) std::size(bows); ++elements) {
        if (weapon == bows[elements]) {
            if ((weapon[0] == 'P') || (weapon[0] == 'p')) {
                std::cout << "Your weapon is: Prototype Crescent" << std::endl;
                int prototype{PROTOTYPE};
                return prototype;
            } else {
                std::cout << "Your weapon is: Amos Bow" << std::endl;
                int amos{AMOS};
                return amos;
            }
        }
    }
    std::cout << "Invalid input. Please try again. weapon_name() failed." << std::endl;
    return 1;
}

int level_chk(int weapon_name) {
    if (weapon_name == PROTOTYPE) {
        std::cout << "Your Prototype Crescent level: ";
        std::string level{input_handler_str()};
        int level_num{std::stoi(level)};
        if (level_num % 5 != 0) {
            std::cout << "Invalid input. Levels are only accepted in increments of 5\n";
            return 1;
        }
        std::cout << "Weapon level is: " << std::stoi(level) << std::endl;
        int regular_level{(std::stoi(level) / 5) + 1};
        return regular_level;
    }
    else if (weapon_name == AMOS) {
        std::cout << "Your Amos Bow level: ";
        std::string level{input_handler_str()};
        int level_num{std::stoi(level)};
        if (level_num % 5 != 0) {
            std::cout << "Invalid input. Levels are only accepted in increments of 5\n";
            return 1;
        }
        std::cout << "Weapon level is: " << std::stoi(level) << std::endl;
        int regular_level{(std::stoi(level) / 5) + 1};
        return regular_level;
    }
    return 1;
}

float substat_chk(int weapon, int level) {
    if (weapon == PROTOTYPE) {
        float substat{prototype_substat[level]};
        std::cout << "Weapon substat is: " << substat << "% ATK" << '\n';
        return substat;
    } else if (weapon == AMOS) {
        float substat{amos_substat[level]};
        std::cout << "Weapon substat is: " << substat << "% ATK" << '\n';
        return substat;
    }
    std::cout << "Invalid input. Please try again. substat_chk() failed." << std::endl;
    return 1;
}

float passive_chk(int weapon_name) {
    if (weapon_name == PROTOTYPE) {
        std::cout << "Your Weapon passive is:\n\tUnreturning:\n\t\t";
        std::cout << "Charged Attack hits on weak points increase Movement SPD by 10 percent and ATK by 36 percent for 10s." << std::endl;
        return 36; // 36% ATK% boost on hitting weakponts.
    }
    if (weapon_name == AMOS) {
        std::cout << "Your weapon passive is:\n\tStrong-Willed:\n\t\tIncreases Normal Attack and Charged Attack DMG by 12%.";
        std::cout << "\n\t\tNormal and Charged Attack DMG increases by 8 percent every 0.1 seconds for up to 5 times." << std::endl;
        return 52; // 52% ATK% boost on reg shoot boost + 5 stacks of airtime boost
    }
    std::cout << "Invalid input. Please try again. passive_chk() failed." << std::endl;
    return 1;
}