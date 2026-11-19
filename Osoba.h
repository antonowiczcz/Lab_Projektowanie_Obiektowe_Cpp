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
    Osoba(int id, string imie, string nazwisko, string numerTelefonu);
    virtual ~Osoba() = default;

    int getId();
    string getPelneNazwisko();
};
