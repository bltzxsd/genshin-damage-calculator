#ifndef GANYU_LEVEL_H
#define GANYU_LEVEL_H

#include "inputhandler.h"
#include <unordered_map>

struct CharGanyu { int base_atk; float cdmg; };

const std::unordered_map<std::string, CharGanyu> GanyuStats = {
    {"1",   {26,  50.0}},
    {"20",  {68,  50.0}},
    {"20+", {90,  50.0}},
    {"40",  {135, 50.0}},
    {"40+", {151, 59.6}},
    {"50",  {173, 59.6}},
    {"50+", {194, 69.2}},
    {"60",  {217, 69.2}},
    {"60+", {233, 69.2}},
    {"70",  {256, 69.2}},
    {"70+", {272, 78.8}},
    {"80",  {295, 78.8}},
    {"80+", {311, 88.4}},
    {"90",  {335, 88.4}},
};
std::string get_ganyuLevel();
int ganyu_base_atk(std::string);
float ganyu_cdmg(std::string);

#endif 