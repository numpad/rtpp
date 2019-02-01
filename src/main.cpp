#include <stdio.h>
#include <float.h>
#include <time.h>
#include <vector>

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <stb/stb_image_write.h>
#undef STB_IMAGE_WRITE_IMPLEMENTATION

#include "Collidable.hpp"
#include "ImageFramebuffer.hpp"
#include "Vec3.hpp"
#include "Sphere.hpp"
#include "Ray.hpp"
#include "RayHit.hpp"
#include "Scene.hpp"

int main(int argc, char *argv[]) {
	float arg_scale = 1.0f;
	while (argc-- > 0) {
		sscanf(argv[argc], "scale=%f", &arg_scale);
	}
	
	srand(time(nullptr));
	
	/* scene */
	Scene scene;
	scene.add(new Sphere(Vec3( -4.0f,   7.0f, 27.0f),  2.0f));
	scene.add(new Sphere(Vec3(  3.0f,   4.0f, 31.0f),  4.5f));
	scene.add(new Sphere(Vec3( 10.0f, -14.0f, 50.0f), 20.0f));
	
	ImageFramebuffer image(1920 * arg_scale, 1080 * arg_scale);
	Vec3 light_pos(-20.5f, 25.0f, 15.0f);
	Vec3 cam_pos(0.0f, 3.0f, 0.0f);
	const float fov = 3.1415926f * 0.5f;
	for (int y = 0; y < image.get_height(); ++y) {
		for (int x = 0; x < image.get_width(); ++x) {
			float xx =  (2.0f * (x + 0.5f) / (float)image.get_width() - 1.0f) * tan(fov * 0.5f) * (float)image.get_width() / (float)image.get_height();
			float yy = -(2.0f * (y + 0.5f) / (float)image.get_height() - 1.0f) * tan(fov * 0.5f);
			
			Ray ray(cam_pos, Vec3(xx, yy, 1.0f).normal());
			
			RayHit rh = scene.cast(ray);
			if (!rh.hit) { image.set_pixel(x, y, 117, 163, 216); continue; }
			
			/* light */
			Vec3 to_light = (light_pos - rh.p).normal();
			Ray shadow_ray(rh.p + to_light * 0.05f, to_light);
			RayHit srh = scene.cast(shadow_ray);
			
			const float ambient = 0.1875f;
			float occluded = 1.0f;
			if (srh.hit) occluded = 0.0f;
			
			float illu = fmaxf(ambient, occluded * rh.n.dot((light_pos - rh.p).normal()));
			Sphere *sph = (Sphere *)rh.get_collider();
			Vec3 px(sph->get_material().get_diffuse() * illu * 255.0f);
			
			image.set_pixel(x, y, px.x, px.y, px.z);
		
		}
	}
	
	image.save("abc.png");
	
	return 0;
}
