#include<stdio.h>
#include<limits.h>
#include<string.h>

#ifndef MAXP
#define MAXP 20
#endif

#include"strukture.h"
#include"pomocneFunkcije.h"


void unosProcesa(Proces* procesi, int* pbrP)
{
	int i;

	do
	{
		printf("\n\n Unesite broj procesa za dodjelu procesorskog vremena: ");
		scanf("%d", pbrP);

		if (*pbrP > MAXP)
			printf("\n\t Najveci dopusteni broj procesa je %d. ", MAXP);
		if (*pbrP < 1)
			printf("\n\t Broj procesa mora biti pozitivan broj. ");
	} while (*pbrP > MAXP || *pbrP < 1);


	for (i = 0; i < *pbrP; i++)
	{
		printf("\n\n %d. PROCES", i + 1);

		printf("\n\t ID procesa (pID): ");
		scanf("%3s", procesi[i].pID, 4);

		printf("\t vrijeme dolaska (arrival time): ");
		scanf("%d", &procesi[i].arrivalTime);

		printf("\t vrijeme potrebno za obradu (burst time): ");
		scanf("%d", &procesi[i].burstTime);
	}
}


void inicijalizacijaVrijednostiProcesa(Proces* procesi, int brP)
{
	int i;

	for (i = 0; i < brP; i++)
	{
		procesi[i].startTime = -1;
		procesi[i].completionTime = -1;
		procesi[i].turnaroundTime = -1;
		procesi[i].waitingTime = -1;
		procesi[i].remainingTime = procesi[i].burstTime;
		procesi[i].flag = 0;
		procesi[i].order = -1;
	}
}


void ispisIzlaznihPodataka(Proces* procesi, int brP, Algoritam algoritam, char* algIme)
{
	int i;

	printf("\n\n ...... %s ..............................\n", algIme);
	
	printf("\n\t pID   AT   CT   TT   BT   WT ");
	printf("\n\t ---------------------------- ");
	for (i = 0; i < brP; i++)
		printf("\n\t %3s   %2d   %2d   %2d   %2d   %2d ", procesi[i].pID, procesi[i].arrivalTime, procesi[i].completionTime, procesi[i].turnaroundTime, procesi[i].burstTime, procesi[i].waitingTime);

	printf("\n");
	printf("\n\t srednje vrijeme kompletiranja (ATT) = %5.2f ", algoritam.att);
	printf("\n\t srednje vrijeme cekanja       (AWT) = %5.2f ", algoritam.awt);

	printf("\n\n .......................................\n");
}
