#include <cstdlib>
#include <iostream>
#include <fstream>

#include "bus.hpp"
#include "truck.hpp"


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
	default:
		std::cout << "Unknown key" << std::endl;
		system("pause");
		exit(EXIT_FAILURE);
	}
	mean->InputData(fin);
	return mean;
}