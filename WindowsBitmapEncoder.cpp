#include "WindowsBitmapEncoder.h"

namespace BitmapGraphics
{

	WindowsBitmapEncoder::WindowsBitmapEncoder()		
	{
	}

	WindowsBitmapEncoder::~WindowsBitmapEncoder()
	{
	}

	HBitmapEncoder WindowsBitmapEncoder::clone(const HBitmapIterator& bitmapIterator)
	{
		myEncoder = CodecLibrary::getInstance().createEncoder(mimeType, bitmapIterator);
		return myEncoder;
	}

	std::ostream WindowsBitmapEncoder::encodeToStream(HBitmapIterator& bitmapIter)
	{
		std::ostream destinationStream(NULL);
		/*
		while (!isEndofImage)
		{
			//write pixels
			While(!isEndofScanLine)
			{
				std::copy(getColor());
			}

			//write pad bytes
			for (auto pad = 0; pad < alignmentValue; ++pad)
			{
				Binary::Byte(0).write(destinationStream);
			}
			nextScanLine();
		}
		*/
		//return destinationStream;
	}

	std::string WindowsBitmapEncoder::getMimeType()
	{
		return mimeType;
	}

}