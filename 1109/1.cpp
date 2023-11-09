#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ����ü ����: �׷����� ��Ÿ���� ����ü
typedef struct Graph {
	int V;    // ������ ��
	int E;    // ������ ��
	int** Adj; // ���� ���
} Graph;

// �׷����� �����ϰ� �ʱ�ȭ�ϴ� �Լ�
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

// �׷����� ���⼺ �ִ� ������ �߰��ϴ� �Լ�
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
	srand((unsigned int)time(NULL)); // seed������ ����ð� �ο�
	int V = rand() % 6 + 5; // ������ ���� ���� (���⼭�� 5���� 10������ �� �߿��� �����ϰ� ����)
	int e = rand() % 6 + 5; // ������ ���� ���� (���⼭�� 5���� 10������ �� �߿��� �����ϰ� ����)

	printf("Create Random Graph\nsize(vertices): %d\nsize(Edge): %d\n", V, e);
	G = AdjMatrix(V, e);

	for (int i = 0; i < G->E; i++) {
		int u = rand() % G->V;
		int v = rand() % G->V;
		if (u == v || G->Adj[u][v] == 1) {
			i--; // ��ȿ�� ������ �������� �������Ƿ� �ٽ� �õ�
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