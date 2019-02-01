#include "Framebuffer.hpp"

Framebuffer::Framebuffer(int w, int h)
	: width(w), height(h)
{
	
}

int Framebuffer::get_width() const {
	return this->width;
}

int Framebuffer::get_height() const {
	return this->height;
}
