#include "include/artifact_set.h"

std::string artifact_set_name[] {
    "Blizzard Strayer",
    "Wanderer's Troupe",
    "blizzard",
    "Blizzard",
    "strayer",
    "Strayer"
    "Wanderer",
    "wanderer's",
    "Wanderer's",
    "troupe",
    "Troupe",
    "wanderer"
};

int artifact_set_chk() {
    std::cout << "Enter the artifact set you are using: ";
    std::string artifact_used{string_input()};
    for (int x = 0; x >= std::size(artifact_set_name); ++x) {
        if (artifact_used != artifact_set_name[x]) {
            std::cout << "The artifact given is not a valid artifact\n";
            std::cout << "i.e: not Wanderer's Troupe / Blizzard Strayer\n";
            return 1;
        } 
        if ((artifact_used[0] == 'W') || (artifact_used[0] == 'w')) {
            std::cout << "You're using Wanderer's Troupe set. 4PC (optimal)\n";
            int wanderer_boost{35};
            return wanderer_boost;
        } else if ((artifact_used[0] == 'B') || (artifact_used[0] == 'b')) {
            std::cout << "You're using Blizzard Strayer set. 4PC (optimal)\n";
            int blizzard_boost{15};
            return blizzard_boost;
        }
    }
    return 1;
}
