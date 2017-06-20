#include "config/config.hpp"

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

    FillMacros( features );
    FillCxx11Features( features );
    FillCxx14Features( features );
    FillCxx17Features( features );

    std::sort( features.begin(), features.end() );

    ScopedParagraph paragraph( COMPILER_IDENTIFICATION );

    for (const auto& feature : features)
    {
        std::cout << "> " << feature << std::endl;
    }
}

//-----------------------------------------------------------------------------
void CompilerInfo::FillMacros( Features& features )
{
    (void)features;

#ifdef CXX_HAS_ATTRIBUTE
    features.emplace_back( "cxx_macro_has_attribute" );
#endif

#ifdef CXX_HAS_ATTRIBUTE_CPP
    features.emplace_back( "cxx_macro_has_attribute_cpp" );
#endif

#ifdef CXX_HAS_ATTRIBUTE_DECLSPEC
    features.emplace_back( "cxx_macro_has_attribute_declspec" );
#endif

#ifdef CXX_HAS_BUILTIN
    features.emplace_back( "cxx_macro_has_builtin" );
#endif

#ifdef CXX_HAS_EXTENSION
    features.emplace_back( "cxx_macro_has_extension" );
#endif

#ifdef CXX_HAS_FEATURE
    features.emplace_back( "cxx_macro_has_feature" );
#endif

#ifdef CXX_HAS_INCLUDE
    features.emplace_back( "cxx_macro_has_include" );
#endif

#ifdef CXX_HAS_INCLUDE_NEXT
    features.emplace_back( "cxx_macro_has_include_next" );
#endif

#ifdef CXX_HAS_WARNING
    features.emplace_back( "cxx_macro_has_warning" );
#endif
}

//-----------------------------------------------------------------------------
void CompilerInfo::FillCxx11Features( Features& features )
{
    (void)features;

#ifdef CXX11_ALIAS_TEMPLATES
    features.emplace_back( "cxx11_alias_templates" );
#endif

#ifdef CXX11_CONSTEXPR
    features.emplace_back( "cxx11_constexpr" );
#endif

#ifdef CXX11_DECLTYPE
    features.emplace_back( "cxx11_decltype" );
#endif

#ifdef CXX11_DEFAULTED_FUNCTIONS
    features.emplace_back( "cxx11_defaulted_functions" );
#endif

#ifdef CXX11_DELEGATING_CONSTRUCTORS
    features.emplace_back( "cxx11_delegating_constructors" );
#endif

#ifdef CXX11_DELETED_FUNCTIONS
    features.emplace_back( "cxx11_deleted_functions" );
#endif

#ifdef CXX11_GENERALIZED_INITIALIZERS
    features.emplace_back( "cxx11_generalized_initializers" );
#endif

#ifdef CXX11_IMPLICIT_MOVES
    features.emplace_back( "cxx11_implicit_moves" );
#endif

#ifdef CXX11_INHERITING_CONSTRUCTORS
    features.emplace_back( "cxx11_inheriting_constructors" );
#endif

#ifdef CXX11_LAMBDAS
    features.emplace_back( "cxx11_lambdas" );
#endif

#ifdef CXX11_NOEXCEPT
    features.emplace_back( "cxx11_noexcept" );
#endif

#ifdef CXX11_NULLPTR
    features.emplace_back( "cxx11_nullptr" );
#endif

#ifdef CXX11_OVERRIDE_CONTROL
    features.emplace_back( "cxx11_override_control" );
#endif

#ifdef CXX11_STRONG_ENUMS
    features.emplace_back( "cxx11_strong_enums" );
#endif

#ifdef CXX11_VARIADIC_TEMPLATES
    features.emplace_back( "cxx11_variadic_templates" );
#endif
}

//-----------------------------------------------------------------------------
void CompilerInfo::FillCxx14Features( Features& features )
{
    (void)features;

#ifdef CXX14_DECLTYPE_AUTO
    features.emplace_back( "cxx14_decltype_auto" );
#endif

#ifdef CXX14_INIT_CAPTURES
    features.emplace_back( "cxx14_init_captures" );
#endif

#ifdef CXX14_RELAXED_CONSTEXPR
    features.emplace_back( "cxx14_relaxed_constexpr" );
#endif
}

//-----------------------------------------------------------------------------
void CompilerInfo::FillCxx17Features( Features& features )
{
    (void)features;
}
