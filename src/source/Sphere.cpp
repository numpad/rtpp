#include "Sphere.hpp"

#define RAND_FLOAT ((float)rand() / (float)RAND_MAX)
#define RAND_MIX(r) ((RAND_FLOAT + r) * 0.5f)

Sphere::Sphere(Vec3 p, float r)
	: material(Material()), pos(p), radius(r)
{
	this->material.set_diffuse(
		Vec3(RAND_MIX(1.0f), RAND_MIX(1.0f), RAND_MIX(1.0f))
	);
}

RayHit Sphere::intersects(const Ray &ray) {
	/* from ray origin to sphere */
	Vec3 vpc = Vec3::normal(this->pos - ray.pos);
	
	/* ray can intersect with sphere as it is in front of it */
	if (Vec3::dot(ray.dir, vpc) > 0.0f) {
		Vec3 pc = ray.project_point(this->pos);
		
		float dist = fabsf(Vec3::length(pc - this->pos));
		if (dist > this->radius) {
			// no intersection
			return RayHit();
		} else if (dist == this->radius) {
			// one intersection
			return RayHit(pc, Vec3::normal(pc - this->pos), (Collider *)this);
		} else {
			// two intersections
			float pci = sqrtf(this->radius * this->radius - dist * dist);
			Vec3 pos0 = (pc + (ray.dir * pci));
			Vec3 pos1 = (pc - (ray.dir * pci));
			
			Vec3 n0 = Vec3::normal(pos0 - this->pos);
			Vec3 n1 = Vec3::normal(pos1 - this->pos);
			
			/* sort by distance */
			float lp0 = Vec3::length(pos0 - ray.pos);
			float lp1 = Vec3::length(pos1 - ray.pos);
			
			if (lp0 > lp1) {
				return RayHit(pos1, n1, (Collider *)this);
			}
			
			return RayHit(pos0, n0, (Collider *)this);
		}
	} else {
		// behind the ray
		return RayHit();
	}

	return RayHit();
}

Material Sphere::get_material() {
	return this->material;
}
