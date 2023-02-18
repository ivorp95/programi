#include "stdio.h"
#include "string.h"

int main (){

int i,duljina;
char rijec[21], naopako[21];


printf("unesite rijec: ");
scanf("%20s", rijec);
duljina=strlen(rijec)-1; 

for(i=0; i<=duljina; i++){
    naopako[duljina-i]=rijec[i];
}

naopako[strlen(rijec)]='\0';


for(i=0; i<duljina; i++){
printf("%c+",naopako[i]);
}
printf("%c\n",naopako[i]);

    return 0;
}