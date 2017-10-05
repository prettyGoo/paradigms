#include <fstream>

#include "car.hpp"

void input(Car *car, std::ifstream &fin)
{
	fin >> car->speed >> car->power;
}

void output(Car *car, std::ofstream &fout)
{
	fout << "Car: " << car->speed << " " << car->power << std::endl;
}

double calculate_value(Car *car) {
	return car->power * car->speed;
}