#include "hash.h"
#include <stdlib.h>
#include <string.h>

struct tabelaHash
{
    Lista** tabela;
    unsigned int tamanho;
};

struct palavra
{
    char* p;
    int q;
};

TabelaHash* TabelaHash_Cria(unsigned int tamanho)
{
    TabelaHash* th = (TabelaHash*)malloc(sizeof(TabelaHash));
    th->tabela = (Lista**)malloc(sizeof(Lista*) * tamanho);
    int i;
    for (i = 0; i < tamanho; i++)
        th->tabela[i] = Lista_Cria("char*");
    th->tamanho = tamanho;
    return th;
}

void TabelaHash_Destroi(TabelaHash* th)
{
    int i;
    for (i = 0; i < th->tamanho; i++)
        Lista_Destroi(th->tabela[i], NULL);
    free(th->tabela);
    free(th);
    th = NULL;
}

int TabelaHash_Dispersao(char* chave, TabelaHash* tabela)
{
    return (strlen(chave) + 1) % tabela->tamanho;
}



Palavra* Palavra_Cria(char* p)
{
    Palavra* plv = (Palavra*)malloc(sizeof(Palavra));
    plv->p = (char*)malloc(strlen(p) + 1);
    strcpy(plv->p, p);
    
}
