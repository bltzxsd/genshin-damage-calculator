#include <iostream>
#include <limits>
#include <typeinfo>

inline void ignore_line()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int input_handler_range(int min, int max) {
    while (true) {
        int input{};
        std::cin >> input;
        if ((input < min) || (input > max)) {
            std::cin.clear();
            ignore_line();
            std::cout << "Invalid Input. Please try again.\n" << std::endl;
        } else {
            return input;
        }
    }
}

float input_handler() {
    while (true) {
        float input{};
        std::cin >> input;
        if (input < 0 || std::cin.fail()) {
            std::cin.clear();
            ignore_line();
            std::cout << "Invalid input. Please try again.\n" << std::endl;
        } else {
            return input;
        }
    }
}
