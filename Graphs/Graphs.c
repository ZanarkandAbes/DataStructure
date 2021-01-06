#include <stdio.h>
#include <stdlib.h>
#include "SimpleLinkedListWithInt.h"

typedef struct grafoMatriz {
    int verificaPonderado;
    int numeroVertices;
    int grauMaximo;
    int **arestas;
    float **pesos;
    int *grau;
} GrafoMatriz;

typedef struct grafoLista {
    int vertices;
    int arcos;
    Lista *adjacentes[];
} GrafoLista;

// A lista de adjacência é um array (onde a quantidade de elementos do array são os vértices) e cada vértice aponta para uma lista encadeada simples,
// ou seja, semelhante a tabela hash, mesmo raciocínio, só que a quantidade de listas desse array é o número de vértices.
// Inserir por exemplo seria, escolher um vértice (posição do array) e com o vértice escolhido, inserir na lista desse vértice o valor correspondente
// Escolhe o vértice de origem e o de destino para inserir.
// Remover por exemplo seria, escolher um vértice (posição do array) e chamar a função que remove elemento da lista encadeada simples para
// aquela lista escolhida em específico da posição do array.

GrafoLista *CriaGrafoLista(int vertices);
void InsereArcoLista(GrafoLista *grafo, int origem, int destino);
void ImprimeGrafoLista(GrafoLista *grafo);
void ExcluiArcoLista(GrafoLista *grafo, int origem, int destino);

GrafoMatriz *CriaGrafoMatriz(int numeroVertices, int grauMaximo, int verificaPonderado);

void LiberaGrafo(GrafoMatriz *grafo);
void ImprimeGrafoMatriz(GrafoMatriz *grafo);

int InsereArestaMatriz(GrafoMatriz *grafo, int origem, int destino, int verificaDigrafo, float peso);
int RemoveArestaMatriz(GrafoMatriz *grafo, int origem, int destino, int verificaDigrafo);

