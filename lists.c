#include <stdio.h>
#include <stdlib.h>

/*

• Uma lista encadeada é uma estrutura de dados que representa um conjunto
de dados organizados em ordem linear e dinâmica.

• Cada elemento da lista é chamado de nó e contém um campo de dados e um
ponteiro para o próximo nó da lista.

• A lista encadeada é uma estrutura de dados que permite a inserção e a
remoção de elementos em qualquer posição da lista.

*/

// -----------------------------List Methods-----------------------------

typedef struct node
{
    int data;          // campo de dados
    struct node *next; // ponteiro para o próximo nó
} Node;                // tipo de dado Node

typedef struct
{
    Node *head; // ponteiro para o primeiro nó da lista
    Node *tail; // ponteiro para o último nó da lista
    int size;   // tamanho da lista
} List;         // tipo de dado List

void initialize(List *list) // Função para inicializar a lista
{
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL; // Supondo que a lista está vazia.
    return newNode;
}

List *createList()
{
    List *newList = (List *)malloc(sizeof(List));
    initialize(newList);
    return newList;
}

void insertAtBeginning(List *list, int data)
{
    Node *newNode = createNode(data); // criar variável que vai receber nó chamado newNode! Criando ponteiro!

    // Verifica se a lista está vazia ou não
    if (list->head == NULL) // Se está vazia
    {
        list->head = newNode; // É o primeiro nó da lista
        list->tail = newNode; // É o último nó da lista
    }
    else // Se não está vazia
    {
        newNode->next = list->head; // O ponteiro que estava no inicio da lista, agora aponta para o novo nó
        list->head = newNode;       // O primeiro nó da lista passa a ser o novo nó
    }
    list->size++;
}

void insertAtEnding(List *list, int data)
{
    Node *newNode = createNode(data); // criar variável que vai receber nó chamado newNode! Criando ponteiro!

    // Verifica se a lista está vazia ou não
    if (list->head == NULL) // Se está vazia
    {
        list->head = newNode; // É o primeiro nó da lista
        list->tail = newNode; // É o último nó da lista
    }
    else // Se não está vazia
    {
        list->tail->next = newNode; // O ponteiro do último nó da lista aponta para o novo nó
        list->tail = newNode;       // O último nó da lista passa a ser o novo nó
    }
    list->size++;
}

void removeAtBeginning(List *list)
{
    if (list->head != NULL) // Verifica se a lista não está vazia
    {
        Node *node = list->head;       // Cria variável que vai receber o primeiro nó da lista
        list->head = list->head->next; // O primeiro nó da lista passa a ser o segundo nó da lista
        list->size--;
        if (list->head == NULL) // Verifica se a lista ficou vazia
        {
            list->tail = NULL; // O último nó da lista passa a ser NULL
        }
        free(node); // Libera o primeiro nó da lista
    }
}

void removeSpecifiedNode(List *list, int value)
{
    Node *previous = NULL;      // ponteiro para o nó anterior
    Node *current = list->head; // ponteiro para o nó atual

    while (current != NULL && current->data != value) // Verifica se o nó atual não é NULL e se o valor do nó atual é diferente do valor que queremos remover
    {
        previous = current;      // O nó anterior passa a ser o nó atual
        current = current->next; // O nó atual passa a ser o próximo nó
    }

    if (current != NULL)
    {
        if (previous == NULL)
        {
            removeAtBeginning(list);
        }
        else
        {
            previous->next = current->next;
            list->size--;
            if (current == list->tail)
            {
                list->tail = previous;
            }
            free(current);
        }
    }
}

// -----------------------------Utility Functions-----------------------------

int chosenValue()
{
    int value;
    printf("Qual o valor voce deseja inserir ou remover?\n");
    scanf("%d", &value);
    return value;
}

void printfList(List *list)
{
    Node *aux = list->head;
    while (aux != NULL)
    {
        printf("%d ", aux->data);
        aux = aux->next;
    }
    printf("\n");
}

// _______________________________Menu Function______________________________

void menu(int op, List *list, int value)
{
    do
    {
        printf("\n\tO que voce deseja fazer?\n\n");
        printf("1. Inserir um valor no inicio da lista\n");
        printf("2. Inserir um valor no final lista\n");
        printf("3. Remover um valor do inicio da lista\n");
        printf("4. Remover um valor especifico da lista\n");
        printf("5. Imprimir lista\n");
        printf("6. Sair\n\n");
        printf("Digite a opcao desejada: ");
        scanf("%d", &op);
        system("cls || clear");

        switch (op)
        {
        case 1:
            value = chosenValue();
            insertAtBeginning(list, value);
            break;
        case 2:
            value = chosenValue();
            insertAtEnding(list, value);
            break;
        case 3:
            removeAtBeginning(list);
            break;
        case 4:
            value = chosenValue();
            removeSpecifiedNode(list, value);
            break;
        case 5:
            printfList(list);
            break;
        case 6:
            printf("Saindo...\n");
            break;
        default:
            printf("Digite uma opcao valida\n");
        }

    } while (op != 6);
}

// _______________________________Main Function______________________________

void main()
{
    int value, op;
    List *list = createList();
    menu(op, list, value);
}