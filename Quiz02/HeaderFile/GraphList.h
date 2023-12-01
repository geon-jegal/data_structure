#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 50

// 큐의 구조체 정의
typedef struct {
	int data[MAX_VERTICES];
	int front, rear;
} QueueType;

// 그래프의 노드를 나타내는 구조체 정의
typedef struct GraphNode {
	int vertex;
	struct GraphNode* link;
} GraphNode;

// 그래프의 정보를 담는 구조체 정의
typedef struct GraphType {
	int n; // 정점의 개수
	GraphNode* adj_list[MAX_VERTICES];
} GraphType;

bool visited[MAX_VERTICES];  // 정점 방문 여부를 저장하는 전역 배열

// 큐 초기화 함수
void init(QueueType* q) {
	q->front = q->rear = -1;
}

// 큐가 비어 있는지 확인하는 함수
bool is_empty(QueueType* q) {
	return q->front == -1;
}

// 큐에 원소를 삽입하는 함수
void enqueue(QueueType* q, int value) {
	if (q->rear == MAX_VERTICES - 1) {
		fprintf(stderr, "큐 오버플로우\n");
		exit(EXIT_FAILURE);
	}
	q->data[++q->rear] = value;
	if (q->front == -1) {
		q->front = 0;
	}
}

// 큐에서 원소를 추출하는 함수
int dequeue(QueueType* q) {
	if (is_empty(q)) {
		fprintf(stderr, "큐 언더플로우\n");
		exit(EXIT_FAILURE);
	}
	// 여기서 원소를 추출하고 front를 증가시킴
	int value = q->data[q->front++];
	// 만약 큐가 비어있다면 front와 rear을 초기화
	if (q->front > q->rear) {
		q->front = q->rear = -1;
	}
	return value;
}

// 그래프 초기화
void init(GraphType* g) {
	int v;
	g->n = 0;
	for (v = 0; v < MAX_VERTICES; v++) g->adj_list[v] = NULL;
}

// 정점 삽입 연산
void insert_vertex(GraphType* g, int v) {
	if (((g->n) + 1) > MAX_VERTICES) {
		fprintf(stderr, "그래프: 정점의 개수 초과");
		return;
	}
	g->n++;
}

//간접 삽입연산, v를 u의 인접 리스트에 삽입한다
void insert_edge(GraphType* g, int u, int v) {
	GraphNode* node;
	if (u >= g->n || v >= g->n) {
		fprintf(stderr, "그래프: 정점 번호 오류");
		return;
	}
	node = (GraphNode*)malloc(sizeof(GraphNode));
	node->vertex = v;
	node->link = g->adj_list[u];
	g->adj_list[u] = node;
}

void print_adj_list(GraphType* g) {
	for (int i = 0; i < g->link; i++) {
		GraphNode* p = g->adj_list[i];
		prinf("정점 %d의 인접 리스트", i);
		while (p != NULL) {
			printf("-> %d ", p->vertex);
			p = p->link;
		}
		printf("\n");
	}
}

// 깊이 우선 탐색
void dfs_list(GraphType* g, int v) {
	GraphNode* w;
	visited[v] = true;
	printf("정점 %d -> ", v);
	for (w = g->adj_list[v]; w; w = w->link)
		if (!visited[w->vertex])
			dfs_list(g, w->vertex);
}

void bfs_list(GraphType* g, int v) {
	GraphNode* w;
	QueueType q;

	init(&q);
	visited[v] = true;
	printf("%d 방문 -> ", v);
	enqueue(&q, v);
	while (!is_empty(&q)) {
		v = dequeue(&q);
		for (w = g->adj_list[v]; w; w = w->link) {
			visited[w->vertex] = true;
			printf("%d 방분 -> ", w->vertex);
			enqueue(&q, w->vertex);
		}
	}
}