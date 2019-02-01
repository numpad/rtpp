#ifndef SPHERE_HPP
#define SPHERE_HPP
#include <stdio.h>                                                                                                                 
#include <math.h>
#include "Collidable.hpp"
#include "Material.hpp"

class Sphere : public Collidable {
	Material material;
	
public:
	Vec3 pos;
	float radius;
	
	Sphere(Vec3 p, float r);
	
	RayHit intersects(const Ray &ray);
	Material get_material();
	
};

#endif
