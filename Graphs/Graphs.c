#include <stdio.h>
#include <stdlib.h>

typedef struct grafoMatriz{
    int vertices;
    int arestas;
    int **adjacentes;
} GrafoMatriz;

typedef struct grafoLista {
    int verificaPonderado;
    int numeroVertices;
    int grauMaximo;
    int **arestas;
    float **pesos;
    int *grau;
} GrafoLista;

GrafoMatriz *CriaGrafoMatriz(int numeroVertices);

int **CriaMatriz(int numeroVertices, int valorInicial);

void ImprimeGrafoMatriz(GrafoMatriz *grafo);
void InsereArestaMatriz(GrafoMatriz *grafo, int origem, int destino);
void RemoveArestaMatriz(GrafoMatriz *grafo, int origem, int destino);

GrafoLista *CriaGrafoLista(int numeroVertices, int grauMaximo, int verificaPonderado);

void LiberaGrafo(GrafoLista *grafo);
void ImprimeGrafoLista(GrafoLista *grafo);
void BuscaProfundidadeGrafoLista(GrafoLista *grafo, int inicial, int *visitado);
void BuscaProfundidade(GrafoLista *grafo, int inicial, int *visitado, int contador);
void BuscaLarguraGrafoLista(GrafoLista *grafo, int inicial, int *visitado);
void BuscaMenorCaminhoGrafoLista(GrafoLista *grafo, int inicial, int *anterior, float *distancia);

int ProcuraMenorDistancia(float distancia[], int *visitado, int numeroVertices);
int InsereArestaLista(GrafoLista *grafo, int origem, int destino, int verificaDigrafo, float peso);
int RemoveArestaLista(GrafoLista *grafo, int origem, int destino, int verificaDigrafo);

