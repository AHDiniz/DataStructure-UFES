#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXTAM 10

struct pessoa
{
    char* nome;
    int idade;
    char* endereco;
};

struct pilha
{
    Pessoa* itens[MAXTAM];
    int topo;
};

static void imprime_pessoa(Pessoa* pessoa)
{
    if (pessoa->nome != NULL)
        printf("Nome: %s    Idade: %d    ", pessoa->nome, pessoa->idade);
    if (pessoa->endereco != NULL)
        printf("Endereco: %s\n", pessoa->endereco);
}

static void destroi_pessoa(Pessoa* pessoa)
{
    if (pessoa != NULL)
    {
        free(pessoa->nome);
        free(pessoa->endereco);
        free(pessoa);
    }
}

Pilha* cria_pilha()
{
    Pilha* p = (Pilha*)malloc(sizeof(Pilha));
    p->topo = 0;
    return p;
}

int vazia_pilha(Pilha* p)
{
    return (p->topo == 0);
}

int tamanho_pilha(Pilha* p)
{
    return (p->topo);
}

void push(Pessoa* pessoa, Pilha* pilha)
{
    if (pilha->topo == MAXTAM)
    {
        printf("Pilha cheia.\n");
        return;
    }

    if (pilha->itens[pilha->topo] != NULL)
        destroi_pessoa(pilha->itens[pilha->topo]);

    pilha->itens[pilha->topo] = pessoa;
    pilha->topo++;
}

Pessoa* pop(Pilha* pilha)
{
    if (pilha->topo == 0)
    {
        printf("Tentando tirar item de pilha vazia.\n");
        return NULL;
    }

    Pessoa* pessoa = pilha->itens[pilha->topo];
    pilha->topo--;

    return pessoa;
}

void imprime_pilha(Pilha* pilha)
{
    if (pilha->topo == 0)
        printf("Pilha vazia.\n");

    int i;
    printf("Pilha de pessoas:\n\n");

    for(i = 0; i < pilha->topo; i++)
    {
        if (pilha->itens[i] != NULL)
        {
            printf("Nome: %s    ", pilha->itens[i]->nome);
            printf("Idade: %d    ", pilha->itens[i]->idade);
            printf("Endereco: %s\n", pilha->itens[i]->endereco);
        }
    }
}

Pilha* destroi_pilha(Pilha* pilha)
{
    for (int i = 0; i < pilha->topo; i++)
        destroi_pessoa(pilha->itens[i]);
    free(pilha);

    return NULL;
}

Pessoa* inicializaPessoa(char* nome, int idade, char* endereco)
{
    Pessoa* pessoa = (Pessoa*)malloc(sizeof(Pessoa));

    pessoa->nome = (char*)malloc(strlen(nome) + 1);
    strcpy(pessoa->nome, nome);

    pessoa->idade = idade;

    pessoa->endereco = (char*)malloc(strlen(endereco) + 1);
    strcpy(pessoa->endereco, endereco);

    return pessoa;
}

int retorna_idade(Pessoa* p)
{
    return p->idade;
}
