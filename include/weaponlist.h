#ifndef WEAPON_LIST
#define WEAPON_LIST
    #include <string>
    #include <iostream>
    #include <array>

    extern std::string bows[];
    int weapon_name();
    int level_chk(int);
    float substat_chk(int);
    float passive_chk(float);
#endif