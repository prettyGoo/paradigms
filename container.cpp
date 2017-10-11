#include <fstream>
#include <iostream>

#include "container.hpp"

Transport* input(std::ifstream &fin);
void output(Transport *transport, std::ofstream &fout);
double ouput_calculate_value(Transport *transport);
bool compare_for_greatness(Transport* transport_one, Transport* transport_two);

void init(DoubleList *list) {
	list->size = 0;
	list->max_size = 100;

	list->head = nullptr;
}

void clear(DoubleList *list) {
	Node *head = list->head;

	if (head == nullptr) return;

	head->prev->next = nullptr; // tear the chain
	while (head != nullptr)
	{
		Node *current_node = head->next;
		delete head->value;
		delete head;
		head = current_node;
	}

	list->size = 0;
}

void fill(DoubleList *list, std::ifstream &fin) {
	int line = 0;

	while (!fin.eof()) {
		Node* active_node = new Node;
		active_node->value = input(fin);

		if (list->size == 0) {
			active_node->next = active_node;
			active_node->prev = active_node;
			list->head = active_node;
		}
		else {
			active_node->prev = list->head->prev;
			list->head->prev->next = active_node;
			active_node->next = list->head;
			list->head->prev = active_node;
		}

		list->size++;

		if (list->size == list->max_size) {
			std::cout << "Container is full" << std::endl;
			return;
		}

		line++;
	}

	return;
}

void show(DoubleList *list, std::ofstream &fout) {
	Node *active_node = list->head;

	if (active_node->value == nullptr) {
		std::cout << "Container is empty" << std::endl;
	}

	do {
		output(active_node->value, fout);
		active_node = active_node->next;
	} while (active_node != list->head);
}

void show_calculate_value(DoubleList *list, std::ofstream &fout) {
	Node *active_node = list->head;

	if (active_node->value == nullptr) {
		std::cout << "Container is empty" << std::endl;
	}

	do {
		active_node = active_node->next;
		fout << ouput_calculate_value(active_node->value) << std::endl;
	} while (active_node != list->head);
}

void sort(DoubleList *list) {
	Node* active_node = list->head;
	Node* node_to_compare = active_node->next;

	Transport *buffer;

	while (active_node->next != list->head) {
		while (node_to_compare != list->head) {
			if (compare_for_greatness(active_node->value, node_to_compare->value)) {
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
/*void push_back(DoubleList *list, Node *active_node) {
    if (list->size == 0) {
        active_node->next = active_node;
        active_node->prev = active_node;
        list->head = active_node;
    }
    else {
        active_node->prev = list->head->prev;
        list->head->prev->next = active_node;
        active_node->next = list->head;
        list->head->prev = active_node;
    }
    list->size += 1;

	return;
}

/*inline void push_front(DoubleList *list, Transport) {
	Node *active_node = new Node;
	active_node->value = new Bus;

	active_node->value->speed = 50;

	if (list->size == 0) {
		active_node->next = active_node;
		active_node->prev = active_node;
	}
	else {
		active_node->next = list->head;
		list->head->prev->next = active_node;
		active_node->prev = list->head->prev;
		list->head->prev = active_node;
	}

	list->head = active_node;
	list->size += 1;
}

inline void pop_back(DoubleList *list) {
	if (list->size == 0) return;
	else {
		list->head->prev = list->head->prev->prev;
		delete list->head->prev->next;
		list->head->prev->next = list->head;

	}

	list->size -= 1;
}

inline void pop_front(DoubleList *list) {
	if (list->size == 0) return;
	else {
		Node *new_head = new Node;

		new_head = list->head->next;
		new_head->prev = list->head->prev;
		list->head->prev->next = new_head;

		delete list->head;
		list->head = new_head;
	}

	list->size -= 1;
}

*/