#include<stdio.h>
#include<math.h>


int main()
{

	float a, b, c, opseg;
	printf("\n Program izračunava Opseg trokuta za unesene stranice a, b, c.\n");

	printf("Unesi a: ");
	scanf("%f", &a);

	printf("Unesi b: ");
	scanf("%f", &b);

	printf("Unesi c: ");
	scanf("%f", &c);

	opseg = a + b + c;
	printf("\n Opseg iznosi: %4.2f \n", opseg);


	return 0;
}