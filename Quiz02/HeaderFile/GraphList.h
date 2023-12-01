#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 50

// ť�� ����ü ����
typedef struct {
	int data[MAX_VERTICES];
	int front, rear;
} QueueType;

// �׷����� ��带 ��Ÿ���� ����ü ����
typedef struct GraphNode {
	int vertex;
	struct GraphNode* link;
} GraphNode;

// �׷����� ������ ��� ����ü ����
typedef struct GraphType {
	int n; // ������ ����
	GraphNode* adj_list[MAX_VERTICES];
} GraphType;

bool visited[MAX_VERTICES];  // ���� �湮 ���θ� �����ϴ� ���� �迭

// ť �ʱ�ȭ �Լ�
void init(QueueType* q) {
	q->front = q->rear = -1;
}

// ť�� ��� �ִ��� Ȯ���ϴ� �Լ�
bool is_empty(QueueType* q) {
	return q->front == -1;
}

// ť�� ���Ҹ� �����ϴ� �Լ�
void enqueue(QueueType* q, int value) {
	if (q->rear == MAX_VERTICES - 1) {
		fprintf(stderr, "ť �����÷ο�\n");
		exit(EXIT_FAILURE);
	}
	q->data[++q->rear] = value;
	if (q->front == -1) {
		q->front = 0;
	}
}

// ť���� ���Ҹ� �����ϴ� �Լ�
int dequeue(QueueType* q) {
	if (is_empty(q)) {
		fprintf(stderr, "ť ����÷ο�\n");
		exit(EXIT_FAILURE);
	}
	// ���⼭ ���Ҹ� �����ϰ� front�� ������Ŵ
	int value = q->data[q->front++];
	// ���� ť�� ����ִٸ� front�� rear�� �ʱ�ȭ
	if (q->front > q->rear) {
		q->front = q->rear = -1;
	}
	return value;
}

// �׷��� �ʱ�ȭ
void init(GraphType* g) {
	int v;
	g->n = 0;
	for (v = 0; v < MAX_VERTICES; v++) g->adj_list[v] = NULL;
}

// ���� ���� ����
void insert_vertex(GraphType* g, int v) {
	if (((g->n) + 1) > MAX_VERTICES) {
		fprintf(stderr, "�׷���: ������ ���� �ʰ�");
		return;
	}
	g->n++;
}

//���� ���Կ���, v�� u�� ���� ����Ʈ�� �����Ѵ�
void insert_edge(GraphType* g, int u, int v) {
	GraphNode* node;
	if (u >= g->n || v >= g->n) {
		fprintf(stderr, "�׷���: ���� ��ȣ ����");
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
		prinf("���� %d�� ���� ����Ʈ", i);
		while (p != NULL) {
			printf("-> %d ", p->vertex);
			p = p->link;
		}
		printf("\n");
	}
}

// ���� �켱 Ž��
void dfs_list(GraphType* g, int v) {
	GraphNode* w;
	visited[v] = true;
	printf("���� %d -> ", v);
	for (w = g->adj_list[v]; w; w = w->link)
		if (!visited[w->vertex])
			dfs_list(g, w->vertex);
}

void bfs_list(GraphType* g, int v) {
	GraphNode* w;
	QueueType q;

	init(&q);
	visited[v] = true;
	printf("%d �湮 -> ", v);
	enqueue(&q, v);
	while (!is_empty(&q)) {
		v = dequeue(&q);
		for (w = g->adj_list[v]; w; w = w->link) {
			visited[w->vertex] = true;
			printf("%d ��� -> ", w->vertex);
			enqueue(&q, w->vertex);
		}
	}
}