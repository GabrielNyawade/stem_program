#include <stdio.h>

int main() {
    int rows = 5;  // Number of rows for the triangle
    int spaces, stars;

    for (int i = 1; i <= rows; i++) {
        // Print spaces before the stars
        for (spaces = 1; spaces <= rows - i; spaces++) {
            printf(" ");
        }

        // Print stars for current row
        for (stars = 1; stars <= 2 * i - 1; stars++) {
            printf("*");
        }

        printf("\n");  // Move to the next line after each row
    }

    return 0;
}
