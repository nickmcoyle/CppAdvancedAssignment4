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

			ColorComponent const red = Binary::Byte(255) - oldColor.getRed();
			ColorComponent const green = Binary::Byte(255) - oldColor.getGreen();
			ColorComponent const blue = Binary::Byte(255) - oldColor.getBlue();
			
			Color(red.getByte(), green.getByte(), blue.getByte());			
		}	
	};
}