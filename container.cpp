#include "container.hpp"

void init(DoubleList *list) {
    list->size = 0;
    list->max_size = 0;

    list->head = nullptr;
}

void clear(DoubleList *list) {
    Node *head = list->head;

    if (head == nullptr) return;

    head->prev->next = nullptr;
    while (head != nullptr)
    {
        Node *p = head->next;
        delete head->value;
        delete head;
        head = p;
    }

    list->size = 0;
}

void push(DoubleList *list) {
    Node *active_node = new Node;
    active_node->value = new Bus;

    active_node->value->speed = 100;

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
}

void shift(DoubleList *list) {
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

void pop(DoubleList *list) {
    if (list->size == 0) return;
    else {
        list->head->prev = list->head->prev->prev;
        delete list->head->prev->next;
        list->head->prev->next = list->head;

    }

    list->size -= 1;
}

void unshift(DoubleList *list) {
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