#include <stdio.h>
#include <stdlib.h>

int main () {
    int hi, mi, hf, mf, i, countH = 0, countM = 0;

    // Lê as horas e minutos de início e de fim do jogo
    scanf ("%d %d %d %d", &hi, &mi, &hf, &mf);

    // Calcula a quantidade de horas entre o início e o fim do jogo
    do {
        countH++; // Incrementa a contagem de horas

        // Se a hora atual não chegou a 24, incrementa; caso contrário, volta para 1
        if (hi != 24)
            hi++;
        else
            hi = 1;

        // Verifica se o jogo começou em 24 horas (meia-noite) e se chegou a 24 novamente
        if (hf == 0 && hi == 24)
            break; // Sai do laço se essa condição for verdadeira
    }
    while (hi != hf); // Continua até que a hora inicial seja igual à hora final

    // Calcula a diferença de minutos entre o início e o fim
    countM = mf - mi;

    // Ajusta os minutos, caso a diferença seja negativa
    if (countM < 0) {
        countH--;       // Reduz uma hora, já que os minutos "emprestam" 60
        countM += 60;   // Ajusta os minutos somando 60
    }

    // Se o jogo durou exatamente 24 horas e houve minutos adicionais, zera as horas
    if (countH == 24 && countM >= 1)
        countH = 0;

    // Exibe a duração do jogo em horas e minutos
    printf ("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", countH, countM);

    return 0;
}
