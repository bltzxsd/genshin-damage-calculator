#include "include/inputhandler.h"
#include <iostream>

int main() {

    std::cout << "Your Ganyu level: ";
    int ganyu_level{input_handler_range(1, 90)};
}
