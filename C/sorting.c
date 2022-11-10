#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <locale.h>

// -----------------------------Utility Functions-----------------------------

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

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// _______________________________Sorting Algorithms______________________________

// A function to implement Bubble Sort
/*[PT-BR]
BUBBLE SORT
O Bubble Sort é um algoritmo de ordenação simples. Este algoritmo percorre o vetor várias vezes,
e a cada passagem compara pares de elementos adjacentes e os troca de posição caso estejam em ordem errada.
O algoritmo só para quando não houver mais trocas a serem feitas, o que significa que o vetor está ordenado.
*/

void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)

        // Ultimos i elementos já estão no lugar certo
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}

// Optimized version of Bubble Sort
void bubbleSortOpt(int arr[], int n)
{
    int flag = 1;
    int i, j;
    for (i = 0; i < n - 1 && flag == 1; i++)
    {
        flag = 0; // flag = 0 significa que não houve troca
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                flag = 1; // flag = 1 significa que houve troca
            }
        }
    }
}

// A function to implement Insertion sort

/*[PT-BR]
INSERTION SORT
O funcionamento do algoritmo é bem simples: consiste em cada passo a partir do segundo
elemento selecionar o próximo item da sequência e colocá-lo no local apropriado de acordo
com o critério de ordenação.
*/
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        /* Move os elementos do arr[0..i-1], que são maiores que a chave, para uma posição à frente da sua posição atual */
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// A function to implement Selection Sort
/*[PT-BR]
SELECTION SORT
A ordenação por seleção ou selection sort consiste em selecionar o menor item e colocar na primeira posição, selecionar
 o segundo menor item e colocar na segunda posição, segue estes passos até que reste um único elemento. */

void selectionSort(int arr[], int n)
{
    int i, j, min_idx;

    // Um por um move o limite do vetor não ordenado
    for (i = 0; i < n - 1; i++)
    {
        // Encontra o menor elemento no vetor não ordenado
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        // Troca o menor elemento encontrado com o primeiro elemento
        if (min_idx != i)
            swap(&arr[min_idx], &arr[i]);
    }
}

// A function to implement Merge Sort

/*
[PT-BR]
MERGE SORT
Lema: Dividir para conquistar!
Procedimento: Dividir no meio até sobrar um elemento. Depois os elementos vão sendo combinados/mergeados de forma ordenada.
Recursão
Vantagens: complexidade de tempo, tanto no melhor, quanto no pior caso é de O(n log n).No melhor caso
ou médio, é equivalente à complexidade do Quick Sort;
Desvantagem: Faz uso de n unidades O(n) de memória auxiliar. É necessário um vetor auxiliar.
*/

void merge(int arr[], int start, int middle, int end)
{
    int start_1 = start, start_2 = middle + 1, start_aux = 0, length = end - start + 1;
    int *arrAux;
    arrAux = (int *)malloc(length * sizeof(int));

    // Equanto houver elementos em ambos os subvetores. É interrompido quando um dos subvetores acabam
    while (start_1 <= middle && start_2 <= end)
    {
        /* Comparo o primeiro valor dispinível de um subvetor com primeiro valor disponível do outro
        Salvo o menor valor no vetor auxiliar e passo para o próximo elemento do vetor auxliar e da metade que tiver tirado o menor valor */
        if (arr[start_1] < arr[start_2])
        {
            arrAux[start_aux] = arr[start_1];
            start_1++;
        }
        else
        {
            arrAux[start_aux] = arr[start_2];
            start_2++;
        }
        start_aux++;
    }

    // Caso ainda haja elementos no primeiro subvetor, vou salvando no vetor auxiliar os números restantes
    while (start_1 <= middle)
    {
        arrAux[start_aux] = arr[start_1];
        start_aux++;
        start_1++;
    }

    // Caso ainda haja elementos no segundo subvetor, vou salvando no vetor auxiliar os números restantes
    while (start_2 <= end)
    {
        arrAux[start_aux] = arr[start_2];
        start_aux++;
        start_2++;
    }

    // Copio os elementos do vetor auxiliar para o vetor original
    for (start_aux = start; start_aux <= end; start_aux++)
    {
        arr[start_aux] = arrAux[start_aux - start];
    }

    // Libero a memória alocada para o vetor auxiliar
    free(arrAux);
}

void mergeSort(int arr[], int start, int end)
{ // O vetor será dividido até restar um elemento
    if (start < end)
    {
        int middle = floor((end + start) / 2); // Cálculo meio do vetor

        mergeSort(arr, start, middle);
        mergeSort(arr, middle + 1, end);
        merge(arr, start, middle, end);
    }
}

// A function to implement Quick Sort
/*
[PT-BR]
QUICK SORT

Escolhe um elemento como pivô
Aloca na esquerda do pivô os valores menores do que ele e na direita os valores maiores
No final do algoritmo o pivô estará na posição correta
Recursão: Divide duas partes, escolhe novo pivô e faz o mesmo procedimento
Vantagens: Não necessita de Vetor Auxilar (não gasta memória extra) e no melhor caso apresenta complexidade O(n log n).
Desvantagem: pode apresentar, no pior caso, O(n²)
Pior caso - vetor ordenado ou quase ordenado
Ao escolher o pivô em extremidades, um lado fica vazio e outro fica com tamanho n-1
Recursão no lado não vazio
Se o vetor estivesse desordenado em cada passo iria ordenar mais números
*/

void quickSort(int *arr, int left, int right)
{
    int i, j, x, y;

    i = left;
    j = right;
    x = arr[(left + right) / 2];

    while (i <= j)
    {
        while (arr[i] < x && i < right)
        {
            i++;
        }
        while (arr[j] > x && j > left)
        {
            j--;
        }
        if (i <= j)
        {
            y = arr[i];
            arr[i] = arr[j];
            arr[j] = y;
            i++;
            j--;
        }
    }

    if (j > left)
    {
        quickSort(arr, left, j);
    }
    if (i < right)
    {
        quickSort(arr, i, right);
    }
}

// _______________________________Menu Function______________________________

void menu(int op, int arr[], int n)
{
    do
    {
        printf("\n\tQual metodo de ordencao voce quer usar?\n\n");
        printf("1. Bubble Sort\n");
        printf("2. Bubble Sort Optimized\n");
        printf("3. Insertion Sort\n");
        printf("4. Selection Sort\n");
        printf("5. Merge Sort\n");
        printf("6. Quick Sort\n");
        printf("7. Imprimir Array\n");
        printf("8. Sair do programa\n");
        printf("\nDigite a opcao desejada: ");
        scanf("%d", &op);
        system("cls || clear");

        switch (op)
        {
        case 1:
            bubbleSort(arr, n);
            break;
        case 2:
            bubbleSortOpt(arr, n);
            break;
        case 3:
            insertionSort(arr, n);
            break;
        case 4:
            selectionSort(arr, n);
            break;
        case 5:
            mergeSort(arr, 0, n - 1);
            break;
        case 6:
            quickSort(arr, 0, n - 1);
            break;
        case 7:
            printArray(arr, n);
            break;
        case 8:
            printf("Saindo do programa...\n");
            break;
        default:
            printf("Digite uma opcao valida\n");
        }

    } while (op != 8);
}

// _______________________________Main Function______________________________

int main()
{
    int op;
    int n;

    printf("Quantos registros voce quer inserir no vetor?\n");
    scanf("%d", &n);
    int *arr = spaceAlocation(n);
    generateNumbers(arr, n);
    menu(op, arr, n);
    free(arr);
    return 0;
}