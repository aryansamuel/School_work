/****************************************************************************************
* Graph.c
* Aryan Samuel
* arsamuel
* CMPS 101
* 11/23/16
* Programming Assignment 5
* Graph ADT that is implemented by FindComponents.c. Performs basic operations such as
* creating, deleting, and modifying graphs and their elements.
*****************************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include "Graph.h"

// Constant macros
#define NIL 0
#define UNDEF -1
#define WHITE 1
#define GRAY 2
#define BLACK 3

// Structs ---------------------------------------------------------------------------
// private GraphObj type
typedef struct GraphObj {
	List* adj;
	int* color;
	int* parent;
	int* discover;
	int* finish;
	int order;
	int size;
} GraphObj;


// Constructors-Destructors -----------------------------------------------------------

// newGraph()
// Returns a reference to a new empty Graph object.
Graph newGraph(int n) {
	Graph G;
	G = malloc(sizeof(GraphObj));
	G->adj = calloc(n+1, sizeof(List));
	G->color = calloc(n+1, sizeof(int));
	G->parent = calloc(n+1, sizeof(int));
	G->discover = calloc(n+1, sizeof(int));
	G->finish = calloc(n+1, sizeof(int));
	G->order = n;
	G->size = 0;
	for (int i=0; i<=n; i++) {
		G->adj[i] = newList();
		G->color[i] = WHITE;
		G->parent[i] = NIL;
		G->discover[i] = UNDEF;
		G->finish[i] = UNDEF;
	}
	return G;
}

// freeGraph()
// Frees all heap memory associated with Graph *pG, and set *pG to NULL.
void freeGraph(Graph* pG) {
	Graph G = *pG;
	for (int i=0; i <= G->order; i++) {
		freeList(&(G->adj[i]));
	}
	free(G->adj);
	free(G->color);
	free(G->parent);
	free(G->discover);
	free(G->finish);
	free(*pG);
	*pG = NULL;
}


// Private helper functions -----------------------------------------------------------

// Visit()
// Recursive algorithm called by DFS() to check the visit status.
void Visit(Graph G, List S, int u, int* time) {
	G->color[u] = GRAY;
	G->discover[u] = ++*time;
	moveFront(G->adj[u]);
	while (index(G->adj[u]) >= 0) {
		int y = get(G->adj[u]);
		if (G->color[y] == WHITE) {
			G->parent[y] = u;
			Visit(G, S, y, time);
		}
		moveNext(G->adj[u]);
	}
	
	G->color[u] = BLACK;
	G->finish[u] = ++*time;
	prepend(S, u); // Put new element at front of S
}


// Access functions -------------------------------------------------------------------

// getOrder()
// Returns the number of vertices in the graph.
int getOrder(Graph G) {
	if (G == NULL) {
		printf("Graph Error: calling getOrder() on NULL Graph reference\n");
		exit(1);
	}
	return G->order;
}

// getSize()
// Returns the size of the graph.
int getSize(Graph G) {
	if (G == NULL) {
		printf("Graph Error: calling getSize() on NULL Graph reference\n");
		exit(1);
	}
	return G->size;
}

// getParent()
// Return the parent of vertex u in tree created by DFS, or NIL if DFS was not called.
// pre: 1 <= u <= getOrder(G)
int getParent(Graph G, int u) {
	if (G == NULL) {
		printf("Graph Error: calling getParent() on NULL Graph reference\n");
		exit(1);
	}
	if (u < 1 || u > getOrder(G)) {
		printf("Graph Error: calling getParent() on out of bounds vertex\n");
		exit(1);
	}
	
	return G->parent[u];
}

// getDiscover()
// Returns the discover time of vertex u in tree created by DFS, 
// or UNDEF if DFS was not called.
// pre: 1 <= u <= getOrder(G)
int getDiscover(Graph G, int u) {
	if (G == NULL) {
		printf("Graph Error: calling getDiscover() on NULL Graph reference\n");
		exit(1);
	}
	if (u < 1 || u > getOrder(G)) {
		printf("Graph Error: calling getDiscover() on out of bounds vertex\n");
		exit(1);
	}
	
	return G->discover[u];
}

// getFinish()
// Returns the finish time of vertex u in tree created by DFS, 
// or UNDEF if DFS was not called.
// pre: 1 <= u <= getOrder(G)
int getFinish(Graph G, int u) {
	if (G == NULL) {
		printf("Graph Error: calling getFinish() on NULL Graph reference\n");
		exit(1);
	}
	if (u < 1 || u > getOrder(G)) {
		printf("Graph Error: calling getFinish() on out of bounds vertex\n");
		exit(1);
	}
	
	return G->finish[u];
}


// Manipulation procedures ------------------------------------------------------------

// addEdge()
// Inserts a new edge joining u to v, i.e. u is added to the adjacency List of v,
// and v to the adjacency List of u.
// pre: 1<=u<=getOrder(G), 1<=v<=getOrder(G)
void addEdge(Graph G, int u, int v) {
	if (G == NULL) {
		printf("Graph Error: calling addEdge() on NULL Graph reference\n");
		exit(1);
	}
	if ( u<1 || u>getOrder(G) || v<1 || v>getOrder(G) ) {
		printf("Graph Error: calling addEdge() on out of bounds vertex\n");
		exit(1);
	}
	
	addArc(G, u, v);
	addArc(G, v, u);
	
	G->size--; // Since calling addArc() twice adds 2 to size, we want 1.
}

// addArc()
// Inserts a new directed edge from u to v, i.e. v is added to the adjacency List
// of u, but not u to the adjacency List of v.
// pre: 1<=u<=getOrder(G), 1<=v<=getOrder(G)
void addArc(Graph G, int u, int v) {
	if (G == NULL) {
		printf("Graph Error: calling addArc() on NULL Graph reference\n");
		exit(1);
	}
	if ( u<1 || u>getOrder(G) || v<1 || v>getOrder(G) ) {
		printf("Graph Error: calling addEdge() on out of bounds vertex\n");
		exit(1);
	}
	
	List L = G->adj[u];
	moveFront(L);
	while (index(L)>-1 && v>get(L)) {
		moveNext(L);
	}
	if (index(L) == -1) {
		append(L, v);
	} else {
		insertBefore(L, v);
	}
	
	G->size++;
}

// DFS()
// Runs the DFS algorithm on the graph G, with List S defining the order in which
// vertices will be processed, and storing the vertices in order of decreasing
// finish times once DFS is complete.
// pre: length(S) == getOrder(G)
void DFS(Graph G, List S) {
	if (G == NULL) {
		printf("Graph Error: calling addArc() on NULL Graph reference\n");
		exit(1);
	}
	if (length(S) != getOrder(G)) {
		printf("Graph Error: calling DFS() on irregular sizes\n");
		exit(1);
	}
	
	for (int i=0; i<=getOrder(G); i++) {
		G->color[i] = WHITE;
		G->parent[i] = NIL;
		G->discover[i] = UNDEF;
		G->finish[i] = UNDEF;
	}
	
	int time = 0;
	moveFront(S);
	while (index(S) >= 0) {
		int u = get(S);
		if (G->color[u] == WHITE) {
			Visit(G, S, u, &time);
		}
		moveNext(S);
	}
	
	// Remove old elements from the back in S
	for (int i=length(S)/2; i>0; i--) {
		deleteBack(S);
	}
	
}


// Other Operations -------------------------------------------------------------------

// transpose()
// Returns a reference to a new graph object representing the transpose of G.
Graph transpose(Graph G) {
	Graph N = newGraph(getOrder(G));
	for (int i=0; i<=getOrder(G); i++) {
		moveFront(G->adj[i]);
		while (index(G->adj[i]) >= 0) {
			addArc(N, get(G->adj[i]), i);
			moveNext(G->adj[i]);
		}
	}
	
	return N;
}

// copyGraph()
// Returns a reference to a new graph which is a copy og G.
Graph copyGraph(Graph G) {
	Graph N = newGraph(getOrder(G));
	for (int i=0; i<=getOrder(G); i++) {
		moveFront(G->adj[i]);
		while (index(G->adj[i]) >= 0) {
			addArc(N, i, get(G->adj[i]));
			moveNext(G->adj[i]);
		}
	}
	
	return N;
}

// printGraph()
// Prints the adjacency list representation of G to the file pointed to by out.
void printGraph(FILE* out, Graph G) {
	if (G == NULL) {
		printf("Graph Error: calling printGraph() on NULL Graph reference\n");
		exit(1);
	}
	
	for (int i=1; i<=getOrder(G); i++) {
		fprintf(out, "%d: ", i);
		printList(out, G->adj[i]);
		fprintf(out, "\n");
	}
}