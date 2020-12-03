#include <stdio.h>
#include <stdlib.h>

typedef struct noArvore {
    int conteudo;
    struct noArvore *esq;
    struct noArvore *dir;
} noArv;

void CriaArvore(noArv **arvore);
noArv *CriaNoArvore(int conteudo);
int InserirNaArvore(noArv **arvore, int conteudo);
void ImprimeArvorePreOrdem(noArv *arvore);
void ImprimeArvoreInOrdem(noArv *arvore);
void ImprimeArvorePosOrdem(noArv *arvore);
int BuscarElementoNaArvore(noArv *arvore, int conteudo);
int RemoverElementoNaArvore(noArv **arvore, int conteudo);
noArv *RemoveNoArvoreAtual(noArv *arvoreAtual);
int AlturaArvore(noArv *arvore);

int main(){

    int optionValue = 0, secondOptionValue = 0;
    int conteudo = 0, retornoInsercao = 0;
    char escolha, escolhaTerminar, escolhaTerminarDeBuscar, escolhaTerminarDeBuscarERemover;

    noArv **arvore;
    CriaArvore(arvore);

    do{
        printf("Exercicios Slides 7 e 16 (Estrutura de Dados II) - IFSP Campinas \n");
        printf("1 - Inserir sequencia de inteiros positivos com terminador 0 \n");
        printf("2 - Imprimir \n");
        printf("3 - Buscar um elemento na arvore: \n");
        printf("4 - Remover um elemento na arvore: \n");
        printf("5 - Altura da arvore: \n");
        scanf("%i", &optionValue);

        switch(optionValue){
            case 1:
                do{
                    do{
                        printf("Digite um numero maior que zero para inserir na arvore: [para finalizar a insercao digite 0]\n");
                        scanf("%i", &conteudo);
                    }while(conteudo < 0);
                    if(conteudo > 0){
                        retornoInsercao = InserirNaArvore(arvore, conteudo);
                    }
                    if(retornoInsercao == 1){
                        printf("Valor %i inserido com sucesso na arvore binaria ! \n", conteudo);
                    }else{
                        printf("Nao foi possivel inserir o valor na arvore binaria ! \n");
                    }
                    retornoInsercao = 0;
                }while(conteudo != 0);

                break;
            case 2:
                printf("1 - Pre-ordem: \n");
                printf("2 - In-ordem: \n");
                printf("3 - Pos-ordem: \n");
                scanf("%i", &secondOptionValue);
                switch(secondOptionValue){
                    // Amostra de árvore: 5,3,2,4,8,7,9
                    case 1:
                        // PreOrdem: 5, 3, 2, 4, 8, 7, 9
                        ImprimeArvorePreOrdem(*arvore);
                        break;
                    case 2:
                        // InOrdem: 2, 3, 4, 5, 7, 8, 9
                        ImprimeArvoreInOrdem(*arvore);
                        break;
                    case 3:
                        // PosOrdem: 2, 4, 3, 7, 9, 8, 5
                        ImprimeArvorePosOrdem(*arvore);
                        break;
                    default:
                        printf("Opcao invalida ! \n");
                        break;
                }
                break;
            case 3:
                do{
                    printf("Digite um numero para buscar na arvore binaria: \n");
                    scanf("%i", &conteudo);
                    if(BuscarElementoNaArvore(*arvore, conteudo) == 1){
                        printf("O conteudo %i foi encontrado na arvore ! \n", conteudo);
                    }else{
                        printf("O conteudo %i nao foi encontrado na arvore ! \n", conteudo);
                    }
                    printf("Deseja procurar outro valor? [s- sim | n- nao] \n");
                    setbuf(stdin, NULL);
                    scanf("%c", &escolhaTerminarDeBuscar);
                    system("cls");
                }while(escolhaTerminarDeBuscar != 'n');
                break;
            case 4:
                do{
                    printf("Digite um numero para remover na arvore binaria: \n");
                    scanf("%i", &conteudo);
                    if(RemoverElementoNaArvore(arvore, conteudo) == 1){
                        printf("O conteudo %i foi removido com sucesso da arvore ! \n", conteudo);
                    }else{
                        printf("O conteudo %i nao foi removido da arvore ! \n", conteudo);
                    }
                    printf("Deseja remover outro valor? [s- sim | n- nao] \n");
                    setbuf(stdin, NULL);
                    scanf("%c", &escolhaTerminarDeBuscarERemover);
                    system("cls");
                }while(escolhaTerminarDeBuscarERemover != 'n');
                break;
            case 5:
                printf("Calculando a altura da arvore binaria: \n");
                int altura = 0;
                altura = AlturaArvore(*arvore);
                printf("A altura (ou maior nivel) da arvore e: %i \n", altura);
                break;
            default:
                printf("Opcao invalida ! \n");
                break;
        }
        printf("\n");
        printf("Deseja encerrar a aplicacao? (s- sim | n- nao) \n");
        setbuf(stdin, NULL);
        scanf("%c", &escolhaTerminar);
        system("cls");
    }while(escolhaTerminar != 's');

    return 0;

}

