#include <fstream>

#include "car.hpp"


void Car::InputData(std::ifstream &fin)
{
	fin >> maxSpeed >> power >> fuelUsage;
}


void Car::OutputData(std::ofstream &fout)
{
	fout << "Car: " << maxSpeed << " max speed, " << power << " power, " << "fuel usage " << fuelUsage << std::endl;
}

int Car::CalculateValue()
{
	return power * maxSpeed;
}