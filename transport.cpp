#include "transport.hpp"
#include <fstream>
#include <iostream>


void input(Bus *bus, std::ifstream &fin);
void input(Truck *truck, std::ifstream &fin);
void input(Car *car, std::ifstream &fin);

void output(Bus *bus, std::ofstream &fout);
void output(Truck *truck, std::ofstream &fout);
void output(Car *car, std::ofstream &fout);


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