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
#include "messages/message.hpp"

int main() {
    std::srand(std::time(NULL));
    std::cout << "C++ PAMSI project "
              << PROJECT_VERSION_MAJOR
              << "."
              << PROJECT_VERSION_MINOR
              << "."
              << PROJECT_VERSION_PATCH
              << "."
              << PROJECT_VERSION_TWEAK
              << std::endl;
    std::system("cat ../LICENSE");
    std::cout << "================================== \n\n\n\n";

    std::string payload =
        "Droga Anno,\n"
        "stworzylismy specjalną ofertę dla firm, na kompleksową obsługę inwestycji w fotowoltaike.  "
        " Specjalizujemy sie w zakresie doboru, montazu i serwisie instalacji fotowoltaicznych, dysponujemy najnowoczesniejszymi rozwiazania, "
        "ktore zapewnia Panstwu oczekiwane rezultaty. "
        "Mozemy przygotowac dla Panstwa wstępna kalkulacje i przeanalizowac efekty mozliwe do osiagniecia. "
        "Czy jestes otwarta na wstepna rozmowe w tym temacie?\n"
        "Pozdrawiam\nJan";

    auto elems = std::rand() % 3 + 4;
    std::cout << "Wiadomosc podzielono na " << elems << " czesci.\n";
    auto mess = pamsi::Message(payload, elems);
    for (auto i = 0u; i < mess.package_list.size(); ++i) {
        std::cout << "Package " << mess.package_list[i]->id << " :\t" << mess.package_list[i]->data << std::endl;
    }
    // Bring in the dummy class from the example source,
    // just to show that it is accessible from main.cpp.
}
