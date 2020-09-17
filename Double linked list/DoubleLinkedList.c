#include <stdio.h>
#include <stdlib.h>

typedef struct _no_dup {
    int val;
    struct _no_dup *ant;
    struct _no_dup *prox;
}NoDup;

typedef struct _dup_lista {
    NoDup *inicio;
    NoDup *fim;
    int length;
}DupLista;

NoDup *CriaNo(int val);

DupLista *CriaLista();

void InsereNoInicio(DupLista *L, int val);

void ImprimeLista(DupLista *L);

void ImprimeListaInvertido(DupLista *L);

void InsereNoFim(DupLista *L, int val);

int RemoverNoInicio(DupLista *L);

int RemoverNoFinal(DupLista *L);

int BuscaERemove(DupLista *L, int val);

int BuscaERemoveRepetidos(DupLista *L, int val);

int ContarNumeroDeElementos(DupLista *L);

int VerificarListaVazia(DupLista *L);

void ConcatenarLista(DupLista *L, DupLista *L2);

NoDup *BuscaPonteiro(DupLista *L, int val);

DupLista *CopiarLista(DupLista *L);

DupLista *OrdernarLista(DupLista *L, char escolha);

DupLista *InverterLista(DupLista *L);

void InsercaoOrdenada(DupLista *L, int val);

int main(){

    DupLista *L = CriaLista();
    int optionValue = 0;
    int optionValueSecond = 0;
    int value = 0;
    char escolha, escolhaTerminar, escolhaOrdem;

    do{
        printf("Lista Duplamente Encadeada - IFSP Campinas \n");
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
                ImprimeListaInvertido(L);
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
                printf("Numero de elementos da lista: %i", L->length);
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
                DupLista *L2 = CriaLista();
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
                printf("Lista L concatenada com L2: \n");
                ImprimeLista(L);
                ImprimeListaInvertido(L);
                break;
            case 8:
                printf("Copiando a lista L: \n");
                DupLista *L3 = CopiarLista(L);
                printf("Lista L3 (Copia da lista L) \n");
                ImprimeLista(L3);
                ImprimeListaInvertido(L3);
                printf("Lista L \n");
                ImprimeLista(L);
                ImprimeListaInvertido(L3);
                break;
            case 9:
                do{
                    printf("Escolha a ordenacao (c- crescente | d- decrescente) \n");
                    setbuf(stdin, NULL);
                    scanf("%c", &escolhaOrdem);
                }while((escolhaOrdem != 'c') && (escolhaOrdem != 'd'));
                system("cls");
                L = OrdernarLista(L,escolhaOrdem);
                break;
            case 10:
                printf("Digite um elemento a ser buscado: \n");
                scanf("%i", &value);
                printf("Buscando o ponteiro do elemento %i da lista: \n", value);
                NoDup *ponteiro = BuscaPonteiro(L, value);

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

DupLista *CriaLista() {
    DupLista *L  = (DupLista *) calloc(1, sizeof(DupLista));
    L->inicio = L->fim = NULL;
    L->length = 0;

    return L;
}

NoDup *CriaNo(int val) {
    NoDup *no   = (NoDup*) calloc(1, sizeof(NoDup));
    no->val  = val;
    no->ant = NULL;
    no->prox = NULL;

    return no;
}

void InsereNoInicio(DupLista *L, int val) {
    NoDup *p = CriaNo(val);

    if(L->inicio == NULL){
        L->inicio = p;
        L->fim = p;
        L->inicio->ant = NULL;
    }else{
        p->prox   = L->inicio;
        L->inicio->ant = p;
        L->inicio = p;
    }
    L->length++;
}

void ImprimeLista(DupLista *L) {
    printf("Lista -> ");

    NoDup *p = L->inicio;

    while (p != NULL) {
        printf("%d -> ", p->val);
        p = p->prox;
    }
    printf("NULL\n");
}

void ImprimeListaInvertido(DupLista *L){
    printf("Lista invertida -> ");

    NoDup *p = L->fim;

    while (p != NULL){
        printf("%d -> ", p->val);
        p = p->ant;
    }
    printf("NULL \n");
}

void InsereNoFim(DupLista *L, int val){
    NoDup *p = CriaNo(val);

    if(L->inicio == NULL){
        L->inicio = p;
        L->fim = p;
        L->inicio->ant = NULL;
    }else{
        L->fim->prox = p;
        p->ant = L->fim;
        L->fim = p;
        L->fim->prox = NULL;
    }
    L->length++;
}

int RemoverNoInicio(DupLista *L){
    NoDup *n;
    int valor;

    if (L->inicio == NULL){
        return -1;
    }

    if (L->inicio->prox == NULL){
        L->inicio = NULL;
        L->fim = NULL;
        L->length--;
        return 1;
    }

    n = L->inicio;
    L->inicio = n->prox;
    L->inicio->ant = NULL;

    valor = n->val;
    L->length--;
    free(n);
    return valor;
}

int RemoverNoFinal(DupLista *L){

    int valor;

    if(L->inicio == NULL){
        return -1;
    }

    if(L->inicio->prox == NULL){
        valor = L->inicio->val;
        L->inicio = NULL;
        L->fim = NULL;
    }else{
        valor = L->fim->val;
        L->fim = L->fim->ant;
        L->fim->prox = NULL;
    }
    L->length--;
    return valor;
}

int BuscaERemove(DupLista *L, int val){

    NoDup *p = L->inicio;

    if(L->inicio == NULL){
        return -1;
    }
    if(BuscaPonteiro(L,val) != NULL){
        while((p->val != val) && (p->prox != NULL)){
            p = p->prox;
        }

        if(p == L->inicio){
            RemoverNoInicio(L);
            free(p);
            return 1;
        }

        if((L->fim == p) && (L->fim->val == val)){
            L->fim = p->ant;
            p->ant->prox = NULL;
            L->length--;
            free(p);
            return 1;
        }

        p->ant->prox = p->prox;
        p->prox->ant = p->ant;
        L->length--;
        return 1;
    }

    return -1;
}

int BuscaERemoveRepetidos(DupLista *L, int val){
    NoDup *aux = L->inicio;
    NoDup *p = L->inicio;

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
                    //printf("Aqui ! \n");
                    aux->prox = p->prox;
                    p->prox->ant = aux;
                }
                L->length--;
            }else{
                aux = p;
            }
            p = p->prox;
        }else{
            if(val == p->val){
                //printf("Aqui ! \n");
                L->inicio = L->inicio->prox;
                //printf("Aqui2 ! \n");
                if(L->inicio != NULL){
                    L->inicio->ant = NULL;
                }else{
                    L->inicio = NULL;
                    L->fim = NULL;
                }
                //printf("Aqui3 ! \n");
                aux = p;
                //printf("Aqui4 ! \n");
                p = p->prox;
                //printf("Aqui5 ! \n");
                L->length--;
                //printf("Aqui6 ! \n");
            }else{
                aux = p;
                p = p->prox;
            }
        }
    }

    return 1;
}

