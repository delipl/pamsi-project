#pragma once
#include <chrono>
#include <functional>

namespace pamsi {
struct Timer {
    std::function<void()> func;

    Timer(std::function<void()> func)
        : func{func} {
    }

    std::chrono::duration<double>  check_duration() {
        auto start = std::chrono::steady_clock::now();
        func();
        auto end = std::chrono::steady_clock::now();
        std::chrono::duration<double> elapsed_seconds = end - start;
        return elapsed_seconds;
    }
};
}  // namespace pamsi