#ifndef CATALOGUE_H
#define CATALOGUE_H

#include <vector>
#include "Book.h"

class Catalogue {
public:
    void add(Attributes* attrs);

    std::vector<Book*> find(const Attributes& target_attrs) const;
private:
    std::vector<Book*> booklist;
};



#endif // CATALOGUE_H
