#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"

int main(void) {

	Graph* mygraph = (Graph*)malloc(sizeof(Graph));
	mygraph = AdjMatrix(8, 7);
	mygraph = insert(mygraph, 0, 1);
	mygraph = insert(mygraph, 1, 2);
	mygraph = insert(mygraph, 2, 3);
	mygraph = insert(mygraph, 4, 5);
	mygraph = insert(mygraph, 4, 6);
	mygraph = insert(mygraph, 4, 7);
	//mygraph = insert(mygraph, 1, 4);

	print_adj_mat(mygraph);

	for (int i = 0; i < mygraph->V; i++) {
		if (!Visited[i]) DFS(mygraph, i);
	}

	return 0;
}