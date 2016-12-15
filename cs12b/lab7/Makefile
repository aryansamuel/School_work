#------------------------------------------------------------------------------
# DictionaryClient.java Makefile
# Aryan Samuel
# arsamuel
# CMPS 12M
# 05/27/16
# Lab 7
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
	submit cmps012b-pt.s16 lab7 README Makefile Dictionary.java DuplicateKeyException.java KeyNotFoundException.java DictionaryInterface.java DictionaryClient.java

subchk:
	ls  /afs/cats.ucsc.edu/class/cmps012b-pt.s16/lab7/arsamuel

