#include "Recepcjonista.h"

Recepcjonista::Recepcjonista(int id, string imie, string nazwisko, string numerTelefonu, string idPracownika, string zmiana)
    : Osoba(id, imie, nazwisko, numerTelefonu), idPracownika(idPracownika), zmiana(zmiana) {
}

string Recepcjonista::getIdPracownika() {
    return idPracownika;
}

string Recepcjonista::getZmiana() {
    return zmiana;
}
