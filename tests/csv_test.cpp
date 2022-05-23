#include "csv_reader.hpp"
#include "doctest/doctest.h"
#include "sort.hpp"

TEST_CASE("CSV constructor") {
    CHECK_NOTHROW(pamsi::CSVReader csv("projekt2_dane.csv", 10));
}

TEST_CASE("CSV constructor") {
    pamsi::CSVReader csv("../projekt2_dane.csv", 10);
    CHECK(csv.data()[0] == pamsi::Package(0, "After Life (2019– )", 9.0));

    CHECK(csv.data()[9].rate == 2.0);
}

TEST_CASE("Merge sort") {
    pamsi::CSVReader csv("../projekt2_dane.csv", 10);
    auto vec = csv.data();
    CHECK_NOTHROW(pamsi::merge_sort(vec.begin(), vec.end()));
    auto first = vec.begin();
    std::for_each(vec.begin() + 1, vec.end(), [first](auto &i) { CHECK(*first <= i); first; });
}

TEST_CASE("quick sort") {
    pamsi::CSVReader csv("../projekt2_dane.csv", 14);
    static auto vec = csv.data();
    CHECK_NOTHROW(pamsi::quick_sort(vec.begin(), vec.end()));
    auto first = vec.begin();
    std::for_each(vec.begin() + 1, vec.end(), [&first](auto &i) { CHECK(*first <= i); first++; });
}

TEST_CASE("insert sort") {
    pamsi::CSVReader csv("../projekt2_dane.csv", 8);
    static auto vec = csv.data();
    auto first = vec.begin();

    CHECK_NOTHROW(pamsi::insert_sort(vec.begin(), vec.end()));
    first = vec.begin();
    std::for_each(vec.begin() + 1, vec.end(), [&first](auto &i) {
        CHECK(*first <= i);
        first++;
    });

    first = vec.begin();


    std::for_each(vec.begin(), vec.end(), [&first](auto &i) {
        std::cout
            << i.rate << "\t";
    });
    std::cout << "\n";
}