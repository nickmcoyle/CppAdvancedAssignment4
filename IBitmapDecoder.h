#pragma once
#include <memory>
#include <iostream>
#include <string>

namespace BitmapGraphics
{	
	class IBitmapDecoder
	{
	public:
		IBitmapDecoder() = default;

		virtual ~IBitmapDecoder() {};

		virtual HBitmapDecoder clone(std::string const& firstChunk, std::istream& sourceStream) = 0;
		virtual HBitmapIterator createIterator(std::istream& sourceStream) = 0;
		virtual std::string getMimeType() = 0;
		virtual bool isSupported(std::string header) = 0;
	};
}