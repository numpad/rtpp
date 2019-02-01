#ifndef COLLIDABLE_HPP
#define COLLIDABLE_HPP

#include "Ray.hpp"
#include "Material.hpp"

class Collidable {

public:
	virtual ~Collidable();
	virtual RayHit intersects(const Ray &ray) =0;
	virtual Material get_material() =0;
};

#endif
