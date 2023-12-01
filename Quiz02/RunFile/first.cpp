/*#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Graph.h"
#include "GraphList.h"
//#include "Hash.h"
//#include "HashList.h"

int main() {
	GraphType* mygraph = (GraphType*)malloc(sizeof(GraphType));
	init(mygraph);

	for(int i = 0; i < 8; i++) insert_vertex(mygraph,i);

	insert_edge(mygraph, 0, 1);
	insert_edge(mygraph, 1, 2);
	insert_edge(mygraph, 1, 7);
	insert_edge(mygraph, 2, 3);
	insert_edge(mygraph, 2, 4);
	insert_edge(mygraph, 4, 5);
	insert_edge(mygraph, 4, 6);
	insert_edge(mygraph, 4, 7);

	print_adj_list(mygraph);


	printf("DFS\n");
	dfs_list(mygraph, 0);


	printf("\nBFS\n");
	bfs_list(mygraph, 0);

	Graph* graph = (Graph*)malloc(sizeof(Graph));
	graph = AdjMatrix(8, 7);
	graph = insert(graph, 0, 1);
	graph = insert(graph, 1, 2);
	graph = insert(graph, 1, 7);
	graph = insert(graph, 2, 3);
	graph = insert(graph, 2, 4);
	graph = insert(graph, 4, 5);
	graph = insert(graph, 4, 6);
	graph = insert(graph, 4, 7);

	print_adj_mat(graph);

	DFS(graph, 0);
	BFS(graph, 0);

	for (int i = 0; i < graph->V; i++) {
		if (!Visited[i]) DFS(graph, i);
	}
	return 0;
}
*/