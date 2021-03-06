#include "sort.hpp"

#include "csv_reader.hpp"
#include "doctest/doctest.h"
#include "timer.hpp"

#define ILE 500000u

// TEST_CASE("Merge sort") {
//     pamsi::CSVReader csv("../dane.csv", ILE);
//     auto vec = csv.data();
//     CHECK_NOTHROW(pamsi::merge_sort(vec.begin(), vec.end()));
//     auto first = vec.begin();
//     std::for_each(vec.begin() + 1, vec.end(), [first](auto &i) { CHECK(*first <= i); first; });
// }

// TEST_CASE("quick sort") {
//     pamsi::CSVReader csv("../dane.csv", ILE);
//     static auto vec = csv.data();
//     CHECK_NOTHROW(pamsi::quick_sort(vec.begin(), vec.end()));
//     auto first = vec.begin();
//     std::for_each(vec.begin() + 1, vec.end(), [&first](auto &i) { CHECK(*first <= i); first++; });
// }

TEST_CASE("insert sort") {
    pamsi::CSVReader csv("../dane.csv", ILE);
    auto vec = csv.data();
    auto first = vec.begin();
    auto i = 0u;
    pamsi::Timer timer([&vec]() {
        pamsi::bucket_sort(vec.begin(), vec.end());
    });

    std::cout  << "Duration: " << timer.check_duration().count() << std::endl;
    std::for_each(vec.begin() + 1, vec.end(), [&first](auto &i) {
        CHECK(*first <= i);
        first++;
    });
}

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