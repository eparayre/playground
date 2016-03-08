#include "Playground.hpp"

#if defined( CXX11_INHERITING_CONSTRUCTORS )

namespace
{
    //-----------------------------------------------------------------------------
    class Base
    {
    public:
        Base(int intA, int intB)
            : intA_(intA)
            , intB_(intB)
        {}

    public:
        inline int GetIntA() const { return intA_; }
        inline int GetIntB() const { return intB_; }

    private:
        int intA_;
        int intB_;
    };

    //-----------------------------------------------------------------------------
    class Derived : public Base
    {
    public:
        using Base::Base;
    };
}

TEST_CASE("Inheriting Constructors", "[c++11][inheriting_constructors]")
{
    Derived object(69, 1337);

    CHECK(object.GetIntA() == 69);
    CHECK(object.GetIntB() == 1337);
}

#endif
