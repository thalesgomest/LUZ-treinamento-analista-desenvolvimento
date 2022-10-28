#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int *spaceAlocation(int n)
{
    return (int *)malloc(n * sizeof(int));
}

void generateNumbers(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        arr[i] = (rand() % n);
    }
}

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// A function to implement bubble sort
void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)

        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int op;
    int n;

    printf("Quantos registros você quer inserir no vetor?\n");
    scanf("%d", &n);
    int *arr = spaceAlocation(n);
    generateNumbers(arr, n);
    printArray(arr, n);

    do
    {
        printf("\n\tQual método de ordenação você quer usar?\n\n");
        printf("1. Bubble Sort\n");
        printf("2. Insertion Sort\n");
        printf("3. Selection Sort\n");
        printf("4. Merge Sort\n");
        printf("5. Quick Sort\n");
        printf("6. Sair do programa\n");

        scanf("%d", &op);
        system("cls || clear");

        switch (op)
        {
        case 1:
            bubbleSort(arr, n);
            printf("Sorted array: \n");
            printArray(arr, n);
            break;
        case 6:
            printf("Saindo do programa...\n");
            break;
        default:
            printf("Digite uma opcao valida\n");
        }

    } while (op != 6);
}