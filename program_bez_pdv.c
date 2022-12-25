#include <stdio.h>
#include <math.h>

int main()
{
    float pdv = 25.0f, cijena, cijenaN;

    printf("\n Program ispisuje cijenu bez PDV-a \n");
    printf("\n Unesi cijenu:");
    scanf("%f", &cijena);

    cijenaN = cijena/(1+pdv/100);

    printf("\n\n Cijena bez PDV-a: %6.2f \n\n", cijenaN);



    return 0;

}
