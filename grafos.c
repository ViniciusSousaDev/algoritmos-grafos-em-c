#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int grafo[MAX][MAX];
int visitado[MAX];
int pai[MAX];
int fila[MAX];

int inicioFila = 0, fimFila = 0;

// Função para inserir na fila
void enfileirar(int v) {
    fila[fimFila++] = v;
}

// Função para remover da fila
int desenfileirar() {
    return fila[inicioFila++];
}

// BFS para encontrar caminho entre origem e destino
void bfs(int vertices, int origem) {
    for (int i = 0; i < vertices; i++) {
        visitado[i] = 0;
        pai[i] = -1;
    }

    visitado[origem] = 1;
    enfileirar(origem);

    while (inicioFila < fimFila) {
        int atual = desenfileirar();

        for (int i = 0; i < vertices; i++) {
            if (grafo[atual][i] == 1 && !visitado[i]) {
                visitado[i] = 1;
                pai[i] = atual;
                enfileirar(i);
            }
        }
    }
}

// Função para imprimir o caminho
void imprimirCaminho(int origem, int destino) {
    if (destino == -1) {
        return;
    }
    imprimirCaminho(origem, pai[destino]);
    printf("%d ", destino);
}

int main() {
    int vertices, arestas;
    int origem, destino;

    printf("Digite a quantidade de vertices: ");
    scanf("%d", &vertices);

    // Inicializa o grafo
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            grafo[i][j] = 0;
        }
    }

    printf("Digite a quantidade de ligacoes (arestas): ");
    scanf("%d", &arestas);

    printf("Digite as ligacoes (vertice origem e vertice destino):\n");
    for (int i = 0; i < arestas; i++) {
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        grafo[v1][v2] = 1;
        grafo[v2][v1] = 1; // grafo não direcionado
    }

    printf("Digite o vertice de origem: ");
    scanf("%d", &origem);

    printf("Digite o vertice de destino: ");
    scanf("%d", &destino);

    bfs(vertices, origem);

    if (visitado[destino]) {
        printf("Caminho encontrado:\n");
        imprimirCaminho(origem, destino);
        printf("\n");
    } else {
        printf("Nao existe caminho entre %d e %d\n", origem, destino);
    }

    return 0;
}
