
#include<stdio.h>


int main()
{
    int i, j, n;

    //i - broj redka
    //j - broj stupca
    //j<=n-i  za svaki redak od ukupnog - trenutni

    printf("\n Program ispisuje pravokutni trokut sa brojem redaka koje unese korisnik");
    printf("\n Unesi broj redaka :");
    scanf("%d", &n);
    printf("\n\n");

    for (i = 1; i <= n; i++) {

        for (j = 1; j <= (n-i); j++) {
            printf(" ");
        }

        for (j = 1; j <= i; j++) {
            printf("@ ");
        }
        printf("\n");
    }

    return 0;
}
