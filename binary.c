/*definição da estrutura que representará cada elemento da árvore binária*/
typedef struct No
{
    int num;              /*será uma árvore que armazenará inteiros*/
    struct No *esq, *dir; /*ponteiros para fazer a ligação entre nós a esquerda e a direita*/
} No;

typedef struct Arvore
{
    struct No *raiz; /*ponteiro que irá apontar para a raiz da árvore*/
} Arvore;

/*definição do estrutura que irá representar cada elemento da árvore em um pilha*/
struct Elemento
{
    struct No *num;
    struct Elemento *prox;
};
typedef struct Elemento Elemento;

/*registro do tipo Pilha contento um ponteiro "topo" do tipo Elemento para controlar a pilha*/
struct Pilha
{
    struct Elemento *topo; /*aponta para o elemento qu esta no topo da pilha*/
};
typedef struct Pilha Pilha;

/*ponteiros auxiliares*/
No *aux;
No *aux1;
No *novo;
No *anterior;

Elemento *aux2;

Arvore *cria_arvore()
{
    /*alocação do ponteiro arv para controlar a árvore*/
    Arvore *arv = (Arvore *)malloc(sizeof(Arvore));
    if (arv != NULL)
    {
        arv->raiz = NULL; /*a pilha inicia-se vazia, portanto seu topo é igual a NULL*/
    }
    return arv;
}

Pilha *cria_pilha()
{
    /*alocação do ponteiro pi para controlar a pilha*/
    Pilha *pi = (Pilha *)malloc(sizeof(Pilha));
    if (pi != NULL)
    {
        pi->topo = NULL; /*a pilha inicia-se vazia, portanto seu topo é igual a NULL*/
    }
    return pi;
}

void insere_elemento(Arvore *arv)
{
    /*a cada inserção alocamos dinamicamente um espaço para um novo elemento*/
    No *novo = (No *)malloc(sizeof(No));
    printf("Digite o numero a ser inserido na arvore: ");
    scanf("%d", &novo->num);
    novo->esq = NULL;
    novo->dir = NULL;
    /*caso a árvore esteja vazia, o elemento inserido será a raiz */
    if (arv->raiz == NULL)
    {
        arv->raiz = novo;
        /*caso a árvore  já contenha algum elemento*/
    }
    else
    {
        /*variável para verificação*/
        int achou;
        /*aux aponta para o mesmo endereço de raiz*/
        aux = arv->raiz;
        achou = 0;
        /*é feita uma busca em toda árvore para saber onde novo deve ser enserido*/
        while (achou == 0)
        {
            /*caso o novo numero a ser inserido seja menor que aux-> num*/
            if (novo->num < aux->num)
            {
                /*caso não aja nenhum elemento a esquerda de aux, novo será inserido a esquerda dele*/
                if (aux->esq == NULL)
                {
                    aux->esq = novo;
                    achou = 1;
                    /*caso já exista um elemento a esquerda de aux, aux  aponta para este elemento  e uma nova iteração será realizada*/
                }
                else
                {
                    aux = aux->esq;
                }
                /*caso o novo numero a ser inserido seja maior ou igual a aux-> num*/
            }
            else if (novo->num >= aux->num)
            {
                /*caso não aja nenhum elemento a direita de aux, novo será inserido a direita dele*/
                if (aux->dir == NULL)
                {
                    aux->dir = novo;
                    achou = 1;
                }
                else
                {
                    /*caso já exista um elemento a direita de aux, aux  aponta para este elemento  e uma nova iteração será realizada*/
                    aux = aux->dir;
                }
            }
        }
    }
    printf("\nNumero inserido na arvore!");
    getch();
}

void consulta_no(Arvore *arv)
{
    /*caso a árvore esteja vazia*/
    if (arv->raiz == NULL)
    {
        printf("\nArvore Vazia!!");
    }
    else
    {
        int numero, achou;
        printf("Digite o numero a ser consultado: ");
        scanf("%d", &numero);
        achou = 0;
        /*aux aponta para o mesmo endereço de raiz*/
        aux = arv->raiz;
        /*enquanto aux não apontar para NULL e achou for igual a 0 será feita uma busca na árvore*/
        while (aux != NULL && achou == 0)
        {
            /*caso aux-> seja igual o número buscado*/
            if (aux->num == numero)
            {
                printf("Numero %d encontrado!", numero);
                achou = 1;
                /*do contrário verificamos se o número está a direita ou a esquerda de aux->num e atualizamos aux*/
            }
            else if (numero < aux->num)
            {
                aux = aux->esq;
            }
            else
            {
                aux = aux->dir;
            }
        }
        if (achou == 0)
            printf("Número não encontrado!");
    }

    getch();
}

