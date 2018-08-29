#pragma once

#include "CodecLibrary.h"
#include "IBitmapDecoder.h"
#include "Bitmap.h"
#include "SizedWord.h"
#include <string>
#include <sstream>
#include <iostream>
#include <memory>

namespace BitmapGraphics
{
	class WindowsBitmapDecoder : public IBitmapDecoder
	{
	public:
		WindowsBitmapDecoder();
		WindowsBitmapDecoder(const Bitmap& bitmap);

		WindowsBitmapDecoder(const WindowsBitmapDecoder&) = default;
		WindowsBitmapDecoder(WindowsBitmapDecoder&&) = default;

		WindowsBitmapDecoder& operator=(const WindowsBitmapDecoder&) = default;
		WindowsBitmapDecoder& operator=(WindowsBitmapDecoder&&) = default;

		~WindowsBitmapDecoder();

		HBitmapDecoder clone(std::string const& firstChunk, std::istream& sourceStream);
		HBitmapDecoder clone(std::istream& sourceStream);
		HBitmapIterator createIterator(std::istream& sourceStream); //created with a stream and produces an iterator
		std::string getMimeType();
		bool isSupported(std::string header);

		const Binary::Byte& getNextByte(std::stringstream ss);

	private:
		Bitmap myBitmap;
		const std::string mimeType{ "image/x-ms-bmp" };
		static const Binary::DoubleWord alignmentValue;
		HBitmapDecoder myDecoder;
	};
}