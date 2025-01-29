#include <stdio.h>
#include <string.h>

int eh_vogal(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int eh_palindromo(char* risada) {
    int n = strlen(risada);
    for (int i = 0; i < n / 2; i++) {
        if (risada[i] != risada[n - 1 - i]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char risada[51];
    scanf("%s", risada);

    char vogais[51];
    int j = 0;
    for (int i = 0; i < strlen(risada); i++) {
        if (eh_vogal(risada[i])) {
            vogais[j++] = risada[i];
        }
    }
    vogais[j] = '\0';

    if (eh_palindromo(vogais)) {
        printf("S\n");
    } else {
        printf("N\n");
    }

    return 0;
}