/*consulta em ordem mostra os nós na seguinte ordem
    1° ramo da esquerda
    2° raiz
    3° ramo da direita	*/
void consulta_arvore_ordem(Arvore *arv, Pilha *pi)
{
    /*caso a árvore esteja vazia*/
    if (arv->raiz == NULL)
    {
        printf("\nArvore Vazia!!");
        /*caso a árvore contenha elementos*/
    }
    else
    {
        /*aux aponta para o endereço de raiz*/
        aux = arv->raiz;
        /*como aqui utilizaremos uma pilha, incializamos seu topo com null*/
        pi->topo = NULL;
        do
        {
            /*caminha pela árvore pelo ramo da esquerda até NULL, colocando cada elemento visitado na pilha */
            while (aux != NULL)
            {
                /*alocamos um espaço para inserir o elemento a ser mostrado na pilha*/
                Elemento *aux_pilha = (Elemento *)malloc(sizeof(Elemento));
                /*a pilha recebe o elemento apontado por auix*/
                aux_pilha->num = aux;
                /*para encadear os elementos da pilha, aux_pilha->prox aponta para o topo da pilha*/
                aux_pilha->prox = pi->topo;
                /*o topo da pilha apontará para o elemento que está sendo inserido na pilha*/
                pi->topo = aux_pilha;
                /*aux aponta para o elemento a esquerda do aux atual*/
                aux = aux->esq;
            }
            /*imprimiremos aos elementos empilhados no momento a partir do topo */
            if (pi->topo != NULL)
            {
                aux2 = pi->topo;
                printf("%d ", aux2->num->num);
                /*caso aja um elemento a direita do elemento apontado por topo na árvore, seu prox será NULL, portanto ao encontrar
                um elemento a direita do elemento impresso retornaremos ao while anterior antes de imprimir o restante da pilha*/
                aux = pi->topo->num->dir;
                pi->topo = pi->topo->prox;
            }
        } while (pi->topo != NULL || aux != NULL);
    }
    getch();
}

/*consulta em pré-ordem mostra os nós na seguinte ordem
    1° raiz
    2° ramo da esquerda
    3° ramo da direita	*/
void consulta_arvore_pre_ordem(Arvore *arv, Pilha *pi)
{
    /*caso a árvore esteja vazia*/
    if (arv->raiz == NULL)
    {
        printf("\nArvore Vazia!!");
        /*caso a árvore contenha elementos*/
    }
    else
    {
        /*aux aponta para o endereço de raiz*/
        aux = arv->raiz;
        /*como aqui utilizaremos uma pilha, incializamos seu topo com null*/
        pi->topo = NULL;
        do
        {
            /*caminha pela árvore mostrando cada elemento visitado, e também coloca cada elemento visitado na pilha */
            while (aux != NULL)
            {
                /*alocamos um espaço para inserir um elemento na pilha*/
                Elemento *aux_pilha = (Elemento *)malloc(sizeof(Elemento));
                /*impressão do elemento apontado por aux*/
                printf("%d ", aux->num);
                /*colocamos na pilha o elemento impresso*/
                aux_pilha->num = aux;
                aux_pilha->prox = pi->topo;
                pi->topo = aux_pilha;
                /*fazemos com que aux aponte para o elemento a sua esquerda*/
                aux = aux->esq;
            }
            if (pi->topo != NULL)
            {
                aux_pilha = pi->topo;
                pi->topo = pi->topo->prox;
                /*aux aponta para o elemento a direita de topo na árvore*/
                aux = aux_pilha->num->dir;
            }
        } while (pi->topo != NULL || aux != NULL);
    }
    getch();
}

/*consulta em pós-ordem mostra os nós na seguinte ordem
    1° ramo da esquerda
    2° ramo da dreita
    3° raiz */
