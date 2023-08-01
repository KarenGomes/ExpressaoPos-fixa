#include <stdio.h>
#include <stdlib.h>
#include "TADs_pilha_fila_aloc_enc.h"

void CriaFilaVazia(TipoFila *fila)
{
    fila->frente = (TipoCelula *)malloc(sizeof(TipoCelula));
    fila->tras = fila->frente;
    fila->frente->proximo = NULL;
}

int TestaFilaVazia(TipoFila *fila)
{
    return (fila->frente == fila->tras);
}

void InsereFila(TipoFila *fila, TipoItem item)
{
    fila->tras->proximo = (TipoCelula *)malloc(sizeof(TipoCelula));
    fila->tras = fila->tras->proximo;
    fila->tras->item = item;
    fila->tras->proximo = NULL;
}

void RemoveFila(TipoFila *fila, TipoItem *item)
{
    if (TestaFilaVazia(fila))
    {
        printf("Erro: fila vazia\n");
        return;
    }
    TipoCelula *q = fila->frente;
    fila->frente = fila->frente->proximo;
    *item = fila->frente->item;
    free(q);
}

void ImprimeFila(TipoFila *fila)
{
    TipoCelula *aux = fila->frente->proximo;
    while (aux != NULL)
    {
        printf("%c ", aux->item.valor);
        aux = aux->proximo;
    }
}
