#pragma once
#include "UslugaDodatkowa.h"

using namespace std;

class Parking : public UslugaDodatkowa {
private:
    int numerMiejsca;

public:
    Parking(int numerMiejsca, double cenaZaDobe = 30.0);

    double obliczKoszt(int liczbaDni) override;
    int getNumerMiejsca();
};
