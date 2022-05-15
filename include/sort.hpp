#pragma once

#include <algorithm>
#include <iterator>
#include <vector>

namespace pamsi {
template <typename it>
void merge(it begin, it mid, it end) {
    std::vector<typename it::value_type> vec;
    vec.reserve(std::distance(begin, end));

    it left = begin;
    it right = mid;

    while (left != mid and right != end) {
        if (*right < *left) {
            vec.emplace_back(*right++);
        } else {
            vec.emplace_back(*left++);
        }
    }

    vec.insert(vec.end(), left, mid);
    vec.insert(vec.end(), right, end);

    std::move(vec.begin(), vec.end(), begin);
}
template <typename it>
void merge_sort(it left, it right) {
    auto size = std::distance(left, right);
    if (size <= 1) return;

    auto mid = std::next(left, size / 2);
    merge_sort(left, mid);
    merge_sort(mid, right);
    merge(left, mid, right);
}

}  // namespace pamsi