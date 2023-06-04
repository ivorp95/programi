#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>

typedef struct {
char nazivFilma[31];      
char directorPrezime[30]; 
char directorIme[30]; 
int godina_izlaska;    
int trajanje;            
} Film;

typedef struct Celija
{
	Film elementi;
	struct Celija* sljedeca;
} CelijaReda;


typedef struct
{
	CelijaReda* izlaz;
	CelijaReda* ulaz;
} RedFilmova;


void ubaci(Film noviElement, RedFilmova* pokRed);
void ispisi(RedFilmova* pokRed);
void obrisi(RedFilmova* pokRed);
void izmijeni(Film izmijenjeniElement, Film originalniElement, RedFilmova* pokRed);

void ispisGodineIzlaska(RedFilmova *pokRed, int godina);
void ispisTrajanje(RedFilmova *pokRed, int dg, int gg);

void binarnoPretrazivanje(RedFilmova* pokRed, char imeTrazi[], int dg, int gg);

int main (){
    Film unos, originalniElement, izmijenjeniElement;
    RedFilmova mojRed;
    mojRed.izlaz=mojRed.ulaz= (CelijaReda*) malloc (sizeof(CelijaReda));
    char menu_opcija, submenu;

    printf("\nProgram za unos filmova preko celija u strukturu reda, unose se podatci o:\nNazivu filma, Imenu i Prezimenu redatelja, \nGodini izdavanja filma, Trajanju filma u minutama.\n");

    do{
    sleep(1);
    printf("\nGLAVNI IZBORNIK:\n\n");
    sleep(1);
    printf("a. Unos podataka o novom filmu.\n");
    printf("b. Ispis svih podataka trenutno pohranjenih u redu.\n");
    printf("c. Brisanje podataka iz reda.\n");
    printf("d. Izmjena postojecih podataka u redu.\n");
    printf("e. Pretraga podataka po Imenu filma ili Imenu/Prezimenu redatelja.\n");
	printf("f. Pretraga podataka po Godini izdavanja filma ili Trajanju filma u minutama.\n");
    printf("g. Zavrsetak programa.\n");
    sleep(1);
    printf("\nUnesite svoj odabir: ");
    scanf(" %c",&menu_opcija);

        switch(menu_opcija){

        case 'a':
			printf("\n Unesite podatke o novom filmu ");
			printf("\n Unesite Naziv filma: ");
			scanf(" %30s",unos.nazivFilma);
			printf("\n Unesite ime Redatelja filma: ");
			scanf(" %30s",unos.directorIme);
			printf("\n Unesite prezime Redatelja filma: ");
			scanf(" %30s",unos.directorPrezime);
			printf("\n Unesite godinu izlaska filma: ");
			scanf(" %d",&unos.godina_izlaska);
			printf("\n Unesite Naziv filma: ");
			scanf(" %d",&unos.trajanje);

			ubaci(unos, &mojRed);
            break;

        case 'b':
			ispisi(&mojRed);
            break;

        case 'c':
			obrisi(&mojRed);
            break;

        case 'd':
			printf("\n\n\n PODIZBORNIK ZA IZMJENU :\n");
			printf("\n a. za izmjenu po Nazivu filma\n");
			printf("\n b. za izmjenu po Imenu redatelja filma\n");
			printf("\n c. za izmjenu po Prezimenu redatelja filma\n");
			printf("\nUnesite svoj odabir: ");
			scanf(" %c", &submenu);

				switch(submenu){
					case 'a':
			printf("\n Unesite Naziv filma koji zelite zamijeniti: ");
			scanf(" %30s",originalniElement.nazivFilma);
					break;

					case 'b':
			printf("\n Unesite Ime redatelja filma koji zelite zamijeniti: ");
			scanf(" %30s",originalniElement.directorIme);
					break;

					case 'c':
			printf("\n Unesite Ime redatelja filma koji zelite zamijeniti: ");
			scanf(" %30s",originalniElement.directorPrezime);
					break;
				}

			printf("\n\n\nUnesite podatke o novom filmu koji ce zamjijeniti postojece\n");
			printf("\n Unesite Naziv filma: ");
			scanf(" %30s",izmijenjeniElement.nazivFilma);
			printf("\n Unesite ime Redatelja filma: ");
			scanf(" %30s",izmijenjeniElement.directorIme);
			printf("\n Unesite prezime Redatelja filma: ");
			scanf(" %30s",izmijenjeniElement.directorPrezime);
			printf("\n Unesite godinu izlaska filma: ");
			scanf(" %d",&izmijenjeniElement.godina_izlaska);
			printf("\n Unesite Naziv filma: ");
			scanf(" %D",&izmijenjeniElement.trajanje);

			izmijeni(izmijenjeniElement, originalniElement, &mojRed);

            break;
        case 'e':
            break;

		case 'f':
			printf("\n\n\nZelite li pretrazivati po godini izlaska filma ili po trajanju (od - do) filma\n");
			printf("a. Pretraga po godini izlaksa filma\n");
    		printf("b. Pretraga po trajanju u intervalu (od - do)\n");
			scanf(" %c",&submenu);
				switch(submenu){
					case 'a':
					printf("\n Unesite Godinu za pretragu: \n");
					int godina;
					scanf(" %d",&godina);
					ispisGodineIzlaska(&mojRed, godina );
					break;

					case 'b':
					printf("\n Unesite Trajanje za pretragu u minutama: \n");
					int dg, gg;
					printf("\n Unesite donju granicu: \n");
					scanf(" %d",&dg);
					printf("\n Unesite gornju granicu: \n");
					scanf(" %d",&gg);
					ispisTrajanje(&mojRed,dg,gg);
					break;
				}

			break;
        case 'g':
            break;

        default:
            printf("\nKrivo slovo odabira, molim ponovite odabir kroz izbornik.\n");
            break;
    }

    }while(menu_opcija !='g');

    return 0;
}


