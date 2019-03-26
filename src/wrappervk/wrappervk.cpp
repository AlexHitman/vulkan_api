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

	__attribute__((unused)) vkExtention NameToExtension(std::string const & name)
	{
		auto iter = std::find_if(extensionMap.cbegin(), extensionMap.cend(), [&name](auto const & item){
			return item.second == name;
		});
		if (iter == extensionMap.cend())
			throw std::runtime_error("No extension named " + name);
		return iter->first;
	}

	std::string const & ExtensionToName(vkExtention ext)
	{
		auto iter = std::find_if(extensionMap.cbegin(), extensionMap.cend(), [&ext](auto const & item){
			return item.first == ext;
		});
		if (iter == extensionMap.cend())
			throw std::runtime_error("No name for extension " + std::to_string(int(ext)));
		return iter->second;
	}

	std::vector<VkExtensionProperties> GetAvailableExtensions()
	{
		uint32_t extensionCount = 0;
		if(vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr) != VK_SUCCESS) {
			std::cerr << "Can't get number of vulkan extensions" << std::endl;
			return {};
		}

		std::vector<VkExtensionProperties> extensions(extensionCount);
		if(vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, extensions.data()) != VK_SUCCESS) {
			std::cerr << "Can't get vulkan extensions" << std::endl;
			return {};
		}

		return extensions;
	}
}

namespace wrappervk {
	void Init(std::vector<vkExtention> const & extensions)
	{
		const std::vector<VkExtensionProperties> availableExtensions = GetAvailableExtensions();

		std::cerr << "Available vulkan extensions:" << std::endl;
		for (const auto & extension: availableExtensions)
			std::cerr << "\t" << extension.extensionName << std::endl;

		std::vector<VkExtensionProperties> extensionsToUse;
		for (auto const & item: extensions)
		{
			std::string const & name = ExtensionToName(item);
			const auto iter = find_if(availableExtensions.cbegin(), availableExtensions.cend(), [&name](auto const & availableItem) {
				return name == availableItem.extensionName;
			});
			if (iter != availableExtensions.cend())
				extensionsToUse.push_back(*iter);
			else
				std::cerr << "Extension " << name << " is not available";
		};

		//TODO: init vk

		std::cerr << "Vulkan wrapper initialized" << std::endl;
	}
}
