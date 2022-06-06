#include "csv_reader.hpp"
#include "sort.hpp"
#include "doctest/doctest.h"
#include "timer.hpp"
#include <algorithm>
#define ILE 960000u

TEST_CASE("bucket sort") {
    int tab[] = {10000, 50000, 100000, 200000, 320000};
    for (auto i = 0u; i < 5; ++i) {
        pamsi::CSVReader csv("../dane.csv", tab[i]);
        std::cout << "Wczytano" << std::endl;
        auto &vec = csv.data();
        pamsi::Timer timer([&vec, tab, i]() {
            std::sort(vec.begin(), vec.begin() + tab[i]);
        });

        std::cout << "Items:" << tab[i] <<"\tDuration: " << timer.check_duration().count() << std::endl;
        auto first = vec.begin();
        std::for_each(vec.begin() + 1, vec.end(), [first](auto &i) { CHECK(*first <= i); first; });
    }
}

// TEST_CASE("quick sort") {
//     pamsi::CSVReader csv("../dane.csv", ILE);
//     static auto vec = csv.data();
//     CHECK_NOTHROW(pamsi::quick_sort(vec.begin(), vec.end()));
//     auto first = vec.begin();
//     std::for_each(vec.begin() + 1, vec.end(), [&first](auto &i) { CHECK(*first <= i); first++; });
// }

// TEST_CASE("insert sort") {
//     pamsi::CSVReader csv("../dane.csv", ILE);
//     static auto vec = csv.data();
//     CHECK_NOTHROW(pamsi::insert_sort(vec.begin(), vec.end()));
//     auto first = vec.begin();
//     std::for_each(vec.begin() + 1, vec.end(), [&first](auto &i) {
//         CHECK(*first <= i);
//         first++;
//     });
// }

// TEST_CASE("buckeet sort") {
//     pamsi::CSVReader csv("../dane.csv", ILE);
//     static auto vec = csv.data();
//     auto first = vec.begin();
//     CHECK_NOTHROW(pamsi::bucket_sort(vec.begin(), vec.end(), 4));
//     std::for_each(vec.begin() + 1, vec.end(), [&first](auto &i) {
//         CHECK(*first <= i);
//         first++;
//     });
// }

// TEST_CASE("heap sort") {
//     pamsi::CSVReader csv("../dane.csv", ILE);
//     static auto vec = csv.data();
//     auto first = vec.begin();

//     CHECK_NOTHROW(pamsi::heap_sort(vec.begin(), vec.end()));
//     std::for_each(vec.begin() + 1, vec.end(), [&first](auto &i) {
//         CHECK(*first <= i);
//         first++;
//     });
// }

// TEST_CASE("intro sort") {
//     pamsi::CSVReader csv("../dane.csv", ILE);
//     static auto vec = csv.data();
//     auto first = vec.begin();

//     CHECK_NOTHROW(pamsi::intro_sort(vec.begin(), vec.end()));
//     std::for_each(vec.begin() + 1, vec.end(), [&first](auto &i) {
//         CHECK(*first <= i);
//         first++;
//     });
// }