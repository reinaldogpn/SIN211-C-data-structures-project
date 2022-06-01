#include <stdio.h>
#include <stdlib.h>

typedef struct sComandoPilha
{
    int cmdPilha;
    int qtdPilha;
} ComandoPilha;

typedef struct sNo2
{
    ComandoPilha info2;
    struct sNo2 *prox;
} NO2;

int vaziaP(NO2 *topo)
{
    if (topo == NULL)
        return 1;
    return 0;
}

NO2 *alocarNoP()
{
    return (NO2 *)malloc(sizeof(NO2));
}

void desalocarNo(NO2 *p)
{
    free(p);
}

void iniciar(NO2 **topo)
{
    *topo = NULL;
}

void empilhar(NO2 **topo, ComandoPilha elem)
{
    NO2 *novo;
    novo = alocarNoP();
    if (novo != NULL)
    {
        novo->info2 = elem;
        novo->prox = *topo;
        *topo = novo;
    }
    else
    {
        printf("Poblema na alocacao\n");
    }
}

ComandoPilha desempilhar(NO2 **topo)
{
    if (!vaziaP(*topo))
    {
        NO2 *aux;
        aux = *topo;
        *topo = aux->prox;

        ComandoPilha P;
        P = aux->info2;

        desalocarNo(aux);
        return P;
    }
    else
    {
        printf("ERRO! Pilha vazia.\n\n");
    }
}