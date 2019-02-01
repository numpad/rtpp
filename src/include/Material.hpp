#ifndef MATERIAL_HPP
#define MATERIAL_HPP

#include "Vec3.hpp"

class Material {
	Vec3 diffuse;
	
public:
	
	Material();
	Material(float r, float g, float b);
	Material(Vec3 color);
	
	void set_diffuse(Vec3 color);
	Vec3 get_diffuse() const;
	
};

#endif
