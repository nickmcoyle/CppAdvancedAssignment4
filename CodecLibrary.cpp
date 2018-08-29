#include "CodecLibrary.h"

namespace BitmapGraphics
{

	CodecLibrary& CodecLibrary::getInstance()
	{
		static CodecLibrary codecLibrary; //use C++ 11 magic statics
		return codecLibrary;
	}

	void CodecLibrary::registerEncoder(HBitmapEncoder const& encoder)
	{
		myEncoders.push_back(encoder);
	}

	void CodecLibrary::registerDecoder(HBitmapDecoder const& decoder)
	{
		myDecoders.push_back(decoder);
	}

	HBitmapDecoder CodecLibrary::createDecoder(std::istream& sourceStream)
	{
		//lookup decoder from the collection and return handle to it?
		if ()
		{

		}
		return HBitmapDecoder();
	}

	HBitmapDecoder CodecLibrary::createDecoder(std::string const& mimeType, std::istream& sourceStream)
	{
		std::string actualMimeType = "";
		//actualMimeType = something from source stream;
		if (mimeType != actualMimeType)
		{
			throw std::runtime_error{ "Error creating encoder, Mime type does not match the source file" };
		}
		//take first 100 bytes and determine the correct decoder to return
		return HBitmapDecoder();
	}

	HBitmapEncoder CodecLibrary::createEncoder(std::string const& mimeType, HBitmapIterator const& bitmapIterator)
	{
		//take first 100 bytes and determine the correct decoder to return
		return HBitmapEncoder();
	}

}