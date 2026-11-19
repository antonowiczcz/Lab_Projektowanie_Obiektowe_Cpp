#include "UslugaDodatkowa.h"

UslugaDodatkowa::UslugaDodatkowa(string nazwa, double cenaPodstawowa)
    : nazwa(nazwa), cenaPodstawowa(cenaPodstawowa) {
}

string UslugaDodatkowa::getNazwa() {
    return nazwa;
}

double UslugaDodatkowa::getCenaPodstawowa() {
    return cenaPodstawowa;
}
