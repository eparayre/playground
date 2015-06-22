
function AddLocation(target)
    configuration(target)
        location(target)
end

function SetupDefaultConfigs()
    configuration "Debug"
        defines { "DEBUG" }
        objdir "../tmp/obj"
        targetdir "../tmp/bin"
        flags { "Symbols" }

    configuration "Release"
        defines { "NDEBUG" }
        objdir "../tmp/obj"
        targetdir "../tmp/bin"
        flags { "Optimize" }

    configuration "*"
end

function SetupPostBuildExecute()
    configuration {"gmake"}
		postbuildcommands  { "$(TARGET)" }
        
    configuration { "vs*" }
        postbuildcommands { "\"$(TargetPath)\"" }
end

function GenerateSolution()
    solution "Playground"
        configurations { "Debug", "Release" }

        AddLocation("gmake")
        AddLocation("vs2012")
        AddLocation("vs2013")
        AddLocation("vs2015")

        project "Playground"
            kind "StaticLib"
            SetupDefaultConfigs()
            files {
                "../source/**.h",
                "../source/**.hpp",
                "../source/**.cpp" }

        project "Playground.Test"
            kind "ConsoleApp"
            SetupDefaultConfigs()
            SetupPostBuildExecute();
            files {
                "../test/**.h",
                "../test/**.hpp",
                "../test/**.cpp" }
end

GenerateSolution()
