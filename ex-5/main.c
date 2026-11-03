#include <stdio.h>

int main() {
    int nb;
    int count = 0;
    char pas;
    printf("Choose a symbol:\n > + \n > - \n Symbol: ");
    scanf("%s", &pas);
    printf("Enter a number greater than 0: ");
    scanf("%d", &nb);
    if (pas == 43) {
        while (nb >= count) {
            printf("%d\n", count);
            count++;
        }
    } else if (pas == 45) {
        while (nb >= count) {
            printf("%d\n", nb);
            nb--;
        }
    } else {
        printf("Invalid symbol. Please choose either '+' or '-'.\n");
    }
}