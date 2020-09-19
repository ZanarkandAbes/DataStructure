#include <stdio.h>
#include <stdlib.h>

typedef struct _no {
    int val;
    struct _no *prox;
} No;

typedef struct _pilha {
    No *topo;
    int length;
} Pilha;

No *CriaNo(int val);

Pilha *Pilha_Inicia();

void Pilha_Empilha(Pilha *P, int val);

int Pilha_Desempilha(Pilha *P);

int Pilha_EhVazia(Pilha *P);

void ImprimePilha(Pilha *P);

int main(){
    Pilha *P = Pilha_Inicia();
    int optionValue = 0;
    int value = 0;
    char escolha, escolhaTerminar;

    do{
        printf("Pilhas - IFSP Campinas \n");
        printf("1 - Verificar se a pilha esta vazia \n");
        printf("2 - Empilha (Insere no Topo) \n");
        printf("3 - Desempilha (Remover no Topo) \n");
        printf("4 - Imprimir a pilha \n");
        printf("5 - Quantidade de elementos da pilha \n");
        scanf("%i", &optionValue);

        switch(optionValue){
            case 1:
                if(Pilha_EhVazia(P) == 1){
                    printf("A pilha esta vazia ! \n");
                }else{
                    printf("A pilha contem elementos ! \n");
                }
                break;
            case 2:
                do{
                    printf("Digite um valor inteiro para inserir: \n");
                    scanf("%i", &value);
                    Pilha_Empilha(P, value);

                    printf("Deseja inserir outro valor? (s- sim | n- nao) \n");
                    setbuf(stdin, NULL);
                    scanf("%c", &escolha);

                }while(escolha != 'n');
                system("cls");
                break;
            case 3:
                do{
                    printf("Valor removido da pilha: %i \n", Pilha_Desempilha(P));

                    printf("Deseja remover outro valor? (s- sim | n- nao) \n");
                    setbuf(stdin, NULL);
                    scanf("%c", &escolha);

                }while(escolha != 'n');
                system("cls");
                break;
            case 4:
                ImprimePilha(P);
                break;
            case 5:
                printf("Quantidade de elementos da pilha: %i \n", P->length);
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

No *CriaNo(int val) {
    No *no   = (No*) calloc(1, sizeof(No));
    no->val  = val;
    no->prox = NULL;

    return no;
}

Pilha *Pilha_Inicia() {
    Pilha *P  = (Pilha *) calloc(1, sizeof(Pilha));
    P->topo = NULL;
    P->length = 0;

    return P;
}

void Pilha_Empilha(Pilha *P, int val){
    No *p = CriaNo(val);

    if(P->topo == NULL){
        P->topo = p;
    }else{
        p->prox = P->topo;
        P->topo = p;
    }
    P->length++;
}

int Pilha_Desempilha(Pilha *P){
    No *aux = P->topo;
    int valor = 0;

    if(P->topo == NULL){
        return -1;
    }else{
        P->topo = aux->prox;
        aux->prox = NULL;
        valor = aux->val;
        free(aux);
        P->length--;
        return valor;
    }
}

int Pilha_EhVazia(Pilha *P){

    if(P->topo == NULL){
        return 1;
    }else{
        return 0;
    }

}

void ImprimePilha(Pilha *P){
    No *aux = P->topo;

    printf("Pilha (TOPO) \n");

    while(aux != NULL){
        printf("%d \n", aux->val);
        aux = aux->prox;
    }

    printf("Pilha (FIM) \n");
}
