#pragma once

#include <algorithm>
#include <limits>
#include <iostream>
#include <memory>
#include <string>

namespace pamsi {

struct Package {
    std::size_t id;
    std::string data = "";
    double rate{std::numeric_limits<double>::quiet_NaN()};

    Package() = default;
    ~Package() = default;
    Package(const std::size_t id, const std::string& data, const double rate)
        : id{id}, data{data}, rate{rate} {};

    Package(const Package& other)
        : id{other.id}, data{other.data}, rate{other.rate} {};

    operator double() const { return rate; };
};

std::istream& operator>>(std::istream& is, Package& d) {
    std::string id;
    std::string name, temp;
    std::string rate;

    if (std::getline(is, id, ',') and std::getline(is, name, ',')){
        if(name.find('"') != std::string::npos){
            std::string add;
            std::getline(is, temp, '"');
            name = name.substr(1, name.length()) + "," + temp;
            is.get();
        }
        try {
            d.id = std::stoi(id);
        } catch (const std::exception& e) {
            d.id = 0;
            throw std::runtime_error("BAD ID");
        }
        d.data = name;
    }
    if (std::getline(is, rate)) {
        try{
            d.rate = std::stod(rate);
        } catch (const std::exception& e) {
            d.rate = 0.0;
            throw std::runtime_error("BAD rate");
        }
    }

    return is;
}

std::ostream& operator<<(std::ostream& os, Package& d) {
    os << "ID: " << d.id << "\tNAME: " << d.data << "\tRATE: " << d.rate;
    return os;
}

inline bool operator==(const Package& lhs, const Package& rhs) { return lhs.rate == rhs.rate; }
inline bool operator!=(const Package& lhs, const Package& rhs) { return !(lhs == rhs); }
inline bool operator<(const Package& lhs, const Package& rhs) { return lhs.rate < rhs.rate; }
inline bool operator>(const Package& lhs, const Package& rhs) { return rhs < lhs; }
inline bool operator<=(const Package& lhs, const Package& rhs) { return !(lhs > rhs); }
inline bool operator>=(const Package& lhs, const Package& rhs) { return !(lhs < rhs); }
}  // namespace pamsi