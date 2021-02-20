#include "include/inputhandler.h"
#include "include/weapon_level.h"
#include "include/weapon_stats.h"

std::string bows[12] {
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

const int crescent_passive_boost{36};
const int amos_passive_boost{52};
const int prototype{99};
const int amos{98};

int weapon_name() {
    // Gets weapon input from user. 
    std::cout << "Enter the weapon you have equipped: ";
    std::string weapon{string_input()};
    for (std::size_t elements{0}; elements <= std::size(bows); ++elements) {
        if (weapon == bows[elements]) {
            if ((weapon[0] == 'P') || (weapon[0] == 'p')) {
                std::cout << "Your weapon is: Prototype Crescent" << std::endl;
                return prototype;
            } else {
                std::cout << "Your weapon is: Amos Bow" << std::endl;
                return amos;
            }
        }
    }
    std::cout << "Invalid input. Please try again. weapon_name() failed." << std::endl;
    return 1;
}

std::string level_chk(int weapon_name) {
    // There is no viable way I have found to calculate the substat and base damage from level.
    // Mihoyo has forced my hand to create this mess. Too bad! 
    if (weapon_name == prototype) {
        std::string input {string_input()};
        auto get = PrototypeCrescent.find(input);
        // Check if the value provided by input is in the map.
        if (get == PrototypeCrescent.end()) {
            std::cout << "Value does not exist. Please try again\n";
            return NULL;
        } else {
            std::cout << "Base Damage of your Prototype Crescent is: " << get -> second.base_damage << '\n';
            return input;
        }
    } else if (weapon_name == amos) {
        std::string input {string_input()};
        auto get = AmosBow.find(input);
        // Check if the value provided by input is in the map.
        if (get == AmosBow.end()) {
            std::cout << "Value does not exist. Please try again\n";
            return NULL;
        } else {
            std::cout << "Base Damage of your Amos Bow is: " << get -> second.base_damage << '\n';
            return input;
        }

    }
    return NULL;
}

float substat_chk(int weapon_name, std::string weapon_level) {
    if (weapon_name == prototype) {
        auto get = PrototypeCrescent.find(weapon_level);
        std::cout << "Substat ATK% boost of your Prototype Crescent is: " << get -> second.substat << "%\n";
        return get -> second.substat;
    }
    if (weapon_name == amos) {
        auto get = AmosBow.find(weapon_level);
        std::cout << "Substat ATK% boost of your Amos Bow is: " << get -> second.substat << "%\n";
        return get -> second.substat;
    }
    return 1;
}

int base_dmg_weapon(std::string weapon_level, int weapon_name) {
    if (weapon_name == prototype) {
        auto get = PrototypeCrescent.find(weapon_level);
        return get -> second.base_damage;
    }
    if (weapon_name == amos) {
        auto get = AmosBow.find(weapon_level);
        return get -> second.base_damage;
    }
    return -1;
}
