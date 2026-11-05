# Przebieg Komunikatów na Diagramie Sekwencji

Diagram sekwencji przedstawia scenariusz składania rezerwacji:

## Przebieg interakcji (Krok po kroku):

1. **Inicjacja:** Aktor `Gosc` wywołuje metodę `stworzRezerwacje(idGoscia, nrPokoju, dataOd, dataDo)` skierowaną bezpośrednio do obiektu sterującego systemu (`SystemHotelu`).

2. **Weryfikacja dostępności pokoju:** System odpytuje obiekt `:Pokoj` za pomocą metody `czyWolny()`. W odpowiedzi otrzymuje flagę logiczną typu `bool` (`wolny`).

3. **Ścieżka alternatywna — Pokój niedostępny** `[wolny == false]`: Jeśli pokój jest zajęty, proces zostaje przerwany, a system zwraca do gościa komunikat o niepowodzeniu (`blad: brak dostepnosci`).

4. **Zablokowanie pokoju** `[wolny == true]`: Jeśli pokój jest dostępny, system wysyła komunikat `zablokuj()` do obiektu `:Pokoj`, rezerwując go na wybrany termin.

5. **Utworzenie rekordu rezerwacji:** System dynamicznie tworzy nową instancję obiektu `:Rezerwacja` za pomocą komunikatu `<<create>>`.

6. **Opcjonalne dołączenie usług (Opt):** Jeśli gość wybrał usługi dodatkowe, system wywołuje metodę `dodajUsluge(usluga)` na utworzonym obiekcie `:Rezerwacja`.

7. **Aktualizacja statusu:** System aktualizuje status rezerwacji, wywołując `zmienStatus("Zarezerwowana")` na obiekcie `:Rezerwacja`.

8. **Potwierdzenie:** Na zakończenie system zwraca do aktora `Gosc` gotowy obiekt `rezerwacja: Rezerwacja` jako potwierdzenie pomyślnego złożenia rezerwacji.
