#ifndef PARADIGMS_CONTAINER_HPP
#define PARADIGMS_CONTAINER_HPP

struct Transport;

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

#endif //PARADIGMS_CONTAINER_HPP
