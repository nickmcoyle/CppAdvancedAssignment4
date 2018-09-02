#include "BitmapIterator.h"

namespace BitmapGraphics
{	

	BitmapIterator::BitmapIterator(Bitmap& bitmap) :
		bitmapWidth(bitmap.getWidth()),
		bitmapHeight(bitmap.getHeight()),
		scanLineIterator(bitmap.begin()),
		scanLineEnd(bitmap.end()),
		colorIterator(scanLineIterator->cbegin())
	{			
	}

	void BitmapIterator::nextScanLine()
	{
		scanLineIterator++;
		//reset pixelIterator
		colorIterator = scanLineIterator->cbegin();
	}

	bool BitmapIterator::isEndOfImage() const
	{
		if (scanLineIterator == scanLineEnd)
		{
			return true;
		}
		return false;
	}

	void BitmapIterator::nextPixel()
	{
		colorIterator++;
	}

	bool BitmapIterator::isEndOfScanLine() const
	{
		if (colorIterator == scanLineIterator->cend())
		{
			return true;
		}
		return false;
	}

	Color BitmapIterator::getColor() const
	{		
		if (isEndOfImage())
		{
			throw std::out_of_range("Request to get color reached end of bitmap");
		}
		return (*colorIterator);
	}

	int BitmapIterator::getBitmapWidth() const
	{
		return bitmapWidth;
	}

	int BitmapIterator::getBitmapHeight() const
	{
		return bitmapHeight;
	}
	
	/*int BitmapIterator::getNumberOfPadBytes() const
	{		
		return bitmap->getNumberOfPadBytes();
	}*/

}