set (SOURCES wrappervk.cpp)
set (HEADERS wrappervk.h)

add_library (wrappervk ${SOURCES} ${HEADERS})

target_include_directories (wrappervk
	PUBLIC
	    ${CMAKE_CURRENT_SOURCE_DIR}
	PRIVATE
	    Vulkan::Vulkan)

target_link_libraries (wrappervk Vulkan::Vulkan)

if (WIN32)
	target_compile_definitions(wrappervk PUBLIC VK_USE_PLATFORM_WIN32_KHR)
elseif (APPLE)
	target_compile_definitions(wrappervk PUBLIC VK_USE_PLATFORM_MACOS_MVK) # TODO: Probably some MoltenVK stuff needed
elseif (LINUX)
	target_compile_definitions(wrappervk PUBLIC VK_USE_PLATFORM_${UnixWindowsSystem}_KHR)
else ()
	message (FATAL_ERROR "Unsupported platform. Win, Mac and Linux are supported only!")
endif ()
