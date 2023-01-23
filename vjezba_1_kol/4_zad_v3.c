#include <stdio.h>

int main ()
{

int i, broj;

do {
    printf("\n unesi cijeli dvoznamenkasti broj:");
    scanf("%d", &broj);
}
while(broj<10 || broj>99);

i=0;

while(i<=broj){

i=i+4;
printf("\n svaki cetvrti je: %d\n", i);
}


    return 0;
}