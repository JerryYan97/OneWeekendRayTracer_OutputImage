#include "ray.h"
#include "hittable.h"
#include <iostream>
#include <float.h>
Vector3d color(const ray& r, hittable *world) 
{
	hit_record rec;
	rec.normal = Vector3d(1, 0, 0);
	rec.p = Vector3d(0, 0, 0);
	rec.t = 0;
	if (world->hit(r, 0.0, FLT_MAX, rec))
	{
		// return 0.5 * Vector3d(rec.normal.x() + 1, rec.normal.y() + 1, rec.normal.z() + 1);
		// std::cout << "normal length: " << sqrt(rec.normal.x() * rec.normal.x() + rec.normal.y() * rec.normal.y() + rec.normal.z() * rec.normal.z()) << std::endl;
		// rec.normal.normalize();
		// std::cout << "x: " << rec.normal.x() << " y: "<< rec.normal.y() << " z: " << rec.normal.z() << std::endl;
		// std::cout << "t: " << rec.t << std::endl;

		return 0.5 * Vector3d(rec.normal.x() + 1, rec.normal.y() + 1, rec.normal.z() + 1);
		
		// return Vector3d(0.9, 0.9, 0.9);
		// return rec.normal * 0.01;
	}
	else
	{
		// return Vector3d(0, 0, 0);
		Vector3d unit_direction = r.direction().normalized();
		float t = 0.5 * (unit_direction.y() + 1.0);
		return (1.0 - t) * Vector3d(1.0, 1.0, 1.0) + t * Vector3d(0.5, 0.7, 1.0);
	}	
}