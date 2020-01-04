#include "camera.h"

Vector3d random_in_unit_disk()
{
	Vector3d p;
	do {
		p = 2.0 * Vector3d(random_double(), random_double(), 0) - Vector3d(1, 1, 0);
	} while (p.dot(p) >= 1.0);
	return p;
}
