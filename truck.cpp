#include <fstream>

#include "truck.hpp"

void input(Truck *truck, std::ifstream &fin)
{
	fin >> truck->speed >> truck->power;
}

void output(Truck *truck, std::ofstream &fout)
{
	fout << "Truck: " << truck->speed << " " << truck->power << std::endl;
}

double calculate_value(Truck *truck) {
	return truck->power * truck->speed;
}