int main(){

    /*rafoMatriz *grafoMatriz;
    grafoMatriz = CriaGrafoMatriz(10, 7, 0);

    InsereArestaMatriz(grafoMatriz, 0, 1, 0, 0);
    printf("Impressao 1: \n");
    ImprimeGrafoMatriz(grafoMatriz);
    InsereArestaMatriz(grafoMatriz, 1, 3, 0, 0);
    printf("Impressao 2: \n");
    ImprimeGrafoMatriz(grafoMatriz);
    RemoveArestaMatriz(grafoMatriz, 0, 1, 0);
    printf("Impressao 3: \n");
    ImprimeGrafoMatriz(grafoMatriz);
    LiberaGrafo(grafoMatriz);

    printf("Exemplo de codigo que vai ter para listas de adjacencia: \n");
    GrafoLista *grafoLista = CriaGrafoLista(5);
    // Criar uma função que cria o grafo de lista e aloca os vértices (tamanho do array de listas) os arcos (que começa em 0 porque nenhum grafo foi
    // conectado) e alocar o array de listas.
    // Cada elemento que for inserido será incrementado um arco!
    InsereArcoLista(grafoLista, 0, 4);
    InsereArcoLista(grafoLista, 4, 2);
    InsereArcoLista(grafoLista, 4, 0);
    ImprimeGrafoLista(grafoLista);
    ExcluiArcoLista(grafoLista, 0, 4);
    ImprimeGrafoLista(grafoLista);
    ExcluiArcoLista(grafoLista, 3, 4);
    ImprimeGrafoLista(grafoLista);*/

    int optionValue = 0, secondOptionValue = 0, numeroVertices = 0, grauMaximo = 0, verificaPonderado = 0, origem = 0, destino = 0, verificaDigrafo = 0;
    int conteudo = 0;
    char escolha, escolhaTerminar, escolhaTerminarDeInserir;
    float peso = 0.0;

    do{
        printf("Trabalho Bimestral 02 (Estrutura de Dados II) - IFSP Campinas (Grafos) \n");
        printf("1 - Grafo de Matriz de Adjacencia:\n");
        printf("2 - Grafo de Lista de Adjacencia:\n");
        scanf("%i", &optionValue);

        switch(optionValue){
            case 1:
                printf("1 - Criar o grafo:\n");
                printf("2 - Inserir aresta no grafo:\n");
                printf("3 - Remover aresta no grafo:\n");
                printf("4 - Imprimir grafo: \n");
                scanf("%i", &secondOptionValue);
                GrafoMatriz *grafoMatriz;
                switch(secondOptionValue){
                    case 1:
                        do{
                            printf("Digite o numero de vertices do grafo para gerar a matriz de adjacencia: \n");
                            scanf("%i", &numeroVertices);
                            if(numeroVertices < 0){
                                printf("Digite um numero maior que 0! \n");
                            }
                        }while(numeroVertices < 0);

                        do{
                            printf("Digite o grau maximo do grafo para a matriz de adjacencia: \n");
                            scanf("%i", &grauMaximo);
                            if(grauMaximo < 0){
                                printf("Digite um numero maior que 0! \n");
                            }
                        }while(grauMaximo < 0);

                        do{
                            printf("E um grafo ponderado? [1 - sim | 0 - nao] \n");
                            scanf("%i", &verificaPonderado);
                        }while((verificaPonderado != 0) && (verificaPonderado != 1));

                        grafoMatriz = CriaGrafoMatriz(numeroVertices, grauMaximo, verificaPonderado);
                        system("cls");
                        break;
                    case 2:
                        do{
                            printf("Digite o vertice de origem do grafo para inserir na matriz de adjacencia: \n");
                            scanf("%i", &origem);
                            if(origem < 0){
                                printf("Digite um numero maior que 0! \n");
                            }
                        }while((origem < 0) || (origem >= grafoMatriz->numeroVertices));

                        do{
                            printf("Digite o vertice de destino do grafo para inserir na matriz de adjacencia: \n");
                            scanf("%i", &destino);
                            if(destino < 0){
                                printf("Digite um numero maior que 0! \n");
                            }
                        }while((destino < 0) || (destino >= grafoMatriz->numeroVertices));

                        do{
                            printf("E um digrafo? [1 - sim | 0 - nao] \n");
                            scanf("%i", &verificaDigrafo);
                        }while((verificaDigrafo != 0) && (verificaDigrafo != 1));

                        do{
                            printf("Digite um peso para o grafo : \n");
                            scanf("%f", &peso);
                        }while(peso < 0);

                        InsereArestaMatriz(grafoMatriz, origem, destino, verificaDigrafo, peso);
                        system("cls");
                        break;
                    case 3:
                        do{
                            printf("Digite o vertice de origem do grafo para remover da matriz de adjacencia: \n");
                            scanf("%i", &origem);
                            if(origem < 0){
                                printf("Digite um numero maior que 0! \n");
                            }
                        }while((origem < 0) || (origem >= grafoMatriz->numeroVertices));

                        do{
                            printf("Digite o vertice de destino do grafo para remover da matriz de adjacencia: \n");
                            scanf("%i", &destino);
                            if(destino < 0){
                                printf("Digite um numero maior que 0! \n");
                            }
                        }while((destino < 0) || (destino >= grafoMatriz->numeroVertices));

                        do{
                            printf("E um digrafo? [1 - sim | 0 - nao] \n");
                            scanf("%i", &verificaDigrafo);
                        }while((verificaDigrafo != 0) && (verificaDigrafo != 1));


                        RemoveArestaMatriz(grafoMatriz, origem, destino, verificaDigrafo);
                        system("cls");
                        break;
                    case 4:
                        ImprimeGrafoMatriz(grafoMatriz);
                        break;
                    default:
                        printf("Opcao invalida ! \n");
                        break;
                }
                break;
            case 2:
                printf("1 - Criar o grafo:\n");
                printf("2 - Inserir arco no grafo:\n");
                printf("3 - Remover arco no grafo:\n");
                printf("4 - Imprimir grafo: \n");
                printf("5 - Busca em Profundidade: \n");
                printf("6 - Busca em largura: \n");
                scanf("%i", &secondOptionValue);
                GrafoLista *grafoLista;

                switch(secondOptionValue){
                    case 1:
                        do{
                            printf("Digite o numero de vertices do grafo para gerar a lista de adjacencia: \n");
                            scanf("%i", &numeroVertices);
                            if(numeroVertices < 0){
                                printf("Digite um numero maior que 0! \n");
                            }
                        }while(numeroVertices < 0);

                        grafoLista = CriaGrafoLista(numeroVertices);
                        system("cls");
                        break;
                    case 2:
                        do{
                            printf("Digite o vertice de origem do grafo para inserir na lista de adjacencia: \n");
                            scanf("%i", &origem);
                            if(origem < 0){
                                printf("Digite um numero maior que 0! \n");
                            }
                        }while((origem < 0) || (origem >= grafoLista->vertices));

                        do{
                            printf("Digite o vertice de destino do grafo para inserir na lista de adjacencia: \n");
                            scanf("%i", &destino);
                            if(destino < 0){
                                printf("Digite um numero maior que 0! \n");
                            }
                        }while((destino < 0) || (destino >= grafoLista->vertices));

                        InsereArcoLista(grafoLista, origem, destino);
                        system("cls");
                        break;
                    case 3:
                        do{
                            printf("Digite o vertice de origem do grafo para remover da lista de adjacencia: \n");
                            scanf("%i", &origem);
                            if(origem < 0){
                                printf("Digite um numero maior que 0! \n");
                            }
                        }while((origem < 0) || (origem >= grafoLista->vertices));

                        do{
                            printf("Digite o vertice de destino do grafo para remover da lista de adjacencia: \n");
                            scanf("%i", &destino);
                            if(destino < 0){
                                printf("Digite um numero maior que 0! \n");
                            }
                        }while((destino < 0) || (destino >= grafoLista->vertices));

                        ExcluiArcoLista(grafoLista, origem, destino);
                        system("cls");
                        break;
                    case 4:
                        ImprimeGrafoLista(grafoLista);
                        break;
                    default:
                        printf("Opcao invalida ! \n");
                        break;
                }
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

GrafoLista *CriaGrafoLista(int vertices){
    GrafoLista *grafo = (GrafoLista*) calloc(1, sizeof(GrafoLista));
    grafo->vertices = vertices;
    grafo->arcos = 0;
    grafo->adjacentes[vertices];
    for(int i = 0; i < vertices; i++){
        grafo->adjacentes[i] = (Lista*) calloc(vertices, sizeof(Lista));
        grafo->adjacentes[i] = CriaLista();
    }
    return grafo;
}

void InsereArcoLista(GrafoLista *grafo, int origem, int destino){

    if(grafo == NULL){
        printf("Grafo nao existe");
        return;
    }

    if((origem < 0) || (origem >= grafo->vertices)){
        printf("Origem e um valor negativo ou ultrapassa o numero de vertices do grafo ! \n");
        return;
    }

    if((destino < 0) || (destino >= grafo->vertices)){
        printf("Destino e um valor negativo ou ultrapassa o numero de vertices do grafo ! \n");
        return;
    }

    InsereNoFim(grafo->adjacentes[origem], destino);
    grafo->arcos++;
    printf("Insercao feita com sucesso! \n");
}

void ExcluiArcoLista(GrafoLista *grafo, int origem, int destino){

    if(grafo == NULL){
        printf("Grafo nao existe");
        return;
    }

    if((origem < 0) || (origem >= grafo->vertices)){
        printf("Origem e um valor negativo ou ultrapassa o numero de vertices do grafo ! \n");
        return;
    }

    if((destino < 0) || (destino >= grafo->vertices)){
        printf("Destino e um valor negativo ou ultrapassa o numero de vertices do grafo ! \n");
        return;
    }

    BuscaERemoveRepetidos(grafo->adjacentes[origem], destino);
    grafo->arcos--;
    printf("Remocao feita com sucesso! \n");
}

GrafoMatriz *CriaGrafoMatriz(int numeroVertices, int grauMaximo, int verificaPonderado){

    GrafoMatriz *grafo = (GrafoMatriz*) calloc(1, sizeof(GrafoMatriz));

    if(grafo != NULL){
        grafo->numeroVertices = numeroVertices;
        grafo->grauMaximo = grauMaximo;
        if(verificaPonderado != 0){
            grafo->verificaPonderado = 1;
        }else{
            grafo->verificaPonderado = 0;
        }
        grafo->grau = (int*) calloc(numeroVertices, sizeof(int));
        grafo->arestas = (int**) calloc(numeroVertices, sizeof(int*));
        for(int i = 0; i < numeroVertices; i++){
            grafo->arestas[i] = (int*) calloc(grauMaximo, sizeof(int*));
            if(grafo->verificaPonderado == 1){
                grafo->pesos = (float**) calloc(numeroVertices, sizeof(float*));
                for(int i = 0; i < numeroVertices; i++){
                    grafo->pesos[i] = (float*) calloc(grauMaximo, sizeof(float));
                }
            }
        }
    }
    return grafo;
}

void LiberaGrafo(GrafoMatriz *grafo){

    if(grafo != NULL){
        for(int i = 0; i < grafo->numeroVertices; i++){
            free(grafo->arestas[i]);
        }
        free(grafo->arestas);

        if(grafo->verificaPonderado == 1){
            for(int i = 0; i < grafo->numeroVertices; i++){
                free(grafo->pesos[i]);
            }
            free(grafo->pesos);
        }
        free(grafo->grau);
        free(grafo);
    }
}

int InsereArestaMatriz(GrafoMatriz *grafo, int origem, int destino, int verificaDigrafo, float peso){

    if(grafo == NULL){
        return 0;
    }

    if((origem < 0) || (origem >= grafo->numeroVertices)){
        return 0;
    }

    if((destino < 0) || (destino >= grafo->numeroVertices)){
        return 0;
    }

    grafo->arestas[origem][grafo->grau[origem]] = destino;

    if(grafo->verificaPonderado == 1){
        grafo->pesos[origem][grafo->grau[origem]] = peso;
    }

    grafo->grau[origem]++;

    if(verificaDigrafo == 0){
        InsereArestaMatriz(grafo, destino, origem, 1, peso);
    }
    return 1;
}

int RemoveArestaMatriz(GrafoMatriz *grafo, int origem, int destino, int verificaDigrafo){

    if(grafo == NULL){
        return 0;
    }

    if((origem < 0) || (origem >= grafo->numeroVertices)){
        return 0;
    }

    if((destino < 0) || (destino >= grafo->numeroVertices)){
        return 0;
    }

    int i = 0;
    while((i < grafo->grau[origem]) && (grafo->arestas[origem][i] != destino)){
        i++;
    }
    if(i == grafo->grau[origem]){
        return 0;
    }
    grafo->grau[origem]--;
    grafo->arestas[origem][i] = grafo->arestas[origem][grafo->grau[origem]];
    if(grafo->verificaPonderado == 1){
        grafo->pesos[origem][i] = grafo->pesos[origem][grafo->grau[origem]];
    }
    if(verificaDigrafo == 0){
        RemoveArestaMatriz(grafo, destino, origem, 1);
    }
    return 1;
}

void ImprimeGrafoMatriz(GrafoMatriz *grafo){

    if(grafo == NULL){
        printf("Grafo vazio ! \n");
    }
    int i, j;
    printf("\n---------------------MATRIZ DE ADJACENCIA------------------------------\n");
    for(i = 0; i < grafo->numeroVertices; i++){
        printf("%i-", i);
        for(j = 0; j < grafo->grau[i]; j++){
            if(grafo->verificaPonderado == 1){
                printf("%i(%2.f),", grafo->arestas[i][j], grafo->pesos[i][j]);
            }else{
                printf("%i,", grafo->arestas[i][j]);
            }
        }
        printf("\n");
    }
    printf("---------------------FIM DA MATRIZ DE ADJACENCIA-----------------------\n");
}

void ImprimeGrafoLista(GrafoLista *grafo){

    printf("\n---------------------LISTA DE ADJACENCIA-------------------------------\n");
    for(int i = 0; i < grafo->vertices; i++){
        printf("Vertice: %i-------------------------------------------------------------\n", i);
        ImprimeLista(grafo->adjacentes[i]);
        printf("\n");
    }
    printf("---------------------FIM DA LISTA DE ADJACENCIA------------------------\n");
}





