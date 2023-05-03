#include <stdio.h>

#define MAX 20

typedef struct {
	int brojcana;
	char slovna;
} Ocjena;

typedef struct{
 Ocjena elementi[MAX];
 int izlaz;
 int ulaz;
} Red;

void ubaci(Ocjena x, Red *pokRed) {
 if ((pokRed->ulaz+1)%MAX == pokRed-> izlaz)
  printf("Red je pun");
 else {
  pokRed->ulaz = (pokRed->ulaz+1) % MAX;
  pokRed->elementi[pokRed->ulaz] = x;
 }
}

void ispis(Red *pokRed){
 int index; 

  printf("\n\nISPIS REDA: \n");
 
  index = (pokRed->izlaz+1) %MAX;
  while(index != (pokRed->ulaz+1)%MAX){
  printf("%d ",pokRed->elementi[index].brojcana);
  printf("%c ",pokRed->elementi[index].slovna);
  printf("\n");
  index = (index + 1) %MAX;
 }
}


void obrisi(Red *pokRed){
 if (pokRed->izlaz == pokRed->ulaz)  
  printf("Red je prazan");
 else pokRed->izlaz = (pokRed->izlaz+1)%MAX;
}


int main() {
	Ocjena korisnickiUnos;
	int ocjenaZaBrisanje;

	Red mojRed;
	mojRed.izlaz = mojRed.ulaz = 0;


	int i;
	for (i = 0; i < 5; i++) {
		do {
			printf("Unesi brojcanu ocjenu: ");
			scanf("%d", &korisnickiUnos.brojcana);
			if (korisnickiUnos.brojcana < 0 || korisnickiUnos.brojcana > 5) {
				printf("Brojcana ocjena treba biti unutar intervala 0-5!\n");
			}
			else {
				break;
			}
		} while (1 == 1);
		
		do {
			printf("Unesi slovnu ocjenu: ");
			scanf(" %c", &korisnickiUnos.slovna);
			if (korisnickiUnos.slovna != 'A' && korisnickiUnos.slovna != 'B' &&
				korisnickiUnos.slovna != 'C' && korisnickiUnos.slovna != 'D' &&
				korisnickiUnos.slovna != 'E' && korisnickiUnos.slovna != 'F') {
				printf("Slovna ocjena treba biti A, B, C, D, E ili F!\n");
			}
			else {
				break;
			}

		} while (1 == 1);
		
		ubaci(korisnickiUnos, &mojRed);
	}
	ispis(&mojRed);

	/*
	do {
		printf("\n\nUnesite brojcanu ocjenu do koje brisete elemente liste: ");
		scanf("%d", &ocjenaZaBrisanje);
		if (ocjenaZaBrisanje < 0 || ocjenaZaBrisanje > 5) {
			printf("Brojcana ocjena treba biti unutar intervala 0-5!\n");
		}
		else {
			break;
		}
	} while (1 == 1);
	

	for (i = 0; i <= mojRed.ulaz; i++) {
		if (mojRed.elementi[i].brojcana <= ocjenaZaBrisanje) {
			obrisi(&mojRed);
			i = i - 1;
		}
	}
	ispis(&mojRed);
*/
	return 0;
}