void consulta_arvore_pos_ordem(Arvore *arv, Pilha *pi)
{
    /*caso a árvore esteja vazia*/
    if (arv->raiz == NULL)
    {
        printf("\nArvore Vazia!!");
        /*caso a árvore contenha elementos*/
    }
    else
    {
        /*aux aponta para o endereço de raiz*/
        aux = arv->raiz;
        /*como aqui utilizaremos uma pilha, incializamos seu topo com null*/
        pi->topo = NULL;
        do
        {
            do
            {
                /*caminha pela árvore pelo ramo da esquerda até NULL, colocando cada elemento visitado na pilha*/
                while (aux != NULL)
                {
                    /*alocamos um espaço para inserir um elemento na pilha*/
                    Elemento *aux_pilha = (Elemento *)malloc(sizeof(Elemento));
                    /*a pilha recebe o elemento apontado por aux*/
                    aux_pilha->num = aux;
                    /*para encadear os elementos da pilha, aux_pilha->prox aponta para o topo da pilha*/
                    aux_pilha->prox = pi->topo;
                    /*o topo da pilha apontará para o elemento que está sendo inserido na pilha*/
                    pi->topo = aux_pilha;
                    /*aux aponta para o elemento a esquerda do aux atual*/
                    aux = aux->esq;
                }
                /*caso o exista um elemento a direita do endereço apontado por topo na árvore, aux aponta para esse elemento*/
                if (pi->topo->num->dir != NULL)
                {
                    aux = pi->topo->num->dir;
                }
            } while (aux != NULL);
            if (pi->topo != NULL)
            {
                /*imprime o elemento apontado por topo*/
                printf("%d ", pi->topo->num->num);
                /*se ainda existirem elementos na pilha além de topo*/
                if (pi->topo->prox != NULL)
                {
                    /*caso exista um elemento a direta do prox da pilha na árvore e esse elemento seja diferente do topo,
                        aux apontara para esse elemento e topo apontará para o próximo elemento da pilha*/
                    if (pi->topo->prox->num->dir != NULL && pi->topo->prox->num->dir != pi->topo->num)
                    {
                        aux = pi->topo->prox->num->dir;
                        pi->topo = pi->topo->prox;
                        /*caso o exista um elemento a direita do endereço apontado por topo na árvore e esse elemento seja igual a topo,
                            topo apontará para o próximo elemento da pilha e este será  impresso*/
                    }
                    else
                    {
                        /*caso exista um elemento a direta do prox da pilha na árvore e esse elemento seja igual ao topo,
                        o topo apontará receberá prox e será impresso até que essa igualdade exista ou não existerem mais elementos
                        na pilha, isso será feito através do while*/
                        while (pi->topo->prox != NULL && pi->topo->prox->num->dir == pi->topo->num)
                        {
                            pi->topo = pi->topo->prox;
                            printf("%d ", pi->topo->num->num);
                        }
                        /*topo apontará para o próximo elemento da pilha*/
                        pi->topo = pi->topo->prox;
                        /*se topo não for null aux aponta para o elemento a direita do endereço apontado por topo na árvore*/
                        if (pi->topo != NULL)
                        {
                            aux = pi->topo->num->dir;
                            /*caso contrário aux recebe NULL*/
                        }
                        else
                        {
                            aux = NULL;
                        }
                    }
                    /*se topo igual a NULL*/
                }
                else
                {
                    pi->topo = pi->topo->prox;
                    aux = NULL;
                }
            }
        } while (pi->topo != NULL || aux != NULL);
    }
    getch();
}

/*consulta em pós-ordem mostra os nós na seguinte ordem
    1° ramo da esquerda
    2° ramo da dreita
    3° raiz */
