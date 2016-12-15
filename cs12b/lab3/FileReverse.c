/*
 * FileReverse.c
 * Aryan Samuel
 * arsamuel
 * CMPS 12M
 * 04/17/16
 * Lab 3
 * Takes string input from a user specifed file and reverse its contents.
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* Reverse string algorithm */
void stringReverse (char* s) {
	int i=0, j=strlen(s)-1;
	while (i<=j) {
		char temp = s[i];
		s[i] = s[j];
		s[j] = temp;
		i++;
		j--;
	}
}

/* Main function */
int main (int argc, char* argv[]) {
	FILE* in;
	FILE* out;
	char word[256];
	
	/* Command line argument check */
	if (argc != 3) {
	printf("Usage: %s <input file> <output file>\n", argv[0]);
	exit(EXIT_FAILURE);
	}
	
	/* Open all files */
	in = fopen(argv[1], "r");
	if (in==NULL) {
		printf("Unable to read from file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	
	out = fopen (argv[2], "w");
	if (out==NULL) {
		printf("Unable to write to file %s\n", argv[2]);
		exit(EXIT_FAILURE);
	}
	
	while (fscanf(in, "%s", word) != EOF) {
		stringReverse(word);
		fprintf(out, "%s\n", word);
	}
	
	/* Close all files */
	fclose(in);
	fclose(out);
	
	return(EXIT_SUCCESS);
}
