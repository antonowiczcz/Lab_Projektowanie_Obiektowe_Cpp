#pragma once
#include <string>
#include "UslugaDodatkowa.h"

using namespace std;

class Sniadanie : public UslugaDodatkowa {
private:
    string typDiety;

public:
    double obliczKoszt(int liczbaDni) override;
};
