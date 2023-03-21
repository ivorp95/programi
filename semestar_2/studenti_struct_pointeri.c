#include <stdio.h>
#include <math.h>
#include <string.h>
#define MAX 50


typedef struct {
    int br_ocjena, god_rod;
    unsigned int jmbag;
    int ocjene[20];
    float prosjek;
    char ime[21], prezime[21];
}Student;


float prosjek_izracun(int ukupno, int ocjena[]);

void unos_vrijednosti(Student* pstudent);

void ispis_vrijednosti(Student* pstudent);





int main() {

    int i, j, unos;

    Student student[MAX], * pstudent;




    do {
        printf("\nUnesite kolicinu unosa (MAX 50): ");
        scanf_s("%d", &unos);
    } while (unos > MAX || unos < 1);


    pstudent = &student[0];
    unos_vrijednosti(&pstudent);

    pstudent = &student[0];
    ispis_vrijednosti(&pstudent);



    return 0;
}


float prosjek_izracun(int ukupno, int ocjena[]) {
    int i;
    float suma = 0, prosjek = 0;

    for (i = 0; i < ukupno; i++)
        suma += ocjena[i];

    return prosjek = suma / ukupno;
};









void unos_vrijednosti(Student* pstudent) {

    for (int i = 0; i < MAX; i++) {
        printf("\n\nUnesite Ime  %d. studenta: ", i + 1);
        scanf_s("%20s", pstudent->ime);
        printf("\nUnesite Prezime  %d. studenta: ", i + 1);
        scanf_s("%20s", pstudent->prezime);

        printf("\nUnesite JMBAG %d. studenta: ", i + 1);
        scanf_s("%u", &pstudent->jmbag);

        printf("\nUnesite Godinu rodenja %d. studenta: ", i + 1);
        scanf_s("%d", &pstudent->god_rod);

        printf("\nUnesite ukupni broj ocjena %d. studenta: ", i + 1);
        scanf_s("%d", &pstudent->br_ocjena);


        for (int j = 0; j < pstudent->br_ocjena; j++) {
            printf("\n Unesite ocjenu za %d predmet: ", j + 1);
            scanf_s("%d", &pstudent->ocjene[j]);
        }

        pstudent->prosjek = prosjek_izracun(pstudent->br_ocjena, pstudent->ocjene);

    }
    pstudent++;
}





void ispis_vrijednosti(Student* pstudent) {

    for (int i = 0; i < MAX; i++) {
        printf("\n %d. Student: \n\t Ime i prezime: %s %s \n\t JMBAG: %d \n\t Godiste: %d \n\t Ocjenjeno %d predmeta \n\t Prosjek ocjena: %.2f \n", i + 1, pstudent->ime, pstudent->prezime, pstudent->jmbag, pstudent->god_rod, pstudent->br_ocjena, pstudent->prosjek);

    }



}