#ifndef ATTRIBUTES_H
#define ATTRIBUTES_H

#include <iostream>

enum class Genre {
    ADVENTURE,
    CLASSICS,
    DETECTIVE,
    FANTASY,
    HISTORIC,
    HORROR,
    ROMANCE,
    SCIFI,
    UNSPECIFIED
};

inline std::ostream& operator <<(std::ostream& ostr, const Genre& genre) {
    switch (genre) {
    case Genre::ADVENTURE: ostr << "adventure"; break;
    case Genre::CLASSICS: ostr << "classics"; break;
    case Genre::DETECTIVE: ostr << "detective"; break;
    case Genre::FANTASY: ostr << "fantasy"; break;
    case Genre::HISTORIC: ostr << "historic"; break;
    case Genre::HORROR: ostr << "horror"; break;
    case Genre::ROMANCE: ostr << "romance"; break;
    case Genre::SCIFI: ostr << "scifi"; break;
    default: ostr << "unspecified"; break;
    }

    return ostr;
}

class Attributes {
public:
    Attributes(const std::string& ttl, const std::string& lst, const std::string& fst, const int yr, const Genre gen)
        : title{ttl}, last{lst}, first{fst}, year{yr}, genre{gen} {}

    std::string get_title() const { return title; }
    std::string get_last() const { return last; }
    std::string get_first() const { return first; }
    int get_year() const { return year; }
    Genre get_genre() const { return genre;}

    bool is_match(const Attributes& target_attrs) const {
        return equal_ignore_case(target_attrs.get_title(), title)
            && equal_ignore_case(target_attrs.get_last(), last)
            && equal_ignore_case(target_attrs.get_first(), first)
            && ((target_attrs.get_year() == 0) || (target_attrs.get_year() == year))
            && ((target_attrs.get_genre() == Genre::UNSPECIFIED) || (target_attrs.get_genre() == genre));
    }
private:
    std::string title;
    std::string last;
    std::string first;
    int year;
    Genre genre;

    static bool equal_ignore_case(const std::string& string1, const std::string& string2) {
        for (int i = 0; i < string1.length(); ++i) {
            if (std::tolower(string1[i]) != std::tolower(string2[i])) {
                return false;
            }
        }

        return true;
    }
};

inline std::ostream& operator <<(std::ostream& ostr, const Attributes& attrs) {
    ostr << "{TITLE: '" << attrs.get_title()
        << "', LAST: '" << attrs.get_last()
        << "', FIRST: '" << attrs.get_first()
        << "', YEAR: " << attrs.get_year()
        << ", GENRE: " << attrs.get_genre() << "}";

    return ostr;
}

#endif // ATTRIBUTES_H
