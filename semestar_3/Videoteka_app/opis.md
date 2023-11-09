# Osnove objektno orijentiraniog programiranja
# Videoteka_app

* Aplikacija mora imati:
1. Login ekran
2. CRUD operacije
3. Izvršnu Java datoteku (.jar)
* Ostale segmente koje su važni za kvalitetno izvršavanje aplikacije
* Uz aplikaciju treba odraditi i popratne aktivnosti:
1. kreiranje relacijske baze podataka na serveru
2. preuzimanje i postavljanje MySQL JDBC drivera prilikom izgradnje aplikacije
3. postaviti driver za izvršnu datoteku

# 0. Korisnicka priča - zahtjevi
    Aplikacija "Vidoeteka", applikacija za sustav videoteke sa mogućnosti prijave i registracije korisnika/admina,
    u aplikaciji se pristupa na glavni izbornik gjde su ponuđene opcije
    za pretragu/posudbu/unos/brisanje/uvid (zavisno o tipu prijavljenog korisnika)
    u stanje nekog od filmova u kolekciji. Korisnici mogu pretraživati filmove
    po nekom podatku (godina, ime, redatelj, trajanje) ili ispisati sve filmove
    koji se nalaze u kolekciji te klikom na "posudi" posuditi odabrani film,
    kod svakog filma nalazi se broj dostupnih komada za trenutnu posudbu.

# 1. ANALIZA
    1. Mogućnost kreacije i prijave korisnika u sustav
    2. Izbornik sa opcijama za - pretragu/posudbu/uvid u stanje  -unos/brisanje/administriranje
    3. Pretraga po nekom podatku o filmu - godina/ime/redatelj/trajanje
    4. Ispis svih filmova u kolekciji sa brojem dostupnih za posudbu
    5. Odabir filma za posudbu klikom na gumb pokraj dostupnog filma
    6. Praćenje stanja filmova u kolekciji -količina slobodna za posudbu  -količina koja je trenutno posuđena
    7. Zapisivanje koji je film posuđen kojem korisniku
    8. Posudbom filma količina slobodnih se smanjuje