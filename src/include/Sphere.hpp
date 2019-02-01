#ifndef SPHERE_HPP
#define SPHERE_HPP
#include <stdio.h>
#include "Collidable.hpp"

class Sphere : public Collidable {

public:
	Vec3 pos;
	float radius;
	
	Sphere(Vec3 p, float r);
	
	RayHit intersects(const Ray &ray);
};

#endif
