#pragma once

#include "IBitmapIterator.h"
#include <memory>
#include <iostream>
#include <string>

namespace BitmapGraphics
{
	class IBitmapEncoder;
	using HBitmapEncoder = std::shared_ptr<IBitmapEncoder>;

	class IBitmapEncoder
	{
	public:
		IBitmapEncoder() = default;

		virtual ~IBitmapEncoder() {};

		virtual HBitmapEncoder clone(const HBitmapIterator& bitmapIterator) = 0;
		virtual std::ostream& encodeToStream(HBitmapIterator&) = 0;
		virtual void encodeToStream(const std::ofstream& stream) = 0;
		virtual std::string getMimeType() = 0;
	};
}