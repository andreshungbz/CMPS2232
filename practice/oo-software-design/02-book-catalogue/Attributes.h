#ifndef ATTRIBUTES_H
#define ATTRIBUTES_H

#include <string>
#include <map>
#include <variant>

#include "Key.h"
#include "Kind.h"
#include "Genre.h"
#include "Region.h"
#include "Subject.h"

typedef std::variant<int, std::string, Kind, Genre, Region, Subject> AttributeValue;
typedef std::map<Key, AttributeValue> AttributeMap;

enum type_indexes {
    INT_INDEX,
    STRING_INDEX,
    KIND_INDEX,
    GENRE_INDEX,
    REGION_INDEX,
    SUBJECT_INDEX
};

class Attributes {
public:
    explicit Attributes(AttributeMap* pairs);
    ~Attributes() { delete attribute_map; }

    bool is_match(const Attributes& target_attrs) const;

    friend std::ostream& operator <<(std::ostream& ostr, const Attributes& attrs);
private:
    AttributeMap* attribute_map;

    bool is_matching_pair(const Key& target_key, const AttributeValue& target_value) const;

    static bool equal_ignore_case(const std::string& string1, const std::string& string2) {
        for (int i = 0; i < string1.length(); ++i) {
            if (std::tolower(string1[i]) != std::tolower(string2[i])) {
                return false;
            }
        }

        return true;
    }
};

#endif // ATTRIBUTES_H
