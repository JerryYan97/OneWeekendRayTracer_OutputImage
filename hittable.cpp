#include "hittable.h"
#include <iostream>
#include "eigen-3.3.7/Eigen/Dense"

bool sphere::hit(const ray& r, float t_min, float t_max, hit_record& rec) const
{
	Vector3d oc = r.origin() - center;
	float a = r.direction().dot(r.direction());
	float b = 2.0 * r.direction().dot(oc);
	float c = oc.dot(oc) - radius * radius;
	float discriminant = b * b - 4 * a * c;
	if (discriminant > 0)
	{
		float temp_t = (-b - sqrt(discriminant)) / (2.0 * a);
		if (temp_t < t_max && temp_t > t_min)
		{
			rec.t = temp_t;
			rec.p = r.point_at_parameter(temp_t);
			rec.normal = (rec.p - center).normalized();
			return true;
		}
		temp_t = (-b + sqrt(discriminant)) / (2.0 * a);
		if (temp_t < t_max && temp_t > t_min)
		{
			rec.t = temp_t;
			rec.p = r.point_at_parameter(temp_t);
			rec.normal = (rec.p - center).normalized();
			return true;
		}
	}
	return false;
}

bool hittable_list::hit(const ray& r, float t_min, float t_max, hit_record& rec) const
{
	hit_record temp_rec;
	bool hit_anything = false;
	double closest_so_far = t_max;
	for (auto itr = mList.begin(); itr != mList.end(); itr++)
	{
		hittable* ptr = *itr;
		if (ptr->hit(r, t_min, closest_so_far, temp_rec))
		{
			hit_anything = true;
			closest_so_far = temp_rec.t;
			rec = temp_rec;
		}
	}
	return hit_anything;
}