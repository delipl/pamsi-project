#include "csv_reader.hpp"
#include "doctest/doctest.h"

TEST_CASE("CSV constructor") {
    CHECK_NOTHROW(pamsi::CSVReader csv("../dane.csv", 10));
}

// TEST_CASE("CSV constructor") {
//     pamsi::CSVReader csv("../dane.csv", 10);
//     CHECK(csv.data()[0] == pamsi::Package(0, "After Life (2019– )", 9.0));
//     CHECK(csv.data()[9].rate == 2.0);

//     CHECK(csv.data()[0].data == "After Life (2019– )");
// }

TEST_CASE("CSV constructor long") {
    auto i = 962800;
    CHECK_NOTHROW(pamsi::CSVReader csv("../dane.csv", i));
    pamsi::CSVReader csv("../dane.csv", i);
    std::for_each(csv.data().begin(), csv.data().end(), [](auto &i) {
        CHECK(i != 0.0);
    });
    // pamsi::CSVReader csx("../dane.csv", i);
    // std::for_each(csx.data().begin(), csx.data().end(), [](auto &i) {
    //     CHECK(i != 0.0);
    // });

    // pamsi::CSVReader csz("../dane.csv", i);
    // std::for_each(csz.data().begin(), csz.data().end(), [](auto &i) {
    //     CHECK(i != 0.0);
    // });
}