NoDup *BuscaPonteiro(DupLista *L, int val){
    NoDup *p = L->inicio;

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

int VerificarListaVazia(DupLista *L){

    if(L->inicio == NULL){
        return 1;
    }else{
        return 0;
    }
}

void ConcatenarLista(DupLista *L, DupLista *L2){
    if((L->inicio != NULL) && (L2->inicio != NULL)){
        L->fim->prox = L2->inicio;
        L2->inicio->ant = L->fim;
        L->fim = L2->fim;
        L->fim->prox = NULL;

        L->length += L2->length;

        free(L2);
    }
    return NULL;
}

DupLista *CopiarLista(DupLista *L){
    DupLista *Lcopia = CriaLista();
    NoDup *aux = L->inicio;
    while (aux != NULL){
        InsereNoFim(Lcopia, aux->val);
        aux = aux->prox;
    }
    return Lcopia;
}

DupLista *OrdernarLista(DupLista *L, char escolha){
    NoDup *aux = L->inicio;
    NoDup *p;
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

void InsercaoOrdenada(DupLista *L, int val){
    NoDup *novoElemento = CriaNo(val);
    NoDup *p, *pAux;

    if(L->inicio == NULL){
        L->inicio = novoElemento;
        L->fim = novoElemento;
        L->length++;
        return NULL;
    }

    p = L->inicio;
    pAux = NULL;

    while(p != NULL){
        if(novoElemento->val < p->val){
            break;
        }
        pAux = p;
        p = p->prox;
    }

    novoElemento->prox = p;

    if(pAux == NULL){
        //printf("Inicio - novoElemento->val : %i \n", novoElemento->val);
        p->ant = novoElemento;
        L->inicio = p->ant;
        L->inicio->ant = NULL;
    }else if(p == NULL){
        //printf("Fim - novoElemento->val : %i \n", novoElemento->val);
        L->fim->prox = novoElemento;
        novoElemento->ant = L->fim;
        L->fim = novoElemento;
    }else{
        //printf("Meio - novoElemento->val : %i \n", novoElemento->val);
        p->ant->prox = novoElemento;
        novoElemento->ant = p->ant;
        p->ant = novoElemento;
    }
    L->length++;
}
