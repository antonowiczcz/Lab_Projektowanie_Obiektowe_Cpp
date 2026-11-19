#pragma once
#include <string>
#include "UslugaDodatkowa.h"

using namespace std;

class Sniadanie : public UslugaDodatkowa {
private:
    string typDiety;

public:
    Sniadanie(string typDiety, double cenaZaDobe = 40.0);

    double obliczKoszt(int liczbaDni) override;
    string getTypDiety();
};
