#include<stdlib.h>  // malloc - funkcija je tu definirana - clang llvm
#include<stdio.h>
#include<math.h>


typedef struct {
	int x;
	int izraz1;
	int izraz2;
} Broj ;


typedef struct Celija {
	Broj element;
	struct Celija* psljedeca;
} CelijaBroj;


/*
CelijaLjubimac* pronadjiZadnju(CelijaLjubimac* ppolaznaCelija);
CelijaLjubimac* pronadjiAdresu_element(KucniLjubimac element, CelijaLjubimac* ppolaznaCelija);
CelijaLjubimac* pronadjiAdresu_pozicija(int pozicija, CelijaLjubimac* ppolaznaCelija);


void ispisi(CelijaLjubimac* ppolaznaCelija);
void obrisi(CelijaLjubimac* pcelija);
void izmijeni(KucniLjubimac izmijenjeniElement, CelijaLjubimac* pcelijaZaIzmjenu);
*/

void ubaci(Broj noviElement, CelijaBroj* pcelija);

CelijaBroj* pronadjiZadnju(CelijaBroj* ppolaznaCelija);



int main() {
	Broj broj_unos;
	CelijaBroj* ppolazna_celija;
	ppolazna_celija = (CelijaBroj*)malloc(sizeof(CelijaBroj));
	ppolazna_celija->psljedeca = NULL;

	int pocetak, kraj, razlika, i;

	do {
		printf("\n Unesi pocetak: ");
		scanf_s("%d", &pocetak);

		printf("\n Unesi kraj: ");
		scanf_s("%d", &kraj);
		razlika = pocetak - kraj;

		if (pocetak < kraj && razlika > 10) {
			printf("Pocetak mora biti veci od Kraja, razlika ne smije biti veca od 10\n");
		}
	} while (pocetak < kraj && razlika > 10);

	for (i = pocetak; i >= kraj; i--) {

		broj_unos.x = i;

		ubaci(broj_unos, ppolazna_celija);
	}

	

	return 0;
}

void ubaci(Broj noviElement, CelijaBroj* pcelija){

	CelijaBroj* psljedecaStara = pcelija->psljedeca;

	pcelija->psljedeca = (CelijaBroj*)malloc(sizeof(CelijaBroj));

	pcelija->psljedeca->element = noviElement;
	pcelija->psljedeca->psljedeca = psljedecaStara;
}


CelijaBroj* pronadjiZadnju(CelijaBroj* ppolaznaCelija) {

	CelijaBroj* pzadnjaCelija = ppolaznaCelija;

	while (pzadnjaCelija->psljedeca != NULL)
		pzadnjaCelija = pzadnjaCelija->psljedeca;

	return pzadnjaCelija;
}

/*
CelijaLjubimac* pronadjiZadnju(CelijaLjubimac* ppolaznaCelija)
{
	CelijaLjubimac* pzadnjaCelija = ppolaznaCelija;

	while (pzadnjaCelija->psljedeca != NULL)
		pzadnjaCelija = pzadnjaCelija->psljedeca;

	return pzadnjaCelija;
}


CelijaLjubimac* pronadjiAdresu_element(KucniLjubimac element, CelijaLjubimac* ppolaznaCelija)
{
	CelijaLjubimac* ptrenutnaCelija = ppolaznaCelija;

	while (ptrenutnaCelija->psljedeca != NULL)
	{
		ptrenutnaCelija = ptrenutnaCelija->psljedeca;

		if (strcmp(ptrenutnaCelija->element.ime, element.ime) == 0 &&
			strcmp(ptrenutnaCelija->element.vrsta, element.vrsta) == 0 &&
			ptrenutnaCelija->element.dob == element.dob)
		{
			return ptrenutnaCelija;
		}
	}

	return NULL;
}


CelijaLjubimac* pronadjiAdresu_pozicija(int pozicija, CelijaLjubimac* ppolaznaCelija)
{
	CelijaLjubimac* ptrenutnaCelija = ppolaznaCelija;
	int el = 0;

	while (ptrenutnaCelija->psljedeca != NULL)
	{
		ptrenutnaCelija = ptrenutnaCelija->psljedeca;
		el++;

		if (el == pozicija)
			return ptrenutnaCelija;
	}

	return NULL;
}


// pcelija je pokazivac na celiju NAKON/IZA koje se ubacuje celija s noviElement
void ubaci(KucniLjubimac noviElement, CelijaLjubimac* pcelija)
{
	CelijaLjubimac* psljedecaStara = pcelija->psljedeca;

	pcelija->psljedeca = (CelijaLjubimac*)malloc(sizeof(CelijaLjubimac));

	pcelija->psljedeca->element = noviElement;
	pcelija->psljedeca->psljedeca = psljedecaStara;
}


void ispisi(CelijaLjubimac* ppolaznaCelija)
{
	CelijaLjubimac* ptrenutnaCelija = ppolaznaCelija;
	int el = 0;

	printf("\n\n POLAZNA CELIJA (adresa celije: %p)", ptrenutnaCelija);
	printf("\n\t   element: - ");
	printf("\n\t psljedeca: %p ", ptrenutnaCelija->psljedeca);

	while (ptrenutnaCelija->psljedeca != NULL)
	{
		ptrenutnaCelija = ptrenutnaCelija->psljedeca;
		el++;

		printf("\n\n\n %d. CELIJA (adresa celije: %p)", el, ptrenutnaCelija);
		printf("\n\t   element: ");
		printf("\n\t\t     ime: %s ", ptrenutnaCelija->element.ime);
		printf("\n\t\t   vrsta: %s ", ptrenutnaCelija->element.vrsta);
		printf("\n\t\t     dob: %d ", ptrenutnaCelija->element.dob);
		printf("\n\t psljedeca: %p ", ptrenutnaCelija->psljedeca);
	}
}


// pcelija je pokazivac na celiju NAKON/IZA koje slijedi celija koja se brise 
void obrisi(CelijaLjubimac* pcelija)
{
	CelijaLjubimac* pcelijaZaBrisanje = pcelija->psljedeca;

	//pcelija->psljedeca = pcelija->psljedeca->psljedeca;
	// ili:
	pcelija->psljedeca = pcelijaZaBrisanje->psljedeca;

	free(pcelijaZaBrisanje);
}



void izmijeni(KucniLjubimac izmijenjeniElement, CelijaLjubimac* pcelijaZaIzmjenu)
{
	pcelijaZaIzmjenu->element = izmijenjeniElement;
}

*/