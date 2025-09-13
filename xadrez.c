#include <stdio.h>

// Desafio de Xadrez - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de movimentação das peças de xadrez.
// O objetivo é utilizar estruturas de repetição e funções para determinar os limites de movimentação dentro do jogo.

#define MOV_BISPO 5
#define MOV_TORRE 5
#define MOV_RAINHA 8

void moverTorreRecursivo(int passos);
void moverRainhaRecursivo(int passos);
void moverBispoRecursivo(int passos);
void moverCavaloMestre();

int main() {
    // Nível Novato - Movimentação das Peças
    printf("--- INICIO | NIVEL NOVATO ---\n\n");
    
    // Implementação de Movimentação da Torre
    // Sugestão: Utilize uma estrutura de repetição para simular a movimentação da Torre para a direita.
    printf("Movimentando a Torre (com for):\n");
    for (int i = 0; i < MOV_TORRE; i++) {
        printf("Direita\n");
    }
    printf("\n");

    // Implementação de Movimentação da Rainha
    // Sugestão: Utilize uma estrutura de repetição para simular a movimentação da Rainha para a esquerda.
    printf("Movimentando a Rainha (com while):\n");
    int contador_rainha = 0;
    while (contador_rainha < MOV_RAINHA) {
        printf("Esquerda\n");
        contador_rainha++;
    }
    printf("\n");

    // Implementação de Movimentação do Bispo
    // Sugestão: Utilize uma estrutura de repetição para simular a movimentação do Bispo em diagonal.
    printf("Movimentando o Bispo (com do-while):\n");
    int contador_bispo = 0;
    do {
        // Para simular a diagonal, imprimimos Cima e Direita a cada passo.
        printf("Cima\n");
        printf("Direita\n");
        contador_bispo++;
    } while (contador_bispo < MOV_BISPO);
    
    printf("\n--- FIM | NIVEL NOVATO ---\n");
    printf("--------------------------------------\n\n");


    // Nível Aventureiro - Movimentação do Cavalo
    printf("--- INICIO | NIVEL AVENTUREIRO ---\n\n");
    
    // Sugestão: Utilize loops aninhados para simular a movimentação do Cavalo em L.
    // Um loop pode representar a movimentação horizontal e outro vertical.
    printf("Movimentando o Cavalo (com loops aninhados):\n");
    // Movimento em 'L': 2 casas em uma direção e 1 em outra.
    // Faremos 2 para baixo e 1 para a esquerda.
    for (int i = 0; i < 2; i++) {
        printf("Baixo\n");
        
        // Quando o último movimento para baixo for concluído (i == 1),
        // executamos o loop interno para o movimento horizontal.
        if (i == 1) {
            int j = 0;
            while (j < 1) {
                printf("Esquerda\n");
                j++;
            }
        }
    }

    printf("\n--- FIM | NIVEL AVENTUREIRO ---\n");
    printf("--------------------------------------\n\n");


    // Nível Mestre - Funções Recursivas e Loops Aninhados
    printf("--- INICIO | NIVEL MESTRE ---\n\n");
    
    // Sugestão: Substitua as movimentações das peças por funções recursivas.
    // Exemplo: Crie uma função recursiva para o movimento do Bispo.
    printf("Movimentando a Torre (com recursividade):\n");
    moverTorreRecursivo(MOV_TORRE);
    printf("\n");

    printf("Movimentando a Rainha (com recursividade):\n");
    moverRainhaRecursivo(MOV_RAINHA);
    printf("\n");

    printf("Movimentando o Bispo (com recursividade):\n");
    moverBispoRecursivo(MOV_BISPO);
    printf("\n");

    // Sugestão: Implemente a movimentação do Cavalo utilizando loops com variáveis múltiplas e condições avançadas.
    // Inclua o uso de continue e break dentro dos loops.
    printf("Movimentando o Cavalo (com loop de multiplas variaveis, continue e break):\n");
    moverCavaloMestre();
    
    printf("\n--- FIM | NIVEL MESTRE ---\n");
    
    return 0;
}


// --- IMPLEMENTAÇÃO DAS FUNÇÕES (Nível Mestre) ---

/**
 * @brief Move a torre para a direita de forma recursiva.
 * @param passos A quantidade de casas restantes para mover.
 */
void moverTorreRecursivo(int passos) {
    if (passos <= 0) { // Condição de parada
        return;
    }
    printf("Direita\n");
    moverTorreRecursivo(passos - 1); // Chamada recursiva
}

/**
 * @brief Move a rainha para a esquerda de forma recursiva.
 * @param passos A quantidade de casas restantes para mover.
 */
void moverRainhaRecursivo(int passos) {
    if (passos <= 0) {
        return;
    }
    printf("Esquerda\n");
    moverRainhaRecursivo(passos - 1);
}

/**
 * @brief Move o bispo na diagonal superior direita de forma recursiva.
 * @param passos A quantidade de casas restantes para mover.
 */
void moverBispoRecursivo(int passos) {
    if (passos <= 0) {
        return;
    }
    printf("Cima\n");
    printf("Direita\n");
    moverBispoRecursivo(passos - 1);
}

/**
 * @brief Move o cavalo em 'L' (2 para cima, 1 para a direita) usando um
 * loop com múltiplas variáveis, continue e break.
 */
void moverCavaloMestre() {
    // Loop com múltiplas variáveis de controle.
    for (int passo = 1, vertical = 0, horizontal = 0; passo <= 3; passo++) {
        
        // Move verticalmente
        if (vertical < 2) {
            printf("Cima\n");
            vertical++;
            continue; // 'continue' pula para a próxima iteração
        }

        // Move horizontalmente
        if (horizontal < 1) {
            printf("Direita\n");
            horizontal++;
        }
        
        // 'break' encerra o loop quando o movimento estiver completo
        if (vertical == 2 && horizontal == 1) {
            printf("(Movimento em L completo! Saindo do loop com break...)\n");
            break; 
        }
    }
}