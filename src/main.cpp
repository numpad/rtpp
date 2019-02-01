#include <stdio.h>
#include <vector>
#include <float.h>

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <stb/stb_image_write.h>
#undef STB_IMAGE_WRITE_IMPLEMENTATION

#include "Collidable.hpp"
#include "ImageFramebuffer.hpp"
#include "Vec3.hpp"
#include "Sphere.hpp"
#include "Ray.hpp"
#include "RayHit.hpp"

int main() {
	
	std::vector<Collidable *> objects;
	objects.push_back(new Sphere(Vec3(0.0f,  0.0f, 50.0f), 20.0f));
	
	ImageFramebuffer image(800, 600);
	Vec3 light_pos(-7.5f, 15.0f, 35.0f);
	Vec3 cam_pos;
	const float fov = 3.1415926f * 0.5f;
	for (int y = 0; y < image.get_height(); ++y) {
		for (int x = 0; x < image.get_width(); ++x) {
			float xx =  (2.0f * (x + 0.5f) / (float)image.get_width() - 1.0f) * tan(fov * 0.5f) * (float)image.get_width() / (float)image.get_height();
			float yy = -(2.0f * (y + 0.5f) / (float)image.get_height() - 1.0f) * tan(fov * 0.5f);
			
			Ray ray(cam_pos, Vec3(xx, yy, 1.0f).normal());
			
			RayHit rh = ray.intersect(objects);
			if (!rh.hit) { image.set_pixel(x, y, 33, 33, 33); continue; }
			
			/* light */
			float illu = fmaxf(0.0f, rh.n.dot((light_pos - rh.p).normal()));
			
			Vec3 px(illu * 255.0f);
			
			image.set_pixel(x, y, px.x, px.y, px.z);
		
		}
	}
	
	image.save("abc.png");
	
	for (auto *o : objects)
		delete o;
	
	return 0;
}
