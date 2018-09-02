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
		ColorInversionDecorator() = default;		
		ColorInversionDecorator(const ColorInversionDecorator&) = default;
		ColorInversionDecorator(ColorInversionDecorator&&) = default;
		ColorInversionDecorator& operator=(const ColorInversionDecorator&) = default;
		ColorInversionDecorator& operator=(ColorInversionDecorator&&) = default;
		~ColorInversionDecorator() = default;

		ColorInversionDecorator(HBitmapIterator iterator) :
			BitmapIteratorDecorator(iterator)			
		{
		};

		Color getColor() const override
		{
			Color const oldColor = originalIterator->getColor();			

			ColorComponent const red = 255 - static_cast<int>(oldColor.getRed());
			ColorComponent const green = 255 - static_cast<int>(oldColor.getGreen());
			ColorComponent const blue = 255 - static_cast<int>(oldColor.getBlue());
			
			return Color(red.getByte(), green.getByte(), blue.getByte());			
		}		
	};
}