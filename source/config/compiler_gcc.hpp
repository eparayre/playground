#pragma once

//-----------------------------------------------------------------------------
// gcc

#if defined( __GNUC__ )

    //-----------------------------------------------------------------------------
    // setup

    #define GCC_VERSION ( ( __GNUC__ * 10000 ) + ( __GNUC_MINOR__ * 100 ) + ( __GNUC_PATCHLEVEL__ ) )

    //-----------------------------------------------------------------------------
    // c++11

    #if defined( __GXX_EXPERIMENTAL_CXX0X__ )

        #if ( GCCVERSION >= 40300 ) // gcc 4.3
            #define CXX11_DECLTYPE
        #endif

        #if ( GCCVERSION >= 40400 ) // gcc 4.4
            #define CXX11_DEFAULTED_FUNCTIONS
            #define CXX11_DELETED_FUNCTIONS
            #define CXX11_VARIADIC_TEMPLATES
        #endif

        #if ( GCCVERSION >= 40500 ) // gcc 4.5
            #define CXX11_LAMBDAS
        #endif

        #if ( GCCVERSION >= 40501 ) // gcc 4.5.1
            #define CXX11_STRONG_ENUMS
        #endif

        #if ( GCCVERSION >= 40600 ) // gcc 4.6
            #define CXX11_CONSTEXPR
            #define CXX11_GENERALIZED_INITIALIZERS
            #define CXX11_NOEXCEPT
            #define CXX11_NULLPTR
        #endif

        #if ( GCCVERSION >= 40700 ) // gcc 4.7
            #define CXX11_ALIAS_TEMPLATES
        #endif

    #endif

    //-----------------------------------------------------------------------------
    // c++14

    #if ( GCCVERSION >= 40900 ) // gcc 4.9
        #define CXX14_DECLTYPE_AUTO
    #endif

    //-----------------------------------------------------------------------------
    // cleanup

    #undef GCC_VERSION

#endif