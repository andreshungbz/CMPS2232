#include <iostream>
#include <stdexcept>

#include "Time.h"

void displayTime(const std::string& message, const Time& time) {
    std::cout << message << "\nUniversal time: " << time.toUniversalString()
        << "\nStandard time: " << time.toStandardString() << "\n\n";
}

int main() {
    Time t;

    displayTime("Initial time:", t);
    t.setTime(13, 27, 6);
    displayTime("After setTime:", t);

    try {
        t.setTime(99, 99, 99);
    } catch (std::invalid_argument& e) {
        std::cout << "Exception: " << e.what() << "\n\n";
    }

    displayTime("After attempting to set an invalid time:", t);

    return 0;
}