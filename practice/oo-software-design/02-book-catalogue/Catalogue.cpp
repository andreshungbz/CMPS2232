#include "Catalogue.h"
#include "Book.h"

std::vector<Book*> Catalogue::find(const Book& target) const {
    std::vector<Book*> matches;

    std::string target_title = target.get_title();
    std::string target_last = target.get_last();
    std::string target_first = target.get_first();

    for (Book* book : booklist) {
        if (equal_ignore_case(target_title, book->get_title())
            && equal_ignore_case(target_last, book->get_last())
            && equal_ignore_case(target_first, book->get_first())) {
            matches.push_back(book);
        }
    }

    return matches;
}
