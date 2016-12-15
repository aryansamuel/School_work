/****************************************************************************************
* List.h
* Aryan Samuel
* arsamuel
* CMPS 101
* 10/8/16
* Programming Assignment 2
* Header file for List ADT
*****************************************************************************************/

#ifndef _LIST_H_INCLUDE_
#define _LIST_H_INCLUDE_

// Exported type ------------------------------------------------------------------
typedef struct ListObj* List;


// Constructors-Destructors -------------------------------------------------------

// newList()
// Returns reference to new empty List object.
List newList(void);

// freeList()
// Frees all heap memory associated with List *pL, and sets *pL to NULL.
void freeList(List* pL);


// Access Functions ----------------------------------------------------------------

// length()
// returns the number of elements in thei List.
int length(List L);

// index()
// If cursor is defined, returns index of cursor element. Otherwise returns -1.
int index(List L);

// front()
// Returns front element.
// Pre: length()>0
int front(List L);

// back()
// Returns back element.
// Pre: length()>0
int back(List L);

// get()
// Returns cursor element.
// Pre: length()>0, index()>=0
int get(List L);

// equals()
// Returns true if this List and L are the same integer
// sequence. The cursor is ignored in both lists.
int equals(List A, List B);


// Manipulation Procedures ---------------------------------------------------------

// clear()
// Resets this List to its original empty state
void clear(List L);

// moveFront()
// If list is non-empty, places cursor under front element, otherwise does nothing.
void moveFront(List L);

// moveBack()
// If list is non-empty, places cursor under back element, otherwise does nothing.
void moveBack(List L);

// movePrev()
// If cursor is defined and not at front, moves cursor one step toward
// front of this List, if cursor is defined and at front, cursor becomes
// undefined, if cursor is undefined does nothing.
void movePrev(List L);

// moveNext()
// If cursor is defined and not at back, moves cursor one step toward
// back of this List, if cursor is defined and at back, cursor becomes
// undefined, if cursor is undefined does nothing.
void moveNext(List L);

// prepend()
// Insert new element into this List. If List is non-empty,
// insertion takes place before front element.
void prepend(List L, int data);

// append()
// Insert new element into this list. If List is non-empty,
// inswertion takes place after back element.
void append(List L, int data);

// insertBefore()
// Insert new element before cursor.
// Pre: length()>0, index()>=0
void insertBefore(List L, int data);

// insertAfter()
// Inserts new element after cursor.
// Pre: length()>0, index()>=0
void insertAfter(List L, int data);

// deleteFront()
// Deletes the front element.
// Pre: length()>0
void deleteFront(List L);

// deleteBack()
// Deletes the back element.
// Pre: length()>0
void deleteBack(List L);

// delete()
// Deletes cursor element, making cursor undefined.
// Pre: length()>0, index()>=0
void delete(List L);


// Other Operations ----------------------------------------------------------------

// printList()
// prints the L to the file pointed to by out, formatted as 
// a space-separated string
void printList(FILE* out, List L);

// copyList()
// Returns a new List representing the same integer sequence as this List.
List copyList(List L);

#endif