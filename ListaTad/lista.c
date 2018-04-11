#include "lista.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct celula Celula;

struct tipoitem
{
    char* nome;
    int matricula;
    char* endereco;
};

struct celula
{
    TipoItem* aluno;
    Celula* prox;
};

struct tipolista
{
    Celula* top;
    Celula* end;
};

TipoLista* InicializaLista()
{
    TipoLista* l = (TipoLista*)malloc(sizeof(TipoLista));
    l->top = l->end = NULL;
    return l;
}

TipoItem* InicializaTipoItem(char* nome, int matricula, char* endereco)
{
    TipoItem* i = (TipoItem*)malloc(sizeof(TipoItem));
    i->nome = (char*)malloc(strlen(nome) + 1);
    strcpy(i->nome, nome);
    i->matricula = matricula;
    i->endereco = (char*)malloc(sizeof(strlen(endereco) + 1));
    strcpy(i->endereco, endereco);
    return i;
}

static void LiberaItem(TipoItem* i)
{
    free(i->endereco);
    free(i->nome);
    free(i);
}

static Celula* InitCell(TipoItem* i)
{
    Celula* c = (Celula*)malloc(sizeof(Celula));
    c->aluno = i;
    c->prox = NULL;
    return c;
}

static void LiberaCelula(Celula* c)
{
    c->prox = NULL;
    LiberaItem(c->aluno);
    free(c);
}

void Insere(TipoItem* aluno, TipoLista* lista)
{
    if (lista == NULL)
    {
        printf("Erro: tentativa de insercao de item em lista nao inicializada!\n");
        return;
    }
    else if (aluno == NULL)
    {
        printf("Erro: tentativa de insercao de item vazio em lista!\n");
        return;
    }
    else
    {
        Celula* item = InitCell(aluno);
        if (lista->top == NULL)
            lista->top = lista->end = item;
        else
        {
            item->prox = lista->top;
            lista->top = item;
        }
    }
}

TipoItem* Retira(TipoLista* lista, int mat)
{
    Celula* aux = NULL;
    Celula* ret = lista->top;
    while (ret->aluno->matricula != mat && ret != lista->end)
    {
        aux = ret;
        if (ret->prox != NULL)
        ret = ret->prox;
    }
    if (ret->prox == lista->end)
    {
        if (lista->end->aluno->matricula != mat)
            return NULL;
        else
            return lista->end->aluno;
    }
    if (ret == lista->top && ret == lista->end)
    {
        lista->top = lista->end = NULL;
        return ret->aluno;
    }
    if (ret == lista->end)
    {
        lista->end = aux;
        aux->prox = NULL;
        return ret->aluno;
    }
    if (ret == lista->top)
        lista->top = ret->prox;
    else
        aux->prox = ret->prox;
    ret->prox = NULL;
    return ret->aluno;
}

void Imprime(TipoLista* lista)
{
    if (lista->top == NULL)
        printf("Lista vazia.\n");
    else
    {
        Celula* cur = lista->top;
        printf("\nLista:\n");
        while (cur != NULL)
        {
            printf("Nome: %s\nMatricula: %d\nEndereco: %s\n\n", cur->aluno->nome, cur->aluno->matricula, cur->aluno->endereco);
            cur = cur->prox;
        }
    }
}

TipoLista* Libera(TipoLista* lista)
{
    Celula* prev = NULL;
    Celula* cur = lista->top;
    while(cur != NULL)
    {
        prev = cur;
        LiberaCelula(prev);
        cur = cur->prox;
    }
    free(lista);
    return NULL;
}
