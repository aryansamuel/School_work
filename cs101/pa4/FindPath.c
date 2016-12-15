/****************************************************************************************
* List.c
* Aryan Samuel
* arsamuel
* CMPS 101
* 11/7/16
* Programming Assignment 4
* Takes in values (from input file) to create a Graph, and then prints (to output file)
* it, along with the distances and paths from specific sources to destinations.
*****************************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "Graph.h"

#define MAX_LEN 160

int main (int argc, char* argv[]) {
	
	FILE *in, *out;
	char line[MAX_LEN];
	int n, u, v;
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
		addEdge(G, u, v);
	}
	
	printGraph(out, G);
	
	// Declare sources and destinations
	while (fgets(line, MAX_LEN, in) != NULL) {
		fscanf(in, "%d", &u);
		fscanf(in, "%d", &v);
		if (u == 0 || v == 0) break;
		fprintf(out, "\n");
		BFS(G, u);
		int d = getDist(G, v);
		if (d == INF) {
			fprintf(out, "The distance from %d to %d is infinity\n", u, v);
		} else {
			fprintf(out, "The distance from %d to %d is %d\n", u, v, d);
		}
		List P = newList();
		getPath(P, G, v);
		if (front(P) == NIL) {
			fprintf(out, "No %d-%d path exists", u, v);
			fprintf(out, "\n");
		} else {
			fprintf(out, "A shortest %d-%d path is: ", u, v);
			printList(out, P);
			fprintf(out, "\n");
		}
		freeList(&P);
	}
	
	
	// Free memory and Close files
	freeGraph(&G);
	fclose(in);
	fclose(out);
	
	return(0);
}