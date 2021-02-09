// Formalas: 
// Outgoing DMG = ATK x %SKILL (talent) x (1 + dmg bonus)
// ATK = ATK Base x (1 + %atk) + atkflat
// Outgoing Crit DMG = DMG x (1 + %CDMG) 
// Cryo transformative reaction: 
// DMG = DMG (RAW) x (reaction multiplier (1.5)) x
// (1 + %EM Bonus + % Reaction Bonus (artifacs for melt/vaporize)) x
// (1 + %dmgbonus trigger element + %dmg bonus general) x 
// (1 + %cmdg) [if crit] 
// %EM bonus = 2.78 x (EM) / (EM + 1400)

#include "include/dmg_calculation.h"

int crit_dmg(int damage, float cdmgPercentage) {
    return damage * (1 + cdmgPercentage);
}
int em_perc_bonus(int elemental_mastery) {
    return 2.78 * ((elemental_mastery) / (elemental_mastery + 1400));
}
int basic_atk(int baseATK, float atk_percentage, int flat_atk) {    
    return baseATK * (1 + atk_percentage) + flat_atk;
}
int outgoing_dmg(int atk, int talent_percent, int damage_bonus) {
    return atk * talent_percent * (1 + damage_bonus);
}
int amping_dmg(int dmg, float embonus_perc, int dmg_bonus) {
    const float reaction_multiplier{1.5};
    float final_dmg{(dmg * reaction_multiplier) 
                    * (1 + embonus_perc + 0 /*reaction bonus*/ )
                    * (1 + dmg_bonus + 0 /*dmg bonus*/) };
    return  final_dmg;
}
