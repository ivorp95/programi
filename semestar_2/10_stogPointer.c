#include<stdio.h>
#include<math.h>
#include<malloc.h>

typedef struct
{
	int x;
	int izraz1;
	int izraz2;
} Broj;

typedef struct Celija
{
	Broj element;
	struct Celija* psljedeca;
} CelijaBroj;



CelijaBroj* ubaci(Broj noviElement, CelijaBroj* pvrhStoga);
CelijaBroj* obrisi(CelijaBroj* pvrhStoga);
void ispisi(CelijaBroj* pvrhStoga);
void izracunajIzraze(CelijaBroj* pvrhStoga);



int main()
{
	CelijaBroj* pvrhStoga;
	pvrhStoga = NULL;

	Broj broj;
	int pocetak, kraj, i;


	do {
		printf("\n\n Unesite 2 cijela broja odvojena razmakom: ");
		scanf_s("%d %d", &pocetak, &kraj);

		if (pocetak < kraj)
			printf("\n\t Prvi broj treba biti veci od drugoga. ");

		if (pocetak - kraj > 10)
			printf("\n\t Razlika brojeva ne smije biti veca od 10. ");

	} while (pocetak < kraj || pocetak - kraj > 10);


	for (i = pocetak; i >= kraj; i--)
	{
		broj.x = i;
		pvrhStoga=ubaci(broj, pvrhStoga);
	}

	izracunajIzraze(pvrhStoga);
	ispisi(pvrhStoga);
	printf("\n\n");


	pvrhStoga = obrisi(pvrhStoga);
	ispisi(pvrhStoga);
	printf("\n\n");

	pvrhStoga = obrisi(pvrhStoga);
	ispisi(pvrhStoga);
	printf("\n\n");

	pvrhStoga = obrisi(pvrhStoga);
	ispisi(pvrhStoga);

	printf("\n\n");
	return 0;
}




CelijaBroj* ubaci(Broj noviElement, CelijaBroj* pvrhStoga)
{
	CelijaBroj* pnovaCelija = (CelijaBroj*)malloc(sizeof(CelijaBroj));

	pnovaCelija->element = noviElement;
	pnovaCelija->psljedeca = pvrhStoga;

	return pnovaCelija;
}


CelijaBroj* obrisi(CelijaBroj* pvrhStoga)
{
	CelijaBroj* pnoviVrhStoga;

	if (pvrhStoga == NULL)
	{
		printf("\n Stog je prazan. ");
		return NULL;
	}
	else
	{
		pnoviVrhStoga = pvrhStoga->psljedeca;
		free(pvrhStoga);

		return pnoviVrhStoga;
	}
}


void ispisi(CelijaBroj* pvrhStoga)
{
	CelijaBroj* ptrenutnaCelija = pvrhStoga;

	printf("\n    x       izraz1       izraz2 ");
	if (ptrenutnaCelija == NULL)
	{
		printf("\n Stog je prazan. ");
	}
	else
	{
		while (ptrenutnaCelija != NULL)
		{

			printf("\n %4d   %10d   %10d",
				ptrenutnaCelija->element.x,
				ptrenutnaCelija->element.izraz1,
				ptrenutnaCelija->element.izraz2);
				ptrenutnaCelija = ptrenutnaCelija->psljedeca;
		}
	}
}


void izracunajIzraze(CelijaBroj* pvrhStoga)
{
	CelijaBroj* ptrenutnaCelija = pvrhStoga;
	int x;

	while (ptrenutnaCelija != NULL)
	{
		x = ptrenutnaCelija->element.x;
		ptrenutnaCelija->element.izraz1 = pow(x, 4) - 2 * pow(x, 2) + 1 - pow((x + 1), 2);
		ptrenutnaCelija->element.izraz2 = x * (x - 2) * (x + 1) * (x + 1);
		ptrenutnaCelija = ptrenutnaCelija->psljedeca;

	}
}

