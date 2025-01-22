#include <stdio.h>

int main() {
    int t1, t2, t3, t4;

    // Lê o número de tomadas de cada régua
    scanf("%d %d %d %d", &t1, &t2, &t3, &t4);

    // Calcula o número máximo de tomadas disponíveis
    // Subtrai 1 de cada régua, exceto da primeira, porque a régua é ligada na anterior
    int max_aparelhos = (t1 + t2 + t3 + t4) - 3;

    // Imprime o resultado
    printf("%d\n", max_aparelhos);

    return 0;
}
