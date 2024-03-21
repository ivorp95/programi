#include<stdio.h>
#include<limits.h>
#include<string.h>

#include"strukture.h"
#include"pomocneFunkcije.h"
#include"procesi_SJFnpe.h"



// ........... SJF non-preemptive ................................................................

int sljedeciProcesSJF_npe(Proces* procesi, int brP, int tCurr)
{
	int i, indeks = -1, btMin = INT_MAX, atMin = INT_MAX;

	for (i = 0; i < brP; i++)
	{
		if (procesi[i].flag == 0 && procesi[i].arrivalTime <= tCurr)
		{
			if (procesi[i].burstTime < btMin || (procesi[i].burstTime == btMin && procesi[i].arrivalTime < atMin))
			{
				indeks = i;
				btMin = procesi[i].burstTime;
				atMin = procesi[i].arrivalTime;
			}
		}
	}
	return indeks;
}


void SJFalgoritam_npe(Proces* procesi, int brP, Algoritam* palgoritam)
{
	int tCurr = 0, i = 0, indeks;
	int tt_suma = 0, wt_suma = 0;

	while (i < brP)
	{
		indeks = sljedeciProcesSJF_npe(procesi, brP, tCurr);

		if (indeks != -1)
		{
			procesi[indeks].startTime = tCurr;
			procesi[indeks].completionTime = tCurr + procesi[indeks].burstTime;
			procesi[indeks].turnaroundTime = procesi[indeks].completionTime - procesi[indeks].arrivalTime;
			procesi[indeks].waitingTime = procesi[indeks].turnaroundTime - procesi[indeks].burstTime;
			procesi[indeks].flag = 1;
			procesi[indeks].order = i + 1;

			tt_suma += procesi[indeks].turnaroundTime;
			wt_suma += procesi[indeks].waitingTime;

			tCurr += procesi[indeks].burstTime;
			i++;
		}
		else
		{
			tCurr++;
		}
	}

	palgoritam->att = (float)tt_suma / brP;
	palgoritam->awt = (float)wt_suma / brP;
}
