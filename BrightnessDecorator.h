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
			if (brightnessAdjustment > 255 || brightnessAdjustment < 0)
			{
				throw std::runtime_error("BrightnessAdjustment must be between 0 and 255");
			}
			this->brightnessAdjustment = brightnessAdjustment;
		}

		int getBrightnessAdjustment() const {
			return this->brightnessAdjustment;
		}

		Color getColor() const {
			Color const oldColor = originalIterator->getColor();
			
			ColorComponent const red = static_cast<int>(oldColor.getRed()) + brightnessAdjustment;
			ColorComponent const green = static_cast<int>(oldColor.getGreen()) + brightnessAdjustment;
			ColorComponent const blue = static_cast<int>(oldColor.getBlue()) + brightnessAdjustment;
						
			return Color(red.getByte(), green.getByte(), blue.getByte());
		}

	private:		
		int brightnessAdjustment = 0;
	};
}