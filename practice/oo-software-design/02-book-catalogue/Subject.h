#ifndef SUBJECT_H
#define SUBJECT_H

#include <iostream>

enum class Subject {
    DRAWING,
    PAINTING,
    WRITING
};

inline std::ostream& operator <<(std::ostream& ostr, const Subject& subject) {
    switch (subject) {
    case Subject::DRAWING: ostr << "drawing"; break;
    case Subject::PAINTING: ostr << "painting"; break;
    case Subject::WRITING: ostr << "writing"; break;
    }

    return ostr;
}

#endif // SUBJECT_H
