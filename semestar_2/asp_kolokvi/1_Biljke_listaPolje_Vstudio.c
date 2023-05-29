#include <stdio.h>
#include<string.h>

#define MAX 30

typedef struct {
	char vrsta[21];
	char periodVegetacije;
	int brojKomada;
}Biljka;

typedef struct {
	int zadnji;
	Biljka elementi[MAX];
} Lista;


void ubaci(Biljka x, int pozicija_ubacivanja, Lista* pokLista);
void ispis(Lista *pokLista);
void pronadjiBiljku(char vrsta[21], Lista* pokLista);



int main() {
	Biljka unos;
	Lista mojaLista;
	mojaLista.zadnji = -1;
	
	int broj_unosa, i;
	char vrsta[21];

	printf("\n Koliko biljaka zelite unjeti (MAX 30) : ");
	scanf("%d", &broj_unosa);

	for (i = 0; i < broj_unosa;i++) {
		printf("\n\n\n Unesite naziv %d. biljke: ", i+1);
		scanf(" %20s", unos.vrsta, 21);

		do {
			printf("\n Unesite Period Vegetacije %d. biljke: ", i + 1);
			scanf(" %c", &unos.periodVegetacije,1);

			if (unos.periodVegetacije != 'T' && unos.periodVegetacije != 'J' && unos.periodVegetacije != 'D')
				printf("\n Unos mora biti 'T' za Trajnice, 'J' za Jednogodisnje ili 'D' za Dvogodisnje");

		} while (unos.periodVegetacije != 'T' && unos.periodVegetacije != 'J' && unos.periodVegetacije != 'D');

		do {
			printf("\n Unesite broj komada %d. biljke: ", i + 1);
			scanf("%d", &unos.brojKomada);
			
			if (unos.brojKomada < 0)
				printf("\n Broj komada mora biti pozitivan broj");

		} while (unos.brojKomada <= 0);

		ubaci(unos, i, &mojaLista);

	}

	printf("\n\n\n Koju biljku zelite pronaci: ");
	scanf(" %20s", vrsta, 21);
	pronadjiBiljku(vrsta, &mojaLista);


	ispis(&mojaLista);
	
	return 0;
}



void ubaci(Biljka x, int pozicija_ubacivanja, Lista* pokLista) {
	int pozicija;
	if (pokLista->zadnji >= MAX - 1)
		printf("Lista je puna!");
	else if ((pozicija_ubacivanja > pokLista->zadnji + 1) || (pozicija_ubacivanja < 0))
		printf("Pozicija ne postoji!");
	else {
		for (pozicija = pokLista->zadnji; pozicija >= pozicija_ubacivanja; pozicija--)
			pokLista->elementi[pozicija + 1] = pokLista->elementi[pozicija];
		pokLista->zadnji++;
		pokLista->elementi[pozicija_ubacivanja] = x;
	}
}

void ispis(Lista* pokLista) {
	int pozicija, Trajnice=0, Jednogod=0, Dvogod=0;

	printf("\n\nMOJE BILJKE: ");
	for (pozicija = 0; pozicija <= pokLista->zadnji; pozicija++) {
		printf("\n %d. %s",pozicija+1, pokLista->elementi[pozicija].vrsta);
		printf("\n\t\t\t vegetacijski period: %c", pokLista->elementi[pozicija].periodVegetacije);
		if (pokLista->elementi[pozicija].periodVegetacije == 'T')
			Trajnice += pokLista->elementi[pozicija].brojKomada;
		if (pokLista->elementi[pozicija].periodVegetacije == 'J')
			Jednogod += pokLista->elementi[pozicija].brojKomada;
		if (pokLista->elementi[pozicija].periodVegetacije == 'D')
			Dvogod += pokLista->elementi[pozicija].brojKomada;
		printf("\n\t\t\t\t broj komada: %d", pokLista->elementi[pozicija].brojKomada);
		if (pozicija < pokLista->zadnji)
			printf(", ");
	}
	printf("\n Ukupno komada : \n\n Trajnice = %d, \n Jednogodisnje = %d, \n Dvogodisnje = %d ", Trajnice, Jednogod, Dvogod);
}



void pronadjiBiljku(char vrsta[21], Lista* pokLista) {

	int pozicija;
	for (pozicija = 0; pozicija <= pokLista->zadnji; pozicija++) {
		if (strcmp(vrsta, pokLista->elementi[pozicija].vrsta) == 0) {
			printf("\n %d. %s", pozicija + 1, pokLista->elementi[pozicija].vrsta);
			printf("\n\t\t\t vegetacijski period: %c", pokLista->elementi[pozicija].periodVegetacije);
			printf("\n\t\t\t\t broj komada: %d", pokLista->elementi[pozicija].brojKomada);
			if (pozicija < pokLista->zadnji)
				printf(", ");
		}
	}
}