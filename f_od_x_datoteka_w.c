#include<stdio.h>
#include<math.h>


float funkcija(int* px);


int main() {

	FILE* pdatoteka;
	int broj_1, broj_2, i;
	float f;

	do {
		printf(" unsei prvi cijeli broj veci od 0:");
		scanf("%d", &broj_1);

	} while (broj_1 <= 0);

	do {
		printf(" unsei drugi cijeli broj veci od prvog:");
		scanf("%d", &broj_2);

	} while (broj_2 <= broj_1);



	pdatoteka=fopen("/Users/ivorp/podatci.txt", "w");

	if (pdatoteka != NULL) {
		printf(" datoteka je uspjesno kreirana");

		for (i = broj_1; i < broj_2; i++) {

			f = funkcija(&i);

			fprintf(pdatoteka, "\n %.2f", f);
		}

        if (fclose(pdatoteka)==0)
            printf("\n datoteka uspjesno zatvorena");


	}
	else {
		printf(" datoteka nije bila kreirana");
	}
	
	return 0;
}




float funkcija(int* px) {

	float rezultat;
	rezultat = pow(*px, 2) / 2 + 120.0f / (*px);

	return rezultat;
}