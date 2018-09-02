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

		Color getColor() const {
			Color const oldColor = originalIterator->getColor();			

			ColorComponent const red = 255 - static_cast<int>(oldColor.getRed());
			ColorComponent const green = 255 - static_cast<int>(oldColor.getGreen());
			ColorComponent const blue = 255 - static_cast<int>(oldColor.getBlue());
			
			Color(red.getByte(), green.getByte(), blue.getByte());			
		}	
	};
}