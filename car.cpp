#include <fstream>

#include "car.hpp"


void input(Car *car, std::ifstream &fin)
{
	fin >> car->max_speed >> car->passengers_capacity;
}

void output(Car *car, std::ofstream &fout)
{
	fout << "Car: " << car->max_speed << " " << car->passengers_capacity << std::endl;
}