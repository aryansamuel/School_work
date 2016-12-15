#------------------------------------------------------------------------------
# List.java Makefile
# Aryan Samuel
# arsamuel
# CMPS 101
# 10/01/16
# Programming Assignment 1
# Makefile for CMPS 101 pa1 
#------------------------------------------------------------------------------ 

MAINCLASS  = Lex
JAVAC      = javac 
JAVASRC    = $(wildcard *.java)
SOURCES    = $(JAVASRC) makefile README
CLASSES    = $(patsubst %.java, %.class, $(JAVASRC))
JARCLASSES = $(patsubst %.class, %*.class, $(CLASSES))
JARFILE    = $(MAINCLASS) 

all: $(JARFILE)
	
$(JARFILE): $(CLASSES)
	echo Main-class: $(MAINCLASS) > Manifest
	jar cvfm $(JARFILE) Manifest $(JARCLASSES)
	chmod +x $(JARFILE)
	rm Manifest

%.class: %.java
	$(JAVAC) $<

clean:
	rm -f *.class $(JARFILE)

submit:
	submit cmps101-pt.f16 pa1 Makefile README List.java ListClient.java Lex.java

check:
	ls  /afs/cats.ucsc.edu/class/cmps101-pt.f16/pa1/arsamuel
