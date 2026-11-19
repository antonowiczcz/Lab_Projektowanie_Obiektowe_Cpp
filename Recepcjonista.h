#pragma once
#include <string>
#include "Osoba.h"

using namespace std;

class Recepcjonista : public Osoba {
private:
    string idPracownika;
    string zmiana;

public:
    Recepcjonista(int id, string imie, string nazwisko, string numerTelefonu, string idPracownika, string zmiana);

    string getIdPracownika();
    string getZmiana();
};
