#pragma once
#include "eigen-3.3.7/Eigen/dense"
#include "ray.h"
using namespace Eigen;
class camera
{
public:
	Vector3d origin;
	Vector3d lower_left_corner;
	Vector3d horizontal;
	Vector3d vertical;
	camera()
	{
		lower_left_corner = Vector3d(-2.0, -1.0, -1.0);
		horizontal = Vector3d(4.0, 0.0, 0.0);
		vertical = Vector3d(0.0, 2.0, 0.0);
		origin = Vector3d(0.0, 0.0, 0.0);
	}

	ray get_ray(float u, float v)
	{
		return ray(origin, lower_left_corner + u * horizontal + v * vertical);
	}
};

