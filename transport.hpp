#ifndef PARADIGMS_TRANSPORT_HPP
#define PARADIGMS_TRANSPORT_HPP

#include <fstream>

#include "bus.hpp"
#include "truck.hpp"

struct Transport {
	enum mean { BUS = 0, TRUCK = 1};
	mean mean;

	union
	{
		Bus bus;
		Truck truck;
	};

};


#endif //PARADIGMS_TRANSPORT_HPP
