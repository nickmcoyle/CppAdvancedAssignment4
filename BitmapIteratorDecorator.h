#pragma once

#include "IBitmapIterator.h"
#include "ranged_number.h"

namespace BitmapGraphics
{
	class BitmapIteratorDecorator : public IBitmapIterator
	{
	public:
		BitmapIteratorDecorator(HBitmapIterator const& originalIterator)
			: originalIterator(originalIterator)
		{
		}		

		virtual void nextScanLine() override
		{
			originalIterator->nextScanLine();
		}

		virtual bool isEndOfImage() const override
		{
			return originalIterator->isEndOfImage();
		}

		virtual void nextPixel() override
		{
			originalIterator->nextPixel();
		}

		virtual bool isEndOfScanLine() const override
		{
			return originalIterator->isEndOfScanLine();
		}

		virtual Color getColor() const = 0;

		virtual int getBitmapWidth() const { return originalIterator->getBitmapWidth(); };
		virtual int getBitmapHeight() const { return originalIterator->getBitmapHeight(); };
		virtual int getNumberOfPadBytes() const { return originalIterator->getNumberOfPadBytes(); };

	protected:			
		HBitmapIterator originalIterator;	
		using ColorComponent = ranged_number <int, 0, 255>;
	};
}
