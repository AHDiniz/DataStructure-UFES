#include "listahet.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOVEL 0
#define IMOVEL 1

// Definição dos tipos que o usuário não terá acesso:
typedef struct celula Celula;

typedef union item Item;


// Implementação dos tipos:
union item
{
    Movel* movel;
    Imovel* imovel;
};

struct cliente
{
    char* nome;
    int id;
};

struct movel
{
    int placa;
    int ano;
    float valor;
};

struct imovel
{
    int identificador;
    int ano;
    float valor;
};

struct celula
{
    Celula* prox;
    Cliente* cliente;
    Item* item;
    int id;
};

struct listahet
{
    Celula* prim;
    Celula* ult;
};


// Funções que não serão usadas pelo usuário:
static Celula* cria_celula(Cliente* c, Item* i, int id)
{
    Celula* cel = (Celula*)malloc(sizeof(Celula));
    cel->prox = NULL;
    cel->cliente = c;
    cel->item = i;
    cel->id = id;
    return cel;
}

static Item* cria_item_movel(Movel* m)
{
    Item* item = (Item*)malloc(sizeof(Item));
    item->movel = m;
    return item;
}

static Item* cria_item_imovel(Imovel* i)
{
    Item* item = (Item*)malloc(sizeof(Item));
    item->imovel = i;
    return item;
}


// Implementação das funções que serão usadas pelo usuário:
ListaHet* cria()
{
    ListaHet* lh = (ListaHet*)malloc(sizeof(ListaHet));
    lh->prim = lh->ult = NULL;
    return lh;
}

Cliente* cria_cliente(char* nome, int id)
{
    Cliente* c = (Cliente*)malloc(sizeof(Cliente));
    c->nome = (char*)malloc(sizeof(strlen(nome) + 1));
    c->id = id;
    return c;
}

Movel* cria_movel(int placa, int ano, float valor)
{
    Movel* m = (Movel*)malloc(sizeof(Movel));
    m->placa = placa;
    m->ano = ano;
    m->valor = valor;
    return m;
}

Imovel* cria_imovel(int id, int ano, float valor)
{
    Imovel* i = (Imovel*)malloc(sizeof(Imovel));
    i->identificador = id;
    i->ano = ano;
    i->valor = valor;
    return i;
}

ListaHet* insere_movel(ListaHet* lista, Cliente* dono, Movel* item)
{
    Item* itemMovel = cria_item_movel(item);
    Celula* cel = cria_celula(dono, itemMovel, MOVEL);
    cel->prox = lista->prim;
    lista->prim = cel;
    return lista;
}

ListaHet* insere_imovel(ListaHet* lista, Cliente* dono, Imovel* item)
{
    Item* itemMovel = cria_item_imovel(item);
    Celula* cel = cria_celula(dono, itemMovel, IMOVEL);
    cel->prox = lista->prim;
    lista->prim = cel;
    return lista;
}

void imprime(ListaHet* lista)
{    
    printf("Lista Heterogenea:\n");
    for (Celula* c = lista->prim; c != NULL; c = c->prox)
    {
        if (c->id == MOVEL)
        {
            printf("Nome do dono: %s ", c->cliente->nome);
            printf("ID do dono: %d ", c->cliente->id);
            printf("Placa do movel: %d ", c->item->movel->placa);
            printf("Ano do movel: %d\n\n", c->item->movel->ano);
        }
        else if (c->id == IMOVEL)
        {
            printf("Nome do dono: %s ", c->cliente->nome);
            printf("ID do dono: %d ", c->cliente->id);
            printf("ID do imovel: %d ", c->item->imovel->identificador);
            printf("Ano do movel: %d\n\n", c->item->imovel->ano);
        }
    }
}

ListaHet* retira_cliente(ListaHet* lista, int id_cliente)
{
    Celula* anterior;
    Celula* atual;

    for (atual = lista->prim; atual != NULL; atual = atual->prox)
    {
        if (atual->cliente->id == id_cliente)
        {
            if (atual == lista->prim)
            {
                lista->prim = atual->prox;
                anterior = atual;
            }
            if (atual->prox == NULL)
            {
                anterior->prox = NULL;
                break;
            }
            else
                anterior->prox = atual->prox;
        }
    }
    return lista;
}

float calcula_valor_assegurado(ListaHet* lista, Cliente* dono, float taxa_movel, float taxa_imovel)
{
    Celula* celula;
    float v = 0;
    for (celula = lista->prim; celula != NULL; celula = celula->prox)
        if (celula->cliente = dono)
            if (celula->id == MOVEL)
                v += celula->item->movel->valor * taxa_movel;
            else if (celula->id == IMOVEL)
                v += celula->item->imovel->valor * taxa_imovel;
    return v;
}