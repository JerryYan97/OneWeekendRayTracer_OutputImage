#include "Material.h"


Material::Material()
{
}

Material::~Material()
{
}

bool lambertian::scatter(const ray& r_in, const hit_record& rec, Vector3d& attenuation, ray& scattered) const
{
	scattered = ray(rec.p, rec.normal + random_in_unit_sphere());
	attenuation = albedo;
	return true;
}

bool metal::scatter(const ray& r_in, const hit_record& rec, Vector3d& attenuation, ray& scattered) const
{
	Vector3d reflected = reflect(r_in.direction(), rec.normal);
	scattered = ray(rec.p, reflected + fuzz * random_in_unit_sphere());
	attenuation = albedo;
	// Should not it be always true ?
	return (scattered.direction().dot(rec.normal) > 0);
}

bool dielectric::scatter(const ray& r_in, const hit_record& rec, Vector3d& attenuation, ray& scattered) const
{
	Vector3d outward_normal;
	Vector3d reflected = reflect(r_in.direction(), rec.normal);
	float ni_over_nt;
	attenuation = Vector3d(1.0, 1.0, 1.0);
	Vector3d refracted;

	if (r_in.direction().dot(rec.normal) > 0)
	{
		// e.g. From a glass ball inside to a glass ball outside.
		outward_normal = -rec.normal;
		ni_over_nt = ref_idx;
	}
	else
	{
		// e.g. From a glass ball outside to a glass ball inside.
		outward_normal = rec.normal;
		ni_over_nt = 1.0 / ref_idx;
	}

	if (refract(r_in.direction(), outward_normal, ni_over_nt, refracted))
	{
		// If a refract effect is exist.
		scattered = ray(rec.p, refracted);
	}
	else
	{
		// If a refract effect does not exist.
		scattered = ray(rec.p, reflected);
		return false;
	}
	return true;
}