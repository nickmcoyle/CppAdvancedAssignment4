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

		virtual std::string getMimeType() override;
		virtual bool isSupported(std::string header) override;		

	private:
		std::shared_ptr<Bitmap> HBitmap{ nullptr };
		static const std::string mimeType;
		static const Binary::DoubleWord alignmentValue;
	};
}