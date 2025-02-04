#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>

class Book {
public:
    Book(const std::string& ttl, const std::string& lst, const std::string& fst)
        : title{ttl}, last{lst}, first{fst} {}

    std::string get_title() const { return title; }
    std::string get_last() const { return last; }
    std::string get_first() const { return first; }
private:
    std::string title;
    std::string last;
    std::string first;
};

inline std::ostream& operator <<(std::ostream& ostr, const Book& book) {
    ostr << "{TITLE: '" << book.get_title() << "', LAST: '" << book.get_last() << "', FIRST: " << book.get_first() << "'}";
    return ostr;
}


#endif // BOOK_H
