#include <iostream>
#include <fstream>

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
			float r = float(column) / float(nx);
			float g = float(row) / float(ny);
			float b = 0.2;
			int ir = int(255.99 * r);
			int ig = int(255.99 * g);
			int ib = int(255.99 * b);
			outputFile << ir << " " << ig << " " << ib << "\n";
		}
	}
	outputFile.close();
}