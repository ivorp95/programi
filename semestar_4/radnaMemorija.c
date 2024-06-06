// algoritmi za zamjenu stranica u radnoj memoriji

#include<stdio.h>
#include<time.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>

#define MAXO 20
#define MAXZ 40

typedef struct
{
	int empty;
	int pageNum;
	time_t timestamp;
} Okvir;


void inicijalizacijaVrijednostiOkvira(Okvir* okviri, int brO);

int stranica_uOkviru(Okvir* okviri, int brO, int brojStranice, char* algoritam);
int prviPrazanOkvir(Okvir* okviri, int brO);
void upisi_uOkvir(Okvir* okviri, int iOkvira, int brojStranice);

int izbaciStranicuFIFO_timestamp(Okvir* okviri, int brO);
int izbaciStranicuLRU_timestamp(Okvir* okviri, int brO);
int izbaciStranicuOptimalni(Okvir* okviri, int brO, int* slijedZahtjeva, int brZ, int jZahtjeva);

void pohranaStanjaOkvira(Okvir* okviri, int brO, int jZahtjeva, char slijedStanjaOkvira[MAXO][MAXZ]);
void ispisSlijedaStanjaOkvira(int brO, int* slijedZahtjeva, int brZ, char slijedStanjaOkvira[MAXO][MAXZ], char slijedPromasaja[MAXZ], int brPromasaja);

int dodjelaOkvira(Okvir* okviri, int brO, int* slijedZahtjeva, int brZ, char slijedStanjaOkvira[MAXO][MAXZ], char slijedPromasaja[MAXZ], char* algoritam);



int main()
{
	Okvir okviri[MAXO];
	int slijedZahtjeva[MAXZ];
	char algoritam[11];

	char slijedStanjaOkvira[MAXO][MAXZ];
	char slijedPromasaja[MAXZ];

	int j, brO, brZ = 0, brPromasaja;

	do
	{
		printf("\n\n Unesite broj okvira u radnoj memoriji: ");
		scanf("%d", &brO);
		if (brO > MAXO)
			printf("\n\t Najveci dopusteni broj okvira je %d. ", MAXO);
		if (brO < 1)
			printf("\n\t Broj okvira mora biti pozitivan broj. ");
	} while (brO > MAXO || brO < 1);

	inicijalizacijaVrijednostiOkvira(okviri, brO);

	printf("\n\n\n Unos slijeda zahtjeva za stranicama (-1 za kraj): \n");
	for (j = 0; j < MAXZ; j++)
	{
		printf("\t %2d. zahtjev: ", j + 1);
		scanf("%d", &slijedZahtjeva[j]);
		if (slijedZahtjeva[j] == -1)
		{
			brZ = j;
			break;
		}
	}

	strcpy(algoritam,  "Optimalni");  // FIFO_ts, LRU_ts, Optimalni
	brPromasaja = dodjelaOkvira(okviri, brO, slijedZahtjeva, brZ, slijedStanjaOkvira, slijedPromasaja, algoritam);

	printf("\n\n\n ... %s algoritam ...........................", algoritam);
	ispisSlijedaStanjaOkvira(brO, slijedZahtjeva, brZ, slijedStanjaOkvira, slijedPromasaja, brPromasaja);
	printf("\n\n ....................................................................");

	printf("\n\n");
	return 0;
}



void inicijalizacijaVrijednostiOkvira(Okvir* okviri, int brO)
{
	int i;

	for (i = 0; i < brO; i++)
	{
		okviri[i].empty = 1;
		okviri[i].pageNum = -1;
		time(&okviri[i].timestamp);
		usleep(1000);
	}
}


int stranica_uOkviru(Okvir* okviri, int brO, int brojStranice, char* algoritam)
{
	int i, uOkviru = 0;

	for (i = 0; i < brO; i++)
	{
		if (okviri[i].pageNum == brojStranice)
		{
			uOkviru = 1;

			if (strcmp(algoritam, "LRU_ts") == 0)
			{
				time(&okviri[i].timestamp);
				usleep(1000);
			}

			break;
		}
	}

	return uOkviru;
}


int prviPrazanOkvir(Okvir* okviri, int brO)
{
	int i;

	for (i = 0; i < brO; i++)
	{
		if (okviri[i].empty == 1)
			return i;
	}

	return -1;
}


void upisi_uOkvir(Okvir* okviri, int iOkvira, int brojStranice)
{
	okviri[iOkvira].empty = 0;
	okviri[iOkvira].pageNum = brojStranice;
	time(&okviri[iOkvira].timestamp);
	usleep(1000);
}


