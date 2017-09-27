#include <iostream>
#include <fstream>
#include <cstdlib>
#include <clocale>

#include "container.cpp"


int main(int argc, char* argv[]) {

//    if (argc < 3) {
//        std::cout << "There are not enough input arguments" << std::endl;
//        exit(EXIT_FAILURE);
//    }

	std::ifstream fin("in.txt");
	if (!fin.is_open()) {
		std::cout << "Input file has not been found" << std::endl;
		exit(EXIT_FAILURE);
	}

	std::ofstream fout("out.txt");
	if (!fout.is_open()) {
		std::cout << "Output file has not been found" << std::endl;
		exit(EXIT_FAILURE);
	}

    DoubleList list;
    init(&list);

	fill(&list, fin);
	show(&list, fout);
	std::cout << "The size of the container is " << list.size << std::endl;

	clear(&list);
	std::cout << "The container has been cleaned. Its size is " << list.size << std::endl;

	fin.close();

#ifdef _WIN64
	system("pause");
#elif _WIN32
	system("pause");
#endif // _WIN64


    return 0;
}