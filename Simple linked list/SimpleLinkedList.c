#include <stdio.h>
#include <stdlib.h>

typedef struct _no {
    int val;
    struct _no *prox;
} No;

typedef struct _lista {
    No *inicio;
    No *fim;
    int totalElements;
} Lista;

No *CriaNo(int val);

Lista *CriaLista();

void InsereNoInicio(Lista *L, int val);

void ImprimeLista(Lista *L);

void InsereNoFim(Lista *L, int val);

int RemoverNoInicio(Lista *L);

int RemoverNoFinal(Lista *L);

int BuscaERemove(Lista *L, int val);

int BuscaERemoveRepetidos(Lista *L, int val);

int ContarNumeroDeElementos(Lista *L);

int VerificarListaVazia(Lista *L);

void ConcatenarLista(Lista *L, Lista *L2);

Lista *CopiarLista(Lista *L);

Lista *OrdernarLista(Lista *L, char escolha);

Lista *InverterLista(Lista *L);

No *BuscaPonteiro(Lista *L, int val);

void InsercaoOrdenada(Lista *L, int val);

int main(){
    Lista *L = CriaLista();
    int optionValue = 0;
    int optionValueSecond = 0;
    int value = 0;
    char escolha, escolhaTerminar, escolhaOrdem;

    do{
        printf("1 - Inserir elemento na cabeça (inicio) da lista: \n");
        printf("2 - Impressao dos elementos da lista: \n");
        printf("3 - Inserir elemento na cauda (fim) da lista: \n");
        printf("4 - Remover elemento(s): \n");
        printf("5 - Contar numero de elementos: \n");
        printf("6 - Verificar se a lista esta vazia: \n");
        printf("7 - Concatenar de duas listas: \n");
        printf("8 - Copiar uma lista em outra: \n");
        printf("9 - Ordenar uma lista: \n");
        printf("10 - Buscar elemento e retornar o ponteiro: \n");
        printf("11 - Insercao ordenada na lista: \n");
        scanf("%i", &optionValue);

        switch(optionValue){
            case 1:
                do{
                    printf("Digite um valor inteiro para inserir: \n");
                    scanf("%i", &value);
                    InsereNoInicio(L, value);

                    printf("Deseja inserir outro valor? (s- sim | n- nao) \n");
                    setbuf(stdin, NULL);
                    scanf("%c", &escolha);

                }while(escolha != 'n');
                system("cls");
                break;
            case 2:
                ImprimeLista(L);
                break;
            case 3:
                do{
                    printf("Digite um valor inteiro para inserir: \n");
                    scanf("%i", &value);
                    InsereNoFim(L, value);

                    printf("Deseja inserir outro valor? (s- sim | n- nao) \n");
                    setbuf(stdin, NULL);
                    scanf("%c", &escolha);

                }while(escolha != 'n');
                system("cls");
                break;
            case 4:
                system("cls");
                printf("1 - Remover elemento no inicio: \n");
                printf("2 - Remover elemento no fim: \n");
                printf("3 - Buscar e remover elemento (uma ocorrencia): \n");
                printf("4 - Buscar e remover elemento (n ocorrencias): \n");
                scanf("%i", &optionValueSecond);
                int removedElement = 0;
                int booleanValue = 0;
                switch(optionValueSecond){
                    case 1:
                        removedElement = RemoverNoInicio(L);
                        if(removedElement != -1){
                            printf("Elemento removido: %i", removedElement);
                            printf("\n");
                        }else{
                            printf("Elemento nao encontrado! \n");
                        }
                        break;
                    case 2:
                        removedElement = RemoverNoFinal(L);
                        if(removedElement != -1){
                            printf("Elemento removido: %i", removedElement);
                            printf("\n");
                        }else{
                            printf("Elemento nao encontrado! \n");
                        }
                        break;
                    case 3:
                        do{
                            printf("Digite o valor que deseja remover: \n");
                            scanf("%i", &value);
                            booleanValue = BuscaERemove(L, value);

                            if(booleanValue != -1){
                                printf("Elemento %i removido! \n", value);
                            }

                            printf("Deseja remover a ocorrencia de mais um valor? (s- sim | n -nao) \n");
                            setbuf(stdin, NULL);
                            scanf("%c", &escolha);
                        }while(escolha != 'n');
                        break;
                    case 4:
                        do{
                            printf("Digite o valor que deseja remover (todas as ocorrencias): \n");
                            scanf("%i", &value);
                            booleanValue = BuscaERemoveRepetidos(L, value);

                            if(booleanValue != -1){
                                printf("Ocorrencias do elemento %i removidas! \n", value);
                            }else{

                            }

                            printf("Deseja remover as ocorrencias de mais valores? (s- sim | n -nao) \n");
                            setbuf(stdin, NULL);
                            scanf("%c", &escolha);
                        }while(escolha != 'n');
                        break;
                    default:
                        printf("Opcao de remover invalida ! \n");
                        break;
                }
                break;
            case 5:
                printf("Numero de elementos da lista: %i", L->totalElements);
                printf("\n");
                break;
            case 6:
                if(VerificarListaVazia(L) == 1){
                    printf("A lista esta vazia ! \n");
                }else{
                    printf("A lista contem elementos ! \n");
                }
                break;
            case 7:
                printf("Declarando a segunda lista: \n");
                Lista *L2 = CriaLista();
                do{
                    printf("Digite um valor inteiro para inserir na segunda lista: \n");
                    scanf("%i", &value);
                    InsereNoInicio(L2, value);

                    printf("Deseja inserir outro valor? (s- sim | n- nao) \n");
                    setbuf(stdin, NULL);
                    scanf("%c", &escolha);

                }while(escolha != 'n');
                system("cls");
                ConcatenarLista(L,L2);
                break;
            case 8:
                printf("Copiando a lista L: \n");
                Lista *L3 = CopiarLista(L);
                printf("Lista L3 (Copia da lista L) \n");
                ImprimeLista(L3);
                printf("Lista L \n");
                ImprimeLista(L);
                break;
            case 9:
                do{
                    printf("Escolha a ordenacao (c- crescente | d- decrescente) \n");
                    setbuf(stdin, NULL);
                    scanf("%c", &escolhaOrdem);
                }while((escolhaOrdem != 'c') && (escolhaOrdem != 'd'));
                system("cls");
                OrdernarLista(L,escolhaOrdem);
                break;
            case 10:
                printf("Digite um elemento a ser buscado: \n");
                scanf("%i", &value);
                printf("Buscando o ponteiro do elemento %i da lista: \n", value);
                No *ponteiro = BuscaPonteiro(L, value);

                if(ponteiro != NULL){
                    printf("Valor do ponteiro: %i \n", ponteiro->val);
                    printf("Endereco do ponteiro: %p \n", ponteiro);
                }
                break;
            case 11:
                do{
                    printf("Digite um valor inteiro para inserir ordenadamente: \n");
                    scanf("%i", &value);
                    InsercaoOrdenada(L, value);

                    printf("Deseja inserir outro valor? (s- sim | n- nao) \n");
                    setbuf(stdin, NULL);
                    scanf("%c", &escolha);

                }while(escolha != 'n');
                system("cls");
                break;
            default:
                printf("Opcao invalida ! \n");
                break;
        }
        printf("Deseja encerrar a aplicacao? (s- sim | n- nao) \n");
        setbuf(stdin, NULL);
        scanf("%c", &escolhaTerminar);
        system("cls");
    }while(escolhaTerminar != 's');

    return 0;
}

