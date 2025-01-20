#include <iomanip>
#include <stdexcept>
#include <sstream>
#include <string>

#include "Time.h"

void Time::setTime(int h, int m, int s) {
    if ((h >= 0 && h < 24) && (m >=0 && m < 60) && (s >= 0 && s < 60)) {
        hour = h;
        minute = m;
        second = s;
    } else {
        throw std::invalid_argument("hour, minute and/or second was out of range");
    }
}

std::string Time::toUniversalString() const {
    std::ostringstream output;
    output << std::setfill('0') << std::setw(2) << hour << ":"
        << std::setw(2) << minute << ":" << std::setw(2) << second;
    return output.str();
}


std::string Time::toStandardString() const {
    std::ostringstream output;
    output << ((hour == 0 || hour == 12) ? 12 : hour % 12) << ":"
        << std::setfill('0') << std::setw(2) << minute << ":" << std::setw(2)
        << second << (hour < 12 ? " AM" : " PM");
    return output.str();
}
