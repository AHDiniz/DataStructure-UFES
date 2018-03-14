// Read a string and reverse it
// Alan Herculano Diniz
// 03/14/2018

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *ReverseString(char *, int);

int main(void)
{
    char *string;
    int size;

    printf("This program gets an input string and reverse it.\n");

    printf("How many characters does the string have:\n");
    if (scanf("%zu", &n) != 1)
    {
        printf("Invalid input.\n");
        exit(EXIT_FAILURE);
    }

    if ((string = (char *) calloc(size, sizeof(char))) == NULL)
    {
        printf("Cannot allocate %zu bytes for the string.\n", size * sizeof(char));
        exit(EXIT_FAILURE);
    }

    printf("Insert the string:\n");
    scanf("%s", string);
    
    return 0;
}

char *ReverseString(char *s, int n)
{
    if (s == 0 || *s == 0)
        return;

    char a[n];
    
}