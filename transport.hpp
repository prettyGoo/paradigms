#ifndef PARADIGMS_TRANSPORT_HPP
#define PARADIGMS_TRANSPORT_HPP

#include <fstream>

#include "bus.hpp"
#include "truck.hpp"
#include "car.hpp"


struct Transport {
	enum mean { BUS = 0, TRUCK = 1, CAR = 2};
	mean mean;

	union
	{
		Bus bus;
		Truck truck;
		Car car;
	};

};


#endif //PARADIGMS_TRANSPORT_HPP
