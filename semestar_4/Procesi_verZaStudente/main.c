// algoritmi za dodjelu procesorskog vremena

#include<stdio.h>
#include<limits.h>
#include<string.h>
#define MAXP 20

#include"strukture.h"
#include"pomocneFunkcije.h"

#include"procesi_FCFS.h"
#include"procesi_SJFnpe.h"
#include"procesi_SJFpe.h"


int main()
{
	Proces procesi[MAXP];
	Algoritam FCFS, SJFnpe, SJFpe;
	int brP;
	
	unosProcesa(procesi, &brP);
	
	inicijalizacijaVrijednostiProcesa(procesi, brP);
	FCFSalgoritam(procesi, brP, &FCFS);
	ispisIzlaznihPodataka(procesi, brP, FCFS, "FCFS");

	printf("\n\n");
		/*
	inicijalizacijaVrijednostiProcesa(procesi, brP);
	SJFalgoritam_npe(procesi, brP, &SJFnpe);
	ispisIzlaznihPodataka(procesi, brP, SJFnpe, "SJF-npe");

	printf("\n\n");

	inicijalizacijaVrijednostiProcesa(procesi, brP);
	SJFalgoritam_pe(procesi, brP, &SJFpe);
	ispisIzlaznihPodataka(procesi, brP, SJFpe, "SJF-pe");
*/
	printf("\n\n");
	return 0;
}






