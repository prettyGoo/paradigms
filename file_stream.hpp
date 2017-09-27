//
// Created by nikita on 26.09.17.
//

#ifndef PARADIGMS_FILE_STREAM_HPP
#define PARADIGMS_FILE_STREAM_HPP

#include <iostream>
#include <fstream>
#include <string>

struct FileStream {
    std::ifstream ifstream;
    std::ofstream ofstream;

    std::string ifsteam_name;
    std::string ofstream_name;
};



#endif //PARADIGMS_FILE_STREAM_HPP
