#ifndef PARADIGMS_TRANSPORT_HPP
#define PARADIGMS_TRANSPORT_HPP

#include <fstream>


class Transport
{
	public:
		static Transport* InputTransport(std::ifstream &fin);
		virtual void InputData(std::ifstream &fin) = 0;
		virtual void OutputData(std::ofstream &fout) = 0;
		virtual int CalculateValue() = 0;


	protected:
		Transport() {};
		//virtual ~Transport() {};

};

#endif //PARADIGMS_TRANSPORT_HPP
