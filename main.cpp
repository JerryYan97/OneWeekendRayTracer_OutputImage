#include <iostream>
#include <fstream>
#include <list>
#include "camera.h"
#include "ray.h"
#include "hittable.h"
#include "mRandom.h"
#include "Material.h"

using namespace std;
using namespace Eigen;

void main()
{
	std::ofstream outputFile;
	outputFile.open("HelloWorld.ppm");
	int nx = 200;
	int ny = 100;
	int ns = 100;
	outputFile << "P3\n" << nx << " " << ny << "\n255\n";

	Vector3d lower_left_corner(-2.0, -1.0, -1.0);
	Vector3d horizontal(4.0, 0.0, 0.0);
	Vector3d vertical(0.0, 2.0, 0.0);
	Vector3d origin(0.0, 0.0, 0.0);
	
	lambertian matA = lambertian(Vector3d(0.8, 0.3, 0.3));
	lambertian matB = lambertian(Vector3d(0.8, 0.8, 1.0));
	metal matC = metal(Vector3d(0.8, 0.6, 0.2), 1.0);
	metal matD = metal(Vector3d(0.8, 0.8, 0.8), 0.3);

	sphere s1 = sphere(Vector3d(0, 0, -1), 0.5, &matA);
	sphere s2 = sphere(Vector3d(0, -100.5, -1), 100, &matB);
	sphere s3 = sphere(Vector3d(1, 0, -1), 0.5, &matC);
	sphere s4 = sphere(Vector3d(-1, 0, -1), 0.5, &matD);
	list<hittable*> objList = { &s1, &s2, &s3, &s4};
	hittable_list world = hittable_list(objList, objList.size());
	camera cam;

	for (int rowIdx = ny - 1; rowIdx >= 0; rowIdx--)
	{
		for (int columnIdx = 0; columnIdx < nx; columnIdx++)
		{
			// We create a ray for every pixels of the image.
			// Transform pixel coordinate to uv coordinate.
			float u = float(columnIdx) / float(nx);
			float v = float(rowIdx) / float(ny);
			// Transform uv coordinate to an easy world coordinate,
			// and then create a ray for it.
			// We can conclude from the data format of origin and pointing place
			// that they are in the world coordinate.
			// ray r(origin, lower_left_corner + u * horizontal + v * vertical);

			// Vector3d col = color(r, &world);
			Vector3d col(0, 0, 0);
			for (int s = 0; s < ns; s++)
			{
				float u = float(columnIdx + random_double()) / float(nx);
				float v = float(rowIdx + random_double()) / float(ny);
				ray r = cam.get_ray(u, v);
				col += color(r, &world, 0);
			}
			col /= float(ns);
			col = Vector3d(sqrt(col(0)), sqrt(col(1)), sqrt(col(2)));

			int ir = int(255.99 * col(0));
			int ig = int(255.99 * col(1));
			int ib = int(255.99 * col(2));
			outputFile << ir << " " << ig << " " << ib << "\n";
		}
	}
	outputFile.close();
}