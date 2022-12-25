
#include<stdio.h>
#include<math.h>


int main()
{

	float a, b, c, d;
	printf("\n Program izracunava polovinu, cetvrtinu, i osminu za uneseni a.\n");

	printf("Unesi a: ");
	scanf("%f", &a);

	b = a / 2;
	c = b / 2;
	d = c / 2;

	printf("\n b= %2.6f \n c= %2.6f \n d= %2.6f", b, c, d);


	return 0;
}
