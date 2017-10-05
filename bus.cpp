#include <fstream>

#include "bus.hpp"


void input(Bus *bus, std::ifstream &fin)
{
	fin >> bus->speed >> bus->power;
}

void output(Bus *bus, std::ofstream &fout)
{
	fout << "Bus: " << bus->speed << " " << bus->power << std::endl;
}

double calculate_value(Bus *bus) {
	return bus->power * bus->speed;
}