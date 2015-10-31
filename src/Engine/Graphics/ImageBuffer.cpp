
#include "Engine/Graphics/ImageBuffer.hpp"

ImageBuffer::ImageBuffer(size_t width, size_t height) :
	width(width),
	height(height),
	size(width * height * sizeof(int))
{
	data = new int[width * height];
}

ImageBuffer::~ImageBuffer()
{
	cleanUp();
}

void	ImageBuffer::cleanUp()
{
	width = 0;
	height = 0;
	size = 0;
	delete[] data;
}
