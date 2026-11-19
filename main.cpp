#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include "SystemHotelu.h"
#include "Gosc.h"
#include "Recepcjonista.h"
#include "Pokoj.h"
#include "Parking.h"
#include "Sniadanie.h"

using namespace std;

void inicjalizujHotel(SystemHotelu& hotel) {
    hotel.dodajPokoj(Pokoj(101, "Standard", 200.0));
    hotel.dodajPokoj(Pokoj(102, "Apartament", 450.0));
    hotel.dodajPokoj(Pokoj(103, "Standard", 220.0));
    hotel.dodajPokoj(Pokoj(201, "Deluxe", 350.0));

    hotel.dodajGoscia(Gosc(1, "Jan", "Kowalski", "501-111-222", "jan.k@hotel.pl", "ABC123456"));
    hotel.dodajGoscia(Gosc(2, "Anna", "Nowak", "502-333-444", "anna.n@hotel.pl", "XYZ789012"));

    hotel.dodajRecepcjoniste(Recepcjonista(10, "Piotr", "Wisniewski", "503-555-666", "PRAC-01", "Poranna"));
}

void menuGosc(SystemHotelu& hotel) {
    string imie, nazwisko;
    cout << "\n--- LOGOWANIE GOSCIA ---" << endl;
    cout << "Podaj imie: ";
    cin >> imie;
    cout << "Podaj nazwisko: ";
    cin >> nazwisko;

    Gosc* gosc = hotel.zalogujLubZarejestrujGoscia(imie, nazwisko);
    int idGoscia = gosc->getId();

    cout << "\nZalogowano pomyslnie: " << gosc->getPelneNazwisko() << " (ID: " << idGoscia << ")" << endl;

    int wybor = -1;
    while (wybor != 0) {
        cout << "\n========================================" << endl;
        cout << "            PANEL GOSCIA                " << endl;
        cout << " Zalogowany: " << gosc->getPelneNazwisko() << endl;
        cout << "========================================" << endl;
        cout << " [1] Wyszukaj wolne pokoje" << endl;
        cout << " [2] Zloz rezerwacje pokoju" << endl;
        cout << " [3] Sprawdz status swoich rezerwacji" << endl;
        cout << " [4] Anuluj rezerwacje" << endl;
        cout << " [0] Wyloguj i wroc do menu glownego" << endl;
        cout << "Wybierz opcje: ";
        if (!(cin >> wybor)) {
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        if (wybor == 1) {
            string dataOd, dataDo;
            cout << "Podaj date zameldowania (np. 2026-12-01): ";
            cin >> dataOd;
            cout << "Podaj date wymeldowania (np. 2026-12-04): ";
            cin >> dataDo;

            vector<Pokoj> wolne = hotel.wyszukajWolnePokoje(dataOd, dataDo);
            cout << "\n--- WOLNE POKOJE ---" << endl;
            if (wolne.empty()) {
                cout << "Brak wolnych pokoi w zadanym terminie." << endl;
            } else {
                for (const Pokoj& p : wolne) {
                    cout << " - Pokoj nr " << p.getNumerPokoju() 
                         << " (" << p.getStandard() << "), cena: " 
                         << p.getCenaZaDobe() << " PLN/doba" << endl;
                }
            }
        } else if (wybor == 2) {
            int nrPokoju;
            string dataOd, dataDo;
            cout << "Podaj numer pokoju, ktory chcesz zarezerwowac: ";
            cin >> nrPokoju;

            Pokoj* p = hotel.pobierzPokoj(nrPokoju);
            if (p == nullptr || !p->czyWolny()) {
                cout << "\n[BLAD] Pokoj nr " << nrPokoju << " nie istnieje lub jest juz zajety!" << endl;
                continue;
            }

            cout << "Podaj date przyjazdu (np. 2026-12-01): ";
            cin >> dataOd;
            cout << "Podaj date wyjazdu (np. 2026-12-04): ";
            cin >> dataDo;

            Rezerwacja rez = hotel.stworzRezerwacje(idGoscia, nrPokoju, dataOd, dataDo);
            if (rez.getIdRezerwacji() == -1) {
                cout << "\n[BLAD] Nie udalo sie utworzyc rezerwacji." << endl;
            } else {
                Rezerwacja* r = hotel.pobierzRezerwacje(rez.getIdRezerwacji());
                cout << "\n[SUKCES] Utworzono rezerwacje ID: " << r->getIdRezerwacji() 
                     << " na " << r->getLiczbaDni() << " doby (od " 
                     << r->getDataOd() << " do " << r->getDataDo() << ")." << endl;

                char dodacUsluge;
                cout << "Czy chcesz dodac miejsce parkingowe (30 PLN/doba)? (t/n): ";
                cin >> dodacUsluge;
                if (dodacUsluge == 't' || dodacUsluge == 'T') {
                    hotel.dodajUslugeDoRezerwacji(r->getIdRezerwacji(), make_unique<Parking>(15, 30.0));
                    cout << "Dodano parking do rezerwacji." << endl;
                }

                cout << "Czy chcesz dodac sniadanie (40 PLN/doba)? (t/n): ";
                cin >> dodacUsluge;
                if (dodacUsluge == 't' || dodacUsluge == 'T') {
                    hotel.dodajUslugeDoRezerwacji(r->getIdRezerwacji(), make_unique<Sniadanie>("Standardowe", 40.0));
                    cout << "Dodano sniadanie do rezerwacji." << endl;
                }

                cout << "Laczny koszt pobytu z uslugami: " << r->obliczKosztCalkowity() << " PLN" << endl;
            }
        } else if (wybor == 3) {
            cout << "\n--- TWOJE REZERWACJE (" << gosc->getPelneNazwisko() << ") ---" << endl;
            bool znaleziono = false;
            for (const Rezerwacja& r : hotel.getListaRezerwacji()) {
                if (r.getIdGoscia() == idGoscia) {
                    znaleziono = true;
                    cout << " - ID Rezerwacji: " << r.getIdRezerwacji()
                         << " | Pokoj nr: " << r.getNrPokoju()
                         << " | Termin: " << r.getDataOd() << " do " << r.getDataDo() << " (" << r.getLiczbaDni() << " doby)"
                         << " | Status: " << r.getStatus()
                         << " | Koszt: " << r.obliczKosztCalkowity() << " PLN" << endl;
                    if (!r.getUslugi().empty()) {
                        cout << "   Uslugi dodatkowe:" << endl;
                        for (UslugaDodatkowa* u : r.getUslugi()) {
                            cout << "     * " << u->getNazwa() << " (" << u->obliczKoszt(r.getLiczbaDni()) << " PLN)" << endl;
                        }
                    }
                }
            }
            if (!znaleziono) {
                cout << "Nie masz jeszcze zadnych rezerwacji." << endl;
            }
        } else if (wybor == 4) {
            int idRez;
            cout << "Podaj ID rezerwacji do anulowania: ";
            cin >> idRez;

            Rezerwacja* r = hotel.pobierzRezerwacje(idRez);
            if (r == nullptr || r->getIdGoscia() != idGoscia) {
                cout << "[BLAD] Nie znaleziono Twojej rezerwacji o ID " << idRez << endl;
            } else if (r->getStatus() != "Zarezerwowana") {
                cout << "[BLAD] Nie mozna anulowac rezerwacji o statusie: " << r->getStatus() << endl;
            } else {
                double oplata = hotel.anulujRezerwacje(idRez);
                cout << "\n[SUKCES] Rezerwacja ID " << idRez << " zostala anulowana." << endl;
                cout << "Naliczona oplata manipulacyjna: " << oplata << " PLN" << endl;
            }
        }
    }
}

void menuRecepcjonista(SystemHotelu& hotel) {
    int wybor = -1;

    while (wybor != 0) {
        cout << "\n========================================" << endl;
        cout << "         PANEL RECEPCJONISTY            " << endl;
        cout << "========================================" << endl;
        cout << " [1] Przegladaj katalog pokoi" << endl;
        cout << " [2] Zamelduj goscia" << endl;
        cout << " [3] Anuluj rezerwacje w imieniu goscia" << endl;
        cout << " [4] Wymelduj goscia i wystaw fakture" << endl;
        cout << " [0] Powrot do wyboru roli" << endl;
        cout << "Wybierz opcje: ";
        if (!(cin >> wybor)) {
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        if (wybor == 1) {
            cout << "\n--- STAN POKOI W HOTELU ---" << endl;
            for (const Pokoj& p : hotel.getKatalogPokoi()) {
                cout << " - Pokoj nr " << p.getNumerPokoju() 
                     << " | " << p.getStandard() 
                     << " | " << p.getCenaZaDobe() << " PLN/doba"
                     << " | Status: " << p.getStatus() << endl;
            }
        } else if (wybor == 2) {
            int idRez;
            cout << "Podaj ID rezerwacji do zameldowania: ";
            cin >> idRez;
            Rezerwacja* r = hotel.pobierzRezerwacje(idRez);
            if (r == nullptr) {
                cout << "[BLAD] Nie znaleziono rezerwacji o ID " << idRez << endl;
            } else if (r->getStatus() != "Zarezerwowana") {
                cout << "[BLAD] Nie mozna zameldowac rezerwacji ze statusem: " << r->getStatus() << " (wymagany: Zarezerwowana)!" << endl;
            } else {
                hotel.zameldujGoscia(idRez);
                cout << "\n[SUKCES] Gosc zameldowany." << endl;
                cout << "Status rezerwacji zmieniony na: " << r->getStatus() << endl;
                Pokoj* p = hotel.pobierzPokoj(r->getNrPokoju());
                if (p != nullptr) {
                    cout << "Status pokoju nr " << p->getNumerPokoju() << " zmieniony na: " << p->getStatus() << endl;
                }
            }
        } else if (wybor == 3) {
            int idRez;
            cout << "Podaj ID rezerwacji do anulowania: ";
            cin >> idRez;
            Rezerwacja* r = hotel.pobierzRezerwacje(idRez);
            if (r == nullptr) {
                cout << "[BLAD] Nie znaleziono rezerwacji o ID " << idRez << endl;
            } else if (r->getStatus() != "Zarezerwowana") {
                cout << "[BLAD] Nie mozna anulowac rezerwacji ze statusem: " << r->getStatus() << "!" << endl;
            } else {
                double oplata = hotel.anulujRezerwacje(idRez);
                cout << "\n[SUKCES] Rezerwacja anulowana w imieniu goscia." << endl;
                cout << "Pobrana oplata manipulacyjna: " << oplata << " PLN" << endl;
            }
        } else if (wybor == 4) {
            int idRez;
            cout << "Podaj ID rezerwacji do wymeldowania: ";
            cin >> idRez;
            Rezerwacja* r = hotel.pobierzRezerwacje(idRez);
            if (r == nullptr) {
                cout << "[BLAD] Nie znaleziono rezerwacji o ID " << idRez << endl;
            } else if (r->getStatus() != "Zameldowany") {
                cout << "[BLAD] Nie mozna wymeldowac rezerwacji ze statusem: " << r->getStatus() << " (gosc nie byl zameldowany)!" << endl;
            } else {
                Faktura fv = hotel.wymeldujGoscia(idRez);
                cout << "\n[SUKCES] Gosc zostal wymeldowany, pokoj zwolniony." << endl;
                cout << "Wystawiono fakture rozliczajaca pobyt:" << endl;
                fv.drukujFakture();
            }
        }
    }
}

int main() {
    SystemHotelu hotel;
    inicjalizujHotel(hotel);

    int rola = -1;
    while (rola != 0) {
        cout << "\n========================================================" << endl;
        cout << "           SYSTEM ZARZADZANIA HOTELEM                  " << endl;
        cout << "========================================================" << endl;
        cout << " Wybierz swoja role w systemie:" << endl;
        cout << " [1] Gosc (wyszukiwanie, rezerwacja, podglad, anulowanie)" << endl;
        cout << " [2] Recepcjonista (podglad pokoi, meldunek, faktury)" << endl;
        cout << " [0] Wyjscie z programu" << endl;
        cout << "Wybierz opcje: ";
        if (!(cin >> rola)) {
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        if (rola == 1) {
            menuGosc(hotel);
        } else if (rola == 2) {
            menuRecepcjonista(hotel);
        } else if (rola == 0) {
            cout << "\nZamykanie aplikacji. Do widzenia!" << endl;
        } else {
            cout << "Niepoprawny wybor, sprobuj ponownie." << endl;
        }
    }

    return 0;
}