int main(){

    int optionValue = 0, secondOptionValue = 0, numeroVertices = 0, grauMaximo = 0, verificaPonderado = 0, origem = 0, destino = 0, verificaDigrafo = 0;
    int conteudo = 0, inicial = 0;
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

                        grafoMatriz = CriaGrafoMatriz(numeroVertices);
                        system("cls");
                        break;
                    case 2:
                        do{
                            printf("Digite o vertice de origem do grafo para inserir na matriz de adjacencia: \n");
                            scanf("%i", &origem);
                            if(origem < 0){
                                printf("Digite um numero maior que 0! \n");
                            }
                        }while((origem < 0) || (origem >= grafoMatriz->vertices));

                        do{
                            printf("Digite o vertice de destino do grafo para inserir na matriz de adjacencia: \n");
                            scanf("%i", &destino);
                            if(destino < 0){
                                printf("Digite um numero maior que 0! \n");
                            }
                        }while((destino < 0) || (destino >= grafoMatriz->vertices));

                        InsereArestaMatriz(grafoMatriz, origem, destino);
                        system("cls");
                        break;
                    case 3:
                        do{
                            printf("Digite o vertice de origem do grafo para remover da matriz de adjacencia: \n");
                            scanf("%i", &origem);
                            if(origem < 0){
                                printf("Digite um numero maior que 0! \n");
                            }
                        }while((origem < 0) || (origem >= grafoMatriz->vertices));

                        do{
                            printf("Digite o vertice de destino do grafo para remover da matriz de adjacencia: \n");
                            scanf("%i", &destino);
                            if(destino < 0){
                                printf("Digite um numero maior que 0! \n");
                            }
                        }while((destino < 0) || (destino >= grafoMatriz->vertices));

                        RemoveArestaMatriz(grafoMatriz, origem, destino);
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
                printf("6 - Busca em Largura: \n");
                printf("7 - Busca pelo menor caminho (algoritmo de Dijkstra): \n");
                scanf("%i", &secondOptionValue);
                GrafoLista *grafoLista;
                int *visitado, *anterior;
                float *distancia;

                switch(secondOptionValue){
                    case 1:
                        do{
                            printf("Digite o numero de vertices do grafo para gerar a lista de adjacencia: \n");
                            scanf("%i", &numeroVertices);
                            if(numeroVertices < 0){
                                printf("Digite um numero maior que 0! \n");
                            }
                        }while(numeroVertices < 0);

                        do{
                            printf("Digite o grau maximo do grafo para a lista de adjacencia: \n");
                            scanf("%i", &grauMaximo);
                            if(grauMaximo < 0){
                                printf("Digite um numero maior que 0! \n");
                            }
                        }while(grauMaximo < 0);

                        do{
                            printf("E um grafo ponderado? [1 - sim | 0 - nao] \n");
                            scanf("%i", &verificaPonderado);
                        }while((verificaPonderado != 0) && (verificaPonderado != 1));

                        grafoLista = CriaGrafoLista(numeroVertices, grauMaximo, verificaPonderado);
                        system("cls");
                        break;
                    case 2:
                        do{
                            printf("Digite o vertice de origem do grafo para inserir na lista de adjacencia: \n");
                            scanf("%i", &origem);
                            if(origem < 0){
                                printf("Digite um numero maior que 0! \n");
                            }
                        }while((origem < 0) || (origem >= grafoLista->numeroVertices));

                        do{
                            printf("Digite o vertice de destino do grafo para inserir na lista de adjacencia: \n");
                            scanf("%i", &destino);
                            if(destino < 0){
                                printf("Digite um numero maior que 0! \n");
                            }
                        }while((destino < 0) || (destino >= grafoLista->numeroVertices));

                        do{
                            printf("E um digrafo? [1 - sim | 0 - nao] \n");
                            scanf("%i", &verificaDigrafo);
                        }while((verificaDigrafo != 0) && (verificaDigrafo != 1));

                        do{
                            printf("Digite um peso para o grafo : \n");
                            scanf("%f", &peso);
                        }while(peso < 0);

                        InsereArestaLista(grafoLista, origem, destino, verificaDigrafo, peso);
                        system("cls");
                        break;
                    case 3:
                        do{
                            printf("Digite o vertice de origem do grafo para remover da lista de adjacencia: \n");
                            scanf("%i", &origem);
                            if(origem < 0){
                                printf("Digite um numero maior que 0! \n");
                            }
                        }while((origem < 0) || (origem >= grafoLista->numeroVertices));

                        do{
                            printf("Digite o vertice de destino do grafo para remover da lista de adjacencia: \n");
                            scanf("%i", &destino);
                            if(destino < 0){
                                printf("Digite um numero maior que 0! \n");
                            }
                        }while((destino < 0) || (destino >= grafoLista->numeroVertices));

                        do{
                            printf("E um digrafo? [1 - sim | 0 - nao] \n");
                            scanf("%i", &verificaDigrafo);
                        }while((verificaDigrafo != 0) && (verificaDigrafo != 1));

                        RemoveArestaLista(grafoLista, origem, destino, verificaDigrafo);
                        system("cls");
                        break;
                    case 4:
                        ImprimeGrafoLista(grafoLista);
                        break;
                    case 5:
                        do{
                            printf("Digite o vertice inicial de busca de profundidade : \n");
                            scanf("%i", &inicial);

                        }while(inicial < 0);

                        if(grafoLista != NULL){
                            visitado = (int*) calloc(grafoLista->numeroVertices, sizeof(int));
                        }else{
                            printf("Grafo nao existe, encerrando a aplicacao ! \n");
                            return 0;
                        }
                        BuscaProfundidadeGrafoLista(grafoLista, inicial, visitado);
                        printf("Indice de visita nos vertices do grafo: \n");
                        for(int i = 0; i < grafoLista->numeroVertices; i++){
                            printf("visitado[%i] : %i \n", i, visitado[i]);
                        }
                        break;
                    case 6:
                        do{
                            printf("Digite o vertice inicial de busca de largura : \n");
                            scanf("%i", &inicial);

                        }while(inicial < 0);

                        if(grafoLista != NULL){
                            visitado = (int*) calloc(grafoLista->numeroVertices, sizeof(int));
                        }else{
                            printf("Grafo nao existe, encerrando a aplicacao ! \n");
                            return 0;
                        }

                        BuscaLarguraGrafoLista(grafoLista, inicial, visitado);
                        printf("Indice de visita nos vertices do grafo: \n");
                        for(int i = 0; i < grafoLista->numeroVertices; i++){
                            printf("visitado[%i] : %i \n", i, visitado[i]);
                        }
                        break;
                    case 7:
                        do{
                            printf("Digite o vertice inicial de busca pelo menor caminho : \n");
                            scanf("%i", &inicial);

                        }while(inicial < 0);

                        if(grafoLista != NULL){
                            anterior = (int*) calloc(grafoLista->numeroVertices, sizeof(int));
                            distancia = (float*) calloc(grafoLista->numeroVertices, sizeof(float));
                        }else{
                            printf("Grafo nao existe, encerrando a aplicao ! \n");
                            return 0;
                        }
                        BuscaMenorCaminhoGrafoLista(grafoLista, inicial, anterior, distancia);
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

GrafoLista *CriaGrafoLista(int numeroVertices, int grauMaximo, int verificaPonderado){

    GrafoLista *grafo = (GrafoLista*) calloc(1, sizeof(GrafoLista));

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

void LiberaGrafo(GrafoLista *grafo){

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

int InsereArestaLista(GrafoLista *grafo, int origem, int destino, int verificaDigrafo, float peso){

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
        InsereArestaLista(grafo, destino, origem, 1, peso);
    }
    return 1;
}

int RemoveArestaLista(GrafoLista *grafo, int origem, int destino, int verificaDigrafo){

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
        RemoveArestaLista(grafo, destino, origem, 1);
    }
    return 1;
}

void ImprimeGrafoLista(GrafoLista *grafo){

    if(grafo == NULL){
        printf("Grafo vazio ! \n");
    }
    int i, j;
    printf("\n---------------------LISTA DE ADJACENCIA------------------------------\n");
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
    printf("---------------------FIM DA LISTA DE ADJACENCIA-----------------------\n");
}

GrafoMatriz *CriaGrafoMatriz(int numeroVertices){
    GrafoMatriz *grafo = (GrafoMatriz*) calloc(1, sizeof(GrafoMatriz));
    grafo->vertices = numeroVertices;
    grafo->arestas = 0;
    grafo->adjacentes = CriaMatriz(numeroVertices, 0);
    return grafo;
}

int **CriaMatriz(int numeroVertices, int valorInicial){
    int **matriz = (int**) calloc(numeroVertices, sizeof(int*));
    for(int i = 0; i < numeroVertices; i++){
        matriz[i] = (int*) calloc(numeroVertices, sizeof(int));
    }
    for(int i = 0; i < numeroVertices; i++){
        for(int j = 0; j < numeroVertices; j++){
            matriz[i][j] = valorInicial;
        }
    }
    return matriz;
}

void ImprimeGrafoMatriz(GrafoMatriz *grafo){

    for(int i = 0; i < grafo->vertices; i++){
        printf("%d:", i);
        for(int j = 0; j < grafo->vertices; j++){
            if(grafo->adjacentes[i][j] == 1){
                printf(" %d", j);
            }
        }
        printf("\n");
    }
}

void InsereArestaMatriz(GrafoMatriz *grafo, int origem, int destino){

    if(grafo == NULL){
        printf("Grafo nao existe ! \n");
        return;
    }

    if(grafo->adjacentes[origem][destino] == 0){
        grafo->adjacentes[origem][destino] = 1;
        grafo->arestas++;
    }
}

void RemoveArestaMatriz(GrafoMatriz *grafo, int origem, int destino){

    if(grafo == NULL){
        printf("Grafo nao existe ! \n");
        return;
    }

    if(grafo->adjacentes[origem][destino] == 1){
        grafo->adjacentes[origem][destino] = 0;
        grafo->arestas--;
    }
}

void BuscaProfundidade(GrafoLista *grafo, int inicial, int visitado[], int contador){

    int i;
    visitado[inicial] = contador;
    for(i = 0; i < grafo->grau[inicial]; i++){
        if(!visitado[grafo->arestas[inicial][i]]){
            BuscaProfundidade(grafo, grafo->arestas[inicial][i], visitado, contador + 1);
        }
    }
}

void BuscaProfundidadeGrafoLista(GrafoLista *grafo, int inicial, int *visitado){

    int i, contador = 1;
    for(i = 0; i < grafo->numeroVertices; i++){
        visitado[i] = 0;
    }
    BuscaProfundidade(grafo, inicial, visitado, contador);

}

void BuscaLarguraGrafoLista(GrafoLista *grafo, int inicial, int *visitado){

    int i, vertice, numeroVertices, contador = 1, *fila, inicioFila = 0, finalFila = 0;

    for(i = 0; i < grafo->numeroVertices; i++){
        visitado[i] = 0;
    }
    numeroVertices = grafo->numeroVertices;
    fila = (int*) calloc(numeroVertices, sizeof(int));
    finalFila++;
    fila[finalFila] = inicial;
    visitado[inicial] = contador;
    while(inicioFila != finalFila){
        inicioFila = (inicioFila + 1) % numeroVertices;
        vertice = fila[inicioFila];
        contador++;
        for(i = 0; i < grafo->grau[vertice]; i++){
            if(!visitado[grafo->arestas[vertice][i]]){
                finalFila = (finalFila + 1) % numeroVertices;
                fila[finalFila] = grafo->arestas[vertice][i];
                visitado[grafo->arestas[vertice][i]] = contador;
            }
        }
    }
    free(fila);
}

int ProcuraMenorDistancia(float distancia[], int *visitado, int numeroVertices){

    int i, menor = -1, primeiro = 1;
    for(i = 0; i < numeroVertices; i++){
        if(distancia[i] >= 0 && visitado[i] == 0){
            if(primeiro){
                menor = i;
                primeiro = 0;
            }else{
                if(distancia[menor] > distancia[i]){
                    menor = i;
                }
            }
        }
    }
    return menor;
}

void BuscaMenorCaminhoGrafoLista(GrafoLista *grafo, int inicial, int *anterior, float *distancia){

    int i, contador, numeroVertices, indice, *visitado, verticeRetorno;
    contador = numeroVertices = grafo->numeroVertices;
    visitado = (int*) calloc(numeroVertices, sizeof(int));
    for(i = 0; i < numeroVertices; i++){
        anterior[i] = -1;
        distancia[i] = -1;
        visitado[i] = 0;
    }
    distancia[inicial] = 0;
    while(contador > 0){
        verticeRetorno = ProcuraMenorDistancia(distancia, visitado, numeroVertices);
        if(verticeRetorno == -1){
            break;
        }
        visitado[verticeRetorno] = 1;
        contador--;

        for(i = 0; i < grafo->grau[verticeRetorno]; i++){
            indice = grafo->arestas[verticeRetorno][i];
            if(distancia[indice] < 0){
                distancia[indice] = distancia[verticeRetorno] + 1;
                anterior[indice] = verticeRetorno;
            }else{
                if(distancia[indice] > distancia[verticeRetorno] + 1){
                    distancia[indice] = distancia[verticeRetorno] + 1;
                    anterior[indice] = verticeRetorno;
                }
            }
        }
    }
    printf("Indice de visita aos vertices anteriores ao vertice procurado e a distancia de cada um deles: \n");
    for(int i = 0; i < grafo->numeroVertices; i++){
        printf("anterior[%i] : %i \n", i, anterior[i]);
    }
    printf("-------------------------------------- \n");
    for(int i = 0; i < grafo->numeroVertices; i++){
        printf("distancia[%i] : %.2f \n", i, distancia[i]);
    }
    free(visitado);
}
