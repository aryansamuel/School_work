#------------------------------------------------------------------------------
# DictionaryClient.java Makefile
# Aryan Samuel
# arsamuel
# CMPS 12B
# 04/24/16
# Programming Assignment 3
# Makefile for the DictionaryClient.java file
#------------------------------------------------------------------------------

JAVAC      = javac 
MAINCLASS  = DictionaryClient
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
	submit cmps012b-pt.s16 pa3 README Makefile Dictionary.java DictionaryTest.java DuplicateKeyException.java KeyNotFoundException.java DictionaryInterface.java DictionaryClient.java

check:
	ls  /afs/cats.ucsc.edu/class/cmps012b-pt.s16/pa3/arsamuel

