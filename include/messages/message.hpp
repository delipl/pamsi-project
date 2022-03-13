#pragma once
#include <vector>

#include "messages/package.hpp"

namespace pamsi {

struct Message {
    std::vector<PackageSharedPtr> package_list;
    void sort();
};
}  // namespace pamsi
