#include "WindowsBitmapDecoder.h"

namespace BitmapGraphics
{

	WindowsBitmapDecoder::WindowsBitmapDecoder(const Bitmap& bitmap)
		:myBitmap(bitmap)
	{
	}

	WindowsBitmapDecoder::~WindowsBitmapDecoder()
	{
	}

	HBitmapDecoder WindowsBitmapDecoder::clone(std::string const& firstChunk, std::istream& sourceStream)
	{
		//per design patterns book invoke copy constructor?
		CodecLibrary::createDecoder(sourceStream);
	}

	HBitmapIterator WindowsBitmapDecoder::createIterator(std::istream& sourceStream)
	{
		return myBitmap.createIterator(sourceStream);
	}

	std::string WindowsBitmapDecoder::getMimeType()
	{
		return mimeType;
	}

	bool WindowsBitmapDecoder::isSupported(std::string header)
	{
		if (header[0] == 'B' && header[1] == 'M')
		{
			return true;
		}
		return false;
	}

	const Binary::Byte& WindowsBitmapDecoder::getNextByte(std::stringstream ss)
	{
		return Binary::Byte(ss.get());
	}

}