#include "Scene.hpp"

Scene::Scene() {
	
}

Scene::~Scene() {
	for (Collidable *c : this->objects)
		delete c;
}

void Scene::add(Collidable *object) {
	this->objects.push_back(object);
}

RayHit Scene::cast(const Ray &ray) {
	RayHit rayhit;
	float dist = FLT_MAX;
	
	for (Collidable *c : this->objects) {
		RayHit rh = c->intersects(ray);
		if (rh.hit) {
			float d = Vec3::length2(ray.pos - rh.p);
			if (d < dist) {
				dist = d;
				rayhit = rh;
			}
		}
	}
	
	return rayhit;
}
