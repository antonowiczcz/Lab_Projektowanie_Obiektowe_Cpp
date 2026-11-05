#pragma once
#include <string>
#include <vector>
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

public:
    vector<Pokoj> wyszukajWolnePokoje(string dataOd, string dataDo);
    Rezerwacja stworzRezerwacje(int idGoscia, int nrPokoju, string dataOd, string dataDo);
    void zameldujGoscia(int idRezerwacji);
    double anulujRezerwacje(int idRezerwacji);
    Faktura wymeldujGoscia(int idRezerwacji);
};