Lista *CriaLista() {
    Lista *L  = (Lista *) calloc(1, sizeof(Lista));
    L->inicio = L->fim = NULL;
    L->totalElements = 0;

    return L;
}

No *CriaNo(int val) {
    No *no   = (No*) calloc(1, sizeof(No));
    no->val  = val;
    no->prox = NULL;

    return no;
}

void InsereNoInicio(Lista *L, int val) {
    No *p = CriaNo(val);

    if(L->inicio == NULL){
        L->inicio = p;
        L->fim = p;
    }else{
        p->prox   = L->inicio;
        L->inicio = p;
    }
    L->totalElements++;
}

void ImprimeLista(Lista *L) {
    printf("Lista -> ");

    No *p = L->inicio;

    while (p != NULL) {
        printf("%d -> ", p->val);
        p = p->prox;
    }
    printf("NULL\n");
}

void InsereNoFim(Lista *L, int val){
    No *p = CriaNo(val);
    No *q;

    if(L->inicio == NULL){
        L->inicio = p;
        L->fim = p;
    }else{
        L->fim->prox = p;
        L->fim = L->fim->prox;
        L->fim->prox = NULL;
    }
    L->totalElements++;
}

int RemoverNoInicio(Lista *L){
    No *n;
    int valor;

    if (L->inicio == NULL){
        return -1;
    }

    n = L->inicio;
    L->inicio = n->prox;

    valor = n->val;
    L->totalElements--;
    free(n);
    return valor;
}

int RemoverNoFinal(Lista *L){
    No *n, *aux;
    int valor;

    No *p = L->inicio;

    if(L->inicio == NULL){
        return -1;
    }

    if(p->prox == NULL){
        n = p->prox;
        p->prox = NULL;
    }else{
        aux = p;
        while(aux->prox->prox != NULL){
            aux = aux->prox;
        }
        n = aux->prox;
        aux->prox = NULL;
    }
    valor = n->val;
    L->totalElements--;
    L->fim = aux;
    free(n);
    return valor;

}

