#ifndef GENRE_H
#define GENRE_H

#include <iostream>

enum class Genre {
    ADVENTURE,
    CLASSICS,
    DETECTIVE,
    FANTASY,
    HISTORIC,
    HORROR,
    ROMANCE,
    SCIFI,
};

inline std::ostream& operator <<(std::ostream& ostr, const Genre& genre) {
    switch (genre) {
    case Genre::ADVENTURE: ostr << "adventure"; break;
    case Genre::CLASSICS: ostr << "classics"; break;
    case Genre::DETECTIVE: ostr << "detective"; break;
    case Genre::FANTASY: ostr << "fantasy"; break;
    case Genre::HISTORIC: ostr << "historic"; break;
    case Genre::HORROR: ostr << "horror"; break;
    case Genre::ROMANCE: ostr << "romance"; break;
    case Genre::SCIFI: ostr << "scifi"; break;
    }

    return ostr;
}

#endif // GENRE_H
