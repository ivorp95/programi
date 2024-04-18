#include<stdio.h>
#include<limits.h>
#include<string.h>

#include"strukture.h"
#include"pomocneFunkcije.h"
#include"procesi_SJFpe.h"



// ........... SJF preemptive ................................................................

int sljedeciProcesSJF_pe(Proces* procesi, int brP, int tCurr)
{
	int i, indeks = -1, rtMin = INT_MAX, atMin = INT_MAX;

	for (i = 0; i < brP; i++)
	{
		if (procesi[i].flag == 0 && procesi[i].arrivalTime <= tCurr)
		{
			if (procesi[i].remainingTime /*burstTime kod SJFnpe*/< rtMin || (procesi[i].remainingTime == rtMin && procesi[i].arrivalTime < atMin))
			{
				indeks = i;
				rtMin = procesi[i].remainingTime; //BT iz SJFnpe se zamjenjuje sa remainingTime isto tako i u uvijetu
				atMin = procesi[i].arrivalTime;
			}
		}
	}
	return indeks;
}


void SJFalgoritam_pe(Proces* procesi, int brP, Algoritam* palgoritam)
{
	int tCurr = 0, i = 0, indeks;
	int tt_suma = 0, wt_suma = 0;

	while (i < brP)
	{
		indeks = sljedeciProcesSJF_pe(procesi, brP, tCurr);

		if (indeks != -1)
		{
			if (procesi[indeks].remainingTime == 1) //tek kada funcija sljedeciProces izvrti proces da je RT = 1 
			{
				procesi[indeks].completionTime = tCurr + 1; //CT je uvijek tCurr +1 jer gledamo svaki vremenski trenuak
				procesi[indeks].turnaroundTime = procesi[indeks].completionTime - procesi[indeks].arrivalTime;
				procesi[indeks].waitingTime = procesi[indeks].turnaroundTime - procesi[indeks].burstTime;
				procesi[indeks].flag = 1;
				procesi[indeks].remainingTime = 0; //RT za obavljeni proces je = 0
				// order netreba posto proces sa RT = 0 nece biti uzet u obzir 

				tt_suma += procesi[indeks].turnaroundTime;
				wt_suma += procesi[indeks].waitingTime;
				i++;
			}
			else
			{
				procesi[indeks].remainingTime--;
			}
		}

		tCurr++;
	}

	palgoritam->att = (float)tt_suma / brP;
	palgoritam->awt = (float)wt_suma / brP;
}

