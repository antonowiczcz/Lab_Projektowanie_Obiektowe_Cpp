#pragma once
#include <string>

using namespace std;

class Osoba {
protected:
    int id;
    string imie;
    string nazwisko;
    string numerTelefonu;

public:
    virtual ~Osoba() = default;

    int getId();
    string getPelneNazwisko();
};
