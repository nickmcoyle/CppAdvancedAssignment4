#include "WindowsBitmapEncoder.h"

namespace BitmapGraphics
{	

	const std::string WindowsBitmapEncoder::mimeType = "image/x-ms-bmp";

	HBitmapEncoder WindowsBitmapEncoder::clone(const HBitmapIterator& bitmapIterator)
	{
		return std::make_shared<WindowsBitmapEncoder>();
	}
	
	std::ostream& WindowsBitmapEncoder::encodeToStream(HBitmapIterator& bitmapIter)
	{
		std::ostream destinationStream(NULL);
		
		//make header
		WindowsBitmapHeader().writeFileHeader(destinationStream);
		
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