void consulta_arvore_pos_ordem(Arvore *arv, Pilha *pi)
{
    /*caso a árvore esteja vazia*/
    if (arv->raiz == NULL)
    {
        printf("\nArvore Vazia!!");
        /*caso a árvore contenha elementos*/
    }
    else
    {
        /*aux aponta para o endereço de raiz*/
        aux = arv->raiz;
        /*como aqui utilizaremos uma pilha, incializamos seu topo com null*/
        pi->topo = NULL;
        do
        {
            do
            {
                /*caminha pela árvore pelo ramo da esquerda até NULL, colocando cada elemento visitado na pilha*/
                while (aux != NULL)
                {
                    /*alocamos um espaço para inserir um elemento na pilha*/
                    Elemento *aux_pilha = (Elemento *)malloc(sizeof(Elemento));
                    /*a pilha recebe o elemento apontado por aux*/
                    aux_pilha->num = aux;
                    /*para encadear os elementos da pilha, aux_pilha->prox aponta para o topo da pilha*/
                    aux_pilha->prox = pi->topo;
                    /*o topo da pilha apontará para o elemento que está sendo inserido na pilha*/
                    pi->topo = aux_pilha;
                    /*aux aponta para o elemento a esquerda do aux atual*/
                    aux = aux->esq;
                }
                /*caso o exista um elemento a direita do endereço apontado por topo na árvore, aux aponta para esse elemento*/
                if (pi->topo->num->dir != NULL)
                {
                    aux = pi->topo->num->dir;
                }
            } while (aux != NULL);
            if (pi->topo != NULL)
            {
                /*imprime o elemento apontado por topo*/
                printf("%d ", pi->topo->num->num);
                /*se ainda existirem elementos na pilha além de topo*/
                if (pi->topo->prox != NULL)
                {
                    /*caso exista um elemento a direta do prox da pilha na árvore e esse elemento seja diferente do topo,
                        aux apontara para esse elemento e topo apontará para o próximo elemento da pilha*/
                    if (pi->topo->prox->num->dir != NULL && pi->topo->prox->num->dir != pi->topo->num)
                    {
                        aux = pi->topo->prox->num->dir;
                        pi->topo = pi->topo->prox;
                        /*caso o exista um elemento a direita do endereço apontado por topo na árvore e esse elemento seja igual a topo,
                            topo apontará para o próximo elemento da pilha e este será  impresso*/
                    }
                    else
                    {
                        /*caso exista um elemento a direta do prox da pilha na árvore e esse elemento seja igual ao topo,
                        o topo apontará receberá prox e será impresso até que essa igualdade exista ou não existerem mais elementos
                        na pilha, isso será feito através do while*/
                        while (pi->topo->prox != NULL && pi->topo->prox->num->dir == pi->topo->num)
                        {
                            pi->topo = pi->topo->prox;
                            printf("%d ", pi->topo->num->num);
                        }
                        /*topo apontará para o próximo elemento da pilha*/
                        pi->topo = pi->topo->prox;
                        /*se topo não for null aux aponta para o elemento a direita do endereço apontado por topo na árvore*/
                        if (pi->topo != NULL)
                        {
                            aux = pi->topo->num->dir;
                            /*caso contrário aux recebe NULL*/
                        }
                        else
                        {
                            aux = NULL;
                        }
                    }
                    /*se topo igual a NULL*/
                }
                else
                {
                    pi->topo = pi->topo->prox;
                    aux = NULL;
                }
            }
        } while (pi->topo != NULL || aux != NULL);
    }
    getch();
}

void esvaziar_arvore(Arvore *arv, Pilha *pi)
{
    /*caso a árvore esteja vazia*/
    if (arv->raiz == NULL)
    {
        printf("\nArvore Vazia!!");
        /*caso a árvore contenha elementos*/
    }
    else
    {
        /*aux aponta para o endereço de raiz*/
        aux = arv->raiz;
        /*como aqui utilizaremos uma pilha, incializamos seu topo com null*/
        pi->topo = NULL;
        do
        {
            while (aux != NULL)
            {
                Elemento *aux_pilha = (Elemento *)malloc(sizeof(Elemento));
                /*impressão do elemento apontado por aux*/
                printf("%d ", aux->num);
                /*colocamos na pilha o elemento impresso*/
                aux_pilha->num = aux;
                aux_pilha->prox = pi->topo;
                pi->topo = aux_pilha;
                /*fazemos com que aux aponte para o elemento a sua esquerda*/
                aux = aux->esq;
            }
            if (pi->topo != NULL)
            {
                aux2 = pi->topo;
                pi->topo = pi->topo->prox;
                /*aux aponta para o elemento a direita de topo na árvore*/
                aux = aux2->num->dir;
            }
        } while (pi->topo != NULL || aux != NULL);
        aux2 = pi->topo;
        /*passagem por todos os elementos da pilha e removendo cada um deles*/
        while (aux2 != NULL)
        {
            pi->topo = pi->topo->prox;
            free(pi->topo->num);
            free(aux2);
            aux2 = pi->topo;
        }
        arv->raiz = NULL;
        printf("\nArvore esvaziada");
    }
    getch();
}