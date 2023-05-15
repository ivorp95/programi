#include <stdio.h>

#define MAX 20

typedef struct {
	char nazivDvorane[50 + 1];
	float temperatura;
	float vlaznostZraka;
} Ocitanje;

typedef struct {
	int zadnji;
	Ocitanje elementi[MAX];
} Lista;

void ubaci(Ocitanje x, int pozicija_ubacivanja, Lista* pokLista);
void ispis(Lista* pokLista);

int main() {
	Lista listaOcitanja;
	Ocitanje korisnickoOcitanje;
	listaOcitanja.zadnji = -1;

	int brojOcitanja;
	for (brojOcitanja = 1; brojOcitanja < 5; brojOcitanja++) {
		printf("Ocitanje: %d", brojOcitanja);
		printf("\nUnesite naziv dvorane: ");
		scanf("%s", korisnickoOcitanje.nazivDvorane);
		printf("Unesite temperaturu: ");
		scanf("%f", &korisnickoOcitanje.temperatura);
		printf("Unesite vlaznost zraka: ");
		scanf("%f", &korisnickoOcitanje.vlaznostZraka);

		ubaci(korisnickoOcitanje, listaOcitanja.zadnji + 1, &listaOcitanja);
	}

	ispis(&listaOcitanja);

}


void ubaci(Ocitanje x, int pozicija_ubacivanja, Lista* pokLista) {
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
	int pozicija;
	printf("\n\nIspis liste: ");
	for (pozicija = 0; pozicija <= pokLista->zadnji; pozicija++) {
		printf("\n%s\t\t % .2f\t\t % .2f",
			pokLista->elementi[pozicija].nazivDvorane,
			pokLista->elementi[pozicija].temperatura,
			pokLista->elementi[pozicija].vlaznostZraka);
	}
}