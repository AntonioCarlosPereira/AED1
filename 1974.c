não finalizado


#include <stdio.h>

int main() {
    int n;  // Número de estrelas
    scanf("%d", &n);

    int sitios[n];  // Carneiros em cada estrela
    long long tot = 0;  // Total de carneiros restantes (usa long long para segurança)

    // Lê a quantidade de carneiros em cada estrela
    for (int i = 0; i < n; ++i) {
        scanf("%d", &sitios[i]);
        tot += sitios[i];  // Soma os carneiros ao total
    }

    int i = 0;         // Índice da estrela atual
    int estrelasAtacadas = 0;  // Contador de estrelas atacadas

    // Realiza a jornada
    while (i >= 0 && i < n) {
        if (sitios[i] > 0) {
            ++estrelasAtacadas;  // Incrementa o contador de estrelas atacadas
        }

        // Verifica se a estrela atual tem carneiros para roubar
        if (sitios[i] > 0) {
            --sitios[i];  // Rouba um carneiro
            --tot;        // Atualiza o total de carneiros
        }

        // Determina o próximo movimento
        if (sitios[i] % 2 == 1) {
            ++i;  // Vai para a próxima estrela (índice +1)
        } else {
            --i;  // Vai para a estrela anterior (índice -1)
        }
    }

    // Imprime o número de estrelas atacadas e o total de carneiros restantes
    printf("%d %lld\n", estrelasAtacadas, tot);

    return 0;
}
