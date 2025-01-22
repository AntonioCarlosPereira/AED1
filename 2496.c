#include <stdio.h>
#include <stdbool.h>

bool verificaOrdenacao(char *);

int main() {
    unsigned short casos, qtsLetras;
    scanf("%hu", &casos);

    while (casos--) {
        scanf("%hu", &qtsLetras);

        char alfabeto[qtsLetras + 1];
        scanf("%s", alfabeto);

        if (verificaOrdenacao(alfabeto))
            printf("There are the chance.\n");
        else
            printf("There aren't the chance.\n");
    }

    return 0;
}

bool verificaOrdenacao(char *alfabeto) {
    unsigned short i, qtsMudancas = 0, primeiro = -1, segundo = -1;

    for (i = 0; alfabeto[i] != '\0'; i++) {
        if (alfabeto[i] != 'A' + i) {
            qtsMudancas++;
            if (primeiro == -1) {
                primeiro = i;
            } else {
                segundo = i;
            }
        }
    }

    // Se houver mais de 2 letras fora do lugar ou as letras não puderem ser trocadas entre si
    if (qtsMudancas != 2 || alfabeto[primeiro] != 'A' + segundo || alfabeto[segundo] != 'A' + primeiro) {
        return false;
    }

    return true;
}
