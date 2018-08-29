#include "CodecLibrary.h"

namespace BitmapGraphics
{

	CodecLibrary& CodecLibrary::getInstance()
	{
		return this;
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
		return HBitmapDecoder();
	}

	HBitmapEncoder CodecLibrary::createEncoder(std::string const& mimeType, HBitmapIterator const& bitmapIterator)
	{
		return HBitmapEncoder();
	}

}