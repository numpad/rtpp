#ifndef RAY_HPP
#define RAY_HPP

#include <float.h>
#include <vector>
#include "Vec3.hpp"
#include "RayHit.hpp"

class Collidable;

class Ray {
	
public:
	Vec3 project_point(const Vec3 point) const;
	
	const Vec3 pos, dir;
	
	Ray(Vec3 pos, Vec3 dir);
	
	RayHit intersect(std::vector<Collidable *> colliders);
};

#endif
