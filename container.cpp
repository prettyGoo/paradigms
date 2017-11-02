#include <fstream>
#include <iostream>

#include "container.hpp"
#include "transport.hpp"

#include "car.hpp"


void List::InputData(std::ifstream &fin)
{
	while (!fin.eof()) {
		Node* active_node = new Node;
		active_node->value = Transport::InputTransport(fin);

		if (head == nullptr) {
			active_node->next = active_node;
			active_node->prev = active_node;
			head = active_node;
		}
		else {
			active_node->prev = head->prev;
			head->prev->next = active_node;
			active_node->next = head;
			head->prev = active_node;
		}
	}

	return;
}


void List::OutputData(std::ofstream &fout)
{
	Node *active_node = head;

	if (active_node->value == nullptr) {
		std::cout << "Container is empty" << std::endl;
		return;
	}

	do {
		active_node->value->OutputData(fout);
		active_node = active_node->next;

	} while (active_node != head);
}


void List::Clear()
{
	if (head == nullptr) return;

	head->prev->next = nullptr; // tear the chain
	while (head != nullptr)
	{
		Node *current_node = head->next;
		delete head->value;
		delete head;
		head = current_node;
	}
}


int List::Count() {
	Node *active_node = head;
	int counter = 0;

	if (active_node == nullptr) return 0;

	do {
		counter++;
		active_node = active_node->next;
	} while (active_node != head);

	return counter;
}


void List::OutputCalculatedValues(std::ofstream &fout) 
{
	Node *active_node = head;
	if (head == nullptr) return;

	do {
		fout << "Calculated value: " << active_node->value->CalculateValue() << std::endl;
		active_node = active_node->next;
	} while (active_node != head);
}


void List::Sort()
{
	Node* active_node = head;
	Node* node_to_compare = active_node->next;

	Transport *buffer;

	while (active_node->next != head) {
		while (node_to_compare != head) {
			if (active_node->value->Compare(node_to_compare->value)) {
				buffer = active_node->value;
				active_node->value = node_to_compare->value;
				node_to_compare->value = buffer;
			}
			node_to_compare = node_to_compare->next;
		}
		active_node = active_node->next;
		node_to_compare = active_node->next;
	}
}


void List::OutputOnly(Transport *base_transport, std::ofstream &fout)
{
	Node *active_node = head;

	if (active_node->value == nullptr) {
		std::cout << "Container is empty" << std::endl;
		return;
	}

	do {
		if (dynamic_cast<Car*> (active_node->value) != 0) {
			active_node->value->OutputData(fout);
		}
		active_node = active_node->next;
	} while (active_node != head);
}