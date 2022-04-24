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
    CHECK_NOTHROW(l.push_back(5));
    CHECK(l.size() == 1);

    pamsi::List<double> d;
    CHECK_NOTHROW(d.push_front(6.35));
    CHECK(d.size() == 1);

    CHECK_NOTHROW(l.push_front(15));
    CHECK(l.size() == 2);

    CHECK(l.front() == 15);
    CHECK(l.back() == 5);
}

TEST_CASE("list Operator []"){
    pamsi::List<int> l;
    CHECK_NOTHROW(l.push_back(5));
    CHECK_NOTHROW(l.push_back(4));
    CHECK_NOTHROW(l.push_back(69));
    CHECK_NOTHROW(l.push_back(13));
    CHECK_NOTHROW(l.push_back(88));

    CHECK(l[0] == 5);
    CHECK(l[1] == 4);
    CHECK(l[2] == 69);
    CHECK(l[3] == 13);
    CHECK(l[4] == 88);

    CHECK_NOTHROW(l.push_front(55));
    CHECK(l[0] == 55);
    CHECK(l.size() == 6);

   
}

TEST_CASE("Swap test"){
    pamsi::List<int> l;
    CHECK_NOTHROW(l.push_back(5));
    CHECK_NOTHROW(l.push_back(4));
    CHECK_NOTHROW(l.push_back(69));
    CHECK_NOTHROW(l.push_back(13));
    CHECK_NOTHROW(l.push_back(88));

}