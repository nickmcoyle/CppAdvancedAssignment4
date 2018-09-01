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
	
	std::ostream& WindowsBitmapEncoder::encodeToStream(HBitmapIterator& bitmapIter)
	{
		std::ostream destinationStream(NULL);
		
		while (!bitmapIter->isEndOfImage())
		{
			//write pixels
			while (!bitmapIter->isEndOfScanLine())
			{
				destinationStream << bitmapIter->getColor();
			}

			//write pad bytes
			for (auto pad = 0; pad < bitmapIter->getNumberOfPadBytes(); ++pad)
			{
				Binary::Byte(0).write(destinationStream);
			}
			bitmapIter->nextScanLine();
		}
		
		return destinationStream;
	}

	void WindowsBitmapEncoder::encodeToStream(const std::ofstream& stream)
	{			
		//I dont know what to do here
		stream;
	}

	std::string WindowsBitmapEncoder::getMimeType()
	{
		return mimeType;
	}

}