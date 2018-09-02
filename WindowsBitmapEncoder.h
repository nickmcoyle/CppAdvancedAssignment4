#pragma once

#include "CodecLibrary.h"
#include "IBitmapEncoder.h"
#include "Bitmap.h"
#include "SizedWord.h"
#include "WindowsBitmapHeader.h"
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <memory>

namespace BitmapGraphics
{
	class WindowsBitmapEncoder : public IBitmapEncoder
	{
	public:
		WindowsBitmapEncoder() = default;
		WindowsBitmapEncoder(const WindowsBitmapEncoder&) = default;
		WindowsBitmapEncoder(WindowsBitmapEncoder&&) = default;
		WindowsBitmapEncoder& operator=(const WindowsBitmapEncoder&) = default;
		WindowsBitmapEncoder& operator=(WindowsBitmapEncoder&&) = default;
		~WindowsBitmapEncoder() = default;

		virtual HBitmapEncoder clone(const HBitmapIterator& bitmapIterator) override;
		virtual std::ostream& encodeToStream(HBitmapIterator& bitmapIter) override; //encoder is created with an iterator and produces/encodes to a stream
		virtual void encodeToStream(const std::ofstream& stream) override;		
		virtual std::string getMimeType() override;

	private:				
		static const std::string mimeType;
		static const Binary::DoubleWord alignmentValue;
	};
}