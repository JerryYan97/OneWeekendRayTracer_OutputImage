#pragma once
#include "ray.h"
#include "hittable.h"

class Material
{
public:
	Material();
	~Material();

	virtual bool scatter(const ray& r_in, const hit_record& rec, Vector3d& attenuation, ray& scattered) const = 0;
};

class lambertian : public Material
{
public:
	Vector3d albedo;

	lambertian(const Vector3d& a) : albedo(a) {}
	virtual bool scatter(const ray& r_in, const hit_record& rec, Vector3d& attenuation, ray& scattered) const;
};

class metal : public Material
{
public:
	Vector3d albedo;
	float fuzz;

	metal(const Vector3d& a, float f) : albedo(a) 
	{
		if (f < 1)
		{
			fuzz = f;
		}
		else
		{
			fuzz = 1;
		}
	}
	virtual bool scatter(const ray& r_in, const hit_record& rec, Vector3d& attenuation, ray& scattered) const;
};