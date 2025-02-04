#include <stdio.h>
#include <string.h>

#define MAX_N 50
#define MAX_LEN 50

int main() {
    int N, i, maxLen;
    char words[MAX_N][MAX_LEN + 1];
    int first_case = 1;
    
    while (scanf("%d", &N) && N != 0) {
        if (!first_case) {
            printf("\n"); // Linha em branco entre casos de teste
        }
        first_case = 0;
        
        maxLen = 0;
        for (i = 0; i < N; i++) {
        
            scanf("%s", words[i]);
            int len = strlen(words[i]);
            if (len > maxLen) {
                maxLen = len;
            }
        }
        
        for (i = 0; i < N; i++) {
            printf("%*s\n", maxLen, words[i]); // Justificando à direita
        }
    }
    
    return 0;
}
