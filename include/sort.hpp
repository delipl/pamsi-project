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
template <typename it>
void print_iters(it begin, it end) {
    std::for_each(begin, end, [begin](auto &i) {
        std::cout
            << i.rate << "\t";
    });
    std::cout << "\n";
}
template <typename it>
void bucket_sort(it begin, it end, std::size_t number_of_buckets) {
    auto size = std::distance(begin, end);
    std::vector<std::vector<typename it::value_type>> buckets(number_of_buckets);

    auto max_value = *begin;
    std::for_each(begin, end, [begin, &max_value](auto &elem) {
        max_value = elem > max_value ? elem : max_value;
    });

    for (auto i = begin; i != end; ++i) {
        int bucket = std::floor(*i / (max_value + 1) * number_of_buckets);
        auto obj = Package(*i);
        buckets[bucket].push_back(obj);
    }

    auto left = begin;
    std::for_each(buckets.begin(), buckets.end(), [&buckets, &left, &begin, &end](auto &bucket) {
        insert_sort(bucket.begin(), bucket.end());
        left += bucket.size();
    });

    auto iter = begin;
    for (auto &bucket : buckets) {
        std::copy(bucket.begin(), bucket.end(), iter);
        iter += bucket.size();
    }
}

template <typename it>
void heap_sort(it begin, it end) {
    Heap<typename it::value_type> heap;
    for (auto i = begin; i != end; ++i) {
        auto obj = Package(*i);
        heap.push(obj);
    }
    for (auto i = begin; i != end; ++i) {
        *i = heap.pop();
    }
}
}  // namespace pamsi