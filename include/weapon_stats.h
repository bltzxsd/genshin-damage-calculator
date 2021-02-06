#ifndef WEAPON_LIST
#define WEAPON_LIST
#include <string>
#include <iostream>
#include <array>

extern std::string bows[];
int weapon_name();
std::string level_chk(int);
float substat_chk(int, std::string);
float passive_chk(float);
#endif