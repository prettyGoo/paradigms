#include <fstream>

#include "truck.hpp"


void Truck::InputData(std::ifstream &fin)
{
	fin >> weight >> power;
}


void Truck::OutputData(std::ofstream &fout)
{
	fout << "Truck: " << weight << " tonns, " << power << " power" << std::endl;
}


int Truck::CalculateValue()
{
	return power * weight;
}