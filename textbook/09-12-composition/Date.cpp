#include <array>
#include <iostream>
#include <sstream>
#include <stdexcept>

#include "Date.h"

Date::Date(unsigned int mn, unsigned int dy, unsigned int yr)
    : month{mn}, day{checkDay(dy)}, year{yr} {
    if (mn < 1 || mn > monthsPerYear) {
        throw std::invalid_argument("month must be 1-12");
    }

    std::cout << "Date object constructor for date " << toString() << std::endl;
}

std::string Date::toString() const {
    std::ostringstream output;
    output << month << '/' << day << '/' << year;
    return output.str();
}

Date::~Date() {
    std::cout << "Date object destructor for date " << toString() << std::endl;
}

unsigned int Date::checkDay(int testDay) const {
    static const std::array<int, monthsPerYear + 1> daysPerMonth{
        0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
    };

    if (testDay > 0 && testDay <= daysPerMonth[month]) {
        return testDay;
    }

    if (month == 2 && testDay == 29 && (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))) {
        return testDay;
    }

    throw std::invalid_argument("Invalid dat for current month and year");
}
