#include "Gosc.h"

Gosc::Gosc(int id, string imie, string nazwisko, string numerTelefonu, string email, string numerDokumentu)
    : Osoba(id, imie, nazwisko, numerTelefonu), email(email), numerDokumentu(numerDokumentu) {
}

string Gosc::getEmail() {
    return email;
}

string Gosc::getNumerDokumentu() {
    return numerDokumentu;
}
