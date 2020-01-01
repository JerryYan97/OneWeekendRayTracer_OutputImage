#pragma once

#include <cstdlib>
#include <random>
#include <iostream>
#include "eigen-3.3.7/Eigen/Dense"

inline double random_double()
{
	// return rand() / (RAND_MAX + 1.0);
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> dis(0.0, 1.0);
	return dis(gen);
}


