#pragma once
#include <string>
#include "Osoba.h"

using namespace std;

class Recepcjonista : public Osoba {
private:
    string idPracownika;
    string zmiana;

public:
    string getIdPracownika();
};
