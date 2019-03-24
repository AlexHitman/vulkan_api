#pragma once

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

	void Init();
}
