#include "Material.hpp"

Material::Material(float r, float g, float b)
	: diffuse(r, g, b)
{
	
}

Material::Material(Vec3 color)
	: Material(color.x, color.y, color.z)
{
	
}

Material::Material()
	: Material(0.0f, 0.0f, 0.0f)
{
	
}

void Material::set_diffuse(Vec3 color) {
	this->diffuse = color;
}

Vec3 Material::get_diffuse() const {
	return this->diffuse;
}
