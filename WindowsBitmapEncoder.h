#pragma once

#include "CodecLibrary.h"
#include "IBitmapEncoder.h"
#include "Bitmap.h"
#include "SizedWord.h"
#include <string>
#include <sstream>
#include <iostream>
#include <memory>

namespace BitmapGraphics
{	
	using HBitmapEncoder = std::shared_ptr<IBitmapEncoder>;

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
		std::ostream& encodeToStream(HBitmapIterator& bitmapIter); //encoder is created with an iterator and produces/encodes to a stream
		std::ostream& encodeToStream(std::ofstream& stream);
		std::string getMimeType();

	private:
		BitmapIterator myBitmapIterator;
		const std::string mimeType{ "image/x-ms-bmp" };
		static const Binary::DoubleWord alignmentValue;
		HBitmapEncoder myEncoder;
	};
}