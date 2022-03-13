#include "doctest/doctest.h"
#include "list/list.tpp"

TEST_CASE("List constructor"){
    pamsi::List<int> l;
    CHECK(l.size() == 0);
    CHECK_THROWS_AS(l.back(), std::underflow_error);
    CHECK_THROWS_AS(l.front(), std::overflow_error);
}

TEST_CASE("List front and back check"){
    pamsi::List<int> l;
    l.push_back(5);
    CHECK(l.size() == 1);

    pamsi::List<double> d;
    d.push_front(6.35);
    CHECK(d.size() == 1);

    l.push_front(15);
    CHECK(l.size() == 2);

    CHECK(l.front() == 15);
    CHECK(l.back() == 5); 
}