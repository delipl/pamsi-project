#pragma once

#include <cstring>
#include <iostream>
#include <iterator>
#include <memory>

namespace pamsi {
template <typename T>
class Heap {
   public:
    Heap() = default;

    void push(const T elem) {
        ++actual_size;
        auto *ptr = new T[actual_size];
        memcpy(ptr, tab, (actual_size - 1) * sizeof(T));
        delete[] tab;
        tab = ptr;

        tab[actual_size - 1] = elem;

        auto i = actual_size - 1;
        while (tab[i] < tab[parent(i)]) {
            auto temp = tab[i];
            tab[i] = tab[parent(i)];
            tab[parent(i)] = temp;
            i = parent(i);
        }
    }

    T pop() {
        --actual_size;
        auto return_val = tab[0];

        tab[0] = tab[actual_size];
        auto *ptr = new T[actual_size];
        memcpy(ptr, tab, (actual_size) * sizeof(T));
        delete[] tab;
        tab = ptr;

        auto i = 0;
        while (tab[i] > tab[childs(i).first] || tab[i] > tab[childs(i).second] && i < actual_size && actual_size != 0) {
            auto j = tab[childs(i).first] > tab[childs(i).second] ? childs(i).second : childs(i).first;
            if(!j){
                break;
            }
            auto temp = tab[i];
            tab[i] = tab[j];
            tab[j] = temp;
            i = j;
        }
        return return_val;
    }

    std::size_t size() {
        return actual_size;
    }

   private:
    T *tab;
    std::size_t actual_size = 0;

    std::size_t parent(const std::size_t &child) {
        return (child - 1) / 2;
    }

    std::pair<std::size_t, std::size_t> childs(const std::size_t &parent) {
        auto first = 2 * parent + 1;
        auto second = 2 * parent + 2;
        if(first >= actual_size){
            first = 0;
            second = 0;
        }
        else if(second >= actual_size){
            second = 0;
        }
        return {first, second};
    }
};
}  // namespace pamsi