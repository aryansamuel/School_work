/****************************************************************************************
* GraphTest.c
* Aryan Samuel
* arsamuel
* CMPS 101
* 11/23/16
* Programming Assignment 5
* Test client for the Graph ADT.
*****************************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include"Graph.h"

int main(int argc, char* argv[]) {
	
	int n=15;
	Graph G = NULL;
	List S = newList();
	
	G = newGraph(n);
	for(int i=1; i<n; i++){
		if( i%2!=0 ) addEdge(G, i, i+1);
		if( i<=12 ) addEdge(G, i, i+3);
	}
	for (int i=1; i<=n; i++) {
		append(S, i);
	}
   
	addArc(G, 10, 14);
	printGraph(stdout, G);
	printf("The size of G is %d\n", getSize(G));
	printf("The order of G is %d\n\n", getOrder(G));
	Graph T = transpose(G);
	Graph C = copyGraph(G);
	printf("The transpose of G is:\n\n");
	printGraph(stdout, T);
	printf("The copied graph of G is:\n\n");
	printGraph(stdout, C);
	
	DFS(G, S);
	printf("The parent of 10 is %d\n\n", getParent(G, 10));
	printf("The discover time of 10 is %d\n\n", getDiscover(G, 10));
	printf("The finish time of 10 is %d\n", getFinish(G, 10));
	
	
	freeList(&S);
	freeGraph(&G);
	freeGraph(&T);
	freeGraph(&C);
	
	return(0);
}