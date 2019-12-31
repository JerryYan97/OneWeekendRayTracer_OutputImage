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

Vector3d color(const ray& r) {
	Vector3d unit_director = r.B.normalized();
	// std::cout << "unit_director: " << unit_director << std::endl;
	float t = 0.5 * (unit_director.y() + 1.0);
	return (1.0 - t) * Vector3d(1.0, 1.0, 1.0) + t * Vector3d(0.5, 0.7, 1.0);
}