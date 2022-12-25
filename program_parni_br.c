
#include<stdio.h>
#include<math.h>


int main()
{

	int a, b;

	printf("\n Program provjerava je li uneseni a parni broj.\n");

	printf("Unesi a: ");
	scanf("%d", &a);

	b = a % 2;

	if (b != 1) {
		printf("\n Uneseni a JE parni broj.\n");
	}
	else {
		printf("\n Uneseni a NIJE parni broj.\n");
	}


	return 0;
}
