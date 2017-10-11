#include <fstream>

#include "car.hpp"

void input(Car *car, std::ifstream &fin)
{
	fin >> car->speed >> car->power >> car->fuel_usage;
}

void output(Car *car, std::ofstream &fout)
{
	fout << "Car: speed: " << car->speed << ", power: " << car->power << ", fuel usage:" << car->fuel_usage << std::endl;
}

double calculate_value(Car *car) {
	return car->power * car->speed;
}