#include <iostream>
#include <fstream>
#include "ray.h"

using Eigen::MatrixXd;
using Eigen::Vector3d;
using namespace std;

void main()
{
	std::ofstream outputFile;
	outputFile.open("HelloWorld.ppm");
	int nx = 200;
	int ny = 100;
	outputFile << "P3\n" << nx << " " << ny << "\n255\n";

	Vector3d lower_left_corner(-2.0, -1.0, -1.0);
	Vector3d horizontal(4.0, 0.0, 0.0);
	Vector3d vertical(0.0, 2.0, 0.0);
	Vector3d origin(0.0, 0.0, 0.0);

	for (int rowIdx = 0; rowIdx < ny; rowIdx++)
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
			ray r(origin, lower_left_corner + u * horizontal + v * vertical);

			Vector3d col = color(r);

			int ir = int(255.99 * col(0));
			int ig = int(255.99 * col(1));
			int ib = int(255.99 * col(2));
			outputFile << ir << " " << ig << " " << ib << "\n";
		}
	}
	outputFile.close();
}