#include <iostream>
#include <fstream>
#include <cstdlib>
#include <clocale>

#include "container.hpp"


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

    List list;

	list.InputData(fin);
	//list.OutputData(fout);
	list.OutputCalculatedValues(fout);

	std::cout << "The size of the container is " << list.Count() << std::endl;
	list.Clear();
	std::cout << "The container has been cleaned. Its size is " << list.Count() << std::endl;

	fin.close();
	fout.close();

#ifdef _WIN64
	system("pause");
#elif _WIN32
	system("pause");
#endif // _WIN64


    return 0;
}