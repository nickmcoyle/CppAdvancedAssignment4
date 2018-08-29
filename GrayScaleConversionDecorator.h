#pragma once

#include "BitmapIteratorDecorator.h"
#include "Bitmap.h"
#include "ranged_number.h"
#include "Color.h"

namespace BitmapGraphics
{

	class GrayScaleConversionDecorator : public BitmapIteratorDecorator
	{
	public:
		GrayScaleConversionDecorator(HBitmapIterator const& originalIterator)
			: originalIterator(originalIterator)
		{
		}				

		void nextScanLine() {
			originalIterator->nextScanLine();
		}

		bool isEndOfImage() const {
			return originalIterator->isEndOfImage();
		}

		void nextPixel() {
			originalIterator->nextPixel();
		}

		bool isEndOfScanLine() const {
			return originalIterator->isEndOfScanLine();
		}

		Color getColor() const {
			Color const oldColor = originalIterator->getColor();
			//average all the values, similar to what GIMP uses to convert color images to grayscale
			Binary::Byte const grayScale = ((oldColor.getRed() + oldColor.getBlue() + oldColor.getGreen()) / 3);

			return Color(grayScale, grayScale, grayScale);
		}

	private:		
		HBitmapIterator originalIterator;		
	};
}