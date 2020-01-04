#pragma once
#define _USE_MATH_DEFINES
#include "eigen-3.3.7/Eigen/dense"
#include "ray.h"
#include <iostream>
#include <math.h>
using namespace Eigen;
class camera
{
public:
	Vector3d origin;
	Vector3d lower_left_corner;
	Vector3d horizontal;
	Vector3d vertical;
	Vector3d u, v, w;
	float lens_radius;

	// camera(Vector3d lookfrom, Vector3d lookat, Vector3d vup, float vfov, float aspect, float aperture, float focus_dist)
	camera(Vector3d lookfrom, Vector3d lookat, Vector3d vup, float vfov, float aspect)
	{
		/*float theta = vfov * M_PI / 180.0;
		float half_height = tan(theta / 2.0);
		float half_width = aspect * half_height;
		origin = lookfrom;
		w = (lookfrom - lookat).normalized();
		u = vup.cross(w).normalized();
		v = w.cross(u);
		lower_left_corner = origin - half_width * focus_dist * u - half_height * focus_dist * v - focus_dist * w;
		horizontal = 2 * half_width * focus_dist * u;
		vertical = 2 * half_height * focus_dist * v;*/
		/*lower_left_corner = Vector3d(-2.0, -1.0, -1.0);
		horizontal = Vector3d(4.0, 0.0, 0.0);
		vertical = Vector3d(0.0, 2.0, 0.0);
		origin = Vector3d(0.0, 0.0, 0.0);*/
		float theta = vfov * M_PI / 180.0;
		float half_height = tan(theta / 2.0);
		float half_width = aspect * half_height;
		origin = lookfrom;
		w = (lookfrom - lookat).normalized();
		u = (vup.cross(w)).normalized();
		v = w.cross(u);
		lower_left_corner = origin - half_width * u - half_height * v - w;
		horizontal = 2 * half_width*u;
		vertical = 2 * half_height*v;
		std::cout << "w:" << w << std::endl;
		std::cout << "u:" << u << std::endl;
		std::cout << "v:" << v << std::endl;
		std::cout << "lower_left_corner:" << lower_left_corner << std::endl;
		std::cout << "horizontal:" << horizontal << std::endl;
		std::cout << "vertical:" << vertical << std::endl;
	}

	ray get_ray(float u, float v)
	{
		return ray(origin, lower_left_corner + u * horizontal + v * vertical - origin);
	}
};

