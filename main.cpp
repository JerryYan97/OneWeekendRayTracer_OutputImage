#include <iostream>
#include <fstream>
#include "3rdparty/eigen-3.3.7/Eigen/Dense"

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
	for (int row = 0; row < ny; row++)
	{
		for (int column = 0; column < nx; column++)
		{
			Vector3d col(float(column) / float(nx), float(row) / float(ny), 0.2);
			int ir = int(255.99 * col(0));
			int ig = int(255.99 * col(1));
			int ib = int(255.99 * col(2));
			outputFile << ir << " " << ig << " " << ib << "\n";
		}
	}
	outputFile.close();
}