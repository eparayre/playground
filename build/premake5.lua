
local Playground = {}

Playground.RootDir = path.getabsolute( ".." );
Playground.SrcDir  = path.join( Playground.RootDir, "source" )
Playground.OutDir  = path.join( Playground.RootDir, "output/" .. _ACTION )
Playground.BinDir  = path.join( Playground.OutDir, "bin" )
Playground.ObjDir  = path.join( Playground.OutDir, "obj" )

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

        includedirs { Playground.SrcDir }

        files {
            path.join( Playground.SrcDir, "**.h" ),
            path.join( Playground.SrcDir, "**.hpp" ),
            path.join( Playground.SrcDir, "**.inl" ),

            path.join( Playground.SrcDir, "**.c" ),
            path.join( Playground.SrcDir, "**.cpp" ),
            path.join( Playground.SrcDir, "**.cxx" )
        }

        configuration { "Debug" }
            defines { "DEBUG" }
            flags { "Symbols" }

        configuration { "Release" }
            defines { "NDEBUG" }
            flags { "Optimize" }

        configuration { "gmake" }
            postbuildcommands { "$(TARGET)" }
            buildoptions { "-std=gnu++0x" }

        configuration { "vs*" }
            postbuildcommands { "\"$(TargetPath)\"" }
end

if _ACTION then
    Playground.GenerateSolution()
end
