#ifndef PARADIGMS_TRUCK_HPP
#define PARADIGMS_TRUCK_HPP

#include "transport.hpp"


class Truck : public Transport
{
	private:
		int weight;
		int power;

	public:
		void InputData(std::ifstream &fin);
		void OutputData(std::ofstream &fout);
		int CalculateValue();
		Truck() {};
};



#endif //PARADIGMS_TRUCK_HPP
