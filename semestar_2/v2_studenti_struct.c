#include <stdio.h>
#include <math.h>
#include <string.h>
#define MAX 50

float prosjek_izracun(int ukupno, int ocjena[]);


int main(){

typedef struct{
    int jmbag,br_ocjena,god_rod;
    int ocjene[10];
    float prosjek;
    char ime[21], prezime[21];
}student;

int i,j,unos;
char enter;

do {
    printf("\nUnesite kolicinu unosa (MAX 50): ");
    scanf("%d",&unos);
}
while (unos>MAX || unos<1);

student Student[unos];

for (i=0;i<unos;i++){
    printf("\n\nUnesite Ime  %d. studenta: ",i+1);
    scanf("%20s",Student[i].ime);
    printf("\nUnesite Prezime  %d. studenta: ",i+1);
    scanf("%20s",Student[i].prezime);

    printf("\nUnesite JMBAG %d. studenta: ",i+1);
    scanf("%d",&Student[i].jmbag);

    printf("\nUnesite Godinu rodenja %d. studenta: ",i+1);
    scanf("%d",&Student[i].god_rod);

    printf("\nUnesite ukupni broj ocjena %d. studenta: ",i+1);
    scanf("%d",&Student[i].br_ocjena);


        for (j=0;j<Student[i].br_ocjena;j++){
        printf("\n Unesite ocjenu za %d predmet: ", j+1);
        scanf("%d",&Student[i].ocjene[j]);
        }

    Student[i].prosjek=prosjek_izracun(Student[i].br_ocjena, Student[i].ocjene);

}

for (i=0;i<unos;i++){
    printf("\n %d. Student: \n\t Ime i prezime: %s %s \n\t JMBAG: %d \n\t Godiste: %d \n\t Ocjenjeno %d predmeta \n\t Prosjek ocjena: %.2f \n",i+1, Student[i].ime,Student[i].prezime,Student[i].jmbag,Student[i].god_rod, Student[i].br_ocjena,Student[i].prosjek);
}



return 0;
}


float prosjek_izracun(int ukupno, int ocjena[]){
int i;
float suma=0, prosjek=0;

for (i=0; i<ukupno; i++)
    suma+=ocjena[i];

return prosjek=suma/ukupno;
};