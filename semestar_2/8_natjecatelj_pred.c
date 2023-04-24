#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>


typedef struct
{
	char ime[21];
	char spol;
	int godRodj;
} Natjecatelj;

typedef struct Celija
{
	Natjecatelj element;
	struct Celija* psljedeca;
} CelijaNatjecatelj;


typedef struct
{
	CelijaNatjecatelj* pizlaz;
	CelijaNatjecatelj* pulaz;
} RedNatjecatelj;


void unosNatjecatelja(Natjecatelj* pnatjecatelj);

void ubaci(Natjecatelj noviElement, RedNatjecatelj* pred);
void ispisi(RedNatjecatelj* pred);
void obrisi(RedNatjecatelj* pred);
void izmijeni(Natjecatelj izmijenjeniElement, Natjecatelj originalniElement, RedNatjecatelj* pred);
CelijaNatjecatelj* pronadjiAdresu_ime(char* imeNatjecatelja, RedNatjecatelj* pred);


int main() {

	RedNatjecatelj red_natjecatelja;
	red_natjecatelja.pulaz =(CelijaNatjecatelj*)malloc(sizeof(CelijaNatjecatelj));
	red_natjecatelja.pulaz->psljedeca = NULL;
	red_natjecatelja.pizlaz = red_natjecatelja.pulaz;

	Natjecatelj natjecatelj;

	char noviUnos;
	char imeObrisi[21];
	int i;


	do {
		unosNatjecatelja(&natjecatelj);

		ubaci(natjecatelj, &red_natjecatelja);

		printf("\n\n Zelite li unijeti podatke za novog natjecatelja? (D/N) ");
		scanf(" %c", &noviUnos);
	} while (noviUnos == 'D' || noviUnos== 'd');

	ispisi(&red_natjecatelja);
	printf("\n\n");


	obrisi(&red_natjecatelja);
	printf("\n\n\n\n ... Ispis celija reda nakon 1. brisanja elementa ... ");
	ispisi(&red_natjecatelja);

	obrisi(&red_natjecatelja);
	printf("\n\n\n\n ... Ispis celija reda nakon 2. brisanja elementa ... ");
	ispisi(&red_natjecatelja);
	
	printf("\n\n");

	return 0;
}


void unosNatjecatelja(Natjecatelj* pnatjecatelj)
{
	printf("\n Unesite ime natjecatelja: ");
	scanf("%20s", pnatjecatelj->ime);

	do {
		printf(" Unesite spol natjecatelja: ");
		scanf(" %c", &pnatjecatelj->spol);

		if (pnatjecatelj->spol != 'Z' && pnatjecatelj->spol != 'M')
			printf("\t Spol treba biti Z ili M.\n");
	} while (pnatjecatelj->spol != 'Z' && pnatjecatelj->spol != 'M');

	do {
		printf(" Unesite godinu rodjenja natjecatelja: ");
		scanf("%d", &pnatjecatelj->godRodj);

		if (pnatjecatelj->godRodj < 1930 || pnatjecatelj->godRodj > 2005)
			printf("\t Godina rodjenja treba biti u intervalu od 1930 do 2005.\n");
	} while (pnatjecatelj->godRodj < 1930 || pnatjecatelj->godRodj > 2005);
}



void ubaci(Natjecatelj noviElement, RedNatjecatelj* pred)
{
	pred->pulaz->psljedeca = (CelijaNatjecatelj*)malloc(sizeof(CelijaNatjecatelj));
	pred->pulaz = pred->pulaz->psljedeca;

	pred->pulaz->element = noviElement;
	pred->pulaz->psljedeca = NULL;
}


void ispisi(RedNatjecatelj* pred)
{
	CelijaNatjecatelj* ptrenutnaCelija = pred->pizlaz;

	int brZ = 0, brM = 0;

	while (ptrenutnaCelija->psljedeca != NULL)
	{
		ptrenutnaCelija = ptrenutnaCelija->psljedeca;
		printf("\n");
		printf("\n Ime: %s ", ptrenutnaCelija->element.ime);
		printf("\n Spol: %c ", ptrenutnaCelija->element.spol);
		printf("\n Godina rodjenja: %d ", ptrenutnaCelija->element.godRodj);

		if (ptrenutnaCelija->element.spol == 'Z')
			brZ++;
		else
			brM++;
	}

	printf("\n\n UKUPNO NATJECATELJA - Zenskih: %d; Muskih: %d.", brZ, brM);
}


void obrisi(RedNatjecatelj* pred)
{
	CelijaNatjecatelj* pcelijaZaBrisanje;

	if (pred->pizlaz == pred->pulaz)
	{
		printf("\n Red je prazan. ");
	}
	else
	{
		pcelijaZaBrisanje = pred->pizlaz;
		pred->pizlaz = pred->pizlaz->psljedeca;
		free(pcelijaZaBrisanje);
	}
}


void izmijeni(Natjecatelj izmijenjeniElement, Natjecatelj originalniElement, RedNatjecatelj* pred)
{
	CelijaNatjecatelj* ptrenutnaCelija = pred->pizlaz;

	while (ptrenutnaCelija->psljedeca != NULL)
	{
		ptrenutnaCelija = ptrenutnaCelija->psljedeca;

		if (strcmp(ptrenutnaCelija->element.ime, originalniElement.ime) == 0 &&
			ptrenutnaCelija->element.spol == originalniElement.spol &&
			ptrenutnaCelija->element.godRodj == originalniElement.godRodj)
		{
			ptrenutnaCelija->element = izmijenjeniElement;
		}
	}
}

