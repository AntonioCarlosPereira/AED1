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