#include "stdio.h"
#include "math.h"





int main (){

float x, z;
float* pbroj_1=&x, *pbroj_3=&z;       //pointeri za svoju vrijednost dobivaju adrese varijabli

int y;
int* pbroj_2=&y;

printf("unesi realni broj x: ");
scanf("%f", &*pbroj_1);
printf("unesi cijeli broj y: ");
scanf("%d", &*pbroj_2);

*pbroj_3=cosf(*pbroj_1)-2*(*pbroj_2);



printf(" Z = cos(x)-2y =   %.3f \n", *pbroj_3);

    return 0;
}