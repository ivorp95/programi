LISTA PREKO POLJA
 
-DEFINICIJA MAKSIMALNE VELIČINE POLJA-
#define MAX 20
 
-DEFINICIJA STRUKTURE LISTE-
typedef struct{
​int zadnji;
​TIP_PODATKA elementi[MAX];
} Lista;
 
-FUNKCIJE ZA LISTU PREKO POLJA-
void ubaci (TIP_PODATKA x, int pozicija_ubacivanja, Lista *pokLista) {
​int pozicija;
​if (pokLista->zadnji >= MAX-1)
​​printf("Lista je puna!");
​else if ((pozicija_ubacivanja>pokLista->zadnji+1) || (pozicija_ubacivanja<0) )
​​printf("Pozicija ne postoji!");
​else {
​​for (pozicija=pokLista->zadnji; pozicija >= pozicija_ubacivanja; pozicija--)
​​​pokLista->elementi[pozicija+1]= pokLista->elementi[pozicija];
​​pokLista->zadnji++;
​​pokLista->elementi[pozicija_ubacivanja] = x;
​}
}
 
void ispis(Lista *pokLista){
​int pozicija;
​printf("\n\nIspis liste: ");
​for (pozicija=0; pozicija <= pokLista->zadnji; pozicija++){
​​printf("%TIP_PODATKA", pokLista->elementi[pozicija]);
​​if (pozicija < pokLista->zadnji)
​​​printf(", ");
​}
}
 
void obrisi(int pozicija_brisanja, Lista *pokLista) {
​int pozicija;
​if ((pozicija_brisanja>pokLista->zadnji) || (pozicija_brisanja<0))
​​printf("Pozicija ne postoji!");
​else {
​​pokLista->zadnji--;    
​​for (pozicija=pozicija_brisanja; pozicija<=pokLista->zadnji; pozicija++)
​​​pokLista->elementi[pozicija] = pokLista->elementi[pozicija+1];
​}
}
 
INICIJALIZACIJA LISTE U MAIN-u
 
Lista mojaLista;
mojaLista.zadnji = -1;
 
POZIVI FUNKCIJA U MAIN-u
 
ubaci(PODATAK_UBACIVANJA, POZICIJA_UBACIVANJA, &mojaLista);
ispis (&mojaLista);
obrisi (POZICIJA_BRISANJA, &mojaLista);

LISTA PREKO POKAZIVAČA (zadnja ćelija)
 
#include<malloc.h>
 
-DEFINICIJA STRUKTURE LISTE-
 
typedef struct Celija {
​TIP_PODATKA element;
​struct Celija *sljedeca;
} Lista;
 
-FUNKCIJE ZA LISTU PREKO POKAZIVAČA-
 
Lista *zadnjaCelija(Lista *pokLista) {
​Lista *celija;
​celija = pokLista;
​do{
​​celija = celija->sljedeca;
​​if (celija==NULL) return pokLista;
​​if (celija->sljedeca ==NULL) return celija;
​}
​while (celija->sljedeca !=NULL);
}
 
void ubaci (TIP_PODATKA x, Lista *pozicija_ubacivanja) {
​Lista *privremeno;
​privremeno = pozicija_ubacivanja->sljedeca;
​pozicija_ubacivanja->sljedeca = (Lista*)  malloc(sizeof(Lista));
​pozicija_ubacivanja->sljedeca->element = x;
​pozicija_ubacivanja->sljedeca->sljedeca=privremeno;
}
 
void ispis (Lista *lista) {
​Lista *celija;
​celija = lista;
​printf("\nIspis liste:\n");
​while (celija->sljedeca!=NULL){
​​celija = celija->sljedeca;
​​printf("%TIP_PODATKA",celija->element);
​}
}
 
 
 
 
 
 
 
 
 
Lista *adresaCelije(Lista *lista, int pozicija) {
​Lista *celija;
​celija = lista;
​int brojac = 0;
​while (celija->sljedeca!=NULL){
​​brojac = brojac + 1;
​​if (brojac == pozicija){
​​​break;
​​}
​​celija = celija->sljedeca;
​}
​return celija;
}
 
void obrisi (Lista *pozicija_brisanja) {
​Lista *privremeno;
​privremeno = pozicija_brisanja->sljedeca;
​pozicija_brisanja->sljedeca = pozicija_brisanja->sljedeca->sljedeca;
​free(privremeno);
}
 
INICIJALIZACIJA LISTE U MAIN-u
 
Lista *mojaLista;
mojaLista = (Lista*) malloc(sizeof(Lista));
mojaLista->sljedeca = NULL;
 
