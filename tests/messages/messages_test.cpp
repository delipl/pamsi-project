#include <memory>
#include "doctest/doctest.h"
#include "messages/message.hpp"

TEST_CASE("Package constructor"){
    pamsi::Package package = {1, "first package"};
    CHECK((package.id == 1, package.data == "first package") == true);
    CHECK((package.id == 2, package.data == "second package") == false);
}

TEST_CASE("Package operators"){
    pamsi::Package p1 = {1, "first package"};
    pamsi::Package p2 = {1, "first but second package"};
    pamsi::Package p3 = {3, "third package"};
    pamsi::Package p4 = {4, "forth package"};
    CHECK(p1 == p2);
    CHECK(p1 <= p2);
    CHECK(p2 >= p2);
    CHECK(p1 < p3);
    CHECK(p3 > p2);
    CHECK_FALSE(p3 < p1);
}

TEST_CASE("Message constructor"){
    
}