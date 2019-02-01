#include "Ray.hpp"

#include "Collidable.hpp"

Ray::Ray(Vec3 p, Vec3 d)
	: pos(p), dir(d.normal())
{
	
}

Vec3 Ray::project_point(const Vec3 point) const {
	Vec3 u = point - this->pos;
	Vec3 puv = this->dir * Vec3::dot(this->dir, u) / this->dir.length();
	
	return this->pos + puv;
}

RayHit Ray::intersect(std::vector<Collidable *> colliders) {
	RayHit rayhit;
	float dist = FLT_MAX;
	
	for (Collidable *c : colliders) {
		RayHit rh = c->intersects(*this);
		if (rh.hit) {
			float d = Vec3::length2(this->pos - rh.p);
			if (d < dist) {
				dist = d;
				rayhit = rh;
			}
		}
	}
	
	return rayhit;
}
