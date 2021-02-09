#ifndef TALENT_LEVEL
#define TALENT_LEVEL

#include "inputhandler.h"
#include <unordered_map>

struct Talent {
    float first_hit;
    float second_hit;
    float third_hit;
    float fouth_hit;
    float fifth_hit;
    float sixth_hit;
    float aim_shot;
    float charge_shot_level_one;
    float frostflake_arrow;
    float frostflake_arrow_bloom;
};

const std::unordered_map<int, Talent> AutoTalents {
    {1,  {31.73, 35.60, 45.49, 45.49, 48.25, 57.62 , 43.86, 124.0, 128.0, 217.60}},
    {2,  {34.32, 38.50, 49.20, 49.20, 52.17, 62.31 , 47.43, 133.3, 137.6, 233.92}},
    {3,  {36.90, 41.40, 52.90, 52.90, 56.10, 67.00 , 51.00, 142.6, 147.2, 250.24}},
    {4,  {40.59, 45.54, 58.19, 58.19, 61.71, 73.70 , 56.10, 155.0, 160.0, 272.00}},
    {5,  {43.70, 48.44, 61.89, 61.89, 65.64, 78.39 , 59.67, 164.3, 169.6, 288.32}},
    {6,  {46.13, 51.75, 66.13, 66.13, 70.13, 83.75 , 63.75, 173.6, 179.2, 304.64}},
    {7,  {50.18, 56.30, 71.94, 71.94, 76.3 , 91.12 , 69.36, 186.0, 192.0, 326.40}},
    {8,  {54.24, 60.86, 77.76, 77.76, 82.47, 98.49 , 74.97, 198.4, 204.8, 348.16}},
    {9,  {58.30, 65.41, 83.58, 83.58, 88.64, 105.86, 80.58, 210.8, 217.6, 369.68}},
    {10, {67.23, 70.38, 89.93, 89.93, 95.37, 113.9 , 86.70, 223.2, 230.4, 391.68}},
    {11, {67.80, 76.07, 97.20, 97.20, 103.08, 123.11, 92.82, 235.6, 243.2, 413.44}}
};
extern std::unordered_map<int, Talent>::const_iterator get;
extern int auto_talent_lvl;
int talent_level_get();
float auto_first_atk(int);
float auto_second_atk(int);
float auto_third_atk(int);
float auto_fourth_atk(int);
float auto_fifth_atk(int);
float auto_sixth_atk(int);
float auto_aimshot(int);
float auto_chargeshot(int);
float auto_frostflake(int);
float auto_frostflake_bloom(int);

#endif