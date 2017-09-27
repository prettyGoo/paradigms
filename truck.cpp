#include <fstream>

#include "truck.hpp"

void input(Truck *truck, std::ifstream &fin)
{
	fin >> truck->speed >> truck->goods_capacity;
}

void output(Truck *truck, std::ofstream &fout)
{
	fout << "Truck: " << truck->speed << " " << truck->goods_capacity << std::endl;
}