#ifndef SCENE_HPP
#define SCENE_HPP

#include <vector>
#include "Vec3.hpp"
#include "Collidable.hpp"
#include "Ray.hpp"
#include "RayHit.hpp"

class Scene {
	
	std::vector<Collidable *> objects;
	
public:
	
	Scene();
	~Scene();
	
	void add(Collidable *object);
	RayHit cast(const Ray &ray);
};

#endif
