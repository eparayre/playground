#pragma once

//-----------------------------------------------------------------------------
// gcc

#if defined( __GNUC__ ) && !defined( __clang__ )

    #define GCC_VERSION ( __GNUC__ * 10000 + __GNUC_MINOR__ * 100 + __GNUC_PATCHLEVEL__ )

    #define COMPILER_STR( a ) #a
    #define COMPILER_XSTR( a ) COMPILER_STR( a )

    #define COMPILER_IDENTIFICATION "gcc-" COMPILER_XSTR( __GNUC__ ) "." COMPILER_XSTR( __GNUC_MINOR__ ) "." COMPILER_XSTR( __GNUC_PATCHLEVEL__ )

    //-----------------------------------------------------------------------------
    // c++11

    #if defined( __GXX_EXPERIMENTAL_CXX0X__ )

        #if ( GCC_VERSION >= 40300 ) // gcc 4.3
            #define CXX11_DECLTYPE
        #endif

        #if ( GCC_VERSION >= 40400 ) // gcc 4.4
            #define CXX11_DEFAULTED_FUNCTIONS
            #define CXX11_DELETED_FUNCTIONS
            #define CXX11_VARIADIC_TEMPLATES
        #endif

        #if ( GCC_VERSION >= 40500 ) // gcc 4.5
            #define CXX11_LAMBDAS
        #endif

        #if ( GCC_VERSION >= 40501 ) // gcc 4.5.1
            #define CXX11_STRONG_ENUMS
        #endif

        #if ( GCC_VERSION >= 40600 ) // gcc 4.6
            #define CXX11_CONSTEXPR
            #define CXX11_GENERALIZED_INITIALIZERS
            #define CXX11_NOEXCEPT
            #define CXX11_NULLPTR
        #endif

        #if ( GCC_VERSION >= 40700 ) // gcc 4.7
            #define CXX11_ALIAS_TEMPLATES
            #define CXX11_DELEGATING_CONSTRUCTORS
        #endif

        #if ( GCC_VERSION >= 40800 ) // gcc 4.8
            #define CXX11_INHERITING_CONSTRUCTORS
        #endif

    #endif

    //-----------------------------------------------------------------------------
    // c++14

    #if ( GCC_VERSION >= 40900 ) // gcc 4.9
        #define CXX14_DECLTYPE_AUTO
    #endif

    #if ( GCC_VERSION >= 40900 ) // gcc 4.9
        #define CXX14_INIT_CAPTURES
    #endif

    #if defined( __cpp_constexpr ) && ( __cpp_constexpr >= 201304 )
        #define CXX14_RELAXED_CONSTEXPR
    #endif

#endif