void ubaci(Film x, RedFilmova *pokRed) {
	pokRed->ulaz->sljedeca = (CelijaReda*) malloc (sizeof(CelijaReda));
	pokRed->ulaz = pokRed->ulaz->sljedeca;
	pokRed->ulaz->elementi = x;
	pokRed->ulaz->sljedeca = NULL;
}
 
void ispisi(RedFilmova *pokRed) {
	CelijaReda *celija;
	if (pokRed->ulaz == pokRed->izlaz)   
		printf("\n\nRed Filmova je prazan\n\n");
	if (pokRed->izlaz != pokRed->ulaz){
		celija = pokRed->izlaz;
printf("\n\nIspis reda: \n\n");
		while (celija->sljedeca!=NULL)
		{
			int i=0;
			celija = celija->sljedeca;
			printf("\n\n%d. Film: %s , Redatelj: %s %s, Godina izlaska: %d , Trajanje filma: %d min.",i+1, celija->elementi.nazivFilma, celija->elementi.directorIme,celija->elementi.directorPrezime,celija->elementi.godina_izlaska,celija->elementi.trajanje);
			
		}	
	}	
} 

void ispisGodineIzlaska(RedFilmova *pokRed, int godina) {
	CelijaReda *celija;

	if (pokRed->izlaz != pokRed->ulaz){
		celija = pokRed->izlaz;
		while (celija->sljedeca!=NULL)
		{
			int i=0;
			celija = celija->sljedeca;
			if(celija->elementi.godina_izlaska==godina)
			printf("\n\n%d. Film: %s , Redatelj: %s %s, Godina izlaska: %d , Trajanje filma: %d min.",i+1, celija->elementi.nazivFilma, celija->elementi.directorIme,celija->elementi.directorPrezime,celija->elementi.godina_izlaska,celija->elementi.trajanje);
			
		}	
	}	
} 

void ispisTrajanje(RedFilmova *pokRed, int dg, int gg) {
	CelijaReda *celija;

	if (pokRed->izlaz != pokRed->ulaz){
		celija = pokRed->izlaz;
		while (celija->sljedeca!=NULL)
		{
			int i=0;
			celija = celija->sljedeca;
			if(celija->elementi.trajanje>=dg && celija->elementi.trajanje<=gg)
			printf("\n\n%d. Film: %s , Redatelj: %s %s, Godina izlaska: %d , Trajanje filma: %d min.",i+1, celija->elementi.nazivFilma, celija->elementi.directorIme,celija->elementi.directorPrezime,celija->elementi.godina_izlaska,celija->elementi.trajanje);
			
		}	
	}	
} 
 
void obrisi(RedFilmova *pokRed) {
	CelijaReda *privremeno;
	if (pokRed->ulaz == pokRed->izlaz)   
		printf("Red Filmova je prazan");
	else {
		privremeno = pokRed->izlaz;
		pokRed->izlaz = pokRed->izlaz->sljedeca;
		free(privremeno);
	}
}

void izmijeni(Film izmijenjeniElement, Film originalniElement, RedFilmova* pred)
{
	CelijaReda* ptrenutnaCelija = pred->izlaz;

	while (ptrenutnaCelija->sljedeca != NULL)
	{
		ptrenutnaCelija = ptrenutnaCelija->sljedeca;

		if (strcmp(ptrenutnaCelija->elementi.nazivFilma, originalniElement.nazivFilma) == 0 || strcmp(ptrenutnaCelija->elementi.directorIme, originalniElement.directorIme) == 0 || strcmp(ptrenutnaCelija->elementi.directorPrezime, originalniElement.directorPrezime) == 0 &&
			ptrenutnaCelija->elementi.godina_izlaska == originalniElement.godina_izlaska &&
			ptrenutnaCelija->elementi.trajanje == originalniElement.trajanje)
		{
			ptrenutnaCelija->elementi = izmijenjeniElement;
		}
	}
}


/*
void binarnoPretrazivanje(RedFilmova* pokRed, char imeTrazi[], int dg, int gg)
{
	int i, ind, j, flagSlovo, flagIme = 0;

	if (abs(gg - dg) <= 1)
	{
		for (i = dg; i <= gg; i++)
		{
			if (strcmp(pokRed->elementi.ime, imeTrazi) == 0)
			{
				printf("\n\t  Adresa osobe s imenom %s je %s. ", pokRed->elementi[i].ime, pokRed->elementi[i].adresa);
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

		while (pokRed->elementi[ind].ime[j] != '\0')
		{
			if (pokRed->elementi[ind].ime[j] > imeTrazi[j])
			{
				flagSlovo = -100;
				break;
			}

			if (pokRed->elementi[ind].ime[j] < imeTrazi[j])
			{
				flagSlovo = 100;
				break;
			}

			j++;
		}

		if (flagSlovo == 111 && strlen(pokRed->elementi[ind].ime) == strlen(imeTrazi))
		{
			printf("\n\t  Adresa osobe s imenom %s je %s. ", pokRed->elementi[ind].ime, pokRed->elementi[ind].adresa);
		}

		if (flagSlovo == 111 && strlen(pokRed->elementi[ind].ime) != strlen(imeTrazi))
		{
			binarnoPretrazivanje(pokRed, imeTrazi, ind, gg);
		}

		if (flagSlovo == -100)
		{
			binarnoPretrazivanje(pokRed, imeTrazi, dg, ind);
		}

		if (flagSlovo == 100)
		{
			binarnoPretrazivanje(pokRed, imeTrazi, ind, gg);
		}
	}
}
*/