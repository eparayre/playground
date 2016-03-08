#include "Playground.hpp"

#if defined( CXX11_DELEGATING_CONSTRUCTORS )

namespace
{
    //-----------------------------------------------------------------------------
    class DelegatingConstructors
    {
    public:
        DelegatingConstructors()
            : DelegatingConstructors(true, 11, 22)
        {}

        explicit DelegatingConstructors(bool boolean)
            : DelegatingConstructors(boolean, 33, 44)
        {}

        DelegatingConstructors(bool boolean, int intA)
            : DelegatingConstructors(boolean, intA, 66)
        {}

        DelegatingConstructors(bool boolean, int intA, int intB)
            : boolean_(boolean)
            , intA_(intA)
            , intB_(intB)
        {}

    public:
        inline bool GetBoolean() const { return boolean_; }
        inline int GetIntA() const { return intA_; }
        inline int GetIntB() const { return intB_; }

    private:
        bool boolean_;
        int intA_;
        int intB_;
    };
}

TEST_CASE("Delegating Constructors", "[c++11][delegating_constructors]")
{
    SECTION("Default Ctor")
    {
        DelegatingConstructors object;

        CHECK(object.GetBoolean() == true);
        CHECK(object.GetIntA() == 11);
        CHECK(object.GetIntB() == 22);
    }

    SECTION("Ctor 1")
    {
        DelegatingConstructors object(true);

        CHECK(object.GetBoolean() == true);
        CHECK(object.GetIntA() == 33);
        CHECK(object.GetIntB() == 44);
    }

    SECTION("Ctor 2")
    {
        DelegatingConstructors object(true, 55);

        CHECK(object.GetBoolean() == true);
        CHECK(object.GetIntA() == 55);
        CHECK(object.GetIntB() == 66);
    }

    SECTION("Ctor 3")
    {
        DelegatingConstructors object(true, 77, 88);

        CHECK(object.GetBoolean() == true);
        CHECK(object.GetIntA() == 77);
        CHECK(object.GetIntB() == 88);
    }
}

#endif
