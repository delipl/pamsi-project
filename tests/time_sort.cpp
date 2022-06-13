#include <algorithm>
#include <fstream>
#include <iostream>

#include "csv_reader.hpp"
#include "doctest/doctest.h"
#include "sort.hpp"
#include "timer.hpp"
#define ILE 960000u

// TEST_CASE("merge sort") {
//     std::vector<std::size_t> tab = {10000, 100000, 200000, 300000, 400000, 500000, 600000, 800000, 962800};

//     std::ofstream myfile;
//     myfile.open("../measure.txt", std::ios::app);
//     for (auto i = 0u; i < tab.size(); ++i) {
//         pamsi::CSVReader csv("../dane.csv", tab[i]);
//         std::cout << "Wczytano" << std::endl;
//         auto &vec = csv.data();

//         std::cout << "merge Sort:" << std::endl;

//         pamsi::Timer timer([&vec]() {
//             pamsi::merge_sort(vec.begin(), vec.end());
//         });

//         myfile << "merge Sort:" << std::endl;
//         auto time = timer.check_duration().count();
//         myfile << tab[i] << ";\t" << time << std::endl;
//         std::cout << "Items: " << tab[i] << "\tDuration: " << time << std::endl;
//         auto first = vec.begin();
//         std::for_each(vec.begin() + 1, vec.end(), [first](auto &i) { CHECK(*first <= i); first; });
//     }
//     myfile.close();
// }

TEST_CASE("quick sort") {
    std::vector<std::size_t> tab = {10000, 100000, 200000, 300000, 400000, 500000, 600000, 800000, 962800};
    std::ofstream myfile;
    for (auto i = 0u; i < tab.size(); ++i) {
        pamsi::CSVReader csv("../dane.csv", tab[i]);
        std::cout << "Wczytano" << std::endl;
        auto &vec = csv.data();

        auto size = vec.size();

        //TODO: make median
        double mean = 0.0;
        std::for_each(vec.begin(), vec.end(), [&mean](auto i) {
            mean += i;
        });
        mean /= size;
        auto median = vec[(size - 1) / 2 - 1] + vec[(size - 1) / 2];
        median /= 2;
        std::cout << "średnia: " << mean <<  "\tmediana: " << median << std::endl;

    }
}

// TEST_CASE("quick sort") {
//     std::vector<std::size_t> tab = {10000, 100000, 200000, 300000, 400000, 500000, 600000, 800000, 962800};
//     std::ofstream myfile;
//     myfile.open("../measure.txt", std::ios::app);
//     for (auto i = 0u; i < tab.size(); ++i) {
//         pamsi::CSVReader csv("../dane.csv", tab[i]);
//         std::cout << "Wczytano" << std::endl;
//         auto &vec = csv.data();

//         std::cout << "quick Sort:" << std::endl;

//         pamsi::Timer timer([&vec]() {
//             pamsi::quick_sort(vec.begin(), vec.end());
//         });

//         myfile << "quick Sort:" << std::endl;
//         auto time = timer.check_duration().count();
//         myfile << tab[i] << ";\t" << time << std::endl;
//         std::cout << "Items: " << tab[i] << "\tDuration: " << time << std::endl;
//         auto first = vec.begin();
//         std::for_each(vec.begin() + 1, vec.end(), [first](auto &i) { CHECK(*first <= i); first; });
//     }
//     myfile.close();
// }

// TEST_CASE("bucket sort") {
//     std::vector<std::size_t> tab = {10000, 100000, 200000, 300000, 400000, 500000, 600000, 800000, 962800};
//     std::ofstream myfile;
//     myfile.open("../measure.txt", std::ios::app);
//     for (auto i = 0u; i < tab.size(); ++i) {
//         pamsi::CSVReader csv("../dane.csv", tab[i]);
//         std::cout << "Wczytano" << std::endl;
//         auto &vec = csv.data();

//         std::cout << "bucket Sort:" << std::endl;

//         pamsi::Timer timer([&vec]() {
//             pamsi::bucket_sort(vec.begin(), vec.end());
//         });

//         myfile << "bucket Sort:" << std::endl;
//         auto time = timer.check_duration().count();
//         myfile << tab[i] << ";\t" << time << std::endl;
//         std::cout << "Items: " << tab[i] << "\tDuration: " << time << std::endl;
//         auto first = vec.begin();
//         std::for_each(vec.begin() + 1, vec.end(), [first](auto &i) { CHECK(*first <= i); first; });
//     }
//     myfile.close();
// }

// TEST_CASE("Quick sort") {
//     int tab[] = {10000, 50000, 100000, 3000000};
//     for (auto i = 0u; i < 4; ++i) {
//         pamsi::CSVReader csv("../dane.csv", tab[i]);
//         auto &vec = csv.data();
//         std::cout << "Quick Sort:" << std::endl;

//         pamsi::Timer timer([&vec, tab, i]() {
//             pamsi::quick_sort(vec.begin(), vec.begin() + tab[i]);
//         });

//         std::cout << "Items:" << tab[i] << "\tDuration: " << timer.check_duration().count() << std::endl;
//         auto first = vec.begin();
//         std::for_each(vec.begin() + 1, vec.end(), [first](auto &i) { CHECK(*first <= i); first; });
//     }
// }

// TEST_CASE("bucket sort") {
//     int tab[] = {10000, 50000, 100000, 3200000};
//     for (auto i = 0u; i < 4; ++i) {
//         pamsi::CSVReader csv("../dane.csv", tab[i]);
//         std::cout << "Wczytano" << std::endl;
//         auto &vec = csv.data();
//         std::cout << "Bucket Sort:" << std::endl;

//         pamsi::Timer timer([&vec, tab, i]() {
//             pamsi::bucket_sort(vec.begin(), vec.begin() + tab[i]);
//         });

//         std::cout << "Items:" << tab[i] << "\tDuration: " << timer.check_duration().count() << std::endl;
//         auto first = vec.begin();
//         std::for_each(vec.begin() + 1, vec.end(), [first](auto &i) { CHECK(*first <= i); first; });
//     }
// }

// TEST_CASE("std::sort") {
//     int tab[] = {10000, 50000, 100000, 3200000};
//     for (auto i = 0u; i < 4; ++i) {
//         pamsi::CSVReader csv("../dane.csv", tab[i]);
//         std::cout << "Wczytano" << std::endl;
//         auto &vec = csv.data();

//         std::cout << "std::Sort:" << std::endl;

//         pamsi::Timer timer([&vec, tab, i]() {
//             std::sort(vec.begin(), vec.begin() + tab[i]);
//         });

//         std::cout << "Items:" << tab[i] << "\tDuration: " << timer.check_duration().count() << std::endl;
//         auto first = vec.begin();
//         std::for_each(vec.begin() + 1, vec.end(), [first](auto &i) { CHECK(*first <= i); first; });
//     }
// }


