#include "Playground.hpp"

#if defined( CXX17_NESTED_NAMESPACES )

namespace A::B::C
{
    //-----------------------------------------------------------------------------
    int Add(int a, int b)
    {
        return a + b;
    }
}

//-----------------------------------------------------------------------------
TEST_CASE( "Nested Namespaces", "[c++17][nested_namespaces]" )
{
    CHECK( A::B::C::Add(1, 2) == 3 );
    CHECK( A::B::C::Add(2, 3) == 5 );
    CHECK( A::B::C::Add(3, 4) == 7 );
}

#endif
