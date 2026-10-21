#pragma once
#include <string>

using namespace std;

class Faktura {
private:
    string numerFaktury;
    string dataWystawienia;
    double kwotaLaczna;
    double oplataManipulacyjna;

public:
    double getKwotaLaczna();
    void drukujFakture();
};
