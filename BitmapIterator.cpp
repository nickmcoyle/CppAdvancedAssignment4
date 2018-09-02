#include "BitmapIterator.h"

namespace BitmapGraphics
{	

	BitmapIterator::BitmapIterator(Bitmap& bitmap) :
		bitmapWidth(bitmap.getWidth()),
		bitmapHeight(bitmap.getHeight()),
		scanLineIterator(bitmap.begin()),
		scanLineEnd(bitmap.end()),
		pixelIterator(scanLineIterator->cbegin())
	{			
	}

	void BitmapIterator::nextScanLine()
	{
		scanLineIterator++;		
		pixelIterator = scanLineIterator->cbegin();
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
		pixelIterator++;
	}

	bool BitmapIterator::isEndOfScanLine() const
	{
		if (pixelIterator == scanLineIterator->cend())
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
		return (*pixelIterator);
	}

	int BitmapIterator::getNumberOfPadBytes() const
	{
		const auto remainder = (bitmapWidth * 3) % 4;
		return (remainder == 0) ? 0 : (4 - remainder);
	}

	int BitmapIterator::getBitmapWidth() const
	{
		return bitmapWidth;
	}

	int BitmapIterator::getBitmapHeight() const
	{
		return bitmapHeight;
	}	

}