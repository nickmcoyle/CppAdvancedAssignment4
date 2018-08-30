#pragma once

#include "IBitmapIterator.h"

namespace BitmapGraphics
{
	class BitmapIteratorDecorator : public IBitmapIterator
	{
	public:
		BitmapIteratorDecorator(HBitmapIterator const& originalIterator)
			: originalIterator(originalIterator)
		{
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

		virtual Color getColor() const = 0;

	protected:		
		using ColorComponent = ranged_number <int, 0, 255>;
		HBitmapIterator originalIterator;				
	};
}
