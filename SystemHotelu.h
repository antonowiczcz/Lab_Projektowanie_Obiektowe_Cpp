#pragma once
#include <string>
#include <vector>
#include <memory>
#include "Gosc.h"
#include "Recepcjonista.h"
#include "Pokoj.h"
#include "Rezerwacja.h"
#include "Faktura.h"

using namespace std;

class SystemHotelu {
private:
    vector<Gosc> listaGosci;
    vector<Recepcjonista> listaRecepcjonistow;
    vector<Pokoj> katalogPokoi;
    vector<Rezerwacja> listaRezerwacji;
    vector<unique_ptr<UslugaDodatkowa>> magazynUslug;
    int kolejnyNumerRezerwacji = 1;
    int kolejnyNumerFaktury = 1;
    int kolejnyNumerGoscia = 100;

    int obliczLiczbeDni(string dataOd, string dataDo);

public:
    SystemHotelu() = default;

    void dodajPokoj(Pokoj pokoj);
    void dodajGoscia(Gosc gosc);
    void dodajRecepcjoniste(Recepcjonista recepcjonista);

    vector<Pokoj> wyszukajWolnePokoje(string dataOd, string dataDo);
    Rezerwacja stworzRezerwacje(int idGoscia, int nrPokoju, string dataOd, string dataDo);
    bool zameldujGoscia(int idRezerwacji);
    double anulujRezerwacje(int idRezerwacji);
    Faktura wymeldujGoscia(int idRezerwacji);

    void dodajUslugeDoRezerwacji(int idRezerwacji, unique_ptr<UslugaDodatkowa> usluga);
    Gosc* zalogujLubZarejestrujGoscia(string imie, string nazwisko);
    Gosc* pobierzGoscia(int idGoscia);
    Rezerwacja* pobierzRezerwacje(int idRezerwacji);
    Pokoj* pobierzPokoj(int nrPokoju);
    
    const vector<Pokoj>& getKatalogPokoi() const;
    const vector<Rezerwacja>& getListaRezerwacji() const;
    const vector<Gosc>& getListaGosci() const;
    const vector<Recepcjonista>& getListaRecepcjonistow() const;
};
