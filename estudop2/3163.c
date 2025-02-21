#include <stdio.h>

#define MAX_AIRPLANES 1000

// Arrays de strings para armazenar os aviões de cada direção
char west[MAX_AIRPLANES][5], north[MAX_AIRPLANES][5], south[MAX_AIRPLANES][5], east[MAX_AIRPLANES][5];
int wCount = 0, nCount = 0, sCount = 0, eCount = 0;

void printQueue() {
    int i = 0, j = 0, k = 0, l = 0;

    // Loop imprimindo os aviões na ordem correta
    while (i < wCount || j < nCount || k < sCount || l < eCount) {
        if (i < wCount) printf("%s ", west[i++]);
        if (j < nCount) printf("%s ", north[j++]);
        if (k < sCount) printf("%s ", south[k++]);
        if (l < eCount) printf("%s ", east[l++]);
    }
    printf("\n");
}

int main() {
    int card;
    
    // Loop principal para ler entrada
    while (1) {
        scanf("%d", &card);
        if (card == 0) break; // Finaliza se receber 0
        
        // Lê aviões até encontrar outro número
        while (1) {
            char airplane[5];  // String temporária para armazenar entrada
            if (scanf("%s", airplane) != 1) break; // Sai se não houver mais entrada
            
            if (airplane[0] == 'A') {  // Se for avião, armazena na fila correspondente
                if (card == -1) {
                    west[wCount][0] = airplane[0];  // Copia diretamente sem usar strcpy
                    west[wCount][1] = airplane[1];
                    west[wCount][2] = airplane[2];
                    west[wCount][3] = airplane[3];
                    west[wCount][4] = '\0';  // Finaliza string
                    wCount++;
                } 
                else if (card == -2) {
                    south[sCount][0] = airplane[0];
                    south[sCount][1] = airplane[1];
                    south[sCount][2] = airplane[2];
                    south[sCount][3] = airplane[3];
                    south[sCount][4] = '\0';
                    sCount++;
                } 
                else if (card == -3) {
                    north[nCount][0] = airplane[0];
                    north[nCount][1] = airplane[1];
                    north[nCount][2] = airplane[2];
                    north[nCount][3] = airplane[3];
                    north[nCount][4] = '\0';
                    nCount++;
                } 
                else if (card == -4) {
                    east[eCount][0] = airplane[0];
                    east[eCount][1] = airplane[1];
                    east[eCount][2] = airplane[2];
                    east[eCount][3] = airplane[3];
                    east[eCount][4] = '\0';
                    eCount++;
                }
            } 
            else { 
                // Se não for avião, então é um novo ponto cardeal, volta o valor para scanf
                sscanf(airplane, "%d", &card);
                break;
            }
        }
    }

    printQueue(); // Imprime a fila final
    return 0;
}
