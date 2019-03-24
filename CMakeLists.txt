cmake_minimum_required (VERSION 3.8)
project (vulkan_api)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED on)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")

if (UNIX AND NOT APPLE AND NOT CYGWIN)
	set (LINUX TRUE)
endif ()

if (DEFINED ENV{VULKAN_SDK})
	message("Vulkan SDK path: $ENV{VULKAN_SDK}")
else ()
	message(FATAL_ERROR "Vulkan SDK does not setup properly")
endif ()

find_package (Vulkan REQUIRED)

set(UnixWindowsSystem "XCB" CACHE STRING "Unix windows system library: XCB, XLIB, WAYLAND, MIR")
set_property(CACHE UnixWindowsSystem PROPERTY STRINGS XCB XLIB WAYLAND MIR)
message("UNIX windows system library: ${UnixWindowsSystem}")

add_subdirectory (src/wrappervk)
add_subdirectory (src/example)
