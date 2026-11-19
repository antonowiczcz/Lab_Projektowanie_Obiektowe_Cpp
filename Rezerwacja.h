#pragma once
#include <string>
#include <vector>
#include "UslugaDodatkowa.h"

using namespace std;

class Rezerwacja {
private:
    int idRezerwacji;
    int idGoscia;
    int nrPokoju;
    double cenaPokojuZaDobe;
    string dataOd;
    string dataDo;
    int liczbaDni;
    string status;
    vector<UslugaDodatkowa*> uslugi;

public:
    Rezerwacja(int idRezerwacji, int idGoscia, int nrPokoju, double cenaPokojuZaDobe, string dataOd, string dataDo, int liczbaDni = 1);

    void dodajUsluge(UslugaDodatkowa* usluga);
    double obliczKosztCalkowity() const;
    double obliczOplateManipulacyjna() const;
    void zmienStatus(string nowyStatus);

    int getIdRezerwacji() const;
    int getIdGoscia() const;
    int getNrPokoju() const;
    int getLiczbaDni() const;
    string getDataOd() const;
    string getDataDo() const;
    string getStatus() const;
    const vector<UslugaDodatkowa*>& getUslugi() const;
};
