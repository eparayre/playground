#include "Playground.hpp"

#if defined( CPP11_CONSTEXPR ) && defined( CPP11_NOEXCEPT )

namespace
{
#if defined( CPP14_CONSTEXPR )
    //-----------------------------------------------------------------------------
    constexpr int Pow( int base, int exp ) noexcept
    {
        auto result = 1;
        for( int i = 0; i < exp; ++i ) result *= base;
        return result;
    }
#else
    //-----------------------------------------------------------------------------
    constexpr int Pow( int base, int exp ) noexcept
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
    std::array< int, Pow( 2, 4 ) > array2_4;

    CHECK( array0_1.size() ==  1 );
    CHECK( array3_3.size() ==  9 );
    CHECK( array2_4.size() == 16 );
}

#endif
