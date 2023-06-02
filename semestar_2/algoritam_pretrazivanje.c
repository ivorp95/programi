// algoritmi za pretrazivanje

#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define MAX 20


typedef struct
{
	char ime[21];
	char adresa[21];
} Osoba;

typedef struct
{
	int iZadnji;
	Osoba elementi[MAX];
} Lista;


void blokovskoPretrazivanje(Lista* plista, char imeTrazi[], int velBloka);
void binarnoPretrazivanje(Lista* plista, char imeTrazi[], int dg, int gg);


int main()
{
	Lista listaOsoba;
	strcpy(listaOsoba.elementi[0].ime, "Ana");
	strcpy(listaOsoba.elementi[0].adresa, "Ciottina 20");
	strcpy(listaOsoba.elementi[1].ime, "Goran");
	strcpy(listaOsoba.elementi[1].adresa, "Zagrebacka 22");
	strcpy(listaOsoba.elementi[2].ime, "Ivan");
	strcpy(listaOsoba.elementi[2].adresa, "Opatijska 3");
	strcpy(listaOsoba.elementi[3].ime, "Luka");
	strcpy(listaOsoba.elementi[3].adresa, "Zametska 20");
	strcpy(listaOsoba.elementi[4].ime, "Marija");
	strcpy(listaOsoba.elementi[4].adresa, "Istarska 4");
	strcpy(listaOsoba.elementi[5].ime, "Marko");
	strcpy(listaOsoba.elementi[5].adresa, "Primorska 15a");
	strcpy(listaOsoba.elementi[6].ime, "Pero");
	strcpy(listaOsoba.elementi[6].adresa, "Pomerio 10");
	strcpy(listaOsoba.elementi[7].ime, "Sanja");
	strcpy(listaOsoba.elementi[7].adresa, "Jadranska 10");
	strcpy(listaOsoba.elementi[8].ime, "Zeljko");
	strcpy(listaOsoba.elementi[8].adresa, "Primorska 3");
	listaOsoba.iZadnji = 8;

	char imeTrazi[21];
	int velBloka;

	printf("\n Unesite ime za pretragu: ");
	scanf("%s", imeTrazi);

	//velBloka = 3;
	//blokovskoPretrazivanje(&listaOsoba, imeTrazi, velBloka);

	binarnoPretrazivanje(&listaOsoba, imeTrazi, 0, listaOsoba.iZadnji);

	printf("\n\n");
	return 0;
}


void blokovskoPretrazivanje(Lista* plista, char imeTrazi[], int velBloka)
{
	int i, j, k, flagSlovo, flagIme = 0;

	for (i = velBloka - 1; i <= plista->iZadnji; i = i + velBloka)
	{
		//printf("\n\t   ime: %s ", plista->elementi[i].ime);
		j = 0;
		flagSlovo = 111;

		while (plista->elementi[i].ime[j] != '\0')
		{
			if (plista->elementi[i].ime[j] > imeTrazi[j])
			{
				flagSlovo = 1;
				break;
			}

			if (plista->elementi[i].ime[j] < imeTrazi[j])
			{
				flagSlovo = 2;
				break;
			}

			j++;
		}

		//printf("\n %d ", flagSlovo);
		if (flagSlovo == 111 && strlen(plista->elementi[i].ime) == strlen(imeTrazi))
		{
			printf("\n\t  Adresa osobe s imenom %s je %s. ", plista->elementi[i].ime, plista->elementi[i].adresa);
			flagIme = 1;
			break;
		}

		if (flagSlovo == 111 && strlen(plista->elementi[i].ime) != strlen(imeTrazi))
		{
			flagSlovo = 2;
		}

		if (flagSlovo == 1)
		{
			for (k = i - velBloka + 1; k < i; k++)
			{
				//printf("\n\t   ime: %s ", plista->elementi[k].ime);
				if (strcmp(plista->elementi[k].ime, imeTrazi) == 0)
				{
					printf("\n\t  Adresa osobe s imenom %s je %s. ", plista->elementi[k].ime, plista->elementi[k].adresa);
					flagIme = 1;
					break;
				}
			}

			break;
		}
	}

	if (flagIme == 0)
	{
		printf("\n\t  Osobe s imenom %s nema u listi. ", imeTrazi);
	}
}


void binarnoPretrazivanje(Lista* plista, char imeTrazi[], int dg, int gg)
{
	int i, ind, j, flagSlovo, flagIme = 0;

	if (abs(gg - dg) <= 1)
	{
		for (i = dg; i <= gg; i++)
		{
			if (strcmp(plista->elementi[i].ime, imeTrazi) == 0)
			{
				printf("\n\t  Adresa osobe s imenom %s je %s. ", plista->elementi[i].ime, plista->elementi[i].adresa);
				flagIme = 1;
				break;
			}
		}

		if (flagIme == 0)
		{
			printf("\n\t  Osobe s imenom %s nema u listi. ", imeTrazi);
		}
	}
	else
	{
		ind = (dg + gg) / 2;

		j = 0;
		flagSlovo = 111;

		while (plista->elementi[ind].ime[j] != '\0')
		{
			if (plista->elementi[ind].ime[j] > imeTrazi[j])
			{
				flagSlovo = -100;
				break;
			}

			if (plista->elementi[ind].ime[j] < imeTrazi[j])
			{
				flagSlovo = 100;
				break;
			}

			j++;
		}

		if (flagSlovo == 111 && strlen(plista->elementi[ind].ime) == strlen(imeTrazi))
		{
			printf("\n\t  Adresa osobe s imenom %s je %s. ", plista->elementi[ind].ime, plista->elementi[ind].adresa);
		}

		if (flagSlovo == 111 && strlen(plista->elementi[ind].ime) != strlen(imeTrazi))
		{
			binarnoPretrazivanje(plista, imeTrazi, ind, gg);
		}

		if (flagSlovo == -100)
		{
			binarnoPretrazivanje(plista, imeTrazi, dg, ind);
		}

		if (flagSlovo == 100)
		{
			binarnoPretrazivanje(plista, imeTrazi, ind, gg);
		}
	}
}