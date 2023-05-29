#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 10


typedef struct {
	float visina;
	int tezina;
}Kutija;

typedef struct {
	int vrh;
	Kutija elementi[MAX];
} Stog;

void ubaci(Kutija x, Stog* pokStog);
int obrisiKutiju(Stog* pokStog);
void ispis(Stog* pokStog);



int main() {
	Stog  mojStog;
	mojStog.vrh = MAX;
	Kutija unos;
	int i, tezinaUkloni=0, tezinaPovrat=0;
	char odgovor[10];

	for (i = 0; i < MAX;i++) {
		printf("\n\n\n Unesite podatke za %d kutiju", i + 1);
		printf("\n Visina: ");
		scanf("%f", &unos.visina);
		printf("\n Tezina: ");
		scanf("%d", &unos.tezina);

		ubaci(unos, &mojStog);
	

		printf("\n Zelite li unjeti podatke za jos jednu Kutiju 'zelim': ");
		scanf(" %s", odgovor);

		if (strcmp("zelim", odgovor) != 0)
			break;
	} ;

	printf("\n Koliku ukupnu tezinu zelite ukloniti sa stoga? ");
	scanf("%d", &tezinaUkloni);

	do {
		tezinaPovrat += obrisiKutiju(&mojStog);
	} while (tezinaPovrat <= tezinaUkloni);



	return 0;
};



void ubaci(Kutija x, Stog* pokStog) {
	if (pokStog->vrh == 0)
		printf("Stog je pun!");
	else {
		pokStog->vrh--;
		pokStog->elementi[pokStog->vrh] = x;
	}
}

void ispis(Stog* pokStog) {
	int indeks;
	printf("\nStog:\n");

	for (indeks = pokStog->vrh; indeks <= MAX - 1; indeks++) {
		printf("%d", pokStog->elementi[indeks].tezina);

	}
}

int obrisiKutiju(Stog* pokStog) {
	int i=0,ukupnaTezina=0;

	if (pokStog->vrh == MAX)
		printf("Stog je prazan!");
	else
		printf("\n Uklonjeno je : %d kg.", pokStog->elementi[pokStog->vrh].tezina);
	ukupnaTezina = pokStog->elementi[pokStog->vrh].tezina;
	pokStog->vrh++;


	return ukupnaTezina;

}
