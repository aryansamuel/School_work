/****************************************************************************************
* FindComponents.c
* Aryan Samuel
* arsamuel
* CMPS 101
* 11/23/16
* Programming Assignment 5
* Takes in values (from input file) to create a Graph, and then prints (to output file)
* it, along with its strongly connected components.
*****************************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "Graph.h"

#define MAX_LEN 160

int main (int argc, char* argv[]) {
	
	FILE *in, *out;
	char line[MAX_LEN];
	int n, u, v, sc = 0;
	Graph G = NULL;
	
	// Error Check
	if (argc != 3) {
		printf("Usage: FindPath <input file> <output file>\n");
		exit(1);
	}
	
	// Open files
	in = fopen(argv[1], "r");
	out = fopen(argv[2], "w");
	if (in == NULL) {
		printf("File Error: unable to open file %s for reading\n", argv[1]);
		exit(1);
	}
	if (out == NULL) {
		printf("File error: unable to open file %s for writing\n", argv[2]);
		exit(1);
	}
	
	// Read n and declare G order
	fgets(line, MAX_LEN, in);
	n = atoi(line);
	G = newGraph(n);
	fclose(in); // Reopen file
	in = fopen(argv[1], "r");
	
	// Declare edges and vertices of G, then print G
	while (fgets(line, MAX_LEN, in) != NULL) {
		fscanf(in, "%d", &u);
		fscanf(in, "%d", &v);
		if (u == 0 || v == 0) break;
		addArc(G, u, v);
	}
	
	fprintf(out, "Adjacency list representation of G:\n");
	printGraph(out, G);
	fprintf(out, "\n");
	
	// List for DFS
	List S = newList();
	for (int i=1; i<=n; i++) { //allocate sufficient space
		append(S, i);
	}
	
	// Perform DFS on G and transpose of G to find # of scc's
	DFS(G, S);
	Graph T = transpose(G);
	DFS(T, S);
	moveFront(S);
	while (index(S) >= 0) { //
		if (getParent(T, get(S)) == NIL) { //get # of scc's
			sc++;
		}
		moveNext(S);
	}
	
	// Create list array for lists of scc's
	List Lsc[sc];
	for (int i=0; i<sc; i++) {
		Lsc[i] = newList();
	}
	
	// Add the scc's to a list array
	moveFront(S);
	int x = sc;
	while (index(S) >= 0) {
		if (getParent(T, get(S)) == NIL) { //Once there are no more parents in the list
			x--; //Change the list array the scc's are being added to
		} if (x == sc) {
			break;
		}
		append(Lsc[x], get(S)); //Add scc to list
		moveNext(S);
	}
	
	// Print scc's
	fprintf(out, "G contains %d strongly connected components:\n", sc);
	for (int i=1; i<=sc; i++) {
		fprintf(out, "Component %d: ", i);
		printList(out, Lsc[i-1]);
		freeList(&Lsc[i-1]);
		fprintf(out, "\n");
	}
	
	
	// Free memory and Close files
	freeGraph(&G);
	freeGraph(&T);
	freeList(&S);
	fclose(in);
	fclose(out);
	
	return(0);
}