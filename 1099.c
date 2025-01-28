#include <stdio.h>

int main() {
    char nome[50];
    double salarioFixo, totalVendas, comissao, totalReceber;

    // Entrada de dados
    scanf("%s", nome);
    scanf("%lf %lf", &salarioFixo, &totalVendas);

    // Cálculo do total a receber
    comissao = totalVendas * 0.15;
    totalReceber = salarioFixo + comissao;

    // Saída formatada
    printf("TOTAL = R$ %.2lf\n", totalReceber);

    return 0;
}