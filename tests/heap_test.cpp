#include "heap.tpp"

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
