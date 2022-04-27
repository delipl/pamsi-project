#include "doctest/doctest.h"
#include "heap.tpp"

TEST_CASE("Heap constructor"){
    pamsi::Heap<int> heap;

    CHECK_NOTHROW(heap.push(5));
    CHECK(heap.size() == 1);
    CHECK_NOTHROW(heap.push(5));
    CHECK_NOTHROW(heap.push(5));
    CHECK_NOTHROW(heap.push(5));
    CHECK(heap.size() == 4);

    CHECK_NOTHROW(heap.pop());
    CHECK(heap.size() == 3);
}
