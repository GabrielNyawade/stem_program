#include <stdio.h>

int main() {

    int spaces, stars;

    for (int i = 1; i <= 5; i++) {
        // Print spaces before the stars
        for (spaces = 1; spaces <= 5 - i; spaces++) {
            printf(" ");
        }

        // Print stars for current row
        for (stars = 1; stars <= 2 * i - 1; stars++) {
            printf("*");
        }

        printf("\n");  // Move to the next line after each row
    }
    
    
    for (int i = 4; i >= 1; i--) {
        // Print spaces before the stars
        for (spaces = 0; spaces <= 4 - i; spaces++) {
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
