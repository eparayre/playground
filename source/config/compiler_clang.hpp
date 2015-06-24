#pragma once

//-----------------------------------------------------------------------------
// clang

#if defined( __clang__ )

    #define COMPILER_STR( a ) #a
    #define COMPILER_XSTR( a ) COMPILER_STR( a )

    #define COMPILER_IDENTIFICATION "clang-" COMPILER_XSTR( __clang_major__ ) "." COMPILER_XSTR( __clang_minor__ ) "." COMPILER_XSTR( __clang_patchlevel__ )

    //-----------------------------------------------------------------------------
    // c++11

    #if __has_feature( cxx_alias_templates )
        #define CXX11_ALIAS_TEMPLATES
    #endif

    #if __has_feature( cxx_constexpr )
        #define CXX11_CONSTEXPR
    #endif

    #if __has_feature( cxx_decltype )
        #define CXX11_DECLTYPE
    #endif

    #if __has_feature( cxx_defaulted_functions )
        #define CXX11_DEFAULTED_FUNCTIONS
    #endif

    #if __has_feature( cxx_deleted_functions )
        #define CXX11_DELETED_FUNCTIONS
    #endif

    #if __has_feature( cxx_generalized_initializers )
        #define CXX11_GENERALIZED_INITIALIZERS
    #endif

    #if __has_feature( cxx_implicit_moves )
        #define CXX11_IMPLICIT_MOVES
    #endif

    #if __has_feature( cxx_lambdas )
        #define CXX11_LAMBDAS
    #endif

    #if __has_feature( cxx_noexcept )
        #define CXX11_NOEXCEPT
    #endif

    #if __has_feature( cxx_nullptr )
        #define CXX11_NULLPTR
    #endif

    #if __has_feature( cxx_strong_enums )
        #define CXX11_STRONG_ENUMS
    #endif

    #if __has_feature( cxx_variadic_templates )
        #define CXX11_VARIADIC_TEMPLATES
    #endif

    //-----------------------------------------------------------------------------
    // c++14

    #if __has_feature( __cxx_decltype_auto__ )
        #define CXX14_DECLTYPE_AUTO
    #endif

    #if __has_feature( cxx_relaxed_constexpr )
        #define CXX14_RELAXED_CONSTEXPR
    #endif

#endif
