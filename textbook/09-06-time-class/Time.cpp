#include <iomanip>
#include <stdexcept>
#include <sstream>
#include <string>

#include "Time.h"

Time::Time(int hour, int minute, int second) {
    setTime(hour, minute, second);
}


void Time::setTime(int h, int m, int s) {
    setHour(h);
    setMinute(m);
    setSecond(s);
}

void Time::setHour(int h) {
    if (h >= 0 && h < 24) {
        hour = h;
    } else {
        throw std::invalid_argument("hour must be 0-23");
    }
}

void Time::setMinute(int m) {
    if (m >= 0 && m < 60) {
        minute = m;
    } else {
        throw std::invalid_argument("minute must be 0-59");
    }
}

void Time::setSecond(int s) {
    if (s >= 0 && s < 60) {
        second = s;
    } else {
        throw std::invalid_argument("second must be 0=59");
    }
}

unsigned int Time::getHour() const {
    return hour;
}

unsigned int Time::getMinute() const {
    return minute;
}

unsigned int Time::getSecond() const {
    return second;
}

std::string Time::toUniversalString() const {
    std::ostringstream output;
    output << std::setfill('0') << std::setw(2) << getHour() << ":"
        << std::setw(2) << getMinute() << ":" << std::setw(2) << getSecond();
    return output.str();
}


std::string Time::toStandardString() const {
    std::ostringstream output;
    output << ((getHour() == 0 || getHour() == 12) ? 12 : getHour() % 12) << ":"
        << std::setfill('0') << std::setw(2) << minute << ":" << std::setw(2)
        << getSecond() << (hour < 12 ? " AM" : " PM");
    return output.str();
}
