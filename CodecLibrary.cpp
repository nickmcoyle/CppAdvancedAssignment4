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
		myEncoders.emplace(encoder->getMimeType(), encoder);
	}

	void CodecLibrary::registerDecoder(HBitmapDecoder const& decoder)
	{
		myDecoders.emplace(decoder->getMimeType(), decoder);
	}

	HBitmapDecoder CodecLibrary::createDecoder(std::istream& sourceStream)
	{
		//take first 100 bytes and determine the correct decoder to return
		std::istream_iterator<std::string> iter(sourceStream);
		std::string header;
		for (int i = 0; i < 100; ++i)
		{
			header += *iter++;
		}

		//std::string header(std::istreambuf_iterator<char>(sourceStream), {});
		sourceStream.seekg(std::ios_base::beg);
				
		//lookup decoder from the collection and return handle to it?
		for (const auto& decoder : myDecoders)
		if (decoder.second->isSupported(header))
		{			
			HBitmapDecoder instance = decoder.second;
			return instance;
		}

		throw std::runtime_error("No decoder available for this file type");
	}

	HBitmapDecoder CodecLibrary::createDecoder(std::string const& mimeType, std::istream& sourceStream)
	{
		//take first 100 bytes and determine the correct decoder to return
		std::istream_iterator<std::string> iter(sourceStream);
		std::string header;
		for (int i = 0; i < 100; ++i)
		{
			header += *iter++;
		}

		//std::string header(std::istreambuf_iterator<char>(sourceStream), {});
		sourceStream.seekg(std::ios_base::beg);

		if (!myDecoders[mimeType]->isSupported(header))
		{		
			throw std::runtime_error{ "Error creating decoder, Mime type does not match the source file" };
		}

		HBitmapDecoder instance = myDecoders[mimeType];
		return instance;
	}

	HBitmapEncoder CodecLibrary::createEncoder(std::string const& mimeType, HBitmapIterator const& bitmapIterator)
	{
		//lookup decoder from the collection and return handle to it?		
		if (myEncoders[mimeType] == nullptr)
		{
			throw std::runtime_error("No encoder available for this file type");
		}
			
		HBitmapEncoder instance = myEncoders[mimeType];
		return instance;
	}

}