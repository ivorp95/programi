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

typedef struct Celija{
	Film elementi;
	struct Celija* sljedeca;
} CelijaReda;


typedef struct{
	CelijaReda* izlaz;
	CelijaReda* ulaz;
} RedFilmova;


void ubaci(Film noviElement, RedFilmova* pokRed);
void ispisi(RedFilmova* pokRed);
void obrisi(RedFilmova* pokRed);
void izmijeni(Film izmijenjeniElement, Film originalniElement, RedFilmova* pokRed);

void ispisGodineIzlaska(RedFilmova *pokRed, int godina);
void ispisGodineInterval(RedFilmova *pokRed, int dg, int gg);
void ispisTrajanje(RedFilmova *pokRed, int dg, int gg);
void IspisImePrezime(RedFilmova *pokRed, Film originalniElement);
void IspisNaziv(RedFilmova *pokRed, Film originalniElement);

int main (){
    Film unos, originalniElement, izmijenjeniElement;
    RedFilmova mojRed;
    mojRed.izlaz=mojRed.ulaz= (CelijaReda*) malloc (sizeof(CelijaReda));
    char menu_opcija, submenu, enter;
	
// PD unosi
	strcpy(unos.nazivFilma,"The Dark Knight\n");
	strcpy(unos.directorImePrezime,"Cristopher Nolan\n");
	unos.godina_izlaska=2008;
	unos.trajanje=152;
	ubaci(unos, &mojRed);
	strcpy(unos.nazivFilma,"2001 a Space Odyssey\n");
	strcpy(unos.directorImePrezime,"Stanley Kubrick\n");
	unos.godina_izlaska=1968;
	unos.trajanje=149;
	ubaci(unos, &mojRed);
	strcpy(unos.nazivFilma,"Gladiator\n");
	strcpy(unos.directorImePrezime,"Ridley Scott\n");
	unos.godina_izlaska=2000;
	unos.trajanje=170;
	ubaci(unos, &mojRed);
	strcpy(unos.nazivFilma,"Joker\n");
	strcpy(unos.directorImePrezime,"Todd Philips\n");
	unos.godina_izlaska=2019;
	unos.trajanje=122;
	ubaci(unos, &mojRed);
	strcpy(unos.nazivFilma,"A Clockwork Orange\n");
	strcpy(unos.directorImePrezime,"Stanley Kubrick\n");
	unos.godina_izlaska=1971;
	unos.trajanje=137;
	ubaci(unos, &mojRed);
	strcpy(unos.nazivFilma,"Dr. Strangelove\n");
	strcpy(unos.directorImePrezime,"Stanley Kubrick\n");
	unos.godina_izlaska=1963;
	unos.trajanje=95;
	ubaci(unos, &mojRed);
	strcpy(unos.nazivFilma,"Mad Max: Fury Road\n");
	strcpy(unos.directorImePrezime,"George Miller\n");
	unos.godina_izlaska=2015;
	unos.trajanje=120;
	ubaci(unos, &mojRed);
	strcpy(unos.nazivFilma,"Watchmen\n");
	strcpy(unos.directorImePrezime,"Zack Snyder\n");
	unos.godina_izlaska=2009;
	unos.trajanje=215;
	ubaci(unos, &mojRed);
	strcpy(unos.nazivFilma,"Blade Runner (The Final Cut)\n");
	strcpy(unos.directorImePrezime,"Ridley Scott\n");
	unos.godina_izlaska=1982;
	unos.trajanje=119;
	ubaci(unos, &mojRed);
	strcpy(unos.nazivFilma,"The Lord of the Rings: The Fellowship of the Ring\n");
	strcpy(unos.directorImePrezime,"Peter Jackson\n");
	unos.godina_izlaska=2001;
	unos.trajanje=178;
	ubaci(unos, &mojRed);
	strcpy(unos.nazivFilma,"The Lord of the Rings: The Two Towers\n");
	strcpy(unos.directorImePrezime,"Peter Jackson\n");
	unos.godina_izlaska=2002;
	unos.trajanje=180;
	ubaci(unos, &mojRed);
	strcpy(unos.nazivFilma,"The Lord of the Rings: Return of the King\n");
	strcpy(unos.directorImePrezime,"Peter Jackson\n");
	unos.godina_izlaska=2003;
	unos.trajanje=201;
	ubaci(unos, &mojRed);
	strcpy(unos.nazivFilma,"Memento\n");
	strcpy(unos.directorImePrezime,"Cristopher Nolan\n");
	unos.godina_izlaska=2000;
	unos.trajanje=113;
	ubaci(unos, &mojRed);
	strcpy(unos.nazivFilma,"300\n");
	strcpy(unos.directorImePrezime,"Zack Snyder\n");
	unos.godina_izlaska=2006;
	unos.trajanje=117;
	ubaci(unos, &mojRed);
	strcpy(unos.nazivFilma,"Inglorious Bastards\n");
	strcpy(unos.directorImePrezime,"Quentin Tarantino\n");
	unos.godina_izlaska=2009;
	unos.trajanje=153;
	ubaci(unos, &mojRed);
//


    printf("\nProgram za unos filmova preko celija u strukturu reda, unose se podatci o:\nNazivu filma, Imenu i Prezimenu redatelja, \nGodini izdavanja filma, Trajanju filma u minutama.\n");

    label:do{
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
    scanf(" %c",&menu_opcija);

        switch(menu_opcija){

        case 'a':
			do{
			printf("\n Unesite podatke o novom filmu \n");
			printf("\n Naziv filma: ");
			fgets(unos.nazivFilma,51,stdin);
			printf("\n Ime i Prezime Redatelja filma: ");
			fgets(unos.directorImePrezime,51,stdin);
			printf("\n Godina izlaska filma: ");
			scanf(" %d",&unos.godina_izlaska);
			printf("\n Trajanje filma u minutama: ");
			scanf(" %d",&unos.trajanje);

			ubaci(unos, &mojRed);

			printf("\n Zelite li nastaviti unos za jos jedan film ?    'd' ili 'n' ");
			scanf(" %c",&submenu);
			scanf("%c",&enter);
			}while(submenu !='n');
            break;

        case 'b':
			ispisi(&mojRed);
            break;

        case 'c':
			obrisi(&mojRed);
            break;

        case 'd':
			do{
			printf("\n\n\n PODIZBORNIK ZA IZMJENU :\n");
			printf("\n a. za izmjenu po Nazivu filma\n");
			printf("\n b. za izmjenu po Imenu i Prezimenu redatelja filma");
			printf("\n c. za izlaz\n");
			printf("\n Unesite svoj odabir: ");
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
			IspisImePrezime(&mojRed, originalniElement);
			scanf("%c",&enter);
			printf("\n Unesite Naziv filma redatelja: %s koji zelite zamijeniti: ", originalniElement.directorImePrezime);
			fgets(originalniElement.nazivFilma,51,stdin);
			scanf("%c",&enter);
					break;

					case 'c':
					goto label;
					break;
				} 
			}while(submenu!='c');

			printf("\n\n\n Unesite podatke o novom filmu koji ce zamjijeniti postojece\n");
			printf("\n Naziv filma: ");
			fgets(izmijenjeniElement.nazivFilma,51,stdin);
			printf("\n Ime i Prezime Redatelja filma: ");
			fgets(izmijenjeniElement.directorImePrezime,51,stdin);
			printf("\n Godina izlaska filma: ");
			scanf(" %d",&izmijenjeniElement.godina_izlaska);
			printf("\n Trajanje filma u minutama: ");
			scanf(" %d",&izmijenjeniElement.trajanje);

			izmijeni(izmijenjeniElement, originalniElement, &mojRed);
			scanf("%c",&enter);
			break;


        case 'e':
			while(1==1){
				printf("\n\n\n a. Pretraga po Nazivu filma ");
				printf("\n b. Pretraga po Imenu i Prezimenu Redatelja");
				printf("\n c. za izlaz\n") ;
				printf("\n Unesite svoj odabir: ");
				scanf(" %c",&submenu);
				switch (submenu) {
				case 'a':
				printf("\n Unesite Naziv filma po kojem zelite pretrazivati: ");
				scanf("%c",&enter);
				fgets(originalniElement.nazivFilma,51,stdin);
				IspisNaziv(&mojRed, originalniElement);
				break;

				case 'b':
				printf("\n Unesite Ime i Prezime redatelja filma po kojem zelite pretrazivati: ");
				scanf("%c",&enter);
				fgets(originalniElement.directorImePrezime,51,stdin);
				IspisImePrezime(&mojRed, originalniElement);
				break;
				case 'c':
					goto label;
				break;
				}
			}
            break;

		case 'f':
			while(1==1){
			printf("\n\n\n Zelite li pretrazivati po godini izlaska filma ili po trajanju filma\n");
			printf("a. Pretraga po godini izlaksa filma\n");
			printf("b. Pretraga po intervalu godina izlaksa filma\n");
    		printf("c. Pretraga po intervalu trajanja (od - do) (d. za izlaz)\n");
			printf("d. za izlaz\n");
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
					printf("\n Unesite Godine za pretragu: ");
					int dg,gg;
					printf("\n Unesite donju granicu: ");
					scanf(" %d",&dg);
					printf("\n Unesite gornju granicu: ");
					scanf(" %d",&gg);
					ispisGodineInterval(&mojRed,dg,gg);
					break;

					case 'c':
					printf("\n Unesite Trajanje za pretragu u minutama: \n");
					printf("\n Unesite donju granicu: ");
					scanf(" %d",&dg);
					printf("\n Unesite gornju granicu: ");
					scanf(" %d",&gg);
					ispisTrajanje(&mojRed,dg,gg);
					scanf("%c",&enter);
					break;

					case 'd':
					goto label;
					break;
				}
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
			i++;
			printf("\n\n%d. Film: \n\tNaziv filma: \t\t\t%s \n\tRedatelj: \t\t\t%s \n\tGodina izlaska: \t\t%d  \n\n\tTrajanje filma: \t\t%d min.",i, celija->elementi.nazivFilma, celija->elementi.directorImePrezime,celija->elementi.godina_izlaska,celija->elementi.trajanje);
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
			printf("\n\n%d. Film: \n\tNaziv filma: \t\t\t%s \n\tRedatelj: \t\t\t%s \n\tGodina izlaska: \t\t%d  \n\n\tTrajanje filma: \t\t%d min.",i, celija->elementi.nazivFilma, celija->elementi.directorImePrezime,celija->elementi.godina_izlaska,celija->elementi.trajanje);
		}	
	}	
} 

