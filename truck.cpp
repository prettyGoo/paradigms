#include <fstream>

#include "truck.hpp"


void Truck::InputData(std::ifstream &fin)
{
	fin >> weight >> power >> fuelUsage;
}


void Truck::OutputData(std::ofstream &fout)
{
	fout << "Truck: " << weight << " tonns, " << power << " power, " << "fuel usage " << fuelUsage << std::endl;
}


int Truck::CalculateValue()
{
	return power * weight;
}