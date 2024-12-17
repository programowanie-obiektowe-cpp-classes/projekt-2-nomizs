#include "Funkcjonalnosc.hpp"
#include <functional>
#include <iostream>
#include <math.h>
#include <numeric>

double Funkcjonalnosc::dodawanie(std::vector< double > skladniki)
{
    return std::accumulate(skladniki.begin(), skladniki.end(), 0.0);
};

double Funkcjonalnosc::odejmowanie(double odjemna, double odjemnik)
{
    return odjemna - odjemnik;
};

double Funkcjonalnosc::mnozenie(std::vector< double > czynniki)
{
    return std::accumulate(czynniki.begin(), czynniki.end(), 1.0, std::multiplies< double >());
};

double Funkcjonalnosc::dzielenie(double dzielna, double dzielnik)
{
    return dzielna / dzielnik;
};

int Funkcjonalnosc::silnia(int liczba)
{
    int wynik = 1;

    for (int i = liczba; i > 0; i--)
    {
        wynik *= i;
    };
    return wynik;
};

double Funkcjonalnosc::pierwiastek(double liczba, int stopien)
{
    return std::pow(liczba, 1 / stopien);
};

double Funkcjonalnosc::potegowanie(double podstawa, double wykladnik)
{
    return std::pow(podstawa, wykladnik);
};

double Funkcjonalnosc::sinus(double liczba)
{
    return std::sin(liczba);
};

double Funkcjonalnosc::cosinus(double liczba)
{
    return std::cos(liczba);
};

double Funkcjonalnosc::tangens(double liczba)
{
    return std::tan(liczba);
};