int izbaciStranicuFIFO_timestamp(Okvir* okviri, int brO)
{
	int i, iIzbaci = 0;
	time_t timeMin = okviri[0].timestamp;

	for (i = 1; i < brO; i++)
	{
		if (okviri[i].timestamp < timeMin)
		{
			timeMin = okviri[i].timestamp;
			iIzbaci = i;
		}
	}

	return iIzbaci;
}


int izbaciStranicuLRU_timestamp(Okvir* okviri, int brO)
{
	int i, iIzbaci = 0;
	time_t timeMin = okviri[0].timestamp;

	for (i = 1; i < brO; i++)
	{
		if (okviri[i].timestamp < timeMin)
		{
			timeMin = okviri[i].timestamp;
			iIzbaci = i;
		}
	}

	return iIzbaci;
}


int izbaciStranicuOptimalni(Okvir* okviri, int brO, int* slijedZahtjeva, int brZ, int jZahtjeva)
{
	int i, j, iIzbaci = 0;
	int jNajdalji[MAXO];

	for (i = 0; i < brO; i++)
	{
		jNajdalji[i] = -1;
	}

	for (i = 0; i < brO; i++)
	{
		for (j = jZahtjeva + 1; j < brZ; j++)
		{
			if (okviri[i].pageNum == slijedZahtjeva[j])
			{
				jNajdalji[i] = j;
				break;
			}
		}

		if (jNajdalji[i] == -1)
			return i;
	}

	for (i = 1; i < brO; i++)
	{
		if (jNajdalji[i] > jNajdalji[iIzbaci])
			iIzbaci = i;
	}

	return iIzbaci;
}


void pohranaStanjaOkvira(Okvir* okviri, int brO, int jZahtjeva, char slijedStanjaOkvira[MAXO][MAXZ])
{
	int i;

	for (i = 0; i < brO; i++)
	{
		if (okviri[i].pageNum != -1)
			slijedStanjaOkvira[i][jZahtjeva] = okviri[i].pageNum + '0';
		else
			slijedStanjaOkvira[i][jZahtjeva] = '-';
	}
}


void ispisSlijedaStanjaOkvira(int brO, int* slijedZahtjeva, int brZ, char slijedStanjaOkvira[MAXO][MAXZ], char slijedPromasaja[MAXZ], int brPromasaja)
{
	int i, j;

	printf("\n\n  ZAHTJEV: ");
	for (j = 0; j < brZ; j++)
	{
		printf("%d  ", slijedZahtjeva[j]);
	}

	printf("\n -----------");
	for (j = 0; j < brZ; j++)
	{
		printf("---");
	}

	for (i = 0; i < brO; i++)
	{
		printf("\n %d. OKVIR: ", i + 1);
		for (j = 0; j < brZ; j++)
		{
			printf("%c  ", slijedStanjaOkvira[i][j]);
		}
	}

	printf("\n -----------");
	for (j = 0; j < brZ; j++)
	{
		printf("---");
	}

	printf("\n PROMASAJ: ");
	for (j = 0; j < brZ; j++)
	{
		printf("%c  ", slijedPromasaja[j]);
	}

	printf("\n\n broj promasaja = %d ", brPromasaja);
}


int dodjelaOkvira(Okvir* okviri, int brO, int* slijedZahtjeva, int brZ, char slijedStanjaOkvira[MAXO][MAXZ], char slijedPromasaja[MAXZ], char* algoritam)
{
	int j, iPrazan, iIzbaci, brPromasaja = 0;

	for (j = 0; j < brZ; j++)
	{
		if (stranica_uOkviru(okviri, brO, slijedZahtjeva[j], algoritam) == 1)
		{
			slijedPromasaja[j] = ' ';
		}
		else
		{
			brPromasaja++;
			slijedPromasaja[j] = 'X';

			iPrazan = prviPrazanOkvir(okviri, brO);

			if (iPrazan != -1)
			{
				upisi_uOkvir(okviri, iPrazan, slijedZahtjeva[j]);
			}
			else
			{
				if (strcmp(algoritam, "FIFO_ts") == 0)
					iIzbaci = izbaciStranicuFIFO_timestamp(okviri, brO);

				if (strcmp(algoritam, "LRU_ts") == 0)
					iIzbaci = izbaciStranicuLRU_timestamp(okviri, brO);

				if (strcmp(algoritam, "Optimalni") == 0)
					iIzbaci = izbaciStranicuOptimalni(okviri, brO, slijedZahtjeva, brZ, j);

				upisi_uOkvir(okviri, iIzbaci, slijedZahtjeva[j]);
			}
		}

		pohranaStanjaOkvira(okviri, brO, j, slijedStanjaOkvira);
	}

	return brPromasaja;
}
