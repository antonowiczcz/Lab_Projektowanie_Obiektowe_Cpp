#include "Pokoj.h"

Pokoj::Pokoj(int numerPokoju, string standard, double cenaZaDobe, string status)
    : numerPokoju(numerPokoju), standard(standard), cenaZaDobe(cenaZaDobe), status(status) {
}

bool Pokoj::czyWolny() const {
    return status == "Wolny";
}

void Pokoj::zablokuj() {
    status = "Zablokowany";
}

void Pokoj::zwolnij() {
    status = "Wolny";
}

double Pokoj::getCenaZaDobe() const {
    return cenaZaDobe;
}

int Pokoj::getNumerPokoju() const {
    return numerPokoju;
}

string Pokoj::getStandard() const {
    return standard;
}

string Pokoj::getStatus() const {
    return status;
}

void Pokoj::setStatus(string nowyStatus) {
    status = nowyStatus;
}
