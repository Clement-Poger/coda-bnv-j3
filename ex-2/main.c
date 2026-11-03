#include <stdio.h>

int main() {
    char op;
    printf("Choose an Operation Symbol among +, -, *, /, %: ");
    scanf("%c", &op);
    if (op == 43) {
        printf("\nYou choose addition.\n");
    } else if (op == 45) {
        printf("\nYou choose subtraction.\n");
    } else if (op == 42) {
        printf("\nYou choose multiplication.\n");
    } else if (op == 47) {
        printf("\nYou choose division.\n");
    } else if (op == 37) {
        printf("\nYou choose modulo.\n");
    } else {
        printf("\nUnknown symbol. Please repeat.\n");
        main();
    }
}