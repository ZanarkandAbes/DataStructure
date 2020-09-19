#include <stdio.h>
#include <stdlib.h>

typedef struct _no {
    int val;
    struct _no *prox;
} No;

typedef struct _fila {
    No *entrada;
    No *saida;
    int length;
} Fila;

No *CriaNo(int val);

Fila *CriaFila();

int VerificarFilaVazia(Fila *F);

int Desinfilera(Fila *F);

void Enfilera(Fila *F, int val);

void ImprimeFila(Fila *F);

int main(){
    Fila *F = CriaFila();
    int optionValue = 0;
    int value = 0;
    char escolha, escolhaTerminar;

    do{
        printf("Filas - IFSP Campinas \n");
        printf("1 - Verificar se a fila esta vazia \n");
        printf("2 - Enfilera (Insere no Fim) \n");
        printf("3 - Desinfilera (Remover no Inicio) \n");
        printf("4 - Imprimir a fila \n");
        printf("5 - Quantidade de elementos da fila \n");
        scanf("%i", &optionValue);

        switch(optionValue){
            case 1:
                if(VerificarFilaVazia(F) == 1){
                    printf("A fila esta vazia ! \n");
                }else{
                    printf("A fila contem elementos ! \n");
                }
                break;
            case 2:
                do{
                    printf("Digite um valor inteiro para inserir: \n");
                    scanf("%i", &value);
                    Enfilera(F, value);

                    printf("Deseja inserir outro valor? (s- sim | n- nao) \n");
                    setbuf(stdin, NULL);
                    scanf("%c", &escolha);

                }while(escolha != 'n');
                system("cls");
                break;
            case 3:
                do{
                    printf("Valor removido da fila: %i \n", Desinfilera(F));

                    printf("Deseja remover outro valor? (s- sim | n- nao) \n");
                    setbuf(stdin, NULL);
                    scanf("%c", &escolha);

                }while(escolha != 'n');
                system("cls");
                break;
            case 4:
                ImprimeFila(F);
                break;
            case 5:
                printf("Quantidade de elementos da fila: %i \n", F->length);
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

Fila *CriaFila() {
    Fila *F  = (Fila *) calloc(1, sizeof(Fila));
    F->entrada = F->saida = NULL;
    F->length = 0;

    return F;
}

int VerificarFilaVazia(Fila *F){

    if(F->saida == NULL){
        return 1;
    }else{
        return 0;
    }
}

int Desinfilera(Fila *F){
    No *n;
    int valor;

    if (F->saida == NULL){
        return -1;
    }

    n = F->saida;
    F->saida = n->prox;

    valor = n->val;
    F->length--;
    free(n);

    if(F->saida == NULL){
        F->entrada = NULL;
    }

    return valor;
}

void Enfilera(Fila *F, int val){
    No *p = CriaNo(val);

    if(F->saida == NULL){
        F->saida = p;
        F->entrada = p;
    }else{
        F->entrada->prox = p;
        F->entrada = F->entrada->prox;
        F->entrada->prox = NULL;
    }
    F->length++;
}

void ImprimeFila(Fila *F) {
    printf("Fila -> ");

    No *p = F->saida;

    while (p != NULL) {
        printf("%d -> ", p->val);
        p = p->prox;
    }
    printf("NULL\n");
}


