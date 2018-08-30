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
		BrightnessDecorator() = default;
		
		void setBrightnessAdjustment(int brightnessAdjustment) {
			this->brightnessAdjustment = brightnessAdjustment;
		}

		int getBrightnessAdjustment() const {
			return this->brightnessAdjustment;
		}

		Color getColor() const {
			Color const oldColor = originalIterator->getColor();
			
			ColorComponent const red = oldColor.getRed() + Binary::Byte(brightnessAdjustment);
			ColorComponent const green = oldColor.getGreen() + Binary::Byte(brightnessAdjustment);
			ColorComponent const blue = oldColor.getBlue() + Binary::Byte(brightnessAdjustment);

			const Binary::Byte byteRed(red.get());
			const Binary::Byte byteGreen(green.get());
			const Binary::Byte byteBlue(blue.get());

			return Color(byteRed, byteGreen, byteBlue);
		}

	private:		
		int brightnessAdjustment = 0;
	};
}