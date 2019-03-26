#pragma once

#include <vector>

namespace wrappervk {
	enum class vkExtension
	{
		ExtDebugReport,
		KhrSurface,
		KhrXcbSurface,
		KhrXlibSurface,
		KhrWaylandSurface,
		Unknown
	};

	void Init(std::vector<vkExtension> const & extensions);
}
