#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

void colocarNavioHorizontal(int tab[10][10], int lin, int col, int navio[3]) {
    if ((col > 7) || (col < 0) || (lin < 0) || (lin > 9)) {
        printf("O navio não pode ser inserido fora do tabuleiro\n");
        return;
    }

    for (int i = 0; i < 3; i++)
    {
        if (tab[lin][col+i] != 0) {
            printf("O navio não pode ser inserido sobre outro navio\n");
            return;
        }
    }

    // Coloca o navio no tabuleiro
    for (int i = 0; i < 3; i++)
    {
        tab[lin][col+i] = navio[i];
    }
    
}

void colocarNavioVertical(int tab[10][10], int lin, int col, int navio[3]) {
    if ((lin > 7) || (col < 0) || (lin < 0) || (col > 9)) {
        printf("O navio não pode ser inserido fora do tabuleiro\n");
        return;
    }

    for (int i = 0; i < 3; i++)
    {
        if (tab[lin+i][col] != 0) {
            printf("O navio não pode ser inserido sobre outro navio\n");
            return;
        }
    }

    // Coloca o navio no tabuleiro
    for (int i = 0; i < 3; i++)
    {
        tab[lin+i][col] = navio[i];
    }
    
}

void colocarNavioDiagonal(int tab[10][10], int lin, int col, int navio[3]) {
    if ((lin > 7) || (col < 0) || (lin < 0) || (col > 7)) {
        printf("O navio não pode ser inserido fora do tabuleiro\n");
        return;
    }

    for (int i = 0; i < 3; i++)
    {
        if (tab[lin+i][col+i] != 0) {
            printf("O navio não pode ser inserido sobre outro navio\n");
            return;
        }
    }

    // Coloca o navio no tabuleiro
    for (int i = 0; i < 3; i++)
    {
        tab[lin+i][col+i] = navio[i];
    }
    
}

void colocarNavioDiagonalInvertido(int tab[10][10], int lin, int col, int navio[3]) {
    if ((lin > 7) || (col < 2) || (lin < 0) || (col > 9)) {
        printf("O navio não pode ser inserido fora do tabuleiro\n");
        return;
    }

    for (int i = 0; i < 3; i++)
    {
        if (tab[lin+i][col-i] != 0) {
            printf("O navio não pode ser inserido sobre outro navio\n");
            return;
        }
    }

    // Coloca o navio no tabuleiro
    for (int i = 0; i < 3; i++)
    {
        tab[lin+i][col-i] = navio[i];
    }
    
}

void executarHabilidade(int tab[10][10], int lin, int col, int habilidade[5][5], int inicioLinha) {
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (habilidade[i][j] == 1)
            {
                // calcula a posição no tabuleiro
                int a = lin+i-inicioLinha;
                int b = col+j-2;
                if ((a < 0) || (a > 9) || (b < 0) || (b > 9))
                {
                    continue;   // pula posições fora do tabuleiro
                }
                tab[a][b] = 5;
            }
        }
    }
}

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    // inicializa o tabuleiro com água (0)
    int tabuleiro[10][10] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

    // define as habilidades especiais (5x5)
    int cone[5][5];
    int coneInicioLinha = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if ((i < 3) && j >= 2 - i && j <= 2 + i)
            {
                cone[i][j] = 1;
                
            }
            else
            {
                cone[i][j] = 0;
            }
        }
    }

    int cruz[5][5];
    int cruzInicioLinha = 1;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if ((i == 1) || ((i < 3) && (j == 2)))
            {
                cruz[i][j] = 1;
                
            }
            else
            {
                cruz[i][j] = 0;
            }
        }
    }

    int octaedro[5][5];
    int octaedroInicioLinha = 1;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (((i == 1) && (j > 0) && (j < 4)) || ((i < 3) && (j == 2)))
            {
                octaedro[i][j] = 1;
            }
            else
            {
                octaedro[i][j] = 0;
            }
        }
    }

    // define os navios (3 partes cada)
    int navio1[3] = {3,3,3};
    int navio2[3] = {3,3,3};
    int navio3[3] = {3,3,3};
    int navio4[3] = {3,3,3};

    // insere os navios no tabuleiro
    // argumentos: tabuleiro, linha, coluna, navio
    colocarNavioHorizontal(tabuleiro, 0, 3, navio1);
    colocarNavioVertical(tabuleiro, 4, 8, navio2);
    colocarNavioDiagonal(tabuleiro, 7, 6, navio3);
    colocarNavioDiagonalInvertido(tabuleiro, 7, 4, navio4);

    // executa as habilidades especiais
    // argumentos: tabuleiro, linha, coluna, habilidade, linha de início da habilidade
    executarHabilidade(tabuleiro, 0, 0, cone, coneInicioLinha);
    executarHabilidade(tabuleiro, 4, 4, cruz, cruzInicioLinha);
    executarHabilidade(tabuleiro, 1, 8, octaedro, octaedroInicioLinha);

    // imprime o tabuleiro
    printf("   A B C D E F G H I J\n"); // imprime o nome de cada coluna
    for (int i = 0; i < 10; i++)
    {
        printf("%02d ", i+1);            // imprime os números de cada linha
        for (int j = 0; j < 10; j++)
        {
            printf("%d ",tabuleiro[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
