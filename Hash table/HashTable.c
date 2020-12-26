#include <stdio.h>
#include <stdlib.h>
#include "SimpleLinkedListWithInt.h"

#define tamanhoVetorDeListas 100

void CriaHashInt(Lista *tabelaHash[]);
void ImprimirTabelaHash(Lista *tabelaHash[]);
void InsereHashComTratamentoDeColisaoListasEncadeadas(Lista *tabelaHash[], int conteudo);
void ExercicioHash(Lista *tabelaHash[], int quantidadeNumerosAleatorios);

int BuscarElementoNaTabela(Lista *tabelaHash[], int conteudo);
int ChaveDivisao(int conteudo, int tamanhoTabela);
int IndiceMaiorLista(Lista *tabelaHash[]);
int MaiorLista(Lista *tabelaHash[]);
int IndiceMenorLista(Lista *tabelaHash[]);
int MenorLista(Lista *tabelaHash[]);

int main(){

    int optionValue = 0, secondOptionValue = 0, quantidadeNumerosAleatorios;
    int conteudo = 0;
    char escolha, escolhaTerminar, escolhaTerminarDeInserir;

    Lista *tabelaHash[tamanhoVetorDeListas];

    CriaHashInt(tabelaHash);

    do{
        printf("Exercicio sobre Tabela HASH (Estrutura de Dados II) - IFSP Campinas \n");
        printf("1 - Inserir na tabela HASH:\n");
        printf("2 - Imprimir a tabela HASH:\n");
        printf("3 - Buscar um elemento na tabela HASH:\n");
        printf("4 - Exercicio [Sedg 14.19]:\n");
        scanf("%i", &optionValue);

        switch(optionValue){
            case 1:
                do{
                    printf("Digite um numero para inserir na tabela HASH: \n");
                    scanf("%i", &conteudo);
                    InsereHashComTratamentoDeColisaoListasEncadeadas(tabelaHash, conteudo);
                    printf("Deseja parar de inserir? (s- sim | n- nao) \n");
                    setbuf(stdin, NULL);
                    scanf("%c", &escolhaTerminarDeInserir);
                }while(escolhaTerminarDeInserir != 's');
                break;
            case 2:
                ImprimirTabelaHash(tabelaHash);
                break;
            case 3:
                printf("Digite o numero que deseja buscar na tabela HASH: \n");
                scanf("%i", &conteudo);
                BuscarElementoNaTabela(tabelaHash, conteudo);
                break;
            case 4:
                do{
                    printf("Digite a quantidade de numeros aleatorios a serem preenchidos na tabela HASH: \n");
                    scanf("%i", &quantidadeNumerosAleatorios);
                }while(quantidadeNumerosAleatorios <= 0);

                ExercicioHash(tabelaHash, quantidadeNumerosAleatorios);
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

void ExercicioHash(Lista *tabelaHash[], int quantidadeNumerosAleatorios){

    int numeros[quantidadeNumerosAleatorios];

    for(int i = 0; i < quantidadeNumerosAleatorios; i++){
        numeros[i] = rand();
    }

    for(int i = 0; i < quantidadeNumerosAleatorios; i++){
        InsereHashComTratamentoDeColisaoListasEncadeadas(tabelaHash, numeros[i]);
    }

    printf("Lista de indice %i, mais curta, de tamanho: %i \n", IndiceMenorLista(tabelaHash), tabelaHash[IndiceMenorLista(tabelaHash)]->totalElements);
    printf("Lista de indice %i, mais longa, de tamanho: %i \n", IndiceMaiorLista(tabelaHash), tabelaHash[IndiceMaiorLista(tabelaHash)]->totalElements);

}

int IndiceMaiorLista(Lista *tabelaHash[]){

    int i, j, maior = tabelaHash[0]->totalElements, indiceMaiorLista;
    for(i = 0; i < tamanhoVetorDeListas; i++){
        if(tabelaHash[i]->totalElements > maior){
            maior = tabelaHash[i]->totalElements;
            indiceMaiorLista = i;
        }
    }
    return indiceMaiorLista;
}

int MaiorLista(Lista *tabelaHash[]){

    int i, j, maior = tabelaHash[0]->totalElements, indiceMaiorLista;
    for(i = 0; i < tamanhoVetorDeListas; i++){
        if(tabelaHash[i]->totalElements > maior){
            maior = tabelaHash[i]->totalElements;
        }
    }
    return maior;
}

int IndiceMenorLista(Lista *tabelaHash[]){

    int i, j, menor = tabelaHash[0]->totalElements, indiceMenorLista;
    for(i = 0; i < tamanhoVetorDeListas; i++){
        if(tabelaHash[i]->totalElements < menor){
            menor = tabelaHash[i]->totalElements;
            indiceMenorLista = i;
        }
    }
    return indiceMenorLista;
}

int MenorLista(Lista *tabelaHash[]){

    int i, j, menor = tabelaHash[0]->totalElements;
    for(i = 0; i < tamanhoVetorDeListas; i++){
        if(tabelaHash[i]->totalElements < menor){
            menor = tabelaHash[i]->totalElements;
        }
    }
    return menor;
}

void CriaHashInt(Lista *tabelaHash[]){

    int i;
    for(i = 0; i < tamanhoVetorDeListas; i++){
        tabelaHash[i] = CriaLista();
    }
}

void InsereHashComTratamentoDeColisaoListasEncadeadas(Lista *tabelaHash[], int conteudo){

    int indice = ChaveDivisao(conteudo, tamanhoVetorDeListas);
    InsereNoFim(tabelaHash[indice], conteudo);
}

void ImprimirTabelaHash(Lista *tabelaHash[]){

    printf("\n---------------------TABELA---------------------------\n");
    for(int i = 0; i < tamanhoVetorDeListas; i++){
        printf("Indice: %i--------------------------------------------\n", i);
        ImprimeLista(tabelaHash[i]);
        printf("\n");
    }
    printf("---------------------FIM TABELA-----------------------\n");
}

int ChaveDivisao(int conteudo, int tamanhoTabela){
    return (conteudo & 0x7FFFFFFF) % tamanhoTabela;
}

int BuscarElementoNaTabela(Lista *tabelaHash[], int conteudo){

    int indice = ChaveDivisao(conteudo, tamanhoVetorDeListas);
    No *no = BuscaPonteiro(tabelaHash[indice], conteudo);
    if(no == NULL){
        printf("Valor nao encontrado ! \n");
        return -1;
    }
    printf("Valor %i encontrado ! \n", no->val);
    return no->val;
}


