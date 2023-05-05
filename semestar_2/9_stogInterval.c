#include<stdio.h>
#include<string.h>
#define MAX 20


typedef struct
{
	int broj;
	char odnos;
} Interval;

typedef struct
{
	int iVrh;
	Interval elementi[MAX];
} Stog;


void ubaci(Interval noviElement, Stog* pstog);
void ispisi(Stog* pstog);
void obrisi(Stog* pstog);
void spremiUDatoteku(char* nazivDatoteke, Stog* pstog);
void procitajIzDatoteke(char* nazivDatoteke, Stog* pstog);
void provjeraBrojeva(int dg, int gg, Stog* pstog);

int main()
{
	Stog stogInterval, stogIntervalDatoteka;
	stogInterval.iVrh = MAX;
	Interval interval;

	int brUnosa, i, dg, gg, max = MAX;

	do
	{
		printf("\n Koliko cijelih brojeva zelite unijeti? (max = %d) ", max);
		scanf_s("%d", &brUnosa);
	} while (brUnosa < 1 || brUnosa > MAX);

	for (i = 0; i < brUnosa; i++)
	{
		printf("\n Unesite %d. broj: ", i + 1);
		scanf_s("%d", &interval.broj);

		ubaci(interval, &stogInterval);
	}

	do {
		printf("\n\n Unesite donju i gornju granicu intervala (odvojene razmakom): ");
		scanf_s("%d %d", &dg, &gg);

		if (dg >= gg)
			printf("\n\t Donja granica mora biti manja od gornje.");
	} while (dg >= gg);

	provjeraBrojeva(dg, gg, &stogInterval);

	printf("\n\n\n ... Ispis elemenata liste ... ");
	ispisi(&stogInterval);


	obrisi(&stogInterval);
	printf("\n\n\n\n ... Ispis nakon 1. brisanja elementa s vrha stoga ... ");
	ispisi(&stogInterval);

	obrisi(&stogInterval);
	printf("\n\n\n\n ... Ispis nakon 2. brisanja elementa s vrha stoga ... ");
	ispisi(&stogInterval);


	spremiUDatoteku("stogInterval", &stogIntervalDatoteka);


	procitajIzDatoteke("stogInterval", &stogIntervalDatoteka);
	printf("\n\n\n\n ... Ispis podataka procitanih iz datoteke ... ");
	ispisi(&stogIntervalDatoteka);

	printf("\n\n");
	return 0;
}




void ubaci(Interval noviElement, Stog* pstog)
{
	if (pstog->iVrh == 0)
		printf("\n Stog je pun. ");

	else
	{
		pstog->iVrh--;
		pstog->elementi[pstog->iVrh] = noviElement;
	}
}


void ispisi(Stog* pstog)
{
	int i, el = 0;

	for (i = pstog->iVrh; i <= MAX - 1; i++)
	{
		el++;
		printf("\n\n %d. ELEMENT STOGA (elementi[%d])", el, i);
		printf("\n\n %4d    %c", pstog->elementi[i].broj, pstog->elementi[i].odnos);
	}
}



void obrisi(Stog* pstog)
{
	if (pstog->iVrh == MAX)
		printf("\n Stog je prazan. ");

	else
		pstog->iVrh++;
}


void spremiUDatoteku(char* nazivDatoteke, Stog* pstog)
{
	FILE* pdatoteka;
	fopen_s(&pdatoteka, nazivDatoteke, "wb");

	if (pdatoteka == NULL)
	{
		printf("\n Problem u otvaranju datoteke. ");
	}
	else
	{
		fwrite(pstog, sizeof(Stog), 1, pdatoteka);
		fclose(pdatoteka);
	}
}


void procitajIzDatoteke(char* nazivDatoteke, Stog* pstog)
{
	FILE* pdatoteka;
	fopen_s(&pdatoteka, nazivDatoteke, "rb");

	if (pdatoteka == NULL)
	{
		printf("\n Problem u otvaranju datoteke. ");
	}
	else
	{
		fread(pstog, sizeof(Stog), 1, pdatoteka);
		fclose(pdatoteka);
	}
}


void provjeraBrojeva(int dg, int gg, Stog* pstog)
{
	int i;

	for (i = pstog->iVrh; i <= MAX - 1; i++)
	{
		if (pstog->elementi[i].broj < dg)
			pstog->elementi[i].odnos = '<';

		else if (pstog->elementi[i].broj <= gg)
			pstog->elementi[i].odnos = '=';

		else
			pstog->elementi[i].odnos = '>';
	}
}
