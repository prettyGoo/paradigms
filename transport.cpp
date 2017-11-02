#include <cstdlib>
#include <iostream>
#include <fstream>

#include "bus.hpp"
#include "truck.hpp"
#include "car.hpp"


Transport* Transport::InputTransport(std::ifstream &fin)
{
	Transport *mean;
	int k;
	fin >> k;

	switch (k)
	{
	case 0:
		mean = new Bus();
		break;
	case 1:
		mean = new Truck();
		break;
	case 2:
		mean = new Car();
		break;
	default:
		std::cout << "Unknown key" << std::endl;
		system("pause");
		exit(EXIT_FAILURE);
	}
	mean->InputData(fin);
	return mean;
}


bool Transport::Compare(Transport *transportToCompare) 
{
	return CalculateValue() < transportToCompare->CalculateValue();
}

void Transport::OutputCar(std::ofstream &fout)
{
	fout << std::endl;
}