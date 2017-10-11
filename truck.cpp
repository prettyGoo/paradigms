#include <fstream>

#include "truck.hpp"

void input(Truck *truck, std::ifstream &fin)
{
	fin >> truck->speed >> truck->power >> truck->fuel_usage;
}

void output(Truck *truck, std::ofstream &fout)
{
	fout << "Truck: speed: " << truck->speed << ", power: " << truck->power << ", fuel usage:" << truck->fuel_usage << std::endl;
}

double calculate_value(Truck *truck) {
	return truck->power * truck->speed;
}