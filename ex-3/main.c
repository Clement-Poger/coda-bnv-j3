#include <stdio.h>

int main() {
    char word[100];
    int times = 5;
    printf("Enter a word: ");
    scanf("%99s", word);
    while (times > 0) {
        printf("%d, %s\n", (5-times), word);
        times--;
    }
}