/*
to generate Pascal's Triangle.
Output:
no.of.rows =5
*/


#include <stdio.h>

int main() {
    int rows = 5, coef = 1;

    for (int i = 0; i < rows; i++) {
        // Print leading spaces for formatting
        for (int space = 1; space <= rows - i; space++) {
            printf("  ");
        }
        
        // Print Pascal's Triangle values
        for (int j = 0; j <= i; j++) {
            if (j == 0 || i == 0) {
                coef = 1;
            } else {
                coef = coef * (i - j + 1) / j;
            }
            printf("%4d", coef);
        }
        printf("\n");
    }

    return 0;
}
