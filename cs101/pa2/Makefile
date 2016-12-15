#------------------------------------------------------------------------------
# Makefile
# Aryan Samuel
# arsamuel
# CMPS 101
# 10/8/16
# Programming Assignment 2
# Makefile for Lex.c
#------------------------------------------------------------------------------

Lex : Lex.o List.o
	gcc -o Lex Lex.o List.o

Lex.o : Lex.c List.h
	gcc -c -std=c99 -Wall Lex.c

ListClient: ListClient.o List.o
	gcc -o ListClient ListClient.o List.o

ListClient.o : ListClient.c List.h
	gcc -c -std=c99 -Wall ListClient.c

List.o : List.c List.h
	gcc -c -std=c99 -Wall List.c

clean :
	rm -f Lex ListClient Lex.o ListClient.o List.o
	
submit:
	submit  cmps101-pt.f16 pa2 README Makefile List.c List.h Lex.c ListClient.c
	
subchk:
	ls  /afs/cats.ucsc.edu/class/cmps101-pt.f16/pa2/arsamuel