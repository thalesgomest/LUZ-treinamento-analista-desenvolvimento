#include <stdlib.h>
#include <stdio.h>

/*

• Uma árvore binária é uma estrutura de dados que pode ser representada como uma hierarquia onde cada elemento é chamado de nó.
O nó inicial ou o primeiro elemento é chamado de raiz.

• Em uma árvore binária um elemento pode ter um máximo de dois filhos no nível inferior denominados como sub-árvore esquerda e sub-árvore
direita.Um nó sem filhos é chamado de folha.

• A profundidade de um nó é a distância desse nó até a raiz e a distância entre a folha mais distante e a raiz é a altura da árvore.

• Um conjunto de nós com a mesma profundidade é denominado, nível da árvore.

• Uma árvore binária é uma estrutura de dados que permite a inserção e a remoção de elementos em qualquer posição da árvore.

Elementos
Nós - são todos os itens guardados na árvore
Raiz - é o nó do topo da árvore.
Filhos - são os nós que vem depois dos outros nós.
Folhas - são os nós que não têm filhos; são os últimos nós da árvore.

*/

/*definição da estrutura que representará cada elemento da árvore binária*/
typedef struct No {
    int valor;  /*será uma árvore que armazenará inteiros*/
    struct No *esquerda;  /*ponteiros para fazer a ligação entre nós a esquerda e a direita*/
    struct No *direita;
} No;

typedef struct Arvore {
    No *raiz;  /*ponteiro para o nó raiz da árvore*/
} Arvore;

/*função que cria uma árvore binária vazia*/
Arvore *criarArvore() {
    Arvore *arvore = (Arvore *) malloc(sizeof(Arvore));  /*aloca memória para a árvore*/
    arvore->raiz = NULL;  /*inicializa a raiz como NULL*/
    return arvore;
}

/*função que cria um nó da árvore binária*/
No *criarNo(int valor) {
    No *no = (No *) malloc(sizeof(No));  /*aloca memória para o nó*/
    no->valor = valor;  /*atribui o valor ao nó*/
    no->esquerda = NULL;  /*inicializa os ponteiros para os filhos como NULL*/
    no->direita = NULL;
    return no;
}

/*função que insere um nó na árvore binária*/
void inserirNo(No *raiz, No *no) {
    if (no->valor < raiz->valor) {  /*se o valor do nó for menor que o valor do nó raiz*/
        if (raiz->esquerda == NULL) {  /*se o nó raiz não tiver filho a esquerda*/
            raiz->esquerda = no;  /*o nó passa a ser o filho a esquerda do nó raiz*/
        } else {
            inserirNo(raiz->esquerda, no);  /*se o nó raiz tiver filho a esquerda, chama a função novamente passando o filho a esquerda como raiz*/
        }
    } else if (no->valor > raiz->valor) {  /*se o valor do nó for maior que o valor do nó raiz*/
        if (raiz->direita == NULL) {  /*se o nó raiz não tiver filho a direita*/
            raiz->direita = no;  /*o nó passa a ser o filho a direita do nó raiz*/
        } else {
            inserirNo(raiz->direita, no);  /*se o nó raiz tiver filho a direita, chama a função novamente passando o filho a direita como raiz*/
        }
    } else {
        free(no);
    }
}

/*função que insere um valor na árvore binária*/
void inserir(Arvore *arvore, int valor) {
    No *no = criarNo(valor);  /*cria um nó com o valor passado como parâmetro*/
    if (arvore->raiz == NULL) {  /*se a árvore estiver vazia*/
        arvore->raiz = no;  /*o nó criado passa a ser a raiz da árvore*/
    } else {
        inserirNo(arvore->raiz, no);  /*se a árvore não estiver vazia, chama a função inserirNo passando a raiz da árvore como parâmetro*/
    }
}

