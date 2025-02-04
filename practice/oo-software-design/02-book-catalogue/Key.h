#ifndef KEY_H
#define KEY_H

#include <iostream>

enum class Key {
    KIND,
    TITLE,
    LAST,
    FIRST,
    YEAR,
    GENRE,
    REGION,
    SUBJECT
};

inline std::ostream& operator <<(std::ostream& ostr, const Key& key) {
    switch (key) {
    case Key::KIND: ostr << "KIND"; break;
    case Key::TITLE: ostr << "TITLE"; break;
    case Key::LAST: ostr << "LAST"; break;
    case Key::FIRST: ostr << "FIRST"; break;
    case Key::YEAR: ostr << "YEAR"; break;
    case Key::GENRE: ostr << "GENRE"; break;
    case Key::REGION: ostr << "REGION"; break;
    case Key::SUBJECT: ostr << "SUBJECT"; break;
    }

    return ostr;
}

#endif // KEY_H
