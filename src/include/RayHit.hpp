#ifndef RAYHIT_HPP
#define RAYHIT_HPP

#include "Vec3.hpp"

class Collider;

class RayHit {
	Collider *object;
	
public:
	
	Vec3 p;
	Vec3 n;
	bool hit = false;
	
	RayHit();
	RayHit(Vec3 pos, Vec3 normal, Collider *object);
	
	Collider *get_collider();
};

#endif
