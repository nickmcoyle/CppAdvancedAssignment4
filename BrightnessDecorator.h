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
						
			return Color(red.getByte(), green.getByte(), blue.getByte());
		}

	private:		
		uint8_t brightnessAdjustment = 0;
	};
}