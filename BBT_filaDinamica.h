#include <stdio.h>
#include <stdlib.h>

typedef struct sComandoFila
{
    int cmdFila;
    int qtdFila;
} ComandoFila;

typedef struct sNo
{
    ComandoFila info;
    struct sNo *prox;
} NO;

typedef struct sFila
{
    NO *inicio;
    NO *fim;
} Fila;

void inic(Fila *ptrF)
{
    ptrF->inicio = NULL;
    ptrF->fim = NULL;
}

int vazia(Fila *ptrF)
{
    if (ptrF->inicio == NULL)
        return 1; // sem elementos (vazia)
    return 0;     // com elementos
}

NO *alocarNo()
{

    return (NO *)malloc(sizeof(NO));
}

void enfileirar(Fila *ptr, ComandoFila elem)
{
    NO *novo;
    novo = alocarNo();
    if (novo != NULL)
    {
        novo->info = elem;
        novo->prox = NULL;
        if (vazia(ptr))
        {
            ptr->inicio = novo;
            ptr->fim = novo;
        }
        else
        {
            (ptr->fim)->prox = novo;
            ptr->fim = novo;
        }
        printf("Comando inserido com sucesso!\n");
    }
    else
    {
        printf("Poblema na alocacao!\n");
    }
}
