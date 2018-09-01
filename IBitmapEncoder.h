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

		virtual HBitmapEncoder clone(HBitmapIterator& bitmapIterator) = 0;
		virtual std::ostream& encodeToStream(HBitmapIterator&) = 0;
		virtual void encodeToStream(const std::ofstream& stream) = 0;
		virtual std::string getMimeType() = 0;
	};
}