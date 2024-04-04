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
	int flag;
	int order;
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

		procesi[i].flag = 0;
		procesi[i].order = -1;
	}
}


void bankarevAlgoritam(Proces* procesi, int brP, int* numRes)
{
	int i, j, ok, indeks, order = 0, brProlazaka = 1;
	int availableRes[RES];

	for (j = 0; j < RES; j++)
	{
		availableRes[j] = numRes[j];

		for (i = 0; i < brP; i++)
		{
			availableRes[j] -= procesi[i].allocatedRes[j];
		}
	}

	i = 0;
	while (brProlazaka <= brP)
	{
		if (procesi[i].flag == 0)
		{
			ok = 0;
			for (j = 0; j < RES; j++)
			{
				if (procesi[i].allocatedRes[j] + availableRes[j] >= procesi[i].maxRes[j])
				{
					ok++;
				}	
			}

			if (ok == RES)
			{
				indeks = i;
				procesi[indeks].order = ++order;
				procesi[indeks].flag = 1;

				for (j = 0; j < RES; j++)
				{
					availableRes[j] = availableRes[j] + procesi[indeks].allocatedRes[j];
				}

				if (order == brP)
					break;
			}
		}

		if (i == brP - 1)
		{
			i = 0;
			brProlazaka++;
		}
		else
		{
			i++;
		}
	}

	if (order == brP)
	{
		printf("\n\n Postoji siguran slijed procesa.");
	}
	else
	{
		printf("\n\n Ne postoji siguran slijed procesa.");
	}
}


