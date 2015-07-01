#include "config.hpp"

#include <algorithm>
#include <iostream>
#include <sstream>

namespace
{
    //-----------------------------------------------------------------------------
    struct ScopedParagraph
    {
        ScopedParagraph( const std::string& header )
        {
            std::cout << std::endl;
            std::cout << header << std::endl;
        }

        ~ScopedParagraph()
        {
            std::cout << std::endl;
        }
    };
}

//-----------------------------------------------------------------------------
void CompilerInfo::DumpSupportedFeatures()
{
    Features features;

    FillCxx11Features( features );
    FillCxx14Features( features );

    std::sort( features.begin(), features.end() );

    ScopedParagraph paragraph( COMPILER_IDENTIFICATION );

    for (const auto& feature : features)
    {
        std::cout << "> " << feature << std::endl;
    }
}

//-----------------------------------------------------------------------------
void CompilerInfo::FillCxx11Features( Features& features )
{
    (void)features;

#ifdef CXX11_ALIAS_TEMPLATES
    features.push_back( "cxx11_alias_templates" );
#endif

#ifdef CXX11_CONSTEXPR
    features.push_back( "cxx11_constexpr" );
#endif

#ifdef CXX11_DECLTYPE
    features.push_back( "cxx11_decltype" );
#endif

#ifdef CXX11_DEFAULTED_FUNCTIONS
    features.push_back( "cxx11_defaulted_functions" );
#endif

#ifdef CXX11_DELETED_FUNCTIONS
    features.push_back( "cxx11_deleted_functions" );
#endif

#ifdef CXX11_GENERALIZED_INITIALIZERS
    features.push_back( "cxx11_generalized_initializers" );
#endif

#ifdef CXX11_IMPLICIT_MOVES
    features.push_back( "cxx11_implicit_moves" );
#endif

#ifdef CXX11_LAMBDAS
    features.push_back( "cxx11_lambdas" );
#endif

#ifdef CXX11_NOEXCEPT
    features.push_back( "cxx11_noexcept" );
#endif

#ifdef CXX11_NULLPTR
    features.push_back( "cxx11_nullptr" );
#endif

#ifdef CXX11_STRONG_ENUMS
    features.push_back( "cxx11_strong_enums" );
#endif

#ifdef CXX11_VARIADIC_TEMPLATES
    features.push_back( "cxx11_variadic_templates" );
#endif
}

//-----------------------------------------------------------------------------
void CompilerInfo::FillCxx14Features( Features& features )
{
    (void)features;

#ifdef CXX14_DECLTYPE_AUTO
    features.push_back( "cxx14_decltype_auto" );
#endif

#ifdef CXX14_INIT_CAPTURES
    features.push_back( "cxx14_init_captures" );
#endif

#ifdef CXX14_RELAXED_CONSTEXPR
    features.push_back( "cxx14_relaxed_constexpr" );
#endif
}
