#include "include/inputhandler.h"
#include <iostream>

void ignore_line()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int input_handler_range(int min, int max, std::string fail_out) {
    // This func gets input between 2 values (int min, int max)
    // 3rd parameter is used for outputting whats wrong the input.
    while (true){
        int input{};
        std::cin >> input;
        if ((input < min) || (input > max)) {
            ignore_line();
            std::cout << "Invalid Input. Please try again. input_handler_range() failed." << std::endl;
            std::cout << fail_out;
        } else {
            return input;
        }
    }
}

float input_handler_num() {
    // This func handles numeric input, 
    // Ideally, input should never be less than 0.
    while (true) {
        float input{};
        std::cin >> input;
        if (input < 0 || std::cin.fail()) {
            ignore_line();
            std::cout << "Invalid input. Please try again. input_handler_num() failed." << std::endl;
        } else {
            return input;
        }
    }
}

std::string string_input() {
    while (true) {
        // Handles std::string input.
        std::string input;
        std::cin >> std::noskipws >> input;
        if (std::cin.fail()) {
            ignore_line();
            std::cout << "Invalid input. Please try again. input_handler_str() failed." << std::endl;
        }
        return input;
    }
}