#include "BitmapIterator.h"

namespace BitmapGraphics
{
	BitmapIterator::BitmapIterator() :
		myBitmap(Bitmap(0,0)),
		scanLineCollectionIterator(myBitmap.begin()),
		pixelIterator((*scanLineCollectionIterator).cbegin())
	{

	}
	BitmapIterator::BitmapIterator(Bitmap& myBitmap) :
		myBitmap(myBitmap),
		scanLineCollectionIterator(myBitmap.begin()),
		pixelIterator((*scanLineCollectionIterator).cbegin())
	{			
	}

	void BitmapIterator::nextScanLine()
	{
		scanLineCollectionIterator++;
		//reset pixelIterator
		pixelIterator = (*scanLineCollectionIterator).cbegin();		
	}

	bool BitmapIterator::isEndOfImage() const
	{
		if (scanLineCollectionIterator == myBitmap.end())
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
		if (pixelIterator == (*scanLineCollectionIterator).cend())
		{
			return true;
		}
		return false;
	}

	Color BitmapIterator::getColor() const
	{		
		if (isEndOfImage)
		{
			throw std::out_of_range("Request to get color reached end of bitmap");
		}
		return (*pixelIterator);
	}

	int BitmapIterator::getBitmapWidth() const
	{
		return myBitmap.getWidth();
	}

	int BitmapIterator::getBitmapHeight() const
	{
		return myBitmap.getHeight();
	}
	
	int BitmapIterator::getNumberOfPadBytes() const
	{		
		return myBitmap.getNumberOfPadBytes();
	}

}