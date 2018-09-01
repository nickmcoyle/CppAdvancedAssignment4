#pragma once

#include "IBitmapIterator.h"
#include "Color.h"
#include <memory>

namespace BitmapGraphics
{	
	using HBitmapIterator = std::shared_ptr<IBitmapIterator>;	
	using PixelIterator = Bitmap::ScanLine::const_iterator;	
	
	class BitmapIterator : public IBitmapIterator
	{	
	public:
		BitmapIterator() = default;
		BitmapIterator(Bitmap& myBitmap);	

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

		int getNumberOfPadBytes() const;
		
	private:		
		Bitmap& myBitmap;
		Bitmap::ScanLineIterator scanLineCollectionIterator;
		PixelIterator pixelIterator;		
	};	
}