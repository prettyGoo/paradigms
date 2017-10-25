#include <fstream>
#include <iostream>

#include "container.hpp"
#include "transport.hpp"


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