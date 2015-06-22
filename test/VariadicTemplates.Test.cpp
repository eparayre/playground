
#include "catch.hpp"
#include "../source/VariadicTemplates.h"

TEST_CASE( "VariadicTemplates/C#_like_StringFormat" )
{
    SECTION("ordered arguments")
    {
        auto result = StringFormat("key {0} = value {1}", 'A', 'B');

        CHECK(result == "key A = value B");
    }

    SECTION("inverted arguments")
    {
        auto result = StringFormat("key {1} = value {0}", 'A', 'B');

        CHECK(result == "key B = value A");
    }
}
