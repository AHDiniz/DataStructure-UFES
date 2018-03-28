#include <stdlib.h>
#include <stdio.h>
#include "matriz.h"

struct matriz
{
    int linhas;
    int colunas;
    int** m;
};

Matriz* inicializaMatriz(int nLinhas, int nColunas)
{
    Matriz* m = (Matriz*)malloc(sizeof(struct matriz));
    m->colunas = nColunas;
    m->linhas = nLinhas;
    m->m = (int**)malloc(nLinhas * sizeof(int*));
    for (int i = 0; i < nLinhas; i++)
        m->m[i] = (int*)malloc(nColunas * sizeof(int));
}

void modificaElemento(Matriz *mat, int linha, int coluna, int elem)
{
    mat->m[linha][coluna] = elem;
}

int recuperaElemento(Matriz *mat, int linha, int coluna)
{
    return mat->m[linha][coluna];
}

int recuperaNColunas(Matriz *mat)
{
    return mat->colunas;
}

int recuperaNLinhas(Matriz *mat)
{
    return mat->linhas;
}

void destroiMatriz(Matriz *mat)
{
    for (int i = 0; i < mat->linhas; i++)
        free(mat->m[i]);
    free(mat->m);
    free(mat);
}

void imprimeMatriz(Matriz *mat)
{
    for (int i = 0; i < mat->linhas; i++)
    {
        for (int j = 0; j < mat->colunas; j++)
            printf("%d ", mat->m[i][j]);
        printf("\n");
    }
}

Matriz* transposta(Matriz *mat)
{
    Matriz* trp = inicializaMatriz(mat->colunas, mat->linhas);
    for (int i = 0; i < trp->linhas; i++)
        for (int j = 0; j < trp->colunas; j++)
            modificaElemento(trp, i, j, recuperaElemento(mat, j, i));
}

Matriz* multiplicacao(Matriz *mat1, Matriz *mat2)
{
    if (recuperaNColunas(mat1) == recuperaNLinhas(mat2))
    {
        Matriz *mult = inicializaMatriz(mat1->linhas, mat2->colunas);
        for (int i = 0; i < mult->linhas; i++)
            for (int j = 0; j < mult->colunas; j++)
            {
                modificaElemento(mult, i, j, 0);
                for (int k = 0; k < mat1->linhas; k++)
                {
                    int aux = recuperaElemento(mult, i, j) + recuperaElemento(mat1, i, k) * recuperaElemento(mat2, k, j);
                    modificaElemento(mult, i, j, aux);
                }
            }
    }
    else
    {
        printf("Erro: impossivel multiplicar as matrizes de entrada.\n");
        return NULL;
    }
}
