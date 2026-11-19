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
    Pokoj(int numerPokoju, string standard, double cenaZaDobe, string status = "Wolny");

    bool czyWolny() const;
    void zablokuj();
    void zwolnij();
    double getCenaZaDobe() const;
    int getNumerPokoju() const;
    string getStandard() const;
    string getStatus() const;
    void setStatus(string nowyStatus);
};
