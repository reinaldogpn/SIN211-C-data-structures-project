#include <stdio.h>
#include <stdlib.h>
#include "BBT_filaDinamica.h"
#include "BBT_pilhaDinamica.h"

int continuar(int opcao);
void voceFalhou(int tentativas);
int passou_de_fase(int fase);
ComandoFila registraComandosFila(Fila *fileira, int fase, char sentido, char Tabuleiro[8][8]);
ComandoPilha registraComandosPilha(NO2 *pilha, int fase, char sentido, char Tabuleiro[8][8]);

char sentido_jogador(char sentido) // Essa função mostra no menu em qual sentido o player está.
{
    char sent;
    if (sentido == 'd')
    {
        sent = '>';
    }
    if (sentido == 'b')
    {
        sent = 'V';
    }
    if (sentido == 'c')
    {
        sent = '^';
    }
    if (sentido == 'e')
    {
        sent = '<';
    }
    return sent;
}

char criar_tabuleiro(char Tabuleiro[8][8]) // Essa função cria um tabuleiro jogável.
{
    int i, j;

    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
        {
            Tabuleiro[i][j] = ' ';
        }
    }

    // obstaculos
    // POSIÇÃO DE' P' E DE 'O'
    Tabuleiro[0][0] = 'P';
    Tabuleiro[7][7] = 'O';

    Tabuleiro[1][1] = 'X';
    Tabuleiro[1][2] = 'X';
    Tabuleiro[1][3] = 'X';
    Tabuleiro[5][2] = 'X';
    Tabuleiro[5][3] = 'X';
    Tabuleiro[5][4] = 'X';
    Tabuleiro[6][6] = 'X';
    Tabuleiro[5][6] = 'X';
    Tabuleiro[7][1] = 'X';
    Tabuleiro[7][2] = 'X';
    Tabuleiro[0][7] = 'X';
    Tabuleiro[1][7] = 'X';
    Tabuleiro[3][0] = 'X';
    Tabuleiro[3][1] = 'X';

    return Tabuleiro[8][8];
}
void imprimirNaoClassicaFila(Fila *ptr);

