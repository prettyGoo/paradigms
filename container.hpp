#ifndef PARADIGMS_CONTAINER_HPP
#define PARADIGMS_CONTAINER_HPP

#include "transport.hpp"

struct Node {
    Transport *value;
    Node *next;
    Node *prev;
};

struct DoubleList {
    int size;
    int max_size;

    Node* head;
};

void init(DoubleList *list);
void clear(DoubleList *list);
void fill(DoubleList *list, std::ifstream &fin);
void sort(DoubleList *list);
void show(DoubleList *list, std::ofstream &fout);
void show_calculate_value(DoubleList *list, std::ofstream &fout);
void show_cars_only(DoubleList *list, std::ofstream &fout);

#endif //PARADIGMS_CONTAINER_HPP
