
#include <stdio.h>
#include <math.h>

int main ()
{
    int broj_a, broj_b, razlika;

    printf("\n Unesi a:  ");
    scanf("%d", &broj_a);

    printf("\n Unesi b:  ");
    scanf("%d", &broj_b);

    while(broj_a%broj_b != 0){
      printf("\n Unesi a:  ");
    scanf("%d", &broj_a);

    printf("\n Unesi b:  ");
    scanf("%d", &broj_b);  
    }
    
    razlika = broj_a - broj_b;
    printf("\n razlika brojeva je: %d \n", razlika);

    return 0;
}