int BuscaERemove(Lista *L, int val){

    No *ant = L->inicio;
    No *pos = L->inicio->prox;

    if(L->inicio == NULL){
        return -1;
    }
    if(BuscaPonteiro(L,val) != NULL){
        while((pos->val != val) && (pos->prox != NULL)){
            ant = pos;
            pos = pos->prox;
        }

        if((L->fim == pos) && (L->fim->val == val)){
            ant->prox = pos->prox;
            free(pos);
            pos = ant->prox;
            L->fim = ant;
            L->totalElements--;
            return 1;
        }

        ant->prox = pos->prox;
        pos = ant->prox;
        L->totalElements--;
        return 1;
    }

    return -1;
}

int BuscaERemoveRepetidos(Lista *L, int val){
    No *aux = L->inicio;
    No *p = L->inicio;

    if(BuscaPonteiro(L,val) == NULL){
        return -1;
    }

    if(L->inicio == NULL){
        return -1;
    }

    while(p != NULL){
        if(p != L->inicio){
            if(val == p->val){
                if((L->fim == aux->prox) && (L->fim->val == val)){
                    L->fim = aux;
                    aux->prox = NULL;
                }else{
                    aux->prox = p->prox;
                }
                L->totalElements--;
            }else{
                aux = p;
            }
            p = p->prox;
        }else{
            if(val == p->val){
                L->inicio = L->inicio->prox;
                aux = p;
                p = p->prox;
                L->totalElements--;
            }else{
                aux = p;
                p = p->prox;
            }
        }
    }

    return 1;
}

int ContarNumeroDeElementos(Lista *L){
    No *p = L->inicio;

    int quantidadeDeValores = 0;

    if(L->inicio == NULL){
        return -1;
    }

    while(p != NULL){
        quantidadeDeValores++;
        p = p->prox;
    }

    return quantidadeDeValores;
}

int VerificarListaVazia(Lista *L){

    if(L->inicio == NULL){
        return 1;
    }else{
        return 0;
    }
}

void ConcatenarLista(Lista *L, Lista *L2){
    if((L->inicio != NULL) && (L2->inicio != NULL)){
        No *p = L->inicio;
        while(p->prox != NULL){
            p = p->prox;
        }
        p->prox = L2->inicio;
        L->fim = L2->fim;
        L->totalElements += L2->totalElements;
        free(L2);
    }
}

Lista *CopiarLista(Lista *L){
    Lista *Lcopia = CriaLista();
    No *aux = L->inicio;
    while (aux != NULL){
        InsereNoFim(Lcopia, aux->val);
        aux = aux->prox;
    }
    return Lcopia;
}

Lista *OrdernarLista(Lista *L, char escolha){
    No *aux = L->inicio;
    No *p;
    int valoraux = 0;

    if(L->inicio == NULL){
        return NULL;
    }
    if(escolha == 'c'){
        while(aux != NULL){
            p = aux->prox;
            while(p != NULL){
                if(aux->val > p->val){
                    valoraux = aux->val;
                    aux->val = p->val;
                    p->val = valoraux;
                }
                p = p->prox;
            }
            aux = aux->prox;
        }
        free(aux);
        free(p);
        return L;
    }else if(escolha == 'd'){
        while(aux != NULL){
            p = aux->prox;
            while(p != NULL){
                if(aux->val < p->val){
                    valoraux = p->val;
                    p->val = aux->val;
                    aux->val = valoraux;
                }
                p = p->prox;
            }
            aux = aux->prox;
        }
        free(aux);
        free(p);
        return L;
    }
}

Lista *InverterLista(Lista *L){
    Lista *Lcopia = CriaLista();
    No *aux = L->inicio;
    while (aux != NULL){
        InsereNoInicio(Lcopia, aux->val);
        aux = aux->prox;
    }
    return Lcopia;
}

No *BuscaPonteiro(Lista *L, int val){
    No *p = L->inicio;

    if(L->inicio == NULL){
        printf("A lista esta vazia! \n");
        return NULL;
    }else{
        while(p != NULL){
            if(p->val == val){
                return p;
            }
            p = p->prox;
        }
        printf("Elemento nao encontrado! \n");
        return NULL;
    }
}

void InsercaoOrdenada(Lista *L, int val){
    No *novoElemento = CriaNo(val);
    No *pAtual, *pAnterior;

    if(L->inicio == NULL){
        L->inicio = novoElemento;
        L->fim = novoElemento;
        L->totalElements++;
        return NULL;
    }

    pAtual = L->inicio;
    pAnterior = NULL;

    while(pAtual != NULL){
        if(novoElemento->val < pAtual->val){
            break;
        }
        pAnterior = pAtual;
        pAtual = pAtual->prox;
    }

    novoElemento->prox = pAtual;

    if(pAnterior == NULL){
        L->inicio = novoElemento;
        L->totalElements++;
    }else{
        pAnterior->prox = novoElemento;
        L->totalElements++;
    }

    if((pAtual == NULL) && (pAnterior != NULL)){
        L->fim = pAnterior->prox;
    }
}

