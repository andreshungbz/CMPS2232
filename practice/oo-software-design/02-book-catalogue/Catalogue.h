#ifndef CATALOGUE_H
#define CATALOGUE_H

#include <string>
#include <vector>
#include "Book.h"

class Catalogue {
public:
    void add(const std::string& title, const std::string& last, const std::string& first) {
        booklist.push_back(new Book{title, last, first});
    }

    std::vector<Book*> find(const Book& target) const;
private:
    std::vector<Book*> booklist;

    static bool equal_ignore_case(const std::string& string1, const std::string& string2) {
        for (int i = 0; i < string1.length(); ++i) {
            if (std::tolower(string1[i]) != std::tolower(string2[i])) {
                return false;
            }
        }

        return true;
    }
};



#endif // CATALOGUE_H
