#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 구조체 정의: 그래프를 나타내는 구조체
typedef struct Graph {
	int V;    // 정점의 수
	int E;    // 간선의 수
	int** Adj; // 인접 행렬
} Graph;

// 그래프를 생성하고 초기화하는 함수
Graph* AdjMatrix(int v, int e) {
	Graph* G = (Graph*)malloc(sizeof(Graph));
	if (!G) {
		printf("Memory Error");
		exit(0);
	}
	G->V = v;
	G->E = e;
	G->Adj = (int**)malloc(sizeof(int*) * G->V);
	for (int i = 0; i < G->V; i++)
		G->Adj[i] = (int*)malloc(sizeof(int) * G->V);
	for (int i = 0; i < G->V; i++)
		for (int j = 0; j < G->V; j++)
			G->Adj[i][j] = 0;
	return G;
}

// 그래프에 방향성 있는 간선을 추가하는 함수
Graph* insert_direct(Graph* G)
{
	int u, v;
	for (int i = 0; i < G->E; i++)
	{
		printf("\n Reading Edge %d (u,v) : ", i + 1);
		scanf("%d %d", &u, &v);
		if (u >= G->V || v >= G->V) {
			printf(" No such vertex!!");
			exit(0);
		}
		G->Adj[u][v] = 1;
		G->Adj[v][u] = 1;
	}
	return G;
}

void deleteMatrix(Graph* G) {
	for (int i = 0; i < G->V; i++)
		free(G->Adj[i]);
	free(G->Adj);
	free(G);
}

void print_adj_mat(Graph* G) {
	if (G->Adj == NULL) {
		printf("No Matrix exist!\n");
		return;
	}
	printf("\n Adjacency Matrix of Direct Graph\n");
	for (int u = 0; u < G->V; u++) {
		for (int v = 0; v < G->V; v++) {
			printf("%2d ", G->Adj[u][v]);
		}
		printf("\n");
	}
}

Graph* randomGraph(Graph* G) {
	srand((unsigned int)time(NULL)); // seed값으로 현재시간 부여
	int V = rand() % 6 + 5; // 랜덤한 값을 생성 (여기서는 5부터 10까지의 값 중에서 랜덤하게 선택)
	int e = rand() % 6 + 5; // 랜덤한 값을 생성 (여기서는 5부터 10까지의 값 중에서 랜덤하게 선택)

	printf("Create Random Graph\nsize(vertices): %d\nsize(Edge): %d\n", V, e);
	G = AdjMatrix(V, e);

	for (int i = 0; i < G->E; i++) {
		int u = rand() % G->V;
		int v = rand() % G->V;
		if (u == v || G->Adj[u][v] == 1) {
			i--; // 유효한 간선을 생성하지 못했으므로 다시 시도
			printf("\n<No Matrix exist!>");
			continue;
		}
		G->Adj[u][v] = 1;
		G->Adj[v][u] = 1;
		printf("\nEdge : %d  %d", u, v);
	}

	return G;
}

int main(void) {

	Graph* g = (Graph*)malloc(sizeof(Graph));
	g = randomGraph(g);

	print_adj_mat(g);

	return 0;
}