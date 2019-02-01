#include "RayHit.hpp"

RayHit::RayHit()
	: object(nullptr), p(Vec3()), n(Vec3()), hit(false)
{
	
}

RayHit::RayHit(Vec3 p, Vec3 n, Collider *object)
	: object(object), p(p), n(n), hit(true)
{
	
}

Collider *RayHit::get_collider() {
	return this->object;
}
