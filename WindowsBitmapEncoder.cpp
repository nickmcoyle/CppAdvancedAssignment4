#include "WindowsBitmapEncoder.h"

WindowsBitmapEncoder::WindowsBitmapEncoder()
{	
}

WindowsBitmapEncoder::~WindowsBitmapEncoder()
{
}

HBitmapEncoder WindowsBitmapEncoder::clone(const HBitmapIterator& bitmapIterator)
{
	return HBitmapEncoder();
}

std::ostream WindowsBitmapEncoder::encodeToStream(HBitmapIterator)
{
}

std::string WindowsBitmapEncoder::getMimeType()
{
	return mimeType;
}