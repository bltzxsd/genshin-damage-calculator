#include <iostream>
#include <limits>
#include <sstream>

void ignore_line()
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

float input_handler_string(bool datatype) {
    while (true) {
        std::stringstream input{};
        if (datatype) {
            float num_input{};
            if (std::cin.fail()) {
                std::cin.clear();
                ignore_line();
                std::cout << "Invalid input. Please try again.\n" << std::endl;
            } else {
                input >> num_input;
                return num_input;
            }
        }
    }
}