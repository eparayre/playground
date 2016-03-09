#include "Playground.hpp"

#if defined( CXX11_DELEGATING_CONSTRUCTORS )

#include <string>

namespace
{
    //-----------------------------------------------------------------------------
    class SampleA
    {
    public:
        SampleA()
        {
            message_ = "must pass through the default ctor";
        }

        SampleA(float value)
            : SampleA()

            // error: an initializer for a delegating constructor must appear alone
            /*, value_(3)*/
        {
            // but we can initialize members in the body
            value_ = value;
        }

        float GetValue() const { return value_; }
        const std::string& GetMessage() const { return message_;}

    private:
        float value_{1.1f};
        std::string message_{"invalid"};
    };

    //-----------------------------------------------------------------------------
    class SampleB
    {
    public:
        SampleB()
            : SampleB(true, 11, 22)
        {}

        explicit SampleB(bool boolean)
            : SampleB(boolean, 33, 44)
        {}

        SampleB(bool boolean, int intA)
            : SampleB(boolean, intA, 66)
        {}

        SampleB(bool boolean, int intA, int intB)
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
    SECTION("Calling default ctor")
    {
        SampleA object(7.0f);

        CHECK(object.GetMessage() == "must pass through the default ctor");
        CHECK(object.GetValue() == 7.0f);
    }

    SECTION("Calling more specialized ctors")
    {
        SECTION("Default Ctor")
        {
            SampleB object;

            CHECK(object.GetBoolean() == true);
            CHECK(object.GetIntA() == 11);
            CHECK(object.GetIntB() == 22);
        }

        SECTION("Ctor 1")
        {
            SampleB object(true);

            CHECK(object.GetBoolean() == true);
            CHECK(object.GetIntA() == 33);
            CHECK(object.GetIntB() == 44);
        }

        SECTION("Ctor 2")
        {
            SampleB object(true, 55);

            CHECK(object.GetBoolean() == true);
            CHECK(object.GetIntA() == 55);
            CHECK(object.GetIntB() == 66);
        }

        SECTION("Ctor 3")
        {
            SampleB object(true, 77, 88);

            CHECK(object.GetBoolean() == true);
            CHECK(object.GetIntA() == 77);
            CHECK(object.GetIntB() == 88);
        }
    }
}

#endif
