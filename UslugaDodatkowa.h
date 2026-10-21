#pragma once
#include <string>

using namespace std;

class UslugaDodatkowa {
protected:
    string nazwa;
    double cenaPodstawowa;

public:
    virtual ~UslugaDodatkowa() = default;

    string getNazwa();
    virtual double obliczKoszt(int liczbaDni) = 0;
};