POZIVI FUNKCIJA U MAIN-u
 
ubaci (PODATAK_UBACIVANJA, zadnjaCelija(mojaLista));
ispis (mojaLista);
obrisi (pozicija_brisanja);
 
 
 
LISTA PREKO POKAZIVAČA (sa pozicijom ubacivanja)
 
-razlikuje se samo u funkciji UBACI i njezinom pozivanju unutar main-a
 
void ubaci (TIP_PODATKA x,int pozicija_ubacivanja, Lista *lista) {
​Lista *privremeno, *celija;
​celija=lista;
​int brojac=0;
​int pozicija_ispravna =0;
​if(brojac==pozicija_ubacivanja){
​​pozicija_ispravna=1;
​}
​else{
​​do{
​​​celija = celija->sljedeca;
​​​brojac++;
​​​if(brojac == pozicija_ubacivanja){
​​​​pozicija_ispravna = 1;
​​​​break;
​​​}
​​}
​​while(celija->sljedeca !=NULL);
​}
​if(pozicija_ispravna == 1){
​​privremeno = celija->sljedeca;
​​celija->sljedeca = (Lista*) malloc(sizeof(Lista));
​​celija->sljedeca->element = x;
​​celija->sljedeca->sljedeca = privremeno;
​}
​else{
​​printf("Pozicija ne postoji.");
​}
}
 
POZIVI FUNKCIJE U MAIN-u
 
ubaci (PODATAK_UBACIVANJA, POZICIJA_UBACIVANJA, mojaLista);
 
RED PREKO POLJA
 
-DEFINICIJA MAKSIMALNE VELIČINE POLJA-
#define MAX 20
-DEFINICIJA STRUKTURE ZA RED PREKO POLJA-
 
typedef struct{
​TIP_PODATKA elementi[MAX];
​int izlaz;
​int ulaz;
} Red;
 
-FUNKCIJE ZA RED PREKO POLJA-
 
void ubaci(TIP_PODATKA x, Red *pokRed) {
​if ((pokRed->ulaz+1)%MAX == pokRed-> izlaz)
​​printf("Red je pun");
​else {
​​pokRed->ulaz = (pokRed->ulaz+1) % MAX;
​​pokRed->elementi[pokRed->ulaz] = x;
​}
}
 
void ispis(Red *pokRed){
​int index;
 
​printf("\n\nISPIS REDA: "); 
 
​index = (pokRed->izlaz+1) %MAX; 
​while(index != (pokRed->ulaz+1)%MAX){ 
​​printf("%TIP_PODATKA ",pokRed->elementi[index]);
​​index = (index + 1) %MAX;
​}
}
 
 
void obrisi(Red *pokRed){
​if (pokRed->izlaz == pokRed->ulaz)  
​​printf("Red je prazan");
​else pokRed->izlaz = (pokRed->izlaz+1)%MAX;
}
 
 
INICIJALIZACIJA REDA U MAIN-u
 
Red mojRed;
mojRed.izlaz = mojRed.ulaz = 0;
 
POZIVI FUNKCIJA U MAIN-u
 
ubaci (PODATAK_UBACIVANJA, &mojRed);
ispis(&mojRed);
obisi(&mojRed);

RED PREKO POKAZIVAČA
 
#include <malloc.h>
 
-DEFINICIJA STRUKTURE REDA-
 
typedef struct Celija {
​TIP_PODATKA  element;
​struct Celija *sljedeca;
} CelijaReda;
 
typedef struct {
​CelijaReda *ulaz;
​CelijaReda *izlaz;
} Red;
 
-FUNKCIJE ZA RED PREKO POKAZIVAČA-
 
void ubaci (TIP_PODATKA x, Red *pokRed) {
​pokRed->ulaz->sljedeca = (CelijaReda*) malloc (sizeof(CelijaReda));
​pokRed->ulaz = pokRed->ulaz->sljedeca;
​pokRed->ulaz->element = x;
​pokRed->ulaz->sljedeca = NULL;
}
 
void ispis (Red *pokRed) {
​CelijaReda *celija;
​if (pokRed->izlaz != pokRed->ulaz){
​​celija = pokRed->izlaz;
printf("\n\nIspis reda: \n\n");
​​while (celija->sljedeca!=NULL)
​​{
​​​celija = celija->sljedeca;
​​​printf("%TIP_PODATKA ", celija->element);
​​​
​​}​
​}​
}
 
