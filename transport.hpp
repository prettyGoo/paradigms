#ifndef PARADIGMS_TRANSPORT_HPP
#define PARADIGMS_TRANSPORT_HPP

#include <fstream>

//#include "bus.hpp"
//#include "truck.hpp"


class Transport
{
	public:
		static Transport* InputTransport(std::ifstream &fin);
		virtual void InputData(std::ifstream &fin) = 0;
		virtual void OutputData(std::ofstream &fout) = 0;

	protected:
		Transport() {};

};

#endif //PARADIGMS_TRANSPORT_HPP
