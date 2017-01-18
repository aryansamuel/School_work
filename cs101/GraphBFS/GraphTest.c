/****************************************************************************************
* List.c
* Aryan Samuel
* arsamuel
* CMPS 101
* 11/7/16
* Programming Assignment 4
* Test client for the Graph ADT.
*****************************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include"Graph.h"

int main(int argc, char* argv[]) {
	
	int n=15;
	List A = newList();
	Graph G = NULL;
	
	G = newGraph(n);
	for(int i=1; i<n; i++){
		if( i%2!=0 ) addEdge(G, i, i+1);
		if( i<=12 ) addEdge(G, i, i+3);
	}
   
	addArc(G, 10, 14);
	printGraph(stdout, G);
	printf("%d\n", getSize(G));
	printf("%d\n", getOrder(G));
	printf("%d\n", getSource(G));
	printf("%d\n\n", getDist(G, 5));
	
	BFS(G, 2);
	printf("%d\n", getParent(G, 10));
	printf("%d\n", getDist(G,10));
	getPath(A, G, 10);
	printList(stdout, A);
	printf("\n\n");
	
	makeNull(G);
	printGraph(stdout, G);
	freeList(&A);
	freeGraph(&G);
	
	return(0);
}