#pragma once
#include <string>
#include "Osoba.h"

using namespace std;

class Gosc : public Osoba {
private:
    string email;
    string numerDokumentu;

public:
    string getEmail();
};
