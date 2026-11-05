#include "Osoba.h"

int Osoba::getId() {
    return id;
}

string Osoba::getPelneNazwisko() {
    return imie + " " + nazwisko;
}
