#include <stdio.h>
#include <string.h>
#include <ctype.h>

void analisar_frase(char *frase) {
    int contagem[26] = {0};
    int diferentes = 0;
    
    for (int i = 0; frase[i] != '\0'; ++i) {
        if (isalpha(frase[i])) {
            contagem[tolower(frase[i]) - 'a'] = 1;
        }
    }
    
    for (int i = 0; i < 26; ++i) {
        if (contagem[i]) ++diferentes;
    }
    
    if (diferentes == 26)        printf("frase completa\n");
    else if (diferentes > 12)    printf("frase quase completa\n");
    else                        printf("frase mal elaborada\n");
}

int main() {
    int N;
    char frase[1001];
    
    scanf("%d\n", &N);
    
    for (int k = 0; k < N; ++k) {
        fgets(frase, sizeof(frase), stdin);
        analisar_frase(frase);
    }
    
    return 0;
}
