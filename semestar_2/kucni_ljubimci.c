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
    printf("\n\tUnos podataka za %d. ljubimca ", i+1);
    printf("\n Unseite vrstu:");
    gets(ljubimci[i].vrsta);
    

    printf("\n Unseite Ime ljubimca:");
    scanf("%30s",ljubimci[i].ime);

    printf("\n Unseite boju:");
    scanf("%30s",ljubimci[i].boja);

    printf("\n Unseite vrstu:");
    scanf("%d",&ljubimci[i].godine);

    if(DEBUG == 1){
        printf("\n %d.Ljubimac - Vrsta: %s, Ime: %s , Boja: %s, Godine: %d", i+1, ljubimci[i].vrsta, ljubimci[i].ime, ljubimci[i].boja, ljubimci[i].godine);

    }
}









    return 0;
}

