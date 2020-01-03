#include "ray.h"
#include "hittable.h"
#include "mRandom.h"
#include "Material.h"
#include <iostream>
#include <float.h>

Eigen::Vector3d random_in_unit_sphere()
{
	Eigen::Vector3d p;
	do {
		p = 2.0 * Eigen::Vector3d(random_double(), random_double(), random_double()) - Eigen::Vector3d(1, 1, 1);
	} while (p.squaredNorm() >= 1.0);
	return p;
}


Vector3d color(const ray& r, hittable *world, int depth) 
{
	hit_record rec;
	rec.normal = Vector3d(1, 0, 0);
	rec.p = Vector3d(0, 0, 0);
	rec.t = 0;
	if (world->hit(r, 0.001, FLT_MAX, rec))
	{
		ray scattered;
		Vector3d attenuation;
		if (depth < 50 && rec.mat_ptr->scatter(r, rec, attenuation, scattered))
		{
			return attenuation.cwiseProduct(color(scattered, world, depth + 1));
		}
		else
		{
			return Vector3d(0, 0, 0);
		}
		// return 0.5 * color(ray(rec.p, rec.normal + random_in_unit_sphere()), world);
	}
	else
	{
		// return Vector3d(0, 0, 0);
		Vector3d unit_direction = r.direction().normalized();
		float t = 0.5 * (unit_direction.y() + 1.0);
		return (1.0 - t) * Vector3d(1.0, 1.0, 1.0) + t * Vector3d(0.5, 0.7, 1.0);
	}	
}

Vector3d reflect(const Vector3d& v, const Vector3d& n)
{
	return v - 2 * v.dot(n) * n;
}

bool refract(const Vector3d& v, const Vector3d& n, float ni_over_nt, Vector3d& refracted)
{
	Vector3d uv = v.normalized();
	float dt = uv.dot(n);
	float discriminant = 1.0 - ni_over_nt * ni_over_nt * (1 - dt * dt);
	if (discriminant > 0)
	{
		refracted = ni_over_nt * (uv - n * dt) - n * sqrt(discriminant);
		// refracted = ni_over_nt * sqrt(1 - dt * dt) * (uv + n * dt).normalized() - n * sqrt(discriminant);
		return true;
	}
	else
	{
		return false;
	}
}