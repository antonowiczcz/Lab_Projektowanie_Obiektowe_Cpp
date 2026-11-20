#include "Faktura.h"
#include <iostream>
#include <cstdio>

Faktura::Faktura(string numerFaktury, string dataWystawienia, double kwotaLaczna, double oplataManipulacyjna, string daneGoscia, int nrPokoju)
    : numerFaktury(numerFaktury), dataWystawienia(dataWystawienia),
      kwotaLaczna(kwotaLaczna), oplataManipulacyjna(oplataManipulacyjna),
      daneGoscia(daneGoscia), nrPokoju(nrPokoju) {
}

double Faktura::getKwotaLaczna() const {
    return kwotaLaczna;
}

double Faktura::getOplataManipulacyjna() const {
    return oplataManipulacyjna;
}

string Faktura::getNumerFaktury() const {
    return numerFaktury;
}

string Faktura::getDataWystawienia() const {
    return dataWystawienia;
}

string Faktura::getDaneGoscia() const {
    return daneGoscia;
}

int Faktura::getNrPokoju() const {
    return nrPokoju;
}

void Faktura::drukujFakture() const {
    cout << "========================================" << endl;
    cout << "           FAKTURA: " << numerFaktury << endl;
    cout << " Data wystawienia: " << dataWystawienia << endl;
    if (!daneGoscia.empty()) {
        cout << " Nabywca:          " << daneGoscia << endl;
    }
    if (nrPokoju > 0) {
        cout << " Dotyczy pokoju:   nr " << nrPokoju << endl;
    }
    printf(" Kwota laczna:     %.2f PLN\n", kwotaLaczna);
    if (oplataManipulacyjna > 0.0) {
        printf(" W tym oplata man.: %.2f PLN\n", oplataManipulacyjna);
    }
    cout << "========================================" << endl;
}
