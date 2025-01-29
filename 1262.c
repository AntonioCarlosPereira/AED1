#include <stdio.h>
#include <string.h>

int calcular_ciclos(const char *rastro, int processos) {
    int ciclos = 0, i, tamanho = strlen(rastro);
    
    for (i = 0; i < tamanho; i++) {
        if (rastro[i] == 'W') {
            ciclos++; // Cada gravação precisa de um ciclo exclusivo
        } else { // rastro[i] == 'R'
            ciclos++; // Conta um ciclo para o bloco de leituras
            int count = 0;
            while (i < tamanho && rastro[i] == 'R' && count < processos) {
                count++;
                i++;
            }
            i--; // Ajuste porque o loop principal também incrementa i
        }
    }
    
    return ciclos;
}

int main() {
    char rastro[51];
    int processos;
    
    while (scanf("%s", rastro) != EOF) {
        scanf("%d", &processos);
        printf("%d\n", calcular_ciclos(rastro, processos));
    }
    
    return 0;
}
