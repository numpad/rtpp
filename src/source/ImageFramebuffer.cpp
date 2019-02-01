#include "ImageFramebuffer.hpp"

ImageFramebuffer::ImageFramebuffer(int w, int h)
	: width(w), height(h)
{
	this->pixels = (unsigned char *)malloc(w * h * 3 * sizeof(unsigned char));
}

ImageFramebuffer::~ImageFramebuffer() {
	free(this->pixels);
}

int ImageFramebuffer::get_width() {
	return this->width;
}

int ImageFramebuffer::get_height() {
	return this->height;
}

void ImageFramebuffer::set_pixel(int x, int y, unsigned char r, unsigned char g, unsigned char b) {
	if (x < 0 || y < 0 || x >= this->width  || y >= this->height)
		return;
	
	this->pixels[(x + y * this->width) * 3 + 0] = r;
	this->pixels[(x + y * this->width) * 3 + 1] = g;
	this->pixels[(x + y * this->width) * 3 + 2] = b;
}

void ImageFramebuffer::save(std::string filename) {
	stbi_write_png(filename.c_str(),
		this->width, this->height, 3,
		this->pixels,
		this->width * 3 * sizeof(unsigned char)
	);
}
