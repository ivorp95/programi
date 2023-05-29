#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct {
	char vrsta[31];
	int ocekivanoTrajanje;
}KucanskiPosao;

typedef struct Celija {
	KucanskiPosao element;
	struct Celija* sljedeca;
}Stog;

Stog* ubaci(KucanskiPosao x, Stog* pokStog);
void ispis(Stog* pokStog);
Stog* obrisi(Stog* pokStog);

int main() {
	KucanskiPosao unos;
	Stog* mojStog;
	mojStog = NULL;

	int i, broj_poslova, odradeni_posao, ukupno_trajanje=0;

	printf("\n Koliko poslova zelite pohraniti: ");
	scanf("%d", &broj_poslova);

	for (i = 0; i < broj_poslova;i++) {
		printf("\n %d. POSAO: ", i + 1);
		printf("\n\n\t Unesite vrstu posla: ");
		scanf(" %30s", unos.vrsta);

		do {
			printf("\n\t Unesite trajanje posla u minutama: ");
			scanf(" %d", &unos.ocekivanoTrajanje);
			if (unos.ocekivanoTrajanje <= 0)
				printf("\n Trajanje mora biti pozitivan broj");
		} while (unos.ocekivanoTrajanje <= 0);

		mojStog = ubaci(unos, mojStog);
	}


	printf("\n\n\n Koliko poslova zelite obaviti: ");
	scanf("%d", &odradeni_posao);
	for (i = 0;i < odradeni_posao;i++) {
		printf("\n Obavljam %d. posao ............ %20s (%d minuta)", i + 1, mojStog->element.vrsta, mojStog->element.ocekivanoTrajanje);
		ukupno_trajanje += mojStog->element.ocekivanoTrajanje;
		mojStog = obrisi(mojStog);
		
	}
	printf("\n\n Ukupno Trajanje poslova:  %d minuta", ukupno_trajanje);

	return 0;
}

Stog* ubaci(KucanskiPosao x, Stog* pokStog) {
	Stog* privremeno = (Stog*)malloc(sizeof(Stog));
	privremeno->element = x;
	privremeno->sljedeca = pokStog;
	return privremeno;
}

void ispis(Stog* pokStog) {
	Stog* celija;
	celija = pokStog;
	if (celija == NULL) {
		printf("\n\nStog je prazan!");
	}
	else {
		printf("\nStog:\n");
		while (celija != NULL) {
			printf("\n%d", celija->element.vrsta);
			celija = celija->sljedeca;
		}
	}
}

Stog* obrisi(Stog* pokStog) {
	Stog* privremeno;
	if (pokStog == NULL) {
		printf("Stog je prazan!");
		return NULL;
	}
	privremeno = pokStog->sljedeca;
	free(pokStog);
	return privremeno;
}