void mostrar_tabuleiro(Fila *ncFila, int fase, char sentido, char Tabuleiro[8][8]) // Essa função exibe o tabuleiro criado e é utilizada nas fases 1 e 3 (parte 1)
{
    int i, j;
    if (fase == 1)
    {
        printf("\nFASE 1  Estrutura Fila do tipo FIFO (first-in first-out)\n\n");
    }
    else
    {
        printf("\nFASE 3  Estrutura Fila do tipo FIFO (first-in first-out)\n\n");
    }
    printf("Fila: ");
    imprimirNaoClassicaFila(ncFila);
    printf("\n");

    for (i = 0; i < 8; i++)
    {

        if (i == 0)
        {
            printf("|---|---|---|---|---|---|---|---|          Sentido do player no tabuleiro:\n");
        }
        else if (i == 1 && (sentido_jogador(sentido) == '>'))
        {
            printf("|---|---|---|---|---|---|---|---|         | P >|\n");
        }
        else if (i == 1 && (sentido_jogador(sentido) == '<'))
        {
            printf("|---|---|---|---|---|---|---|---|        |< P |\n");
        }
        else if (i == 1 && (sentido_jogador(sentido) == '^'))
        {
            printf("|---|---|---|---|---|---|---|---|          ^\n");
        }
        else if (i == 1 && (sentido_jogador(sentido) == 'V'))
        {
            printf("|---|---|---|---|---|---|---|---|         | P |\n");
        }
        else if (i == 2 && (sentido_jogador(sentido) == '^'))
        {
            printf("|---|---|---|---|---|---|---|---|         | P |\n");
        }
        else if (i == 2 && (sentido_jogador(sentido) == 'V'))
        {
            printf("|---|---|---|---|---|---|---|---|           V\n");
        }
        else if (i == 3)
        {
            printf("|---|---|---|---|---|---|---|---|          Comandos:\n");
        }
        else if (i == 4)
        {
            printf("|---|---|---|---|---|---|---|---|          1) F F\n");
        }
        else if (i == 5)
        {
            printf("|---|---|---|---|---|---|---|---|          2) E F\n");
        }
        else if (i == 5 && fase == 3)
        {
            printf("|---|---|---|---|---|---|---|---|          2) F E\n");
        }
        else if (i == 6 && fase == 1)
        {
            printf("|---|---|---|---|---|---|---|---|          3) D F F\n");
        }
        else if (i == 6 && fase == 3)
        {
            printf("|---|---|---|---|---|---|---|---|          3) F D\n");
        }
        else if (i == 7 && fase == 3)
        {
            printf("|---|---|---|---|---|---|---|---|          4) D F F\n");
        }
        else
        {
            printf("|---|---|---|---|---|---|---|---|\n");
        }
        for (j = 0; j < 8; j++)
        {
            printf("| %c ", Tabuleiro[i][j]);
        }
        printf("|\n");
    }
    printf("|---|---|---|---|---|---|---|---|\n");
}
void impressaoNaoClassicaPilha(NO2 *topo);
void mostrar_tabuleiro2(NO2 *ncPilha, int fase, char sentido, char Tabuleiro[8][8]) // Essa função exibe o tabuleiro criado e é utilizada nas fases 2 e 3 (parte 2)
{
    int i, j;
    if (fase == 2)
    {
        printf("\nFASE 2  Estrutura Pilha do tipo LIFO (last-in first-out)\n\n");
    }
    else
    {
        printf("\nFASE 3  Estrutura Pilha do tipo LIFO (last-in first-out)\n\n");
    }
    printf("Pilha: ");
    impressaoNaoClassicaPilha(ncPilha);
    printf("\n");

    for (i = 0; i < 8; i++)
    {
        if (i == 0)
        {
            printf("|---|---|---|---|---|---|---|---|          Sentido do player no tabuleiro:\n");
        }
        else if (i == 1 && (sentido_jogador(sentido) == '>'))
        {
            printf("|---|---|---|---|---|---|---|---|          | P >|\n");
        }
        else if (i == 1 && (sentido_jogador(sentido) == '<'))
        {
            printf("|---|---|---|---|---|---|---|---|        |< P |\n");
        }
        else if (i == 1 && (sentido_jogador(sentido) == '^'))
        {
            printf("|---|---|---|---|---|---|---|---|          ^\n");
        }
        else if (i == 1 && (sentido_jogador(sentido) == 'V'))
        {
            printf("|---|---|---|---|---|---|---|---|        | P |\n");
        }
        else if (i == 2 && (sentido_jogador(sentido) == '^'))
        {
            printf("|---|---|---|---|---|---|---|---|        | P |\n");
        }
        else if (i == 2 && (sentido_jogador(sentido) == 'V'))
        {
            printf("|---|---|---|---|---|---|---|---|          V\n");
        }
        else if (i == 3)
        {
            printf("|---|---|---|---|---|---|---|---|          Comandos:\n");
        }
        else if (i == 4 && fase == 2)
        {
            printf("|---|---|---|---|---|---|---|---|          1) F F F\n");
        }
        else if (i == 4 && fase != 2)
        {
            printf("|---|---|---|---|---|---|---|---|          1) F F\n");
        }
        else if (i == 5 && fase == 2)
        {
            printf("|---|---|---|---|---|---|---|---|          2) D F F\n");
        }
        else if (i == 5 && fase != 2)
        {
            printf("|---|---|---|---|---|---|---|---|          2) F E\n");
        }
        else if (i == 6 && fase == 2)
        {
            printf("|---|---|---|---|---|---|---|---|          3) E F F\n");
        }
        else if (i == 6 && fase != 2)
        {
            printf("|---|---|---|---|---|---|---|---|          3) F D\n");
        }
        else if (i == 7 && fase == 2)
        {
            printf("|---|---|---|---|---|---|---|---|          4) F F\n");
        }
        else if (i == 7 && fase != 2)
        {
            printf("|---|---|---|---|---|---|---|---|          4) D F F\n");
        }
        else
        {
            printf("|---|---|---|---|---|---|---|---|\n");
        }
        for (j = 0; j < 8; j++)
        {
            printf("| %c ", Tabuleiro[i][j]);
        }
        printf("|\n");
    }
    printf("|---|---|---|---|---|---|---|---|\n");
}

