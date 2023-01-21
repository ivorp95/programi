#include <stdio.h>
#include <math.h>

int main ()
{
    float broj_a;
    float volumen;

    printf("\n Unesi a:  ");
    scanf("%f", &broj_a);

    if (broj_a<=0){
         printf("\n Broj mora biti veci od 0 \n");
    }
    else{

    volumen = sqrt(2)*pow(broj_a, 3)/12;


    printf("\n Volumen je: %.4f \n", volumen);
    }

    return 0;
}