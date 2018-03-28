#include "matriz.h"
#include <stdlib.h>

Matriz NovaMatriz(int linhas, int colunas)
{
    Matriz m = (Matriz)calloc(linhas, sizeof(float*));
    for (int i = 0; i < linhas; i++)
        m[i] = (float*)calloc(colunas, sizeof(float));
    return m;
}