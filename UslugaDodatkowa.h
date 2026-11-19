#pragma once
#include <string>

using namespace std;

class UslugaDodatkowa {
protected:
    string nazwa;
    double cenaPodstawowa;

public:
    UslugaDodatkowa(string nazwa, double cenaPodstawowa);
    virtual ~UslugaDodatkowa() = default;

    string getNazwa();
    double getCenaPodstawowa();
    virtual double obliczKoszt(int liczbaDni) = 0;
};
