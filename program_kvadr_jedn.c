#include<stdio.h>
#include<math.h>


int main()
{

	float a, b, c, diskr, nazivnik, x1, x2;

	printf("\n Program izracunava x1 i x2 kvadratne jednadzbe za unesene a, b, c.\n");

	printf("Unesi a: ");
	scanf("%f", &a);

	printf("Unesi b: ");
	scanf("%f", &b);

	printf("Unesi c: ");
	scanf("%f", &c);

	diskr = pow(b, 2) - 4 * a * c;
	nazivnik = 2 * a;

	x1 = (-b + sqrt(diskr)) / nazivnik;
	x2 = (-b - sqrt(diskr)) / nazivnik;


	printf("\n x1= %2.2f \n x2= %2.2f ", x1, x2);

    printf("\n");


	return 0;
}
