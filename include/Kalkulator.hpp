#ifndef KALKULATOR_HPP
#define KALKULATOR_HPP

#include "Funkcjonalnosc.hpp"

class Kalkulator
{
public:
    void wykonajDzialanie();

    Funkcjonalnosc dzialania_{};
};

#endif