// Executables must have the following defined if the library contains
// doctest definitions. For builds with this disabled, e.g. code shipped to
// users, this can be left out.
#ifdef ENABLE_DOCTEST_IN_LIBRARY
#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest/doctest.h"
#endif

#include <stdio.h> /* printf, scanf, puts, NULL */

#include <cstdlib>  // std::rand, std::srand
#include <ctime>    // std::time
#include <iostream>
#include <string>

#include "exampleConfig.h"
#include "heap.tpp"
#include "package.hpp"
template <typename T>
void shuffle(T* arr, std::size_t n) {
    if (n > 1) {
        size_t i;
        for (i = 0; i < n - 1; i++) {
            size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
            T t = arr[j];
            arr[j] = arr[i];
            arr[i] = t;
        }
    }
}

int main() {
    std::cout << "C++ PAMSI project "
              << PROJECT_VERSION_MAJOR
              << "."
              << PROJECT_VERSION_MINOR
              << "."
              << PROJECT_VERSION_PATCH
              << "."
              << PROJECT_VERSION_TWEAK
              << std::endl;
    std::cout << "================================== \n\n\n\n";
    std::srand(std::time(NULL));

    std::string payload =
        "Droga Anno,\n"
        "stworzylismy specjalną oferte dla firm, na kompleksowa obsługe inwestycji w fotowoltaike.  "
        " Specjalizujemy sie w zakresie doboru, montazu i serwisie instalacji fotowoltaicznych, dysponujemy najnowoczesniejszymi rozwiazania, "
        "ktore zapewnia Panstwu oczekiwane rezultaty. "
        "Mozemy przygotowac dla Panstwa wstępna kalkulacje i przeanalizowac efekty mozliwe do osiagniecia. "
        "Czy jestes otwarta na wstepna rozmowe w tym temacie?\n"
        "Pozdrawiam\nJan";

    std::size_t elems = std::rand() % 8 + 4;
    std::cout << "Wiadomosc podzielono na " << elems << " czesci.\n";
    std::size_t one_size = payload.length() / elems +1;

    auto* tab = new pamsi::Package[elems];
    for (auto i = 0u; i < elems; ++i) {
        auto start = i * one_size;
        auto one_package = payload.substr(start, one_size);
        if (one_package.length() != 0) {
            tab[i] = pamsi::Package(i, one_package);
        }
    }

    shuffle(tab, elems);

    auto heap = pamsi::Heap<pamsi::Package>();
    std::cout << "=====================[Wyslanie]========================\n";

    for (auto i = 0u; i < elems; ++i) {
        std::cout << tab[i].id << "\t" << tab[i].data << std::endl;
        heap.push(tab[i]);
    }
    delete[] tab;
    std::cout << "=====================[Odebranie]========================\n";
    for (auto i = 0u; i < elems; ++i) {
        auto pop = heap.pop();
        std::cout
            <<pop.id << "\t" << pop.data << std::endl;
    }
    return 0;
}
