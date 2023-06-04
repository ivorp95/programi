/*
ASP samostalni zadatak 2023 Ivor Pangos

Potrebno je izraditi program pisan u C jeziku u kojem se podaci (minimalno 3 komponente, pri tome: minimalno 1 komponenta tip polje znakova i minimalno 1 komponenta brojevnog tipa) pohranjuju u strukturu podataka tipa RED.

Odabir načina implementacije reda (preko polja ili preko pokazivača, tj. ćelija), kao i vrste podataka za pohranu (npr. zbirka filmova, knjiga, cipela, ...) je na vama, tj. odabir je slobodan.

Program treba imati početni izbornik u kojem korisnik odabire operaciju koju želi izvršiti:
- unos novog zapisa,   
- ispis svih zapisa,
- brisanje postojećeg zapisa,
- izmjenu postojećeg zapisa,
- pretraživanje reda prema vrijednosti jedne komponente i odgovarajući ispis. Napisana funkcija ispisuje sve elemente reda koji sadrže taj podatak. Primjer: ispisuju se svi podaci o svim ljubimcima koji se zovu Max, koliko god ljubimaca tog imena u redu bilo.
Sve navedene funkcije je potrebno isprogramirati.

C kod projektnog zadatka je potrebno predati do ponedjeljka 05.06.2023. u 08:00 sati

*/



OPIS PROGRAMA -  Moja kolekcija UHD 4k Bluray filmova




izbornik u main-u (unos, ispis, brisanje, izmjena, pretrazivanje)




funkcija za pretrazivanje po imenu/godini/redatelju/trajanju(<>),?
funkcija za unos podataka u celiju
funkcija za ubacivanje celije u red
funkcija za ispis reda
funkcija za brisanje elementa u redu
funkcija za izmjenu elementa



Struktura pohranjenih podataka - Moja kolekcija UHD 4k Bluray filmova

typedef struct {
char title_eng[31]      engleski naziv filma
char director_lname[30] redatelj prezime
char director_fname[30] redatelj ime
int publication_year    godina izdavanja
int duration            trajanje filma u min
} Film;


Celija sa elementom Film i pokazivacem na sljedecu

typedef struct Celija{
    Film element
    struct Film *pnext
} FilmCelija


Red sa pokazivacima pentry(ulaz) i pexit(izlaz) na celije tipa FilmCelija sa elementima strukture Film

typedef struct{
    CelijaFilm* pentry
    CelijaFilm* pexit
}




