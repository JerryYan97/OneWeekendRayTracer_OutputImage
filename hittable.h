#pragma once
#include "ray.h"
#include <list>

class Material;
using Eigen::Vector3d;

struct hit_record
{
	float t;
	Vector3d p;
	Vector3d normal;
	Material *mat_ptr;
};

class hittable
{
public:
	virtual bool hit(const ray& r, float t_min, float t_max, hit_record& rec) const = 0;
};

class sphere : public hittable
{
public:
	Vector3d center;
	float radius;
	Material *mat_ptr;

	sphere(){}
	sphere(Vector3d cen, float r, Material* m)
		: center(cen), radius(r), mat_ptr(m)
	{};

	virtual bool hit(const ray& r, float tmin, float tmax, hit_record& rec) const;
	
};

class hittable_list : public hittable
{
public:
	std::list<hittable*> mList;
	int list_size;
	hittable_list(){}
	hittable_list(std::list<hittable*>& iList, int iSize)
		: mList(iList), list_size(iSize)
	{}
	virtual bool hit(const ray& r, float tmin, float tmax, hit_record& rec) const;
};