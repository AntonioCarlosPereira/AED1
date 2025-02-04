#include <stdio.h>
#include <string.h>

void remover_zeros(char *str) {
    int i, j = 0;
    char temp[20];
    
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] != '0') {
            temp[j++] = str[i];
        }
    }
    temp[j] = '\0';
    strcpy(str, temp);
}

int main() {
    int M, N, soma;
    char resultado[20];
    
    while (scanf("%d %d", &M, &N) && !(M == 0 && N == 0)) {
        soma = M + N;
        sprintf(resultado, "%d", soma);
        remover_zeros(resultado);
        printf("%s\n", resultado);
    }
    
    return 0;
}
