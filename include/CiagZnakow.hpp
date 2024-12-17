#ifndef CIAGZNAKOW_HPP
#define CIAGZNAKOW_HPP

#include "Funkcjonalnosc.hpp"
#include <iostream>

class CiagZnakow
{
public:
    CiagZnakow();

    std::string rownanie_;

    double policz();

    double liczenie(std::string& dzialanie);

    Funkcjonalnosc dzialania_Ciag_{};
};

#endif