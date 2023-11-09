## Osnove objektno orijentiraniog programiranja
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


    Koje mogućnosti aplikacija/sustav mora zadovoljiti:

    1. Mogućnost kreacije i prijave korisnika u sustav
    2. Izbornik sa opcijama za - pretragu/posudbu/uvid u stanje  -unos/brisanje/administriranje
    3. Pretraga po nekom podatku o filmu - godina/ime/redatelj/trajanje
    4. Ispis svih filmova u kolekciji sa brojem dostupnih za posudbu
    5. Odabir filma za posudbu klikom na gumb pokraj dostupnog filma
    6. Praćenje stanja filmova u kolekciji -količina slobodna za posudbu  -količina koja je trenutno posuđena
    7. Zapisivanje koji je film posuđen kojem korisniku
    8. Posudbom filma količina slobodnih se smanjuje



    Tko su akteri u aplikaciji/sustavu:

    1. Korisnik
    2. Administrator
    3. Baza podataka



    Kako akteri interaktiraju sa sustavom:
    
    1. Korisnik
        1.1. Prijava u sustav sa korisničkim odobrenjima
        1.2. Mogućnost pretrage/posudbe/uvida u filmove u kolekciji
        1.3. Posudbom se stanje smanjuje te se korisniku pripisuje koji je film posudio

    2. Administrator
        2.1. Prijava u sustav sa administratorskim odobrenjima
        2.2. Mogućnost pretrage/posudbe/uvida-/dodavanja/brisanja filmova u kolekciji
        2.3. Mogućnost uvida u posuđene filmove i kod kojih su korisnika
        2.4. Mogućnost uvida u popis korisnika te izmjenu(brisanje neaktivnih ili slično)

    3. Baza podataka
        3.1. Tablica filmova sa podatcima o filmovima i trenutnom kolicinom na stanju, PK filma, FK korisnika koji su posudili taj film
        3.2. Tablica korisnika sa korisnickim imenom, PK korisnika, FK filma koji je trenutno posudio
        3.3. Posudbom filma o strane korisnika stanje u količini u bazi se smanjuje za 1, a kod korisnika se vodi zapis da je posuđen 1 film
        3.4. Administrator može brisati/dodavati/izmjenjivati filmove i podatke o filmovima
        3.5. Administrator može brisati neaktivne korisnike ili one koji nevraćaju filmove
        3.6. 