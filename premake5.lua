workspace "cs_rl"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release"
    }

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["glm"] = "cs_rl/vendor/glm"
IncludeDir["SFML"] = "cs_rl/vendor/SFML/include"

project "cs_rl"
    location "cs_rl"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

    targetdir ("bin/")
    objdir ("bin-int/")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
        "%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl",
    }

    defines 
    { 
        "SFML_STATIC"
    }

    includedirs
    {
        "%{prj.name}/src",
        "%{IncludeDir.glm}",
        "%{IncludeDir.SFML}"

    }

	links
    {	
        "sfml-graphics",
        "sfml-window",
        "sfml-system",
        "sfml-audio",
        "sfml-network"
    }

    filter "system.Unix"
        systemversion "latest"
        defines
        {
            "CS_RL_PLATFORM_UNIX"
        }
        
    filter "configurations:Debug"
		defines { "CS_RL_DEBUG"}
		symbols "On"

	filter "configurations:Release"
		defines { "CS_RL_RELEASE" }
		optimize "On"
