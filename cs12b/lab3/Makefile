#------------------------------------------------------
# FileReverse.c Makefile
# Aryan Samuel
# arsamuel
# CMPS 12M
# 04/17/16
# Lab 3
# Makefile for FileReverse.c program.
#------------------------------------------------------

FLAGS   = -std=c99 -Wall
SOURCES = FileReverse.c
OBJECTS = FileReverse.o
EXEBIN  = FileReverse

all: $(EXEBIN)

$(EXEBIN) : $(OBJECTS)
	gcc -o $(EXEBIN) $(OBJECTS)

$(OBJECTS) : $(SOURCES)
	gcc -c $(FLAGS) $(SOURCES)

clean :
	rm -f $(EXEBIN) $(OBJECTS)
