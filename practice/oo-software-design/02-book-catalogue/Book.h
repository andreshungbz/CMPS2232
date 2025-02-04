#ifndef BOOK_H
#define BOOK_H

#include "Attributes.h"

class Book {
public:
    Book(Attributes* const attrs)
        : attributes{attrs} {}
    virtual ~Book() { delete attributes; }

    Attributes* get_attributes() const { return attributes; }
private:
    Attributes* attributes;
};



#endif // BOOK_H
