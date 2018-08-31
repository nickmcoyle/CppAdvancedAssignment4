#include "WindowsBitmapDecoder.h"

namespace BitmapGraphics
{
	
	WindowsBitmapDecoder::WindowsBitmapDecoder()
		:myBitmap(Bitmap(0,0)),
		myDecoder(this)
	{
		CodecLibrary::getInstance().registerDecoder(myDecoder);
	}

	WindowsBitmapDecoder::WindowsBitmapDecoder(const Bitmap& bitmap)
		:myBitmap(bitmap),
		myDecoder(this)
	{		
		CodecLibrary::getInstance().registerDecoder(myDecoder);
	}

	WindowsBitmapDecoder::~WindowsBitmapDecoder()
	{
	}

	HBitmapDecoder WindowsBitmapDecoder::clone(std::string const& firstChunk, std::istream& sourceStream)
	{				
		myDecoder = CodecLibrary::getInstance().createDecoder(sourceStream);
		return myDecoder;
	}

	HBitmapDecoder WindowsBitmapDecoder::clone(std::istream& sourceStream)
	{
		myDecoder = CodecLibrary::getInstance().createDecoder(sourceStream);
		return myDecoder;
	}

	HBitmapIterator WindowsBitmapDecoder::createIterator()
	{
		return myBitmap.createIterator();
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