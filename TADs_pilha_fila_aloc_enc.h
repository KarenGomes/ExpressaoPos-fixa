//pilha e fila com alocação dinamica
typedef struct
{
    int valor;

}TipoItem;

typedef struct celula
{
    TipoItem item;
    struct celula *proximo;
}TipoCelula;

//PILHA

typedef struct
{
    TipoCelula *topo;
    TipoCelula *fundo;
}TipoPilha;

void CriaPilhaVazia(TipoPilha *pilha);

int TestaPilhaVazia(TipoPilha *pilha);

void InserePilha(TipoPilha *pilha, TipoItem item);

void RemovePilha(TipoPilha *pilha, TipoItem *item);

void ImprimePilha(TipoPilha *pilha);

//FILA

typedef struct
{
    TipoCelula *frente;
    TipoCelula *tras;
}TipoFila;

void CriaFilaVazia(TipoFila *fila);

int TestaFilaVazia(TipoFila *fila);

void InsereFila(TipoFila *fila, TipoItem item);

void RemoveFila(TipoFila *fila, TipoItem *item);

void ImprimeFila(TipoFila *fila);
