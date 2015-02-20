# CMake entry point
cmake_minimum_required(VERSION 2.8)
project (SplendidMines)  # TODO: version number

find_package(PkgConfig)
pkg_check_modules(GTKMM gtkmm-3.0)

if ("${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang")
	message(STATUS "Using clang.")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
endif()

add_definitions(
	-std=c++11
	-g
	-Wall
	-Wextra
)

include_directories(${GTKMM_INCLUDE_DIRS})

file(GLOB CORE_SOURCES core/*.cpp)
file(GLOB GUI_SOURCES gui/*.cpp)
file(GLOB FRONTEND_SOURCES frontend/*.cpp)

if(WIN32)
add_executable(splendidmines WIN32
    ${CORE_SOURCES}
    ${GUI_SOURCES}
    ${FRONTEND_SOURCES} )
else(WIN32)
add_executable(splendidmines
    ${CORE_SOURCES}
    ${GUI_SOURCES}
    ${FRONTEND_SOURCES} )
endif(WIN32)

link_directories(${GTKMM_LIBRARY_DIRS})

target_link_libraries(splendidmines ${GTKMM_LIBRARIES})

add_custom_command(
	TARGET splendidmines POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_SOURCE_DIR}/frontend/splendidmines.glade" "${CMAKE_CURRENT_BINARY_DIR}/splendidmines.glade"
	COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_SOURCE_DIR}/frontend/selfdefined.glade" "${CMAKE_CURRENT_BINARY_DIR}/selfdefined.glade"
	COMMAND ${CMAKE_COMMAND} -E copy_directory "${CMAKE_CURRENT_SOURCE_DIR}/textures" "${CMAKE_CURRENT_BINARY_DIR}/textures"
)
