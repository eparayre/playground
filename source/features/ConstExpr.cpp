#include "Playground.hpp"

#if defined( CXX11_CONSTEXPR )

namespace
{
#if defined( CXX14_RELAXED_CONSTEXPR )
    //-----------------------------------------------------------------------------
    constexpr int Pow( int base, int exp )
    {
        auto result = 1;
        for( int i = 0; i < exp; ++i ) result *= base;
        return result;
    }
#else
    //-----------------------------------------------------------------------------
    constexpr int Pow( int base, int exp )
    {
        return ( exp == 0 ? 1 : base * Pow( base, exp - 1 ) );
    }
#endif
}

//-----------------------------------------------------------------------------
TEST_CASE( "CompileTime Expression", "[constexpr]" )
{
    std::array< int, Pow( 0, 1 ) > array0_1;
    std::array< int, Pow( 3, 3 ) > array3_3;
    std::array< int, Pow( 2, 6 ) > array2_6;

    CHECK( array0_1.size() ==  0 );
    CHECK( array3_3.size() == 27 );
    CHECK( array2_6.size() == 64 );
}

#endif
