#include "BitmapIterator.h"

namespace BitmapGraphics
{
	BitmapIterator::BitmapIterator(const Bitmap& myBitmap) :
		myBitmap(myBitmap),
		indexScanLine(0),
		indexPixel(0)
	{
	}

	void BitmapIterator::nextScanLine()
	{
		indexScanLine++;
		indexPixel = 0;
	}

	bool BitmapIterator::isEndOfImage() const
	{
		if (indexScanLine > this->getBitmapHeight())
		{
			return true;
		}
		return false;
	}

	void BitmapIterator::nextPixel()
	{
		indexPixel++;
	}

	bool BitmapIterator::isEndOfScanLine() const
	{
		if (indexPixel > this->getBitmapWidth())
		{
			return true;
		}
		return false;
	}

	Color BitmapIterator::getColor() const
	{
		if(isEndOfScanLine)
		{
			throw std::runtime_error("Request to get color reached end of ScanLine");
		}
		if (isEndOfImage)
		{
			throw std::runtime_error("Request to get color reached end image");
		}
		
		return myBitmap.getPixel(indexScanLine, indexPixel);
	}

	int BitmapIterator::getBitmapWidth() const
	{
		return myBitmap.getWidth();
	}

	int BitmapIterator::getBitmapHeight() const
	{
		return myBitmap.getHeight();
	}

}