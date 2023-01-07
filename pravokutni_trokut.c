#include<stdio.h>

//program ispisuje pravkoutni trokut od zvijezdica sa brojem redaka koje unosi korisnik

int main()
{
int i, j, n;

printf("\n Program ispisuje pravokutni trokut sa brojem redaka koje unese korisnik");
printf("\n Unesi broj redaka :");
scanf("%d", &n );
printf("\n\n");

for (i=1; i<=n; i++){
    for (j=1; j<=i; j++){
        printf("@");
    }
    printf("\n");
}

return 0;
}