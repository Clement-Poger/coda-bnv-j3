#include <stdio.h>

int main() {
    int nb;
    printf("Enter a number: ");
    scanf("%d", &nb);
    if (nb > 42) {
        printf("The number is greater than 42.\n");
    } else if (nb < 42) {
        printf("The number is less than 42.\n");
    } else {
        printf("The number is equal to 42.\n");
    }
}