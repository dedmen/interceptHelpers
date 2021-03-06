cmake_minimum_required (VERSION 3.7)


message(STATUS "Cmake Generator: ${CMAKE_GENERATOR}")

#if("${CMAKE_GENERATOR}" MATCHES "Visual Studio 15 2017 Win64")
#	set( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} /std:c++latest" )
#	set( USE_64BIT_BUILD ON)
#elseif("${CMAKE_GENERATOR}" MATCHES "Visual Studio 15 2017")
#	set( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} /std:c++latest" )
#elseif("${CMAKE_CXX_COMPILER_ID}" MATCHES "MSVC")
#	message(FATAL_ERROR "ERROR: You need a C++17 compatible compiler")
#endif()

if(USE_64BIT_BUILD)
	set(PLUGIN_NAME InterceptHelper_x64)
else()
	set(PLUGIN_NAME InterceptHelper)
endif()

project(${PLUGIN_NAME})

set( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} /std:c++latest" )

# Double detection is necessary as 'project' wipes previous 'set's
#if("${CMAKE_GENERATOR}" MATCHES "Visual Studio 15 2017 Win64")
#	set( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} /std:c++latest" )
#	set( USE_64BIT_BUILD ON)
#elseif("${CMAKE_GENERATOR}" MATCHES "Visual Studio 15 2017")
#	set( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} /std:c++latest" )
#elseif("${CMAKE_CXX_COMPILER_ID}" MATCHES "MSVC")
#	message(FATAL_ERROR "ERROR: You need a C++17 compatible compiler")
#endif()

# Intercept is either read from enviroment variable or searched two dirs up
if ("$ENV{INTERCEPT_PATH}" STREQUAL "")
	set(INTERCEPT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../../intercept/)
else()
	set(INTERCEPT_PATH $ENV{INTERCEPT_PATH})
endif()

# Log infos
message(STATUS "Intercept path: ${INTERCEPT_PATH}" )

if(CMAKE_COMPILER_IS_GNUCXX)
	# This target defaults to 32-bit on linux
	SET(CMAKE_CXX_FLAGS "-std=c++11 -march=i686 -m32 -O2 -s -fPIC -fpermissive")

	if(ACRE_LINK_TYPE STREQUAL "static")
		set(CMAKE_FIND_LIBRARY_SUFFIXES ".a")
		set(CMAKE_SHARED_LINKER_FLAGS "-static-libgcc -static-libstdc++")
	endif()
elseif(MSVC)
	if(ACRE_LINK_TYPE STREQUAL "static")
		set(CMAKE_CXX_FLAGS_DEBUG "/D _DEBUG /MTd /Zi /Ob0 /Od /RTC1" PARENT_SCOPE)
		set(CMAKE_CXX_FLAGS_MINSIZEREL     "/MT /O1 /Ob1 /D NDEBUG" PARENT_SCOPE)
		set(CMAKE_CXX_FLAGS_RELEASE       "/MT /O2 /Ob2 /D NDEBUG" PARENT_SCOPE)
		set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "/MT /Zi /O2 /Ob1 /D NDEBUG" PARENT_SCOPE)
	else()
		set(CMAKE_CXX_FLAGS_DEBUG "/D _DEBUG /MDd /bigobj /Zi /Ob0 /Od /RTC1")
		set(CMAKE_CXX_FLAGS_MINSIZEREL     "/MD /bigobj /O1 /Ob1 /D NDEBUG")
		set(CMAKE_CXX_FLAGS_RELEASE       "/MD /bigobj /O2 /Ob2 /D NDEBUG")
		set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "/MD /bigobj /Zi /O2 /Ob1 /D NDEBUG")
	endif()

	set(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} /NODEFAULTLIB:libcmt.lib")
	set(CMAKE_EXE_LINKER_FLAGS_MINSIZEREL "${CMAKE_EXE_LINKER_FLAGS_MINSIZEREL} /NODEFAULTLIB:libcmt.lib")
	set(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} /NODEFAULTLIB:libcmt.lib")
	set(CMAKE_EXE_LINKER_FLAGS_RELWITHDEBINFO "${CMAKE_EXE_LINKER_FLAGS_RELWITHDEBINFO} /NODEFAULTLIB:libcmt.lib")
endif()

file(GLOB SOURCES *.h *.hpp *.c *.cpp) # Grab all source files and stuff them into ${SOURCES}
file(GLOB INTERCEPT_CLIENT_SOURCES ${INTERCEPT_PATH}/src/client/headers/*.hpp ${INTERCEPT_PATH}/src/client/intercept/*.cpp)
file(GLOB INTERCEPT_CLIENT_MAIN_SOURCES  ${INTERCEPT_PATH}/src/client/headers/client/*.hpp ${INTERCEPT_PATH}/src/client/intercept/client/*.cpp)
file(GLOB INTERCEPT_CLIENT_SHARED_SOURCES  ${INTERCEPT_PATH}/src/client/headers/shared/*.hpp ${INTERCEPT_PATH}/src/client/intercept/shared/*.cpp)
file(GLOB INTERCEPT_CLIENT_SQF_SHARED_SOURCES ${INTERCEPT_PATH}/src/client/headers/client/sqf/*.hpp ${INTERCEPT_PATH}/src/client/intercept/client/sqf/*.cpp)

SOURCE_GROUP("intercepthelper" FILES ${SOURCES})
SOURCE_GROUP("includes\\intercept" FILES ${INTERCEPT_CLIENT_HEADERS})
SOURCE_GROUP("includes\\intercept\\client" FILES ${INTERCEPT_CLIENT_MAIN_SOURCES})
SOURCE_GROUP("includes\\intercept\\shared" FILES ${INTERCEPT_CLIENT_SHARED_SOURCES})
SOURCE_GROUP("includes\\intercept\\client\\sqf" FILES ${INTERCEPT_CLIENT_SQF_SHARED_SOURCES})

include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${INTERCEPT_PATH}/src/client/headers ${INTERCEPT_PATH}/src/client/headers/client ${INTERCEPT_PATH}/src/client/headers/client/sqf ${INTERCEPT_PATH}/src/client/headers/client/shared)

add_library(${PLUGIN_NAME} SHARED ${SOURCES} ${INTERCEPT_CLIENT_HEADERS} ${INTERCEPT_CLIENT_MAIN_SOURCES} ${INTERCEPT_CLIENT_SHARED_SOURCES} ${INTERCEPT_CLIENT_SQF_SHARED_SOURCES})

target_link_libraries(${PLUGIN_NAME} ${LINK_LIBS})