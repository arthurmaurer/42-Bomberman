
#ifndef _IMAGE_BUFFER_HPP
# define _IMAGE_BUFFER_HPP

# include <cstdlib>

class ImageBuffer
{
public:
	int *	data = NULL;
	size_t	width = 0;
	size_t	height = 0;
	size_t	size = 0;

	ImageBuffer(size_t width, size_t height);
	~ImageBuffer();

	void	cleanUp();
};

#endif /* _IMAGE_BUFFER_HPP */