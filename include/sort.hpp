#pragma once

#include <algorithm>
#include <iostream>
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

template <typename it>
it part(it begin, it end, typename it::value_type pivot) {
    auto left = begin;
    auto new_pivot = begin;
    while (left != end) {
        if (pivot >= *left and new_pivot != std::prev(end)) {
            std::iter_swap(left, new_pivot++);
        }
        ++left;
    }
    return new_pivot;
}

template <typename it>
void quick_sort(it begin, it end) {
    if (std::distance(begin, end) <= 1) return;
    typename it::value_type pivot = *(std::prev(end));
    auto splitter = part(begin, end, pivot);
    quick_sort(begin, splitter);
    quick_sort(splitter, end);
}

template <typename it>
void insert_sort(it begin, it end) {
    auto left = begin;
    while (std::prev(end) != left++) {
        auto pivot = std::prev(left);
        auto back = left;
        while (*back < *pivot) {
            std::iter_swap(back--, pivot--);
        }
    }

}
}  // namespace pamsi