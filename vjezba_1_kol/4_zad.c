
#include <stdio.h>
#include <math.h>

int main ()
{
int broj_a, i=0;
float suma=0;  

do{

    printf("Unesi cijeli dvoznamenkasti broj: ");
    scanf("%d", &broj_a);
    i++;
    suma=suma+broj_a;
}
while(broj_a>=10);


printf("\nUkupno unesenih brojeva: %d\n", i);
printf("\nProsjek vrjednosti svih brojeva: %.2f\n", suma/i);

return 0;

}