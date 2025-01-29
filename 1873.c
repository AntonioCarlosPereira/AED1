#include <stdio.h>
#include <string.h>

const char* determinar_vencedor(const char* escolha1, const char* escolha2) {
    if (strcmp(escolha1, escolha2) == 0) {
        return "empate";
    }
    
    if ((strcmp(escolha1, "tesoura") == 0 && (strcmp(escolha2, "papel") == 0 || strcmp(escolha2, "lagarto") == 0)) ||
        (strcmp(escolha1, "papel") == 0 && (strcmp(escolha2, "pedra") == 0 || strcmp(escolha2, "spock") == 0)) ||
        (strcmp(escolha1, "pedra") == 0 && (strcmp(escolha2, "lagarto") == 0 || strcmp(escolha2, "tesoura") == 0)) ||
        (strcmp(escolha1, "lagarto") == 0 && (strcmp(escolha2, "spock") == 0 || strcmp(escolha2, "papel") == 0)) ||
        (strcmp(escolha1, "spock") == 0 && (strcmp(escolha2, "tesoura") == 0 || strcmp(escolha2, "pedra") == 0))) {
        return "rajesh";
    } else {
        return "sheldon";
    }
}

int main() {
    int C;
    scanf("%d", &C);

    while (C--) {
        char escolha1[20], escolha2[20];
        scanf("%s %s", escolha1, escolha2);
        printf("%s\n", determinar_vencedor(escolha1, escolha2));
    }

    return 0;
}