char mudarSentido(char sentido, char novoSentido) // Essa função altera o sentido do player de acordo com o comando selecionado
{                                                 // sent 0 = (>) sent 1 = (V), sent 2 = (^), sent 3(<)
    if (novoSentido == 'e')
    { // esquerda
        if (sentido == 'd')
        {
            return sentido = 'c';
        }
        else if (sentido == 'b')
        {
            return sentido = 'd';
        }
        else if (sentido == 'c')
        {
            return sentido = 'e';
        }
        else if (sentido == 'e')
        {
            return sentido = 'b';
        }
    }
    if (novoSentido == 'd')
    { // direita

        if (sentido == 'd')
        {
            return sentido = 'b';
        }
        else if (sentido == 'b')
        {
            return sentido = 'e';
        }
        else if (sentido == 'c')
        {
            return sentido = 'd';
        }
        else if (sentido == 'e')
        {
            return sentido = 'c';
        }
    }
}

int verificarCaminho(int i, int j, char Tabuleiro[8][8]);    // *** ESTÁ EM USO?
char comandoF(int fase, char sentido, char Tabuleiro[8][8]); // *** ESTÁ EM USO?

char comandoF(int fase, char sentido, char Tabuleiro[8][8]) // Essa função serve para movimentar o player (P) no tabuleiro seguindo
                                                            // algumas condições detalhadas abaixo.
{
    int i, j;
    // antes de mover vou conferir o sentido
    // criar um if para identificar o sentido que ele estiver seguindo e
    // criar uma linha de movimento para tal

    // comando 1 frente frente frente
    // em caso de sentido d >
    if (sentido == 'd')
    {
        for (i = 0; i < 8; i++)
        {
            for (j = 0; j < 8; j++)
            {
                if (Tabuleiro[i][j] == 'P')
                {
                    if (Tabuleiro[i][j] == Tabuleiro[i][7])
                    {
                        Tabuleiro[i][j] = 'P';
                        return Tabuleiro[8][8];
                    }
                    else if (verificarCaminho(i, j + 1, Tabuleiro))
                    {
                        return Tabuleiro[8][8];
                    }
                    else
                    {
                        if (Tabuleiro[i][j] == Tabuleiro[7][7] && fase != 4)
                        {
                            Tabuleiro[i][j] = 'O';
                            Tabuleiro[i][j + 1] = 'P';
                            return Tabuleiro[8][8];
                        }
                        Tabuleiro[i][j] = ' ';
                        Tabuleiro[i][j + 1] = 'P';
                        return Tabuleiro[8][8];
                    }
                }
            }
        }
    }
    // em caso de sentido c ^
    if (sentido == 'c')
    {
        for (i = 0; i < 8; i++)
        {
            for (j = 0; j < 8; j++)
            {
                if (Tabuleiro[i][j] == 'P')
                {
                    if (verificarCaminho(i - 1, j, Tabuleiro))
                    {
                        return Tabuleiro[8][8];
                    }
                    else
                    {
                        if (Tabuleiro[i][j] == Tabuleiro[7][7] && fase != 4)
                        {
                            Tabuleiro[i][j] = 'O';
                            Tabuleiro[i - 1][j] = 'P';
                            return Tabuleiro[8][8];
                        }
                        Tabuleiro[i][j] = ' ';
                        Tabuleiro[i - 1][j] = 'P';
                        return Tabuleiro[8][8];
                    }
                }
            }
        }
    }
    // em caso de sentido b V
    if (sentido == 'b')
    {
        for (i = 0; i < 8; i++)
        {
            for (j = 0; j < 8; j++)
            {
                if (Tabuleiro[i][j] == 'P')
                {
                    if (verificarCaminho(i + 1, j, Tabuleiro))
                    {
                        return Tabuleiro[8][8];
                    }
                    else
                    {
                        if (Tabuleiro[i][j] == Tabuleiro[7][7] && fase != 4)
                        {
                            Tabuleiro[i][j] = 'O';
                            Tabuleiro[i + 1][j] = 'P';
                            return Tabuleiro[8][8];
                        }
                        Tabuleiro[i][j] = ' ';
                        Tabuleiro[i + 1][j] = 'P';
                        return Tabuleiro[8][8];
                    }
                }
            }
        }
    }
    // em caso de sentido e <
    if (sentido == 'e')
    {
        for (i = 0; i < 8; i++)
        {
            for (j = 0; j < 8; j++)
            {
                if (Tabuleiro[i][j] == 'P')
                {
                    if (verificarCaminho(i, j - 1, Tabuleiro))
                    {
                        return Tabuleiro[8][8];
                    }
                    else
                    {
                        if (Tabuleiro[i][j] == Tabuleiro[7][7] && fase != 4)
                        {
                            Tabuleiro[i][j] = 'O';
                            Tabuleiro[i][j - 1] = 'P';
                            return Tabuleiro[8][8];
                        }
                        Tabuleiro[i][j] = ' ';
                        Tabuleiro[i][j - 1] = 'P';
                        return Tabuleiro[8][8];
                    }
                }
            }
        }
    }
}

