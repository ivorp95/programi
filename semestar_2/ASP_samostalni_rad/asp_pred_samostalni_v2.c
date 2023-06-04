#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>

typedef struct {
char nazivFilma[51];      
char directorImePrezime[51]; 
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

void bubbleChar(RedFilmova *pokRed);
void blokovskoPretrazivanje(RedFilmova* pokRed, char imeTrazi[], int velBloka);

int main (){
    Film unos, originalniElement, izmijenjeniElement;
    RedFilmova mojRed;
    mojRed.izlaz=mojRed.ulaz= (CelijaReda*) malloc (sizeof(CelijaReda));
    char menu_opcija, submenu, enter;
	
	// PD unosi
	strcpy(unos.nazivFilma,"Batman\n");
	strcpy(unos.directorImePrezime,"Cristopher Nolan\n");
	unos.godina_izlaska=2001;
	unos.trajanje=150;
	ubaci(unos, &mojRed);
	strcpy(unos.nazivFilma,"2001 a space odissey\n");
	strcpy(unos.directorImePrezime,"Stanley Kubrick\n");
	unos.godina_izlaska=1965;
	unos.trajanje=200;
	ubaci(unos, &mojRed);








    printf("\nProgram za unos filmova preko celija u strukturu reda, unose se podatci o:\nNazivu filma, Imenu i Prezimenu redatelja, \nGodini izdavanja filma, Trajanju filma u minutama.\n");

    do{
    sleep(1);
    printf("\n\n\n\n\nGLAVNI IZBORNIK:\n\n");
    sleep(1);
    printf("a. Unos podataka o novom filmu.\n");
    printf("b. Ispis svih podataka trenutno pohranjenih u redu.\n");
    printf("c. Brisanje podataka iz reda.\n");
    printf("d. Izmjena postojecih podataka u redu.\n");
    printf("e. Pretraga podataka po Nazivu filma ili Imenu i Prezimenu redatelja.\n");
	printf("f. Pretraga podataka po Godini izdavanja filma ili Trajanju filma u minutama.\n");
    printf("g. Zavrsetak programa.\n");
    sleep(1);
    printf("\nUnesite svoj odabir: ");
    scanf("%c",&menu_opcija);
	scanf("%c",&enter);

        switch(menu_opcija){

        case 'a':
			printf("\n Unesite podatke o novom filmu \n");
			printf("\n Naziv filma: ");
			fgets(unos.nazivFilma,51,stdin);
			printf("\n Ime i Prezime Redatelja filma: ");
			fgets(unos.directorImePrezime,51,stdin);
			printf("\n Godina izlaska filma: ");
			scanf(" %d",&unos.godina_izlaska);
			printf("\n Trajanje filma u minutama: ");
			scanf(" %d",&unos.trajanje);
			scanf("%c",&enter);

			ubaci(unos, &mojRed);
            break;

        case 'b':
			ispisi(&mojRed);
            break;

        case 'c':
			obrisi(&mojRed);
            break;

        case 'd':
			//bubbleChar(&mojRed);
			printf("\n\n\n PODIZBORNIK ZA IZMJENU :\n");
			printf("\n a. za izmjenu po Nazivu filma\n");
			printf("\n b. za izmjenu po Imenu i Prezimenu redatelja filma\n");
			printf("\nUnesite svoj odabir: ");
			scanf(" %c", &submenu);
			scanf("%c",&enter);

				switch(submenu){
					case 'a':
			printf("\n Unesite Naziv filma koji zelite zamijeniti: ");
			fgets(originalniElement.nazivFilma,51,stdin);
			scanf("%c",&enter);
					break;

					case 'b':
			printf("\n Unesite Ime i Prezime redatelja filma koji zelite zamijeniti: ");
			fgets(originalniElement.directorImePrezime,51,stdin);
			scanf("%c",&enter);
					break;
				}

			printf("\n\n\nUnesite podatke o novom filmu koji ce zamjijeniti postojece\n");
			printf("\n Naziv filma: ");
			fgets(izmijenjeniElement.nazivFilma,51,stdin);
			printf("\n Ime i Prezime Redatelja filma: ");
			fgets(izmijenjeniElement.directorImePrezime,51,stdin);
			printf("\n Godina izlaska filma: ");
			scanf(" %d",&izmijenjeniElement.godina_izlaska);
			printf("\n Trajanje filma u minutama: ");
			scanf(" %d",&izmijenjeniElement.trajanje);

			izmijeni(izmijenjeniElement, originalniElement, &mojRed);

            break;
        case 'e':
            break;

		case 'f':
			printf("\n\n\nZelite li pretrazivati po godini izlaska filma ili po trajanju filma\n");
			printf("a. Pretraga po godini izlaksa filma\n");
    		printf("b. Pretraga po trajanju u intervalu (od - do)\n");
			scanf(" %c",&submenu);
				switch(submenu){
					case 'a':
					printf("\n Unesite Godinu za pretragu: ");
					int godina;
					scanf(" %d",&godina);
					ispisGodineIzlaska(&mojRed, godina );
					scanf("%c",&enter);
					break;

					case 'b':
					printf("\n Unesite Trajanje za pretragu u minutama: \n");
					int dg, gg;
					printf("\n Unesite donju granicu: ");
					scanf(" %d",&dg);
					printf("\n Unesite gornju granicu: ");
					scanf(" %d",&gg);
					ispisTrajanje(&mojRed,dg,gg);
					scanf("%c",&enter);
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


void ubaci(Film noviElement, RedFilmova *pokRed) {
	pokRed->ulaz->sljedeca = (CelijaReda*) malloc (sizeof(CelijaReda));
	pokRed->ulaz = pokRed->ulaz->sljedeca;
	pokRed->ulaz->elementi = noviElement;
	pokRed->ulaz->sljedeca = NULL;
}
 
void ispisi(RedFilmova *pokRed) {
	CelijaReda *celija;
	int i=0;
	if (pokRed->ulaz == pokRed->izlaz)   
		printf("\n\nRed Filmova je prazan\n\n");
	if (pokRed->izlaz != pokRed->ulaz){
		celija = pokRed->izlaz;
		printf("\n\nIspis reda: \n\n");
		while (celija->sljedeca!=NULL)
		{
			celija = celija->sljedeca;
			printf("\n\n%d. Film: \n\tNaziv filma: \t\t\t%s \n\tRedatelj: \t\t\t%s \n\tGodina izlaska: \t\t%d  \n\n\tTrajanje filma: \t\t%d min.",i+1, celija->elementi.nazivFilma, celija->elementi.directorImePrezime,celija->elementi.godina_izlaska,celija->elementi.trajanje);
			i++;
		}	
	}	
} 

void ispisGodineIzlaska(RedFilmova *pokRed, int godina) {
	CelijaReda *celija;
	int i=0;
	if (pokRed->izlaz != pokRed->ulaz){
		celija = pokRed->izlaz;
		while (celija->sljedeca!=NULL)
		{
			celija = celija->sljedeca;
			i++;
			if(celija->elementi.godina_izlaska==godina)
			printf("\n\n%d. Film: \n\tNaziv filma: \t\t\t%s \n\tRedatelj: \t\t\t%s \n\tGodina izlaska: \t\t%d  \n\n\tTrajanje filma: \t\t%d min.",i+1, celija->elementi.nazivFilma, celija->elementi.directorImePrezime,celija->elementi.godina_izlaska,celija->elementi.trajanje);
		}	
	}	
} 

void ispisTrajanje(RedFilmova *pokRed, int dg, int gg) {
	CelijaReda *celija;
	int i=0;
	if (pokRed->izlaz != pokRed->ulaz){
		celija = pokRed->izlaz;
		while (celija->sljedeca!=NULL)
		{
			celija = celija->sljedeca;
			i++;
			if(celija->elementi.trajanje>=dg && celija->elementi.trajanje<=gg)
			printf("\n\n%d. Film: \n\tNaziv filma: \t\t\t%s \n\tRedatelj: \t\t\t%s \n\tGodina izlaska: \t\t%d  \n\n\tTrajanje filma: \t\t%d min.",i+1, celija->elementi.nazivFilma, celija->elementi.directorImePrezime,celija->elementi.godina_izlaska,celija->elementi.trajanje);
			
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

void izmijeni(Film izmijenjeniElement, Film originalniElement, RedFilmova* pokRed)
{
	CelijaReda* ptrenutnaCelija = pokRed->izlaz;

	while (ptrenutnaCelija->sljedeca != NULL)
	{
		ptrenutnaCelija = ptrenutnaCelija->sljedeca;

		if (strcmp(ptrenutnaCelija->elementi.nazivFilma, originalniElement.nazivFilma) == 0 || strcmp(ptrenutnaCelija->elementi.directorImePrezime, originalniElement.directorImePrezime) == 0 &&
			ptrenutnaCelija->elementi.godina_izlaska == originalniElement.godina_izlaska &&
			ptrenutnaCelija->elementi.trajanje == originalniElement.trajanje)
		{
			ptrenutnaCelija->elementi = izmijenjeniElement;
		}
	}
}

/*
void bubbleChar(RedFilmova *pokRed){

	CelijaReda* ptrenutnaCelija = pokRed->ulaz;
	int i, j, k, flag, dulj=1;
	CelijaReda temp;

	while(ptrenutnaCelija->sljedeca!=NULL){
		dulj++;
		ptrenutnaCelija = ptrenutnaCelija->sljedeca;
	}

	for (i = 0; i <= dulj ; i++)
	{
		flag = 0;
		for (j = 0; j < 51; j++)
		{
			if (ptrenutnaCelija->sljedeca->elementi.nazivFilma[j] < ptrenutnaCelija->elementi.nazivFilma[j])
			{
				temp.elementi = ptrenutnaCelija->sljedeca->elementi;
				ptrenutnaCelija->elementi = ptrenutnaCelija->sljedeca->elementi;
				ptrenutnaCelija->sljedeca->elementi= temp.elementi;
				flag = 1;
			}
		}

		if (flag == 0)
		{
			break;
		}
		ptrenutnaCelija = ptrenutnaCelija->sljedeca;
	}
}
*/

