#pragma once

//-----------------------------------------------------------------------------
// clang

#if defined( __clang__ )

    #define COMPILER_STR( a ) #a
    #define COMPILER_XSTR( a ) COMPILER_STR( a )

    #define COMPILER_IDENTIFICATION "clang-" COMPILER_XSTR( __clang_major__ ) "." COMPILER_XSTR( __clang_minor__ ) "." COMPILER_XSTR( __clang_patchlevel__ )

    #include "config/compiler_has_feature.hpp"

#endif
