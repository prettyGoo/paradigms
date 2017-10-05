#include <fstream>

#include "car.hpp"

void input(Car *car, std::ifstream &fin)
{
	fin >> car->speed >> car->goods_capacity;
}

void output(Car *car, std::ofstream &fout)
{
	fout << "Car: " << car->speed << " " << car->goods_capacity << std::endl;
}