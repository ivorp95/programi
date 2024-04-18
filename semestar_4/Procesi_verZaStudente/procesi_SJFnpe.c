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
		if (procesi[i].flag == 0 && procesi[i].arrivalTime <= tCurr) //isto kao kod FCFS samo bez uvjeta da je arival manje od atMin
		{		//ako je ovaj uvjet zadovoljen trenutni proces nije zavrsen i dolazak mu je  <= trenutnom vremenu
				// sljedeci poziv funkcije daje joj i novo vrijeme tCurr

			if (procesi[i].burstTime < btMin || (procesi[i].burstTime == btMin && procesi[i].arrivalTime < atMin))
				//kod prvog procesa uvjet je sigurno zadovoljen, za svaki sljedeci ili je BT manji od btMin(koji je ostao vrijednost BT proslog procesa)
				//ili je BT novog jednak btMin a AT je manji od atMin(koji je AT proslog procesa)
			{
				indeks = i;
				btMin = procesi[i].burstTime; //kada dobijemo prvi proces za obradu njegov BT postaje btMin
				atMin = procesi[i].arrivalTime; //takoder njegov AT postaje atMin
			}
		}
	}
	return indeks;
}



// funkicja ista kao i kod FCFS

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
			procesi[indeks].turnaroundTime = procesi[indeks].completionTime - procesi[indeks].arrivalTime; // TT = CT - AT
			procesi[indeks].waitingTime = procesi[indeks].turnaroundTime - procesi[indeks].burstTime; // WT = TT - BT
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
