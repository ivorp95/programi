#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct {
	float iznosNaRacunu;
	char ime[21];
}Klijent;

typedef struct Celija {
	Klijent element;
	struct Celija* sljedeca;
} CelijaReda;

typedef struct {
	CelijaReda* ulaz;
	CelijaReda* izlaz;
} Red;

void ubaci(Klijent x, Red* pokRed);
void ispis(Red* pokRed);
void obrisi(Red* pokRed);

int main() {
	Red mojRed;
	mojRed.izlaz = mojRed.ulaz = (CelijaReda*)malloc(sizeof(CelijaReda));
	Klijent unos;
	int i,usluzivanje;
	char odgovor;

	do {
		printf("\n\n Unesite podatke za jednog klijenta..");
		printf("\n Unesite Ime klijenta: ");
		scanf("%20s", unos.ime);
		printf("\n Unesite stanje na racunu klijenta: ");
		scanf("%f", &unos.iznosNaRacunu);
		printf("\n\n zelite li unjeti podatke za jos jednog klijenta 'D' ili 'N' : ");
		scanf(" %c", &odgovor);

		ubaci(unos, &mojRed);
		if (odgovor == 'N')
			break;
	} while (1==1);

	printf("\n\n Koliko klijenata zelite usluziti: ");
	scanf("%d", &usluzivanje);
	for (i = 0;i < usluzivanje;i++) {
		obrisi(&mojRed);
	}

	printf("\n\n klijenti koje jos treba usluziti:");
	ispis(&mojRed);




	return 0;
};

void ubaci(Klijent x, Red* pokRed) {
	pokRed->ulaz->sljedeca = (CelijaReda*)malloc(sizeof(CelijaReda));
	pokRed->ulaz = pokRed->ulaz->sljedeca;
	pokRed->ulaz->element = x;
	pokRed->ulaz->sljedeca = NULL;
}

void ispis(Red* pokRed) {
	CelijaReda* celija;
	if (pokRed->izlaz != pokRed->ulaz) {
		celija = pokRed->izlaz;
		while (celija->sljedeca != NULL)
		{
			celija = celija->sljedeca;
			printf("\t\t %s ", celija->element.ime);

		}
	}
}

void obrisi(Red* pokRed) {
	CelijaReda* privremeno;
	if (pokRed->ulaz == pokRed->izlaz)
		printf("Red je prazan");
	else {
		privremeno = pokRed->izlaz;
		pokRed->izlaz = pokRed->izlaz->sljedeca;
		free(privremeno);
	}
}