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
		WindowsBitmapDecoder() = default;
		
		WindowsBitmapDecoder(const WindowsBitmapDecoder&) = default;
		WindowsBitmapDecoder(WindowsBitmapDecoder&&) = default;

		WindowsBitmapDecoder& operator=(const WindowsBitmapDecoder&) = default;
		WindowsBitmapDecoder& operator=(WindowsBitmapDecoder&&) = default;

		~WindowsBitmapDecoder() = default;

		virtual HBitmapDecoder clone(std::istream& sourceStream) override;
		virtual HBitmapIterator createIterator() override;
		//virtual HBitmapIterator createIterator(std::istream& sourceStream) override; //created with a stream and produces an iterator		

		virtual std::string getMimeType() override;
		virtual bool isSupported(std::string header) override;

		//const Binary::Byte& getNextByte(std::stringstream ss);

	private:
		std::shared_ptr<Bitmap> HBitmap{ nullptr };
		const std::string mimeType{ "image/x-ms-bmp" };
		static const Binary::DoubleWord alignmentValue;
	};
}