/*
 * charType.c
 * Aryan Samuel
 * arsamuel
 * CMPS 12M
 * 04/27/16
 * Lab 4
 * Takes string input from a file and prints the different types of characters 
 * each line consists of, and how many of each there are.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<assert.h>

#define MAX_STRING_LENGTH 100

/* Function prototype */
void extract_chars (char* s, char* a, char* d, char* p, char* w);

/* Function Main */
int main (int argc, char* argv[]) {
	FILE* in;
	FILE* out;
	char* line;
	char* alpha;
	char* digit;
	char* punct;
	char* whtspc;
	
	/* Command line arguments check */
	if (argc != 3) {
		printf("Usage: %s input-file output-file\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	
	/* Open files */
	if ((in=fopen(argv[1], "r")) == NULL) {
		printf("Unable to read from file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	if ((out=fopen(argv[2], "w")) == NULL) {
		printf("Unable to write to file %s\n", argv[2]);
		exit(EXIT_FAILURE);
	}
	
	/* Allocate string on the heap */
	line = calloc(MAX_STRING_LENGTH+1, sizeof(char));
	alpha = calloc(MAX_STRING_LENGTH+1, sizeof(char));
	digit = calloc(MAX_STRING_LENGTH+1, sizeof(char));
	punct = calloc(MAX_STRING_LENGTH+1, sizeof(char));
	whtspc = calloc(MAX_STRING_LENGTH+1, sizeof(char));
	assert (line != NULL && alpha != NULL && digit != NULL &&
		punct != NULL && whtspc != NULL);
	
	/* Read each line and sort characters */
	int linNum=1; 
	while (fgets(line, MAX_STRING_LENGTH, in) != NULL) {
		extract_chars(line, alpha, digit, punct, whtspc);
		int a = strlen(alpha), d = strlen(digit), p = strlen(punct), w = strlen(whtspc);
		fprintf(out, "Line %d contains:\n", linNum);
		fprintf(out, "%d alphabetic character",a);	 /*Print alphabets*/
		fprintf(out, (a>1? "s: %s\n" : ": %s\n"), alpha);  /*Singular or plural*/
		fprintf(out, "%d numeric character", d);     /*Print numerics*/
		fprintf(out, (d>1? "s: %s\n" : ": %s\n"), digit);  /*Singular or plural*/
		fprintf(out, "%d punctuation character", p); /*Print punctuations*/
		fprintf(out, (p>1? "s: %s\n" : ": %s\n"), punct);  /*Singular or plural*/
		fprintf(out, "%d whitespace character", w);  /*Print white spaces*/
		fprintf(out, (w>1? "s: %s\n" : ": %s\n"), whtspc); /*Singular or plural*/
		linNum++;
	}
		
	/* Free memory and close files */
	free(line);
	free(alpha);
	free(digit);
	free(punct);
	free(whtspc);
	
	fclose(in);
	fclose(out);
	
	return EXIT_SUCCESS;
}

/* Eaxtract Characters function */
void extract_chars (char* s, char* a, char* d, char* p, char* w) {
	int i=0, j=0, k=0, l=0, m=0;
	while (s[i] != '\0' && i < MAX_STRING_LENGTH) {
		if (isalpha(s[i])) a[j++] = s[i]; 
		else if (isdigit(s[i])) d[k++] = s[i];
		else if (ispunct(s[i])) p[l++] = s[i];
		else if (isspace(s[i])) w[m++] = s[i];
		i++;
	}
	a[j] = '\0';
	d[k] = '\0';
	p[l] = '\0';
	w[m] = '\0';
}