#include "include/artifact_value.h"

int flat_atk[5]{0, 0, 0, 0, 0};
float atk_percent[5]{0.0F, 0.0F, 0.0F, 0.0F, 0.0F};

void flat_atk_get() {
    for (size_t x = 0; x <= 5; ++x) {
        switch (x) {
            case 1: {
                std::cout << "Enter the total FLAT ATK on your Circlet of Logos (substat): ";
                int circlet{input_handler_range<int>(0, MAX_FLAT_ATK)};
                flat_atk[0] = circlet;
                ignore_line();
            break;
            }
            case 2: {
                std::cout << "Enter the total FLAT ATK on your Goblet of Eonothem (substat): ";
                int goblet{input_handler_range<int>(0, MAX_FLAT_ATK)};
                flat_atk[1] = goblet;
                ignore_line();
            break;
            }
            case 3: {
                std::cout << "Enter the total FLAT ATK on your Sands of Eon (substat): ";
                int cup{input_handler_range<int>(0, MAX_FLAT_ATK)};
                flat_atk[2] = cup;
                ignore_line();
            break;
            }
            case 4: {
                std::cout << "Enter the total FLAT ATK on your Flower of Life (substat): ";
                int flower{input_handler_range<int>(0, MAX_FLAT_ATK)};
                flat_atk[3] = flower;
                ignore_line();
            break;
            }
            case 5: {
                std::cout << "Enter the FLAT ATK on your Plume Of Death (mainstat): ";
                int feather{input_handler_range<int>(0, FEATHER_FLAT_MAX_ATK)};
                flat_atk[4] = feather;
                ignore_line();
            break;
            }
            default: { break; }
        }
    }
    std::cout << '\n';
}

void atk_perc_get() {
    for (size_t x = 0; x <= 5; ++x) {
        switch (x) {
            case 1: {
                std::cout << "Enter the total ATK% on your Circlet of Logos (substat/mainstat): ";
                float circlet{input_handler_range<float>(0, (float) MAX_MAINS_ATKP)};
                atk_percent[0] = circlet;
                ignore_line();
                break;
            }
            case 2: {
                std::cout << "Enter the total ATK% on your Goblet of Eonothem (substat/mainstat): ";
                float goblet{input_handler_range<float>(0, (float) MAX_MAINS_ATKP)};
                atk_percent[1] = goblet;
                ignore_line();
                break;
            }
            case 3: {
                std::cout << "Enter the total ATK% on your Sands of Eon (mainstat/substat): ";
                float cup{input_handler_range<float>(0, (float) MAX_MAINS_ATKP)};
                atk_percent[2] = cup;
                ignore_line();
                break;
            }
            case 4: {
                std::cout << "Enter the total ATK% on your Flower of Life (substat): ";
                float flower{input_handler_range<float>(0, (float) MAX_SUB_ATKP)};
                atk_percent[3] = flower;
                ignore_line();
                break;
            }
            case 5: {
                std::cout << "Enter the total ATK% on your Plume Of Death (substat): ";
                float feather{input_handler_range<float>(0, (float) MAX_SUB_ATKP)};
                atk_percent[4] = feather;
                ignore_line();
                break;
            }
            default: { break; }
        }
    }
    std::cout << '\n';
}