void obrisi (Red *pokRed) {
​CelijaReda *privremeno;
​if (pokRed->ulaz == pokRed->izlaz)  
​​printf("Red je prazan");
​else {
​​privremeno = pokRed->izlaz;
​​pokRed->izlaz = pokRed->izlaz->sljedeca;
​​free(privremeno);
​}
}
 
INICIJALIZACIJA REDA U MAIN-u
 
Red mojRed;
mojRed.izlaz=mojRed.ulaz= (CelijaReda*) malloc (sizeof(CelijaReda));
 
POZIVI FUNKCIJA U MAIN-u
 
ubaci (unos, &mojRed);
ispis (&mojRed);
obrisi (&mojRed);

STOG PREKO POLJA
 
-DEFINICIJA MAKSIMALNE VELIČINE STOGA-
#define MAX 20
 
-DEFINICIJA STRUKTURE STOGA-
typedef struct{
​int vrh;
​TIP_PODATKA elementi[MAX];
} Stog;
 
-FUNKCIJE ZA STOG PREKO POLJA-
void ubaci (TIP_PODATKA x, Stog *pokStog){
​if (pokStog->vrh == 0)
​​printf("Stog je pun!");
​else {
​​pokStog->vrh--;
​​pokStog->elementi[pokStog->vrh] = x;
​}
}
 
void ispis (Stog *pokStog){
​int indeks;
​printf("\nStog:\n");
 
​for(indeks=pokStog->vrh; indeks<=MAX-1; indeks++){
​​printf("%TIP_PODATKA", pokStog->elementi[indeks]);
 
​}
}
 
void obrisi (Stog *pokStog) {
​if (pokStog->vrh==MAX)
​​printf("Stog je prazan!");
​else
​pokStog->vrh++;
}
INICIJALIZACIJA STOGA U MAIN-u
 
Stog mojStog;
mojStog.vrh=MAX;
 
POZIVI FUNKCIJA U MAIN-u
 
ubaci (unos, &mojStog);
ispis (&mojStog);
obrisi (&mojStog);

STOG PREKO POKAZIVAČA
 
#include<malloc.h>
 
DEFINICIJA STRUKTURE STOGA
 
typedef struct Celija{
​TIP_PODATKA element;
​struct Celija *sljedeca;
} Stog;  
 
FUNKCIJE ZA STOG PREKO POKAZIVAČA
Stog *ubaci (TIP_PODATKA x, Stog *pokStog){
​Stog *privremeno = (Stog*) malloc(sizeof(Stog));
​privremeno->element = x;
​privremeno->sljedeca= pokStog;
​return privremeno;
}
 
void ispis (Stog *pokStog){
​Stog *celija;
​celija = pokStog;
​if (celija == NULL) {
​​printf("\n\nStog je prazan!");
​}
​else {
​​printf("\nStog:\n");
​​while (celija != NULL) {
​​​printf("\n%TIP_PODATKA", celija->element);
​​​celija = celija->sljedeca;
​​}
​}
}
 
Stog *obrisi(Stog *pokStog) {
​Stog *privremeno;
​if (pokStog==NULL) {
​​printf ("Stog je prazan!");
​​return NULL;
​}
​privremeno = pokStog->sljedeca;      
​free(pokStog);
​return privremeno;
}
 
INICIJALIZACIJA STOGA U MAINU
 
Stog *mojStog;
mojStog = NULL;
 
POZIVI FUNKCIJA U MAINU
 
mojStog = ubaci(unos, mojStog);
ispis (mojStog);
mojStog =obrisi(mojStog);
 
 
 

RAD S DATOTEKAMA (ZA STRUKTURE PODATAKA IMPLEMENTIRANE PREKO POLJA)
 
void spremiUDatoteku(char *nazivDatoteke, TIP_STRUKTURE_PODATAKA *pokStrPodataka) {
​FILE *datoteka;
​datoteka = fopen(nazivDatoteke, "wb");
​if(datoteka == NULL) {
​​printf("Problem u otvaranju datoteke!");
​}
​else {
​​fwrite(pokStrPodataka, sizeof(*pokStrPodataka),1, datoteka);
​}    
​fclose(datoteka);    
}
 
void procitajIzDatoteke(char *nazivDatoteke, TIP_STRUKTURE_PODATAKA *pokStrPodataka) {
​FILE *datoteka;
​
​datoteka = fopen(nazivDatoteke, "rb");
​if (datoteka == NULL) {
​​printf("Problem u otvaranju datoteke!");
​}
​else {
​​fread(pokStrPodataka,sizeof(*pokStrPodataka),1,datoteka) ;
​}    
​fclose(datoteka);  
}