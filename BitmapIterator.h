#pragma once

#include "IBitmapIterator.h"
#include "Bitmap.h"
#include "Color.h"
#include <memory>

namespace BitmapGraphics
{	
	using HBitmapIterator = std::shared_ptr<BitmapIterator(const Bitmap&)>;
	
	//we define an abstract IBitmapIterator interface that provides a common interface for iterating bitmaps. Then, we can define concrete iterator subclasses for the different implementations 	
	class BitmapIterator : public IBitmapIterator
	{	
	public:
		BitmapIterator(const Bitmap& myBitmap);	

		BitmapIterator(const BitmapIterator& other) = default;
		BitmapIterator(BitmapIterator&& other) = default;
		BitmapIterator& operator =(const BitmapIterator& other) = default;
		BitmapIterator& operator =(BitmapIterator&& other) = default;

		~BitmapIterator() = default;

		void nextScanLine(); //advances the current element (scanline) to the next element
		bool isEndOfImage() const; //tests whether we have advanced beyond the last element (scanline) i.e. finished with the traversal
		void nextPixel(); //advances the current element (pixel) to the next element
		bool isEndOfScanLine() const; //tests whether we have advanced beyond the last element (pixel) i.e. finished with the traversal

		Color getColor() const; //returns the color of the current pixel

		int getBitmapWidth() const;
		int getBitmapHeight() const;
		
	private:		
		const Bitmap& myBitmap;

		int indexScanLine;
		int indexPixel;
	};	
}