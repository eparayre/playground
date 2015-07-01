
local Playground = {}

Playground.RootDir   = path.getabsolute( ".." );
Playground.SourceDir = path.join( Playground.RootDir, "source" )

Playground.OutDir = path.join( Playground.RootDir, "output/" .. _ACTION )
Playground.BinDir = path.join( Playground.OutDir, "bin" )
Playground.ObjDir = path.join( Playground.OutDir, "obj" )

function Playground.GenerateSolution()
    print( "Generating Playground..." )
    print( "  { RootDir = " .. Playground.RootDir .. " }" )
    print( "  { OutDir  = " .. Playground.OutDir  .. " }" )
    print( "  { BinDir  = " .. Playground.BinDir  .. " }" )
    print( "  { ObjDir  = " .. Playground.ObjDir  .. " }" )

    Playground.sln = solution( "Playground" )
        configurations( { "Debug", "Release" } )
        location( _ACTION )

        configuration( "Debug" )
            targetdir( path.join( Playground.BinDir, "Debug" ) )
            objdir( Playground.ObjDir )

        configuration( "Release" )
            targetdir( path.join( Playground.BinDir, "Release" ) )
            objdir( Playground.ObjDir )

    Playground.GenerateProject()

    print()
end

function Playground.GenerateProject()
    Playground.prj = project( "Playground" )
        kind( "ConsoleApp" )
        language( "C++" )

        includedirs { Playground.SourceDir }

        files {
            path.join( Playground.SourceDir, "**.h" ),
            path.join( Playground.SourceDir, "**.hpp" ),
            path.join( Playground.SourceDir, "**.inl" ),

            path.join( Playground.SourceDir, "**.c" ),
            path.join( Playground.SourceDir, "**.cpp" ),
            path.join( Playground.SourceDir, "**.cxx" )
        }

        configuration { "Debug" }
            defines { "DEBUG" }
            flags { "Symbols", "ExtraWarnings", "FatalWarnings" }

        configuration { "Release" }
            defines { "NDEBUG" }
            flags { "Optimize", "ExtraWarnings", "FatalWarnings" }

        configuration { "gmake" }
            postbuildcommands { "$(TARGET)" }
            buildoptions { "-std=c++11", "-std=c++14", "-std=c++17" }

        configuration { "vs*" }
            postbuildcommands { "\"$(TargetPath)\"" }
end

if _ACTION then
    Playground.GenerateSolution()
end
