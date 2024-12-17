#include "Kalkulator.hpp"
#include <iostream>

int main()
{
    std::cout
        << "Oto kalkulator tekstowy. Wpisz jedna z dostepnych komend, aby wykonac interesujace cie dzialannie :)\n"
        << "Dostepne komendy:\n"
        << "dodaj\n"
        << "odejmij\n"
        << "pomnoz\n"
        << "podziel\n"
        << "silnia\n"
        << "pierwiastek\n"
        << "potega\n"
        << "sin\n"
        << "cos\n"
        << "tan\n"
        << "pisanie - zeby uruchomic tryb wpisywania calego rownania  z operacjami + - * / oraz obsluga nawiasow\n";

    Kalkulator kalk{};

    kalk.wykonajDzialanie();
}