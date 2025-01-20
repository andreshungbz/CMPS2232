#include <sstream>
#include <string>

#include "Date.h"

Date::Date(unsigned int m, unsigned int d, unsigned int y)
    : month{m}, day{d}, year{y} {}

std::string Date::toString() const {
    std::ostringstream output;
    output << month << '/' << day << '/' << year;
    return output.str();
}
