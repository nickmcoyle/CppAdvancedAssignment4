#pragma once

#include "IBitmapEncoder.h"
#include "IBitmapDecoder.h"
#include "BitmapIterator.h"
#include "Bitmap.h"
#include <map>
#include <list>

namespace BitmapGraphics
{
	class CodecLibrary
	{
	public:
		static CodecLibrary& getInstance();

	private:		
		using BitmapDecoderCollection = std::map<std::string, HBitmapDecoder>;	
		using BitmapEncoderCollection = std::map<std::string, HBitmapEncoder>;

		CodecLibrary() :
		myDecoders(),
		myEncoders()
		{		
		};

		~CodecLibrary() = default;

		CodecLibrary(const CodecLibrary&) = delete; //prevent copy constructor
		CodecLibrary& operator= (const CodecLibrary) = delete; //prevent copy assignment
		CodecLibrary(CodecLibrary&&) = delete; //prevent move constructor
		CodecLibrary& operator=(CodecLibrary&&) = delete; //prevent move assignment		
		

	public:		
		void registerEncoder(HBitmapEncoder const& encoder);
		void registerDecoder(HBitmapDecoder const& decoder);

		// provide a mime type version and an
		// auto determination version of createDecoder
		HBitmapDecoder createDecoder(std::istream& sourceStream);
		HBitmapDecoder createDecoder(std::string const& mimeType, std::istream& sourceStream);

		HBitmapEncoder createEncoder(std::string const& mimeType, HBitmapIterator const& bitmapIterator);

	private:
		BitmapDecoderCollection myDecoders;
		BitmapEncoderCollection myEncoders;
	};
}