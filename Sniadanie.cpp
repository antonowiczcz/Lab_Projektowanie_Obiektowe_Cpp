#include "Sniadanie.h"

Sniadanie::Sniadanie(string typDiety, double cenaZaDobe)
    : UslugaDodatkowa("Sniadanie (" + typDiety + ")", cenaZaDobe), typDiety(typDiety) {
}

double Sniadanie::obliczKoszt(int liczbaDni) {
    return cenaPodstawowa * liczbaDni;
}

string Sniadanie::getTypDiety() {
    return typDiety;
}
