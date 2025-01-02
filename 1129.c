#include <stdio.h>

void process_respostas() {
    while (1) {
        int n;
        scanf("%d", &n);
        if (n == 0) {
            break;
        }

        for (int i = 0; i < n; i++) {
            int valores[5];
            for (int j = 0; j < 5; j++) {
                scanf("%d", &valores[j]);
            }

            int marcados[5] = {0};
            int count = 0, index = -1;

            // Classifica os valores como preto ou branco
            for (int j = 0; j < 5; j++) {
                if (valores[j] <= 127) {
                    count++;
                    index = j;
                }
            }

            // Verifica se há exatamente uma alternativa marcada
            if (count == 1) {
                printf("%c\n", 'A' + index);
            } else {
                printf("*\n");
            }
        }
    }
}

int main() {
    process_respostas();
    return 0;
}
