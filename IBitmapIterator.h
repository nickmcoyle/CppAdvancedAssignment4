#pragma once

#include "Color.h"
#include <memory>

namespace BitmapGraphics
{
	class IBitmapIterator;
	using HBitmapIterator = std::shared_ptr<IBitmapIterator>;

	class IBitmapIterator
	{
	public:
		IBitmapIterator() = default;

		virtual ~IBitmapIterator() {};

		virtual void nextScanLine() = 0;
		virtual bool isEndOfImage() const = 0;
		virtual void nextPixel() = 0;
		virtual bool isEndOfScanLine() const = 0;

		virtual Color getColor() const = 0;

		virtual int getBitmapWidth() const = 0;
		virtual int getBitmapHeight() const = 0;

		virtual int getNumberOfPadBytes() const = 0;
	};
}