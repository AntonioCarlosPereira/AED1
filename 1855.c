#include <stdio.h>

int Comp(v[i], Flechas[i], int i){
    for(int j = 0; j<i; j++){
        if(strcmp(v[i],Flechas[i])){
            return 1;
        } else {
            return 0;
        }
    }
}

void Percorrer(mat[i][j]){
    int casa;
    int direção;
    int casa = mat[0][0];
    
    while(casa != *){
        
        if(direção == 1){
            casa = mat[i][i-1];
        }
        if(direção == 2){
            casa = mat[i+1][i];
        }
        if(direção == 3){
            casa = mat[i][i+1];
        }
        if(direção == 4){
            casa = mat[i-1][i];
        }
    
        switch(casa){
           case v:
           direção = 3;
            break;
            
            case <:
            direção = 4;
            break;
            
            case >:
            direção = 2;
            break;
            
            case ^:
            direção = 1;
            break;
            
            default:
        }
    }    
}

int main() {

    -iniciar uma matriz com altura y e largura x
    -preencher ela de acordo com as casas dadas ( ler como vetor\fgets)
    -função percorrer a matriz iniciando do (0,0)
    -a cada flecha que passar armazena-la em um vetor Flechas
    -a cada casa que passar comparala com o vetor Flechas se for igual-> break
    -se encontrar uma casa * printf("!")
    
 
    return 0;
}
