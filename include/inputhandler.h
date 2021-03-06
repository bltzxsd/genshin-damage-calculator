#ifndef INPUTHANDLER
#define INPUTHANDLER
#include <string>
#include <iostream>
#include <limits>

void ignore_line();
template<typename T>
T input_handler_range(T min, T max) {
    // This func gets input between 2 values (T min, T max)
    while (true) {
        T input{};
        std::cin >> input;
        if ((input < min) || (input > max)) {
            ignore_line();
            std::cout << "Invalid Input. Please try again. input_handler_range() failed.\n";
            std::cout << "This parameter only accepts values within the range of " << min << " and " << max << '.';
            std::cout << "\nPlease try again: ";
            continue;
        } else {
            return input;
        }
    }
}
float input_handler_num();
std::string string_input();
#endif