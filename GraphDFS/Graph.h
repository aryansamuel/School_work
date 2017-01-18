/****************************************************************************************
* Graph.h
* Aryan Samuel
* arsamuel
* CMPS 101
* 11/23/16
* Programming Assignment 5
* Header file for the Graph ADT.
*****************************************************************************************/

#ifndef _GRAPH_H_INCLUDE_
#define _GRAPH_H_INCLUDE_

#include "List.h"
#define NIL 0
#define UNDEF -1

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

// getParent()
// Return the parent of vertex u in tree created by DFS, or NIL if BFS was not called.
// pre: 1 <= u <= getOrder(G)
int getParent(Graph G, int u);

// getDiscover()
// Returns the discover time of vertex u in tree created by DFS, 
// or UNDEF if DFS was not called.
// pre: 1 <= u <= getOrder(G)
int getDiscover(Graph G, int u);

// getFinish()
// Returns the finish time of vertex u in tree created by DFS, 
// or UNDEF if DFS was not called.
// pre: 1 <= u <= getOrder(G)
int getFinish(Graph G, int u);


// Manipulation procedures ------------------------------------------------------------

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

// DFS()
// Runs the DFS algorithm on the graph G, with List S defining the order in which
// vertices will be processed, and storing the vertices in order of decreasing
// finish times once DFS is complete.
// pre: length(S) == getOrder(G)
void DFS(Graph G, List S);


// Other Operations -------------------------------------------------------------------

// transpose()
// Returns a reference to a new graph object representing the transpose of G.
Graph transpose(Graph G);

// copyGraph()
// Returns a reference to a new graph which is a copy og G.
Graph copyGraph(Graph G);

// printGraph()
// Prints the adjacency list representation of G to the file pointed to by out.
void printGraph(FILE* out, Graph G);


#endif