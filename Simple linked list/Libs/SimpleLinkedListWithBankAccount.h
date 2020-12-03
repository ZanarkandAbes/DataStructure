/* Biblioteca da estrutura de dados: Lista Encadeada Simples (com o tipo 'ContaBancaria') */

#ifndef SIMPLELINKEDLIST_H
#define SIMPLELINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int numero;
    float saldo;

} ContaBancaria;

typedef struct _no {
    ContaBancaria *val;
    struct _no *prox;
} No;

typedef struct _lista {
    No *inicio;
    No *fim;
    int totalElements;
} Lista;

No *CriaNo(ContaBancaria *val);

Lista *CriaLista();

void InsereNoInicio(Lista *L, ContaBancaria *val);

void ImprimeLista(Lista *L);

void InsereNoFim(Lista *L, ContaBancaria *val);

ContaBancaria *RemoverNoInicio(Lista *L);

ContaBancaria *RemoverNoFinal(Lista *L);

ContaBancaria *BuscaERemove(Lista *L, ContaBancaria *val);

ContaBancaria *BuscaERemoveRepetidos(Lista *L, ContaBancaria *val);

int ContarNumeroDeElementos(Lista *L);

int VerificarListaVazia(Lista *L);

void ConcatenarLista(Lista *L, Lista *L2);

Lista *CopiarLista(Lista *L);

Lista *OrdernarLista(Lista *L, char escolha);

Lista *InverterLista(Lista *L);

No *BuscaPonteiro(Lista *L, int val);

void InsercaoOrdenada(Lista *L, ContaBancaria *val);

Lista *CriaLista() {
    Lista *L  = (Lista *) calloc(1, sizeof(Lista));
    L->inicio = L->fim = NULL;
    L->totalElements = 0;

    return L;
}

No *CriaNo(ContaBancaria *val) {
    No *no   = (No*) calloc(1, sizeof(No));
    no->val  = val;
    no->prox = NULL;

    return no;
}

void InsereNoInicio(Lista *L, ContaBancaria *val) {
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

    No *p = L->inicio;
    printf("[\n");

    while (p != NULL) {
        printf("\t{");
        printf("\n \t numero: %d", p->val->numero);
        printf(",\n");
        printf("\t saldo: %.2f", p->val->saldo);
        printf("\n");
        p = p->prox;
        printf("\t},");
        printf("\n");
    }
    printf("]\n");
}

void InsereNoFim(Lista *L, ContaBancaria *val){
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

ContaBancaria *RemoverNoInicio(Lista *L){
    No *n;
    ContaBancaria *valor;

    if (L->inicio == NULL){
        return L->inicio->val;
    }

    n = L->inicio;
    L->inicio = n->prox;

    valor = n->val;
    L->totalElements--;
    free(n);
    return valor;
}

ContaBancaria *RemoverNoFinal(Lista *L){
    No *n, *aux;
    ContaBancaria *valor;

    No *p = L->inicio;

    if(L->inicio == NULL){
        return L->inicio->val;
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

ContaBancaria *BuscaERemove(Lista *L, ContaBancaria *val){

    No *ant = L->inicio;
    No *pos = L->inicio->prox;

    if(L->inicio == NULL){
        return NULL;
    }
    if(BuscaPonteiro(L,val->numero) != NULL){
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
            return L->fim->val;
        }

        ant->prox = pos->prox;
        pos = ant->prox;
        L->totalElements--;
        return pos->val;
    }

    return NULL;
}

ContaBancaria *BuscaERemoveRepetidos(Lista *L, ContaBancaria *val){
    No *aux = L->inicio;
    No *p = L->inicio;

    if(BuscaPonteiro(L,val->numero) == NULL){
        return NULL;
    }

    if(L->inicio == NULL){
        return L->inicio->val;
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

    return NULL;
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
    ContaBancaria *valoraux;

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
            if(p->val->numero == val){
                return p;
            }
            p = p->prox;
        }
        printf("Conta bancaria nao encontrada! \n");
        return NULL;
    }
}

void InsercaoOrdenada(Lista *L, ContaBancaria *val){
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
