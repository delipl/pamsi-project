#pragma once

#include <iostream>
#include <iterator>
#include <memory>

namespace pamsi {
template <typename T>
class Heap {
   public:
    Heap() = default;

    void push(const T &elem) {
        ++actual_size;
        if (actual_size > max_size || max_size == 0) {
            auto ptr = tab;
            tab = new T[actual_size];
            tab = ptr;
        }
        tab[actual_size - 1] = elem;

        // auto i = actual_size - 1;
        // while (i != 0 || tab[i] < tab[parent(i)]) {
        //     auto temp = tab[i];
        //     tab[i] = tab[parent(i)];
        //     tab[parent(i)] = tab[i];
        //     i = parent(i);
        // }
    }

    T pop() {
        --actual_size;
        return T();
    }

    std::size_t size() {
        return actual_size;
    }

   private:
    std::size_t actual_size;
    std::size_t max_size;

    std::size_t parent(const std::size_t &child) {
        return (child - 1) / 2;
    }

    T *tab;
};
}  // namespace pamsi