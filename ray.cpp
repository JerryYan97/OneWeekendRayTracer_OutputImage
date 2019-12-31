#include "ray.h"

Vector3d color(const ray& r) {
	if (hit_sphere(Vector3d(0, 0, 1), 0.5, r))
	{
		return Vector3d(1, 0, 0);
	}
	Vector3d unit_director = r.B.normalized();
	// std::cout << "unit_director: " << unit_director << std::endl;
	float t = 0.5 * (unit_director.y() + 1.0);
	return (1.0 - t) * Vector3d(1.0, 1.0, 1.0) + t * Vector3d(0.5, 0.7, 1.0);
}

bool hit_sphere(const Vector3d& center, float radius, const ray& r)
{
	Vector3d oc = r.origin() - center;
	float a = r.direction().dot(r.direction());
	float b = 2.0 * r.direction().dot(oc);
	float c = oc.dot(oc) - radius * radius;
	float discriminant = b * b - 4 * a * c;
	return (discriminant > 0);
}