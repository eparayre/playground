#include "config/config.hpp"

#define CATCH_CONFIG_RUNNER
#include "catch.hpp"

//-----------------------------------------------------------------------------
int main( int argc, char* const argv[] )
{
    CompilerInfo::DumpSupportedFeatures();

    return Catch::Session().run( argc, argv );
}
