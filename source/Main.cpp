#define CATCH_CONFIG_RUNNER
#include "catch.hpp"

#include "config/config.hpp"

namespace
{
    //-----------------------------------------------------------------------------
    void DumpCxx11Features()
    {
    #ifdef CXX11_ALIAS_TEMPLATES
        std::cout << "> cxx11_alias_templates" << std::endl;
    #endif

    #ifdef CXX11_CONSTEXPR
        std::cout << "> cxx11_constexpr" << std::endl;
    #endif

    #ifdef CXX11_DECLTYPE
        std::cout << "> cxx11_decltype" << std::endl;
    #endif

    #ifdef CXX11_DEFAULTED_FUNCTIONS
        std::cout << "> cxx11_defaulted_functions" << std::endl;
    #endif

    #ifdef CXX11_DELETED_FUNCTIONS
        std::cout << "> cxx11_deleted_functions" << std::endl;
    #endif

    #ifdef CXX11_GENERALIZED_INITIALIZERS
        std::cout << "> cxx11_generalized_initializers" << std::endl;
    #endif

    #ifdef CXX11_IMPLICIT_MOVES
        std::cout << "> cxx11_implicit_moves" << std::endl;
    #endif

    #ifdef CXX11_LAMBDAS
        std::cout << "> cxx11_lambdas" << std::endl;
    #endif

    #ifdef CXX11_NOEXCEPT
        std::cout << "> cxx11_noexcept" << std::endl;
    #endif

    #ifdef CXX11_NULLPTR
        std::cout << "> cxx11_nullptr" << std::endl;
    #endif

    #ifdef CXX11_STRONG_ENUMS
        std::cout << "> cxx11_strong_enums" << std::endl;
    #endif

    #ifdef CXX11_VARIADIC_TEMPLATES
        std::cout << "> cxx11_variadic_templates" << std::endl;
    #endif
    }

    //-----------------------------------------------------------------------------
    void DumpCxx14Features()
    {
    #ifdef CXX14_DECLTYPE_AUTO
        std::cout << "> cxx14_decltype_auto" << std::endl;
    #endif

    #ifdef CXX14_RELAXED_CONSTEXPR
        std::cout << "> cxx14_relaxed_constexpr" << std::endl;
    #endif
    }

    //-----------------------------------------------------------------------------
    void DumpCxxFeatures()
    {
        std::cout << std::endl;

        DumpCxx11Features();
        DumpCxx14Features();

        std::cout << std::endl;
    }
}

//-----------------------------------------------------------------------------
int main( int argc, char* const argv[] )
{
    DumpCxxFeatures();

    return Catch::Session().run( argc, argv );
}
