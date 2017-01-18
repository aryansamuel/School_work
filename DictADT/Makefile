#------------------------------------------------------------------------------
# Dictionary.c Makefile
# Aryan Samuel
# arsamuel
# CMPS 12B
# 05/21/16
# Programming Assignment 5
# Makefile for DictionaryClient.c
#------------------------------------------------------------------------------

FLAGS   = -std=c99 -Wall
SOURCES = Dictionary.c DictionaryClient.c
OBJECTS = Dictionary.o DictionaryClient.o
HEADERS = Dictionary.h
EXEBIN  = DictionaryClient

all: $(EXEBIN)

$(EXEBIN) : $(OBJECTS) $(HEADERS)
	gcc -o $(EXEBIN) $(OBJECTS)

$(OBJECTS) : $(SOURCES) $(HEADERS)
	gcc -c $(FLAGS) $(SOURCES)

clean :
	rm -f $(EXEBIN) $(OBJECTS)

check:
	valgrind --leak-check=full $(EXEBIN)
	
submit:
	submit  cmps012b-pt.s16 pa5 README Makefile Dictionary.c Dictionary.h DictionaryTest.c DictionaryClient.c

subchk:
	ls  /afs/cats.ucsc.edu/class/cmps012b-pt.s16/pa5/arsamuel