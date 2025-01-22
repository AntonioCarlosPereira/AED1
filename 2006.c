#include <stdio.h>

int main() {
    int T;  // Tipo de chá
    scanf("%d", &T);

    int respostas[5];  // Respostas dos cinco competidores
    int acertos = 0;

    // Leitura das respostas dos competidores
    for (int i = 0; i < 5; i++) {
        scanf("%d", &respostas[i]);
    }

    // Verifica quantos competidores acertaram
    for (int i = 0; i < 5; i++) {
        if (respostas[i] == T) {
            acertos++;
        }
    }

    // Imprime o número de acertos
    printf("%d\n", acertos);

    return 0;
}
