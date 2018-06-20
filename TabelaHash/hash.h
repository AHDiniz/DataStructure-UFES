#ifndef HASH_H_

#define HASH_H_

#include "lista.h"

typedef struct tabelaHash TabelaHash;
typedef struct palavra Palavra;

TabelaHash* TabelaHash_Cria(unsigned int tamanho);
void TabelaHash_Destroi(TabelaHash* th);
int TabelaHash_Dispersao(char* chave, TabelaHash* tabela);

Palavra* Palavra_Cria(char* p);
void Palavra_Destroi(Palavra* p);

#endif