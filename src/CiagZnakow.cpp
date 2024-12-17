#include "CiagZnakow.hpp"
#include <algorithm>
#include <cmath>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <vector>

CiagZnakow::CiagZnakow()
{
    std::cout << "Napisz rownanie do policzenia:\n";

    std::cin >> CiagZnakow::rownanie_;

    std::cout << "Wynik rownania to: " << policz();
}

double CiagZnakow::policz()
{
    std::string rownanie = rownanie_;

    while (true)
    {
        auto nawias_zamykajacy = std::find(rownanie.begin(), rownanie.end(), ')');
        if (nawias_zamykajacy == rownanie.end())
            break;

        auto nawias_otwierajacy = std::find(std::make_reverse_iterator(nawias_zamykajacy), rownanie.rend(), '(').base();
        if (nawias_otwierajacy == rownanie.end())
            throw std::runtime_error("Nieprawidlowe nawiasy");

        std::string nawias(nawias_otwierajacy, nawias_zamykajacy);
        double      wartosc = liczenie(nawias);

        rownanie.replace(nawias_otwierajacy - 1, nawias_zamykajacy + 1, std::to_string(wartosc));
    }

    return liczenie(rownanie);
}

double CiagZnakow::liczenie(std::string& dzialanie)
{
    std::stack< double > wartosci;
    std::stack< char >   operatory;

    auto priorytet = [](char operat) {
        if (operat == '+' || operat == '-')
            return 1;
        if (operat == '*' || operat == '/')
            return 2;
        else
            return 0;
    };

    auto policzOpearator = [&](double a, double b, char operat) {
        switch (operat)
        {
        case '+': {
            std::vector< double > v{a, b};
            return dzialania_Ciag_.dodawanie(v);
        }
        case '-':
            return dzialania_Ciag_.odejmowanie(a, b);
        case '*': {
            std::vector< double > v{a, b};
            return dzialania_Ciag_.mnozenie(v);
        }
        case '/':
            if (b == 0)
                throw std::runtime_error("Dzielenie przez zero");
            return dzialania_Ciag_.dzielenie(a, b);
        default:
            throw std::runtime_error("Nieznany operator");
        }
    };

    size_t i = 0;
    while (i < dzialanie.size())
    {
        if (isdigit(dzialanie[i]))
        {
            size_t end;
            double wartosc = std::stod(dzialanie.substr(i), &end);
            wartosci.push(wartosc);
            i += end;
        }
        else if (strchr("+-*/", dzialanie[i]))
        {
            while (!operatory.empty() && priorytet(operatory.top()) >= priorytet(dzialanie[i]))
            {
                double b = wartosci.top();
                wartosci.pop();
                double a = wartosci.top();
                wartosci.pop();
                char operat = operatory.top();
                operatory.pop();
                wartosci.push(policzOpearator(a, b, operat));
            }
            operatory.push(dzialanie[i]);
            i++;
        }
        else
        {
            throw std::runtime_error("Nieprawidlowy znak w rownaniu");
        }
    }

    while (!operatory.empty())
    {
        double b = wartosci.top();
        wartosci.pop();
        double a = wartosci.top();
        wartosci.pop();
        char operat = operatory.top();
        operatory.pop();
        wartosci.push(policzOpearator(a, b, operat));
    }

    if (wartosci.size() != 1)
        throw std::runtime_error("Nieprawidlowe rownanie");
    return wartosci.top();
}