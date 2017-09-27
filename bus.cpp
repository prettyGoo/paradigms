#include <fstream>

#include "bus.hpp"


void input(Bus *bus, std::ifstream &fin)
{
	fin >> bus->speed >> bus->passengers_capacity;
}

void output(Bus *bus, std::ofstream &fout)
{
	fout << "Bus: " << bus->speed << " " << bus->passengers_capacity << std::endl;
}