#pragma once
#include <string>

using namespace std;

class Pokoj {
private:
    int numerPokoju;
    string standard;
    double cenaZaDobe;
    string status;

public:
    bool czyWolny();
    void zablokuj();
    void zwolnij();
    double getCenaZaDobe();
    int getNumerPokoju();
};
