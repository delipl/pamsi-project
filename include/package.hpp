#pragma once

#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
namespace pamsi {

struct Package {
    std::size_t id;
    std::string data;

    Package() = default;
    Package(const std::size_t id, const std::string& data)
        : id{id}, data{data} {};

    Package(const Package& other) = default;
};

inline bool operator==(const Package& lhs, const Package& rhs) { return lhs.id == rhs.id; }
inline bool operator!=(const Package& lhs, const Package& rhs) { return !(lhs == rhs); }
inline bool operator<(const Package& lhs, const Package& rhs) { return lhs.id < rhs.id; }
inline bool operator>(const Package& lhs, const Package& rhs) { return rhs < lhs; }
inline bool operator<=(const Package& lhs, const Package& rhs) { return !(lhs > rhs); }
inline bool operator>=(const Package& lhs, const Package& rhs) { return !(lhs < rhs); }
}  // namespace pamsi