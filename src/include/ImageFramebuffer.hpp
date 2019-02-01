#ifndef IMAGE_FRAMEBUFFER_HPP
#define IMAGE_FRAMEBUFFER_HPP

#include <string>
#include <stdlib.h>
#include "Framebuffer.hpp"

#include <stb/stb_image_write.h>

class ImageFramebuffer : public Framebuffer {
	int width, height;
	
	unsigned char *pixels;
	
public:
	ImageFramebuffer(int width, int height);
	~ImageFramebuffer();
	
	int get_width();
	int get_height();
	
	void set_pixel(int x, int y, unsigned char r, unsigned char g, unsigned char b);
	
	void save(std::string filename);
};

#endif
