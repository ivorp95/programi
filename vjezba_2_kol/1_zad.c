#include "stdio.h"


char ascii_znak(int broj);



int main (){

char ascii;
int broj;

printf(" int: ");
scanf("%d", &broj);

ascii=ascii_znak(broj);
printf(" ascii: %c \n", ascii);

    return 0;

}



char ascii_znak(int broj){

if(broj>=33 && broj<=125 )
return broj;

else
    return 63;


}