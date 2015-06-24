#pragma once

//-----------------------------------------------------------------------------
// msvc++
//
// vs2003: 1310
// vs2005: 1400
// vs2008: 1500
// vs2010: 1600
// vs2012: 1700
// vs2013: 1800
// vs2015: 1900
//

#if defined( _MSC_VER )

    //-----------------------------------------------------------------------------
    // c++11

    #if ( _MSC_VER >= 1600 ) // vs2010
        #define CXX11_DECLTYPE
        #define CXX11_LAMBDAS
        #define CXX11_NULLPTR
    #endif

    #if ( _MSC_VER >= 1700 ) // vs2012
        #define CXX11_STRONG_ENUMS
    #endif

    #if ( _MSC_VER >= 1800 ) // vs2013
        #define CXX11_ALIAS_TEMPLATES
        #define CXX11_DEFAULTED_FUNCTIONS
        #define CXX11_DELETED_FUNCTIONS
        #define CXX11_GENERALIZED_INITIALIZERS
        #define CXX11_VARIADIC_TEMPLATES
    #endif

    #if ( _MSC_VER >= 1900 ) // vs2015
        #define CXX11_CONSTEXPR
        #define CXX11_IMPLICIT_MOVES
        #define CXX11_NOEXCEPT
    #endif

    //-----------------------------------------------------------------------------
    // c++14

    #if ( _MSC_VER >= 1900 ) // vs2015
        #define CXX14_DECLTYPE_AUTO
    #endif

#endif
