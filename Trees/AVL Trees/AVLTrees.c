#include <stdio.h>
#include <stdlib.h>

typedef struct noArvore {
    int conteudo;
    int altura;
    int fatorBalanceamento;
    struct noArvore *esq;
    struct noArvore *dir;
} noArv;

void CriaArvore(noArv **arvore);
void ImprimeArvorePreOrdem(noArv *arvore);
void ImprimeArvoreInOrdem(noArv *arvore);
void ImprimeArvorePosOrdem(noArv *arvore);
void RotacaoLL(noArv **arvore);
void RotacaoRR(noArv **arvore);
void RotacaoLR(noArv **arvore);
void RotacaoRL(noArv **arvore);

noArv *ProcuraMenor(noArv *arvoreAtual);
noArv *RemoveNoArvoreAtual(noArv *arvoreAtual);
noArv *CriaNoArvore(int conteudo);

int InserirNaArvoreAVL(noArv **arvore, int conteudo);
int BuscarElementoNaArvoreAVL(noArv *arvore, int conteudo);
int RemoverElementoNaArvoreAVL(noArv **arvore, int conteudo);
int AlturaArvore(noArv *arvore);
int AlturaNo(noArv *arvore);
int FatorBalanceamentoNo(noArv *arvore);
int MaiorValorNo(int conteudo1, int conteudo2);


