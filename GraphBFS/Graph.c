/****************************************************************************************
* List.c
* Aryan Samuel
* arsamuel
* CMPS 101
* 11/7/16
* Programming Assignment 4
* Graph ADT that is implemented by FindPath.c. Performs basic operations such as
* creating, deleting, and modifying graphs and their elements.
*****************************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include "Graph.h"

// Constant macros
#define NIL -1
#define INF -2
#define WHITE 1
#define GRAY 2
#define BLACK 3

// Structs ---------------------------------------------------------------------------
// private GraphObj type
typedef struct GraphObj {
	List* adj;
	int* color;
	int* parent;
	int* dist;
	int order;
	int size;
	int source;
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
	G->dist = calloc(n+1, sizeof(int));
	G->order = n;
	G->size = 0;
	G->source = NIL;
	for (int i=0; i<=n; i++) {
		G->adj[i] = newList();
		G->color[i] = WHITE;
		G->parent[i] = NIL;
		G->dist[i] = INF;
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
	free(G->dist);
	free(*pG);
	*pG = NULL;
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

// getSource()
// Returns the source vertex most recently used in BFS(), or NIL if BFS was not called.
int getSource(Graph G) {
	if (G == NULL) {
		printf("Graph Error: calling getSource() on NULL Graph reference\n");
		exit(1);
	}
	return G->source;
}

// getParent()
// Return the parent of vertex u in tree created by BFS, or NIL if BFS was not called.
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

// getDist()
// Returns the distance from the most recent BFS source to vertex u,
// or INF if BFS was not called.
// pre: 1 <= u <= getOrder(G)
int getDist(Graph G, int u) {
	if (G == NULL) {
		printf("Graph Error: calling getDist() on NULL Graph reference\n");
		exit(1);
	}
	if (u < 1 || u > getOrder(G)) {
		printf("Graph Error: calling getDist() on out of bounds vertex\n");
		exit(1);
	}
	
	return G->dist[u];
}

// getPath()
// Appends to List L the vertices of a shortest path in G from source to u,
// or appends to L the value NIL if no such path exists.
// pre: 1<=u<=getOrder(G), getSource(G)!=NIL
void getPath(List L, Graph G, int u) {
	if (G == NULL) {
		printf("Graph Error: calling getPath() on NULL Graph reference\n");
		exit(1);
	}
	if (u < 1 || u > getOrder(G)) {
		printf("Graph Error: calling getPath() on out of bounds vertex\n");
		exit(1);
	}
	if (getSource(G) == NIL) {
		printf("Graph Error: calling getPath() with NIL source\n");
		exit(1);
	}
	
	if (u == G->source) {
		prepend(L, G->source);
	} else if (G->parent[u] == NIL) {
		prepend(L, NIL);
	} else {
		prepend(L, u);
		getPath(L, G, G->parent[u]);
	}
}


// Manipulation procedures ------------------------------------------------------------

// makeNull()
// Deletes all edges of G, restoring G to original state.
void makeNull(Graph G) {
	if (G == NULL) {
		printf("Graph Error: calling makeNull() on NULL Graph reference\n");
		exit(1);
	}
	
	for (int i=0; i<=getOrder(G); i++) {
		clear(G->adj[i]);
	}
}

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

// BFS()
// Runs the BFS algorithm on the graph G with source s, setting the color, distance,
// parent, and source fields of G accordingly.
void BFS(Graph G, int s) {
	if (G == NULL) {
		printf("Graph Error: calling BFS() on NULL Graph reference\n");
		exit(1);
	}

	for (int i=0; i<=G->order; i++) {
		G->color[i] = WHITE;
		G->parent[i] = NIL;
		G->dist[i] = INF;
	}
	
	G->source = s;
	G->color[s] = GRAY;
	G->dist[s] = 0;
	
	List Q = newList();
	prepend(Q, s);
	
	while (length(Q) > 0) {
		int x = back(Q);
		deleteBack(Q);
		List A = G->adj[x];
		moveFront(A);
		while (index(A) > -1) {
			int u = get(A);
			if (G->color[u] == WHITE) {
				G->color[u] = GRAY;
				G->parent[u] = x;
				G->dist[u] = G->dist[x] + 1;
				prepend(Q, u);
			}
			moveNext(A);
		}
	}
	
	freeList(&Q);
}


// Other Operations -------------------------------------------------------------------

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