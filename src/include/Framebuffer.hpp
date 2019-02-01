#ifndef FRAMEBUFFER_HPP
#define FRAMEBUFFER_HPP

#include <math.h>
#include "Vec3.hpp"
#define CLAMP_F(v) (fmaxf(0.0f, fminf(v, 1.0f)))


class Framebuffer {
public:
	virtual void set_pixel(int x, int y, unsigned char r, unsigned char g, unsigned char b) =0;
	
};

#endif
