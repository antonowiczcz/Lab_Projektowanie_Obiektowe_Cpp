#include "Osoba.h"

Osoba::Osoba(int id, string imie, string nazwisko, string numerTelefonu)
    : id(id), imie(imie), nazwisko(nazwisko), numerTelefonu(numerTelefonu) {
}

int Osoba::getId() {
    return id;
}

string Osoba::getPelneNazwisko() {
    return imie + " " + nazwisko;
}
