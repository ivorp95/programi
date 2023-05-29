#include<stdio.h>
#include<string.h>

#define MAX 20

typedef struct {
	float promjer;
	char boja[21];
	char uzorak;
}Tanjur;

typedef struct {
	int vrh;
	Tanjur elementi[MAX];
} Stog;

void ubaci(Tanjur x, Stog* pokStog);
void ispis(Stog* pokStog);
void obrisi(Stog* pokStog);
void spremiUDatoteku(char* nazivDatoteke, Stog* pokStrPodataka);
void procitajIzDatoteke(char* nazivDatoteke, Stog* pokStrPodataka);





int main() {
	Tanjur unos;
	Stog  mojStog, stogDatotekaTanjura;
	mojStog.vrh = MAX;
	int i, broj_unosa;

	do {
	printf("\n Unesite broj tanjura koji ce se spremiti u stog (max 20) : ");
	scanf("%d", &broj_unosa);
	if (broj_unosa < 1 || broj_unosa >20)
		printf("\n Broj unosa mora biti izmedu 1 i 20 ");
	} while (broj_unosa < 1 || broj_unosa>20);

	for (i = 0;i < broj_unosa; i++) {
		printf("\n\n\n\n Unesite promjer %d. tanjura koji ce se spremiti u stog : ",i+1);
		scanf("%f", &unos.promjer);
		printf("\n Unesite boju %d. tanjura koji ce se spremiti u stog : ",i+1);
		scanf("%20s", unos.boja,21);
		do {
			printf("\n Unesite uzorak %d. tanjura koji ce se spremiti u stog 'D' ili 'N' : ", i + 1);
			scanf(" %c", &unos.uzorak);
			if (unos.uzorak != 'D' && unos.uzorak != 'N')
				printf("\n Uzorak mora biti znak 'D' ili 'N' ");
		} while (unos.uzorak != 'D' && unos.uzorak != 'N');

		ubaci(unos, &mojStog);
	}

	spremiUDatoteku("datotekaTanjura", &mojStog);

	procitajIzDatoteke("datotekaTanjura", &stogDatotekaTanjura);

	ispis(&stogDatotekaTanjura);



	return 0;
}





void ubaci(Tanjur x, Stog* pokStog) {
	if (pokStog->vrh == 0)
		printf("Stog je pun!");
	else {
		pokStog->vrh--;
		pokStog->elementi[pokStog->vrh] = x;
	}
}

void ispis(Stog* pstog)
{
	int i;

	printf("\n\n ... TANJURI ... \n");
	for (i = pstog->vrh; i <= MAX - 1; i++)
	{
		printf("\n %.2f // %s // %c. ",
			pstog->elementi[i].promjer, pstog->elementi[i].boja, pstog->elementi[i].uzorak);
	}
	printf("\n.................................. \n");
}

void obrisi(Stog* pokStog) {
	if (pokStog->vrh == MAX)
		printf("Stog je prazan!");
	else
		pokStog->vrh++;
}







void spremiUDatoteku(char* nazivDatoteke, Stog* pokStrPodataka) {
	FILE* datoteka;
	fopen(nazivDatoteke, "wb");
	if (datoteka == NULL) {
		printf("Problem u otvaranju datoteke!");
	}
	else {
		fwrite(pokStrPodataka, sizeof(*pokStrPodataka), 1, datoteka);
	}
	fclose(datoteka);
}

void procitajIzDatoteke(char* nazivDatoteke, Stog* pokStrPodataka) {
	FILE* datoteka;

	fopen(nazivDatoteke, "rb");
	if (datoteka == NULL) {
		printf("Problem u otvaranju datoteke!");
	}
	else {
		fread(pokStrPodataka, sizeof(*pokStrPodataka), 1, datoteka);
	}
	fclose(datoteka);
}

