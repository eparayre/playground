#include "Playground.hpp"

#if defined( CXX_HAS_INCLUDE )

#if __has_include("invalide_file.hpp")
    #define HAS_INCLUDE_VALUE -1
#elif __has_include("features/HasIncludeExample.hpp")
    #include "features/HasIncludeExample.hpp"
#else
    #define HAS_INCLUDE_VALUE 0
#endif

//-----------------------------------------------------------------------------
TEST_CASE( "Has Include", "[has_include]" )
{
    CHECK( HAS_INCLUDE_VALUE == 1 );
}

#endif
