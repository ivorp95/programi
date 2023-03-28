#include<stdio.h>
#include<string.h>
#define MAX 20



typedef struct{ 
    char rate;
    int number;
} Interval;


typedef struct{
    int i_last;
    Interval elements[MAX];
} List;

    
void input(Interval new_element, int i_input, List* plist);
void output(List* plist);

/*
void ispisi_v2(Lista lista);
void obrisi(int iObrisi, Lista* plista);
*/


int main() {
    
    int i,range_num;

    List list_interval;
    list_interval.i_last = -1;

    Interval input_num;

    do{
        printf("\n\thow many numbers will be in the list:");
        scanf("%d", &range_num);
            if(range_num>MAX && range_num<=0)
            printf("must be in the range 0 - 20");
    }while(range_num>MAX && range_num<=0);

    for (i = 0; i < range_num; i++) {

        printf("\n\t enter the %d. number: ",i+1);
        scanf("%d", &input_num.number);

        //scanf("%c", &enter, 1);
        input(input_num, i, &list_interval);
    }

    ispisi(&lista_nastave);
    
    return 0;
}


void ubaci(Interval new_element, int i_input, List* plist){
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


void ispisi(Lista* plista){
    int i;
    int uk_P = 0, uk_V = 0, uk_S = 0;

    for (i = 0; i <= plista->iZadnji; i++){
        printf("\n\t Datum: %s ", plista->elementi[i].datum);
        printf("\n\t vrsta: %c ", plista->elementi[i].vrsta);
        printf("\n\t Sati: %d ", plista->elementi[i].broj_sati);

        if (plista->elementi[i].vrsta == 'P')
            uk_P += plista->elementi[i].broj_sati;
        if (plista->elementi[i].vrsta == 'V')
            uk_V += plista->elementi[i].broj_sati;
        if (plista->elementi[i].vrsta == 'S')
            uk_S += plista->elementi[i].broj_sati;
    }

    printf("\t\nUkupno - Predavanja: %d; Vjezbe: %d; Semninar: %d ", uk_P,uk_V,uk_S );


}

/*  
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
*/
