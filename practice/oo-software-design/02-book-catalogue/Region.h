#ifndef REGION_H
#define REGION_H

#include <iostream>

enum class Region {
    CHINA,
    FRANCE,
    INDIA,
    ITALY,
    MEXICO,
    PERSIA,
    US
};

inline std::ostream& operator <<(std::ostream& ostr, const Region& region) {
    switch (region) {
    case Region::CHINA: ostr << "China"; break;
    case Region::FRANCE: ostr << "France"; break;
    case Region::INDIA: ostr << "India"; break;
    case Region::ITALY: ostr << "Italy"; break;
    case Region::MEXICO: ostr << "Mexico"; break;
    case Region::PERSIA: ostr << "Persia"; break;
    case Region::US: ostr << "US"; break;
    }

    return ostr;
}

#endif // REGION_H
