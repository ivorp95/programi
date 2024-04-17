// bankarev algoritam za izbjegavanje zastoja

#include<stdio.h>
#include<limits.h>
#define MAXP 20
#define RES 3

typedef struct
{
	char pID[4];
	int maxRes[RES];
	int allocatedRes[RES];
	int flag; //ako je proces zavrsen je 1 inace 0
	int order; //redni broj kada je proces zavrsen inace -1
} Proces;

void unosResursa(int* numRes);
void unosProcesa(Proces* procesi, int* pbrP);
void bankarevAlgoritam(Proces* procesi, int brP, int* numRes);


int main()
{
	int numRes[RES];
	Proces procesi[MAXP];
	int brP;

	unosResursa(numRes);

	unosProcesa(procesi, &brP);

	bankarevAlgoritam(procesi, brP, numRes);

	printf("\n\n");
	return 0;
}


void unosResursa(int* numRes)
{
	int j;

	printf("\n\n Broj postojecih instanci resursa u racunalu... \n");
	for (j = 0; j < RES; j++)
	{
		printf("\t\t %d. RESURS: ", j + 1);
		scanf("%d", &numRes[j]);
	}
}


void unosProcesa(Proces* procesi, int* pbrP)
{
	int i, j;

	do
	{
		printf("\n\n Unesite broj procesa: ");
		scanf("%d", pbrP);

		if (*pbrP < 1)
			printf("\t Broj procesa mora biti pozitivan broj. ");
		if (*pbrP > MAXP)
			printf("\t Najveci dopusteni broj procesa je %d. ", MAXP);

	} while (*pbrP < 1 || *pbrP > MAXP);

	for (i = 0; i < *pbrP; i++)
	{
		printf("\n %d. PROCES", i + 1);

		printf("\n\t ID procesa: ");
		scanf("%3s", procesi[i].pID, 4);

		printf("\n\t Dodijeljen broj instanci resursa (allocated resources)... \n");
		for (j = 0; j < RES; j++)
		{
			printf("\t\t %d. RESURS: ", j + 1);
			scanf("%d", &procesi[i].allocatedRes[j]);
		}

		printf("\n\t Maksimalni potreban broj instanci resursa (max resources)... \n");
		for (j = 0; j < RES; j++)
		{
			do
			{
				printf("\t\t %d. RESURS: ", j + 1);
				scanf("%d", &procesi[i].maxRes[j]);
			} while (procesi[i].maxRes[j] < procesi[i].allocatedRes[j]);
		}

		procesi[i].flag = 0; //inicijalizacija za svaki proces flag 0
		procesi[i].order = -1; //order -1
	}
}


void bankarevAlgoritam(Proces* procesi, int brP, int* numRes)
{
	int i, j, ok, indeks, order = 0, brProlazaka = 1;
	int availableRes[RES];

	for (j = 0; j < RES; j++)
	{
		availableRes[j] = numRes[j]; //dodjela resursa u pocetku svi imaju ono sto je dodjeljeno u inicijalizaciji

		for (i = 0; i < brP; i++)
		{
			availableRes[j] -= procesi[i].allocatedRes[j]; //petlja za svaki tip resursa oduzimamo alocirane od dostupnih i tako dobivamo koliko svaki ima dodjeljenih
		}
	}

	
	//petlja za obradu resursa
	i = 0;
	while (brProlazaka <= brP) //broj prolazaka manji/jednak od broja procesa
	{
		if (procesi[i].flag == 0) //flag 0 znaci da proces nije zavrsen
		{
			ok = 0; //ok provjera ako imamo dovoljno resursa za obradu procesa
			for (j = 0; j < RES; j++)
			{
				if (procesi[i].allocatedRes[j] + availableRes[j] >= procesi[i].maxRes[j])
				{
					ok++; //ako ima dovoljno resursa ok dobiva 1  i tako za svaki resurs pojedinacno
				}	
			}

			if (ok == RES) //kada petlja pije prode korz sve tipove resursa i ok dobije vrijednost RES (3 u ovom slucaju)
			{
				indeks = i; //indeks dobije vriednost trenutnog i
				procesi[indeks].order = ++order; //proces koji je obraden dobije u svoj order vrijednost ordera iz funkcije +1, order iz funkcije se povecava za jedan nakon obradenog procesa
				procesi[indeks].flag = 1; //proces dobiva flag 1 jer je gotov jer smo nasli sve resurse za obradu

				for (j = 0; j < RES; j++)
				{
					availableRes[j] = availableRes[j] + procesi[indeks].allocatedRes[j]; //slobodnim resursima dodaju se oni koji su vec bili posudeni i sad su vraceni
				}

				if (order == brP) //
					break;
			}
		}

		if (i == brP - 1) // ako je i = zadnjem procesu znaci da sve vracamo na pocetak i prolazimo kroz procese
		{
			i = 0; //u ovom slucaju i se stavlja na 0 kako bi krenuli sa vrha liste ponovo
			brProlazaka++; //broj prolazaka kroz sve procese u listi +1
		}
		else
		{
			i++; //inace i se povecava za 1 , idemo na sljedeci proces
		}
	}

	if (order == brP) // order iz funkicije nakon svih uspjesno odradenih procesa mora biti jednak broju procesa
	{
		printf("\n\n Postoji siguran slijed procesa.");
	}
	else
	{
		printf("\n\n Ne postoji siguran slijed procesa."); //inace nisu svi obradeni
	}
}


