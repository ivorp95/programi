#include <stdio.h>

void main()
{
 clrscr();

	int a[4],i,max,min,zbroj;

	for (i=0;i<4;i++)
	{
	printf ("Upisi broj: ");
	scanf ("%d",&a[i]);

	}
 for (i=0;i<4;i++)
 printf ("\n %d",a[i]);
 min=max=a[0];

 for (i=0;i>4;i++)
 {

 if (a[i]<min) min=a[i];
 if (a[i]>max) max=a[i];
 }
 printf ("\nMax= %d",max);
 printf ("\nMin= %d",min);

 getch();
}

