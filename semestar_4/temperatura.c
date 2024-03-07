#include <stdio.h>
#include <math.h>
#include <stdlib.h>


float prosjecnaTemp(float* Ppolje, int brojUnosa);
void prosjecnaTemp2(float* Ppolje, int brojUnosa, float *prosjek);

int main (){

    float temperature[10];
    int brojUnosaS;
    float prosjek;

    do{
    printf("Unesite broj unosa koje zelite pohraniti - minimalno 1, maximalno 10 ");
    scanf("%d",&brojUnosaS);
    }
    while(brojUnosaS>10 || brojUnosaS<1);

    printf("Unesite temperature za %d dana : \n", brojUnosaS);

    for(int i=0;i<brojUnosaS;i++){
        scanf("%f", &temperature[i]);
    }



    //prosjek = prosjecnaTemp(&temperature[0], brojUnosaS);

    prosjecnaTemp2(temperature, brojUnosaS, &prosjek);


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



void prosjecnaTemp2(float* Ppolje, int brojUnosa, float *prosjek){
    
    float prosjekF;
    float suma=0;

    for(int i=0; i<brojUnosa; i++){
        //suma+=Ppolje[i];
        suma+= *(Ppolje+i); //moze polje[i] ili na adresi --- adresa prvog polja plus pomak za i --> *(polje+i)

    }
    prosjekF=(suma/brojUnosa);

    *prosjek=prosjekF;

}