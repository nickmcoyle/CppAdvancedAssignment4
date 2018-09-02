#pragma once

#include <memory>
#include <istream>
#include <iostream>
#include <string>

namespace BitmapGraphics
{	
	class IBitmapDecoder;
	using HBitmapDecoder = std::shared_ptr<IBitmapDecoder>;

	class IBitmapDecoder
	{
	public:
		IBitmapDecoder() = default;

		virtual ~IBitmapDecoder() {};

		virtual HBitmapDecoder clone(std::istream& sourceStream) = 0;
		//virtual HBitmapIterator createIterator(std::istream& sourceStream) = 0;
		virtual HBitmapIterator createIterator() = 0;
		virtual std::string getMimeType() = 0;
		virtual bool isSupported(std::string header) = 0;	
	};
}