#include<stdio.h>
#include<math.h>

void unos(int* ppolje, int duljina);			//deklaracije funkcije //
void ispis(int* ppolje, int duljina);
int	suma(int* ppolje, int duljina);




int main() {
	int polje[5], suma_el;

	unos(&polje[0], 5);    //  &polje[0] , 5    -- funkciji saljemo adresu prvog polja i duljinu polja - 5

	ispis(&polje[0], 5);

	suma_el=suma(&polje[0], 5);


	printf("\nsuma je: %d", suma_el);

	return 0;
}



void unos(int* ppolje, int duljina) {				//funkcija za unos brojeva u polja od [0] do [4]
	int i = 0;										//ppolje dobiva adresu polja[0], 

	for (i = 0; i < duljina; i++, ppolje++) {
		printf("unseite elemente polja: ");
		scanf("%d", ppolje);			// ppolje dobiva samo adrese polja iz maina
	}
}


void ispis(int* ppolje, int duljina) {					//funkcija za ispis unsenih brojeva polja od [0] do [4]
	int i = 0;												

	for (i = 0; i < duljina; i++, ppolje++) {	
		printf("\nelementi polja: %d ", *ppolje);		// *ppolje znaci da radimo sa vrijednosti na adresi koju ima ppolje
	}
}




int suma(int* ppolje, int duljina) {						//funkcija za sumu unsenih brojeva po poljima od [0] do [4] --- povratni tip je int
	int i = 0;
	int suma=0;

	for (i = 0; i < duljina; i++, ppolje++) {
		suma = suma + *ppolje;
	}

	return suma;
}

