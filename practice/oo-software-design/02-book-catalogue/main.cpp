#include <iostream>
#include <vector>
#include <string>

#include "Book.h"
#include "Catalogue.h"

void fill(Catalogue& catalogue);
void test(const Catalogue& catalogue);

int main() {
    Catalogue catalogue;
    fill(catalogue);
    test(catalogue);

    return 0;
}

void fill(Catalogue& catalogue) {
    // catalogue.add("Life of Pi", "Martel", "Yann");
    // catalogue.add("The Call of the Wild", "London", "Jack");
    // catalogue.add("To Kill a Mockingbird", "Lee", "Harper");
    // catalogue.add("Little Women", "Alcott", "Louisa");
    // catalogue.add("The Adventures of Sherlock Holmes", "Doyle", "Conan");
    // catalogue.add("And Then There Were None", "Christie", "Agatha");
    // catalogue.add("Carrie", "King", "Stephen");
    // catalogue.add("It: A Novel", "King", "Stephen");
    // catalogue.add("Frankenstein", "Shelley", "Mary");
    // catalogue.add("2001: A Space Odyssey", "Clarke", "Arthur");
    // catalogue.add("Ender's Game", "Card", "Orson");

    AttributeMap pairs3{
        {Key::KIND, Kind::FICTION},
        {Key::TITLE, std::string("To Kill a Mockingbird")},
        {Key::LAST, std::string("Lee")},
        {Key::FIRST, std::string("Harper")},
        {Key::YEAR, 1960},
        {Key::GENRE, Genre::CLASSICS}
    };
    catalogue.add(new Attributes{new AttributeMap{pairs3}});
}

void search(const Catalogue& catalogue, const Attributes& target) {
    std::cout << std::endl << "Find " << target << std::endl;
    std::vector<Book*> matches = catalogue.find(target);

    if (matches.empty()) {
        std::cout << "No matches." << std::endl;
    } else {
        std::cout << "Matches:" << std::endl;
        for (Book* book : matches) {
            std::cout << '\t' << *book << std::endl;
        }
    }
}

void test(const Catalogue& catalogue) {
    // Book target1{"Life of Pi", "Martel", "Yann"};
    // search(catalogue, target1);
    //
    // Book target2{"", "King", ""};
    // search(catalogue, target2);
    //
    // Book target3{"1984", "Orwell", "George"};
    // search(catalogue, target3);
    //
    // Book target4{"", "", ""};
    // search(catalogue, target4);

    AttributeMap target_pairs2{
            {Key::KIND, Kind::FICTION},
            {Key::LAST, std::string("KING")},
            {Key::GENRE, Genre::HORROR}
    };
    search(catalogue, Attributes{new AttributeMap{target_pairs2}});

    AttributeMap target_pairsB{
        {Key::LAST, "Lee"}
    };
    search(catalogue, Attributes{new AttributeMap{target_pairsB}});
}