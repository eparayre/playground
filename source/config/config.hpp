#pragma once

#include "compiler_clang.hpp"
#include "compiler_gcc.hpp"
#include "compiler_msvc.hpp"

#include <string>
#include <vector>

//-----------------------------------------------------------------------------
class CompilerInfo
{
public:
    static std::string CompilerIdentification();

    static void DumpSupportedFeatures();

private:
    using Features = std::vector< std::string >;

    static void FillCxx11Features( Features& features );
    static void FillCxx14Features( Features& features );
};
