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
		
		virtual void nextScanLine() override; 
		virtual bool isEndOfImage() const override; //tests whether we have advanced beyond the last element (scanline in the bitmap) i.e. finished with the traversal
		virtual void nextPixel() override; 
		virtual bool isEndOfScanLine() const override; //tests whether we have advanced beyond the last element (pixel in the scanline) i.e. finished with the traversal

		virtual Color getColor() const override; //returns the color of the current pixel

		int getNumberOfPadBytes() const;

		virtual int getBitmapWidth() const override;
		virtual int getBitmapHeight() const override;	
		
	private:		
		int bitmapWidth;
		int bitmapHeight;

		Bitmap::ScanLineIterator scanLineIterator;
		Bitmap::ScanLineIterator scanLineEnd;
		Bitmap::ScanLine::const_iterator pixelIterator;
	};	
}