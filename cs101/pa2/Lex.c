/****************************************************************************************
* Lex.c
* Aryan Samuel
* arsamuel
* CMPS 101
* 10/8/16
* Programming Assignment 2
* Takes in an input from a user specified input file, alphabetizes its contents, and prints 
* the output to a user specified output file.
*****************************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "List.h"

#define MAX_LEN 160

int main (int argc, char * argv[]) {
	
	FILE *in, *out;
	char line[MAX_LEN];
	int i=0, n=0;
	
	// Error Check
	if (argc != 3) {
		printf("Usage: Lex <input file> <output file>\n");
		exit(1);
	}
	
	// Open files
	in = fopen(argv[1], "r");
	out = fopen(argv[2], "w");
	if (in == NULL) {
		printf("Unable to open file %s for reading\n", argv[1]);
		exit(1);
	}
	if (out == NULL) {
		printf("Unable to open file %s for writing\n", argv[2]);
		exit(1);
	}
	
	// Number of lines
	while (fgets(line, MAX_LEN, in) != NULL) {
		n++;
	}
	
	// Reopen file and create string array
	fclose(in);
	in = fopen(argv[1], "r");
	char* words[n];
	while (fgets(line, MAX_LEN, in) != NULL) {
		words[i] = malloc(sizeof(char));
		strcpy(words[i],line);
		i++;
	}
	
	// Create new List
	List L = newList();
	append(L, 0);
	
	// Lex Algorithm
	for (int j=1; j<n; j++) {
		char* s = words[j];
		i = j-1;
		moveBack(L); // Move cursor to the end
		while ( (i >= 0) && (strcmp(s, words[get(L)]) < 0) ) {
			movePrev(L); // Move cursor back one step
			i--;
		}
		if (index(L) == -1) prepend(L, j); // If cursor is null, insert j as first element
		else insertAfter(L, j); // Otherwise insert after where cursor stopped
	}
	
	// Print to output file
	moveFront(L);
	for (int k=0; k<n; k++) {
		fprintf(out, words[get(L)]);
		moveNext(L);
	}
	
	// Free lists & Close files
	for (int k=0; k<n; k++) {
		free(words[k]);
	}
	freeList(&L);
	fclose(in);
	fclose(out);
	
	return(0);
}