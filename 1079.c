#include <stdio.h>

int main() {
    int n; // Número de casos de teste
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        double a, b, c; // Valores reais com uma casa decimal
        scanf("%lf %lf %lf", &a, &b, &c);

        // Calcula a média ponderada
        double media = (a * 2 + b * 3 + c * 5) / 10.0;

        // Imprime a média com uma casa decimal
        printf("%.1lf\n", media);
    }

    return 0;
}
