#include <stdio.h>
#include <string.h>

int calcular_operacoes(char* A, char* B) {
    int operacoes = 0;
    int tamanho = strlen(A);

    for (int i = 0; i < tamanho; i++) {
        int diferenca = B[i] - A[i];
        if (diferenca < 0) {
            diferenca += 26;  // Corrige se a diferença for negativa (ciclo no alfabeto)
        }
        operacoes += diferenca;
    }

    return operacoes;
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        char A[10001], B[10001];
        scanf("%s %s", A, B);
        printf("%d\n", calcular_operacoes(A, B));
    }

    return 0;
}
