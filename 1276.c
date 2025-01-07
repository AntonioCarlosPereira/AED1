#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_LEN 51

// Função para comparar caracteres (usada no qsort)
int compare_chars(const void *a, const void *b) {
    return (*(char *)a - *(char *)b);
}

// Função para processar uma linha e imprimir as faixas
void processar_faixas(char *linha) {
    char letras[MAX_LEN] = {0};
    int n = 0;

    // Filtrar letras únicas e ignorar espaços
    for (int i = 0; linha[i] != '\0'; i++) {
        if (linha[i] >= 'a' && linha[i] <= 'z') {
            if (!strchr(letras, linha[i])) {  // Adiciona apenas letras únicas
                letras[n++] = linha[i];
            }
        }
    }

    // Se não há letras, imprimir uma linha em branco
    if (n == 0) {
        printf("\n");
        return;
    }

    // Ordenar as letras
    qsort(letras, n, sizeof(char), compare_chars);

    // Encontrar e imprimir as faixas
    int inicio = 0;
    for (int i = 1; i <= n; i++) {
        if (i == n || letras[i] != letras[i - 1] + 1) {
            // Imprimir faixa
            if (inicio == i - 1) {
                printf("%c:%c", letras[inicio], letras[inicio]);  // Faixa única
            } else {
                printf("%c:%c", letras[inicio], letras[i - 1]);  // Faixa múltipla
            }
            if (i < n) {
                printf(", ");
            }
            inicio = i;
        }
    }
    printf("\n");
}

int main() {
    char linha[MAX_LEN];

    // Ler múltiplas linhas até EOF
    while (fgets(linha, MAX_LEN, stdin)) {
        processar_faixas(linha);
    }

    return 0;
}
