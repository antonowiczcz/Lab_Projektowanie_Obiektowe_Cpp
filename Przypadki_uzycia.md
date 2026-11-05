# Przypadki Użycia dla Systemu Zarządzania Hotelem

## 1. Wyszukaj wolne pokoje
* **Aktorzy:** Gość, Recepcjonista
* **Opis:** Użytkownik przeszukuje katalog pokoi hotelowych, podając zakres dat (data od, data do), aby sprawdzić dostępność oferty oraz poznać numer pokoju, jego standard i stawkę dobową.
* **Powiązanie z User Story:** Odpowiada pierwszej historii użytkownika (US 1: wyszukiwanie / przeglądanie).

## 2. Złóż rezerwację pokoju
* **Aktor:** Gość
* **Opis:** Gość inicjuje proces rezerwacji wybranego pokoju na określony termin. System rejestruje rezerwację przypisaną do gościa, blokuje pokój na dany okres, nadaje rezerwacji unikalny identyfikator oraz ustawia jej status początkowy.
* **Powiązanie z User Story:** Odpowiada drugiej historii użytkownika (US 2: tworzenie / transakcja).

## 3. Dołącz usługę dodatkową
* **Aktor:** brak bezpośredniego aktora - UC inicjowany przez system jako rozszerzenie UC2
* **Opis:** W trakcie procesu rezerwacji system umożliwia opcjonalne dołączenie usług dodatkowych (miejsce parkingowe lub śniadanie z określonym typem diety), co rozszerza rezerwację o polimorficzne obiekty usług i wpływa na łączny koszt pobytu.
* **Powiązanie z opisem systemu:** Wynika bezpośrednio z założeń biznesowych projektu, metody `dodajUsluge` w klasie `Rezerwacja` oraz polimorficznej hierarchii `UslugaDodatkowa` (`Parking`, `Sniadanie`).

## 4. Sprawdź status rezerwacji
* **Aktorzy:** Gość, Recepcjonista
* **Opis:** Użytkownik sprawdza bieżący stan wskazanej rezerwacji na podstawie jej identyfikatora, weryfikując aktualny status (np. zarezerwowana, zameldowany, anulowana, wymeldowany), termin pobytu oraz przypisane usługi.
* **Powiązanie z opisem systemu:** Wynika bezpośrednio z atrybutów i metod klasy `Rezerwacja` (`getIdRezerwacji()`, `getStatus()`) i służy do monitorowania cyklu życia rezerwacji przez gościa oraz obsługę hotelu.

## 5. Zamelduj gościa
* **Aktor:** Recepcjonista
* **Opis:** Recepcjonista rejestruje przyjazd gościa do hotelu na podstawie identyfikatora rezerwacji. System weryfikuje rezerwację, zmienia jej status na „Zameldowany" oraz aktualizuje stan pokoju na „Zajęty", potwierdzając przekazanie pokoju gościowi.
* **Powiązanie z User Story:** Odpowiada trzeciej historii użytkownika (US 3: zarządcza / administracyjna).

## 6. Anuluj rezerwację
* **Aktorzy:** Gość, Recepcjonista
* **Opis:** Gość lub Recepcjonista rezygnuje z zaplanowanego pobytu, podając identyfikator rezerwacji. System zmienia status rezerwacji na „Anulowana", zwalnia wcześniej zablokowany pokój, a w przypadku przekroczenia określonego czasu bezpłatnej rezygnacji nalicza opłatę manipulacyjną zgodnie z regułą biznesową. Recepcjonista może anulować rezerwację w imieniu gościa (np. podczas kontaktu telefonicznego lub przy ladzie).
* **Powiązanie z User Story:** Odpowiada czwartej historii użytkownika (US 4: logika biznesowa).

## 7. Wymelduj gościa
* **Aktor:** Recepcjonista
* **Opis:** Recepcjonista finalizuje pobyt gościa w hotelu w momencie wyjazdu. System zmienia status rezerwacji na „Wymeldowany", zwalnia zajmowany pokój, oblicza łączny koszt pobytu (doby × stawka + usługi) oraz inicjuje wystawienie dokumentu faktury.
* **Powiązanie z User Story:** Odpowiada piątej historii użytkownika (US 5: zarządcza / transakcja).

## 8. Wydrukuj fakturę
* **Aktor:** brak bezpośredniego aktora - UC inicjowany przez system jako część UC7
* **Opis:** System generuje i drukuje fakturę podsumowującą pobyt, prezentując numer faktury, datę wystawienia, łączną kwotę do zapłaty za pobyt, rozbicie na usługi dodatkowe oraz ewentualną opłatę manipulacyjną.
* **Powiązanie z opisem systemu:** Wynika bezpośrednio z klasy `Faktura`, jej atrybutów oraz metod `drukujFakture()` i `getKwotaLaczna()`. Faktura jest zwracana przez `wymeldujGoscia()` w `SystemHotelu` - nie istnieje jako osobna operacja dostępna z zewnątrz.

