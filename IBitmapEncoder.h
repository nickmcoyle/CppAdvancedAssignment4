#pragma once

#include <memory>
#include <iostream>
#include <string>

namespace BitmapGraphics
{
	class IBitmapEncoder
	{
	public:
		IBitmapEncoder() = default;

		virtual ~IBitmapEncoder() {};

		virtual HBitmapEncoder clone(const HBitmapIterator& bitmapIterator) = 0;
		virtual std::ostream& encodeToStream(HBitmapIterator&) = 0;
		virtual std::string getMimeType() = 0;
	};
}