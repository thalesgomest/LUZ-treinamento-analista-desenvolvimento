#include <stdio.h>

/*
Olhando a nível de memória, quando eu tenho três linhas:
int variavel1 = 10;
int *variavel2 = &variavel1;
int *variavel3 = variavel2;
A nível de referência de memória, descreva o que sabemos sobre as linhas acima.
*/

int main()
{
    int variavel1 = 10;
    int *variavel2 = &variavel1;
    int *variavel3 = variavel2;

    printf("variavel1 = %d\n", variavel1);  // 10
    printf("variavel2 = %p\n", variavel2);  // endereco de memoria de variavel1
    printf("variavel3 = %hx\n", variavel3); // endereco de memoria de variavel1

    /* Outro exemplo */
    int *a;
    int b = 5;

    a = &b;

    printf("\na = %p\n", a); // endereco de memoria de b
    printf("*a = %d\n", *a);
    return 0;
}
