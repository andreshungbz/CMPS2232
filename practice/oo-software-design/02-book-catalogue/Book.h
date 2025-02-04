#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include "Attributes.h"

class Book {
public:
    explicit Book(Attributes* const attrs)
        : attributes{attrs} {}
    virtual ~Book() { delete attributes; }

    Attributes* get_attributes() const { return attributes; }
private:
    Attributes* attributes;
};

inline std::ostream& operator <<(std::ostream& ostr, const Book& book) {
    std::cout << *book.get_attributes();
    return ostr;
}


#endif // BOOK_H
