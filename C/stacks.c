#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    • Pilhas são estruturas de dados que representam um conjunto de dados organizados em ordem linear e dinâmica.

    • A pilha é uma estrutura de dados que permite a inserção e a remoção de elementos apenas no topo da pilha.
    LIFO -- last in, first out (último a entrar, primeiro a sair).
*/

// -----------------------------Stack Methods-----------------------------

typedef struct stackElement
{
    char *data;
    struct stackElement *next; // ponteiro para o próximo elemento da pilha
} StackElement;

typedef struct stackPointer
{
    StackElement *top; // ponteiro para o elemento que está no início da pilha
    int size;          // tamanho da pilha
} Stack;               // tipo de dado Stack

void initialize(Stack *stack) // Função para inicializar a pilha
{
    stack->top = NULL;
    stack->size = 0;
}

Stack *createStack()
{
    Stack *newStack = (Stack *)malloc(sizeof(Stack));
    initialize(newStack);
    return newStack;
}

StackElement *createStackElement(char *data)
{
    StackElement *newStackElement = (StackElement *)malloc(sizeof(StackElement)); // Alocação de memória para o novo elemento da pilha
    newStackElement->data = (char *)malloc(sizeof(char) * strlen(data));          // Alocação de memória para o campo de dados do novo elemento da pilha
    strcpy(newStackElement->data, data);
    newStackElement->next = NULL; // Supondo que a pilha está vazia.
    return newStackElement;
}

void push(Stack *stack, char *data)
{
    StackElement *newStackElement = createStackElement(data);

    // Verifica se a pilha está vazia ou não
    if (stack->top == NULL) // Se está vazia
    {
        stack->top = newStackElement;
    }
    else // Se não está vazia
    {
        newStackElement->next = stack->top;
        stack->top = newStackElement;
    }
    stack->size++;
}

void pop(Stack *stack)
{
    if (stack->top == NULL)
    {
        printf("A pilha está vazia!\n");
    }
    else
    {
        StackElement *aux = stack->top; // Elemento auxiliar para guardar o elemento que está no topo da pilha
        stack->top = stack->top->next;  // Faz o topo apontar para o próximo elemento da pilha
        free(aux->data);
        free(aux); // Liberta a memória do elemento que está no topo da pilha
        stack->size--;
    }
}

// -----------------------------Utility Functions-----------------------------

void printStack(Stack *stack)
{
    if (stack->top == NULL)
    {
        printf("A pilha esta vazia!\n");
    }
    else
    {
        StackElement *aux = stack->top;
        while (aux != NULL)
        {
            printf("%s ", aux->data);
            aux = aux->next;
        }
        printf("\n");
    }
}

// -----------------------------Menu Function-----------------------------

void menu(int op, Stack *stack, char *data)
{
    do
    {
        printf("\n\tO que voce deseja fazer?\n\n");
        printf("1 - Inserir elemento na pilha\n");
        printf("2 - Remover elemento da pilha\n");
        printf("3 - Imprimir pilha\n");
        printf("4 - Sair\n\n");
        printf("Digite a opcao desejada: ");

        scanf("%d", &op);
        system("cls || clear");

        switch (op)
        {
        case 1:
            printf("Qual string voce deseja inserir na pilha: ");
            scanf("%s", data);
            push(stack, data);
            break;
        case 2:
            pop(stack);
            break;
        case 3:
            printStack(stack);
            break;
        case 4:
            printf("Saindo...\n");
            break;
        default:
            printf("Digite uma opcao valida!\n");
        }
    } while (op != 4);
}

// -----------------------------Main Function-----------------------------

int main()
{
    Stack *stack = createStack();
    int op;
    char *data = (char *)malloc(sizeof(char) * strlen(data));
    menu(op, stack, data);
    return 0;
}