void ispisGodineInterval(RedFilmova *pokRed, int dg, int gg) {
	CelijaReda *celija;
	int i=0;
	if (pokRed->izlaz != pokRed->ulaz){
		celija = pokRed->izlaz;
		while (celija->sljedeca!=NULL)
		{
			celija = celija->sljedeca;
			i++;
			if(celija->elementi.godina_izlaska>=dg && celija->elementi.godina_izlaska<=gg)
			printf("\n\n%d. Film: \n\tNaziv filma: \t\t\t%s \n\tRedatelj: \t\t\t%s \n\tGodina izlaska: \t\t%d  \n\n\tTrajanje filma: \t\t%d min.",i, celija->elementi.nazivFilma, celija->elementi.directorImePrezime,celija->elementi.godina_izlaska,celija->elementi.trajanje);
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
			printf("\n\n%d. Film: \n\tNaziv filma: \t\t\t%s \n\tRedatelj: \t\t\t%s \n\tGodina izlaska: \t\t%d  \n\n\tTrajanje filma: \t\t%d min.",i, celija->elementi.nazivFilma, celija->elementi.directorImePrezime,celija->elementi.godina_izlaska,celija->elementi.trajanje);
			
		}	
	}	
} 

void IspisImePrezime(RedFilmova *pokRed, Film originalniElement) {
	CelijaReda *celija;
	int i=0;
	if (pokRed->izlaz != pokRed->ulaz){
		celija = pokRed->izlaz;
		while (celija->sljedeca!=NULL)
		{
			celija = celija->sljedeca;
			i++;
			if(strcmp(celija->elementi.directorImePrezime,originalniElement.directorImePrezime)==0)
			printf("\n\n%d. Film: \n\tNaziv filma: \t\t\t%s \n\tRedatelj: \t\t\t%s \n\tGodina izlaska: \t\t%d  \n\n\tTrajanje filma: \t\t%d min.",i, celija->elementi.nazivFilma, celija->elementi.directorImePrezime,celija->elementi.godina_izlaska,celija->elementi.trajanje);
			
		}	
	}	
} 
 
void IspisNaziv(RedFilmova *pokRed, Film originalniElement) {
	CelijaReda *celija;
	int i=0;
	if (pokRed->izlaz != pokRed->ulaz){
		celija = pokRed->izlaz;
		while (celija->sljedeca!=NULL)
		{
			celija = celija->sljedeca;
			i++;
			if(strcmp(originalniElement.nazivFilma,celija->elementi.nazivFilma)==0)
			printf("\n\n%d. Film: \n\tNaziv filma: \t\t\t%s \n\tRedatelj: \t\t\t%s \n\tGodina izlaska: \t\t%d  \n\n\tTrajanje filma: \t\t%d min.",i, celija->elementi.nazivFilma, celija->elementi.directorImePrezime,celija->elementi.godina_izlaska,celija->elementi.trajanje);
			
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

void izmijeni(Film izmijenjeniElement, Film originalniElement, RedFilmova* pokRed){
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
