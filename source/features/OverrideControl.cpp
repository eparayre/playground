#include "Playground.hpp"

#if defined( CXX11_OVERRIDE_CONTROL )

namespace
{
    class Foo
    {
    public:
        virtual int GetValue() { return 11; }
    };

    class Bar : public Foo
    {
    public:
        virtual int GetValue() override { return 22; }
    };
}

//-----------------------------------------------------------------------------
TEST_CASE( "Override Control", "[c++11][override_control]" )
{
    Foo foo;
    Bar bar;

    CHECK( foo.GetValue() == 11 );
    CHECK( bar.GetValue() == 22 );
}

#endif
