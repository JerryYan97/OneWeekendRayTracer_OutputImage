#include <iostream>
#include <fstream>
#include "ray.h"

//***//
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
			float u = float(columnIdx) / float(nx);
			float v = float(rowIdx) / float(ny);
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