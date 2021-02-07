#include "include/artifact_value.h"

float flat_atk[5]{};
float atk_percent[5]{};

void flat_atk_get()
{
    int total_flat_atk{};
    for (int x : flat_atk)
    {
        switch (x)
        {
        case 1:
        {
            std::cout << "Enter the total FLAT ATK on your Circlet of Logos (substat): ";
            int circlet{input_handler_range(0, MAX_FLAT_ATK)};
            flat_atk[0] = circlet;
            break;
        }
        case 2:
        {
            std::cout << "Enter the total FLAT ATK on your Goblet of Eonothem (substat): ";
            int goblet{input_handler_range(0, MAX_FLAT_ATK)};
            flat_atk[1] = goblet;
            break;
        }
        case 3:
        {
            std::cout << "Enter the total FLAT ATK on your Sands of Eon (substat): ";
            int cup{input_handler_range(0, MAX_FLAT_ATK)};
            flat_atk[2] = cup;
            break;
        }
        case 4:
        {
            std::cout << "Enter the total FLAT ATK on your Flower of Life (substat): ";
            int flower{input_handler_range(0, MAX_FLAT_ATK)};
            flat_atk[3] = flower;
            break;
        }
        case 5:
        {
            std::cout << "Enter the FLAT ATK on your Plume Of Death (mainstat): ";
            int feather{input_handler_range(0, MAX_FLAT_ATK)};
            flat_atk[4] = feather;
            break;
        }

        default:
            break;
        }
    }
    std::cout << '\n';
    for (int x : flat_atk)
    {
        std::cout << flat_atk[x] << ' ';
    }
}