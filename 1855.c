#include <stdio.h>
#include <string.h>

#define MAX 100

// Função para verificar se a casa atual já foi visitada
int foi_visitada(int x, int y, int flechas[MAX][2], int n_flechas) {
    for (int i = 0; i < n_flechas; i++) {
        if (flechas[i][0] == x && flechas[i][1] == y) {
            return 1;
        }
    }
    return 0;
}

// Função para percorrer a matriz
char percorrer_matriz(int altura, int largura, char matriz[MAX][MAX]) {
    int flechas[MAX][2];  // Vetor para armazenar as posições visitadas
    int n_flechas = 0;    // Contador de posições visitadas
    int x = 0, y = 0;     // Posição inicial

    // Verifica se a posição inicial é válida
    if (matriz[0][0] != '>' && matriz[0][0] != '<' &&
        matriz[0][0] != 'v' && matriz[0][0] != '^' &&
        matriz[0][0] != '*') {
        return '!'; // Posição inicial inválida
    }

    while (1) {
        // Verifica se a posição está fora dos limites
        if (x < 0 || x >= altura || y < 0 || y >= largura) {
            return '!'; // Sair do mapa é inválido
        }

        // Verifica se a posição atual já foi visitada
        if (foi_visitada(x, y, flechas, n_flechas)) {
            return '!'; // Encontrou um ciclo
        }

        // Armazena a posição atual no vetor de flechas
        flechas[n_flechas][0] = x;
        flechas[n_flechas][1] = y;
        n_flechas++;

        // Verifica o conteúdo da casa atual
        char atual = matriz[x][y];
        if (atual == '*') {
            return '*';  // Encontrou o baú
        } else if (atual == '>') {
            y++;  // Vai para a direita
        } else if (atual == '<') {
            y--;  // Vai para a esquerda
        } else if (atual == 'v') {
            x++;  // Vai para baixo
        } else if (atual == '^') {
            x--;  // Vai para cima
        } else if (atual == '.') {
        // Espaço atravessável, apenas continua
        // Não altera x nem y
        }else {
            return '!';  // Qualquer outro caractere é inválido
        }
    }
}

int main() {
    int largura, altura;
    char matriz[MAX][MAX];

    // Lê a largura e altura do mapa
    scanf("%d", &largura);
    scanf("%d", &altura);

    // Lê a matriz
    for (int i = 0; i < altura; i++) {
        scanf("%s", matriz[i]);
    }

    // Chama a função para percorrer a matriz e exibe o resultado
    printf("%c\n", percorrer_matriz(altura, largura, matriz));

    return 0;
}


    -iniciar uma matriz com altura y e largura x
    -preencher ela de acordo com as casas dadas ( ler como vetor\fgets)
    -função percorrer a matriz iniciando do (0,0)
    -a cada flecha que passar armazena-la em um vetor Flechas
    -a cada casa que passar comparala com o vetor Flechas se for igual-> break
    -se encontrar uma casa * printf("!")
