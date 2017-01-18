//--------------------------------------------------------------------------------------------------
// DictionaryTest.c
// Aryan Samuel
// arsamuel
// CMPS 12B
// 05/21/16
// Programming Assignment 5
// A test client for the Dctionary ADT. Each new Test block shows what was added only
// after the previous test block passed i.e. no erros when compiled, expected output.
//--------------------------------------------------------------------------------------------------

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Dictionary.h"

#define MAX_LEN 180

int main(int argc, char* argv[]) {
	Dictionary A = newDictionary();

	// Test 1
	insert(A,"1","one");
	// Test 2
	insert(A,"2", "two");
	insert(A,"3", "three");
	insert(A,"4", "four");
	insert(A,"5", "five");
	
	printDictionary(stdout,A);
	
	// Test 3
	printf("%d\n",size(A));
	printf("%d\n",isEmpty(A));
	printf("\n");
	
	// Test 4
	printf("%s\n", lookup(A,"1"));
	printf("%s\n", lookup(A,"3"));
	printf("\n");
	
	// Test 5 / Duplicate Test
	//insert(A,"2","two");
	
	// Test 6
	delete(A,"4");
	printDictionary(stdout,A);
	printf("%d\n",size(A));
	printf("\n");
	
	// Test 7 / Non-existent key test
	//delete(A,"7");
	
	// Test 8
	makeEmpty(A);
	printf("%d\n",isEmpty(A));
	//printDictionary(stdout,A); 
	
	freeDictionary(&A);
	return (EXIT_SUCCESS);
}