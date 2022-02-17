#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define SIZE_OF_INPUTS 100000

void convertToIntArr(char* str, int* res);

int main() {
	int i, counter;
	scanf_s("%d", &counter);

	for (i = 0; i < counter; i++) {
		int numOfPapers;
		long j = 0;
		int H, hBiggerCount = 0;

		scanf_s("%d", &numOfPapers);

		char* citationsSTR = (char*)calloc(sizeof(char), (numOfPapers * SIZE_OF_INPUTS));
		getchar();
		fgets(citationsSTR, numOfPapers * SIZE_OF_INPUTS, stdin);

		int actLength = 0;
		while (citationsSTR[actLength] != '\n') {
			actLength++;
		}
		citationsSTR[actLength] = '\0';

		int* citations;
		citations = (int*)malloc(sizeof(int) * numOfPapers);
		convertToIntArr(citationsSTR, citations);

		printf("Case #%d:", i + 1);

		H = 1;
		for (j = 0; j < numOfPapers; j++) {
			for (int k = 0; k <= j; k++) {
				if (citations[k] > H) {
					hBiggerCount++;
					if (hBiggerCount > H || hBiggerCount == citations[k]) {
						H = hBiggerCount;
						break;
					}
				}
			}
			hBiggerCount = 0;
			printf(" %d", H);
		}

		printf("\n");
	}
	return 0;
}

void convertToIntArr(char* str, int* arr) {
	long i = 0, j = 0;
	do {
		int n = 0;
		while (str[j] != ' ' && str[j] != '\0') {
			n += (int)*(str + j) - '0';

			if (str[j + 1] != ' ') {
				if (str[j + 1] != '\0')
					n *= 10;
			}
			j++;
		}

		j++;

		*(arr + i) = n;
		i++;
	} while (str[j]);
}