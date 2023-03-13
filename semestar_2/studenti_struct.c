#include <stdio.h>
#include <math.h>
#include <string.h>
#define DEBUG 1

typedef struct{
    int jmbag,br_ocjena,god_rod;
    int ocjene[10];
    float prosjek;
    char ime[21], prezime[21];
}student;

float prosjek_izracun(int ukupno, int ocjena[]);




int main(){

int i,j,MAX;
char enter;
student Student[MAX];

printf("\nUnesite max kolicinu unosa: ");
scanf("%d",&MAX);

for (i=0;i<MAX;i++){
    printf("\n\nUnesite Ime i prezime %d. studenta",i+1);
    scanf("%20s %20s",Student[i].ime,Student[i].prezime);

    printf("\nUnesite JMBAG %d. studenta",i+1);
    scanf("%d",&Student[i].jmbag);

    printf("\nUnesite Godinu rodenja %d. studenta",i+1);
    scanf("%d",&Student[i].god_rod);

    printf("\nUnesite ukupni broj ocjena %d. studenta",i+1);
    scanf("%d",&Student[i].br_ocjena);

        for (j=0;j<=Student[i].br_ocjena;j++){
        printf("\n Unesite ocjenu za %d predmet ", j+1);
        scanf("%d",&Student[i].ocjene[j]);
        }

}




return 0;
}





float prosjek_izracun(int ukupno, int ocjena[]){
int i;
float suma, prosjek;
for (i=0; i<=ukupno; i++)
    suma+=ocjena[i];

prosjek=suma/ukupno;

return prosjek;
};