#pragma once

#include "WindowsBitmapEncoder.h"
#include "WindowsBitmapDecoder.h"
#include "BitmapIterator.h"
#include "Bitmap.h"
#include <list>

namespace BitmapGraphics
{
	using HBitmapDecoder = std::shared_ptr<IBitmapDecoder>;
	using HBitmapEncoder = std::shared_ptr<IBitmapEncoder>;

	class CodecLibrary
	{
	private:
		using BitmapEncoderCollection = std::list<HBitmapEncoder>;
		using BitmapDecoderCollection = std::list<HBitmapDecoder>;

	public:
		static CodecLibrary& getInstance();

		void registerEncoder(HBitmapEncoder const& encoder);
		void registerDecoder(HBitmapDecoder const& decoder);

		// provide a mime type version and an
		// auto determination version of createDecoder
		static HBitmapDecoder createDecoder(std::istream& sourceStream);
		static HBitmapDecoder createDecoder(std::string const& mimeType, std::istream& sourceStream);

		static HBitmapEncoder createEncoder(std::string const& mimeType, HBitmapIterator const& bitmapIterator);

	private:
		BitmapDecoderCollection myDecoders;
		BitmapEncoderCollection myEncoders;
	};
}