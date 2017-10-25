#include <fstream>

#include "car.hpp"


void Car::InputData(std::ifstream &fin)
{
	fin >> maxSpeed >> power;
}


void Car::OutputData(std::ofstream &fout)
{
	fout << "Car: " << maxSpeed << " max speed, " << power << " power" << std::endl;
}
