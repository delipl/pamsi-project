#pragma once

#include <algorithm>
#include <cmath>
#include <iostream>
#include <iterator>
#include <vector>

#include "heap.tpp"

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
it part(it begin, it end) {
    auto left = begin;
    auto pivot = begin;
    while (left != end) {
        if (*left <= *end) {
            std::iter_swap(++left, ++pivot);
        } else {
            ++left;
        }
    }
    std::iter_swap(pivot, end);
    return pivot;
}

template <typename it>
void quick_sort(it begin, it end) {
    if (std::distance(begin, end) <= 1) return;
    auto splitter = part(begin, end);
    quick_sort(begin, splitter - 1);
    quick_sort(splitter, end);
}

template <typename it>
void insert_sort(it begin, it end) {
    auto left = begin;
    while (std::prev(end) != left++) {
        auto pivot = std::prev(left);
        auto back = left;
        while (*back < *pivot and back != begin) {
            std::iter_swap(back, pivot);
            --back;
            --pivot;
        }
    }
}

template <typename it>
void print_iters(it begin, it end) {
    std::for_each(begin, end, [begin](auto &i) {
        std::cout
            << i.rate << "\t";
    });
    std::cout << "\n";
}
template <typename it>
void bucket_sort(it begin, it end) {
    auto size = std::distance(begin, end);

    auto max_value = 10.0;

    std::vector<std::vector<typename it::value_type>> buckets(max_value);

    auto left = begin;
    for (auto i = begin; i != end; ++i) {
        auto obj = *i;
        buckets[*i-1].push_back(obj);
    }
    for (auto &bucket : buckets) {
        std::copy(bucket.begin(), bucket.end(), left);
        left += bucket.size();
    }
}
}  // namespace pamsi