void CriaArvore(noArv **arvore){
    *arvore = NULL;
}

noArv *CriaNoArvore(int conteudo){
    noArv *arvore = (noArv*) calloc(1, sizeof(noArv));
    arvore->conteudo = conteudo;
    arvore->dir = NULL;
    arvore->esq = NULL;
    return arvore;
}

int InserirNaArvore(noArv **arvore, int conteudo){

    if(*arvore == NULL){
        (*arvore) = CriaNoArvore(conteudo);
    }else{
        noArv *novoNoArvore = CriaNoArvore(conteudo);
        if(novoNoArvore == NULL){
            return 0;
        }
        noArv *arvoreAtual = *arvore;
        noArv *arvoreAnterior = NULL;
        while(arvoreAtual != NULL){
            arvoreAnterior = arvoreAtual;
            if(conteudo == arvoreAtual->conteudo){
                free(novoNoArvore);
                return 0;
            }
            if(conteudo > arvoreAtual->conteudo){
                arvoreAtual = arvoreAtual->dir;
            }else{
                arvoreAtual = arvoreAtual->esq;
            }
        }
        if(conteudo > arvoreAnterior->conteudo){
            arvoreAnterior->dir = novoNoArvore;
        }else{
            arvoreAnterior->esq = novoNoArvore;
        }
    }
    return 1;
}

void ImprimeArvorePreOrdem(noArv *arvore){

    if(arvore != NULL){
        printf("%i ", arvore->conteudo);
        ImprimeArvorePreOrdem(arvore->esq);
        ImprimeArvorePreOrdem(arvore->dir);
    }
}

void ImprimeArvoreInOrdem(noArv *arvore){

    if(arvore != NULL){
        ImprimeArvoreInOrdem(arvore->esq);
        printf("%i ", arvore->conteudo);
        ImprimeArvoreInOrdem(arvore->dir);
    }
}

void ImprimeArvorePosOrdem(noArv *arvore){

    if(arvore != NULL){
        ImprimeArvorePosOrdem(arvore->esq);
        ImprimeArvorePosOrdem(arvore->dir);
        printf("%i ", arvore->conteudo);
    }
}

int BuscarElementoNaArvore(noArv *arvore, int conteudo){

    if(arvore == NULL){
        return 0;
    }
    noArv *arvoreAtual = arvore;
    while(arvoreAtual != NULL){
        if(conteudo == arvoreAtual->conteudo){
            return 1;
        }
        if(conteudo > arvoreAtual->conteudo){
            arvoreAtual = arvoreAtual->dir;
        }else{
            arvoreAtual = arvoreAtual->esq;
        }
    }
    return 0;
}

int RemoverElementoNaArvore(noArv **arvore, int conteudo){

    if(*arvore == NULL){
        return 0;
    }

    noArv *arvoreAnterior = NULL;
    noArv *arvoreAtual = *arvore;
    while(arvoreAtual != NULL){
        if(conteudo == arvoreAtual->conteudo){
            if(arvoreAtual == *arvore){
                *arvore = RemoveNoArvoreAtual(arvoreAtual);
            }else{
                if(arvoreAnterior->dir == arvoreAtual){
                    arvoreAnterior->dir = RemoveNoArvoreAtual(arvoreAtual);
                }else{
                    arvoreAnterior->esq = RemoveNoArvoreAtual(arvoreAtual);
                }
            }
            return 1;
        }
        arvoreAnterior = arvoreAtual;
        if(conteudo > arvoreAtual->conteudo){
            arvoreAtual = arvoreAtual->dir;
        }else{
            arvoreAtual = arvoreAtual->esq;
        }
    }
}

noArv *RemoveNoArvoreAtual(noArv *arvoreAtual){
    noArv *arvoreUm, *arvoreDois;
    if(arvoreAtual->esq == NULL){
        arvoreDois = arvoreAtual->dir;
        free(arvoreAtual);
        return arvoreDois;
    }
    arvoreUm = arvoreAtual;
    arvoreDois = arvoreAtual->esq;
    while(arvoreDois->dir != NULL){
        arvoreUm = arvoreDois;
        arvoreDois = arvoreDois->dir;
    }

    if(arvoreUm != arvoreAtual){
        arvoreUm->dir = arvoreDois->esq;
        arvoreDois->esq = arvoreAtual->esq;
    }
    arvoreDois->dir = arvoreAtual->dir;
    free(arvoreAtual);
    return arvoreDois;
}

int AlturaArvore(noArv *arvore){

    if(arvore == NULL){
        return -1;
    }else{
        int alturaEsquerda = AlturaArvore(arvore->esq);
        int alturaDireita = AlturaArvore(arvore->dir);
        if(alturaEsquerda < alturaDireita){
            return alturaDireita + 1;
        }else{
            return alturaEsquerda + 1;
        }
    }

}
