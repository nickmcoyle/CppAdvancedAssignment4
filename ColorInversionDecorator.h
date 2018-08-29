#pragma once

#include "BitmapIteratorDecorator.h"
#include "Bitmap.h"
#include "ranged_number.h"
#include "Color.h"

namespace BitmapGraphics
{

	class ColorInversionDecorator : public BitmapIteratorDecorator
	{
	public:
		ColorInversionDecorator(HBitmapIterator const& originalIterator)
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

			ColorComponent const red = 255 - oldColor.getRed();
			ColorComponent const green = 255 - oldColor.getGreen();
			ColorComponent const blue = 255 - oldColor.getBlue();

			return Color(red, green, blue);
		}

	private:
		using ColorComponent = ranged_number <int, 0, 255>;
		HBitmapIterator originalIterator;		
	};
}