#include <fstream>

#include "bus.hpp"


void Bus::InputData(std::ifstream &fin)
{
	fin >> space >> power;
}


void Bus::OutputData(std::ofstream &fout)
{
	fout << "Bus: " << space << " sits for passangers, " << power << " power" << std::endl;
}

int Bus::CalculateValue()
{
	return power * space;
}
