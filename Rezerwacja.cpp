#include "Rezerwacja.h"

Rezerwacja::Rezerwacja(int idRezerwacji, int idGoscia, int nrPokoju, double cenaPokojuZaDobe, string dataOd, string dataDo, int liczbaDni)
    : idRezerwacji(idRezerwacji), idGoscia(idGoscia), nrPokoju(nrPokoju),
      cenaPokojuZaDobe(cenaPokojuZaDobe), dataOd(dataOd), dataDo(dataDo),
      liczbaDni(liczbaDni), status("Zarezerwowana") {
}

void Rezerwacja::dodajUsluge(UslugaDodatkowa* usluga) {
    if (usluga != nullptr) {
        uslugi.push_back(usluga);
    }
}

double Rezerwacja::obliczKosztCalkowity() const {
    double koszt = liczbaDni * cenaPokojuZaDobe;
    for (UslugaDodatkowa* u : uslugi) {
        if (u != nullptr) {
            koszt += u->obliczKoszt(liczbaDni);
        }
    }
    return koszt;
}

double Rezerwacja::obliczOplateManipulacyjna() const {
    return obliczKosztCalkowity() * 0.20;
}

void Rezerwacja::zmienStatus(string nowyStatus) {
    status = nowyStatus;
}

int Rezerwacja::getIdRezerwacji() const {
    return idRezerwacji;
}

int Rezerwacja::getIdGoscia() const {
    return idGoscia;
}

int Rezerwacja::getNrPokoju() const {
    return nrPokoju;
}

int Rezerwacja::getLiczbaDni() const {
    return liczbaDni;
}

string Rezerwacja::getDataOd() const {
    return dataOd;
}

string Rezerwacja::getDataDo() const {
    return dataDo;
}

string Rezerwacja::getStatus() const {
    return status;
}

const vector<UslugaDodatkowa*>& Rezerwacja::getUslugi() const {
    return uslugi;
}
