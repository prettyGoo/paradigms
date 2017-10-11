#include <fstream>

#include "bus.hpp"


void input(Bus *bus, std::ifstream &fin)
{
	fin >> bus->speed >> bus->power >> bus->fuel_usage;
}

void output(Bus *bus, std::ofstream &fout)
{
	fout << "Bus: speed: " << bus->speed << ", power: " << bus->power << ", fuel usage:" << bus->fuel_usage << std::endl;
}

double calculate_value(Bus *bus) {
	return bus->power * bus->speed;
}