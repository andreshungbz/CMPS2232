#include "Catalogue.h"
#include "Book.h"

std::vector<Book*> Catalogue::find(const Attributes& target_attrs) const {
    std::vector<Book*> matches;

    for (Book* book : booklist) {
        Attributes* book_attrs{book->get_attributes()};
        if (book_attrs->is_match(target_attrs)) {
            matches.push_back(book);
        }
    }

    return matches;
}
