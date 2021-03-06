#ifndef WEAPON_LEVEL
#define WEAPON_LEVEL

extern const int prototype;
extern const int amos;

#include <unordered_map>
#include <string>

struct Weapon{ int base_damage; float substat; };
const std::unordered_map<std::string, Weapon> AmosBow = {
    {"1",   {46, (float)10.8}},
    {"5",   {62, 12.5}},
    {"10",  {82, 14.7}},
    {"15",  {102, 16.9}},
    {"20",  {122, 19.1}},
    {"20A", {153, 19.1}},
    {"25",  {173, 21.3}},
    {"30",  {194, 23.4}},
    {"35",  {214, 25.6}},
    {"40",  {235, 27.8}},
    {"40A", {266, 27.8}},
    {"45",  {287, (float)30}},
    {"50",  {308, 32.2}},
    {"50A", {340, 32.2}},
    {"55",  {361, 34.4}},
    {"60",  {382, 36.5}},
    {"60A", {414, 36.5}},
    {"65",  {435, 38.7}},
    {"70",  {457, 40.9}},
    {"70A", {488, 40.9}},
    {"75",  {510, 43.1}},
    {"80",  {532, 45.3}},
    {"80A", {563, 45.3}},
    {"85",  {586, 49.4}},
    {"90",  {608, 49.6}}
};

const std::unordered_map<std::string, Weapon> PrototypeCrescent = {
    {"1",   {42, (float)9}},
    {"5",   {56, 10.5}},
    {"10",  {74, 12.3}},
    {"15",  {91, 14.1}},
    {"20",  {109, 15.9}},
    {"20A", {135, 15.9}},
    {"25",  {152, 17.7}},
    {"30",  {170, 19.5}},
    {"35",  {187, 21.4}},
    {"40",  {205, 23.2}},
    {"40A", {231, 23.2}},
    {"45",  {248, (float)25}},
    {"50",  {266, 26.8}},
    {"50A", {292, 26.8}},
    {"55",  {309, 28.6}},
    {"60",  {327, 30.4}},
    {"60A", {353, 30.4}},
    {"65",  {370, 32.3}},
    {"70",  {388, 34.1}},
    {"70A", {414, 34.1}},
    {"75",  {431, 35.9}},
    {"80",  {475, 37.7}},
    {"80A", {492, 37.7}},
    {"85",  {510, 39.5}},
    {"90",  {510, 41.3}}
};
#endif  