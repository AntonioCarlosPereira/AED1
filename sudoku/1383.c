#include<stdio.h>

        // Verifica se o array contém todos os números de 1 a 9
int check_numbers(int numbers[9]) {
    for (int i = 0; i < 9; i++) {
        // utilizei para verificar as casas da matriz um array no qual todas as suas casas 
        //devem ser iguais a 1, caso isso não ocorra significa que alguma casa esta faltando
        //e que algum numero foi repetido
        if (numbers[i] != 1) return 0;
    }
    return 1;
}

        // Verifica se uma linha contém todos os números de 1 a 9
int check_linha(int matrix[9][9], int linha) {
    int numbers[9] = {0};
    for (int i = 0; i < 9; i++) {
        // Incrementa a contagem para cada número encontrado na linha(se alguma casa estiver repetida o resultado sera 2)
        numbers[matrix[linha][i] - 1]++;
    }
    return check_numbers(numbers);
}

        // Verifica se uma coluna contém todos os números de 1 a 9
int check_coluna(int matrix[9][9], int coluna) {
    int numbers[9] = {0};
    for (int i = 0; i < 9; i++) {
        // Incrementa a contagem para cada número encontrado na coluna
        numbers[matrix[i][coluna] - 1]++;
    }
    return check_numbers(numbers);
}

        // Verifica se uma sub-matriz 3x3 contém todos os números de 1 a 9
int check_sub_matrix(int matrix[9][9], int start_row, int start_col) {
    int numbers[9] = {0};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            // Incrementa a contagem para cada número encontrado na sub-matriz
            numbers[matrix[start_row + i][start_col + j] - 1]++;
        }
    }
    return check_numbers(numbers);
}

        // Verifica se a matriz de Sudoku é uma solução válida
int check_sudoku_solution(int matrix[9][9]) {
    for (int i = 0; i < 9; i++) {
        if (!check_linha(matrix, i) || !check_coluna(matrix, i)) return 0;
    }
    for (int i = 0; i < 9; i += 3) {
        for (int j = 0; j < 9; j += 3) {
            if (!check_sub_matrix(matrix, i, j)) return 0;
        }
    }
    return 1;
}

// Função principal
int main() {
    int n, matrix[9][9];
    scanf("%d", &n);
    for (int instance = 1; instance <= n; instance++) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                scanf("%d", &matrix[i][j]);
            }
        }
        printf("Instancia %d\n", instance);
        if (check_sudoku_solution(matrix)) {
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }
        printf("\n");
    }
    return 0;
}

