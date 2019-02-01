#ifndef VEC3_HPP
#define VEC3_HPP

#include <math.h>

class Vec3 {

public:
	float x, y, z;
	
	Vec3(float x, float y, float z);
	Vec3(float v);
	Vec3();
	
	Vec3 operator+(const Vec3 &other) const;
	Vec3 operator-(const Vec3 &other) const;
	Vec3 operator*(const Vec3 &other) const;
	Vec3 operator*(const float scalar) const;
	Vec3 operator/(const float scalar) const;
	
	Vec3 operator-() const;
	
	float length() const;
	static float length(const Vec3 &vec);
	float length2() const;
	static float length2(const Vec3 &vec);
	
	Vec3 normal() const;
	static Vec3 normal(const Vec3 &vec);
	
	float dot(const Vec3 &other) const;
	static float dot(const Vec3 &a, const Vec3 &b);
};

#endif
