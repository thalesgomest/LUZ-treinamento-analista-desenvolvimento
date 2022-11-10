#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    • Filas são estruturas de dados que representam um conjunto de dados organizados em ordem linear e dinâmica.

    • A fila é uma estrutura de dados que permite a inserção e a remoção de elementos apenas no final da fila.
    FIFO -- first in, first out (primeiro a entrar, primeiro a sair).

*/

// -----------------------------Queue Methods-----------------------------

// Estrutura de cada elemento da fila. Serve para colocar elementos dentro da fila.
typedef struct queueElement
{
    char *data;
    struct queueElement *next; // ponteiro para o próximo elemento da fila
} QueueElement;

// Estrutura da fila. Serve para controlar a fila.
typedef struct queuePointer
{
    QueueElement *first; // ponteiro para o primeiro elemento da fila
    QueueElement *last;  // ponteiro para o último elemento da fila
    int size;            // tamanho da fila
} Queue;


// Função para criar fila
Queue *createQueue()
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->first = NULL;
    queue->last = NULL;
    queue->size = 0;
    return queue;
}

// Criar elemento da fila
QueueElement *createQueueElement(char *data)
{
    QueueElement *newElement = (QueueElement *)malloc(sizeof(QueueElement)); // Alocação de memória para o elemento.
    newElement->data = (char *)malloc(sizeof(char) * strlen(data));          // Alocação de memória para o dado do elemento.
    strcpy(newElement->data, data);                                          // Copia o dado para o elemento.
    newElement->next = NULL;
    return newElement;
}

// Função para inserir elemento na fila
void enqueue(Queue *queue, char *data)
{
    QueueElement *newElement = createQueueElement(data); // Cria o elemento da fila.

    if (queue->first == NULL) // Se a fila estiver vazia, o primeiro elemento da fila é o novo elemento.
    {
        queue->first = newElement;
    }
    else // Se a fila não estiver vazia, o último elemento da fila aponta para o novo elemento.
    {
        queue->last->next = newElement;
    }

    queue->last = newElement; // O último elemento da fila é o novo elemento.
    queue->size++;            // Incrementa o tamanho da fila.
}

// Função para remover elemento da fila
void dequeue(Queue *queue)
{
    if (queue->first != NULL) // Se a fila existir.
    {
        QueueElement *element = queue->first; // Elemento recebe o primeiro elemento da fila.
        queue->first = queue->first->next;    // O primeiro elemento da fila recebe o próximo elemento da fila.
        free(element->data);                  // Libera o dado do elemento.
        free(element);                        // Libera o elemento.
        queue->size--;                        // Decrementa o tamanho da fila.
    }
    else
    {
        printf("A fila esta vazia!\n");
    }
}

// -----------------------------Utility Methods-----------------------------

// Função para imprimir a fila
void printQueue(Queue *queue)
{
    QueueElement *element = queue->first; // Elemento recebe o primeiro elemento da fila.

    while (element != NULL) // Enquanto o elemento não for nulo.
    {
        printf("%s ", element->data); // Imprime o dado do elemento.
        element = element->next;      // Elemento recebe o próximo elemento da fila.
    }
}

// Função para imprimir o tamanho da fila
void printQueueSize(Queue *queue)
{
    printf("\n\nTamanho da fila: %d\n", queue->size);
}

// -----------------------------Menu Function-----------------------------

void menu(int op, Queue *queue, char *data)
{
    do
    {
        printf("\n\tO que voce deseja fazer?\n\n");
        printf("1. Adicionar elementos na fila\n");
        printf("2. Remover elementos da fila\n");
        printf("3. Imprimir elementos da fila\n");
        printf("4. Sair do programa\n\n");
        printf("Digite a opcao desejada: ");

        scanf("%d", &op);
        system("cls || clear");

        switch (op)
        {
        case 1:
            printf("Qual o string que voce deseja inserir?\n");
            scanf("%s", data);
            enqueue(queue, data);
            break;
        case 2:
            dequeue(queue);
            break;
        case 3:
            printQueue(queue);
            printQueueSize(queue);
            break;
        case 4:
            printf("Saindo do programa...\n");
            break;
        default:
            printf("Digite uma opcao valida\n");
        }
    } while (op != 4);
}

// -----------------------------Main Function-----------------------------

int main()
{
    Queue *queue = createQueue();                             // Cria a fila.
    char *data = (char *)malloc(sizeof(char) * strlen(data)); // Alocação de memória para o dado.
    int op;
    menu(op, queue, data);
    return 0;
}