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
