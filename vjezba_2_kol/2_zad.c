#include "stdio.h"
#include "math.h"





int main (){

float x, z;
float* pbroj_1=&x, *pbroj_3=&z;       //pointeri za svoju vrijednost dobivaju adrese varijabli x y z

int y;
int* pbroj_2=&y;

printf("unesi realni broj x: ");
scanf("%f", &*pbroj_1);             //vrijednosti unesene scanf-om se spremaju na adrese koje cuvaju *pointer verijable
printf("unesi cijeli broj y: ");
scanf("%d", &*pbroj_2);

*pbroj_3=cosf(*pbroj_1)-2*(*pbroj_2);   // dobivena vrijednost z se sprema na adresu koju cuva *pointer varijabla



printf(" Z = cos(x)-2y =   %.3f \n", *pbroj_3);     //printf ispisuje vrijednost na adresi koju cuva *pointer varijabla

    return 0;
}