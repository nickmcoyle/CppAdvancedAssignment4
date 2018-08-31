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
		//take first 100 bytes and determine the correct decoder to return		
		std::string header(std::istreambuf_iterator<char>(sourceStream), {});
		sourceStream.seekg;
				
		//lookup decoder from the collection and return handle to it?
		for (const auto& decoder : myDecoders)
		if (decoder->isSupported(header))
		{
			return decoder->clone(header, sourceStream);
		}
		throw std::runtime_error("No decoder available for this file type");
	}

	HBitmapDecoder CodecLibrary::createDecoder(std::string const& mimeType, std::istream& sourceStream)
	{
		std::string actualMimeType = "";
		//actualMimeType = something from source stream;
		if (mimeType != actualMimeType)
		{
			throw std::runtime_error{ "Error creating decoder, Mime type does not match the source file" };
		}
		return createDecoder(sourceStream);
	}

	HBitmapEncoder CodecLibrary::createEncoder(std::string const& mimeType, HBitmapIterator const& bitmapIterator)
	{
		//lookup decoder from the collection and return handle to it?
		for (const auto& encoder : myEncoders)
			if (encoder->getMimeType() == mimeType)
			{
				return encoder->clone(bitmapIterator);
			}
		throw std::runtime_error("No encoder available for this file type");
	}

}