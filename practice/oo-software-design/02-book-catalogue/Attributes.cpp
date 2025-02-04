#include "Attributes.h"

#include <iostream>
#include <string>
#include <cassert>

#include "Key.h"
#include "Kind.h"
#include "Genre.h"
#include "Region.h"
#include "Subject.h"

Attributes::Attributes(AttributeMap* const pairs)
    : attribute_map{pairs} {
    for (AttributeMap::iterator it = pairs->begin(); it != pairs->end(); ++it) {
        Key key = it->first;
        int index = it->second.index();

        switch (key) {
        case Key::YEAR: assert(index == INT_INDEX); break;
        case Key::TITLE:
        case Key::LAST:
        case Key::FIRST:
            assert(index == STRING_INDEX); break;
        case Key::KIND:
            assert(index == KIND_INDEX); break;
        case Key::GENRE:
            assert(index == GENRE_INDEX); break;
        case Key::REGION:
            assert(index == REGION_INDEX); break;
        case Key::SUBJECT:
            assert(index == SUBJECT_INDEX); break;
        }
    }
}

bool Attributes::is_match(const Attributes& target_attrs) const {
    AttributeMap* target_pairs{target_attrs.attribute_map};
    AttributeMap::iterator it;
    for (it = target_pairs->begin(); it != target_pairs->end(); ++it) {
        Key target_key{it->first};
        AttributeValue target_value{it->second};
        if (!is_matching_pair(target_key, target_value)) {
            return false;
        }
    }

    return true;
}

bool Attributes::is_matching_pair(const Key& target_key, const AttributeValue& target_value) const {
    if (attribute_map->find(target_key) == attribute_map->end()) {
        return false;
    }

    if ((*attribute_map)[target_key] == target_value) {
        return true;
    }

    if (target_value.index() == STRING_INDEX) {
        return equal_ignore_case(std::get<std::string>((*attribute_map)[target_key]), std::get<std::string>(target_value));
    }

    return false;
}

std::ostream& operator <<(std::ostream& ostr, const Attributes& attrs) {
    AttributeMap* pairs{attrs.attribute_map};
    AttributeMap::iterator it;

    ostr << "{";

    for (it = pairs->begin(); it != pairs->end(); ++it) {
        Key key{it->first};
        AttributeValue value{it->second};

        if (it != pairs->begin()) ostr << ", ";
        ostr << key << ": ";

        switch (key) {
        case Key::KIND: ostr << std::get<Kind>(value); break;
        case Key::TITLE:
        case Key::LAST:
        case Key::FIRST:
            ostr << "'" << std::get<std::string>(value) << "'"; break;
        case Key::GENRE: ostr << std::get<Genre>(value); break;
        case Key::YEAR: ostr << std::get<int>(value); break;
        case Key::REGION: ostr << std::get<Region>(value); break;
        default: break;
        }
    }

    ostr << "}";
    return ostr;
}