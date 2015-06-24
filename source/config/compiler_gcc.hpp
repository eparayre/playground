#pragma once

//-----------------------------------------------------------------------------
// gcc

#if defined( __GNUC__ )

    //-----------------------------------------------------------------------------
    // setup

    #define GCC_VERSION ( __GNUC__ * 10000 + __GNUC_MINOR__ * 100 + __GNUC_PATCHLEVEL__ )

    #if defined( __GXX_EXPERIMENTAL_CXX0X__ )
        #define GCC_CXX11
        #define COMPILER_NAME "gcc_c++11"
    #else
        #define COMPILER_NAME "gcc"
    #endif

    
    #define COMPILER_VERSION GCC_VERSION

    //-----------------------------------------------------------------------------
    // c++11

    #if ( GCCVERSION >= 40300 ) && defined( GCC_CXX11 ) // gcc 4.3
        #define CXX11_DECLTYPE
    #endif

    #if ( GCCVERSION >= 40400 ) && defined( GCC_CXX11 ) // gcc 4.4
        #define CXX11_DEFAULTED_FUNCTIONS
        #define CXX11_DELETED_FUNCTIONS
        #define CXX11_VARIADIC_TEMPLATES
    #endif

    #if ( GCCVERSION >= 40500 ) && defined( GCC_CXX11 ) // gcc 4.5
        #define CXX11_LAMBDAS
    #endif

    #if ( GCCVERSION >= 40501 ) && defined( GCC_CXX11 ) // gcc 4.5.1
        #define CXX11_STRONG_ENUMS
    #endif

    #if ( GCCVERSION >= 40600 ) && defined( GCC_CXX11 ) // gcc 4.6
        #define CXX11_CONSTEXPR
        #define CXX11_GENERALIZED_INITIALIZERS
        #define CXX11_NOEXCEPT
        #define CXX11_NULLPTR
    #endif

    #if ( GCCVERSION >= 40700 ) && defined( GCC_CXX11 ) // gcc 4.7
        #define CXX11_ALIAS_TEMPLATES
    #endif

    //-----------------------------------------------------------------------------
    // c++14

    #if ( GCCVERSION >= 40900 ) // gcc 4.9
        #define CXX14_DECLTYPE_AUTO
    #endif

#endif
