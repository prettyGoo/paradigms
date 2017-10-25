#ifndef PARADIGMS_BUS_HPP
#define PARADIGMS_BUS_HPP

#include "transport.hpp"


class Bus : public Transport
{
	private:
		short space;
		int power;

	public:
		void InputData(std::ifstream &fin);
		void OutputData(std::ofstream &fout);
		Bus() {};
};



#endif //PARADIGMS_BUS_HPP
