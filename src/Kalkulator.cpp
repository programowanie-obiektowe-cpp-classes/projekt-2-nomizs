#include "Kalkulator.hpp"
#include "CiagZnakow.hpp"
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>

void Kalkulator::wykonajDzialanie()
{
    std::string komenda;
    while (true)
    {
        std::cin >> komenda;

        if (komenda == "dodaj")
        {
            std::cout << "Podaj wszystkie liczby, ktore chcesz dodac, a na koncu wpisz 'add'\n";
            std::vector< double > skladniki;
            double                skladnik;
            std::string           add;

            while (true)
            {
                if (std::cin >> skladnik)
                {
                    skladniki.push_back(skladnik);
                }
                else
                {
                    std::cin.clear();
                    std::cin >> add;

                    if (add == "add")
                    {
                        break;
                    }
                    else
                    {
                        std::cout << "Musisz podac liczbe lub 'add'!!!\n";
                    }
                }
            }

            std::cout << "Wynik dodawania to: " << dzialania_.dodawanie(skladniki);
        }
        else if (komenda == "odejmij")
        {
            std::cout << "Podaj odjemna i odjemnik!\n";
            double odjemna;
            double odjemnik;

            while (!(std::cin >> odjemna))
            {
                std::cout << "To musi byc liczba!!!\n";
            }

            while (!(std::cin >> odjemnik))
            {
                std::cout << "To musi byc liczba!!!\n";
            }

            std::cout << "Wynik odejmowania to: " << dzialania_.odejmowanie(odjemna, odjemnik);
        }
        else if (komenda == "pomnoz")
        {
            std::cout << "Podaj wszystkie liczby, ktore chcesz pomnozyc, a na koncu wpisz 'multiply'\n";
            std::vector< double > czynniki;
            double                czynnik;
            std::string           multiply;

            while (true)
            {
                if (std::cin >> czynnik)
                {
                    czynniki.push_back(czynnik);
                }
                else
                {
                    std::cin.clear();
                    std::cin >> multiply;

                    if (multiply == "multiply")
                    {
                        break;
                    }
                    else
                    {
                        std::cout << "Musisz podac liczbe lub 'multiply'!!!\n";
                    }
                }
            }

            std::cout << "Wynik mnozenia to: " << dzialania_.mnozenie(czynniki);
        }
        else if (komenda == "podziel")
        {
            std::cout << "Podaj dzielna i dzielnik!\n";
            double dzielna;
            double dzielnik;

            while (!(std::cin >> dzielna))
            {
                std::cout << "To musi byc liczba!!!\n";
            }

            while (!(std::cin >> dzielnik))
            {
                std::cout << "To musi byc liczba!!!\n";
            }

            std::cout << "Wynik dzielenia to: " << dzialania_.dzielenie(dzielna, dzielnik);
        }
        else if (komenda == "silnia")
        {
            std::cout << "Podaj liczbe calkowita nieujemna, ktorej silnie chcesz policzyc!\n";
            int liczba;

            while (!(std::cin >> liczba) || liczba < 0)
            {
                std::cout << "To musi byc liczba calkowita nieujemna!!!\n";
            }

            std::cout << "Silnia wynsoi: " << dzialania_.silnia(liczba);
        }
        else if (komenda == "pierwiastek")
        {
            std::cout << "Podaj liczbe podpierwiastkowa i stopien pierwiastka!\n";
            double liczba;
            int    stopien;

            while (!(std::cin >> liczba) || liczba < 0)
            {
                std::cout << "To musi byc liczba nieujemna!!!\n";
            }

            while (!(std::cin >> stopien) || stopien < 0)
            {
                std::cout << "To musi byc liczba calkowita nieujemna!!!\n";
            }

            std::cout << "Wynik pierwiastkowania to: " << dzialania_.pierwiastek(liczba, stopien);
        }
        else if (komenda == "potega")
        {
            std::cout << "Podaj podstawe i wykladnik!\n";
            double podstawa;
            double wykladnik;

            while (!(std::cin >> podstawa))
            {
                std::cout << "To musi byc liczba!!!\n";
            }

            while (!(std::cin >> wykladnik))
            {
                std::cout << "To musi byc liczba!!!\n";
            }

            std::cout << "Wynik potegowania to: " << dzialania_.potegowanie(podstawa, wykladnik);
        }
        else if (komenda == "sin")
        {
            std::cout << "Podaj kat w radianach\n";
            double liczba;

            while (!(std::cin >> liczba))
            {
                std::cout << "To musi byc liczba!!!\n";
            }

            std::cout << "Sinus tej liczby wynosi: " << dzialania_.sinus(liczba);
        }
        else if (komenda == "cos")
        {
            std::cout << "Podaj kat w radianach\n";
            double liczba;

            while (!(std::cin >> liczba))
            {
                std::cout << "To musi byc liczba!!!\n";
            }

            std::cout << "Cosinus tej liczby wynosi: " << dzialania_.cosinus(liczba);
        }
        else if (komenda == "tan")
        {
            std::cout << "Podaj kat w radianach\n";
            double liczba;

            while (!(std::cin >> liczba))
            {
                std::cout << "To musi byc liczba!!!\n";
            }

            std::cout << "Tangens tej liczby wynosi: " << dzialania_.sinus(liczba);
        }
        else if (komenda == "pisanie")
        {
            try
            {
                CiagZnakow ciag{};
            }
            catch (std::exception& a)
            {
                std::cout << "WYJATEK: " << a.what() << std::endl;
            }
        }
        else
        {
            std::cout << "Nie ma takiej komendy!";
        }
        std::cout << std::endl;
    }
}