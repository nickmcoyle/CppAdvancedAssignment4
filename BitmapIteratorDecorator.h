#pragma once

#include "IBitmapIterator.h"
#include "ranged_number.h"

namespace BitmapGraphics
{
	class BitmapIteratorDecorator : public IBitmapIterator
	{

	public:
		BitmapIteratorDecorator() = default;
		BitmapIteratorDecorator(const BitmapIteratorDecorator&) = default;
		BitmapIteratorDecorator(BitmapIteratorDecorator&&) = default;
		BitmapIteratorDecorator& operator=(const BitmapIteratorDecorator&) = default;
		BitmapIteratorDecorator& operator=(BitmapIteratorDecorator&&) = default;
		~BitmapIteratorDecorator() = default;
		
		BitmapIteratorDecorator(HBitmapIterator const& originalIterator) :
			originalIterator(originalIterator)
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

		virtual Color getColor() const override
		{
			return originalIterator->getColor();
		}

		virtual void setColor(const Color& color) override
		{
			originalIterator-> setColor(color);
		}

		virtual int getBitmapWidth() const override
		{
			return originalIterator->getBitmapWidth(); 
		};

		virtual int getBitmapHeight() const override
		{ 
			return originalIterator->getBitmapHeight(); 
		};
		
		virtual int getNumberOfPadBytes() const override
		{
			return originalIterator->getNumberOfPadBytes(); 
		};

	protected:			
		HBitmapIterator originalIterator;
		using ColorComponent = ranged_number <int, 0, 255>;
	};
}
