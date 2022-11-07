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

typedef struct no
{
    int numero;
    struct No *esquerda;
    struct No *direita;
} No;

void criarArvore(No **pRaiz)
{
    *pRaiz = NULL;
}

void insercao(No **pRaiz, int numero2)
{
    if (*pRaiz == NULL)
    {
        *pRaiz = (No *)malloc(sizeof(No));
        (*pRaiz)->esquerda = NULL;
        (*pRaiz)->direita = NULL;
        (*pRaiz)->numero = numero2;
    }
    else
    {
        if (numero2 < ((*pRaiz)->numero))
        {
            insercao(&((*pRaiz)->esquerda), numero2);
        }
        else
        {
            insercao(&((*pRaiz)->direita), numero2);
        }
    }
}

No *MaiorDireita(No **no)
{
    if ((*no)->direita != NULL)
    {
        return MaiorDireita(&(*no)->direita);
    }
    else
    {
        No *aux = *no;

        if ((*no)->esquerda != NULL) // se nao houver essa verificacao, esse nó vai perder todos os seus filhos da esquerda!
        {
            *no = (*no)->esquerda;
        }
        else
        {
            *no = NULL;
            return aux;
        }
    }
}

/* No *MenorEsquerda(No **no)
{
    if ((*no)->esquerda != NULL)
    {
        return MenorEsquerda(&(*no)->esquerda);
    }
    else
    {
        No *aux = *no;
        if ((*no)->direita != NULL) // se nao houver essa verificacao, esse nó vai perder todos os seus filhos da direita!
        {
            *no = (*no)->direita;
        }
        else
        {
            *no = NULL;
        }
        return aux;
    }
} */

void remover(No **pRaiz, int numero)
{
    if (*pRaiz == NULL)
    { // esta verificacao serve para caso o numero nao exista na arvore.
        printf("\nNumero nao existe na arvore!\n");
        getch();
        return;
    }
    if (numero < (*pRaiz)->numero)
        remover(&(*pRaiz)->esquerda, numero);
    else if (numero > (*pRaiz)->numero)
        remover(&(*pRaiz)->direita, numero);
    else
    { // se nao eh menor nem maior, logo, eh o numero que estou procurando! :)
        No *pAux = *pRaiz;
        if (((*pRaiz)->esquerda == NULL) && ((*pRaiz)->direita == NULL))
        { // se nao houver filhos...
            free(pAux);
            (*pRaiz) = NULL;
        }
        else
        { // so tem o filho da direita
            if ((*pRaiz)->esquerda == NULL)
            {
                (*pRaiz) = (*pRaiz)->direita;
                pAux->direita = NULL;
                free(pAux);
                pAux = NULL;
            }
            else
            { // so tem filho da esquerda
                if ((*pRaiz)->direita == NULL)
                {
                    (*pRaiz) = (*pRaiz)->esquerda;
                    pAux->esquerda = NULL;
                    free(pAux);
                    pAux = NULL;
                }
                else
                {                                             // Escolhi fazer o maior filho direito da subarvore esquerda.
                    pAux = MaiorDireita(&(*pRaiz)->esquerda); // se vc quiser usar o Menor da esquerda, so o que mudaria seria isso:
                    pAux->esquerda = (*pRaiz)->esquerda;      //        pAux = MenorEsquerda(&(*pRaiz)->direita);
                    pAux->direita = (*pRaiz)->direita;
                    (*pRaiz)->esquerda = (*pRaiz)->direita = NULL;
                    free((*pRaiz));
                    *pRaiz = pAux;
                    pAux = NULL;
                }
            }
        }
    }
}

/*
Temos três tipo de consultas:

- Em ordem: neste tipo de consulta cada árvore é mostrada primeiramente com o ramo da esquerda, depois a raiz e por fim o ramo da direita.
- Pré-ordem: neste tipo de consulta cada árvore é mostrada primeiramente com a raiz, depois o ramo da esquerda e por fim o ramo da direita.
- Pós-ordem: neste tipo de consulta cada árvore é mostrada primeiramente com o ramo da esquerda, depois o ramo da direita e por fim a raiz.

*/
void imprimirEmOrdem(No *pRaiz)
{
    if (pRaiz != NULL)
    {
        imprimirEmOrdem(pRaiz->esquerda);
        printf("%d ", pRaiz->numero);
        imprimirEmOrdem(pRaiz->direita);
    }
}

void imprimirPreOrdem(No *pRaiz)
{
    if (pRaiz != NULL)
    {
        printf("%d ", pRaiz->numero);
        imprimirPreOrdem(pRaiz->esquerda);
        imprimirPreOrdem(pRaiz->direita);
    }
}

void imprimirPosOrdem(No *pRaiz)
{
    if (pRaiz != NULL)
    {
        imprimirPosOrdem(pRaiz->esquerda);
        imprimirPosOrdem(pRaiz->direita);
        printf("%d ", pRaiz->numero);
    }
}

void apagarArvore(No *pRaiz)
{
    // Funcao para liberar a memoria utilizada pela arvore
    if (pRaiz != NULL)
    {
        apagarArvore(pRaiz->esquerda);
        apagarArvore(pRaiz->direita);
        free(pRaiz);
        pRaiz = NULL;
    }
}

void menu(int op, No *tree, int num)
{
    do
    {
        printf("\n\tO que voce deseja fazer?\n\n");
        printf("1 - Inserir elemento na arvore\n");
        printf("2 - Remover elemento da arvore\n");
        printf("3 - Imprimir arvore em Ordem\n");
        printf("4 - Imprimir arvore em Pre-Ordem\n");
        printf("5 - Imprimir arvore em Pos-Ordem\n");
        printf("6 - Sair\n\n");
        printf("Digite a opcao desejada: ");

        scanf("%d", &op);
        system("cls || clear");

        switch (op)
        {
        case 1:
            printf("Digite o numero que deseja inserir: ");
            scanf("%d", &num);
            insercao(&tree, num);
            break;
        case 2:
            printf("Digite o numero que deseja remover: ");
            scanf("%d", &num);
            remover(&tree, num);
            break;
        case 3:
            printf("Arvore em Ordem: ");
            imprimirEmOrdem(tree);
            break;
        case 4:
            printf("Arvore em Pre-Ordem: ");
            imprimirPreOrdem(tree);
            break;
        case 5:
            printf("Arvore em Pos-Ordem: ");
            imprimirPosOrdem(tree);
            break;
        case 6:
            printf("Saindo...\n");
            break;
        default:
            printf("Digite uma opcao valida!\n");
        }
    } while (op != 6);
}

int main()
{
    No *tree;
    int op, num;

    criarArvore(&tree);
    menu(op, tree, num);
    apagarArvore(tree);
    return 0;
}