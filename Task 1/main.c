#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT_LENGTH 1000

int main() {
    int i, counter;
    scanf_s("%d", &counter);

    for (i = 0; i < counter; i++) {
        long numOfBags, numOfChildren, numOfCandies = 0;

        scanf_s("%ld %ld", &numOfBags, &numOfChildren);
        char* numOfCandiesSTR = (char*)calloc(sizeof(char), numOfBags * INPUT_LENGTH);

        getchar();
        fgets(numOfCandiesSTR, numOfBags * INPUT_LENGTH, stdin);
        
        int j = 0;
        do {
            long numOfCandiesInBag = 0;
            while (numOfCandiesSTR[j] != ' ' && numOfCandiesSTR[j] != '\n') {
                numOfCandiesInBag += (int)*(numOfCandiesSTR + j) - '0';

                if (numOfCandiesSTR[j + 1] != ' ') {
                    if(numOfCandiesSTR[j + 1] != '\n')
                        numOfCandiesInBag *= 10;
                }
                j++;
            }

            j++;
            numOfCandies += numOfCandiesInBag;
        } while (numOfCandiesSTR[j]);

        numOfCandiesSTR = NULL;
        free(numOfCandiesSTR);
        numOfCandies %= numOfChildren;
        printf("Case #%d: %ld\n", i + 1, numOfCandies);
    }
}