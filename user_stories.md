# 1. Opis wymagań biznesowych

System Zarządzania Hotelem wspomaga proces obsługi gości, rezerwacji oraz rozliczeń pobytu. Użytkownicy systemu dzielą się na Gości rezerwujących pokoje oraz Recepcjonistów odpowiedzialnych za obsługę pobytów. Gość może weryfikować dostępność oferty, dokonywać rezerwacji pokoju wraz z opcjonalnymi usługami dodatkowymi oraz anulować ją z uwzględnieniem opłaty manipulacyjnej. Recepcjonista rejestruje przyjazd gościa poprzez zameldowanie oraz finalizuje pobyt poprzez wymeldowanie. Na zakończenie pobytu system automatycznie generuje fakturę obejmującą czas trwania rezerwacji oraz wykorzystane usługi.

---

# 2. User Stories

### US 1: Wyszukiwanie wolnych pokoi
* **Typ operacji:** Wyszukiwanie / przeglądanie
* **Jako** Gość
* **chcę** wyszukać wolne pokoje w wybranym przedziale dat,
* **aby** sprawdzić dostępność oferty i wybrać pokój spełniający moje oczekiwania.
* **Kryterium akceptacji:** System zwraca listę dostępnych pokoi dla zadanego terminu wraz z ich numerem, standardem i stawką dobową.

---

### US 2: Rezerwacja pokoju z usługami
* **Typ operacji:** Tworzenie / transakcja
* **Jako** Gość
* **chcę** zarezerwować wybrany pokój oraz dołączyć do rezerwacji usługi dodatkowe,
* **aby** zagwarantować sobie pobyt oraz wybrane udogodnienia w określonym terminie.
* **Kryterium akceptacji:** Tworzy się rezerwacja powiązana z gościem, pokojem i usługami, a pokój zostaje zablokowany w wybranym terminie.

---

### US 3: Zameldowanie gościa
* **Typ operacji:** Zarządcza / administracyjna
* **Jako** Recepcjonista
* **chcę** zameldować gościa na podstawie numeru rezerwacji,
* **aby** potwierdzić jego przyjazd i przekazać dostęp do pokoju.
* **Kryterium akceptacji:** Status rezerwacji zmienia się na „Zameldowany”, a status pokoju na „Zajęty”.

---

### US 4: Anulowanie rezerwacji
* **Typ operacji:** Logika biznesowa
* **Jako** Gość
* **chcę** anulować złożoną rezerwację,
* **aby** zrezygnować z pobytu.
* **Kryterium akceptacji:** Pokój zostaje zwolniony, status rezerwacji zmienia się na „Anulowana”, a w przypadku późnego anulowania naliczana jest opłata manipulacyjna.

---

### US 5: Wymeldowanie i wystawienie faktury
* **Typ operacji:** Tworzenie / transakcja, Logika biznesowa
* **Jako** Recepcjonista
* **chcę** wymeldować gościa i wygenerować fakturę końcową,
* **aby** rozliczyć pobyt, pobrać opłatę i zwolnić pokój.
* **Kryterium akceptacji:** System tworzy fakturę (doby × stawka + usługi), status rezerwacji zmienia się na „Wymeldowany”, a pokój zostaje zwolniony.
