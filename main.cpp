#include <iostream>
#include <fstream>
#include <cstdlib>
#include <clocale>


#include "bus.hpp"
#include "truck.hpp"
#include "container.cpp"

#include "file_stream.hpp"

using namespace std;

int main(int argc, char* argv[]) {

//    if (argc < 3) {
//        std::cout << "There are not enough input arguments" << std::endl;
//        exit(EXIT_FAILURE);
//    }

//    FileStream stream;
//    stream.ifsteam_name = argv[1];
//    stream.ofstream_name = argv[2];

    std::ifstream f;
    f.open("in.txt", std::fstream::in);
    if (f.is_open()) {
        std::cout << "SUccess\n";
    }
    f.close();

    std::ifstream ff;
    ff.open("out.txt", std::fstream::in);
    if (ff.is_open()) {
        std::cout << "1 SUccess\n";
    }
    ff.close();

    DoubleList list;
    init(&list);

    push_back(&list);
    push_back(&list);
    push_front(&list);
    push_front(&list);

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

//    clear(&list);
    std::cout << list.size << std::endl;

    return 0;
}