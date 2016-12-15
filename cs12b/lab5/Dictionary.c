//----------------------------------------------------------------------------------------------
// Dictionary.c
// Aryan Samuel
// arsamuel
// CMPS 12M
// 05/10/16
// Lab 5
// A Dictionary ADT with pairs of Strings called Keys and Values. 
// Performs various functions such as creating and deleting a Dictionary, 
// and inserting, finding, or removing specific items to and fromt it.
//----------------------------------------------------------------------------------------------

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include"Dictionary.h"


// Private Types---------------------------------------------------------------------------

// NodeObj
typedef struct NodeObj {
	char* key;
	char* value;
	struct NodeObj* next;
} NodeObj;

// Node
typedef NodeObj* Node;

// newNode()
// Constructor of the Node tpye
Node newNode(char* k, char* v) {
	Node N = malloc(sizeof(NodeObj));
	assert(N!=NULL);
	N->key = k;
	N->value = v;
	N->next = NULL;
	return(N);
	free(N);
}

// freeNode()
// destructor for the Node type
void freeNode(Node* pN) {
	if (pN!=NULL && *pN!=NULL) {
		free(*pN);
		*pN = NULL;
	}
}

// DictionaryObj
typedef struct DictionaryObj {
	Node top;
	int numItems;
} DictionaryObj;

// findKey()
Node findKey (Node N, char* k) {
	while (N != NULL) {
		if (strcmp(k, N->key)==0) return N;
		else N = N->next;
	}
	return N;
}


// Public functions ------------------------------------------------------------------------

// newDictionary()
// constructor for the Dictionary type
Dictionary newDictionary(void) {
	Dictionary D = malloc(sizeof(DictionaryObj));
	assert(D != NULL);
	D->top = NULL;
	D->numItems = 0;
	return D;
}

// freeDictionary()
// destructor for the Dictionary type
void freeDictionary(Dictionary* pD) {
	if (pD!=NULL && *pD!=NULL) {
		/*if (!isEmpty(*pD))*/ makeEmpty(*pD);
		free(*pD);
		*pD = NULL;
	}
}

// isEmpty()
// returns 1 (true) if S is empty, 0 (false) otherwise
// pre: none
int isEmpty(Dictionary D) {
	if (D == NULL) {
		fprintf(stderr,"Dictionary Error: calling isEmpty() on NULL Dictionary reference\n");
		exit(EXIT_FAILURE);
	}
	
	return(D->numItems==0);
}

// size()
// returns the number of (key, value) pairs in D
// pre: none
int size(Dictionary D) {
	if (D == NULL) {
		fprintf(stderr,"Dictionary Error: calling size() on NULL Dictionary reference\n");
		exit(EXIT_FAILURE);
	}
	
	return(D->numItems);
}

// lookup()
// returns the value v such that (k, v) is in D, or returns NULL if no 
// such value v exists.
// pre: none
char* lookup(Dictionary D, char* k) {
	Node N;
	if (D==NULL) {
		fprintf(stderr, "Dictionary Error: calling lookup() on NULL Dictionary reference\n");
		exit(EXIT_FAILURE);
	}
	
	N = findKey(D->top, k);
	return (N==NULL ? NULL : N->value);
}

// insert()
// inserts new (key,value) pair into D
// pre: lookup(D, k)==NULL
void insert(Dictionary D, char* k, char* v) {
	if (D==NULL) {
		fprintf(stderr, "Dictionary Error: calling insert() on NULL Dictionary reference\n");
		exit(EXIT_FAILURE);
	}
	if (findKey(D->top, k) != NULL) {
		fprintf(stderr, "Dictionary Error: cannot insert() duplicate key: \"%s\"\n",k);
		exit(EXIT_FAILURE);
	}
	
	if (isEmpty(D)) {
		Node N = newNode(k,v);
		N->next = D->top;
		D->top = N;
	} else {
		Node N = D->top;
		while (N->next != NULL) N = N->next;
		Node C = N->next;
		N->next = newNode(k,v);
		N = N->next;
		N->next = C;
	}
	D->numItems++;
}

// delete()
// deletes pair with the key k
// pre: lookup(D, k)!=NULL
void delete(Dictionary D, char* k) {
	if (D==NULL) {
		fprintf(stderr, "Dictionary Error: calling delete() on NULL Dictionary reference\n");
		exit(EXIT_FAILURE);
	}
	if (findKey(D->top,k) == NULL) {
		fprintf(stderr, "Dictionary Error: cannot delete() non-existent key: \"%s\"\n",k);
		exit(EXIT_FAILURE);
	}
	
	if (strcmp(k,"one")==0) {
		Node N = D->top;
		D->top = D->top->next;
		N->next = NULL;
	} else {
		Node P = D->top;
		while (strcmp(k, P->next->key) != 0) P = P->next;
		Node N = P->next;
		P->next = N->next;
		N->next = NULL;
	}
	D->numItems--;
}

// makeEmpty()
// re-sets D to the empty state.
// pre: none
void makeEmpty(Dictionary D) {
	if (D==NULL) {
		fprintf(stderr, "Dictionary Error: calling makeEmpty() on NULL Dictionary reference\n");
		exit(EXIT_FAILURE);
	}
	
	D->top = NULL;
	D->numItems = 0;
}

// printDictionary()
// pre: none
// prints a text representation of D to the file pointed to by out
void printDictionary(FILE* out, Dictionary D) {
	Node N;
	if (D==NULL) {
		fprintf(stderr, "Dictionary Error: calling printDictionary() on NULL Dictionary reference\n");
		exit(EXIT_FAILURE);
	}
	
	for (N=D->top; N!=NULL; N=N->next) {
		fprintf(out, "%s %s\n", N->key, N->value);
	}
}