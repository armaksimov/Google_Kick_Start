#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define INPUT_SIZE 400

bool isVowel(char c);

int main() {
	int i, counter;
	scanf_s("%d", &counter);

	for (i = 0; i < counter; i++) {
		char* kingdomName = (char*)calloc(sizeof(char), INPUT_SIZE);

		if (i == 0) {
			getchar();
		}
		fgets(kingdomName, INPUT_SIZE, stdin);

		int actLength = 0;
		while (kingdomName[actLength] != '\n') {
			actLength++;
		}
		kingdomName[actLength] = '\0';

		if (kingdomName[actLength - 1] == 'y') {
			printf("Case #%d: %s is ruled by nobody.\n", i + 1, kingdomName);
		}
		else if (isVowel(kingdomName[actLength - 1])) {
			printf("Case #%d: %s is ruled by Alice.\n", i + 1, kingdomName);
		}
		else {
			printf("Case #%d: %s is ruled by Bob.\n", i + 1, kingdomName);
		}
	}

	return 0;
}

bool isVowel(char c) {
	if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
		return true;
	}
	else {
		return false;
	}
}