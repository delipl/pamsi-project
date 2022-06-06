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
        if (!file_stream.good()) {
            throw std::runtime_error("There is no file!");
        }
        Package one;
        std::string line;
        for (auto i = 0u; i < data_size && !file_stream.eof(); ++i) {
            try {
                file_stream >> one;
            } catch (const std::runtime_error &e) {
                continue;
            } catch (const std::out_of_range &e) {
                break;
            }
            data_.push_back(one);
        }
        file_stream.close();
    };

    std::vector<Package> &data() {
        return data_;
    };

    ~CSVReader() {
        data_.clear();
    }

   private:
    std::string file_name_;
    std::vector<Package> data_;
};
}  // namespace pamsi