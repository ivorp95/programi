#include <stdio.h>
#include <math.h>
#include <stdlib.h>


float prosjecnaTemp(float* Ppolje, int brojUnosa);

int main (){

    float temperature[10];
    int brojUnosaS;
    float prosjek;

    printf("Unesite broj unosa koje zelite pohraniti ");
    scanf("%d",&brojUnosaS);

    printf("Unesite temperature za %d dana : \n", brojUnosaS);

    for(int i=0;i<brojUnosaS;i++){
        scanf("%f", &temperature[i]);
    }



    prosjek = prosjecnaTemp(&temperature[0], brojUnosaS);

        printf("Prosjecna temperatura: %.2f \n", prosjek);


    return 0;

}


float prosjecnaTemp(float* Ppolje,int brojUnosa){

    float prosjek;
    float suma=0;

    for(int i=0; i<brojUnosa; i++){
        suma+=Ppolje[i];
    }
    prosjek=(suma/brojUnosa);

    return prosjek;
}