/* funcao remover */
No* remover(No *raiz, int valor) {
    if (raiz == NULL) {  /*se a raiz for NULL, retorna NULL*/
        printf("\nValor nao encontrado na arvore\n");
        return NULL;
    } else if (valor < raiz->valor) {  /*se o valor for menor que o valor do nó raiz*/
        raiz->esquerda = remover(raiz->esquerda, valor);  /*chama a função novamente passando o filho a esquerda como raiz*/
    } else if (valor > raiz->valor) {  /*se o valor for maior que o valor do nó raiz*/
        raiz->direita = remover(raiz->direita, valor);  /*chama a função novamente passando o filho a direita como raiz*/
    } else {  /*se o valor for igual ao valor do nó raiz*/
        if (raiz->esquerda == NULL && raiz->direita == NULL) {  /*se o nó raiz não tiver filhos*/
            printf("\nNo folha removido: %d\n", valor);
            free(raiz);  /*libera a memória do nó raiz*/
            raiz = NULL;  /*atribui NULL ao nó raiz*/
        } else if (raiz->esquerda == NULL) {  /*se o nó raiz tiver apenas o filho a direita*/
            No *no = raiz;  /*cria um nó auxiliar e atribui o nó raiz a ele*/
            raiz = raiz->direita;  /*o nó raiz passa a ser o filho a direita do nó raiz*/
            printf("\nNo com um filho removido: %d\n", valor);
            free(no);  /*libera a memória do nó auxiliar*/
        } else if (raiz->direita == NULL) {  /*se o nó raiz tiver apenas o filho a esquerda*/
            No *no = raiz;  /*cria um nó auxiliar e atribui o nó raiz a ele*/
            raiz = raiz->esquerda;  /*o nó raiz passa a ser o filho a esquerda do nó raiz*/
            printf("\nNo com um filho removido: %d\n", valor);
            free(no);  /*libera a memória do nó auxiliar*/
        } else {  /*se o nó raiz tiver os dois filhos*/
            No *aux = raiz->esquerda;  /*cria um nó auxiliar e atribui o filho a esquerda do nó raiz a ele*/
            while (aux->direita != NULL) {  /*enquanto o filho a direita do nó auxiliar não for NULL*/
                aux = aux->direita;  /*o nó auxiliar passa a ser o filho a direita dele*/
            }
            raiz->valor = aux->valor;  /*o valor do nó raiz passa a ser o valor do nó auxiliar*/
            aux->valor = valor;  /*o valor do nó auxiliar passa a ser o valor passado como parâmetro*/
            printf("\nNos trocados: %d e %d\n", raiz->valor, aux->valor);
            raiz->esquerda = remover(raiz->esquerda, valor);  /*chama a função novamente passando o filho a esquerda do nó raiz como raiz*/
}
    }
    return raiz;
}

/*funcao esvaziar arvore*/
No* esvaziarArvore(No *raiz) {
    if (raiz != NULL) {  /*se a raiz não for NULL*/
        esvaziarArvore(raiz->esquerda);  /*chama a função novamente passando o filho a esquerda como raiz*/
        esvaziarArvore(raiz->direita);  /*chama a função novamente passando o filho a direita como raiz*/
        free(raiz);  /*libera a memória do nó raiz*/
    }
    return NULL;
}

/*função que imprime a árvore binária em pré-ordem*/
void imprimirPreOrdem(No *raiz) {
    if (raiz != NULL) {  /*se a raiz não for NULL*/
        printf("%d ", raiz->valor);  /*imprime o valor do nó raiz*/
        imprimirPreOrdem(raiz->esquerda);  /*chama a função novamente passando o filho a esquerda do nó raiz como raiz*/
        imprimirPreOrdem(raiz->direita);  /*chama a função novamente passando o filho a direita do nó raiz como raiz*/
    }
}

/*função que imprime a árvore binária em ordem*/
void imprimirOrdem(No *raiz) {
    if (raiz != NULL) {  /*se a raiz não for NULL*/
        imprimirOrdem(raiz->esquerda);  /*chama a função novamente passando o filho a esquerda como raiz*/
        printf("%d ", raiz->valor);  /*imprime o valor do nó*/
        imprimirOrdem(raiz->direita);  /*chama a função novamente passando o filho a direita como raiz*/
    }
}

/*função que imprime a árvore binária em pós-ordem*/
void imprimirPosOrdem(No *raiz) {
    if (raiz != NULL) {  /*se a raiz não for NULL*/
        imprimirPosOrdem(raiz->esquerda);  /*chama a função novamente passando o filho a esquerda como raiz*/
        imprimirPosOrdem(raiz->direita);  /*chama a função novamente passando o filho a direita como raiz*/
        printf("%d ", raiz->valor);  /*imprime o valor do nó*/
    } 
}

// -----------------------------Menu Function-----------------------------

void menu(int op, Arvore *arvore, int num)
{
    do
    {
        printf("\n\tO que voce deseja fazer?\n\n");
        printf("1 - Inserir elemento na arvore\n");
        printf("2 - Imprimir arvore em pre ordem\n");
        printf("3 - Imprimir arvore em ordem\n");
        printf("4 - Imprimir arvore em pos ordem\n");
        printf("5 - Remover elemento da arvore\n");
        printf("6 - Esvaziar arvore\n");
        printf("7 - Sair\n\n");
        printf("Digite a opcao desejada: ");

        scanf("%d", &op);
        system("cls || clear");

        switch (op)
        {
        case 1:
            printf("Digite o numero que deseja inserir: ");
            scanf("%d", &num);
            inserir(arvore, num);
            break;
        case 2:
            imprimirPreOrdem(arvore->raiz);
            break;
        case 3:
            imprimirOrdem(arvore->raiz);
            break;
        case 4:
            imprimirPosOrdem(arvore->raiz);
            break;
        case 5:
            printf("Digite o numero que deseja remover: ");
            scanf("%d", &num);
            arvore->raiz = remover(arvore->raiz, num);
            break;
        case 6:
            arvore->raiz = esvaziarArvore(arvore->raiz);
            break;
        case 7:
            printf("Saindo...\n");
            break;
        default:
            printf("Digite uma opcao valida!\n");
        }
    } while (op != 7);
}

// -----------------------------Main Function-----------------------------

int main()
{
    Arvore *arvore = criarArvore();
    int op, num;

    menu(op, arvore, num);

    return 0;
}







