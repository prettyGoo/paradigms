#include <iostream>

#include "bus.hpp"
#include "truck.hpp"
#include "container.cpp"

int main() {

    DoubleList list;
    init(&list);

    push(&list);
    push(&list);
    shift(&list);
    shift(&list);

//    std::cout << list.head->value->speed << std::endl;
//    std::cout << list.head->next->value->speed << std::endl;
//    std::cout << list.head->next->next->value->speed << std::endl;
//    std::cout << list.head->next->next->next->value->speed << std::endl;
//    std::cout << list.head->next->next->next->next->value->speed << std::endl;

//    pop(&list);
//    std::cout << list.head->value->speed << std::endl;
//    std::cout << list.head->next->value->speed << std::endl;
//    std::cout << list.head->next->next->value->speed << std::endl;
//    std::cout << list.head->next->next->next->value->speed << std::endl;

//    unshift(&list);
//    std::cout << list.head->value->speed << std::endl;
//    std::cout << list.head->next->value->speed << std::endl;
//    std::cout << list.head->next->next->value->speed << std::endl;
//    std::cout << list.head->next->next->next->value->speed << std::endl;

    clear(&list);
    std::cout << list.size << std::endl;

    return 0;
}