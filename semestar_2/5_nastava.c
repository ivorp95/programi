#include<stdio.h>
#include<string.h>
#define MAX 20



    typedef struct{ 
    char datum[12];
    char vrsta;
    int broj_sati;
    } Nastava;


    typedef struct{
    int iZadnji;
    Nastava elementi[MAX];
    } Lista;


    void ubaci(Nastava noviElement, int iUbaci, Lista* plista);
    void ispisi(Lista* plista);
    void ispisi_v2(Lista lista);
    void obrisi(int iObrisi, Lista* plista);

    int main() {
    
    int i;
    int broj_tremina;
    char enter;

    Lista lista_nastave;
    lista_nastave.iZadnji = -1;

    Nastava nastava_unos;

    printf("\n\tKoliko termina nastave je odrzano:");
    scanf("%d", &broj_tremina);

    for (i = 0; i <= broj_tremina; i++) {

        printf("\n\t Unesite datum: ");
        scanf("%20s", nastava_unos.datum, 12);

        //scanf("%c", &enter, 1);

        do {
        printf("\t Unesite vrstu sata ( P , V , ili S ) : ");
        scanf(" %c", &nastava_unos.vrsta);

            if (nastava_unos.vrsta != 'P' || nastava_unos.vrsta != 'V' || nastava_unos.vrsta != 'S')
            printf("unesite ( P , V , ili S )");

        } while (nastava_unos.vrsta != 'P' || nastava_unos.vrsta != 'V' || nastava_unos.vrsta != 'S');


        do {
        printf("\t Unesite broj odrzanih sati > 0 : ");
        scanf("%d", &nastava_unos.broj_sati);

            if (nastava_unos.broj_sati <= 0)
            printf("Broj mora bit veci od 0");

        } while (nastava_unos.broj_sati <= 0);

    ubaci(nastava_unos, i, &lista_nastave);

    ispisi(&lista_nastave);



}

return 0;
}


void ubaci(Nastava noviElement, int iUbaci, Lista* plista){
    int i;

    if (plista->iZadnji == MAX - 1)
    printf("\n Lista je puna. ");

    else if (iUbaci > (plista->iZadnji + 1) || iUbaci < 0)
    printf("\n Indeks ubacivanja iUbaci nije ispravno definiran. ");

    else{
        for (i = plista->iZadnji; i >= iUbaci; i--){
        plista->elementi[i + 1] = plista->elementi[i];
        }
    plista->iZadnji++;
    plista->elementi[iUbaci] = noviElement;
    }
}


void ispisi(Lista* plista)
{
int i;
int uk_P = 0, uk_V = 0, uk_S = 0;

for (i = 0; i <= plista->iZadnji; i++)
{
printf("\n\t Datum: %s ", plista->elementi[i].datum);
printf("\n\t vrsta: %s ", plista->elementi[i].vrsta);
printf("\n\t dob: %d ", plista->elementi[i].broj_sati);

if (plista->elementi[i].vrsta == 'P')
uk_P += plista->elementi[i].broj_sati;
if (plista->elementi[i].vrsta == 'V')
uk_V += plista->elementi[i].broj_sati;
if (plista->elementi[i].vrsta == 'S')
uk_S += plista->elementi[i].broj_sati;

printf("Ukupno - Predavanja: %d; Vjezbe: %d; Semninar: %d ", uk_P,uk_V,uk_S );


}
}




void ispisi_v2(Lista lista)
{
int i;

for (i = 0; i <= lista.iZadnji; i++)
{
printf("\n\n %d. ELEMENT LISTE ", i + 1);
printf("\n\t ime: %s ", lista.elementi[i].ime);
printf("\n\t vrsta: %s ", lista.elementi[i].vrsta);
printf("\n\t dob: %d ", lista.elementi[i].dob);
}
}



void obrisi(int iObrisi, Lista* plista)
{
int i;

if (iObrisi > plista->iZadnji || iObrisi < 0)
printf("\n Indeks brisanja iObrisi nije ispravno definiran. ");

else
{
for (i = iObrisi; i < plista->iZadnji; i++)
{
plista->elementi[i] = plista->elementi[i + 1];
}
plista->iZadnji--;
}
}
