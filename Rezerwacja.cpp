#include "Rezerwacja.h"

void Rezerwacja::dodajUsluge(UslugaDodatkowa* usluga) {
}

double Rezerwacja::obliczKosztCalkowity() {
    return 0.0;
}

double Rezerwacja::obliczOplateManipulacyjna() {
    return 0.0;
}

void Rezerwacja::zmienStatus(string nowyStatus) {
    status = nowyStatus;
}

int Rezerwacja::getIdRezerwacji() {
    return idRezerwacji;
}

string Rezerwacja::getStatus() {
    return status;
}
