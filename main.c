#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TADs_pilha_fila_aloc_enc.h"
#include <locale.h>
const int TAM= 100;

TipoFila * le_expressao(char *exp);
int avalia_expressao(TipoFila *exp);

int main(void)
{
    setlocale(LC_ALL,"");
    char exp[TAM];
    int resultado;

    printf("Entre com a expressão aritmética em notação pós-fixa:\n");
    fgets(exp, TAM, stdin);
    exp[strcspn(exp, "\n")] = '\0';

    TipoFila *fila = le_expressao(exp);

    printf("\nFILA: ");
    ImprimeFila(fila);

    resultado = avalia_expressao(fila);

    printf("\n\nO resultado da expressão é: %d", resultado);

    return 0;
}

TipoFila * le_expressao(char *exp){

    TipoFila *fila = (TipoFila *)malloc(sizeof(TipoFila));
    CriaFilaVazia(fila);
    TipoItem item;
    int i=0;
    char valores;

    while (exp[i] != '\0'){

        valores = exp[i];
        item.valor = valores;
        InsereFila(fila, item);
        i++;
    }

    return fila;
}

int avalia_expressao(TipoFila *exp){

    TipoItem item, operando1, operando2;
    int resultado;

    TipoPilha *pilha = (TipoPilha *)malloc(sizeof(TipoPilha));
    CriaPilhaVazia(pilha);

    while (!TestaFilaVazia(exp)){

        RemoveFila(exp, &item);

        if(isdigit(item.valor)){ //função da biblioteca C que verifica se o item é um digito numerico
            item.valor = item.valor - '0'; //subtraindo o caracter '0' para obter o valor correspondente do char como inteiro.
            InserePilha(pilha, item);
        }
        else{
            RemovePilha(pilha, &operando1);
            RemovePilha(pilha, &operando2);
            if(item.valor == '*'){
                item.valor = operando2.valor * operando1.valor;
            }
            else if(item.valor == '+'){
                item.valor = operando2.valor + operando1.valor;
            }
            else if(item.valor == '-'){
                item.valor = operando2.valor - operando1.valor;
            }
            else{
                item.valor = operando2.valor / operando1.valor;
            }
            InserePilha(pilha, item);
        }
    }

    RemovePilha(pilha, &item);
    resultado = item.valor;

    return resultado;
}
