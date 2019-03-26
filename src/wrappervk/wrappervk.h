#pragma once

#include <vector>

namespace wrappervk {
	enum class vkExtention
	{
		ExtDebugReport,
		KhrSurface,
		KhrXcbSurface,
		KhrXlibSurface,
		KhrWaylandSurface,
		Unknown
	};

	void Init(std::vector<vkExtention> const & extensions);
}
