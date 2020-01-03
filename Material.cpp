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