#pragma once
#include "UslugaDodatkowa.h"

using namespace std;

class Parking : public UslugaDodatkowa {
private:
    int numerMiejsca;

public:
    double obliczKoszt(int liczbaDni) override;
};
