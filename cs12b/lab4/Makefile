#------------------------------------------------------------------------------
# charType.c Makefile
# Aryan Samuel
# arsamuel
# CMPS 12M
# 04/27/16
# Lab 4
# Makefile for charType.c program.
#------------------------------------------------------------------------------

FLAGS = -std=c99 -Wall
SOURCES = charType.c
OBJECTS = charType.o
EXEBIN = charType

all: $(EXEBIN)

$(EXEBIN) : $(OBJECTS)
	gcc -o $(EXEBIN) $(OBJECTS)

$(OBJECTS) : $(SOURCES)
	gcc -c $(FLAGS) $(SOURCES)

clean :
	rm $(EXEBIN) $(OBJECTS)

submit:
	submit cmps012b-pt.s16 lab4 README Makefile charType.c

check:
	ls  /afs/cats.ucsc.edu/class/cmps012b-pt.s16/lab4/arsamuel