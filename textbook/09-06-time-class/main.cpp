#include <iostream>
#include <stdexcept>

#include "Time.h"

void displayTime(const std::string& message, const Time& time) {
    std::cout << message << "\nUniversal time: " << time.toUniversalString()
        << "\nStandard time: " << time.toStandardString() << "\n\n";
}

int main() {
    Time t1;
    Time t2{2};
    Time t3{21, 34};
    Time t4{12, 25, 42};

    std::cout << "Constructed with:\n\n";
    displayTime("t1: all arguments defaulted", t1);
    displayTime("t2: hour specified; minute and second defaulted", t2);
    displayTime("t3: hour and minute specified; second defaulted", t3);
    displayTime("t4: hour, minute and second specified", t4);

    try {
        Time t5{27, 74, 99};
    } catch (std::invalid_argument& e) {
        std::cerr << "Exception while initializing t5: " << e.what() << std::endl;
    }

    return 0;
}