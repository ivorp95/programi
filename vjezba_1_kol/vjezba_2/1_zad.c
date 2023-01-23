#include<stdio.h>
#include<math.h>



int main()
{
	int broj1, broj2, i, suma;


	do {
		printf("\n unesi prvi negativni cijeli broj:  ");
		scanf("%d", &broj1);
	} while (broj1 >= 0);

	do {
		printf("\n unesi drugi negativni cijeli broj:  ");
		scanf("%d", &broj2);
	}while (broj2 >= 0 && broj2/broj1>=1 );  //////////////

	i = broj2;
	suma = i;

	for (i >= broj2; i++;) {

		suma = suma + i;

	}

	
	

	printf("\n suma je: %d ", suma);



	return 0;
}

