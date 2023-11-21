# Sustav za praćenje kvalitete zraka u prostorijama (učionicama) veleučilišta:

1.	Parametri koji se prate mogu biti : temperatura, vlaga zraka, tlak, razina co2, senzor dima, vrijeme, datum;
2.	Kvaliteta zraka će se računati temeljem praćenja parametara zraka;
3.	Prikaz na displeju na ulazu: razine kvalitete zraka (semafor pokazuje neke od parametara i boju)
4.	(Polu)Automatizacija za povećanje kvalitete zraka(HVAC, odvlaživač, klimatizacija, filtracija)
5.	Parametri mogu biti dostupni na mobilnim uređajima (studentima, profesorima, ostalom osoblju veleučilišta)
6.	Informiranje o kvaliteti zraka osoba koje su zadužene za održavanje razine kvalitete zraka (informiranje: razina kvalitete i parametri te postupci koji se trebaju provesti)
7.	Vremensko praćenje kvalitete zraka po dvoranama 
8.	Administriranje sustava (povezivanje dvorana i uređaja, upravljanje alarmnim porukama, definiranje trajanja prikaza na zaslonu dvorane)
9.	Alarmne poruke se šalju osobama zaduženim za održavanje razine kvalitete zraka
10.	Administrator dodjeljuje uloge korisnicima (održavanje, administrator)


Tko su akteri u sustavu (tko daje informacije i tko koristi informacije u/iz sustava):
1.	Student 
2.	Profesor
3.	Ostalo osoblje Veleučilišta
4.	Osoba zadužena za održavanje(upravljanje) kvalitete zraka
5.	Administrator

Funkcionalnosti po akterima:

1)	Student : 
a)	vidjeti kvalitetu zraka i parametre na ulaznim vratima u dvorane
b)	vidjeti kvalitetu zraka i parametre putem mobilnih uređaja


2)	Profesor: 
a)	vidjeti kvalitetu zraka i parametre na ulaznim vratima u dvorane
b)	vidjeti kvalitetu zraka i parametre putem mobilnih uređaja


3)	Ostalo osoblje:  
a)	vidjeti kvalitetu zraka i parametre na ulaznim vratima u dvorane
b)	vidjeti kvalitetu zraka i parametre putem mobilnih uređaja


4)	Osoba zadužena za održavanje:
a)	vidjeti kvalitetu zraka i parametre na ulaznim vratima u dvorane
b)	vidjeti kvalitetu zraka i parametre putem mobilnih uređaja
c)	vidjeti postupke koji se trebaju provesti za povećanje kvalitete zraka
d)	vidjeti povijesne podatke kvalitete zraka po dvoranama


5)	Administrator sustava:
a)	vidjeti kvalitetu zraka i parametre na ulaznim vratima u dvorane
b)	vidjeti kvalitetu zraka i parametre putem mobilnih uređaja
c)	vidjeti postupke koji se trebaju provesti za povećanje kvalitete zraka
d)	vidjeti povijesne podatke kvalitete zraka po dvoranama
e)	povezivati dvorane i uređaje
f)	upravljati alarmnim porukama
g)	upravljati trajanjem prikaza zaslona na dvorani
h)	dodjeljivati uloge korisnicima






Pogled na kvalitetu zraka i parametre na ulaznim vratima dvorane:
1)	Korisnik pokrene zaslon 
2)	Na zaslonu se prikazuje semafor (zeleno, narančasto i crveno), temperatura, vlažnost zraka, razina CO2, vrijeme i datum
3)	Zaslon se gasi nakon vremena kojeg je odredio administrator sustava



Pogled na kvalitetu zraka na mobilnim uređajima:
1)	Pokretanje aplikacije
2)	Prijava u aplikaciju ( AAI@Edu)
3)	Ako je prijava uspješna:
i)	Izbor dvorane
ii)	Prikaz semafora (zeleno, narančasto i crveno), temperatura, vlažnost zraka, razina CO2
iii)	Očitanje se automatski osvježava ako je došlo do promjene vrijednosti parametara
4)	Ako prijava nije uspješna prikaz poruke: „Prijava nije uspješna. Pokušajte ponovno.“

Prikaz postupaka koji se trebaju provesti za povećanje kvalitete zraka:
1)	Pokrenuti aplikaciju
2)	Prijava u aplikaciju ( AAI@Edu)
3)	Ako je prijava uspješna:
a)	Izbor dvorane sa smanjenom kvalitetom zraka
b)	Prikaz semafora (zeleno, narančasto i crveno), temperatura, vlažnost zraka, razina CO2
c)	Prikaz postupka za povećanje kvalitete zraka
4)	Ako prijava nije uspješna prikaz poruke: „Prijava nije uspješna. Pokušajte ponovno.“

Prikaz povijesnih podataka kvalitete zraka po dvoranama:
1)	Pokrenuti aplikaciju
2)	Prijava u aplikaciju ( AAI@Edu)
3)	Ako je prijava uspješna:
a)	Izbor dvorane
b)	Specifikacija filtera (Datum i vrijeme od-do, temperatura od-do, vlažnost zraka od-do, CO2 od-do) i vremenski razmak među podacima (15min, 30min, 60min, 2h, 4h, 8h, 12h, 24h)
c)	Prikaz povijesnih podataka ( Datum i vrijeme, temperatura, vlažnost zraka, CO2)
d)	Izvoz u .csv format

4)	Ako prijava nije uspješna prikaz poruke: „Prijava nije uspješna. Pokušajte ponovno.“


Povezivanje dvorane i uređaja:
1)	Pokrenuti aplikaciju
2)	Prijava u aplikaciju ( AAI@Edu)
3)	Ako je prijava uspješna i korisnik ima ulogu administratora:
a)	Dodjeljivanje identifikacije dvorani (identifikacija, naziv dvorane)
b)	Dodjeljivanje identifikacije uređaja (identifikacija)
c)	Povezivanje identifikacije dvorane i identifikacije uređaja
4)	Ako prijava nije uspješna prikaz poruke: „Prijava nije uspješna. Pokušajte ponovno.“

Upravljanje alarmnih poruka:
1)	Pokrenuti aplikaciju
2)	Prijava u aplikaciju ( AAI@Edu)
3)	Ako je prijava uspješna i korisnik ima ulogu administratora:
a)	Definiranje vremena slanja alarmnih poruka (potpuno isključivanje, definiranje vremenskog perioda po danima u tjednu)
4)	Ako prijava nije uspješna prikaz poruke: „Prijava nije uspješna. Pokušajte ponovno.“


Definiranje trajanja prikaza zaslona na dvorani:
1)	Pokrenuti aplikaciju
2)	Prijava u aplikaciju ( AAI@Edu)
3)	Ako je prijava uspješna i korisnik ima ulogu administratora:
a)	Definiranje trajanja prikaza zaslona (slobodan unos od 5sec do 5min)
4)	Ako prijava nije uspješna prikaz poruke: „Prijava nije uspješna. Pokušajte ponovno.“

Dodjela uloga korisnicima:
1)	Pokrenuti aplikaciju
2)	Prijava u aplikaciju ( AAI@Edu)
3)	Ako je prijava uspješna i korisnik ima ulogu administratora:
a)	Izbor uloge (održavanje, administrator)
b)	Prikaz korisnika koji imaju izabranu ulogu (mogućnost promjene uloge i brisanje korisnika)
c)	Dodavanje korisnika u izabranu ulogu (upis korisničkog imena) – kontrola je li korisnik već upisan
4)	Ako prijava nije uspješna prikaz poruke: „Prijava nije uspješna. Pokušajte ponovno.“





 








