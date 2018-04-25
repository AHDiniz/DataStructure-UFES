#include "fila.h"
#include <stdlib.h>
#include <stdio.h>

struct fila
{
    Pilha* p1;
    Pilha* p2;
};

Fila* cria_fila(void)
{
    Fila* f = (Fila*)malloc(sizeof(Fila));
    f->p1 = cria_pilha();
    f->p2 = cria_pilha();
    return f;
}

void insere(Pessoa* pessoa, Fila* f)
{
    push(pessoa, f->p1);
}

Pessoa* retira(Fila* f)
{
    int i;
    Pessoa* p;
    while(!vazia_pilha(f->p1))
        push(pop(f->p1), f->p2);
    p = pop(f->p2);
    while (!vazia_pilha(f->p2))
        push(pop(f->p2), f->p1);
    return p;
}

void imprime_fila(Fila* f)
{
    imprime_pilha(f->p1);
}

int Vazia_fila(Fila* f)
{
    return vazia_pilha(f->p1);
}

void separa_filas(Fila* f, Fila* f_maiores, Fila* f_menores)
{
    return;
}

Fila* destroi_fila(Fila* f)
{
    destroi_pilha(f->p2);
    destroi_pilha(f->p1);
    return NULL;
}