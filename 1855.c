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
    char atual;
    
        // Verifica se a posição inicial é uma flecha válida ou o baú
    if (matriz[0][0] != '>' && matriz[0][0] != '<' &&
        matriz[0][0] != 'v' && matriz[0][0] != '^' &&
        matriz[0][0] != '*') {
        return '!'; // Mapa inválido
    }


    while (1) {
        // Verifica se a posição está fora dos limites
        if (x < 0 || x >= altura || y < 0 || y >= largura) {
            return '!';
        }

        // Verifica se a posição atual já foi visitada
        if (foi_visitada(x, y, flechas, n_flechas)) {
            return '!';
        }

        // Armazena a posição atual no vetor de flechas
        flechas[n_flechas][0] = x;
        flechas[n_flechas][1] = y;
        n_flechas++;

        // Verifica o conteúdo da casa atual
        atual = matriz[x][y];
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
        } else {
            return '!';  // Qualquer outro caractere é inválido
        }
    }
}

int main() {
    int largura, altura;
    char matriz[MAX][MAX];

    // Lê a largura e a altura do mapa
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
