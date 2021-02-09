#include "include/talent_level.h"

int talent_level_get() {
    std::cout << "Enter your Auto attacks (LMB) Talent Level: ";
    auto input{input_handler_range<int>(1, 11)};
    auto get = AutoTalents.find(input);
    if (get == AutoTalents.end()) {
        std::cout << "Talent level does not exist. Please try again."
                  << "Talent levels are only accepted in the range of 1 to 11: ";
    } else {
        return input;
    }
    return 1;
}

int auto_talent_lvl = 0;
std::unordered_map<int, Talent>::const_iterator get;
float auto_first_atk(int talent_level) {
    float first_atk{get->second.first_hit};
    return first_atk;
}
float auto_second_atk(int talent_level) {
    float second_atk{get->second.second_hit};
    return second_atk;
}
float auto_third_atk(int talent_level) {
    float third_atk{get->second.third_hit};
    return third_atk;
}
float auto_fourth_atk(int talent_level) {
    float fourth_atk{get->second.fouth_hit};
    return fourth_atk;
}
float auto_fifth_atk(int talent_level) {
    float fifth_atk{get->second.fifth_hit};
    return fifth_atk;
}
float auto_sixth_atk(int talent_level) {
    float sixth_atk{get->second.sixth_hit};
    return sixth_atk;
}
float auto_aimshot(int talent_level) {
    float aimshot{get->second.aim_shot};
    return aimshot;
}
float auto_chargeshot(int talent_level) {
    float chargedshot{get->second.charge_shot_level_one};
    return chargedshot;
}
float auto_frostflake(int talent_level) {
    float frostflake_arrow{get->second.frostflake_arrow};
    return frostflake_arrow;
}
float auto_frostflake_bloom(int talent_level) {
    float frostflake_bloom{get->second.frostflake_arrow_bloom};
    return frostflake_bloom;
}
