#include<stdio.h>
#define MAX 8


void bubbleInt(int polje[], int dulj);
void selectionInt(int polje[], int dulj);
void insertionInt(int polje[], int dulj);

void bubbleChar(char polje[], int dulj);

int main()
{
	int poljeInt[MAX];
	char poljeChar[MAX];
	int i;

	
	/* sortiranje integera
	for (i = 0; i < MAX; i++)
	{
		printf("\n poljeInt[%d] = ", i);
		scanf("%d", &poljeInt[i]);
	}
	bubbleInt(poljeInt, MAX);
	*/
	//selectionInt(poljeInt, MAX);
	//insertionInt(poljeInt, MAX);
	

	
	// sortiranje znakova
	for (i = 0; i < MAX; i++)
	{
		printf("\n poljeChar[%d] = ", i);
		scanf(" %c", &poljeChar[i], 1);
	}
	bubbleChar(poljeChar, MAX);
	

	printf("\n\n");
}


void bubbleInt(int polje[], int dulj)
{
	int i, j, k, temp, flag;

	printf("\n\n --- BUBBLE SORT ---");

	for (i = 0; i < dulj - 1; i++)
	{
		flag = 0;
		for (j = 0; j < dulj - 1 - i; j++)
		{
			if (polje[j + 1] < polje[j])
			{
				temp = polje[j];
				polje[j] = polje[j + 1];
				polje[j + 1] = temp;
				flag = 1;
			}
		}

		if (flag == 0)
		{
			break;
		}

		printf("\n\n %d. prolaz: ", i + 1);
		for (k = 0; k < dulj; k++)
		{
			printf("%d ", polje[k]);
		}
	}
}


void selectionInt(int polje[], int dulj)
{
	int i, j, j_min, k, temp;

	printf("\n\n --- SELECTION SORT ---");

	for (i = 0; i < dulj - 1; i++)
	{
		j_min = i;

		for (j = i + 1; j < dulj; j++)
		{
			if (polje[j] < polje[j_min])
			{
				j_min = j;
			}
		}

		if (j_min != i)
		{
			temp = polje[i];
			polje[i] = polje[j_min];
			polje[j_min] = temp;
		}
		
		printf("\n\n %d. prolaz: ", i + 1);
		for (k = 0; k < dulj; k++)
		{
			printf("%d ", polje[k]);
		}
	}
}


void insertionInt(int polje[], int dulj)
{
	int i, j, k, temp;

	printf("\n\n --- INSERTION SORT ---");

	for (i = 1; i < dulj; i++)
	{
		temp = polje[i];

		for (j = i - 1; j >= 0; j--)
		{
			if (polje[j] > temp)
			{
				polje[j + 1] = polje[j];
			}
			else
			{
				break;
			}
		}
		polje[j + 1] = temp;

		printf("\n\n %d. prolaz: ", i);
		for (k = 0; k < dulj; k++)
		{
			printf("%d ", polje[k]);
		}
	}
}


void bubbleChar(char polje[], int dulj)
{
	int i, j, k, flag;
	char temp;

	for (i = 0; i < dulj - 1; i++)
	{
		flag = 0;
		for (j = 0; j < dulj - 1 - i; j++)
		{
			if (polje[j + 1] < polje[j])
			{
				temp = polje[j];
				polje[j] = polje[j + 1];
				polje[j + 1] = temp;
				flag = 1;
			}
		}

		if (flag == 0)
		{
			break;
		}

		printf("\n\n %d. prolaz: ", i + 1);
		for (k = 0; k < dulj; k++)
		{
			printf("%c ", polje[k]);
		}
	}
}
