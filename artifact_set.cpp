#include "include/artifact_set.h"

std::string artifact_set_name[] {
    "Blizzard Strayer",
    "Wanderer's Troupe",
    "blizzard",
    "Blizzard",
    "strayer",
    "Strayer",
    "Wanderer",
    "wanderers",
    "Wanderer's",
    "troupe",
    "Troupe",
    "wanderer",
};

const int wanderers{35};
const int blizzard{15};

int artifact_set_chk() {
    std::cout << "Enter the artifact set you are using (Wanderer's Troupe / Blizzard Strayer): ";
    std::string artifact_used{string_input()};
    for (size_t x{0}; x <= (int) std::size(artifact_set_name); ++x) {
        if (artifact_used == artifact_set_name[x]) {
            if ((artifact_used[0] == 'W') || (artifact_used[0] == 'w')) {
                std::cout << "  You're using Wanderer's Troupe set. 4PC (optimal)\n\n";
                return wanderers;
            }
            if ((artifact_used[0] == 'B') || (artifact_used[0] == 'b')) {
                std::cout << "  You're using Blizzard Strayer set. 4PC (optimal)\n\n";
                return blizzard;
            }
        }
    }
    std::cerr << "Not a valid arfifact\ni.e: NOT Wanderer's Troupe / Blizzard Strayer\n"
              << "Warning: Artifact values will not be included in this calculation.\n";
    return 1;
}