int main(){

    int optionValue = 0, secondOptionValue = 0;
    int conteudo = 0, retornoInsercao = 0;
    char escolha, escolhaTerminar, escolhaTerminarDeBuscar, escolhaTerminarDeInserir, escolhaTerminarDeBuscarERemover;

    noArv **arvore;
    CriaArvore(arvore);

    do{
        printf("Trabalho Bimestral 01 (Estrutura de Dados II) - IFSP Campinas (Arvore AVL) \n");
        printf("1 - Inserir na arvore AVL:\n");
        printf("2 - Imprimir a arvore AVL:\n");
        printf("3 - Buscar um elemento na arvore AVL:\n");
        printf("4 - Remover um elemento na arvore AVL:\n");
        printf("5 - Altura da arvore AVL:\n");
        scanf("%i", &optionValue);

        switch(optionValue){
            case 1:
                do{
                    printf("Digite um numero para inserir na arvore AVL: \n");
                    scanf("%i", &conteudo);
                    retornoInsercao = InserirNaArvoreAVL(arvore, conteudo);
                    if(retornoInsercao == 1){
                        printf("Valor %i inserido com sucesso na arvore AVL ! \n", conteudo);
                    }else{
                        printf("Nao foi possivel inserir o valor na arvore AVL ! \n");
                    }
                    printf("Deseja parar de inserir? (s- sim | n- nao) \n");
                    setbuf(stdin, NULL);
                    scanf("%c", &escolhaTerminarDeInserir);
                }while(escolhaTerminarDeInserir != 's');

                retornoInsercao = 0;
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
                    printf("Digite um numero para buscar na arvore AVL: \n");
                    scanf("%i", &conteudo);
                    if(BuscarElementoNaArvoreAVL(*arvore, conteudo) == 1){
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
                    printf("Digite um numero para remover na arvore AVL: \n");
                    scanf("%i", &conteudo);
                    if(RemoverElementoNaArvoreAVL(arvore, conteudo) == 1){
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
    arvore->altura = 0;
    arvore->fatorBalanceamento = 0;
    arvore->conteudo = conteudo;
    arvore->dir = NULL;
    arvore->esq = NULL;
    return arvore;
}

int InserirNaArvoreAVL(noArv **arvore, int conteudo){
    int resposta;

    if((*arvore) == NULL){
        noArv *novoNoArvore;
        novoNoArvore = CriaNoArvore(conteudo);
        *arvore = novoNoArvore;
        return 1;
    }else{
        noArv *arvoreAtual = *arvore;
        if(conteudo < arvoreAtual->conteudo){
            resposta = InserirNaArvoreAVL(&(arvoreAtual->esq), conteudo);
            if(resposta == 1){
                arvoreAtual->fatorBalanceamento = FatorBalanceamentoNo(arvoreAtual);
                if(arvoreAtual->fatorBalanceamento >= 2){
                    if(conteudo < (*arvore)->esq->conteudo){
                        RotacaoLL(arvore);
                    }else{
                        RotacaoLR(arvore);
                    }
                }
            }
        }else{
            if(conteudo > arvoreAtual->conteudo){
                resposta = InserirNaArvoreAVL(&(arvoreAtual->dir), conteudo);
                if(resposta == 1){
                    arvoreAtual->fatorBalanceamento = FatorBalanceamentoNo(arvoreAtual);
                    if(arvoreAtual->fatorBalanceamento <= -2){
                        if((*arvore)->dir->conteudo < conteudo){
                            RotacaoRR(arvore);
                        }else{
                            RotacaoRL(arvore);
                        }
                    }
                }
            }else{
                printf("Valor duplicado ! \n");
                return 0;
            }
        }
        arvoreAtual->altura = MaiorValorNo(AlturaNo(arvoreAtual->esq), AlturaNo(arvoreAtual->dir)) + 1;
        arvoreAtual->fatorBalanceamento = FatorBalanceamentoNo(arvoreAtual);
        return resposta;
    }
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

int BuscarElementoNaArvoreAVL(noArv *arvore, int conteudo){

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

int RemoverElementoNaArvoreAVL(noArv **arvore, int conteudo){

    if(*arvore == NULL){
        printf("O valor a ser removido nao existe! \n");
        return 0;
    }
    int resposta;
    if(conteudo < (*arvore)->conteudo){
        resposta = RemoverElementoNaArvoreAVL(&(*arvore)->esq, conteudo);
        if(resposta == 1){
            (*arvore)->fatorBalanceamento = FatorBalanceamentoNo(*arvore);
            if((*arvore)->fatorBalanceamento >= 2){
                if(AlturaNo((*arvore)->dir->esq) <= AlturaNo((*arvore)->dir->dir)){
                    RotacaoRR(arvore);
                }else{
                    RotacaoRL(arvore);
                }
            }
        }
    }
    if((*arvore)->conteudo < conteudo){
        resposta = RemoverElementoNaArvoreAVL(&(*arvore)->dir, conteudo);
        if(resposta == 1){
            (*arvore)->fatorBalanceamento = FatorBalanceamentoNo(*arvore);
            if((*arvore)->fatorBalanceamento <= -2){
                if(AlturaNo((*arvore)->esq->dir) <= AlturaNo((*arvore)->esq->esq)){
                    RotacaoLL(arvore);
                }else{
                    RotacaoLR(arvore);
                }
            }
        }
    }
    if((*arvore)->conteudo == conteudo){
        if(((*arvore)->esq == NULL) || (*arvore)->dir == NULL){
            noArv *noArvoreAntigo = *arvore;
            if((*arvore)->esq != NULL){
                *arvore = (*arvore)->esq;
            }else{
                *arvore = (*arvore)->dir;
            }
            free(noArvoreAntigo);
        }else{
            noArv *arvoreTemporaria = ProcuraMenor((*arvore)->dir);
            (*arvore)->conteudo = arvoreTemporaria->conteudo;
            RemoverElementoNaArvoreAVL(&(*arvore)->dir, (*arvore)->conteudo);
            (*arvore)->fatorBalanceamento = FatorBalanceamentoNo(*arvore);
            if((*arvore)->fatorBalanceamento <= -2){
                if(AlturaNo((*arvore)->esq->dir) <= AlturaNo((*arvore)->esq->esq)){
                    RotacaoLL(arvore);
                }else{
                    RotacaoLR(arvore);
                }
            }
        }
        return 1;
    }
    return resposta;
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

noArv *ProcuraMenor(noArv *arvoreAtual){
    noArv *noArvore1 = arvoreAtual;
    noArv *noArvore2 = arvoreAtual->esq;
    while(noArvore2 != NULL){
        noArvore1 = noArvore2;
        noArvore2 = noArvore2->esq;
    }
    return noArvore1;
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

int AlturaNo(noArv *arvore){

    if(arvore == NULL){
        return -1;
    }else{
        return arvore->altura;
    }
}

int FatorBalanceamentoNo(noArv *arvore){
    return (AlturaNo(arvore->esq) - AlturaNo(arvore->dir));
}

int MaiorValorNo(int conteudo1, int conteudo2){

    if(conteudo1 > conteudo2){
        return conteudo1;
    }else{
        return conteudo2;
    }
}

void RotacaoLL(noArv **arvore){
    noArv *noArvore;
    noArvore = (*arvore)->esq;
    (*arvore)->esq = noArvore->dir;
    noArvore->dir = *arvore;
    (*arvore)->altura = MaiorValorNo(AlturaNo((*arvore)->esq), AlturaNo((*arvore)->dir)) + 1;

    noArvore->altura = MaiorValorNo(AlturaNo(noArvore->esq), (*arvore)->altura) + 1;

    *arvore = noArvore;
}

void RotacaoRR(noArv **arvore){
    noArv *noArvore;
    noArvore = (*arvore)->dir;
    (*arvore)->dir = noArvore->esq;
    noArvore->esq = (*arvore);
    (*arvore)->altura = MaiorValorNo(AlturaNo((*arvore)->esq), AlturaNo((*arvore)->dir)) + 1;

    noArvore->altura = MaiorValorNo(AlturaNo(noArvore->dir), (*arvore)->altura) + 1;

    *arvore = noArvore;
}

void RotacaoLR(noArv **arvore){
    RotacaoRR(&(*arvore)->esq);
    RotacaoLL(arvore);
}

void RotacaoRL(noArv **arvore){
    RotacaoLL(&(*arvore)->dir);
    RotacaoRR(arvore);
}
