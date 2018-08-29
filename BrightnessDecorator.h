#pragma once

#include "BitmapIteratorDecorator.h"
#include "Bitmap.h"
#include "ranged_number.h"
#include "Color.h"

namespace BitmapGraphics
{
	class BrightnessDecorator : public BitmapIteratorDecorator
	{
	public:
		BrightnessDecorator(HBitmapIterator const& originalIterator)
			: originalIterator(originalIterator), brightnessAdjustment(0) 
		{
		}

		void setBrightnessAdjustment(int brightnessAdjustment) {
			this->brightnessAdjustment = brightnessAdjustment;
		}

		int getBrightnessAdjustment() const {
			return this->brightnessAdjustment;
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
			
			ColorComponent const red = oldColor.getRed() + brightnessAdjustment;
			ColorComponent const green = oldColor.getGreen() + brightnessAdjustment;
			ColorComponent const blue = oldColor.getBlue() + brightnessAdjustment;

			return Color(red, green, blue);
		}

	private:
		using ColorComponent = ranged_number <int, 0, 255>;		
		HBitmapIterator originalIterator;
		Binary::Byte brightnessAdjustment;
	};
}