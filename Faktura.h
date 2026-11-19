#pragma once
#include <string>

using namespace std;

class Faktura {
private:
    string numerFaktury;
    string dataWystawienia;
    double kwotaLaczna;
    double oplataManipulacyjna;
    string daneGoscia;
    int nrPokoju;

public:
    Faktura(string numerFaktury, string dataWystawienia, double kwotaLaczna, double oplataManipulacyjna = 0.0, string daneGoscia = "", int nrPokoju = 0);

    double getKwotaLaczna() const;
    double getOplataManipulacyjna() const;
    string getNumerFaktury() const;
    string getDataWystawienia() const;
    string getDaneGoscia() const;
    int getNrPokoju() const;
    void drukujFakture() const;
};
