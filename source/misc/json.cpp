#include "Playground.hpp"

#if defined( __clang__ )
    #if ( __clang_major__ < 3 ) || ( ( __clang_major__ == 3 ) && ( __clang_minor__ <= 5 ) )
        // exclude those tests, there's issues with clang v3.5
        #define EXCLUDE_MISC_JSON
    #endif
#endif

#if defined( CXX11_NOEXCEPT ) && !defined( EXCLUDE_MISC_JSON )

#include "externs/json.hpp"
#include <iostream>

using namespace nlohmann;

namespace
{
    //-----------------------------------------------------------------------------
    TEST_CASE( "Json Construction", "[json]" )
    {
        json j = {
            { "pi", 3.141 },
            { "happy", true },
            { "name", "Niels" },
            { "nothing", nullptr },
            { "answer", {
                { "everything", 42 }
            } },
            { "list", { 1, 0, 2 } },
            { "object", {
                { "currency", "USD" },
                { "value", 42.99 }
            } }
        };

        CHECK( j["pi"].is_number_float() );
        CHECK( j["pi"] == Approx( 3.141 ) );

        CHECK( j["happy"].is_boolean() );
        CHECK( (bool)j["happy"] == true );

        CHECK( j["name"].is_string() );
        CHECK( j["name"] == "Niels" );

        CHECK( j["nothing"].is_null() );
        CHECK( j["nothing"] == nullptr );

        CHECK( j["answer"].is_object() );
        CHECK( (int)j["answer"]["everything"] == 42 );

        CHECK( j["list"].is_array() );
        CHECK( j["list"].size() == 3 );
        CHECK( (int)j["list"][0] == 1 );
        CHECK( (int)j["list"][1] == 0 );
        CHECK( (int)j["list"][2] == 2 );

        CHECK( j["object"].is_object() );
        CHECK( j["object"]["currency"].is_string() );
        CHECK( j["object"]["currency"] == "USD" );
        CHECK( j["object"]["value"].is_number_float() );
        CHECK( j["object"]["value"] == Approx( 42.99 ) );
    }

    //-----------------------------------------------------------------------------
    TEST_CASE( "Json Parsing", "[json]" )
    {
        std::string solutionFile = R"(
        {
            "solution": "Playground",
            "projects": [
                "Playground.prj.json"
            ]
        })";

        SECTION( "Playground.sln.json" )
        {
            auto j = json::parse(solutionFile);

            CHECK( j["solution"] == "Playground" );

            auto& projects = j["projects"];
            CHECK( projects.size() == 1 );
            CHECK( projects[0] == "Playground.prj.json" );
        }

        std::string projectFile = R"(
        {
          "project": "Playground",
          "configs": [
            {
              "name": "Debug",
              "defines": [
                "DEBUG"
              ],
              "includedirs": [
                "../../source"
              ],
              "pchsource": null
            },
            {
              "name": "Release",
              "defines": [
                "NDEBUG"
              ],
              "includedirs": [
                "../../source"
              ],
              "pchsource": null
            }
          ],
          "files": [
            "../../source/config/config.cpp",
            "../../source/features/ConstExpr.cpp",
            "../../source/features/HasInclude.cpp",
            "../../source/features/ImplicitMoves.cpp",
            "../../source/features/InitCaptures.cpp",
            "../../source/features/Variadics.cpp",
            "../../source/misc/CompileTimeCrc32.cpp",
            "../../source/misc/ConstLiffy.cpp",
            "../../source/Main.cpp"
          ]
        })";

        SECTION( "Playground.prj.json" )
        {
            auto j = json::parse(projectFile);

            CHECK( j["project"] == "Playground" );

            auto& configs = j["configs"];
            CHECK( j["configs"].size() == 2 );

            auto& debug = configs[0];
            CHECK( debug["name"] == "Debug" );
            CHECK( debug["defines"].size() == 1 );
            CHECK( debug["defines"][0] == "DEBUG" );
            CHECK( debug["includedirs"].size() == 1 );
            CHECK( debug["includedirs"][0] == "../../source" );
            CHECK( debug["pchsource"] == nullptr);

            auto& release = configs[1];
            CHECK( release["name"] == "Release" );
            CHECK( release["defines"].size() == 1 );
            CHECK( release["defines"][0] == "NDEBUG" );
            CHECK( release["includedirs"].size() == 1 );
            CHECK( release["includedirs"][0] == "../../source" );
            CHECK( release["pchsource"] == nullptr);

            auto& files = j["files"];
            CHECK( files.size() == 9 );
            CHECK( files[0] == "../../source/config/config.cpp" );
            CHECK( files[1] == "../../source/features/ConstExpr.cpp" );
            CHECK( files[2] == "../../source/features/HasInclude.cpp" );
            CHECK( files[3] == "../../source/features/ImplicitMoves.cpp" );
            CHECK( files[4] == "../../source/features/InitCaptures.cpp" );
            CHECK( files[5] == "../../source/features/Variadics.cpp" );
            CHECK( files[6] == "../../source/misc/CompileTimeCrc32.cpp" );
            CHECK( files[7] == "../../source/misc/ConstLiffy.cpp" );
            CHECK( files[8] == "../../source/Main.cpp" );
        }
    }
}

#endif
