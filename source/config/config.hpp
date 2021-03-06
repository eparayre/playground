#pragma once

#include "compiler_common.hpp"
#include "compiler_clang.hpp"
#include "compiler_gcc.hpp"
#include "compiler_msvc.hpp"

#if !defined( COMPILER_IDENTIFICATION )
    #define COMPILER_IDENTIFICATION "unknown"
#endif

#include <string>
#include <vector>

//-----------------------------------------------------------------------------
class CompilerInfo
{
public:
    static void DumpSupportedFeatures();

private:
    using Features = std::vector< std::string >;

    static void FillMacros( Features& features );
    static void FillCxx11Features( Features& features );
    static void FillCxx14Features( Features& features );
    static void FillCxx17Features( Features& features );
};
