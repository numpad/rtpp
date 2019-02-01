#ifndef COLLIDABLE_HPP
#define COLLIDABLE_HPP

#include "Ray.hpp"

class Collidable {

public:
	virtual ~Collidable();
	virtual RayHit intersects(const Ray &ray) =0;
	
};

#endif
