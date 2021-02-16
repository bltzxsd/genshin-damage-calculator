#ifndef WEAPON_LIST
#define WEAPON_LIST
#include <string>
#include <iostream>
#include <array>

extern const int crescent_passive_boost;
extern const int amos_passive_boost;

extern std::string bows[];
int weapon_name();
std::string level_chk(int);
float substat_chk(int, std::string);
float passive_chk(int);
int base_dmg_weapon(std::string, int);
#endif