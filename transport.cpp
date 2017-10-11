#include "transport.hpp"
#include <fstream>
#include <iostream>


void input(Bus *bus, std::ifstream &fin);
void input(Truck *truck, std::ifstream &fin);
void input(Car *car, std::ifstream &fin);

void output(Bus *bus, std::ofstream &fout);
void output(Truck *truck, std::ofstream &fout);
void output(Car *car, std::ofstream &fout);


double calculate_value(Bus *bus);
double calculate_value(Truck *truck);
double calculate_value(Car *car);

// ==========================================
Transport* input(std::ifstream &fin) {
	Transport *transport = nullptr;

	int key;
	fin >> key;

	switch (key)
	{
		case Transport::mean::BUS: {
			transport = new Transport;
			transport->mean = Transport::mean::BUS;
			input(&transport->bus, fin);
			
			return transport;
		}
		case Transport::mean::TRUCK: {
			transport = new Transport;
			transport->mean = Transport::mean::TRUCK;
			input(&transport->truck, fin);

			return transport;
		}
		case Transport::mean::CAR: {
			transport = new Transport;
			transport->mean = Transport::mean::CAR;
			input(&transport->car, fin);

			return transport;
		}
		default:
			return transport;
	}
}


void output(Transport *transport, std::ofstream &fout)
{
	switch (transport->mean)
	{
		case Transport::mean::BUS: {
			output(&transport->bus, fout);
			break;
		}
		case  Transport::mean::TRUCK: {
			output(&transport->truck, fout);
			break;
		}
		case  Transport::mean::CAR: {
			output(&transport->car, fout);
			break;
		}
		default:
			break;
	}
}

double ouput_calculate_value(Transport *transport) {
	switch (transport->mean)
	{
		case Transport::mean::BUS: {
			return calculate_value(&transport->bus);
		}
		case  Transport::mean::TRUCK: {
			return calculate_value(&transport->truck);
		}
		case  Transport::mean::CAR: {
			return calculate_value(&transport->car);

		}
		default:
			return -1.0;
	}
}

bool compare_for_greatness(Transport* transport_one, Transport* transport_two) {
	return ouput_calculate_value(transport_one) > ouput_calculate_value(transport_two);
}