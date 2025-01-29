#include <stdio.h>
#include <string.h>

int reconhecer_palavra(char* palavra) {
    if (strlen(palavra) == 3) {
        int one_erros = 0;
        int two_erros = 0;
        
        if (palavra[0] != 'o') one_erros++;
        if (palavra[1] != 'n') one_erros++;
        if (palavra[2] != 'e') one_erros++;
        
        if (palavra[0] != 't') two_erros++;
        if (palavra[1] != 'w') two_erros++;
        if (palavra[2] != 'o') two_erros++;
        
        if (one_erros <= 1) return 1;
        if (two_erros <= 1) return 2;
    } else if (strlen(palavra) == 5) {
        int erros = 0;
        char three[] = "three";
        for (int i = 0; i < 5; i++) {
            if (palavra[i] != three[i]) erros++;
        }
        if (erros <= 1) return 3;
    }
    return -1;
}

int main() {
    int n;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        char palavra[6];
        scanf("%s", palavra);
        printf("%d\n", reconhecer_palavra(palavra));
    }
    return 0;
}
