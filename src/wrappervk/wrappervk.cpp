#include "wrappervk.h"

#include <algorithm>
#include <iostream>
#include <vector>

#include <vulkan/vulkan.h>

namespace {
	using namespace wrappervk;

	std::vector<std::pair<vkExtention, std::string>> extensionMap = {
		{vkExtention::ExtDebugReport,    "VK_EXT_debug_report"},
		{vkExtention::KhrSurface,        "VK_KHR_surface"},
		{vkExtention::KhrXcbSurface,     "VK_KHR_xcb_surface"},
		{vkExtention::KhrXlibSurface,    "VK_KHR_xlib_surface"},
		{vkExtention::KhrWaylandSurface, "VK_KHR_wayland_surface"}
	};

	[[maybe_unused]] vkExtention NameToExtension(std::string const & name)
	{
		auto iter = std::find_if(extensionMap.cbegin(), extensionMap.cend(), [&name](auto const & item){
			return item.second == name;
		});
		if (iter == extensionMap.cend())
			throw std::runtime_error("No extension named " + name);
		return iter->first;
	}

	[[maybe_unused]] std::string ExtensionToName(vkExtention ext)
	{
		auto iter = std::find_if(extensionMap.cbegin(), extensionMap.cend(), [&ext](auto const & item){
			return item.first == ext;
		});
		if (iter == extensionMap.cend())
			throw std::runtime_error("No name for extension " + std::to_string(int(ext)));
		return iter->second;
	}
}

namespace wrappervk {
	void Init()
	{
		std::cerr << "Vulkan wrapper initialized" << std::endl;
	}
}
