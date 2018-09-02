#include "WindowsBitmapDecoder.h"

namespace BitmapGraphics
{
	HBitmapDecoder WindowsBitmapDecoder::clone(std::istream& sourceStream)
	{
		return std::make_shared<WindowsBitmapDecoder>();
	}

	HBitmapIterator WindowsBitmapDecoder::createIterator()
	{
		return HBitmap->createIterator();
	}

	/*HBitmapIterator WindowsBitmapDecoder::createIterator(std::istream& sourceStream)
	{
		return bitmap.createIterator(sourceStream);
	}*/	

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
/*
	const Binary::Byte& WindowsBitmapDecoder::getNextByte(std::stringstream ss)
	{
		return Binary::Byte(ss.get());
	}
*/
}