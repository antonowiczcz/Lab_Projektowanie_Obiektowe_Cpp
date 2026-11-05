#pragma once
#include <string>
#include "UslugaDodatkowa.h"

using namespace std;

class Rezerwacja {
private:
    int idRezerwacji;
    string dataOd;
    string dataDo;
    int liczbaDni;
    string status;

public:
    void dodajUsluge(UslugaDodatkowa* usluga);
    double obliczKosztCalkowity();
    double obliczOplateManipulacyjna();
    void zmienStatus(string nowyStatus);
    int getIdRezerwacji();
    string getStatus();
};
