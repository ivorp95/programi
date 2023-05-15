#include<stdio.h>


int main() {
	int polje[8];
	int i,j, temp, flag;
	for (i = 0; i < 8; i++) {
		printf("\n Unesi broj u polje[%d] = ", i);
		scanf_s("%d", &polje[i]);
	}

	for (i = 0; i < 8; i++) {
		printf("\n polje[%d] = %d", i, polje[i]);
	}

	for (j = 0; j < 8; j++) {

		flag = 0;
		
		for (i = 0; i < 7; i++) {
			if (polje[i] > polje[i + 1]) {
				temp = polje[i];
				polje[i] = polje[i + 1];
				polje[i + 1] = temp;
				flag = 1;
			}
		}

		if (flag == 0) 
			break; 

		printf("\n %d. prolaz: ", j + 1);
		for (i = 0; i < 8; i++) {
			printf(" %d",polje[i]);
		}
	}
	return 0;

}