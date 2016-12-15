/****************************************************************************************
* List.c
* Aryan Samuel
* arsamuel
* CMPS 101
* 11/7/16
* Programming Assignment 4
* List ADT that is implemented by Graph.c. Does basic operations such as 
* inserting and deleting elements, all while moving the "cursor".
*****************************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include "List.h"

//structs-------------------------------------------------------------------------

// private NodeObj type
typedef struct NodeObj {
	int data;
	struct NodeObj* next;
	struct NodeObj* prev;
} NodeObj;

// private Node type
typedef NodeObj* Node;

// private ListObj type
typedef struct ListObj {
	Node front;
	Node back;
	Node cursor;
	int length;
	int index;
} ListObj;


// Constructors-Destructors ------------------------------------------------------

// newNode()
// Returns reference to new Node object. Initializes next and data fields.
// Private
Node newNode(int data) {
	Node N = malloc(sizeof(NodeObj));
	N->data = data;
	N->next = N->prev = NULL;
	return(N);
}

// freeNode()
// Frees heap memory pointed to by *pL, sets *pL to NULL.
// Private.
void freeNode(Node* pN) {
	if (pN!=NULL && *pN!=NULL) {
		free(*pN);
		*pN = NULL;
	}
}

// newList()
// Returns reference to new empty List object.
List newList(void) {
	List L;
	L = malloc(sizeof(ListObj));
	L->front = L->back = NULL;
	L->length = 0;
	L->index = -1;
	return(L);
}

// freeList()
// Frees all heap memory associated with List *pL, and sets *pL to NULL.
void freeList(List* pL) {
	if (pL!=NULL && *pL!=NULL) {
		clear(*pL);
		free(*pL);
		*pL = NULL;
	}
}


// Access Functions -----------------------------------------------------------------

// length()
// returns the number of elements in thei List.
int length(List L) {
	if (L == NULL) {
		printf("List Error: calling length() on NULL List reference\n");
		exit(1);
	}
	return (L->length);
}

// index()
// If cursor is defined, returns index of cursor element. Otherwise returns -1.
int index(List L) {
	if (L == NULL) {
		printf("List Error: calling index() on NULL List reference\n");
		exit(1);
	}
	if (L->cursor != NULL) {
		return (L->index);
	} else return -1;
}

// front()
// Returns front element.
// Pre: length()>0
int front(List L) {
	if (L == NULL) {
		printf("List Error: calling front() on NULL List reference\n");
		exit(1);
	}
	if (L->length <= 0) {
		printf("List Error: calling front() on empty List\n");
		exit(1);
	}
	return (L->front->data);
}
		

// back()
// Returns back element.
// Pre: length()>0
int back(List L) {
	if (L == NULL) {
		printf("List Error: calling back() on NULL List reference\n");
		exit(1);
	}
	if (L->length <= 0) {
		printf("List Error: calling back() on empty List\n");
		exit(1);
	}
	return (L->back->data);
}

// get()
// Returns cursor element.
// Pre: length()>0, index()>=0
int get(List L) {
	if (L == NULL) {
		printf("List Error: calling get() on NULL List reference\n");
		exit(1);
	}
	if (L->length <= 0) {
		printf("List Error: calling get() on empty List\n");
		exit(1);
	}
	return (L->cursor->data);
}

// equals()
// Returns true if this List and L are the same integer
// sequence. The cursor is ignored in both lists.
int equals(List A, List B) {
	if (A==NULL || B==NULL) {
		printf("List Error: calling equals() on NULL List reference\n");
		exit(1);
	}
	int boolean = 0;
	Node N = A->front;
	Node M = B->front;
	
	while (N->next!=NULL && M->next!=NULL) {
		if (N->data == M->data) {
			boolean = 1;
		} else boolean = 0;
		N = N->next;
		M = M->next;
	}
	return boolean;
}


// Manipulation Procedures ---------------------------------------------------------

// clear()
// Resets this List to its original empty state
void clear(List L) {
	if (L == NULL) {
		printf("List Error: calling clear() on NULL List reference\n");
		exit(1);
	}
	Node N = L->front;
	Node M = NULL;
	while (N != NULL) {
		M = N->next;
		freeNode(&N);
		N = M;
	}
	L->front = L->back = NULL;
	L->length = 0;
	L->index = -1;
}

// moveFront()
// If list is non-empty, places cursor under front element, otherwise does nothing.
void moveFront(List L) {
	if (L == NULL) {
		printf("List Error: calling moveFront() on NULL List reference\n");
		exit(1);
	}
	if (L->length > 0) {
		L->cursor = L->front;
		L->index = 0;
	}
}

// moveBack()
// If list is non-empty, places cursor under back element, otherwise does nothing.
void moveBack(List L) {
	if (L == NULL) {
		printf("List Error: calling moveBack() on NULL List reference\n");
		exit(1);
	}
	if (L->length > 0) {
		L->cursor = L->back;
		L->index = L->length - 1;
	}
}

// movePrev()
// If cursor is defined and not at front, moves cursor one step toward
// front of this List, if cursor is defined and at front, cursor becomes
// undefined, if cursor is undefined does nothing.
void movePrev(List L) {
	if (L == NULL) {
		printf("List Error: calling movePrev() on NULL List reference\n");
		exit(1);
	}
	if (L->cursor!=NULL && L->cursor!=L->front) {
		L->cursor = L->cursor->prev;
		L->index--;
	} else if (L->cursor!=NULL && L->cursor==L->front) {
		L->cursor = NULL;
		L->index = -1;
	}
}

// moveNext()
// If cursor is defined and not at back, moves cursor one step toward
// back of this List, if cursor is defined and at back, cursor becomes
// undefined, if cursor is undefined does nothing.
void moveNext(List L) {
	if (L == NULL) {
		printf("List Error: calling moveNext() on NULL List reference\n");
		exit(1);
	}
	if (L->cursor!=NULL && L->cursor!=L->back) {
		L->cursor = L->cursor->next;
		L->index++;
	} else if (L->cursor!=NULL && L->cursor==L->back) {
		L->cursor = NULL;
		L->index = -1;
	}
}

// prepend()
// Insert new element into this List. If List is non-empty,
// insertion takes place before front element.
void prepend(List L, int data) {
	if (L == NULL) {
		printf("List Error: calling prepend() on NULL List reference\n");
		exit(1);
	}
	Node N = newNode(data);
	
	if (L->length <= 0) {
		L->front = L->back = N;
	} else {
		L->front->prev = N;
		N->next = L->front;
		L->front = N;
	}
	
	L->length++;
}

// append()
// Insert new element into this list. If List is non-empty,
// inswertion takes place after back element.
void append(List L, int data) {
	if (L == NULL) {
		printf("List Error: calling append() on NULL List reference\n");
		exit(1);
	}
	Node N = newNode(data);
	
	if (L->length <= 0) {
		L->front = L->back = N;
	} else {
		L->back->next = N;
		N->prev = L->back;
		L->back = N;
	}
	
	L->length++;
}

// insertBefore()
// Insert new element before cursor.
// Pre: length()>0, index()>=0
void insertBefore(List L, int data) {
	if (L == NULL) {
		printf("List Error: calling insertBefore() on NULL List reference\n");
		exit(1);
	}
	if (L->length <= 0) {
		printf("List Error: calling insertBefore() on empty List\n");
		exit(1);
	}
	if (L->index < 0) {
		printf("List Error: insertBefore() called on null index\n");
		exit(1);
	}
	
	Node N = newNode(data);
	
	if (L->cursor->prev != NULL) {
		L->cursor->prev->next = N;
		N->prev = L->cursor->prev;
	} else L->front = N;
	
	L->cursor->prev = N;
	N->next = L->cursor;
	
	L->index++;
	L->length++;
}
	

// insertAfter()
// Inserts new element after cursor.
// Pre: length()>0, index()>=0
void insertAfter(List L, int data) {
	if (L == NULL) {
		printf("List Error: calling insertAfter() on NULL List reference\n");
		exit(1);
	}
	if (L->length <= 0) {
		printf("List Error: calling insertAfter() on empty List\n");
		exit(1);
	}
	if (L->index < 0) {
		printf("List Error: insertAfter() called on null index\n");
		exit(1);
	}
	
	Node N = newNode(data);
	
	if (L->cursor->next != NULL) {
		L->cursor->next->prev = N;
		N->next = L->cursor->next;
	} else L->back = N;
	
	L->cursor->next = N;
	N->prev = L->cursor;
	
	L->length++;
}
	

// deleteFront()
// Deletes the front element.
// Pre: length()>0
void deleteFront(List L) {
	if (L == NULL) {
		printf("List Error: calling deleteFront() on NULL List reference\n");
		exit(1);
	}
	if (L->length <= 0) {
		printf("List Error: calling deleteFront() on empty List\n");
		exit(1);
	}
	
	if (L->cursor != NULL) {
		if (L->cursor == L->front) {
			L->cursor = NULL;
			L->index = -1;
		}
	}
	
	Node F = L->front;
	L->front = L->front->next;
	freeNode(&F);
	L->front->prev = NULL;
	L->length--;
}

// deleteBack()
// Deletes the back element.
// Pre: length()>0
void deleteBack(List L) {
	if (L == NULL) {
		printf("List Error: calling deleteBack() on NULL List reference\n");
		exit(1);
	}
	if (L->length <= 0) {
		printf("List Error: calling deleteBack() on empty List\n");
		exit(1);
	}
	
	if (L->cursor == L->back) {
		L->cursor = NULL;
		L->index = -1;
	}
	if (L->back == L->front) {
		L->front = NULL;
	}
	
	Node F = L->back;
	if (L->back->prev != NULL) {
		L->back = L->back->prev;
	}
	freeNode(&F);
	L->back->next = NULL;
	L->length--;
}

// delete()
// Deletes cursor element, making cursor undefined.
// Pre: length()>0, index()>=0
void delete(List L) {
	if (L == NULL) {
		printf("List Error: calling delete() on NULL List reference\n");
		exit(1);
	}
	if (L->length <= 0) {
		printf("List Error: calling delete() on empty List\n");
		exit(1);
	}
	if (L->index < 0) {
		printf("List Error: delete() called on null index\n");
		exit(1);
	}
	
	if (L->cursor == L->front) {
		deleteFront(L);
	} else if (L->cursor == L->back) {
		deleteBack(L);
	} else {
		Node F = L->cursor;
		L->cursor->prev->next = L->cursor->next;
		L->cursor->next->prev = L->cursor->prev;
		freeNode(&F);
		L->cursor = NULL;
		L->index = -1;
	}
	L->length--;
}


// Other Operations ----------------------------------------------------------------

// printList()
// prints the L to the file pointed to by out, formatted as 
// a space-separated string
void printList(FILE* out, List L) {
	if (L == NULL) {
		printf("List Error: calling printList() on NULL List reference\n");
		exit(1);
	}
	
	Node N = NULL;
	for (N = L->front; N!=NULL; N=N->next) {
		fprintf(out, "%d ", N->data);
	}
}

// copyList()
// Returns a new List representing the same integer sequence as this List.
List copyList(List L) {
	if (L == NULL) {
		printf("List Error: calling copyList() on NULL List reference\n");
		exit(1);
	}
	List K = newList();
	Node N = L->front;
	
	while (N != NULL) {
		append(K, N->data);
		N = N->next;
	}
	
	return K;
}