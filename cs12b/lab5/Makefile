#------------------------------------------------------------------------------
# DictionaryClient.c Makefile
# Aryan Samuel
# arsamuel
# CMPS 12M
# 05/10/16
# Lab 5
# Makefile for the Dictionary ADT
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
	submit  cmps012b-pt.s16 lab5 README Makefile Dictionary.c DictionaryTest.c Dictionary.h DictionaryClient.c

subchk:
	ls  /afs/cats.ucsc.edu/class/cmps012b-pt.s16/lab5/arsamuel