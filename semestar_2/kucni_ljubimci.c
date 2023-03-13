#include <stdio.h>
#include <math.h>
#include <string.h>
#define DEBUG 1

int main(){

int i;
char enter;

typedef struct{
char vrsta[31];
char ime[31];
char boja[31];
int godine;
}kucni_ljubimci;

kucni_ljubimci ljubimci[4], ljubimac_default = { "papiga" , "Konstantin",  "zuta", 5};

for (i=0; i<4; i++){
    printf("\tZa pocetak unosa pritisnite enter !!!");
    scanf("%c",&enter);
    printf("\n\n\n\n Unos podataka za %d. ljubimca \n", i+1);
    printf("\n\n Unseite vrstu: ");
    gets(ljubimci[i].vrsta);   // ??? googlati 
    

    printf("\n Unseite Ime ljubimca: ");
    scanf("%30s",ljubimci[i].ime);

    printf("\n Unseite boju: ");
    scanf("%30s",ljubimci[i].boja);

    printf("\n Unseite godine: ");
    scanf("%d",&ljubimci[i].godine);
}

for(i=0;i<4;i++){
    if(DEBUG == 1){
        printf("\n\n %d. Ljubimac \n\tVrsta: %s \n\tIme: %s  \n\tBoja: %s \n\tGodine: %d\n", i+1, ljubimci[i].vrsta, ljubimci[i].ime, ljubimci[i].boja, ljubimci[i].godine);

    }
}

printf("\n\n Default ljubimac \n\tVrsta: %s \n\tIme: %s  \n\tBoja: %s \n\tGodine: %d\n", ljubimac_default.vrsta, ljubimac_default.ime, ljubimac_default.boja, ljubimac_default.godine);








    return 0;
}

