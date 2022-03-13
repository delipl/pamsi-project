#pragma once

#include <memory>
#include <string>
namespace pamsi {

struct Package {
    const std::size_t id;
    const std::string data;
    Package(const std::size_t id, const std::string &data): id{id}, data{data}{};
};

inline bool operator==(const Package& lhs, const Package& rhs) { return lhs.id == rhs.id; }
inline bool operator!=(const Package& lhs, const Package& rhs) { return !(lhs == rhs); }
inline bool operator<(const Package& lhs, const Package& rhs) { return lhs.id < rhs.id; }
inline bool operator>(const Package& lhs, const Package& rhs) { return rhs < lhs; }
inline bool operator<=(const Package& lhs, const Package& rhs) { return !(lhs > rhs); }
inline bool operator>=(const Package& lhs, const Package& rhs) { return !(lhs < rhs); }

using PackageSharedPtr = std::shared_ptr<Package>;
}  // namespace pamsi
