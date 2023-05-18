#include <stdio.h>
#include "stdlib.h"

typedef struct{
    char naziv_dvorane[21];
    float temperatura;
    float vlaga_zraka;
}   Dvorane;

typedef struct Celija{
    Dvorane element;
    struct Celija* sljedeca;
} Lista;

Lista *zadnjaCelija(Lista *pokLista);
Lista *adresaCelije(Lista *lista, int pozicija);

void ubaci (Dvorane novi_element, Lista *pozicija_ubacivanja);
void ubaci2 (Dvorane novi_element,int pozicija_ubacivanja, Lista *lista);
void ispis (Lista *lista);
void obrisi (Lista *pozicija_brisanja);
int thi_racun(Dvorane novi_element);

int main() {
Lista *mojaLista;
mojaLista = (Lista*) malloc(sizeof(Lista));
mojaLista->sljedeca = NULL;
Dvorane moj_unos;

    for (int i=0; i<5; i++){
        printf("Unesite Naziv %d. Dvorane: ", i+1);
        scanf(" %20s", moj_unos.naziv_dvorane);
        printf("Unesite Temperaturu %d. dvorane: ", i+1);
        scanf("%f", &moj_unos.temperatura);
        printf("Unesite Vlagu zraka %d. dvorane: ", i+1);
        scanf("%f", &moj_unos.vlaga_zraka);

        ubaci (moj_unos, zadnjaCelija(mojaLista));
    };

ispis (mojaLista);



    return 0;
}

Lista *zadnjaCelija(Lista *pokLista) {
Lista *celija;
celija = pokLista;
    do{
        celija = celija->sljedeca;
        if (celija==NULL) return pokLista;
        if (celija->sljedeca ==NULL) return celija;
        }
    while (celija->sljedeca !=NULL);
return celija;
}

Lista *adresaCelije(Lista *lista, int pozicija) {
    Lista *celija;
celija = lista;
int brojac = 0;
while (celija->sljedeca!=NULL){
    brojac = brojac + 1;
    if (brojac == pozicija){
        break;
        }
    celija = celija->sljedeca;
    }
return celija;
}


void ubaci (Dvorane novi_element, Lista *pozicija_ubacivanja) {
Lista *privremeno;
    privremeno = pozicija_ubacivanja->sljedeca;
    pozicija_ubacivanja->sljedeca = (Lista*)  malloc(sizeof(Lista));
    pozicija_ubacivanja->sljedeca->element = novi_element;
    pozicija_ubacivanja->sljedeca->sljedeca=privremeno;
}


void ispis (Lista *lista) {
Lista *celija;
celija = lista;
printf("\nIspis liste:\n");
    while (celija->sljedeca!=NULL){
    celija = celija->sljedeca;
    printf("\n %s",celija->element.naziv_dvorane);
    printf("\n %.2f",celija->element.temperatura);
    printf("\n %.2f\n",celija->element.vlaga_zraka);
    printf("\n %d\n",thi_racun(celija->element));
    }
}


void obrisi (Lista *pozicija_brisanja) {
Lista *privremeno;
privremeno = pozicija_brisanja->sljedeca;
pozicija_brisanja->sljedeca = pozicija_brisanja->sljedeca->sljedeca;
free(privremeno);
}

void ubaci2 (Dvorane novi_element,int pozicija_ubacivanja, Lista *lista) {
Lista *privremeno, *celija;
celija=lista;
int brojac=0;
int pozicija_ispravna =0;
if(brojac==pozicija_ubacivanja){
    pozicija_ispravna=1;    
    }
else{
        do{
            celija = celija->sljedeca;
            brojac++;
            if(brojac == pozicija_ubacivanja){
            pozicija_ispravna = 1;
            break;
            }
        }
    while(celija->sljedeca !=NULL);
    }
    if(pozicija_ispravna == 1){
        privremeno = celija->sljedeca;
        celija->sljedeca = (Lista*) malloc(sizeof(Lista)); 
        celija->sljedeca->element = novi_element;
        celija->sljedeca->sljedeca = privremeno;
        }
    else{
        printf("Pozicija ne postoji.");
        printf(" ");
        }
}

int thi_racun(Dvorane novi_element){
    int thi=((1.8*novi_element.temperatura+32)-((0.55-0.0055*novi_element.vlaga_zraka)*(1.8*novi_element.temperatura-26)));
    return thi;
}

/*
char thi_izraz(Dvorane novi_element){
    int thi=((1.8*novi_element.temperatura+32)-((0.55-0.0055*novi_element.vlaga_zraka)*(1.8*novi_element.temperatura-26)));
    char izraz[21];
    if (0<thi && thi<71){
        izraz[20]=("UGODNO\0");
    } else if(72<thi && thi<79){
        izraz="PODNOSLJIVO\0";
    } else if(80<thi && thi<89){
        izraz="NEUGODNO\0";
    }
    return izraz[20];
}
*/
