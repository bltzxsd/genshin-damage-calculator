#ifndef WEAPON_LIST
#define WEAPON_LIST
#include <string>
#include <iostream>
#include <array>

#define AMOS_PASSIVE_BOOST 52
#define CRESCENT_PASSIVE_BOOST 36

extern std::string bows[];
int weapon_name();
std::string level_chk(int);
float substat_chk(int, std::string);
float passive_chk(int);
#endif