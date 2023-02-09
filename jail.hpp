#ifndef JAIL_642
#define JAIL_642
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "StrategyFactory.hpp"

struct matrix
{
	int p1_res, p2_res, p3_res;
};

void read_matrix(matrix*** matrix, std::string filename = "default_matrix.txt");
int* competition(matrix*** matrix, StrategyFactory* SF1, StrategyFactory* SF2, StrategyFactory* SF3, bool is_detailed, std::string& configs_dir, int steps = -1);

#endif /*JAIL_642*/