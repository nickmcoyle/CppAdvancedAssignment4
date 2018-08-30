#pragma once

#include "BitmapIteratorDecorator.h"
#include "Bitmap.h"
#include "ranged_number.h"
#include "Color.h"

namespace BitmapGraphics
{

	class PosterizeDecorator : public BitmapIteratorDecorator
	{
	public:
		PosterizeDecorator() = default;

		const Binary::Byte& posterizeColor(const Binary::Byte& color) const
		{
			if (color < 64)
			{
				return Binary::Byte(31);
			}

			if (color > 63 && color < 128)
			{
				return Binary::Byte(95);
			}

			if (color > 127 && color < 192)
			{
				return Binary::Byte(159);
			}

			if (color > 191 && color < 256)
			{
				return Binary::Byte(223);
			}
			return color;
		}

		Color getColor() const {
			Color const oldColor = originalIterator->getColor();
			
			Binary::Byte const red = posterizeColor(oldColor.getRed());
			Binary::Byte const green = posterizeColor(oldColor.getGreen());
			Binary::Byte const blue = posterizeColor(oldColor.getBlue());			

			return Color(red, green, blue);
		}	
	};
}