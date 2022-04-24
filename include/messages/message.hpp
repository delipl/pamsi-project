#pragma once
#include <algorithm>  // std::random_shuffle
#include <cstdlib>    // std::rand, std::srand
#include <ctime>      // std::time
#include <vector>

#include "messages/package.hpp"
namespace pamsi {

struct Message {
    std::vector<PackageSharedPtr> package_list;
    Message(std::string &data, std::size_t elems){
        std::size_t one_size = data.length() / elems;
        for (auto i = 0u; i <= elems; ++i) {
            auto start = i * one_size;
            auto one_package = data.substr(start, one_size);
            if(one_package.length() != 0){
                package_list.emplace_back(std::make_shared<Package>(i, one_package));
            }
        }

        std::random_shuffle(std::begin(package_list), std::end(package_list));
    }
};
}  // namespace pamsi
