#pragma once

#include "IBitmapIterator.h"
#include "Bitmap.h"
#include "Color.h"

namespace BitmapGraphics
{
	class BitmapIterator : public IBitmapIterator
	{	
	public:
		BitmapIterator() = default;
		BitmapIterator(Bitmap& bitmap);	

		BitmapIterator(const BitmapIterator& other) = default;
		BitmapIterator(BitmapIterator&& other) = default;
		BitmapIterator& operator =(const BitmapIterator& other) = default;
		BitmapIterator& operator =(BitmapIterator&& other) = default;

		~BitmapIterator() = default;
		
		void nextScanLine(); 
		bool isEndOfImage() const; //tests whether we have advanced beyond the last element (scanline in the bitmap) i.e. finished with the traversal
		void nextPixel(); 
		bool isEndOfScanLine() const; //tests whether we have advanced beyond the last element (pixel in the scanline) i.e. finished with the traversal

		Color getColor() const; //returns the color of the current pixel

		int getBitmapWidth() const;
		int getBitmapHeight() const;	

	//	int getNumberOfPadBytes() const;
		
	private:		
		int bitmapWidth;
		int bitmapHeight;

		Bitmap::ScanLineIterator scanLineIterator;
		Bitmap::ScanLineIterator scanLineEnd;
		Bitmap::ScanLine::const_iterator colorIterator;

	};	
}