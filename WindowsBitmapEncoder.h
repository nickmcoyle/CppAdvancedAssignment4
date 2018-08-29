#pragma once

#include "IBitmapEncoder.h"
#include "Bitmap.h"
#include <string>
#include <iostream>

namespace BitmapGraphics
{	
	class WindowsBitmapEncoder : public IBitmapEncoder
	{
	public:
		WindowsBitmapEncoder();

		WindowsBitmapEncoder(const WindowsBitmapEncoder&) = default;
		WindowsBitmapEncoder(WindowsBitmapEncoder&&) = default;

		WindowsBitmapEncoder& operator=(const WindowsBitmapEncoder&) = default;
		WindowsBitmapEncoder& operator=(WindowsBitmapEncoder&&) = default;

		~WindowsBitmapEncoder();

		HBitmapEncoder clone(const HBitmapIterator& bitmapIterator);
		std::ostream encodeToStream(HBitmapIterator& bitmapIter); //encoder is created with an iterator and produces/encodes to a stream
		std::string getMimeType();

	private:
		BitmapIterator myBitmapIterator;
		const std::string mimeType{ "image/x-ms-bmp" };
		static const Binary::DoubleWord alignmentValue;
		HBitmapEncoder myEncoder;
	};
}