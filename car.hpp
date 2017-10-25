#ifndef PARADIGMS_CAR_HPP
#define PARADIGMS_CAR_HPP

#include "transport.hpp"


class Car : public Transport
{
private:
	short maxSpeed;
	int power;

public:
	void InputData(std::ifstream &fin);
	void OutputData(std::ofstream &fout);
	Car() {};
};



#endif //PARADIGMS_CAR_HPP
