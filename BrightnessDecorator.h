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
			ColorComponent const red = ColorComponent(1) + ColorComponent(brightnessAdjustment);

			Color const red = ColorComponent(static_cast<int>(oldColor.getRed())) + ColorComponent(brightnessAdjustment);
			Color const green = oldColor.getGreen() +	brightnessAdjustment;
			Color const blue = oldColor.getBlue() + brightnessAdjustment;

			return Color(red, green, blue);
		}

	private:
		using ColorComponent = ranged_number <int, 0, 255>;		
		HBitmapIterator originalIterator;
		int brightnessAdjustment;
	};
}