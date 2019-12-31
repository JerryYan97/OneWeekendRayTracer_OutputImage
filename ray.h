#pragma once
#include "3rdparty/eigen-3.3.7/Eigen/Dense"

using Eigen::Vector3d;

class ray
{
public:
	Vector3d A;
	Vector3d B;

	ray(){}
	ray(const Vector3d& a, const Vector3d& b)
		:A(a), B(b)
	{}
	Vector3d origin() const { return A; }
	Vector3d direction() const { return B; }
	Vector3d point_at_parameter(float t) const { return A + t * B; }
};

Vector3d color(const ray& r);
bool hit_sphere(const Vector3d& center, float radius, const ray& r);