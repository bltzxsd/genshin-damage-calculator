#include "include/ganyu_level.h" 

std::string get_ganyuLevel() {
    std::string input{string_input()};
    auto get = GanyuStats.find(input);
    if (get == GanyuStats.end()) {
        std::cout << "Level does not exist.\n" 
                  << "Levels are only accepted as max in the format. Example: "
                  << "1, 20, 20+ ... where + is ascended."; 
        return NULL;
    } else {
        return input;
    }
}

int ganyu_base_atk(std::string level) {
    auto get = GanyuStats.find(level);
    auto base_atk{get->second.base_atk};
    std::cout << "Base ATK of your Ganyu is: " << base_atk << '\n';
    return base_atk;
}

float ganyu_cdmg(std::string level) {
    auto get = GanyuStats.find(level);
    auto cdmg{get->second.cdmg};
    std::cout << "Crit DMG provided by Ascension Stat is: " << cdmg << "%\n";
    return cdmg; 
}

