#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "package.hpp"

namespace pamsi {

class CSVReader {
   public:
    explicit CSVReader(const std::string &file_name, const std::size_t data_size)
        : file_name_{file_name} {
        std::ifstream file_stream(file_name);
        Package one;
        std::string line;
        std::getline(file_stream, line, '\n');
        for (auto i = 0u; i < data_size; ++i) {
            file_stream >> one;
            data_.push_back(one);
        }
        file_stream.close();
    };

    std::vector<Package> data() {
        return data_;
    }

   private:
    std::string file_name_;
    std::vector<Package> data_;
};
}  // namespace pamsi