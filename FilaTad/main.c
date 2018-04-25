/*
*********************************
* Programa testador do TAD Fila (usando pilhas)
* *********************************
*/
#include <stdio.h>
#include "fila.h"

int main()
{

    // criando a fila vazia
    Fila *f = cria_fila();

    // tentando imprimir a fila (ainda vazia neste momento)
    imprime_fila(f);

    // criando algumas pessoas apenas para testar (mais adequado seria carregar de um arquivo)
    Pessoa *pessoa1 = inicializaPessoa("pessoa1", 51, "rua da pessoa1");
    Pessoa *pessoa2 = inicializaPessoa("pessoa2", 63, "rua da pessoa2");
    Pessoa *pessoa3 = inicializaPessoa("pessoa3", 10, "rua da pessoa3");
    Pessoa *pessoa4 = inicializaPessoa("pessoa4", 70, "rua da pessoa4");
    Pessoa *pessoa5 = inicializaPessoa("pessoa5", 20, "rua da pessoa5");
    Pessoa *pessoa6 = inicializaPessoa("pessoa6", 30, "rua da pessoa6");
    Pessoa *pessoa7 = inicializaPessoa("pessoa7", 40, "rua da pessoa7");
    Pessoa *pessoa8 = inicializaPessoa("pessoa8", 45, "rua da pessoa8");
    Pessoa *pessoa9 = inicializaPessoa("pessoa9", 65, "rua da pessoa9");
    Pessoa *pessoa10 = inicializaPessoa("pessoa10", 67, "rua da pessoa10");
    Pessoa *pessoa11 = inicializaPessoa("pessoa11", 13, "rua da pessoa11");

    //Insere os pessoas na fila
    insere(pessoa1, f);
    insere(pessoa2, f);
    insere(pessoa3, f);
    insere(pessoa4, f);
    insere(pessoa5, f);
    insere(pessoa6, f);
    insere(pessoa7, f);
    insere(pessoa8, f);
    insere(pessoa9, f);
    insere(pessoa10, f);
    insere(pessoa11, f);

    printf("---------- Imprime fila-----------\n");
    //Imprime a fila com todas as pessoas
    imprime_fila(f);

    // Retira pessoa1 do inicio da fila
    Pessoa *retirado = retira(f);
    // Insere pessoa1 no final da fila
    insere(retirado, f);
    // Retira pessoa2 do inicio da fila
    retirado = retira(f);
    // Insere pessoa2 no final da fila
    insere(retirado, f);
    // Retira pessoa3 do inicio da fila
    retirado = retira(f);
    // Insere pessoa3 no final da fila
    insere(retirado, f);

    printf("---------- Imprime fila-----------\n");
    //Imprime a fila com todas as pessoas
    imprime_fila(f);

    // Retira pessoa4 do inicio da fila
    retirado = retira(f);
    // Insere pessoa4 no final da fila
    insere(retirado, f);
    // Retira pessoa5 do inicio da fila
    retirado = retira(f);
    // Insere pessoa5 no final da fila
    insere(retirado, f);

    printf("---------- Imprime fila-----------\n");
    //Imprime a fila com todas as pessoas
    imprime_fila(f);
    /*
    Fila *f_maiores = cria_fila();
    Fila *f_menores = cria_fila();

    separa_filas(f, f_maiores, f_menores);

    printf("---------- Imprime fila-----------\n");
    //Imprime a fila com todas as pessoas
    imprime_fila(f);

    printf("---------- Imprime fila Maiores-----------\n");
    //Imprime a fila com todas as pessoas maiores que 60
    imprime_fila(f_maiores);

    printf("---------- Imprime fila Menores-----------\n");
    //Imprime a fila com todas as pessoas menores que 60
    imprime_fila(f_menores);*/

    //libera a mem�ria ocupada pela fila
    f = destroi_fila(f);
}