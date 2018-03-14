#include <stdio.h>
#include <stdlib.h>

#define PI 3.1415

void calc_esfera(float, float*, float*);
int negativos(int, float*);
void inverte(int, int*);
void troca(int*, int*);
int** inverte2(int, int*);
int* achaMenor(int, int, int*, int**);

int main()
{
    // Teste calc_esfera:
    float r, a, v;
    printf("Insira o raio da esfera para que o programa calcule a area da superficie e o volume:\n");
    scanf("%f", &r);
    calc_esfera(r, &a, &v);
    printf("Area: %.2f, Volume: %.2f\n", a, v);

    // Teste negativos:
    int n, i;
    float *array;
    printf("Insira o tamanho do vetor de numeros (o programa contara os negativos):\n");
    scanf("%d", &n);
    array = (float *)malloc(n * sizeof(float));
    for (i = 0; i < n; i++)
    {
        printf("Insira o elemento da posicao %d:\n", i);
        scanf("%f", &array[i]);
    }
    printf("Negativos: %d\n", negativos(n, array));
    free(array);
    
    // Teste inverte:
    int *array2;
    printf("Insira o tamanho do vetor de numeros (o programa vai inverter o vetor):\n");
    scanf("%d", &n);
    array2 = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
    {
        printf("Insira o elemento da posicao %d:\n", i);
        scanf("%d", &array2[i]);
    }
    inverte(n, array2);
    printf("Vetor invertido: ");
    for (i = 0; i < n; i++)
        printf("%d ", array2[i]);
    printf("\n");
    free(array2);

    // Teste inverte2:
    int **array3;
    printf("Insira o tamanho do array (o programa vai ordena-lo por meio dos endereços de memoria):\n");
    scanf("%d", &n);
    array2 = (int*)calloc(n, sizeof(int));
    for (i = 0; i < n; i++)
    {
        printf("Insira o elemento da posicao %d:\n", i);
        scanf("%d", &array2[i]);
    }
    array3 = inverte2(n, array2);
    printf("Vetor ordenado: ");
    for (i = 0; i < n; i++)
        printf("%d ", **array3);
    printf("\n");
    return (0);
}

void calc_esfera(float r, float *area, float *volume)
{
    *area = 4 * PI * r * r;
    *volume = (4 / 3) * PI * r * r * r;
}

int negativos(int n, float *vet)
{
    int neg = 0, i;
    for (i = 0; i < n; i++)
    {
        if (vet[i] < 0)
        {
            neg++;
        }
    }
    return neg;
}

void inverte(int n, int *vet)
{
    int i;
    for (i = 0; i < (n / 2); i++)
        troca(&vet[i], &vet[n - i - 1]);
        
}

void troca(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int** inverte2(int n, int *vet)
{
    int **pVet = (int**)calloc(n, sizeof(int*));
    int i, menor;
    for (i = 0; i < n; i++)
        pVet[i] = achaMenor(i, n - 1, vet);
    return pVet;
}

int* achaMenor(int i, int f, int *v, int **pv)
{
    int m = v[i], j;
    for (j = 0; j <= f; j++)
        if (v[j] < m)
        {
            m = v[j];
            break;
        }
    for (j = 0; j <= f; j++)
        if (v[j] == m)
            return &v[j];
}