int verificarCaminho(int i, int j, char Tabuleiro[8][8]) // Função para verificar o caminho e retornar 1 caso seja um obstaculo/ barreira ou 0 caso o caminho for livre
{

    if (Tabuleiro[i][j] == Tabuleiro[1][1] || Tabuleiro[i][j] == Tabuleiro[1][2] || Tabuleiro[i][j] == Tabuleiro[1][3] || Tabuleiro[i][j] == Tabuleiro[5][2] || Tabuleiro[i][j] == Tabuleiro[5][3] || Tabuleiro[i][j] == Tabuleiro[5][4] || Tabuleiro[i][j] == Tabuleiro[6][6] || Tabuleiro[i][j] == Tabuleiro[5][6] || Tabuleiro[i][j] == Tabuleiro[7][1] || Tabuleiro[i][j] == Tabuleiro[7][2] || Tabuleiro[i][j] == Tabuleiro[0][7] || Tabuleiro[i][j] == Tabuleiro[1][7] || Tabuleiro[i][j] == Tabuleiro[3][0] || Tabuleiro[i][j] == Tabuleiro[3][1] || Tabuleiro[i][j] == Tabuleiro[-1][-1] || Tabuleiro[i][j] == Tabuleiro[-1][0] || Tabuleiro[i][j] == Tabuleiro[-1][1] || Tabuleiro[i][j] == Tabuleiro[-1][2] || Tabuleiro[i][j] == Tabuleiro[-1][3] || Tabuleiro[i][j] == Tabuleiro[-1][4] || Tabuleiro[i][j] == Tabuleiro[-1][5] || Tabuleiro[i][j] == Tabuleiro[-1][6] || Tabuleiro[i][j] == Tabuleiro[-1][7] || Tabuleiro[i][j] == Tabuleiro[0][-1] || Tabuleiro[i][j] == Tabuleiro[1][-1] || Tabuleiro[i][j] == Tabuleiro[2][-1] || Tabuleiro[i][j] == Tabuleiro[8][1] || Tabuleiro[i][j] == Tabuleiro[8][2] || Tabuleiro[i][j] == Tabuleiro[8][3] || Tabuleiro[i][j] == Tabuleiro[8][4] || Tabuleiro[i][j] == Tabuleiro[8][5] || Tabuleiro[i][j] == Tabuleiro[8][6] || Tabuleiro[i][j] == Tabuleiro[8][7])
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//========================== SEÇÃO DEDICADA AOS COMANDOS ================================

// comando frente frente
char comandoFF(int fase, char sentido, char Tabuleiro[8][8])
{
    comandoF(fase, sentido, Tabuleiro);
    comandoF(fase, sentido, Tabuleiro);
    return sentido;
}

// comando esquerda frente
char comandoEF(int fase, char sentido, char Tabuleiro[8][8])
{
    char novoSentido = 'e';
    sentido = mudarSentido(sentido, novoSentido);
    comandoF(fase, sentido, Tabuleiro);
    return sentido;
}

// comando direita frente frente
char comandoDFF(int fase, char sentido, char Tabuleiro[8][8])
{
    char novoSentido = 'd';
    sentido = mudarSentido(sentido, novoSentido);
    comandoF(fase, sentido, Tabuleiro);
    comandoF(fase, sentido, Tabuleiro);
    return sentido;
}
// comando frente frente frente
char comandoFFF(int fase, char sentido, char Tabuleiro[8][8])
{
    comandoF(fase, sentido, Tabuleiro);
    comandoF(fase, sentido, Tabuleiro);
    comandoF(fase, sentido, Tabuleiro);
    return sentido;
}
// comando Esquerda frente frente
char comandoEFF(int fase, char sentido, char Tabuleiro[8][8])
{
    char novoSentido = 'e';
    sentido = mudarSentido(sentido, novoSentido);
    comandoF(fase, sentido, Tabuleiro);
    comandoF(fase, sentido, Tabuleiro);
    return sentido;
}
// comando Frente esquerda
char comandoFE(int fase, char sentido, char Tabuleiro[8][8])
{
    char novoSentido = 'e';
    comandoF(fase, sentido, Tabuleiro);
    sentido = mudarSentido(sentido, novoSentido);
    return sentido;
}
// comando Frente direita
char comandoFD(int fase, char sentido, char Tabuleiro[8][8])
{
    char novoSentido = 'd';
    comandoF(fase, sentido, Tabuleiro);
    sentido = mudarSentido(sentido, novoSentido);
    return sentido;
}

char ExecucaoClassicaFila(Fila *ptrF, char sentido, char Tabuleiro[8][8], int fase) // Função de impressão classica fila com a impressão do tabuleiro e aplicação dos comandos
{
    if (!vazia(ptrF))
    {
        NO *aux;
        aux = ptrF->inicio;
        while (aux != NULL)
        {
            if (fase == 1)
            {
                ptrF->inicio = ptrF->inicio->prox;
                if (aux->info.cmdFila == 1)
                {
                    while (aux->info.qtdFila)
                    {
                        sentido = comandoFF(fase, sentido, Tabuleiro);

                        mostrar_tabuleiro(ptrF, fase, sentido, Tabuleiro);
                        system("pause");
                        aux->info.qtdFila--;
                    }
                    free(aux);
                    aux = ptrF->inicio;
                }
                else if (aux->info.cmdFila == 2)
                {
                    while (aux->info.qtdFila)
                    {
                        sentido = comandoEF(fase, sentido, Tabuleiro);
                        mostrar_tabuleiro(ptrF, fase, sentido, Tabuleiro);
                        system("pause");
                        aux->info.qtdFila--;
                    }
                    free(aux);
                    aux = ptrF->inicio;
                }
                else if (aux->info.cmdFila == 3)
                {
                    while (aux->info.qtdFila)
                    {
                        sentido = comandoDFF(fase, sentido, Tabuleiro);
                        mostrar_tabuleiro(ptrF, fase, sentido, Tabuleiro);
                        system("pause");
                        aux->info.qtdFila--;
                    }
                    free(aux);
                    aux = ptrF->inicio;
                }
                // fase 3
            }
            else
            {
                ptrF->inicio = ptrF->inicio->prox;
                if (aux->info.cmdFila == 1)
                {
                    while (aux->info.qtdFila)
                    {
                        sentido = comandoFF(fase, sentido, Tabuleiro);
                        mostrar_tabuleiro(ptrF, fase, sentido, Tabuleiro);
                        system("pause");
                        aux->info.qtdFila--;
                    }
                    free(aux);
                    aux = ptrF->inicio;
                }
                else if (aux->info.cmdFila == 2)
                {
                    while (aux->info.qtdFila)
                    {
                        sentido = comandoFE(fase, sentido, Tabuleiro);
                        mostrar_tabuleiro(ptrF, fase, sentido, Tabuleiro);
                        system("pause");
                        aux->info.qtdFila--;
                    }
                    free(aux);
                    aux = ptrF->inicio;
                }
                else if (aux->info.cmdFila == 3)
                {
                    while (aux->info.qtdFila)
                    {
                        sentido = comandoFD(fase, sentido, Tabuleiro);
                        mostrar_tabuleiro(ptrF, fase, sentido, Tabuleiro);
                        system("pause");
                        aux->info.qtdFila--;
                    }
                    free(aux);
                    aux = ptrF->inicio;
                }
                else if (aux->info.cmdFila == 4)
                {
                    while (aux->info.qtdFila)
                    {
                        sentido = comandoDFF(fase, sentido, Tabuleiro);
                        mostrar_tabuleiro(ptrF, fase, sentido, Tabuleiro);
                        system("pause");
                        aux->info.qtdFila--;
                    }
                    free(aux);
                    aux = ptrF->inicio;
                }
            }
        }
        if (fase == 3)
        {
            return sentido;
        }
        printf("\n");
    }
    else
    {
        printf("Fila vazia\n");
    }
}

int verificarVitoria(int tent, char Tabuleiro[8][8]) // Essa função verifica se o player (P) chegou ao objetivo (O)
                                                     // e decrementa as tentativas do jogador caso tenha errado.
{
    if (Tabuleiro[7][7] == 'P')
        return tent;
    else
        return tent - 1;
}

int verificarVitoriaFinal(int tent, char Tabuleiro[8][8]) // Essa função verifica o resultado na fase final do jogo.
{
    if (Tabuleiro[0][0] == 'P')
        return tent;
    else
        return tent - 1;
}

void ExecucaoClassicaPilha(NO2 **topo, int sentido, char Tabuleiro[8][8], int fase) // Essa função executa as instruções relacionadas a estrutura PILHA.
{
    if (!vaziaP(*topo))
    {
        NO2 *aux;
        aux = *topo;
        ComandoPilha P;

        while (aux != NULL)
        {
            if (fase == 2)
            {
                *topo = aux->prox;
                if (aux->info2.cmdPilha == 1)
                {
                    while (aux->info2.qtdPilha)
                    {
                        sentido = comandoFFF(fase, sentido, Tabuleiro);
                        mostrar_tabuleiro2(aux, fase, sentido, Tabuleiro);
                        system("pause");
                        aux->info2.qtdPilha--;
                    }
                    free(aux);
                    P = aux->info2;
                    aux = aux->prox;
                }
                else if (aux->info2.cmdPilha == 2)
                {
                    while (aux->info2.qtdPilha)
                    {
                        sentido = comandoDFF(fase, sentido, Tabuleiro);
                        mostrar_tabuleiro2(aux, fase, sentido, Tabuleiro);
                        system("pause");
                        aux->info2.qtdPilha--;
                    }
                    free(aux);
                    P = aux->info2;
                    aux = aux->prox;
                }
                else if (aux->info2.cmdPilha == 3)
                {
                    while (aux->info2.qtdPilha)
                    {
                        sentido = comandoEFF(fase, sentido, Tabuleiro);
                        mostrar_tabuleiro2(aux, fase, sentido, Tabuleiro);
                        system("pause");
                        aux->info2.qtdPilha--;
                    }
                    free(aux);
                    P = aux->info2;
                    aux = aux->prox;
                }
                else if (aux->info2.cmdPilha == 4)
                {
                    while (aux->info2.qtdPilha)
                    {
                        sentido = comandoFF(fase, sentido, Tabuleiro);
                        mostrar_tabuleiro2(aux, fase, sentido, Tabuleiro);
                        system("pause");
                        aux->info2.qtdPilha--;
                    }
                    free(aux);
                    P = aux->info2;
                    aux = aux->prox;
                }
                // fase 3
            }
            else
            {
                *topo = aux->prox;
                if (aux->info2.cmdPilha == 1)
                {
                    while (aux->info2.qtdPilha)
                    {
                        sentido = comandoFF(fase, sentido, Tabuleiro);
                        mostrar_tabuleiro2(aux, fase, sentido, Tabuleiro);
                        system("pause");
                        aux->info2.qtdPilha--;
                    }
                    free(aux);
                    P = aux->info2;
                    aux = aux->prox;
                }
                else if (aux->info2.cmdPilha == 2)
                {
                    while (aux->info2.qtdPilha)
                    {
                        sentido = comandoFE(fase, sentido, Tabuleiro);
                        mostrar_tabuleiro2(aux, fase, sentido, Tabuleiro);
                        system("pause");
                        aux->info2.qtdPilha--;
                    }
                    free(aux);
                    P = aux->info2;
                    aux = aux->prox;
                }
                else if (aux->info2.cmdPilha == 3)
                {
                    while (aux->info2.qtdPilha)
                    {
                        sentido = comandoFD(fase, sentido, Tabuleiro);
                        mostrar_tabuleiro2(aux, fase, sentido, Tabuleiro);
                        system("pause");
                        aux->info2.qtdPilha--;
                    }
                    free(aux);
                    P = aux->info2;
                    aux = aux->prox;
                }
                else if (aux->info2.cmdPilha == 4)
                {
                    while (aux->info2.qtdPilha)
                    {
                        sentido = comandoDFF(fase, sentido, Tabuleiro);
                        mostrar_tabuleiro2(aux, fase, sentido, Tabuleiro);
                        system("pause");
                        aux->info2.qtdPilha--;
                    }
                    free(aux);
                    P = aux->info2;
                    aux = aux->prox;
                }
            }
        }
        while (aux != NULL)
        {
            desalocarNo(aux);
        }
    }
    else
    {
        printf("Pilha vazia!\n");
    }
}

void imprimirNaoClassicaFila(Fila *ptr)
{
    NO *aux;
    if (vazia(ptr) != 1)
    {
        aux = (ptr->inicio);
        do
        {
            printf("%d-%d, ", aux->info.cmdFila, aux->info.qtdFila);
            aux = aux->prox;
        } while (aux != NULL);
    }
}

void impressaoNaoClassicaPilha(NO2 *topo)
{
    if (!vaziaP(topo))
    {
        NO2 *aux;
        aux = topo;
        while (aux != NULL)
        {
            printf("%d-%d, ", aux->info2.cmdPilha, aux->info2.qtdPilha);
            aux = aux->prox;
        }
        printf("\n");
    }
}

ComandoFila registraComandosFila(Fila *fileira, int fase, char sentido, char Tabuleiro[8][8])
{
    ComandoFila F;
    if (fase == 1)
    {
        do
        {
            mostrar_tabuleiro(fileira, fase, sentido, Tabuleiro);
            printf("\nDigite os comandos a serem executados em FILA (lembrando que: 1 = FF, 2 = EF, 3 = DFF):\n");
            printf("--> ");
            scanf("%d", &F.cmdFila);
            if (F.cmdFila < 1 || F.cmdFila > 3)
            {
                printf("Comando invalido, tente novamente!\n");
            }
        } while (F.cmdFila != 1 && F.cmdFila != 2 && F.cmdFila != 3);

        do
        {
            printf("\nDigite a quantidade de vezes que o comando sera executado:\n");
            printf("--> ");
            scanf("%d", &F.qtdFila);
            if (F.qtdFila <= 0)
            {
                printf("Quantidade invalida, tente novamente!\n");
            }

        } while (F.qtdFila <= 0);
        return F;
    }
    else
    {
        do
        {
            mostrar_tabuleiro(fileira, fase, sentido, Tabuleiro);
            printf("\nDigite os comandos a serem executados em FILA (lembrando que: 1 = FF, 2 = FE, 3 = FD, 4 = DFF):\n");
            printf("--> ");
            scanf("%d", &F.cmdFila);
            if (F.cmdFila < 1 || F.cmdFila > 4)
            {
                printf("Comando invalido, tente novamente!\n\n");
            }
        } while (F.cmdFila != 1 && F.cmdFila != 2 && F.cmdFila != 3 && F.cmdFila != 4);

        do
        {
            printf("\nDigite a quantidade de vezes que o comando sera executado:\n");
            printf("--> ");
            scanf("%d", &F.qtdFila);

            if (F.qtdFila <= 0)
            {
                printf("Quantidade invalida, tente novamente!\n\n");
            }
        } while (F.qtdFila <= 0);
        return F;
    }
}

int passou_de_fase(int fase)
{
    if (fase == 1)
    {
        printf("======================================================================================\n");
        printf("\n*** PARABENS! Voce atingiu o objetivo da FASE 1! ***\n");
        printf("\n======================================================================================\n");
        system("pause");
        fase++;
    }
    else if (fase == 2)
    {
        printf("======================================================================================\n");
        printf("\n*** PARABENS! Voce atingiu o objetivo da FASE 2! ***\n");
        printf("\n======================================================================================\n");
        system("pause");
        fase++;
    }
    else if (fase == 3)
    {
        printf("======================================================================================\n");
        printf("\n*** Voce atingiu o primeiro objetivo da FASE 3! Agora tente alcancar 'O' novamente fazendo o caminho de volta! ***\n");
        printf("\n======================================================================================\n");
        system("pause");
        fase++;
    }
    else if (fase == 4)
    {
        system("cls||clear");
        system("color 06");
        printf("======================================================================================\n");
        printf("\n                  *** PARABENS!!! VOCE CONCLUIU O JOGO! ***\n");
        printf("\n======================================================================================\n");
        system("pause");
    }
    return fase;
}

void voceFalhou(int tentativas)
{
    printf("\n*** VOCE FALHOU! Tente novamente! (Tentativas restantes: %d) ***\n\n", tentativas);
    system("pause");
}

ComandoPilha registraComandosPilha(NO2 *pilha, int fase, char sentido, char Tabuleiro[8][8])
{
    ComandoPilha P;
    if (fase == 2)
    {
        do
        {
            mostrar_tabuleiro2(pilha, fase, sentido, Tabuleiro);
            printf("\nDigite os comandos a serem executados em PILHA (lembrando que: 1 = FFF, 2 = DFF, 3 = EFF, 4 = FF):\n");
            printf("--> ");
            scanf("%d", &P.cmdPilha);
            if (P.cmdPilha < 1 || P.cmdPilha > 4)
            {
                printf("Comando invalido, tente novamente!\n");
            }
        } while (P.cmdPilha != 1 && P.cmdPilha != 2 && P.cmdPilha != 3 && P.cmdPilha != 4);

        do
        {
            printf("\nDigite a quantidade de vezes que o comando sera executado:\n");
            printf("--> ");
            scanf("%d", &P.qtdPilha);

            if (P.qtdPilha <= 0)
            {
                printf("Quantidade invalida, tente novamente!\n");
            }
        } while (P.qtdPilha <= 0);
        return P;
    }
    else
    {
        do
        {
            mostrar_tabuleiro2(pilha, fase, sentido, Tabuleiro);
            printf("\nDigite o comando (Ex: 1 = FF, 2 = FE, 3 = FD, 4 = DFF) serao executados em Pilha. \n");
            printf("--> ");
            scanf("%d", &P.cmdPilha);
            if (P.cmdPilha < 1 || P.cmdPilha > 4)
            {
                printf("Comando invalido, tente novamente!\n\n");
            }
        } while (P.cmdPilha != 1 && P.cmdPilha != 2 && P.cmdPilha != 3 && P.cmdPilha != 4);

        do
        {
            printf("\nDigite a quantidade de vezes que o comando sera executado:\n");
            printf("--> ");
            scanf("%d", &P.qtdPilha);

            if (P.qtdPilha <= 0)
            {
                printf("Quantidade invalida, tente novamente!\n\n");
            }
        } while (P.qtdPilha <= 0);
        return P;
    }
}

int continuar(int opcao)
{
    do
    {
        printf("\nContinuar? (1 = SIM | 0 = NAO)\n");
        printf("--> ");
        scanf("%d", &opcao);
        if (opcao != 1 && opcao != 0)
        {
            printf("Opcao invalida, tente novamente!\n\n");
        }
        if (opcao == 1)
        {
            system("cls||clear");
        }
    } while (opcao != 1 && opcao != 0);
    return opcao;
}