#ifndef KIND_H
#define KIND_H

#include <iostream>

enum class Kind {
    FICTION,
    COOKBOOK,
    HOWTO
};

inline std::ostream& operator <<(std::ostream& ostr, const Kind& kind) {
    switch (kind) {
    case Kind::FICTION: ostr << "fiction"; break;
    case Kind::COOKBOOK: ostr << "cookbook"; break;
    case Kind::HOWTO: ostr << "howto"; break;
    }

    return ostr;
}

#endif // KIND_H
