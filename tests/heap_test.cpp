#include "heap.tpp"
#include "package.hpp"
#include "doctest/doctest.h"

TEST_CASE("Heap Test") {
    pamsi::Heap<int> heap;

    CHECK_NOTHROW(heap.push(5));
    CHECK(heap.size() == 1);
    CHECK_NOTHROW(heap.push(4));
    CHECK_NOTHROW(heap.push(12));
    CHECK_NOTHROW(heap.push(15));
    CHECK(heap.size() == 4);
    CHECK_NOTHROW(heap.push(1));

    CHECK(heap.pop() == 1);
    CHECK(heap.size() == 4);

    CHECK(heap.pop() == 4);
    CHECK(heap.size() == 3);

    CHECK(heap.pop() == 5);
    CHECK(heap.size() == 2);

    CHECK(heap.pop() == 12);
    CHECK(heap.size() == 1);

    CHECK(heap.pop() == 15);
    CHECK(heap.size() == 0);
}


TEST_CASE("Package test"){
    CHECK_NOTHROW(pamsi::Package());
    CHECK_NOTHROW(pamsi::Package(1, "test"));
    auto x = pamsi::Package();
    auto y = pamsi::Package(1, "test");
    CHECK_NOTHROW(x = y);
    CHECK(x.id == 1);
    CHECK(x.data == "test");

    CHECK_NOTHROW(pamsi::Package(x));
}

TEST_CASE("Package heap") {
    pamsi::Heap<pamsi::Package> heap;
    CHECK_NOTHROW(heap.push(pamsi::Package(1, "blabla")));
    CHECK(heap.size() == 1);

    CHECK_NOTHROW(heap.push(pamsi::Package()));
    CHECK(heap.size() == 2);

    CHECK(heap.pop().id == 0);
    CHECK(heap.size() == 1);

    CHECK_NOTHROW(heap.pop());
    CHECK(heap.size() == 0);

    heap.push(pamsi::Package());
    CHECK(heap.size() == 1);
}