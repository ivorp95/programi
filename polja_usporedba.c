#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>


int main(){
srand(time(NULL));

int polje_rand[6], polje_usr[6], polje_pogodak[6] = { 0,0,0,0,0,0 };
int i, j;
int suma=0;

for (i = 0; i < 6; i++) {
polje_rand[i] = (rand() % 30) + 1;
printf("\t%d", polje_rand[i]);   //ispis rand brojeva
 }

for (i = 0; i < 6; i++) {
printf("\n Pogodi %d. element polja brojeva do 30 :\n", i + 1);
scanf_s("\t %d", &polje_usr[i]);
}

for (i = 0; i < 6; i++) {

for (j = 0; j < 6; j++) {
if(polje_usr[j]==polje_rand[i])
polje_pogodak[i] = 1;        //ako je pogodjeno. za izaci iz nutarnje petlje da se ne prolazi cijelo polje
 }
}

for (i = 0; i < 6; i++) {
suma = suma + polje_pogodak[i];
}
printf("\n pogodeno je %d brojeva\n", suma);

for (i = 0; i < 6; i++) {
if (polje_pogodak[i]==1)
printf("\n pogodeni brojevi su: %d\n", polje_rand[i]);
}

for (i=0; i < 6; i++) {
if (polje_pogodak[i] == 0)
printf("\n ne pogodjeni brojevi su: %d\n", polje_rand[i]);
}

return 0;
}