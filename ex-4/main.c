#include <stdio.h>

int main() {
    int nb;
    int count = 0;
    printf("Enter a number greater than 0: ");
    scanf("%d", &nb);
    while (nb > count) {
        printf("%d\n", count);
        count++;
    }
}