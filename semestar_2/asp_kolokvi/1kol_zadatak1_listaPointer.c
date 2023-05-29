#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
	float cijena;
	char proizvodjac[21];
	char tvrdoca[3];
}Olovka;

typedef struct Celija {
	Olovka element;
	struct Celija* sljedeca;
} Lista;

Lista* zadnjaCelija(Lista* pokLista);
void ubaci(Olovka x, Lista* pozicija_ubacivanja);
void ispisOlovke(Lista* lista);
Lista* adresaCelije(Lista* lista, int pozicija);
void obrisi(Lista* pozicija_brisanja);

int pronadjiTvrdocu(char trazeniPodatak[3], Lista* pokLista);


int main() {

	Lista* mojaLista;
	mojaLista = (Lista*)malloc(sizeof(Lista));
	mojaLista->sljedeca = NULL;
	Olovka unos;
	int i, brojOlovki;
	char odgovor, traziOlovku[3];

	do {
		printf("\n\n\n Unesite podatke za jednu olovku");
		printf("\n Unesite proizvodjaca olovke: ");
		scanf("%20s", unos.proizvodjac);

		do {
			printf("\n Unesite cijenu olovke: ");
			scanf("%f", &unos.cijena);
			if (unos.cijena <= 0)
				printf("\n Cijena mora biti veca od 0");
		} while (unos.cijena <= 0);

		printf("\n Unesite tvrdocu olovke: ");
		scanf("%2s", unos.tvrdoca);

		ubaci(unos,zadnjaCelija(mojaLista));

		printf("\n Zelite li unjeti podatke za jos jednu olovku 'D' ili 'N': ");
		scanf(" %c", &odgovor);

	} while (odgovor == 'D');

	ispisOlovke(mojaLista);

	printf("\n Koju tvrdocu olovke zelite pronaci: ");
	scanf(" %s", traziOlovku);

	brojOlovki = pronadjiTvrdocu(traziOlovku, mojaLista);

	printf("\n U listi se nalazi %d olovki tvrdoce %s ", brojOlovki, traziOlovku);


	return 0;
};


Lista* zadnjaCelija(Lista* pokLista) {
	Lista* celija;
	celija = pokLista;
	do {
		celija = celija->sljedeca;
		if (celija == NULL) return pokLista;
		if (celija->sljedeca == NULL) return celija;
	} while (celija->sljedeca != NULL);
}

void ubaci(Olovka x, Lista* pozicija_ubacivanja) {
	Lista* privremeno;
	privremeno = pozicija_ubacivanja->sljedeca;
	pozicija_ubacivanja->sljedeca = (Lista*)malloc(sizeof(Lista));
	pozicija_ubacivanja->sljedeca->element = x;
	pozicija_ubacivanja->sljedeca->sljedeca = privremeno;
}

void ispisOlovke(Lista* lista) {
	Lista* celija;
	celija = lista;
	int i=0;
	printf("\nIspis olovki:\n");
	while (celija->sljedeca != NULL) {
		celija = celija->sljedeca;
		printf("\n\t\t%d.Olovka\t\t\t %s - %s ( %.2f eura)",i+1, celija->element.proizvodjac, celija->element.tvrdoca, celija->element.cijena);
		i++;
	}
}

Lista* adresaCelije(Lista* lista, int pozicija) {
	Lista* celija;
	celija = lista;
	int brojac = 0;
	while (celija->sljedeca != NULL) {
		brojac = brojac + 1;
		if (brojac == pozicija) {
			break;
		}
		celija = celija->sljedeca;
	}
	return celija;
}

void obrisi(Lista* pozicija_brisanja) {
	Lista* privremeno;
	privremeno = pozicija_brisanja->sljedeca;
	pozicija_brisanja->sljedeca = pozicija_brisanja->sljedeca->sljedeca;
	free(privremeno);
}


int pronadjiTvrdocu(char trazeniPodatak[3], Lista* lista){
	Lista* celija;
	celija = lista;
	int brojac=0;
	printf("\nOlovke tvrdoce %s...\n",trazeniPodatak);
	
	while (celija->sljedeca != NULL) {
		celija = celija->sljedeca;
		if (strcmp(trazeniPodatak, celija->element.tvrdoca) == 0){
			printf("\n\t\t %s", celija->element.tvrdoca);
			brojac++;
		}
		else
			printf("\n U listi nema olovke te tvrdoce");
	}
	return brojac;
}