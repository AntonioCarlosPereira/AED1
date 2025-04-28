#include <stdio.h>
#include <stdlib.h>

// Função de troca
void swap(int *a, int *b, int *count_swap) {
    if (a != b) {
        int temp = *a;
        *a = *b;
        *b = temp;
        (*count_swap)++;
    }
}

// Função de Selection Sort
void selectionSort(int *arr, int n, int *comp, int *swap_count) {
    for (int i = 0; i < n-1; i++) {
        int min_idx = i;
        for (int j = i+1; j < n; j++) {
            (*comp)++;
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if (i != min_idx) {
            swap(&arr[i], &arr[min_idx], swap_count);
        }
    }
}

// Função de Bubble Sort
void bubbleSort(int *arr, int n, int *comp, int *swap_count) {
    int sorted;
    for (int i = 0; i < n-1; i++) {
        sorted = 1;
        for (int j = 0; j < n-i-1; j++) {
            (*comp)++;
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1], swap_count);
                sorted = 0;
            }
        }
        if (sorted) {
            break;
        }
    }
}

// Função de Insertion Sort
void insertionSort(int *arr, int n, int *comp, int *move_count) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0) {
            (*comp)++;
            if (arr[j] > key) {
                arr[j + 1] = arr[j];
                (*move_count)++;
                j--;
            } else {
                break;
            }
        }
        if (j + 1 != i) { // Se mudou de posição
            arr[j + 1] = key;
            (*move_count)++;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int *original = (int*) malloc(n * sizeof(int));
    if (original == NULL) {
        return 1; // Erro de alocação
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &original[i]);
    }

    int *copy = (int*) malloc(n * sizeof(int));
    if (copy == NULL) {
        free(original);
        return 1; // Erro de alocação
    }

    int comp, swap_move;

    // Selection Sort
    for (int i = 0; i < n; i++) copy[i] = original[i];
    comp = 0;
    swap_move = 0;
    selectionSort(copy, n, &comp, &swap_move);
    printf("%d %d\n", comp, swap_move);

    // Bubble Sort
    for (int i = 0; i < n; i++) copy[i] = original[i];
    comp = 0;
    swap_move = 0;
    bubbleSort(copy, n, &comp, &swap_move);
    printf("%d %d\n", comp, swap_move);

    // Insertion Sort
    for (int i = 0; i < n; i++) copy[i] = original[i];
    comp = 0;
    swap_move = 0;
    insertionSort(copy, n, &comp, &swap_move);
    printf("%d %d\n", comp, swap_move);

    free(original);
    free(copy);

    return 0;
}