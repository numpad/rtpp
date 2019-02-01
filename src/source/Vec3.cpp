#include "Vec3.hpp"

Vec3::Vec3(float x, float y, float z) 
	: x(x), y(y), z(z)
{
	
}

Vec3::Vec3(float v)
	: Vec3(v, v, v)
{
	
}

Vec3::Vec3()
	: Vec3(0.0f)
{
	
}

Vec3 Vec3::operator+(const Vec3 &other) const {
	return Vec3(
		this->x + other.x,
		this->y + other.y,
		this->z + other.z
	);
}

Vec3 Vec3::operator-(const Vec3 &other) const {
	return Vec3(
		this->x - other.x,
		this->y - other.y,
		this->z - other.z
	);
}

Vec3 Vec3::operator*(const Vec3 &other) const {
	return Vec3(
		this->x * other.x,
		this->y * other.y,
		this->z * other.z
	);
}

Vec3 Vec3::operator*(const float scalar) const {
	return Vec3(
		this->x * scalar,
		this->y * scalar,
		this->z * scalar
	);
}

Vec3 Vec3::operator/(const float scalar) const {
	return Vec3(
		this->x / scalar,
		this->y / scalar,
		this->z / scalar
	);
}

Vec3 Vec3::operator-() const {
	return *this * -1.0f;
}

float Vec3::length() const {
	return sqrtf(
		this->x * this->x +
		this->y * this->y +
		this->z * this->z
	);
}

float Vec3::length(const Vec3 &vec) {
	return vec.length();
}

float Vec3::length2() const {
	return (
		this->x * this->x +
		this->y * this->y +
		this->z * this->z
	);
}

float Vec3::length2(const Vec3 &vec) {
	return vec.length2();
}

Vec3 Vec3::normal() const {
	return *this / this->length();
}

Vec3 Vec3::normal(const Vec3 &vec) {
	return vec.normal();
}	

float Vec3::dot(const Vec3 &other) const {
	return this->x * other.x +
	       this->y * other.y +
	       this->z * other.z;
}

float Vec3::dot(const Vec3 &a, const Vec3 &b) {
	return a.dot(b);
}
