#include<stdio.h>
#include<math.h>


int main()
{

	float a, b, c, opseg;
	printf("\n Program izračunava Opseg trokuta za unesene stranice a, b, c.\n");

	printf("Unesi a: ");
	scanf_s("%f", &a);

	printf("Unesi b: ");
	scanf_s("%f", &b);

	printf("Unesi c: ");
	scanf_s("%f", &c);

	opseg = a + b + c;
	printf("\n Opseg iznosi: %4.2f \n", opseg);


	return 0;
}

