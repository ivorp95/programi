#include<stdio.h>
#include<limits.h>
#include<string.h>

#include"strukture.h"
#include"pomocneFunkcije.h"
#include"procesi_FCFS.h"



// ........... FCFS ................................................................

int sljedeciProcesFCFS(Proces* procesi, int brP, int tCurr)
{
	int i, indeks = -1, atMin = INT_MAX;

	for (i = 0; i < brP; i++)
	{
		if (procesi[i].flag == 0 && procesi[i].arrivalTime <= tCurr && procesi[i].arrivalTime < atMin)
		//ako proces nije obraden i ako je vrijeme dolaska manje ili jednako trenutnom i 
		//ako je vrijeme dolaska manje od atMin koji je na pocetku INT_MAX
		{
			indeks = i; //index dobiva vrijednost i koji se salje funkciji FCFS kao broj procesa koji se obradjuje
			atMin = procesi[i].arrivalTime; //atMin dobiva vrijednost vremena dolaska procesa pa u sljejdecoj provjeri uvjeta 
											//nije zadovoljeno i FCFS funkciji se vraca index kao index seljedeceg procesa
		}
	}

	return indeks;
}


void FCFSalgoritam(Proces* procesi, int brP, Algoritam* palgoritam)
{
	int tCurr = 0, i = 0, indeks;
	int tt_suma = 0, wt_suma = 0;

	while (i < brP)
	{
		indeks = sljedeciProcesFCFS(procesi, brP, tCurr);

		if (indeks != -1) //index kojeg vraca funkcija sljedeciProces default je -1,
						//u tom slucaju vrijeme se mora povecati jer nije dosao niti jedan proces
		{
			procesi[indeks].startTime = tCurr;
			procesi[indeks].completionTime = tCurr + procesi[indeks].burstTime;
			procesi[indeks].turnaroundTime = procesi[indeks].completionTime - procesi[indeks].arrivalTime;
			procesi[indeks].waitingTime = procesi[indeks].turnaroundTime - procesi[indeks].burstTime;
			procesi[indeks].flag = 1; //proces uspjesno odradjen
			procesi[indeks].order = i + 1; //index +1 redosljed kojim je zavrsen proces za index 0 order je 1 jer je to prvi proces

			tt_suma += procesi[indeks].turnaroundTime; //dodavanje u sumu vrijednosti TT za izracun prosjeka na kraju
			wt_suma += procesi[indeks].waitingTime;		//isto kao gore za prosjek WT

			tCurr += procesi[indeks].burstTime; //sljedece vrijeme je vrijeme nakon zavrsetka procesa = trenutno + burst ovog procesa
			i++;
		}
		else
		{
			tCurr++; //ako nije odraden prosli uvjet povecava se vrijeme i trazi novi index procesa korz gornju funkciju
		}
	}

	palgoritam->att = (float)tt_suma / brP; //prosjek TT -->  sumaTT / ukupan broj procesa
	palgoritam->awt = (float)wt_suma / brP; //prosjek WT -->  sumaWT / ukupan broj procesa  i castanje u FLOAT jer je prosjek
}

