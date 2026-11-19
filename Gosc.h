#pragma once
#include <string>
#include "Osoba.h"

using namespace std;

class Gosc : public Osoba {
private:
    string email;
    string numerDokumentu;

public:
    Gosc(int id, string imie, string nazwisko, string numerTelefonu, string email, string numerDokumentu);

    string getEmail();
    string getNumerDokumentu();
};
