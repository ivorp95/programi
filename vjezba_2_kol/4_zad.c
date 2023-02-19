#include "stdio.h"

int main (){

FILE* pdatoteka;
int i;

pdatoteka=fopen("/users/ivorp/desktop/file","w");

if (pdatoteka){
printf("datoteka je kreirana\n");
    for(i=1;i<=100;i++){
        if(i%5==0)
        fprintf(pdatoteka,"\t%d\n",i);

    }
    if(fclose(pdatoteka)==0)
    printf("datoteka je zatvorena\n");
}
else {
printf("datoteka nije kreirana\n");
}

    return 0;
}
