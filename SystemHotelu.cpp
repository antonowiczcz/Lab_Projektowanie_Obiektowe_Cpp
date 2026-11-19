#include "SystemHotelu.h"
#include <cstdio>

int SystemHotelu::obliczLiczbeDni(string dataOd, string dataDo) {
    int y1, m1, d1, y2, m2, d2;
    // Format YYYY-MM-DD
    if (sscanf(dataOd.c_str(), "%d-%d-%d", &y1, &m1, &d1) == 3 &&
        sscanf(dataDo.c_str(), "%d-%d-%d", &y2, &m2, &d2) == 3) {
        if (y1 == y2 && m1 == m2 && d2 > d1) {
            return d2 - d1;
        }
        int dni1 = y1 * 365 + m1 * 30 + d1;
        int dni2 = y2 * 365 + m2 * 30 + d2;
        if (dni2 > dni1) return dni2 - dni1;
    }
    // Format DD.MM.YYYY
    if (sscanf(dataOd.c_str(), "%d.%d.%d", &d1, &m1, &y1) == 3 &&
        sscanf(dataDo.c_str(), "%d.%d.%d", &d2, &m2, &y2) == 3) {
        int dni1 = y1 * 365 + m1 * 30 + d1;
        int dni2 = y2 * 365 + m2 * 30 + d2;
        if (dni2 > dni1) return dni2 - dni1;
    }
    // Domyslnie 1 doba
    return 1;
}

void SystemHotelu::dodajPokoj(Pokoj pokoj) {
    katalogPokoi.push_back(pokoj);
}

void SystemHotelu::dodajGoscia(Gosc gosc) {
    listaGosci.push_back(gosc);
}

void SystemHotelu::dodajRecepcjoniste(Recepcjonista recepcjonista) {
    listaRecepcjonistow.push_back(recepcjonista);
}

vector<Pokoj> SystemHotelu::wyszukajWolnePokoje(string dataOd, string dataDo) {
    vector<Pokoj> wolne;
    for (Pokoj& pokoj : katalogPokoi) {
        if (pokoj.czyWolny()) {
            wolne.push_back(pokoj);
        }
    }
    return wolne;
}

Rezerwacja SystemHotelu::stworzRezerwacje(int idGoscia, int nrPokoju, string dataOd, string dataDo) {
    Pokoj* pokoj = pobierzPokoj(nrPokoju);
    if (pokoj != nullptr && pokoj->czyWolny()) {
        pokoj->zablokuj();
        int liczbaDni = obliczLiczbeDni(dataOd, dataDo);
        Rezerwacja nowaRezerwacja(kolejnyNumerRezerwacji++, idGoscia, nrPokoju,
                                  pokoj->getCenaZaDobe(), dataOd, dataDo, liczbaDni);
        listaRezerwacji.push_back(nowaRezerwacja);
        return listaRezerwacji.back();
    }
    // Jesli pokoj zajety, zwracamy pusta rezerwacje z id = -1
    return Rezerwacja(-1, idGoscia, nrPokoju, 0.0, dataOd, dataDo, 0);
}

void SystemHotelu::dodajUslugeDoRezerwacji(int idRezerwacji, unique_ptr<UslugaDodatkowa> usluga) {
    Rezerwacja* rez = pobierzRezerwacje(idRezerwacji);
    if (rez != nullptr && usluga != nullptr) {
        magazynUslug.push_back(move(usluga));
        rez->dodajUsluge(magazynUslug.back().get());
    }
}

bool SystemHotelu::zameldujGoscia(int idRezerwacji) {
    Rezerwacja* rez = pobierzRezerwacje(idRezerwacji);
    if (rez != nullptr && rez->getStatus() == "Zarezerwowana") {
        rez->zmienStatus("Zameldowany");
        Pokoj* pokoj = pobierzPokoj(rez->getNrPokoju());
        if (pokoj != nullptr) {
            pokoj->setStatus("Zajety");
        }
        return true;
    }
    return false;
}

double SystemHotelu::anulujRezerwacje(int idRezerwacji) {
    Rezerwacja* rez = pobierzRezerwacje(idRezerwacji);
    if (rez != nullptr && rez->getStatus() == "Zarezerwowana") {
        double oplata = rez->obliczOplateManipulacyjna();
        rez->zmienStatus("Anulowana");
        Pokoj* pokoj = pobierzPokoj(rez->getNrPokoju());
        if (pokoj != nullptr) {
            pokoj->zwolnij();
        }
        return oplata;
    }
    return -1.0; // Nie mozna anulowac (np. juz zameldowany lub anulowany)
}

Faktura SystemHotelu::wymeldujGoscia(int idRezerwacji) {
    Rezerwacja* rez = pobierzRezerwacje(idRezerwacji);
    if (rez != nullptr && rez->getStatus() == "Zameldowany") {
        rez->zmienStatus("Wymeldowany");
        Pokoj* pokoj = pobierzPokoj(rez->getNrPokoju());
        if (pokoj != nullptr) {
            pokoj->zwolnij();
        }
        double kwota = rez->obliczKosztCalkowity();
        string nrFaktury = "FV/2026/00" + to_string(kolejnyNumerFaktury++);

        string nazwaNabywcy = "Gosc #" + to_string(rez->getIdGoscia());
        Gosc* g = pobierzGoscia(rez->getIdGoscia());
        if (g != nullptr) {
            nazwaNabywcy = g->getPelneNazwisko();
        }

        return Faktura(nrFaktury, "2026-11-15", kwota, 0.0, nazwaNabywcy, rez->getNrPokoju());
    }
    return Faktura("FV/BRAK", "2026-11-15", 0.0, 0.0, "Brak", 0);
}

Gosc* SystemHotelu::zalogujLubZarejestrujGoscia(string imie, string nazwisko) {
    for (Gosc& g : listaGosci) {
        if (g.getPelneNazwisko() == imie + " " + nazwisko) {
            return &g;
        }
    }
    // Nowy gosc
    int noweId = kolejnyNumerGoscia++;
    listaGosci.push_back(Gosc(noweId, imie, nazwisko, "brak", imie + "." + nazwisko + "@hotel.pl", "DOC" + to_string(noweId)));
    return &listaGosci.back();
}

Gosc* SystemHotelu::pobierzGoscia(int idGoscia) {
    for (Gosc& g : listaGosci) {
        if (g.getId() == idGoscia) {
            return &g;
        }
    }
    return nullptr;
}

Rezerwacja* SystemHotelu::pobierzRezerwacje(int idRezerwacji) {
    for (Rezerwacja& rez : listaRezerwacji) {
        if (rez.getIdRezerwacji() == idRezerwacji) {
            return &rez;
        }
    }
    return nullptr;
}

Pokoj* SystemHotelu::pobierzPokoj(int nrPokoju) {
    for (Pokoj& pokoj : katalogPokoi) {
        if (pokoj.getNumerPokoju() == nrPokoju) {
            return &pokoj;
        }
    }
    return nullptr;
}

const vector<Pokoj>& SystemHotelu::getKatalogPokoi() const {
    return katalogPokoi;
}

const vector<Rezerwacja>& SystemHotelu::getListaRezerwacji() const {
    return listaRezerwacji;
}

const vector<Gosc>& SystemHotelu::getListaGosci() const {
    return listaGosci;
}

const vector<Recepcjonista>& SystemHotelu::getListaRecepcjonistow() const {
    return listaRecepcjonistow;
}
