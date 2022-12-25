#include <stdio.h>
#include <math.h>

int main()
{
    float eur, kn;

    printf("\n Program ispisuje EUR za unesene HRK\n");
    printf("\n Unesi HRK: ");
    scanf("%f", &kn);

    eur = kn/(7.53450);

    printf("\n\n EUR: %6.2f \n\n", eur);



    return 0;

}
