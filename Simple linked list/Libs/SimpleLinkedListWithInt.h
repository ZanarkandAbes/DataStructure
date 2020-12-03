/* Biblioteca da estrutura de dados: Lista Encadeada Simples (com o tipo 'int') */

#ifndef SIMPLELINKEDLIST_H
#define SIMPLELINKEDLIST_H

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

#endif
