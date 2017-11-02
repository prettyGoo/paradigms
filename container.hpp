#ifndef PARADIGMS_CONTAINER_HPP
#define PARADIGMS_CONTAINER_HPP

#include "transport.hpp"


class Node
{
	public:
		Transport *value;
		Node *next;
		Node *prev;
};


class List
{
	private:
		Node *head;

	public:
		void InputData(std::ifstream &fin);
		void OutputData(std::ofstream &fout);
		void Clear();
		
		int Count();
		void OutputCalculatedValues(std::ofstream &fout);

		void Sort();
		void OutputOnly(Transport *base_transport,std::ofstream &fout);

		List() { head = nullptr; }
		~List() { Clear(); }
};


#endif //PARADIGMS_CONTAINER_HPP
