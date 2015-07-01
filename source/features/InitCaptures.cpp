#include "Playground.hpp"

#if defined( CXX14_INIT_CAPTURES )

#include <vector>
#include <functional>

namespace
{
    class SomeObject
    {
    public:
        SomeObject( int divisor )
            : divisor_( divisor )
        {}

        template< typename C >
        void AddDivisorFilter( C& container )
        {
            container.emplace_back(
                [divisor = divisor_]( int value ) { return ( value % divisor ) == 0; }
                );
        }

    private:
        int divisor_{ 1 };
    };
}

TEST_CASE( "Generalized Lambda Capture", "[c++14][init_captures]" )
{
    using Filters = std::vector< std::function< bool(int) > >;

    Filters filters;

    SomeObject someObjectA( 2 );
    someObjectA.AddDivisorFilter( filters );

    CHECK( filters[0]( 2 ) == true );
    CHECK( filters[0]( 3 ) == false );
    CHECK( filters[0]( 4 ) == true );
    CHECK( filters[0]( 5 ) == false );
    CHECK( filters[0]( 6 ) == true );
    CHECK( filters[0]( 7 ) == false );
    CHECK( filters[0]( 8 ) == true );
    CHECK( filters[0]( 9 ) == false );

    SomeObject someObjectB( 3 );
    someObjectB.AddDivisorFilter( filters );

    CHECK( filters[1]( 2 ) == false );
    CHECK( filters[1]( 3 ) == true );
    CHECK( filters[1]( 4 ) == false );
    CHECK( filters[1]( 5 ) == false );
    CHECK( filters[1]( 6 ) == true );
    CHECK( filters[1]( 7 ) == false );
    CHECK( filters[1]( 8 ) == false );
    CHECK( filters[1]( 9 ) == true );

    SomeObject someObjectC( 4 );
    someObjectC.AddDivisorFilter( filters );

    CHECK( filters[2]( 2 ) == false );
    CHECK( filters[2]( 3 ) == false );
    CHECK( filters[2]( 4 ) == true );
    CHECK( filters[2]( 5 ) == false );
    CHECK( filters[2]( 6 ) == false );
    CHECK( filters[2]( 7 ) == false );
    CHECK( filters[2]( 8 ) == true );
    CHECK( filters[2]( 9 ) == false );
}

#endif
