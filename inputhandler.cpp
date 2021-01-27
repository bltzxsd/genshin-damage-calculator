#include <iostream>
#include <limits>

void ignore_line()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int input_and_validation() {
    // Ideally this function should only be handling integer input.
    // Not made to handle strings as of right now.
    while (true) {
        int input{};
        std::cin >> input;
        if ((input > 90) || (input < 1)) {
            std::cin.clear();
            ignore_line();
            std::cout << "Invalid Input. Please try again.\n" << std::endl;
        } else {
            return input;
        }
    }
}