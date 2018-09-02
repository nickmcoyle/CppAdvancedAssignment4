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
		BrightnessDecorator(const BrightnessDecorator&) = default;
		BrightnessDecorator(BrightnessDecorator&&) = default;
		BrightnessDecorator& operator=(const BrightnessDecorator&) = default;
		BrightnessDecorator& operator=(BrightnessDecorator&&) = default;
		~BrightnessDecorator() = default;

		BrightnessDecorator(HBitmapIterator iterator, int brightnessAdjustment) :
		BitmapIteratorDecorator(iterator),
		brightnessAdjustment(brightnessAdjustment)
		{
		};
		
		void setBrightnessAdjustment(int brightnessAdjustment) 
		{
			if (brightnessAdjustment > 255 || brightnessAdjustment < 0)
			{
				throw std::runtime_error("BrightnessAdjustment must be between 0 and 255");
			}
			this->brightnessAdjustment = brightnessAdjustment;
		};

		int getBrightnessAdjustment() const 
		{
			return this->brightnessAdjustment;
		};

		virtual Color getColor() const override 
		{
			Color const oldColor = originalIterator->getColor();
			
			ColorComponent const red = static_cast<int>(oldColor.getRed()) + brightnessAdjustment;
			ColorComponent const green = static_cast<int>(oldColor.getGreen()) + brightnessAdjustment;
			ColorComponent const blue = static_cast<int>(oldColor.getBlue()) + brightnessAdjustment;
						
			return Color(red.getByte(), green.getByte(), blue.getByte());
		};
				
	private:		
		int brightnessAdjustment;
	};
}