#define CATCH_CONFIG_RUNNER
#include "catch.hpp"

#include "config/config.hpp"

namespace
{
    //-----------------------------------------------------------------------------
    void DumpCxx11Features()
    {
        std::cout << std::endl << "C++11 :" << std::endl;

    #ifdef CXX11_ALIAS_TEMPLATES
        std::cout << "> cxx_alias_templates" << std::endl;
    #endif

    #ifdef CXX11_CONSTEXPR
        std::cout << "> cxx_constexpr" << std::endl;
    #endif

    #ifdef CXX11_DECLTYPE
        std::cout << "> cxx_decltype" << std::endl;
    #endif

    #ifdef CXX11_DEFAULTED_FUNCTIONS
        std::cout << "> cxx_defaulted_functions" << std::endl;
    #endif

    #ifdef CXX11_DELETED_FUNCTIONS
        std::cout << "> cxx_deleted_functions" << std::endl;
    #endif

    #ifdef CXX11_GENERALIZED_INITIALIZERS
        std::cout << "> cxx_generalized_initializers" << std::endl;
    #endif

    #ifdef CXX11_IMPLICIT_MOVES
        std::cout << "> cxx_implicit_moves" << std::endl;
    #endif

    #ifdef CXX11_LAMBDAS
        std::cout << "> cxx_lambdas" << std::endl;
    #endif

    #ifdef CXX11_NOEXCEPT
        std::cout << "> cxx_noexcept" << std::endl;
    #endif

    #ifdef CXX11_NULLPTR
        std::cout << "> cxx_nullptr" << std::endl;
    #endif

    #ifdef CXX11_STRONG_ENUMS
        std::cout << "> cxx_strong_enums" << std::endl;
    #endif

    #ifdef CXX11_VARIADIC_TEMPLATES
        std::cout << "> cxx_variadic_templates" << std::endl;
    #endif
    }

    //-----------------------------------------------------------------------------
    void DumpCxx14Features()
    {
        std::cout << std::endl << "C++14 :" << std::endl;

    #ifdef CXX14_DECLTYPE_AUTO
        std::cout << "> cxx_decltype_auto" << std::endl;
    #endif

    #ifdef CXX14_RELAXED_CONSTEXPR
        std::cout << "> cxx_relaxed_constexpr" << std::endl;
    #endif
    }

    //-----------------------------------------------------------------------------
    void DumpCxxFeatures()
    {
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
