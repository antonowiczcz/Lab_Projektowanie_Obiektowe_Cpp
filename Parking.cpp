#include "Parking.h"

Parking::Parking(int numerMiejsca, double cenaZaDobe)
    : UslugaDodatkowa("Parking", cenaZaDobe), numerMiejsca(numerMiejsca) {
}

double Parking::obliczKoszt(int liczbaDni) {
    return cenaPodstawowa * liczbaDni;
}

int Parking::getNumerMiejsca() {
    return numerMiejsca;
}
