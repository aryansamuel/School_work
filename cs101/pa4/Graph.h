/****************************************************************************************
* List.c
* Aryan Samuel
* arsamuel
* CMPS 101
* 11/7/16
* Programming Assignment 4
* Header file for the Graph ADT.
*****************************************************************************************/

#ifndef _GRAPH_H_INCLUDE_
#define _GRAPH_H_INCLUDE_

#include "List.h"
#define NIL -1
#define INF -2

// Exported Type ----------------------------------------------------------------------
typedef struct GraphObj* Graph;


// Constructors-Destructors -----------------------------------------------------------

// newGraph()
// Returns a reference to a new empty Graph object.
Graph newGraph(int n);

// freeGraph()
// Frees all heap memory associated with Graph *pG, and set *pG to NULL.
void freeGraph(Graph* pG);


// Access functions -------------------------------------------------------------------

// getOrder()
// Returns the number of vertices in the graph.
int getOrder(Graph G);

// getSize()
// Returns the size of the graph.
int getSize(Graph G);

// getSource()
// Returns the source vertex most recently used in BFS(), or NIL if BFS was not called.
int getSource(Graph G);

// getParent()
// Return the parent of vertex u in tree created by BFS, or NIL if BFS was not called.
// pre: 1 <= u <= getOrder(G)
int getParent(Graph G, int u);

// getDist()
// Returns the distance from the most recent BFS source to vertex u,
// or INF if BFS was not called.
// pre: 1 <= u <= getOrder(G)
int getDist(Graph G, int u);

// getPath()
// Appends to List L the vertices of a shortest path in G from source to u,
// or appends to L the value NIL if no such path exists.
// pre: 1<=u<=getOrder(G), getSource(G)!=NIL
void getPath(List L, Graph G, int u);


// Manipulation procedures ------------------------------------------------------------

// makeNull()
// Deletes all edges of G, restoring G to original state.
void makeNull(Graph G);

// addEdge()
// Inserts a new edge joining u to v, i.e. u is added to the adjacency List of v,
// and v to the adjacency List of u.
// pre: 1<=u<=getOrder(G), 1<=v<=getOrder(G)
void addEdge(Graph G, int u, int v);

// addArc()
// Inserts a new directed edge from u to v, i.e. v is added to the adjacency List
// of u, but not u to the adjacency List of v.
// pre: 1<=u<=getOrder(G), 1<=v<=getOrder(G)
void addArc(Graph G, int u, int v);

// BFS()
// Runs the BFS algorithm on the graph G with source s, setting the color, distance,
// parent, and source fields of G accordingly.
void BFS(Graph G, int s);


// Other Operations -------------------------------------------------------------------

// printGraph()
// Prints the adjacency list representation of G to the file pointed to by out.
void printGraph(FILE* out, Graph G);


#endif