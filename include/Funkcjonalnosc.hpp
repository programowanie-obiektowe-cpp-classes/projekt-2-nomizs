#ifndef FUNKCJONALNOSC_HPP
#define FUNKCJONALNOSC_HPP

#include <vector>>

class Funkcjonalnosc
{
public:
    double dodawanie(std::vector< double > skladniki);

    double odejmowanie(double odjemna, double odjemnik);

    double mnozenie(std::vector< double > czynniki);

    double dzielenie(double dzielna, double dzielnik);

    int silnia(int liczba);

    double pierwiastek(double liczba, int stopien);

    double potegowanie(double podstawa, double wykladnik);

    double sinus(double liczba);

    double cosinus(double liczba);

    double tangens(double liczba);
};

#endif