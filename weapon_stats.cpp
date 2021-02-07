#include "include/inputhandler.h"
#include "include/weapon_level.h"
#include "include/weapon_stats.h"

std::string bows[]{
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

int weapon_name()
{
    // Gets weapon input from user.
    std::cout << "Enter the weapon you have equipped: ";
    std::string weapon{string_input()};
    for (int elements{0}; elements < (int)std::size(bows); ++elements)
    {
        if (weapon == bows[elements])
        {
            if ((weapon[0] == 'P') || (weapon[0] == 'p'))
            {
                std::cout << "Your weapon is: Prototype Crescent" << std::endl;
                int prototype{PROTOTYPE};
                return prototype;
            }
            else
            {
                std::cout << "Your weapon is: Amos Bow" << std::endl;
                int amos{AMOS};
                return amos;
            }
        }
    }
    std::cout << "Invalid input. Please try again. weapon_name() failed." << std::endl;
    return 1;
}

std::string level_chk(int weapon_name)
{
    // There is no viable way I have found to calculate the substat and base damage from level.
    // Mihoyo has forced my hand to create this mess. Too bad!
    if (weapon_name == PROTOTYPE)
    {
        std::string input{string_input()};
        auto get = PrototypeCrescent.find(input);
        // Check if the value provided by input is in the map.
        if (get == PrototypeCrescent.end())
        {
            std::cout << "Value does not exist. Please try again\n";
            return NULL;
        }
        else
        {
            std::cout << "Base Damage of your Prototype Crescent is: " << get->second.base_damage << '\n';
            return input;
        }
    }
    else if (weapon_name == AMOS)
    {
        std::string input{string_input()};
        auto get = AmosBow.find(input);
        // Check if the value provided by input is in the map.
        if (get == AmosBow.end())
        {
            std::cout << "Value does not exist. Please try again\n";
            return NULL;
        }
        else
        {
            std::cout << "Base Damage of your Amos Bow is: " << get->second.base_damage << '\n';
            return input;
        }
    }
    return NULL;
}

float passive_chk(int weapon_name)
{
    if (weapon_name == PROTOTYPE)
    {
        std::cout << "Your Weapon passive is:\n\tUnreturning:\n\t\t";
        std::cout << "Charged Attack hits on weak points increase Movement SPD by 10 percent and ATK by 36 percent for 10s." << std::endl;
        return CRESCENT_PASSIVE_BOOST; // 36% ATK% boost on hitting weakponts.
    }
    if (weapon_name == AMOS)
    {
        std::cout << "Your weapon passive is:\n\tStrong-Willed:\n\t\tIncreases Normal Attack and Charged Attack DMG by 12%.";
        std::cout << "\n\t\tNormal and Charged Attack DMG increases by 8 percent every 0.1 seconds for up to 5 times." << std::endl;
        return AMOS_PASSIVE_BOOST; //  + 12% DMG boost on reg shoot boost + 5 stacks of airtime boost of 8%
    }
    std::cerr << "passive_chk() failed.\n";
    return 1;
}

float substat_chk(int weapon_name, std::string weapon_level)
{
    if (weapon_name == PROTOTYPE)
    {
        auto get = PrototypeCrescent.find(weapon_level);
        std::cout << "Substat ATK boost of your Amos Bow is: " << get->second.substat << "%\n";
        return get->second.substat;
    }
    if (weapon_name == AMOS)
    {
        auto get = AmosBow.find(weapon_level);
        return get->second.substat;
    }
    return 1;
}
