#include "WindowsBitmapDecoder.h"

namespace BitmapGraphics
{

	const std::string WindowsBitmapDecoder::mimeType = "image/x-ms-bmp";
	
	HBitmapDecoder WindowsBitmapDecoder::clone(std::istream& sourceStream)
	{
		return std::make_shared<WindowsBitmapDecoder>();
	}

	HBitmapIterator WindowsBitmapDecoder::createIterator()
	{
		return HBitmap->createIterator();
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

}